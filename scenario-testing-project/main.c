// Main function to load and close .so files
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <dlfcn.h>
#include <string.h>

#define DIRECTORY "./modules/" // Directory containing .so files

int main() {
    DIR *dir;
    struct dirent *entry;
    
    dir = opendir(DIRECTORY);
    if (!dir) {
        perror("Failed to open directory");
        return EXIT_FAILURE;
    }

    void *handles[100];
    int handle_count = 0;

    while ((entry = readdir(dir)) != NULL) {
        if (strstr(entry->d_name, ".so")) {
            char path[1024];
            snprintf(path, sizeof(path), "%s%s", DIRECTORY, entry->d_name);

            void *handle = dlopen(path, RTLD_LAZY);
            if (!handle) {
                fprintf(stderr, "Failed to load %s: %s\n", path, dlerror());
                continue;
            }

            void (*onLoad)() = dlsym(handle, "onLoad");
            if (onLoad) {
                onLoad();
            } else {
                fprintf(stderr, "onLoad not found in %s\n", path);
            }

            handles[handle_count++] = handle;
        }
    }

    closedir(dir);

    for (int i = 0; i < handle_count; i++) {
        void (*onUnload)() = dlsym(handles[i], "onUnload");
        if (onUnload) {
            onUnload();
        }

        dlclose(handles[i]);
    }

    return EXIT_SUCCESS;
}


#include "flashbang.h"
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

// trigger flashbang (display image full screen, play a sound)
int bang(char *img_name, char *sound_name) {
    printf("FLASHBANG");
    // TODO: use feh to display an image full screen
    pid_t p = fork();
    if (p < 0) {
        printf("Show %s", img_name);
        exit(0);
    }
    // TODO: play a sound
    pid_t p = fork();
    if (p < 0) {
        printf("Play %s", sound_name);
        exit(0);
    }
    return 0;
}
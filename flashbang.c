#include "flashbang.h"
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// trigger flashbang (display image full screen, play a sound)
int bang(char *img_name, char *sound_name) {
    // TODO: use feh to display an image full screen
    pid_t p_img = fork();
    if (p_img < 0) {
        printf("flashbang: fork() returned exit code %d", p_img);
        exit(1);
    }
    if (p_img == 0) {
        printf("Show %s", img_name);
        char *args[] = {"feh", "--fullscreen", "--auto-zoom", "--image-bg", "white", img_name, '\0'};
        execvp(args[0], args);
        exit(0);
    }
    // TODO: play a sound
    pid_t p_audio = fork();
    if (p_audio < 0) {
        printf("flashbang: fork() returned exit code %d", p_img);
        exit(1);
    }
    if (p_audio == 0) {
        printf("Play %s", sound_name);
        char *args[] = {"play", "-q", sound_name, '\0'};
        execvp(args[0], args);
        exit(0);
    }
    printf("FLASHBANG");
    return 0;
}
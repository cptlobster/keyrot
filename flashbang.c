#include "flashbang.h"
#include <stdio.h>

// trigger flashbang (display image full screen, play a sound)
int bang(char *img_name, char *sound_name) {
    printf("FLASHBANG");
    // TODO: use feh to display an image full screen
    printf("Show %s", img_name);
    // TODO: play a sound
    printf("Play %s", sound_name);
    return 0;
}
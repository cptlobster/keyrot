// 
#include "main.h"
#include "logger.h"
#include "flashbang.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

void clear_buffer(char *buf, int *buf_length) {
    for (int i = 0; i <= BUFFER_SIZE; i++) {
        buf[i] = '\0';
    }
    *buf_length = 0;
}

int main(int argc, char **argv) {
    system("/bin/stty raw");
    char *target = "sus";
    char buf[BUFFER_SIZE] = "";
    int buf_length = 0;
    char next;

    while ((next = get_next_char()) != '.') {
        if (next == target[buf_length]) {
            buf[buf_length] = next;
            buf_length += 1;
            printf("%s", buf);
            if (target[buf_length] == 0) {
                bang("sus.png", "sus.mp3");
                clear_buffer(buf, &buf_length);
            }
        }
        else {
            clear_buffer(buf, &buf_length);
        }
    }
    system("/bin/stty cooked");
    return 0;
}
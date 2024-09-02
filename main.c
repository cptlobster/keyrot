// main loop
#include "main.h"
#include "logger.h"
#include "flashbang.h"
#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 128

// clear the contents of the buffer
void clear_buffer(char *buf, int *buf_length) {
    for (int i = 0; i <= BUFFER_SIZE; i++) {
        buf[i] = '\0';
    }
    *buf_length = 0;
}

// main entrypoint
int main(int argc, char **argv) {
    // temporary fix for our stand-in keylogger. once I get a proper one working we can remove this line
    system("/bin/stty raw");
    // target string to check against. ideally we'll have multiple strings
    char *target = "sus";
    // define buffer characteristics
    char buf[BUFFER_SIZE] = "";
    int buf_length = 0;
    // temp variable for next character
    char next;

    // another temporary fix, since normal escape sequences don't work in /bin/stty raw
    while ((next = get_next_char()) != '.') {
        // check if the next character matches the target string
        // if it does, store it in the buffer
        if (next == target[buf_length]) {
            buf[buf_length] = next;
            buf_length += 1;
            //printf("%s", buf);
            // if we reach the end of the buffer string, trigger the flashbang and clear the buffer
            if (target[buf_length] == 0) {
                bang("sus.png", "sus.mp3");
                clear_buffer(buf, &buf_length);
            }
        }
        else {
            // clear the buffer if it isn't empty
            if (buf_length != 0) {
                clear_buffer(buf, &buf_length);
            }
        }
    }
    // temporary fix for our stand-in keylogger. once I get a proper one working we can remove this line
    system("/bin/stty cooked");
    return 0;
}
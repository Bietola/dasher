#ifndef __user_command_logger_h__
#define __user_command_logger_h__

#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 

namespace command_logger {
    // Set log file path here
    static const char* LOG_FILE_PATH = "/home/dincio/logs/dasher-commands";

    static int LOG_FILEH = NULL;

    void init_log_file() {
        if (!LOG_FILEH) {
            mkfifo(LOG_FILE_PATH, 0666);

            LOG_FILEH = open(LOG_FILE_PATH, O_WRONLY);
        }
    }

    void log_text(const char* text) {
        init_log_file();

        // Multiline text is not handled properly...
        const char* resTxt = NULL;
        if (strlen(text) != 1) {
            fprintf(stderr, "Warning: Multine text input\n"); fflush(stderr);

            resTxt = "<mul>";

        // Escape `<` character
        } else if (!strcmp(text, "<")) {
            resTxt = "<lt>";
        } else {
            resTxt = text;
        }

        printf("\nKey(%s)\n", resTxt); fflush(stdout);
    }

    void log_deletion() {
        init_log_file();

        printf("\nKey(<bs>)\n"); fflush(stdout);
    }

    void handle_cleanup() {
        if (LOG_FILEH) { close(LOG_FILEH); }
    }
}

#endif

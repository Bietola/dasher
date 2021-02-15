#ifndef __user_commander_logger_h__
#define __user_commander_logger_h__

namespace command_logger {
    // Set log file path here
    static const char* LOG_FILE_PATH = "/home/dincio/logs/dasher-commands";

    static FILE* LOG_FILEH = NULL;

    void init_log_file() {
        if (!LOG_FILEH) {
            LOG_FILEH = fopen(LOG_FILE_PATH, "w+");
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

        printf("Logging text: %s\n", resTxt); fflush(stdout);

        // Res
        // TODO: printf("%s", resTxt);
    }

    void log_deletion() {
        init_log_file();

        printf("Logging delete\n"); fflush(stdout);

        // TODO: fprintf("<bs>");
    }

}

#endif

#include <stdio.h>
#include <unistd.h>
#include <ctype.h>

int main(int argc, char **argv) {
    int c;
    int has_option = 0;

    char *echo_msg = NULL;
    char *name = NULL;
    // h: Help
    // e [msg]: Echo message

    // n [name]:print hi [name]
    
    while ((c = getopt(argc, argv, "he:n:p")) != -1) {

        has_option = 1;

        switch (c) {
            case 'h':
                printf("Usage: %s [Options]\n", argv[0]);
                puts("\nOptions:");
                puts("\t-h: Print help message");
                puts("\t-e [msg]: Echo message");
                puts("\t-n [name]: Print Hi[name]");
                puts("\t-p:Print pong!");
                return 0;
            
            case 'e':
                echo_msg = optarg;
                break;
            case 'n':
                name = optarg;
                break;
           
            case 'p':
                puts("Pong!");
                break;
        }


    if (!has_option) {
        fprintf(stderr, "%s: Missing options\nTry '%s -h' for help.\n", argv[0], argv[0]);
        return 1;
    }

    if (echo_msg != NULL)
        puts(echo_msg);
    if (name != NULL)
        printf("Hi %s !",name);
    }
}
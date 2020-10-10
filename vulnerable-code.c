#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("You should specify the user name\n");
        exit(1);
    }
    
    // Now in the code. We can to create a directory based on the name
    // First let's convert it to lowercase 
    char username [16] = "";
    strncpy(username, argv[1], sizeof(username)-1);
    for (int i=0; username[i] != '\0'; ++i)
    {
        if (!isalnum(username[i]))
        {
            printf("No space allowed in username. Try again\n");
            exit(1);
        }
        username[i] = tolower(username[i]);
    }
    char homedir [32] = "/tmp/home/";
    strcat(homedir, username);

    printf("Creating directory: %s\n\n\n", homedir);

    // Call the execlp command
    char *args[] = {"mkdir", "-p", homedir, NULL};

    execvp("mkdir", args);
    printf("Process complete. :)\n");
    return 0;
}

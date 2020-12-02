#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv)
{
    // Checking the number of parameters passed
    if (argc != 2)
    {
        printf("Please specify a username\n");
        printf("Usage: %s <username>\n", argv[1]);
        exit(1);
    }
    
    // Now in the code. We can to create a directory based on the name
    // Creating a variable for the username
    char username [16] = "";
    // Copying the argument to the program to the username variable
    strncpy(username, argv[1], sizeof(username)-1);
    for (int i=0; username[i] != '\0'; ++i)
    {
        printf("Checking if the username is valid (only alphanumeric parameters are allowed) \n");
        if (!isalnum(username[i]))
        {
            printf("Invalid username passed. Please check your input and try again\n");
            exit(1);
        }
        // Converting the letters to uppercase
        username[i] = tolower(username[i]);
    }
    // Setting a base path for the directories that we will create
    char homedir [32] = "/tmp/home/";
    // Appending the username to the base directory
    strcat(homedir, username);

    printf("Creating directory: %s\n", homedir);

    // Setting the arguments for the call to the function. Equivalent bash syntax is mkdir -p <directory>
    char *args[] = {"mkdir", "-p", homedir, NULL};
    
    // Execute the program. execvp will look up the program based on the PATH variable
    execvp("mkdir", args);
}

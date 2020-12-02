/*
 * This is a C program to demonstrate the adjacent memory buffer overflow vulnerability
 * Last modified: April 04th 2020
 * Author: Boladji Vinny - https://vinny.coach / @boladjivinny / https://gitlab.com/boladji
 * Licence: Free GPL
 *
*/ 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
	char record[265];
	char comments[128]; 
	char studentName[256]; 

	if(argc <= 2){
		 printf("Usage: %s [student] [comments]\n", argv[0]);
		 exit(0);
	}

	strncpy(studentName, argv[1], sizeof(studentName)); 
	strncpy(comments, argv[2], sizeof(comments)); 
	sprintf(record,"RECORD: %s",studentName);
	
	printf("%s\n",record);
	return(0);
}

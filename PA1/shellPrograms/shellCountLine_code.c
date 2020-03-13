#include "shellPrograms.h"

/*
Count the number of lines in a file 
*/
int shellCountLine_code(char **args)
{

    /** TASK 6  **/
    // ATTENTION: you need to implement this function from scratch and not to utilize other system program to do this
    // 1. Given char** args, open file in READ mode based on the filename given in args[1] using fopen()
    // 2. Check if file exists by ensuring that the FILE* fp returned by fopen() is not NULL
    // 3. Read the file line by line by using getline(&buffer, &size, fp)
    // 4. Loop, as long as getline() does not return -1, keeps reading and increment the count
    // 6. Close the FILE*
    // 7. Print out how many lines are there in this particular filename
    // 8. Return 1, to exit program

    int lineCount = 0;
    int lineStatus;

    char *tempMem = (char *)malloc(sizeof(char) * SHELL_BUFFERSIZE);
    size_t lineChar = SHELL_BUFFERSIZE;
    //char path[256] = "/home/josejohnson/ProgrammingAssignment1/PA1/";
    //strcat(path, args[1]);

    // FILE *fp = fopen(path, "r");
    FILE *fp = fopen(args[1], "r");

    if (fp == NULL)
    {
        printf("The file did not open properly \n");
        return 0;
    }

    lineStatus = getline(&tempMem, &lineChar, fp);
    while (lineStatus > 0)
    {
        // printf("Number of char %d \n", lineStatus);
        lineCount++;
        // printf("LineCount is %d \n", lineCount);
        lineStatus = getline(&tempMem, &lineChar, fp);
    }

    fclose(fp);
    printf("There are %d lines in this file \n", lineCount);
    return 1;
}

int main(int argc, char **args)
{
    return shellCountLine_code(args);
}
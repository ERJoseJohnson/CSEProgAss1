#include "shellPrograms.h"

/*  A program that prints how many summoned daemons are currently alive */
int shellCheckDaemon_code()
{

   /* TASK 8 */
   //Create a command that trawl through output of ps -efj and contains "summond"
   char *command = malloc(sizeof(char) * 256);
   sprintf(command, "ps -efj | grep summond  | grep -v tty > output.txt");

   // TODO: Execute the command using system(command) and check its return value
   int commandStatus = system(command);
   free(command);
   if (commandStatus != -1)
   {

      int live_daemons = 0;
      // TODO: Analyse the file output.txt, wherever you set it to be. You can reuse your code for countline program
      // 1. Open the file
      // 2. Fetch line by line using getline()
      // 3. Increase the daemon count whenever we encounter a line
      // 4. Close the file
      // 5. print your result

      int lineStatus;
      char *tempMem = (char *)malloc(sizeof(char) * SHELL_BUFFERSIZE);
      size_t lineChar = SHELL_BUFFERSIZE;

      FILE *fp = fopen("output.txt", "r");

      if (fp == NULL)
      {
         printf("The file did not open properly \n");
         return 0;
      }

      lineStatus = getline(&tempMem, &lineChar, fp);
      while (lineStatus > 0)
      {
         // printf("Number of char %d \n", lineStatus);
         live_daemons++;
         // printf("LineCount is %d \n", lineCount);
         lineStatus = getline(&tempMem, &lineChar, fp);
      }

      fclose(fp);
      free(tempMem);
      printf("There are %d daemons running \n", live_daemons);

      if (live_daemons == 0)
         printf("No daemon is alive right now\n");
      else
      {
         printf("There are in total of %d live daemons \n", live_daemons);
      }

      // TODO: close any file pointers and free any statically allocated memory
   }
   else
   {
      printf("The command did not go through \n");
   }
   return 1;
}

int main(int argc, char **args)
{
   return shellCheckDaemon_code();
}
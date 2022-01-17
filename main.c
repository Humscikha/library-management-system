/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#define FILE_NAME "LibBookS.bin"
struct library{
   char bookname[50];
   char author[50];
   int noofpages;
   float price;
};
int main(){
   struct library lib[100];
   char bookname[30];
   int i,j, keepcount;
   i=j=keepcount = 0;
   while(j!=6){
      printf("\n\n1. Add book information\n");
      printf("2. Display book information\n");
      printf("3. no of books in the library\n");
      printf("4. Exit");
      printf ("\n\nEnter one of the above : ");
      scanf("%d",&j);
      FILE *fp;
      fp = fopen(FILE_NAME,"ab+");
      switch (j){
         /* Add book */
         case 1:
            printf ("Enter book name = ");
            scanf ("%s",lib[i].bookname);
            printf ("Enter author name = ");
            scanf ("%s",lib[i].author);
            printf ("Enter pages = ");
            scanf ("%d",&lib[i].noofpages);
            printf ("Enter price = ");
            scanf ("%f",&lib[i].price);
            keepcount++;
            i++;
            
            break;
         case 2:
            printf("you have entered the following information\n");
            for(i=0; i<keepcount; i++){
               printf ("\t book name = %s\n",lib[i].bookname);
               printf ("\t author name = %s\n",lib[i].author);
               printf ("\t pages = %d\n",lib[i].noofpages);
               printf ("\t price = %f\n",lib[i].price);
            }
            break;
         case 3:
            printf("\n No of books in library : %d", keepcount);
            break;
         case 4:
            exit (0);
      }
      fclose(fp);
   }
   return 0;
}
int isFileExists(const char *path)
{
    // Try to open file
    FILE *fp = fopen(path, "rb");
    int status = 0;
    // If file does not exists
    if (fp != NULL)
    {
        status = 1;
        // File exists hence close file
        fclose(fp);
    }
    return status;
}


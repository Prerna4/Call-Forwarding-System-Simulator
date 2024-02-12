#include "../inc/library.h"


void file_exist()
{
        if ((fg=fopen("../data/user.txt", "r+"))== NULL)
         {
                                if ( (fg=fopen("../data/user.txt", "w+")) == NULL)
                 {
                               // printf ("Could not open file\n");
                        log_message(WARNING, "Could not open file..");


                                exit (1);
                                }
                  }
}
void user_reg()
{
        int f=0;
        char c;
        log_message(INFO, "Entering User Registration function");
        printf("\n----------------------------------------------------------\n");
        printf("\n................USER REGISTERATION PAGE...................\n");
        printf("\n----------------------------------------------------------\n");

        printf("\n Enter the Source Number (Mobile Number) : ");
        scanf("%ld", &user.source);

        printf("\n Enter the Destination Number(Forwarded Number) : ");
        scanf("%ld", &user.desti);

        printf("\n Your name: ");
        scanf("%s", user.name);

        printf("\n Your pin : ");
        scanf("%d", &user.pin);
        printf("\n------------------------------------------------\n");
        file_exist();
        while((c=getc(fg))!=EOF)
        {
        for(int i=10;i>=EOF;i--)
        while(fscanf(fg,"%ld|%ld|%100[^|]|%d%*[\n]",&tmobile,&tfmob,tname,&spin) ==4 )
         {
                        if ((user.source==tmobile))
                {
                        printf("\n---------------------------------------------\n");
                        log_message(WARNING, "This Source Number is Already Registered !!!");

                     //printf("\n This Source Number is Alreday Registered !!!\n");
                        printf("\nTry With Another Source Number");
                        f=1;
                        user_reg();
                        break;

                }
        }
        }
        fclose(fg);
        if(f==1)
        {
        }else
        {
        update();
        }
}
        void update(){
        if ( ( fg=fopen("../data/user.txt", "a+")) == NULL)
        {
                    if ( ( fg=fopen("../data/user.txt", "w+")) == NULL)
         {           log_message(WARNING, "Could not open file..");

                      //  printf ("Could not open file\n");
                        exit ( 1);
                    }
        }

        fprintf(fg,"%ld|",user.source);
        fprintf(fg,"%ld|",user.desti);
        fprintf(fg,"%s|",user.name);
        fprintf(fg,"%d",user.pin);
        fprintf(fg," \n");
        fclose(fg);
       log_message(INFO, "You Registered as a User Successfully !!!");

       //       printf("\nYou Registered as a User Successfully !!!");
        printf("\n----------------------------------------------\n");
        menu();
}


void file_existence()
{
       if ((ffg=fopen("../data/user.txt", "r+"))== NULL)
        {
          if ( (ffg=fopen("../data/user.txt", "w+")) == NULL)
                {
                  // printf ("Could not open file\n");
                  log_message(WARNING, "Could not open file..");

                   exit(1);
                }
        }
}

int unregister_user(){
        log_message(INFO, "Unregister user");
        printf("\n---------------------------------------------------------\n");
        printf("\n....................TO UNREGISTER THE USER...............\n");
        printf("\n---------------------------------------------------------\n");

{
          int lno, ctr = 0;
//          char ch;
          FILE *fptr1, *fptr2;
          char fname[MAX];
          char str[MAX], temp[] = "temp.txt";
          printf("\n\n Delete a specific line from a file :\n");
          printf("-----------------------------------------\n");
          printf(" Input the file you want to open: ");
          scanf("%s",fname);
          dis();
          fptr1 = fopen(fname, "r");
          if (!fptr1)
                {
               // printf(" File not found or unable to open the input file!!\n");
                log_message(WARNING, "File not found or unable to open the input file!!");

                return 0;
                }
         fptr2 = fopen(temp, "w"); // open the temporary file in write mode
         if (!fptr2)
                {
                printf("Unable to open a temporary file to write!!\n");
                fclose(fptr1);
                return 0;
                }
        file_existence();
        printf("\n Input the Index Number you want to remove : ");
        scanf("%d", &lno);
        //      lno++;
        // copy all contents to the temporary file except the specific line
        while (!feof(fptr1))
        {
            strcpy(str, "\0");
            fgets(str, MAX, fptr1);
            if (!feof(fptr1))
            {
                ctr++;
                //skip the line at given line number
                if (ctr != lno)
                {
                    fprintf(fptr2, "%s", str);
                }
            }
        }



        fclose(fptr1);
        fclose(fptr2);
        remove(fname);                  // remove the original file
        rename(temp, fname);
          dis();
        printf("\n-----------------------------------------------------\n");
        printf("\n You Deleted %d Index Data Successfully!!!\n",lno);
        return 0;
}
}

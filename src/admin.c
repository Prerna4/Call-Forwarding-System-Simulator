
#include "../inc/library.h"

//#define FILENAME_SIZE 1000
//#define MAX 2048

void update_database(){
        int chh;
        printf("\n------------------------------------------------------------\n");
        printf("\n.....................DISPLAYING PAGE........................\n");
        printf("\n------------------------------------------------------------\n");
        log_message(INFO, "Displaying database");

        printf("\n 1.All User Data \n 2.Particular User's Data\n");
        printf("Enter Your Choice: ");
        scanf("%d",&chh);
        printf("\n------------------------------------------------------------\n");
        switch(chh)
        {
        case 1:
        dis();
        admin_menu();
        break;
        case 2:
        display();
        break;
        default:
        log_message(WARNING, "You Entered Invalid option...");

//      printf("You Entered Invaild Option\n");
        admin_menu();
        }
}
void display(){
        long s;
        int f=0;
        printf("Enter the Unique Id(Source):");
        scanf("%ld",&s);
        char c;
        file_existence();
        while((c=getc(ffg))!=EOF)
   {
        while(fscanf(ffg,"%ld|%ld|%100[^|]|%d%*[\n]",&ttmobile,&ttfmob,ttname,&tspin)==4 )
        {
             if(s==ttmobile)
        {
        printf("******************************************************************");
        printf("Source Number:%ld\n",ttmobile);
        printf("Destination Number:%ld\n",ttfmob);
        printf("User Name:%s\n",ttname);
        printf("User Pin: %d\n",tspin);

        printf("******************************************************************");
        admin_menu();
        f=1;
        break;
        }
        }
    }
        if(f==1)
        {
        }else{
        log_message(WARNING, "You Enter Invaild Source Number...Data is not Present in Our Database");
//      printf("You Enter Invaild Source Number\n Data is not Present in Our Database\n");
    }
}
void dis()
{
        char c;
        int co=1;
        file_existence();
        while((c=getc(ffg))!=EOF)
     {
        for(int i=10;i>EOF;i--)
        {
        while(fscanf(ffg,"%ld|%ld|%100[^|]|%d%*[\n]",&ttmobile,&ttfmob,ttname,&tspin)==4 )
        {

        printf("\n****************INDEX NUMBER:%d***************",co);
        printf("\nSource Number:%ld\n",ttmobile);
        printf("Destination Number:%ld\n",ttfmob);
        printf("User Name:%s\n",ttname);
        printf("User Pin :%d\n",tspin);

        printf("**********************************************\n");
        co+=1;
        }
        }
     }

}
void add(){
        printf("\n--------------------------------------------------------\n");
        printf("\n....................To Add NEW User.....................\n");
        printf("\n--------------------------------------------------------\n");
        user_reg();
        admin_menu();
}

void admin_menu(){
int Achoice;
printf("\n.......................ADMIN MENU......................\n");
//printf("\nwelocme to menu:");
//printf("\n......");
printf("\n 1. Add User");
printf("\n 2. Display Database");
printf("\n 3. Unregister User");
printf("\n 4. Home Page");
printf("\n Enter your Choice:");
scanf("%d",&Achoice);
printf("\n-----------------------------------------------------\n");
switch(Achoice)
{
case 1:
add();
break;
case 2:
update_database();
break;
case 3:
unregister_user();
break;
case 4:
menu();
break;
default:
log_message(WARNING, "Invalid choice..");

//printf("\n You Enter Wrong Choice Try Again!!!\n");
exit(0);
break;
}
}

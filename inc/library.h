
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define FILENAME_SIZE 1000
#define MAX 2048

#define FATAL 0
#define INFO 3
#define WARNING 2
#define DEBUG 1

struct  User{
long source;
long desti;
char name[15];
char call_s_type;
char service_s;
int pin;
}user;


char ttname[10] ,ttcall_s_type[10],ttservice_s[10];
long ttmobile,ttfmob;
int tspin;
int tpin,upin,call_s_type,spin;
char tname[10];
long tid,uid,tmobile,tfmob;
FILE *fg;
FILE *ffg;


void log_message(int level, const char *message);

void file_existence();
void nor();
void busy();
void user_login();
void file_exist();
void file_existence();
void call_type();
void call_for();
void dial();
void menu();
void add();
void admin_menu();
void update_database();
int unregister_user();
void dis();
void display();
void update();
void user_reg();

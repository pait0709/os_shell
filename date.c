
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
int main(int argc,char * args[]){
    if(argc==2){
        time_t new=time(NULL);
        char * time_current=ctime(&new);
        printf("%s",time_current);
    }
    else if(argc==3){
        if(strcmp(args[2],"-u")==0){
        time_t new=time(NULL);
        struct tm *gmt =gmtime(&new);
        printf("%s",asctime(gmt));
        }
        else if(strcmp(args[2],"-R")==0){
        time_t new=time(NULL);
        struct tm *normaltime =localtime(&new);
        char *weekdays[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        char *Months[]={"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
         printf("%s, %d %s %d %02d:%02d:%02d +0530 \n", weekdays[normaltime->tm_wday], normaltime->tm_mday, Months[normaltime->tm_mon], normaltime->tm_year + 1900, normaltime->tm_hour, normaltime->tm_min, normaltime->tm_sec);
        }
        else{
            printf("Error invalid argument");
        }
    }
    else{
            printf("Error invalid argument");
        }
}
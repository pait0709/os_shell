#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
int main(){
    time_t new=time(NULL);
        struct tm *gmt =gmtime(&new);
        printf("%s\n",asctime(gmt));
}
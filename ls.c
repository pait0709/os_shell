#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

void eless(char * args[]){
    chdir(args[1]);
    DIR *directory = opendir(".");
        if (directory == NULL) {
            printf("Error: Directory is invalid\n");
        }
        else{
        struct dirent *dire1 = readdir(directory);
        while (dire1 != NULL) {
            printf("%s\n", dire1->d_name);
            dire1 = readdir(directory);
        }
        closedir(directory);
        }
}

int main(int argc, char *args[]) {
    if (argc==2){
        eless(args);
    }
    else if(argc == 3){
        if(strcmp(args[2],"/")==0){
            chdir("/");
            struct dirent *dire1;
            DIR *directory = opendir(".");
            if (directory == NULL) {
                printf("Error: Directory is invalid\n");
            }
            else{
            dire1 = readdir(directory);
            while (dire1 != NULL) {
                printf("%s\n", dire1->d_name);
                dire1 = readdir(directory);
            }
            closedir(directory);
            chdir(args[1]);
            }
        }
        else if(strcmp(args[2],"~")==0){
            eless(args);
        }
       
        else if((strncmp(args[2],"~",1)!=0&&strncmp(args[2],"/",1)!=0)){
                char currloc[100];
                strcpy(currloc,args[1]);
                strcat(currloc,"/");
                strcat(currloc,args[2]);
                int result = chdir(currloc);
                if(result!=0){
                    printf("Directory not found\n");
                }
                else{
            struct dirent *dire1;
            DIR *directory = opendir(".");
            if (directory == NULL) {
                printf("Error: Directory is invalid\n");
            }
            else{
            dire1 = readdir(directory);
            while (dire1 != NULL) {

                    printf("%s\n", dire1->d_name);
                
                dire1 = readdir(directory);
            }
            closedir(directory);
            chdir(args[1]);
            }
                }
        }
        else{
            printf("Command not supported/Invalid Syntax");
        }
}
}

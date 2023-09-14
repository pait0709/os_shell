#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char * args[]){
    if(argc==3){
        chdir(args[1]);
        int res=remove(args[2]);
        if(res!=0){
            printf("unsuccessfull deletion\n");
        }
    }
    else if (argc==4){
        chdir(args[1]);
        if(strcmp(args[2],"-v")==0){
        int res=remove(args[3]);
        if(res!=0){
            printf("unsuccessfull deletion\n");
        }
        else{
            printf("%s File successfully deleted",args[3]);
        }
        }
        if(strcmp(args[2],"-i")==0){
            char *opt;
            printf("Are you sure you want to delete %s file?(y/n)",args[3]);
            scanf("%s",opt);
            if(strcmp(opt,"y")==0||strcmp(opt,"Y")==0){
                int res=remove(args[3]);
            if(res!=0){
                printf("unsuccessfull deletion\n");
            }
            }
            if(strcmp(opt,"n")==0||strcmp(opt,"N")==0){
                printf("Files not deleted");
            }
        }
        
    }
    else{
        printf("Error Wrong Syntax");
    }
}

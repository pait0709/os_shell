#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(int argc,char * args[]){
    if(argc==3){
        chdir(args[1]);
        char *name=args[2];
       int res= mkdir(name,0777);
       if(res!=0){
        printf("Error in directory creation");
       }
    }
    else if(argc==4){
        chdir(args[1]);
        if(strcmp(args[2],"-v")==0){
            char *name=args[3];
        int res=mkdir(name,0777);
        if (res==0){
            printf("%sDirectory successfully created",name);
        }
        else{
            printf("Directory could not be created");
        }
        }
        if(strcmp(args[2],"-p")==0){
            char *path=args[3];
            char *ent=strtok(path,"/");
            while(ent!=NULL){
                mkdir(ent,0777);
                chdir(ent);
                ent=strtok(NULL,"/");
            }
        
        }
    }
    else{
        printf("Error Wrong Syntax");
    }
}
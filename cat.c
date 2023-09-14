#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
int main(int argc,char * args[]){
    if(argc==3){
        chdir(args[1]);
        FILE *fptr =fopen (args[2], "r");
        if(fptr!=NULL){
        char *buffer = NULL; 
        unsigned long len=0; 
        while(getline(&buffer,&len, fptr)!=-1){
            printf("%s",buffer);
        }
        printf("\n");
        fclose(fptr);
        free(buffer);
        }
        else{
            printf("Error:invalid file\n");
        }
    }
    else if (argc==4){
        chdir(args[1]);
        if (strcmp(args[2],"-n")==0){
            FILE *fptr =fopen (args[3], "r");
            char *buffer = NULL; 
            unsigned long len=0; 
            int i=1;
            while(getline(&buffer,&len, fptr)!=-1){
                printf("%d %s",i,buffer);
                i++;
            }
            printf("\n");
            fclose(fptr);
            free(buffer);
        }
        else if (strcmp(args[2],"-e")==0){
            FILE *fptr =fopen (args[3], "r");
            char *buffer = NULL; 
            unsigned long len=0; 
            
            while(getline(&buffer,&len, fptr)!=-1){
                char * lmoa=strtok(buffer,"\n");
                if (lmoa==NULL){
                    lmoa="";
                }
                printf("%s$\n",lmoa);
            }
            fclose(fptr);
            free(buffer);
        }
        else{
            FILE *fptr =fopen (args[2], "r");
            if(fptr!=NULL){
            char *buffer = NULL; 
            unsigned long len=0; 
            while(getline(&buffer,&len, fptr)!=-1){
                printf("%s",buffer);
            }
            printf("\n");
            }
            else{
                printf("Error: File 1 is invalid");
            }
            if(fptr!=NULL){
            fptr =fopen (args[3], "r");
            char *buffer = NULL; 
            unsigned long len=0;
            while(getline(&buffer,&len, fptr)!=-1){                
                printf("%s",buffer);
            }
            fclose(fptr);
            free(buffer);
            printf("\n");
            }
            else{
                printf("Error:File 2 is invalid");
            }
        }
    }
    else{
        printf("Error Wrong Syntax");
    }
}

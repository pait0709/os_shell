#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h> 
#include <stdlib.h>
#include<pthread.h>
#include <string.h>
void *thread_implementation(void *input){
    char *cmd=(char*)input;
    int res=system(cmd);
    if(res!=0){
        printf("Error wrong arguments");
        return NULL;
    }
    return input;
}
void Thread_caller(char **commandwords){
        char *input=malloc(1000*sizeof(char));
        strcat(input,commandwords[0]);
        int i=1;
        while(commandwords[i]){
            if(strcmp(commandwords[i],"&t")==0){
                break;
            }
            else{
            strcat(input," ");
            strcat(input,commandwords[i]);
            
            i++;
            }
        }
        pthread_t bapu;
        int res=pthread_create(&bapu,NULL,thread_implementation,input);
        if(res!=0){
            printf("Error in thread creation");
        }
        res=pthread_join(bapu,NULL);
}
int main() 
{   

    char daddyloc[100];
    getcwd(daddyloc,100);
    char currloc[100];
    while(1){
        getcwd(currloc,100);
        char command[100];
        printf("Unix$hell: ");
        fgets(command,100,stdin);
                
        char *commandwords[100];
        int commandlen = 0;
        char *command2=strtok(command,"\n");
        if(command2==NULL){
            command2="echo";
        }
        char *token = strtok(command2," ");
        int thread_flag=0;
        while(token!=NULL){
            if (strcmp(token,"&t")==0){thread_flag=1;}
            commandwords[commandlen] = token;
            token = strtok(NULL," ");
            commandlen++;
        }
        if(strcmp(commandwords[0], "echo") == 0){
            if(commandlen==2){
                printf("%s",commandwords[1]);
                printf("\n");
                
            }
            else if(commandlen>2){
                if(strcmp(commandwords[1],"-n")==0){
                    for(int i=2;i<commandlen;i++){
                        printf("%s ",commandwords[i]);
                    }
                }
                else{
                    for(int i=1;i<commandlen;i++){
                        printf("%s ",commandwords[i]);
                    }
                    printf("\n");
                }
            }
        } 
        else if(strcmp(commandwords[0],"pwd") == 0){
            if (commandlen==1){
                printf("%s~ ",getcwd(currloc,100));
            }
            else{
                if(strcmp(commandwords[1], "-L")==0||strcmp(commandwords[1], "-l")==0){
                    printf("%s\n", getenv("PWD"));
                }
                else if(strcmp(commandwords[1], "-P")==0||strcmp(commandwords[1], "-p")==0){ 
                    printf("%s\n", getcwd(currloc, 100));
                }
                else{
                    printf("Invalid command syntax/or not supported\n");
                }
            }
        }
        else if(strcmp(commandwords[0],"exit")==0){
            break;
        }
        else if(strcmp(commandwords[0],"cd")==0){
            if (commandlen==1){
                chdir(getenv("HOME"));
                
            }
            else if(commandlen==2&&(strcmp(commandwords[1],"..")!=0&&strcmp(commandwords[1],"~")!=0&&strcmp(commandwords[1],"/")!=0)){
                if (strncmp(commandwords[1],"/Users",6)==0||strncmp(commandwords[1],"Users",5)==0){
                    chdir("/");
                }
                getcwd(currloc,100);
                strcat(currloc,"/");
                strcat(currloc,commandwords[1]);
                int result = chdir(currloc);
                if(result!=0){
                    printf("Directory not found\n");
                }
            }
            else if(commandlen==2&&(strcmp(commandwords[1],"..")==0)){
                chdir("..");
            }
            else if(strcmp(commandwords[1],"/")==0){
                chdir("/");
            }
            else if(commandlen==2&&(strcmp(commandwords[1],"~")==0)){
                chdir(getenv("HOME"));
            }
            else{printf("Inavalid command syntax");}
        }
        else if(strcmp(commandwords[0],"ls")==0){
            if(thread_flag==1){
                Thread_caller(commandwords);
            }
            else{
            chdir(daddyloc);
            if (commandlen==1){
                int pid = fork();
                if(pid==0){
                    execl("./ls","./ls",currloc,NULL);
                }
                wait(NULL);
            }
            if (commandlen==2){
                int pid = fork();
                if(pid==0){
                    execl("./ls","./ls",currloc,commandwords[1],NULL);
                }
                wait(NULL);
            }
            chdir(currloc);
        }
        }
        else if(strcmp(commandwords[0],"cat")==0){
            if(thread_flag==1){
                Thread_caller(commandwords);
            }
            else{
            chdir(daddyloc);
            if (commandlen==2){
                int pid = fork();
                if(pid==0){
                    execl("./cat","./cat",currloc,commandwords[1],NULL);
                }
                wait(NULL);
            }
            if (commandlen==3){
                int pid = fork();
                if(pid==0){
                    execl("./cat","./cat",currloc,commandwords[1],commandwords[2],NULL);
                }
                wait(NULL);
            }
            chdir(currloc);
        }
        }
        else if(strcmp(commandwords[0],"date")==0){
            if(thread_flag==1){
                Thread_caller(commandwords);
            }
            else{
            chdir(daddyloc);
            if (commandlen==1){
                int pid = fork();
                if(pid==0){
                    execl("./date","./date",currloc,NULL);
                }
                wait(NULL);
            }
            if (commandlen==2){
                int pid = fork();
                if(pid==0){
                    execl("./date","./date",currloc,commandwords[1],NULL);
                }
                wait(NULL);
            }
            chdir(currloc);
        }
        }
        else if(strcmp(commandwords[0],"rm")==0){
            if(thread_flag==1){
                Thread_caller(commandwords);
            }
            else{
            chdir(daddyloc);
            if (commandlen==2){
                int pid = fork();
                if(pid==0){
                    execl("./rm","./rm",currloc,commandwords[1],NULL);
                }
                wait(NULL);
            }
            if (commandlen==3){
                int pid = fork();
                if(pid==0){
                    execl("./rm","./rm",currloc,commandwords[1],commandwords[2],NULL);
                }
                wait(NULL);
            }
            chdir(currloc);
        }
        }
        else if(strcmp(commandwords[0],"mkdir")==0){
            if(thread_flag==1){
                Thread_caller(commandwords);
            }
            else{
            chdir(daddyloc);
            if (commandlen==2){
                int pid = fork();
                if(pid==0){
                    execl("./mkdir","./mkdir",currloc,commandwords[1],NULL);
                }
                wait(NULL);
            }
            if (commandlen==3){
                int pid = fork();
                if(pid==0){
                    execl("./mkdir","./mkdir",currloc,commandwords[1],commandwords[2],NULL);
                }
                wait(NULL);
            }
            chdir(currloc);
        }
        }
        else{
            printf("Invalid Syntax");
        }
    }
return 0;
}


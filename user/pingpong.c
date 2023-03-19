#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,char* argv[]){
    int pid=fork();
    int fds[2];
    pipe(fds);
    char buffer[100];
    int n;
    if(pid<0){
        return 1;
    }
    else if(pid==0){
        write(fds[1],"1",1);
    }
    else{
        int pid;
        n=read(fds[0],buffer,sizeof(fds));
        if(n>0){
            printf("%d:received ping",pid);
        }
    }
    exit(0);
}
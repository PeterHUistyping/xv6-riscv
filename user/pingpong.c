#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc,char* argv[]){
    int fds[2];
    int fds2[2];
    pipe(fds);
    pipe(fds2);
    char b1[100];
    char b2[100];
    char p1[4]="ping"; //a byte
    int n;
    int pid=fork();
    if(pid<0){
        return 1;
    }
    else if(pid==0){ //child
       
        close(fds[0]); // the other side
        n=read(fds2[0],b2,sizeof(fds));
        if(n>0){
            printf("%d: received %s\n",getpid(),b2);
        }
        write(fds[1],b2,4);
        close(fds[1]);
    }
    else{
        close(fds2[0]);
 
        write(fds2[1],p1,4);
        close(fds2[1]);
        n=read(fds[0],b1,sizeof(fds));
        if(n>0){
            printf("%d: received %s\n",getpid(),"pong");
        }
    }
    exit(0);
}
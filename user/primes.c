#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void filter(int * fds){
    int fds2[2]={0};
    pipe(fds2);
    int primes[35]={0};
    int index=0;
    while(!read(fds[0],&primes[index],sizeof(index))){  // read turns 0 when the write side of a pipe is closed.
        index++;
    }
    printf("primes %d\n",primes[0]);
    close(fds[0]);

    if(primes[0]==35){
        return;
    }
    for(int i=1;i<index;i++){
        
        if(primes[i]%primes[0]==0){
            printf("continue %d\n",primes[i]);
            continue;
        }
        printf("Write %d\n",primes[i]);
        write(fds2[1],&primes[i],sizeof(i));
    }
    close(fds2[1]);
    int pid=fork();
    if(pid==0){ //child
        filter(fds2);
    }
    else{
        //SHOULDN'T BE HERE
    }
}
int main(int argc,char* argv[]){
    int fds[2];
    
    pipe(fds);
    
    for(int i=2;i<=35;i++){
        write(fds[1],&i,sizeof(i));
    }
    close(fds[1]);
    filter(fds);
    wait((int *)0); // wait the entire pipe finished.
    exit(0);
}
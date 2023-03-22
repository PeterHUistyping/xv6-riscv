#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/fs.h"
 
char*
fmtname(char *path)
{
  static char buf[DIRSIZ+1];
  char *p;

  // Find first character after last slash.
  for(p=path+strlen(path); p >= path && *p != '/'; p--)
    ;
  p++;

  // Return blank-padded name.
  if(strlen(p) >= DIRSIZ)
    return p;
  memmove(buf, p, strlen(p));
  memset(buf+strlen(p), ' ', DIRSIZ-strlen(p));
  return buf;
}

void find(char *path, char *word ){
    // printf("path %s\n",path);
    char buf[512], *p;
    int fd;
    struct dirent de;
    struct stat st;

    if((fd = open(path, 0)) < 0){
        fprintf(2, "ls: cannot open %s\n", path);
        return;
    }

    if(fstat(fd, &st) < 0){
        fprintf(2, "ls: cannot stat %s\n", path);
        close(fd);
        return;
    }

    switch(st.type){
    case T_DEVICE:
    case T_FILE:
        if(strcmp(fmtname(path),word)==0){
            printf("%s %s %d %l\n", fmtname(path), path, st.ino, st.size);
        }
        
    break;

    case T_DIR:
        if(strlen(path) + 1 + DIRSIZ + 1 > sizeof buf){
        printf("ls: path too long\n");
        break;
    }
    strcpy(buf, path);
    p = buf+strlen(buf);
    *p++ = '/';
    // char new_path[512];
    // strcpy(new_path,buf);    
    while(read(fd, &de, sizeof(de)) == sizeof(de)){
        if(de.inum == 0)
        continue;
        memmove(p, de.name, DIRSIZ);
        p[DIRSIZ] = 0;
        if(stat(buf, &st) < 0){
            printf("ls: cannot stat %s\n", buf);
            continue;
        }
        if (strcmp(de.name, ".") == 0 || strcmp(de.name, "..") == 0){ //infinity loop
            // printf("skip %s\n");
            continue;
        }
        if(st.type==T_FILE){
            // printf("%s\n",p);
            if(strcmp(p ,word)==0){
                printf("%s\n",buf);
            }
        }
        else if (st.type==T_DIR){
            // printf("T_DIR%s\n",buf);
            find(buf,word);
        }

    }
    break;
    }
    close(fd);
}


int main(int argc,char* argv[]){
    // check parameter = 3
    // check argv[1] is dir
    find(argv[1],argv[2]);
    exit(0);
    
}
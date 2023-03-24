# xv6 (Unix Version 6)
A re-implementation of Unix Version 6 (v6).  It is specially implemented for a modern RISC-V multiprocessor using ANSI C.

## Instructions
https://pdos.csail.mit.edu/6.1810/,

https://pdos.csail.mit.edu/6.828/2022/schedule.html,

https://github.com/PeterHUistyping/Operating_System
```
make qemu
make grade
make qemu-gdb 
```
Debug
```
Open the container in a new windows.
gdb-multiarch kernel
target remote:25000
```
## Docker for arm64
sudo docker pull amd64/ubuntu:20.04

dpkg --print-architecture
```
DOCKER_BUILDKIT=0 docker build --platform linux/amd64  .
DOCKER_BUILDKIT=0 docker build -t xv6-riscv .
DOCKER_BUILDKIT=0 docker build --platform linux/amd64  -t xv6-riscv .
 
docker run --platform linux/amd64 -it  xv6-riscv  /bin/bash
docker run xv6-riscv uname -m
docker ps

docker exec -it <container> /bin/bash

docker exec -it fafa318d1cf1 /bin/bash
docker rm $(docker ps -a -q -f status=exited)
```

## OS
```
git checkout <branch name> to see all 13 branches.
```
QEMU: Terminated
Ctrl-a x

### 1. Unix util
```
git checkout util
```
**Reading**:
System call: fork, wait, exec, exit, cat, pipe (see xv6.pdf)<br/>
file descriptor dup <br/>
fork + close -> cat<br/>

Ctrl-p (ps), the kernel will print information about each process. <br/>

File System: inodes, dentry, softlink, file descriptors

i. **Implement** *sleep*<br/>
obtain the command-line arguments passed to a program<br/>
print an error message 
```
fprintf(2, "usage: grep pattern [file ...]\n");
exit(1)
```

ii. **Implement** *pingping*<br/>
1. Create two pipes for two-way communication:<br/> 
Otherwise, it will be received only by one side.
2. close the other side of the file descriptors.<br/> 
3. Transfer after receiving the message.
Otherwise, it will have output at the same time.
```
$ pingpong
34: :r erceeciveeid vpeidn gp
ong
```

iii. **Implement** *primes*<br/>
filter-and-pipeline <br/>
Need an iterative function. Create a pipe2, filter and write to the left side of pipe2. Then the right side of the pipe2 will be new iterative input to this function.


iv. **Implement** *find*<br/>
Using recursion to search inside the directory.
**Reading**:
System call: ls, passing in path<br/>
```
  struct dirent de;
  struct stat st;
```

v. **Implement** *args*<br/>
Read individual lines of input, a character at a time until a newline ('\n') appears.
```
echo hello too | xargs echo bye
```
### 2. System Call 
Using gdb/lldb

make qemu-gdb

**Reading**:
multiplexing, isolation, and interaction<br/>
Traps and system calls<br/>
The ecall instruction traps into the kernel and executes uservec, usertrap, and then syscall
**Implement** *Trace*<br/>
The trace system call should enable tracing for the process that calls it and any children that it subsequently forks, but should not affect other processes.
```
32 (1<<SYS_read) trace runs grep while tracing all system calls;
2147483647 (1<<31)  has all 31 low bits set.
```

_Trouble Shooting_
```
auto-loading has been declined by your `auto-load safe-path' set to "$debugdir:$datadir/auto-load".
```

This indicates that gdb is configured to disallow auto-loading. If auto-loading is disallowed and you start gdb in a directory that contains a .gdbinit file, gdb prints message "auto-loading has been declined" to alert you that the local gdbinit file is being ignored. Here is how to edit your user config file to allow auto-loading:

    Open your user config file ~/.gdbinit in an editor. If file doesn't yet exist, you will need to create it.
    Append this line verbatim:

      set auto-load safe-path /

    Save the file and exit your editor.
    Run gdb again. The previous warning should be gone and the local config file is now auto-loaded.

### Ref
## Push to Github Existing Repo
```
git remote add origin https://github.com/PeterHUistyping/xv6-riscv.git
git remote set-url origin https://github.com/PeterHUistyping/xv6-riscv.git
git remote -v
git push -u -f origin
```
## Github Display change to README.md
```
mkdir .github
cd .github
ln -s ../README.md README.md
```
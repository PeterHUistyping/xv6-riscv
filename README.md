# xv6
A re-implementation of Unix Version 6 (v6).  It is specially implemented for a modern RISC-V multiprocessor using ANSI C.

## Build and Running
You will need a RISC-V "newlib" tool chain from
https://github.com/riscv/riscv-gnu-toolchain, and qemu compiled for
riscv64-softmmu.  Once they are installed, and in your shell
search path, you can run "make qemu".

## Instructions
https://pdos.csail.mit.edu/6.1810/,
https://github.com/PeterHUistyping/Operating_System

## Push to Github Existing Repo
```
git remote add origin https://github.com/PeterHUistyping/xv6-riscv.git
git remote set-url origin https://github.com/PeterHUistyping/xv6-riscv.git
git remote -v
git push -u -f origin
```
## README.md
```
mkdir .github
cd .github
ln -s README.md README.md
```
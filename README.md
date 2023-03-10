# xv6 (Unix Version 6)
A re-implementation of Unix Version 6 (v6).  It is specially implemented for a modern RISC-V multiprocessor using ANSI C.

## Instructions
https://pdos.csail.mit.edu/6.1810/,
https://pdos.csail.mit.edu/6.828/2022/schedule.html,
https://github.com/PeterHUistyping/Operating_System

run "make qemu"

## OS
### Unix util
```
git checkout util
```

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
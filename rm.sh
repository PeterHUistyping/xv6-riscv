# make clean
echo clean
find . -type f -name '*.o' -delete
find . -type f -name '*.d' -delete
find . -type f -name '*.asm' -delete
find . -type f -name '*.sym' -delete
find . -type f -name '*.img' -delete
find . -type f -name '_*' -delete
find . -type f -name '*~' -delete
rm .gdbinit
rm xv6.out*
rm -r __pycache__
rm _*
rm kernel/kernel
rm vectors.S
rm bootblock
rm entryother
rm mkfs/mkfs
rm user/initcode
rm user/initcode.out
rm kernelmemfs
rm kernel/kernel
rm user/usys.S
rm .gdbinit
rm myapi.key
rm *-handin.tar.gz
rm xv6.out*
rm .vagrant/
rm ph
rm barrier
rm /lab-*.json

FROM amd64/ubuntu:20.04

RUN apt-get -qq update 
RUN ln -fs /usr/share/zoneinfo/Europe/London /etc/localtime 
#     dpkg-reconfigure -f noninteractive tzdata

 
RUN apt-get install -y \
                    git \
                    build-essential \ 
                    gdb-multiarch \
                    ack \ 
                    vim

RUN apt-get install -y \
                    qemu-system-misc \
                    gcc-riscv64-linux-gnu \
                    binutils-riscv64-linux-gnu 
 
                                 
WORKDIR /xv6-riscv

ADD . /xv6-riscv/

CMD ["/bin/bash"]
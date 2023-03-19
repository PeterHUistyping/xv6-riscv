FROM --platform=linux/amd64 ubuntu:20.04

RUN apt-get -qq update 
RUN ln -fs /usr/share/zoneinfo/Europe/London /etc/localtime 
#     dpkg-reconfigure -f noninteractive tzdata

# RUN apt-get install -y \
#                     build-essential \
#                     gdb \
#                     gcc-multilib-x86-64-linux-gnu \
#                     tmux \
#                     qemu-system-x86 \
#                     gawk \
#                     expect
RUN apt-get install -y \
                    git \
                    build-essential \ 
                    gdb-multiarch \
                    qemu-system-misc \
                    gcc-riscv64-linux-gnu \
                    binutils-riscv64-linux-gnu \
                    riscv-tools
WORKDIR /xv6-riscv

ADD . /xv6-riscv/

ENV TOOLPREFIX=x86_64-linux-gnu-

CMD ["/bin/bash"]
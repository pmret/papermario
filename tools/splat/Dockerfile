FROM ubuntu:22.04
RUN apt-get update
RUN apt install -y binutils-mips-linux-gnu
ADD https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz .
ADD https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz .
RUN  mkdir -p ./gcc-2.7.2 && \
     tar -xvf gcc-2.7.2-linux.tar.gz -C ./gcc-2.7.2 && \
     tar -xvf binutils-2.6-linux.tar.gz -C ./gcc-2.7.2

FROM ubuntu:18.04 as build

RUN apt-get update && \
    apt-get install -y \
        binutils-mips-linux-gnu \
        build-essential \
        pkg-config \
        python3 \
	python3-pip \
        wget \
	git \
	unzip \
	nano \
	libcapstone-dev \
	libyaml-dev \
	zlib1g-dev \
	vbindiff \
	bison \
	flex \
	texinfo


# Install qemu-irix
RUN wget \
        https://github.com/n64decomp/qemu-irix/releases/download/v2.11-deb/qemu-irix-2.11.0-2169-g32ab296eef_amd64.deb \
        -O qemu.deb && \
    echo 8170f37cf03a08cc2d7c1c58f10d650ea0d158f711f6916da9364f6d8c85f741 qemu.deb | sha256sum --check && \
    dpkg -i qemu.deb && \
    rm qemu.deb


# Build binutils
RUN wget https://ftp.gnu.org/gnu/binutils/binutils-2.34.tar.bz2 -O binutils.tar.bz2
RUN tar xjf binutils.tar.bz2
RUN mkdir -p /opt/cross

# mips-linux-gnu
RUN mkdir build-binutils && cd build-binutils
RUN /binutils-2.34/configure --target=mips-linux-gnu --prefix=/opt/cross --disable-gprof --disable-gdb --disable-werror
RUN make && make install

# mips-sgi-irix5
RUN make distclean
RUN /binutils-2.34/configure --target=mips-sgi-irix5 --prefix=/opt/cross --disable-gprof --disable-gdb --disable-werror
RUN make && make install

RUN rm binutils.tar.bz2
ENV PATH="/opt/cross/bin:${PATH}"


# Install python dependencies
RUN python3 -m pip install --user colorama ansiwrap attrs watchdog python-Levenshtein


# Build capstone
RUN git clone https://github.com/aquynh/capstone.git && \
    cd capstone && \
    git checkout tags/4.0 && \
    ./make.sh && \
    ./make.sh install


RUN mkdir /pm
WORKDIR /pm

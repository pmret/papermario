FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

COPY requirements.txt /
COPY requirements_extra.txt /
COPY install.sh /
COPY install_compilers.sh /

RUN apt-get update && ./install.sh --extra && ./install_compilers.sh

RUN mkdir /papermario
WORKDIR /papermario

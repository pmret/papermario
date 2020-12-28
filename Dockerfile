FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

RUN sudo ./install.sh

RUN mkdir /papermario
WORKDIR /papermario

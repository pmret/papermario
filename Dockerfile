FROM ubuntu:20.04 as build

ENV DEBIAN_FRONTEND=noninteractive

RUN apt-get update && \
    apt-get install -y \
      astyle \
      binutils-mips-linux-gnu \
      build-essential \
      git \
      less \
      libglib2.0 \
      python3 \
      python3-pip \
      unzip \
      wget

RUN python3 -m pip install \
      attrs capstone lark pyyaml pycparser \
      colorama ansiwrap watchdog python-Levenshtein cxxfilt \
      python-ranges \
      pypng

RUN mkdir /papermario
WORKDIR /papermario

FROM ubuntu:latest

RUN apt-get update
RUN apt-get install -y \
build-essential \
gdb \
valgrind \
vim

WORKDIR /usr/src/cpp

COPY . /usr/src/cpp

RUN make

FROM ubuntu:latest

ENV APP_HOME=/usr/src/cpp/ex00

WORKDIR $APP_HOME

COPY . $APP_HOME

RUN apt-get update

RUN apt-get install -y g++ make gdb valgrind

RUN make

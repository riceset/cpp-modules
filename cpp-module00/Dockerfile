FROM ubuntu:latest

ENV APP_HOME=/usr/src/cpp/

WORKDIR $APP_HOME

COPY . $APP_HOME

RUN apt-get update

RUN apt-get install -y g++ make gdb valgrind

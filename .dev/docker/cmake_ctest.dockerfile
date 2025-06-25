FROM ubuntu:24.04
SHELL ["/bin/bash", "-c"]
ENV LANG=C.UTF-8

RUN mkdir /app
COPY ./cbflib /app/cbflib

RUN apt-get update && \
  apt-get install -y build-essential git cmake default-jdk gfortran links m4 python3-dev python3-numpy-dev swig

RUN cd /app/cbflib && \
  cmake . && \
  cmake --build . --parallel `nproc`

RUN cd /app/cbflib && \
  ctest --parallel `nproc`

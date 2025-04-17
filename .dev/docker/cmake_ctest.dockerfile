FROM ubuntu:24.04
SHELL ["/bin/bash", "-c"]

RUN mkdir /app
COPY ./cbflib /app/cbflib

RUN apt-get update && \
  apt-get install -y build-essential git cmake gfortran libtiff-dev m4

RUN cd /app/cbflib && \
  cmake . && \
  make -j4

RUN cd /app/cbflib && \
  ctest -j4

FROM ubuntu:24.04
SHELL ["/bin/bash", "-c"]

RUN mkdir /app
COPY ./cbflib /app/cbflib

RUN apt-get update && \
  apt-get install -y build-essential git cmake default-jdk gfortran m4 swig

RUN cd /app/cbflib && \
  cmake . && \
  cmake --build . --parallel 4

RUN cd /app/cbflib && \
  ctest --parallel 4

FROM ubuntu:24.04
SHELL ["/bin/bash", "-c"]
ENV LANG=C.UTF-8

RUN mkdir /app
COPY ./cbflib /app/cbflib

RUN apt-get update && \
  apt-get install -y bison build-essential git wget libjpeg-dev m4 automake libpcre2-dev liblzma-dev links python3-build python3-dev python3-numpy-dev python3-setuptools python3-venv rsync gfortran libz-dev

RUN cd /app/cbflib && \
  make all

RUN cd /app/cbflib && \
  make tests 2>&1 | tee test.out

RUN ! grep -a ignored /app/cbflib/test.out

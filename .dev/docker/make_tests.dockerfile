FROM ubuntu:24.04
SHELL ["/bin/bash", "-c"]

RUN mkdir /app
COPY ./cbflib /app/cbflib

RUN apt-get update && \
  apt-get install -y build-essential git wget libjpeg-dev m4 automake libpcre2-dev byacc liblzma-dev rsync gfortran libz-dev

RUN mkdir -p ~/miniconda3 && \
  wget https://repo.anaconda.com/miniconda/Miniconda3-latest-Linux-x86_64.sh -O ~/miniconda3/miniconda.sh && \
  bash ~/miniconda3/miniconda.sh -b -u -p /usr/share/miniconda && \
  rm ~/miniconda3/miniconda.sh

RUN source /usr/share/miniconda/etc/profile.d/conda.sh && \
  conda create -y -n build -c conda-forge python=3.11 python-build && \
  conda create -y -n test -c conda-forge python=3.11 numpy matplotlib

RUN cd /app/cbflib && \
  source /usr/share/miniconda/etc/profile.d/conda.sh && \
  conda activate build && \
  make all

RUN cd /app/cbflib && \
  source /usr/share/miniconda/etc/profile.d/conda.sh && \
  conda activate test && \
  make tests

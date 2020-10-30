FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update
RUN apt-get -y install apt-utils
RUN apt-get -y install git
RUN apt-get -y install cmake
RUN apt-get -y install make
RUN apt-get -y install g++

ADD ./lib/oatpp /app/fid/lib/oatpp

WORKDIR /app/fid/lib/oatpp/utility

RUN ./install-oatpp-modules.sh

COPY ./src /app/fid/src

WORKDIR /app/fid

COPY ./CMakeLists.txt /app/fid

RUN mkdir build && cd build && cmake .. && make

ENTRYPOINT ["/bin/bash"]
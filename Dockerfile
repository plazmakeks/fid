FROM ubuntu:20.04

ARG DEBIAN_FRONTEND=noninteractive

RUN apt-get update && apt-get install -y \
    apt-utils \
    git \
    cmake \
    make \
    g++

ADD ./lib/oatpp /app/oatpp-test/lib/oatpp

WORKDIR /app/oatpp-test/lib/oatpp/utility

RUN ./install-oatpp-modules.sh

COPY ./src /app/oatpp-test/src

WORKDIR /app/oatpp-test

COPY ./CMakeLists.txt /app/oatpp-test

RUN mkdir build && cd build && cmake .. && make

EXPOSE 8000

WORKDIR /app/oatpp-test/build

ENTRYPOINT ["./rest-api"]
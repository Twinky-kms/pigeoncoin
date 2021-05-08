FROM debian:stretch
LABEL maintainer="Pigeoncoin Developers <dev@pigeoncoin.org>"
LABEL description="Dockerised PigeoncoinCore, built from Travis"

RUN apt-get update && apt-get -y upgrade && apt-get clean && rm -fr /var/cache/apt/*

COPY bin/* /usr/bin/

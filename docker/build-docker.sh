#!/usr/bin/env bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR/..

DOCKER_IMAGE=${DOCKER_IMAGE:-pigeoncoin/pigeoncoind-develop}
DOCKER_TAG=${DOCKER_TAG:-latest}

BUILD_DIR=${BUILD_DIR:-.}

rm docker/bin/*
mkdir docker/bin
cp $BUILD_DIR/src/pigeoncoind docker/bin/
cp $BUILD_DIR/src/pigeoncoin-cli docker/bin/
cp $BUILD_DIR/src/pigeoncoin-tx docker/bin/
strip docker/bin/pigeoncoind
strip docker/bin/pigeoncoin-cli
strip docker/bin/pigeoncoin-tx

docker build --pull -t $DOCKER_IMAGE:$DOCKER_TAG -f docker/Dockerfile docker

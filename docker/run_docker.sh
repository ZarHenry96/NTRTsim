#!/usr/bin/env bash

# allow access to X server
xhost +

# launcher configuration
PWD=$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )
SRC_DIR=$PWD/../
DOCKER_IMAGE=ubuntu-local-dev

docker run -it --rm -w "/home/ntrt"\
  --volume ${SRC_DIR}:/home/ntrt:rw\
  -v /tmp/.X11-unix:/tmp/.X11-unix \
  -e DISPLAY=:0 \
  --device /dev/dri/ \
  ${DOCKER_IMAGE} /bin/bash

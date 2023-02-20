#!/bin/bash

if [ "$#" -ne 1 ]; then
    printf "Usage: %s <pid>\n" "$0"
    exit 1
fi

kill -s QUIT "$1"

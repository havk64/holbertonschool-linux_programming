#!/bin/bash
# Sends the signal SIGQUIT to a process, given its PID

usage(){
    printf "Usage: %s <pid>\n" "${BASH_SOURCE}"
    exit 1
}

[ "$#" != 1 ] && usage

kill -SIGINT "$1"
exit

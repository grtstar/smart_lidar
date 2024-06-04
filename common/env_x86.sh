#!/bin/bash

SCRIPT_DIR=$(cd $(dirname ${BASH_SOURCE[0]}); pwd)
export COMMON_DIR=$SCRIPT_DIR/x86
echo "Set COMMON_DIR to $COMMON_DIR"
export PATH=$PATH:$COMMON_DIR/bin
export LD_LIBRARY_PATH=$COMMON_DIR/lib:$LD_LIBRARY_PATH
export PYTHONPATH=$COMMON_DIR/lib/python3/dist-packages:$PYTHONPATH
alias cmakex='cmake ..  -DCMAKE_INSTALL_PREFIX=$COMMON_DIR -DCMAKE_INSTALL_PREFIX=$COMMON_DIR'
alias cmakexg='cmake .. -G Ninja -DCXX11=ON -DCMAKE_INSTALL_PREFIX=$COMMON_DIR -DCMAKE_INSTALL_PREFIX=$COMMON_DIR'
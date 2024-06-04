#!/bin/bash

SCRIPT_DIR=$(cd $(dirname ${BASH_SOURCE[0]}); pwd)
export TOP_DIR=$SCRIPT_DIR
export COMMON_DIR=$SCRIPT_DIR/arm
export EXE_DIR=$SCRIPT_DIR/x86
export COMPLIE_DIR=$SCRIPT_DIR/../../toolchain
export SYSROOT=$SCRIPT_DIR/../sysroot
echo "Set COMMON_DIR to $COMMON_DIR"
export PATH=$PATH:$EXE_DIR/bin:$COMPLIE_DIR/bin
export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:$SYSROOT/usr/lib:$SYSROOT/lib:$COMMON_DIR/lib
alias cmaker='cmake .. -DCMAKE_INSTALL_PREFIX=$COMMON_DIR -DCMAKE_TOOLCHAIN_FILE=$TOP_DIR/toolchain.cmake'

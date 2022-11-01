#!/usr/bin/env bash

THIS_DIR=$( cd -- "$( dirname -- "${BASH_SOURCE[0]}" )" &> /dev/null && pwd )

cwd=$(pwd)

cd ../openblt/Host/Source/LibOpenBLT/build
cmake ..
make

cd $THIS_DIR
cd ../openblt/Host/Source/BootCommander/build
cmake ..
make

cd $THIS_DIR
cp ../openblt/Host/BootCommander $THIS_DIR



#!/usr/bin/env bash
# bitcoin2network Developers 2018
# use this installer to clone-and-compile bitcoin2network in one line
# supports Ubuntu 16 LTS

sudo apt-get update
yes "" | sudo apt-get install build-essential python-dev gcc-4.9 g++-4.9 git cmake libssl-dev libboost-all-dev
export CXXFLAGS="-std=gnu++11"
git clone https://github.com/b2n-project/bitcoin2network
cd bitcoin2network
mkdir build && cd $_
cmake ..
make

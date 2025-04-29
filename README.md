# libo-c
A library that includes optional versions of the multi system compiling project headers.

## Build

#### 1. Clone Source
    git clone https://github.com/CoderRC/libo-c.git
    cd libo-c

#### 2. Build
    mkdir build
    cd build
    ../configure
    make

## Install
    make install

## Requirements

Download a sh command line environment to run configure.

Download git to use the git command for cloning the source.

Download make to compile the library.

Download gcc with posix c functions to compile the source and configure it.

If the gcc is mingw and the sh command line environment supports the pacman command do

    pacman -S git
    pacman -S make
    pacman -S mingw-w64-x86_64-gcc
    git clone https://github.com/CoderRC/libmingw32_extended.git
    cd libmingw32_extended
    mkdir build
    cd build
    ../configure
    make
    make install
    cd ../..
    git clone https://github.com/CoderRC/libo-c.git
    cd libo-c
    mkdir build
    cd build
    ../configure LDFLAGS=-lmingw32_extended
    make

If the sh command line environment supports the pacman command do

    pacman -S git
    pacman -S make
    pacman -S gcc

## Contributing to the source

To properly add new headers to the repository, the headers must be added to the include directory in the repository and in the configure file add paths to the INCLUDE_FILES.

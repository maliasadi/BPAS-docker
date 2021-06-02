FROM gcc:7.5

ENV CMAKE_J 6
ENV NTL_VERSION 11.4.4
ENV MPSOLVE_VERSION 3.1.4
ENV MAPLE_VERSION 2021

ENV GCC_8_ROOT="/usr/lib/gcc"
ENV C_INCLUDE_PATH="$GCC_8_ROOT/x86_64-linux-gnu/8/include:$C_INCLUDE_PATH"

RUN apt-get update && \ 
	apt-get upgrade -y && \ 
	apt-get install m4 libgmp-dev cmake cmake-curses-gui libblas-dev liblapack-dev -y

WORKDIR /usr/src/ntl

RUN	set -ex && \
	wget -O ntl-$NTL_VERSION.tar.gz "https://libntl.org/ntl-$NTL_VERSION.tar.gz" && \
	tar -xf ntl-$NTL_VERSION.tar.gz && \
	rm ntl-$NTL_VERSION.tar.gz && \
	cd ./ntl-$NTL_VERSION/src && \
	./configure && \
	make && \
	make install

WORKDIR /usr/src/mpsolve

RUN	set -ex && \
	wget -O mpsolve-$MPSOLVE_VERSION.tar.gz "http://numpi.dm.unipi.it/_media/software/mpsolve/mpsolve-$MPSOLVE_VERSION.tar.gz" && \
	tar -xf mpsolve-$MPSOLVE_VERSION.tar.gz && \
	rm mpsolve-$MPSOLVE_VERSION.tar.gz && \
	cd ./mpsolve-$MPSOLVE_VERSION && \
	./configure && \
	make && \
	make install && \
	ldconfig

ENV LIBRARY_PATH="/usr/local/lib:$LIBRARY_PATH"
ENV LD_LIBRARY_PATH="/usr/local/lib:$LD_LIBRARY_PATH"
ENV C_INCLUDE_PATH="/usr/src/mpsolve/mpsolve-$MPSOLVE_VERSION/include:$C_INCLUDE_PATH"
ENV CPLUS_INCLUDE_PATH="/usr/src/mpsolve/mpsolve-$MPSOLVE_VERSION/include:$CPLUS_INCLUDE_PATH"

WORKDIR /usr/src/ 

RUN	set -ex && \
	wget -O BPAS.tar.gz "http://www.bpaslib.org/src/bpas_src.tar.gz" && \
	tar -xf BPAS.tar.gz && \
	rm BPAS.tar.gz && \
	cd ./BPAS && \
	mkdir build && \
	cd build 

ENV BPAS_HOME="/usr/src/BPAS"
ENV LIBRARY_PATH="$LIBRARY_PATH:$BPAS_HOME/src"
ENV LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$BPAS_HOME/src"
ENV CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:$BPAS_HOME/include"
ENV LIBRARY_PATH="$LIBRARY_PATH:$BPAS_HOME/build"

ENV MAPLE_HOME="/opt/maple$MAPLE_VERSION"
ENV LIBRARY_PATH="$LIBRARY_PATH:$MAPLE_HOME/bin.X86_64_LINUX"
ENV LD_LIBRARY_PATH="$LD_LIBRARY_PATH:$MAPLE_HOME/bin.X86_64_LINUX"
ENV CPLUS_INCLUDE_PATH="$CPLUS_INCLUDE_PATH:$MAPLE_HOME/extern/include"
ENV MAPLE="$MAPLE_HOME"

WORKDIR /usr/src/BPAS/build  

RUN	set -ex && \	
	cmake .. && \
	make -j$CMAKE_J && \
	make check -j$CMAKE_J && \
	make sanity-tests
	# make install is optional; it will copy library and headers to /usr  

CMD ["echo", "BPAS is successfully installed."]

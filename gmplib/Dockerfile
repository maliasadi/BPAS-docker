FROM gcc

ENV GMP_VERSION 6.2.1

COPY . /usr/src/gmplib
WORKDIR /usr/src/gmplib

RUN apt-get install m4 -y

RUN	set -ex && \
	wget -O gmp-$GMP_VERSION.tar.xz "https://gmplib.org/download/gmp/gmp-$GMP_VERSION.tar.xz" && \
	tar -xf gmp-$GMP_VERSION.tar.xz && \
	rm gmp-$GMP_VERSION.tar.xz && \
	cd ./gmp-$GMP_VERSION && \
	./configure && \
	make && \
	make check && \
	make install

RUN g++ -o gmp_test.bin gmp_test.cpp -lgmp

CMD ["./test.bin"]


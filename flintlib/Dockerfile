FROM gcc

ENV FLINT_VERSION 2.7.1

WORKDIR /usr/src/flintlib

RUN apt-get update && \ 
	apt-get upgrade -y && \ 
	apt-get install m4 libgmp-dev libmpfr-dev libmpfr-doc -y

RUN	set -ex && \
	wget -O flint-$FLINT_VERSION.tar.gz "http://www.flintlib.org/flint-$FLINT_VERSION.tar.gz" && \
	tar -xf flint-$FLINT_VERSION.tar.gz && \
	rm flint-$FLINT_VERSION.tar.gz && \
	cd ./flint-$FLINT_VERSION && \
	./configure && \
	make && \
	make -j4 check && \
	make install

CMD ["echo", "FLINT-$FLINT_VERSION is successfully installed."]
 
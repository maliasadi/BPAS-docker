FROM gcc

ENV NTL_VERSION 11.4.4

WORKDIR /usr/src/ntllib

RUN apt-get update && \ 
	apt-get upgrade -y && \ 
	apt-get install m4 libgmp-dev -y 

RUN	set -ex && \
	wget -O ntl-$NTL_VERSION.tar.gz "https://libntl.org/ntl-$NTL_VERSION.tar.gz" && \
	tar -xf ntl-$NTL_VERSION.tar.gz && \
	rm ntl-$NTL_VERSION.tar.gz && \
	cd ./ntl-$NTL_VERSION/src && \
	./configure && \
	make && \
	make check && \
	make install

CMD ["echo", "NTL-$NTL_VERSION is successfully installed."]
 
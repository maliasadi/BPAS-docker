FROM gcc

ENV MPSOLVE_VERSION 3.1.4
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

CMD ["echo", "MPSolve-$MPSOLVE_VERSION is successfully installed."]
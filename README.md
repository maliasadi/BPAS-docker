A collection of Dockerfiles for
- BPAS ([bpaslib.org](http://bpaslib.org)) -> bpaslib/Dockerfile
- GMP ([gmplib.org](https://gmplib.org)) -> gmplib/Dockerfile
- NTL ([libntl.org](https://libntl.org)) -> ntllib/Dockerfile
- FLINT ([flintlib.org](http://flintlib.org/)) -> flintlib/Dockerfile
- MPSolve ([numpi.dm.unipi.it/software/mpsolve](https://numpi.dm.unipi.it/software/mpsolve)) -> mpsolvelib/Dockerfile


To build and run the BPAS image:
```Bash
$ cd ./BPAS-docker/bpaslib
$ docker build -t bpaslib .
$ docker run --name=bpas-container bpaslib 
```


Please let me know if you find any issues or have any comments. 
run on machine

```
$ cd lib/oatpp/utility && ./install-oatpp-modules.sh
$ cd ../../../ && mkdir build && cd build
$ cmake .. && make
``` 

run in docker

```
$ docker build -t fid .
$ docker run -p 8000:8000 fid
```
These files are intended to approximately reproduce the corresponding
scripts in cbflib/.github/workflows. With a correctly configured Docker
installation, you can build one according to this example:

```
$ docker build -f cmake_ctest.dockerfile -t cbflib_cmct --progress=plain --no-cache ../../..
```

Note that we build in the directory three levels above this one so that we can
copy this repo into the image.

To start an interactive container in the resulting image, type:

```
$ docker run -it cbflib_cmct
```

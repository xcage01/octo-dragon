# Octo-Dragon

[![Join the chat at https://gitter.im/xcage01/octo-dragon](https://badges.gitter.im/xcage01/octo-dragon.svg)](https://gitter.im/xcage01/octo-dragon?utm_source=badge&utm_medium=badge&utm_campaign=pr-badge&utm_content=badge)

Octo-Dragon brings together the power of c++ with the simplicity of django

## Status

Currently this project is under development. Any issues or suggestions are
appreciated. It has a dependency of libmicrohttpd from GNU for compiling the
codebase.

## Install

```
cmake
make
```
Or

```
make -f Makefile_test
```

## Run
You should add username and password about your database at runServer in src/app.cc

```
mysql.server start
./app server
```

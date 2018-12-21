
# Collection Framework Shared Library

This is an effor to create a libary which will provide basic functionallty for follwing types of collections.

- Vector
- List
- Set
- Stack
- Queue
- Tree
- Graph
- Hashtable/Map

**Note** This is an effort to write my own implementation and create a library around basic data structures instead of using third party library. This is still **work in progress**

## Build

To generate share library run below commands from libc directory

```shell
  $ make clean
  $ make
```

This will generate libcollection.so(or .dll) on libc directory.

## Install

### Linux

#### Headers

Copy header files(include/*.h) to GCC default include path. This can be found by running following command. Typically this path can be /usr/lib or /usr/local/lib.

```shell
  $ echo | gcc -E -Wp,-v -
```

#### Library

To install the shared library copy it to your library path. This can be found by running following command. Typically this path can be /usr/lib or /usr/local/lib.

```shell
  $ ldconfig -v 2>/dev/null | grep -v ^$'\t'
```

### Windows

#### Headers

Same as Linux setup.

#### Library

- Copy libcollection.dll to any folder. Say c:\temp\lib
- set LIBARY_PATH environment varible to the above directory.

```bat
c:\> set LIBRARY_PATH=c:\temp\lib:%LIBRARY_PATH%
```

# Run

Run following command.

```shell
  $ gcc source_file.c -lcollection
```

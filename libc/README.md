# build object file
$ gcc -o graph.o -c graph.c

# Create .a file using for static linking
$ ar rc libds.a graph.o

## Optional - Rebuild index of archieve 
$ ranlib libds.a

# Create a shared library(so in unix)
$ gcc -shared -o libds.so graph.o

# Create a shared library(dll in windows)
$ gcc -shared -o libds.dll graph.o

$ gcc prog.c -L{path to file containing library} -l${library-name} -I "path to header files"
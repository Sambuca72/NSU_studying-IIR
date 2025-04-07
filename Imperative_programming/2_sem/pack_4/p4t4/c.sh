gcc -c -fPIC core.c
gcc -shared -o libcore.so core.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
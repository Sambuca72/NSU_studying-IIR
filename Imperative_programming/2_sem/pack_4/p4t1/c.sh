gcc -c -fPIC integerset.c
gcc -shared -o libintegerset.so integerset.o
export LD_LIBRARY_PATH=.:$LD_LIBRARY_PATH
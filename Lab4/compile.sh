# eliminamos los archivos anteriores
rm main.o psinfo.o psinfo.out

# compilacion de los archivos .o
gcc main.c -o main.o -c
gcc psinfo.c -o psinfo.o -c

# compilacion del proyecto
gcc -o psinfo.out main.o psinfo.o

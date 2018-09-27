# eliminamos los archivos anteriores
rm main.o psinfo.o psinfo.out report.o error.o

# compilacion de los archivos .o
gcc main.c -o main.o -c
gcc psinfo.c -o psinfo.o -c
gcc report.c -o report.o -c
gcc error.c -o error.o -c

# compilacion del proyecto
gcc -o psinfo.out main.o psinfo.o report.o error.o

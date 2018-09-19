#include <stdio.h>

double calcularMediaMaterias(double *array, int materias, int alumnos){
    double suma = 0;
    double vector[materias];
    //double *p;
    for (int i = 0; i < materias; i++) {
        for (int j = 0; j < alumnos; j++) {
            suma = suma + *(array + i + j);
        }
        *(vector + i) = suma / alumnos;
        suma = 0;
    }
    return *vector;

}

double calcularMediaAlumnos(double *array, int alumnos, int materias){
    double suma = 0;
    double vector[alumnos];
    double *p = array;
    for (int j = 0; j < alumnos; j++) {
        for (int i = 0; i < materias; i++) {
            suma = suma + *p;
            p++;
        }
        *(vector + j) = suma / materias;
        suma = 0;
    }
    return *vector;
}

int main(){
    int numAlumnos = 0;
    double mediaAlumnos[numAlumnos];
    double mediaMaterias[5];
        
    printf("ingrese el numero de alumnos de la clase: \n");
    scanf("%d",&numAlumnos);
    
    double notas[5][numAlumnos];
    
    for (int j = 0; j < numAlumnos; j++) {
        for (int i = 0; i < 5; i++) {
            printf("ingrese la nota para la materia %d para el alumno %d", (i + 1), (j + 1));
            scanf("%lf",&notas[j][i]);
        }
    }
    *mediaAlumnos = calcularMediaAlumnos(&notas[0][0], numAlumnos, 5);
    *mediaMaterias = calcularMediaMaterias(&notas[0][0], 5, numAlumnos);  
    for (int i = 0; i < 5; i++){
        printf("El promedio de la materia %d es: %.2lf", (i + 1), *(mediaMaterias + i));
    }

    for (int i = 0; i < numAlumnos; i++){
        printf("El promedio del alumno %d es: %.2lf", (i + 1), *(mediaAlumnos + i));
    }
           
    return 0;
}
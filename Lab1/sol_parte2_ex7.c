/**
 * @file ejercicio4a.c
 * @author labSO
 * @date 30/07/2018
 * @brief Archivo con codigo de trabajo para ecuaciones cuadraticas.
 *
 * Este codigo se enfoca solo en la parte a del ejercicio 6
 *
 * Nota: Usar -lm para compilar. Por ejemplo:
 *
 * gcc ejercicio6_ab.c -Wall -lm -o ejercicio6_ab.out
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* DECLARACION DE FUNCIONES */

double discriminante(double a, double b, double c);
void bachiller(double a, double b, double c);
void print_raices_diferentes(double r1, double r2);
void print_raices_iguales(double r);
void print_raices_complejas(double p_re, double p_im);

/* FUNCION MAIN*/

int main () {
    double a,b,c = 0;
    printf("El siguiente programa entrega las raices de una ecuacion cuadratica\n");
    printf("aX^2 + bX + c\n");
    printf("para finalizar el programa ingrese un numero (<= 0)\n");
    printf("ingrese el valor del coeficiente a donde (a>0): ");
    scanf("%lf\n",&a);
    printf("ingrese el valor del coeficiente a donde (b>0): ");
    scanf("%lf\n",&b);
    printf("ingrese el valor del coeficiente a donde (c>0): ");
    scanf("%lf\n\n",&c);
    while (a > 0 && b > 0 && c > 0) {
        
        printf("El resultado para a=%lf, b=%lf,c=%lf es:\n",a,b,c);
        bachiller(a, b, c);
        
        printf("\n\n");
        
        printf("El siguiente programa entrega las raices de una ecuacion cuadratica\n");
        printf("aX^2 + bX + c\n");
        printf("para finalizar el programa ingrese un numero (<= 0)\n");
        printf("ingrese el valor del coeficiente a donde (a>0): ");
        scanf("%lf\n",&a);
        printf("ingrese el valor del coeficiente a donde (b>0): ");
        scanf("%lf\n",&b);
        printf("ingrese el valor del coeficiente a donde (c>0): ");
        scanf("%lf\n",&c);
    }
 /*   printf("1 2 2\n");
    printf("1 3 2\n");
    printf("1 2 1\n");
    printf("2 3 1\n");
    printf("2.1 3.2 1.7\n");
    printf("2 2 0.5\n");
    printf("\n");
    bachiller(1, 2, 2);
    bachiller(1, 3, 2);
    bachiller(1, 2, 1);
    bachiller(2, 3, 1);
    bachiller(2.1, 3.2, 1.7);
    bachiller(2, 2, 0.5);*/
    return 0;
}

/* DEFINICION DE FUNCIONES */

/**
 * @brief Metodo que calcula el discriminante de una ecuacion cuadratica a*x^2 + b*x + c
 * @param a coeficiente de x^2
 * @param b coeficiente de x
 * @param c coeficiente independiante
 * @return el valor de la expresion asociada el discriminante: b^2 - 4*a*c
 */

double discriminante(double a, double b, double c) {
    double D = pow(b,2) - 4*a*c;
    return D;
}

/**
 * @brief Metodo que calcula e imprime las raices de una ecuacion cuadratica: a*x^2 + b*x + c = 0
 * @param a coeficiente de x^2
 * @param b coeficiente de x
 * @param c coeficiente independiante
 * @return void
 */

void bachiller(double a, double b, double c) {
    double x1, // Raiz 1
    x2, // Raiz 2
    R,  // Parte real de una raiz si es compleja
    I;  // Parte imaginaria de una raiz si es compleja
    
    int dis;   // Discriminante
    dis = discriminante(a, b, c);
    if(dis > 0) {
        x1 = (-b - sqrt(dis))/(2*a); // Se esta haciendo cast al numerador para forzar resultado double
        x2 = (-b + sqrt(dis))/(2*a);
        print_raices_diferentes(x1, x2);
    }
    else if(dis == 0) {
        x1 = x2 = (-b)/(2*a); // Se esta haciendo cast al numerador
        print_raices_iguales(x1);
    }
    else {
        R = (-b)/(2*a);
        I = sqrt(-dis)/(2*a);
        print_raices_complejas(R, I);
    }
}

/**
 * @brief que imprime las raices de una ecuacion cuadratica cuando son reales y distintas
 * @param r1 es la primera raiz
 * @param r2 es la segunda raiz
 * @return void
 */

void print_raices_diferentes(double r1, double r2){
    printf("%.2f, %.2f\n", r1, r2);
}

/**
 * @brief que imprime las raices de una ecuacion cuadratica cuando son reales e iguales
 * @param r es la raiz
 * @return void
 */

void print_raices_iguales(double r){
    printf("%.2f con multiplicidad 2\n", r);
}

/**
 * @brief que imprime las raices de una ecuacion cuadratica cuando son complejas conjugadas
 * @param p_re es la parte real
 * @param p_im es la parte imaginaria
 * @return void
 */

void print_raices_complejas(double p_re, double p_im){
    if((p_re > 0) & (p_im > 0)) {
        // Forma de impresion: p_re+ p_imj, p_re - p_imj
        printf("%.2f + %.2fj, %.2f - %.2fj\n", p_re, p_im, p_re, p_im);
    }
    else if ((p_re < 0) & (p_im > 0)) {
        // Forma de impresion: (-p_re) + p_imj, (-p_re) - p_imj
        printf("(%.2f) + %.2fj, (%.2f) - %.2fj\n", p_re, p_im, p_re, p_im);
    }
    else if ((p_re == 0) & (p_im > 0)) {
        // Forma de impresion: p_imj, (-p_im)j
        printf("%.2fj, (-%.2f)j\n", p_im, p_im);
    }
    else if ((p_re == 0) & (p_im < 0)) {
        // Forma de impresion: (-p_im)j, -p_imj
        printf("(%.2f)j, %.2fj\n", p_im, -p_im);
    }
    else if ((p_re < 0) & (p_im > 0)) {
        // Forma de impresion: (-p_re) + p_imj, (-p_re) - p_imj
        printf("(%.2f) + %.2fj, (%.2f) - %.2fj\n", p_re, p_im, p_re, p_im);
    }
    else if ((p_re < 0) & (p_im < 0)) {
        printf("(%.2f) + %.2fj, (%.2f) - %.2fj\n", p_re, -p_im, p_re, -p_im);
    }
}



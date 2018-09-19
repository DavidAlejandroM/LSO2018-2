//
//  c1_parte1.c
//  Lab2
//
//  Created by AlejandroMarin on 26/08/18.
//  Copyright © 2018 AlejandroMarin. All rights reserved.
//

//#include "c1_parte1.h"
#include <stdio.h>

#include <stdio.h>


/*********************************************************/
/*             Definiciones de las funciones             */
/*********************************************************/

/* Funciones del programa */

/**
 *   @brief  Determina si un caracter alfabetico
 *
 *   @param  ch es el caracter a verificar
 *   @return 1 si el caracter es una letra del alfabeto y 0 si es otro simbolo.x
 */
int esLetra(char ch) {
    // Coloque el codigo solucion a continuacion...
    if((ch > 64 && ch < 91) || (ch > 96 && ch < 123)){
        return 1;
    }
    return 0;
}

/**
 *   @brief  Convierte un caracter en mayuscula
 *
 *   @param  ch es el caracter ingresado
 */
void volverMayuscula(char *ch) {
    // Coloque el codigo solucion a continuacion...
    while (*ch != '\0') {
        if(*ch > 96 && *ch < 123){
            *ch = (*ch -  32);
        }
        ch++;
    }
    
}


/**
 *   @brief  Convierte en mayusculas la cadena de caracteres ingresada.
 *
 *   @param  s es una cadena de caracteres ingresada y la cual despues del proceso en la función tendra los caracteres en mayuscula.
 */

void stringToMayuscula(char s[]) {
    // Coloque el codigo solucion a continuacion...
    while (*s != '\0') {
        volverMayuscula(s);
        s++;
    }
}

/*********************************************************/
/*             Definiciones de las funciones             */
/*********************************************************/

/* Funciones de test */

/**
 *   @brief  Funcion para testear volverMayuscula
 *
 *   @param  void
 *   @return void
 */
void testVolverMayuscula(void) {
    char *p_char;
    char l1 = 'a', l2 = 'z';
    p_char = &l2;
    printf("Minusculas -> %c, %c\n", l1, l2);
    volverMayuscula(&l1);
    volverMayuscula(p_char);
    printf("Mayusculas -> %c, %c\n", l1, *p_char);
}

/**
 *   @brief  Funcion para testear esLetra
 *
 *   @param  void
 *   @return void
 */
void testEsLetra(void) {
    char c1 = '!', c2 = 's';
    printf("%c -> %d\n", c1, esLetra(c1));
    printf("%c -> %d\n", c2, esLetra(c2));
}

void testStringToMayuscula(void) {
    char s1[] = "hola que mas!!!\n";
    char s2[] = "1234 e_-+!!hay";
    printf("Cadenas en minuscula -> \n");
    printf("cadena 1: %s\n", s1);
    printf("cadena 2: %s\n", s2);
    stringToMayuscula(s1);
    stringToMayuscula(s2);
    printf("\nCadenas en mayuscula -> \n");
    printf("cadena 1: %s\n", s1);
    printf("cadena 2: %s\n", s2);
}

/* Funciones del programa */

/* Codigo ya implementado en la fase 1...*/

int main(){
    char str[1000];
    int ch;
    while((ch = getchar())!= EOF){
        str[0] = ch;
        stringToMayuscula(str);
        printf("%s",str);
    }
}

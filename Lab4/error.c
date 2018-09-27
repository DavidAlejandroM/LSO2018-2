#include "error.h"

/**
 * retorna 
 * -1: 	si ningun parametro es correcto
 * 0: 	si los parametros son correctos
 * 1: 	si tiene un solo parametro y es correcto
 */ 
int validate(char **pids, int length){
	if(length == 1){
		//no tiene parametros
		showHelp();
		return -1;
	}
	else if(length == 2){
		//solo tiene 2 parametros puede ser un un pid o una bandera
		char pid[100];
		strcpy(pid,pids[1]);
		if(strcmp(pid,"-r") == 0 || strcmp(pid,"-r") == 0){
			showHelp();
			return -1;
		}
		else if(isNumber(pid) == 0){
			return 1;
		}
		else{
			showHelp();
			return -1;
		}
	}
	else if(length > 2){
		char flag[100];
		strcpy(flag,pids[1]);
		if(strcmp(flag,"-r") == 0|| strcmp(flag,"-l") == 0){
			int control = 0;
			for(int i = 2; i < length; i++)
        	{
				if(isNumber(pids[i]) != 0){
					showHelp();
					return -1;
				}
				if(fountFileStatus(pids[i]) != 0){
					showHelp();
					return -1;
				}
			}
			return 0;
		}
		else{
			//si las banderas no son -r o -l
			showHelp();
			return -1;
		}
	}
	else{
		showHelp();
	}

}

void showHelp(){
	printf("-------------------------------------------------------------------------------------------\n");
	printf("-               USO: ./psinfo.out [opcion] [identificadores de procesos pid]              -\n");
	printf("-------------------------------------------------------------------------------------------\n");
	printf("-      [opcion]                                                                           -\n");
	printf("-         -l            lista la información del estado de los procesos  con el pid       -\n");
	printf("-                       especificados.                                                    -\n");
	printf("-         -r            genera un archivo \" psinfo-report-[pids].info \"la información     -\n");
	printf("-                       información del estado de los procesos con el pid especificados.  -\n");
	printf("-------------------------------------------------------------------------------------------\n");
	printf("-        [pid]                                                                            -\n");
	printf("-                       coincide   con  el identificador  de  procesos  del  sistema      -\n");
	printf("-                       se especifican de la siguente manera [7655 8769 9876 0987]        -\n");
	printf("-------------------------------------------------------------------------------------------\n");

}
/**
 * retorna -1 si no es un numero y 0 si lo es
 */
int isNumber(char *text){
	if(*(text + 0) != 0){
		int control = 0;
		int i = 0;
		do
		{
			if(*(text + i) < 48 && *(text + i) > 57){
				return -1;
			}
			i++;
		} while (*(text + i) != 0);
		return control;
	}
	else{
		return -1;
	}
}

/**
 * verifica si el archivo status en la carpeta existe sino imprime un error
 */
int fountFileStatus(char *pid){
	char path[100] = "/proc/";
	strcat(path,pid);
	strcat(path,"/status");
	if( access( path, F_OK ) != -1 ) {
    	return 0;
	} else {

		printf("-------------------------------------------------------------------------------------------\n");
		printf("El archivo status no se puede encontra en la ruta %s \nverifique que si sea un proceso activo del sistema\n", path);
		printf("-------------------------------------------------------------------------------------------\n");
		
		return -1;
	}
}
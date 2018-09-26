#include "psinfo.h"
#include "report.h"

int main(int argc, char *argv[]){
    // Comprobar que se haya ingresado el parámetro (PID)
    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }

    char flag[10];
    strncpy(flag, argv[1], strlen(argv[1]) + 1);

    if(strcmp(flag,"-l") == 0 || strcmp(flag,"-r") == 0){
        if(argc <= 2){
            printf("Debes ingresar PID...\n");
            return 1;
        }
        printf("-- Información recolectada!!!\n");
        InfoProccess *infoP;
        infoP = malloc(sizeof(InfoProccess));
        int type = 0;
        // validamos que bandera entró el usuario
        if(strcmp(flag,"-l") == 0){
            type = 1;
        }else if(strcmp(flag,"-r") == 0){
            type = 2;
        }

        char fileNameReport[100];
        getReportFileName(argv,argc,fileNameReport);
        
        for(int i = 2; i < argc; i++)
        {
            // Inicialización de variables
            char pid[10];
            strncpy(pid, argv[i], strlen(argv[i]) + 1);
            char ruta[80] = "/proc/";
            strcat(ruta,pid);
            strcat(ruta,"/status");
            FILE *inFile;
            inFile = fopen(ruta,"r");
            // Comprobar que el archivo se ha abierto
            if(inFile == NULL){
                printf("Error al abrir el archivo %s\n",ruta);
                return -1;
            }
            showInfoProccess(pid, inFile,type,fileNameReport); 
            fclose(inFile);          
        }        
    }
    else{
        //printf("NO es una lista");
        //showInfoProccess(flag);
    }
   
    return 0;
}
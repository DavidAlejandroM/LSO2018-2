#include "psinfo.h"
#include "report.h"
#include "error.h"

int main(int argc, char *argv[]){
    int valid = validate(argv,argc);
    printf("EL CODIGO DE VALIDACION ES: %d\n\n", valid);

    char flag[10];
    strncpy(flag, argv[1], strlen(argv[1]) + 1);

    if(valid ==0 || valid == 1){
        InfoProccess *infoP;
        infoP = malloc(sizeof(InfoProccess));
        int type = 0;
        int limInf = 2;
        // validamos que bandera entró el usuario
        if(strcmp(flag,"-l") == 0){
            type = 1;
        }else if(strcmp(flag,"-r") == 0){
            type = 2;
        }

        if( valid == 1){
            type = 1;
            limInf = 1;
        }

        char fileNameReport[100];
        getReportFileName(argv,argc,fileNameReport);
        
        for(int i = limInf; i < argc; i++)
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
   
   
    return 0;
}
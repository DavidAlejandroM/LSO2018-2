#include "psinfo.h"

int main(int argc, char *argv[]){
    // Comprobar que se haya ingresado el parámetro (PID)
    if (argc==1){
       printf("Debes ingresar mas parametros...\n");
       return 1;
    }

    char flag[10];
    strncpy(flag, argv[1], strlen(argv[1]) + 1);

    if(strcmp(flag,"-l") == 0){
        if(argc <= 2){
            printf("Debes ingresar PID...\n");
            return 1;
        }
        printf("-- Información recolectada!!!\n");
        InfoProccess *infoP = malloc(sizeof(InfoProccess));
        
        for(int i = 2; i < argc; i++)
        {
            char pid[10];
            strncpy(pid, argv[i], strlen(argv[i]) + 1);
            showInfoProccess(pid, infoP);
            printf("Pid: %s\nNombre de proceso: %s\nEstado: %s\nTamaño total de la imagen de memoria: %s\n
                \tTamaño de la memoria en la región TEXT: %s\n\tTamaño de la memoria en la región DATA: %s\n
                \tTamaño de la memoria en la región STACK: %s\n
                Número de cambios de contexto realizados (voluntarios - no voluntarios): %s - %s\n",
                pid,infoP->name,infoP->state,infoP->memTotal,infoP->memText,infoP->memData,
                infoP->memStack,infoP->voluntario,infoP->noVoluntario);
        }        
    }
    else{
        printf("NO es una lista");
        showInfoProccess(flag);
    }
   
    return 0;
}
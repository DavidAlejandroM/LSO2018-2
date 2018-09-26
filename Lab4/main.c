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
        
        for(int i = 2; i < argc; i++)
        {
            char pid[10];
            strncpy(pid, argv[i], strlen(argv[i]) + 1);
            printf("%s\n",pid);

            showInfoProccess(pid);
        }
        
    }
    else{
        printf("NO es una lista");
        showInfoProccess(flag);
    }


    
    return 0;
}

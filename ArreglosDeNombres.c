#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MostrarPersonas(char *V[], int cant);
int main(){
    int cant=5;
    char *V[cant];
    char buff[120];
    for (int i=0; i<cant; i++){
        printf("Ingrese su nombre: ");
        scanf(" %s", buff);
        int caracteres = strlen(buff);
        V[i]= (char *)malloc(sizeof(char) * caracteres);
        strcpy(V[i], buff);
    }
    
    MostrarPersonas(V, cant);

    for(int i=0; i<cant; i++){
        free(V[i]);
    }


    return 0;
}

void MostrarPersonas(char *V[], int cant){
    for (int i=0; i<cant;i++){
        printf(" %s \n", V[i]);

    }
}



#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MostrarPersonas(char *V[], int cant);
int BuscarNombre(char *V[], int cant, char nombre[]);

int main(){
    int cant=5;
    int indice;
    char nombre[120];

    char *V[cant];
    char buff[120];

    for (int i=0; i<cant; i++){
        printf("Ingrese su nombre: ");
        scanf(" %s", buff);
        int caracteres = strlen(buff);
        V[i]= (char *)malloc(sizeof(char) * caracteres + 1);
        strcpy(V[i], buff);
    }
    
    MostrarPersonas(V, cant);
    printf("Ingrese un nombre: ");
    scanf(" %s", nombre);
    indice = BuscarNombre(V, cant, nombre);
    if(indice != -1){
        printf("Coincidencia encontrada: %d) %s \n", indice, V[indice]);
    }else{
        printf("no se encontraron coincidencias\n");
    }

    for(int i=0; i<cant; i++){
        free(V[i]);
    }

    return 0;
}

void MostrarPersonas(char *V[], int cant){
    for (int i=0; i<cant;i++){
        printf("%d %s \n", i,  V[i]);

    }
}

int BuscarNombre(char *V[], int cant, char nombre[]){
    char *resultado;
    int indice;
    //la funcion busca el nombre en el arreglo
    for(int i=0; i<cant; i++){
        resultado=strstr(V[i], nombre);
        if(resultado){
            return i;
        }
    }
    return -1;
}

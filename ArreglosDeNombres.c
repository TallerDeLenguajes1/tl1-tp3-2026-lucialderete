#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void MostrarPersonas(char *V[], int cant);
void BuscarNombre(char *V[], int cant);

int main(){
    int cant=5;
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
    BuscarNombre(V, cant);

    for(int i=0; i<cant; i++){
        free(V[i]);
    }


    return 0;
}

void MostrarPersonas(char *V[], int cant){
    for (int i=0; i<cant;i++){
        printf("%d) %s \n", i, V[i]);

    }
}

void BuscarNombre(char *V[], int cant){
    int num;
    printf("---Busca nombre por ID---");
    printf("Ingrese un numero: ");
    scanf("%d", &num);

    if (num >= 0 && num < cant){
        printf("El nombre ubicado en la posicion %d es %s:\n ", num, V[num]);
    }else{
        printf("no se encontró el valor buscado");
    }
}

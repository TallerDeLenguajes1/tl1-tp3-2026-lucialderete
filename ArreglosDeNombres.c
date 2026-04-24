#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//modulos
void MostrarPersonas(char *V[], int cant);
void BuscarNombrePorId(char *V[], int cant);
int BuscarNombrePorPalabra(char *V[], int cant, char nombre[]);

//funcion principal
int main()
{
    int cant = 5;
    int indice, opcion=0;
    char nombre[120];
    char *V[cant];
    char buff[120];

    printf("--bienvenido xd --\n");

    for (int i = 0; i < cant; i++){
        printf("Ingrese un nombre:");
        scanf(" %s", buff);
        int caracteres = strlen(buff);
        V[i] = (char *)malloc(sizeof(char) * caracteres + 1);
        strcpy(V[i], buff);
    }

    MostrarPersonas(V, cant);

    printf("Buscar por ID (1)\nBuscar por Palabra Clave (2)\n");
    printf("Seleccione una opcion\n");
    scanf(" %d", &opcion);

    if (opcion == 1){
        BuscarNombrePorId(V, cant);
    }
    else if (opcion == 2)
    {
        printf("Ingrese un nombre: ");
        scanf(" %s", nombre);
        indice = BuscarNombrePorPalabra(V, cant, nombre);
        if (indice != -1){
            printf("Coincidencia encontrada: %d) %s \n", indice, V[indice]);
        }else{
            printf("no se encontraron coincidencias\n");
        }
    }else{
        printf("ingrese una opcion valida");
    }

    for (int i = 0; i < cant; i++){
        free(V[i]);
    }

    return 0;
}


//desarrollo de los modulos
void MostrarPersonas(char *V[], int cant)
{
    for (int i = 0; i < cant; i++)
    {
        printf("%d) %s \n", i, V[i]);
    }
}

void BuscarNombrePorId(char *V[], int cant)
{
    int num;
    printf("---Busca nombre por ID---\n");
    printf("Ingrese un numero: ");
    scanf("%d", &num);
    if (num >= 0 && num < cant)
    {
        printf("El nombre ubicado en la posicion %d es %s\n ", num, V[num]);
    }
    else
    {
        printf("no se encontró el valor buscado\n");
    }
}

int BuscarNombrePorPalabra(char *V[], int cant, char nombre[])
{
    char *resultado;
    int indice;
    // la funcion busca el nombre en el arreglo
    for (int i = 0; i < cant; i++)
    {
        resultado = strstr(V[i], nombre);
        if (resultado)
        {
            return i;
        }
    }
    return -1;
}

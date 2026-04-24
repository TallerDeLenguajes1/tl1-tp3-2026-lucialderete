#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//estructuras
char *TiposProductos[]={
    "Galletas", "Snack", "Cigarrillos", "Caramelos", "Bebidas"
};

typedef struct {
    int ProductoID;
    int Cantidad;
    char *TiposProducto;
    float PrecioUnitario;
}Producto;

typedef struct{
    int ClienteID;
    char *NombreCliente;
    int CantidadProductos;
    Producto *Productos;
}Cliente;

//modulos
void cargarClientes(Cliente *Clientes, int cantClientes, char buff[]);
void cargarProductos(Cliente *Clientes, int cantClientes);

//funcion principal
int main(){
    int cantClientes;
    int cantProd = 10;
    char buff[120];
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes (maximo 5): ");
    scanf("%d", &cantClientes);
    Cliente *Clientes = (Cliente *)malloc(cantClientes *sizeof(Cliente));

    cargarClientes(Clientes, cantClientes, buff);
    cargarProductos(Clientes, cantClientes);

    return 0;
}

//desarrollo de los modulos
void cargarClientes(Cliente *Clientes, int cantCliente, char buff[]){
    printf("--CARGAR CLIENTES--\n");
    for(int i=0; i<cantCliente; i++){
        printf("CLIENTE %d\n", i+1);
        Clientes[i].ClienteID = i+1;
        printf("ID: %d\n", Clientes[i].ClienteID);
        printf("Nombre del cliente: ");
        scanf(" %s", buff);
        int totalcaracteres = strlen(buff);
        Clientes[i].NombreCliente = (char *)malloc(sizeof(char)* totalcaracteres + 1);
        strcpy(Clientes[i].NombreCliente, buff);
        Clientes[i].CantidadProductos= (rand() % 5)+1;
        printf("Cantidad de productos: %d\n", Clientes[i].CantidadProductos);
        Clientes[i].Productos = (Producto *)malloc(Clientes[i].CantidadProductos * sizeof(Producto));
        printf("----------------------\n");
    }
}

void cargarProductos(Cliente *Clientes, int cantClientes){
    for(int i=0; i<cantClientes; i++){
        printf("---------------------------------------\n");
        printf("--CARGAR PRODUCTOS CLIENTE %d\n", i+1);
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            printf("--PRODUCTO %d--\n", j+1);
            Clientes[i].Productos[j].ProductoID = j+1;
            printf("ID producto: %d\n", Clientes[i].Productos[j].ProductoID);

            Clientes[i].Productos[j].Cantidad = (rand() % 10)+1;
            printf("Cantiadad: %d\n", Clientes[i].Productos[j].Cantidad);

            int indice = rand() % 4;
            Clientes[i].Productos[j].TiposProducto = TiposProductos[indice];
            printf("Tipo producto: %s\n", Clientes[i].Productos[j].TiposProducto);

            Clientes[i].Productos[j].PrecioUnitario = (rand()%91) + 10;
            printf("Precio Unitario:$%.2f\n", Clientes[i].Productos[j].PrecioUnitario);
        }
    }
    
}
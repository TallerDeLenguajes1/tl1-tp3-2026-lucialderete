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
float costoTotalProducto(Producto p);
void mostrarProductos(Cliente *Clientes, int cantClientes);
void librerarMemoria(Cliente *Clientes, int cantClientes);

//funcion principal
int main(){
    int cantClientes;
    char buff[120];
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes (maximo 5): ");
    scanf("%d", &cantClientes);
    if(cantClientes > 5){
        printf("Ingrese menos cantidad de clientes xd\n");
    }else{
        Cliente *Clientes = (Cliente *)malloc(cantClientes * sizeof(Cliente));

        cargarClientes(Clientes, cantClientes, buff);
        cargarProductos(Clientes, cantClientes);

        mostrarProductos(Clientes, cantClientes);

        librerarMemoria(Clientes, cantClientes);
    }
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
        scanf("%s", buff);

        Clientes[i].NombreCliente = (char *)malloc(strlen(buff) + 1);
        strcpy(Clientes[i].NombreCliente, buff);


        Clientes[i].CantidadProductos= (rand() % 5)+1;
        printf("Cantidad de productos: %d\n", Clientes[i].CantidadProductos);
        Clientes[i].Productos = (Producto *)malloc(Clientes[i].CantidadProductos * sizeof(Producto));
        printf("----------------------\n");
    }
}

void cargarProductos(Cliente *Clientes, int cantClientes){
    for(int i=0; i<cantClientes; i++){
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            Clientes[i].Productos[j].ProductoID = j+1; //id
            Clientes[i].Productos[j].Cantidad = (rand() % 10)+1;//cantidad
            int indice = rand() % 5;
            Clientes[i].Productos[j].TiposProducto = TiposProductos[indice]; //tipoproducto
            Clientes[i].Productos[j].PrecioUnitario = (rand()%91) + 10; //precio
        }
    }
    
}

float costoTotalProducto(Producto prod){
    float costoProducto = prod.Cantidad * prod.PrecioUnitario;

    return costoProducto;
}

void mostrarProductos(Cliente *Clientes, int cantClientes){
    
    for(int i=0; i<cantClientes; i++){
        printf("---PRODUCTOS CLIENTE %d---\n", i+1);
        float precioFinal=0, precioProducto=0;
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            printf("--PRODUCTO %d ---\n", j+1);
            printf("ID producto: %d\n", Clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("Tipo Producto: %s\n", Clientes[i].Productos[j].TiposProducto);
            printf("Precio Unitario: %.2f\n", Clientes[i].Productos[j].PrecioUnitario);
            precioProducto = costoTotalProducto(Clientes[i].Productos[j]);
            printf("Precio total del producto: $%.2f\n", precioProducto);
            precioFinal += precioProducto;
            
        }
        printf("Precio total a pagar: $%.2f\n", precioFinal);

    }
}

void librerarMemoria(Cliente *Clientes, int cantClientes){
    for(int i=0; i<cantClientes; i++){
        free(Clientes[i].NombreCliente);
        free(Clientes[i].Productos);
    }
    free(Clientes);
}


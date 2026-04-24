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
float costoTotalProducto(char productoIngresado[], Cliente *Clientes, int cantClientes);
void mostrarProductos(Cliente *Clientes, int cantClientes);
void librerarMemoria(Cliente *Clientes, int cantClientes);

//funcion principal
int main(){
    int cantClientes;
    int cantProd = 10;
    char productoIngresado[50];
    float precioFinal;
    char buff[120];
    srand(time(NULL));

    printf("Ingrese la cantidad de clientes (maximo 5): ");
    scanf("%d", &cantClientes);
    if(cantClientes > 5){
        printf("Ingrese menos cantidad de clientes xd\n");
    }else{
        Cliente *Clientes = (Cliente *)malloc(cantClientes *sizeof(Cliente));

        cargarClientes(Clientes, cantClientes, buff);
        cargarProductos(Clientes, cantClientes);

        printf("Ingrese el producto que desea calcular el precio total: \n");
        for (int i=0; i<5; i++){
            printf("%d) %s\n", i+1, TiposProductos[i]);
        }
        scanf(" %s", productoIngresado);
        precioFinal = costoTotalProducto(productoIngresado, Clientes, cantClientes);
        printf("El costo total del producto ingresado es: %.2f\n", precioFinal);

        mostrarProductos(Clientes, cantProd);
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
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            Clientes[i].Productos[j].ProductoID = j+1; //id
            Clientes[i].Productos[j].Cantidad = (rand() % 10)+1;//cantidad
            int indice = rand() % 4;
            Clientes[i].Productos[j].TiposProducto = TiposProductos[indice]; //tipoproducto
            Clientes[i].Productos[j].PrecioUnitario = (rand()%91) + 10; //precio
        }
    }
    
}

float costoTotalProducto(char productoIngresado[], Cliente *Clientes, int cantClientes){
    float total=0;
    for(int i=0; i<cantClientes; i++){
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            if(strcmp(productoIngresado, Clientes[i].Productos[j].TiposProducto)==0){
                total += (Clientes[i].Productos[j].Cantidad) * (Clientes[i].Productos[j].PrecioUnitario);
            }
        }
    }
    return total;
}

void mostrarProductos(Cliente *Clientes, int cantClientes){
    float precioFinal=0;
    for(int i=0; i<cantClientes; i++){
        printf("---PRODUCTOS CLIENTE %d---\n", i+1);
        for(int j=0; j<Clientes[i].CantidadProductos; j++){
            printf("--PRODUCTO %d ---", j+1);
            printf("ID producto: %d\n", Clientes[i].Productos[j].ProductoID);
            printf("Cantidad: %d\n", Clientes[i].Productos[j].Cantidad);
            printf("Tipo Producto: %s\n", Clientes[i].Productos[j].TiposProducto);
            printf("Precio Unitario: %.2f\n", Clientes[i].Productos[j].PrecioUnitario);
            precioFinal += ((Clientes[i].Productos[j].PrecioUnitario) * (Clientes[i].Productos[j].Cantidad));
            printf("Precio total: $%.2f\n", precioFinal);
        }   

    }
}

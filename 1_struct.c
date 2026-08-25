#include <stdio.h>
typedef struct //Otra forma de definir una estructura
{
    char descripcion[21];
    int codigo;
    float precio;
}Producto;

Producto CargarProducto(); //Funcion que devuelve un producto. No se escribe "struct Producto CargarProducto();" porque la forma en que definimos la estructura permite no escribirlo
int main()
{
    Producto prod1,prod2;
    prod1 = CargarProducto();
    prod2 = prod1;

    printf("Datos del producto:");
    printf("\nCodigo: %d Descripcion: %s Precio: %.2f",prod1.codigo,prod1.descripcion, prod1.precio);

    printf("\n\nDatos del producto 2:");
    printf("\nCodigo: %d Descripcion: %s Precio: %.2f",prod2.codigo,prod2.descripcion, prod2.precio);

    return 0;
}

Producto CargarProducto()
{
    Producto prod;

    printf ("Ingrese el codigo del producto:");
    scanf("%d",&prod.codigo);

    printf("Ingrese la descripcion del producto:");
    getchar();
    gets(prod.descripcion);

    printf("Ingrese el precio del producto:");
    scanf("%f",&prod.precio);

    return prod;
};

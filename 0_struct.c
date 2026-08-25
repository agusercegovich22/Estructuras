/*La estructura es un tipo de dato definido por el usuario
Tipo de dato compuesto por varios tipos de datos simples(campos, son las partes de la estructura)
*/

#include <stdio.h>

//Definición del tipo de dato en el area global, como mínimo debe de tener dos datos
struct Producto
{
    char descripcion[21]; //Campo
    int codigo; //Campo
    float precio; //Campo
};
int main()
{
    struct Producto prod; //Estoy creando una variable de memoria del tipo: struct Producto
    //Crea en la memoria un espacio llamado prod donde voy a tener: descripcion, codigo y precio
    printf ("Ingrese el codigo del producto:");
    scanf("%d",&prod.codigo); //Instrucción para acceder al campo de la variable(utilizo el operador ".")

    printf("Ingrese la descripcion del producto:");
    getchar(); //Para limpiar el buffer
    gets(prod.descripcion); //Utilizariamos la función leer texto

    printf("Ingrese el precio del producto:");
    scanf("%f",&prod.precio);


    printf("\nCodigo: %d Descripcion: %s Precio: %.2f",prod.codigo,prod.descripcion, prod.precio);

    return 0;
}

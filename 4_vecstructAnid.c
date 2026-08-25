#include <stdio.h>
#define TAM 3
//Cuando hay estrucuras anidadas se define arriba la más interna
typedef struct
{
    int dia;
    int mes;
    int anio;
}fecha;

typedef struct
{
    char descripcion[21];
    int codigo;
    float precio;
    fecha fechaVencimiento;
}Producto;

void CargarProductos(Producto[], int);
void MostrarProductos(Producto[], int);
void Ordenar(Producto[], int);

int main()
{
    Producto vecProductos[TAM];
    CargarProductos(vecProductos, TAM);
    MostrarProductos(vecProductos, TAM);

    printf("\n\nProductos Ordenados\n");
    Ordenar(vecProductos,TAM);
    MostrarProductos(vecProductos, TAM);

    return 0;
}

void CargarProductos(Producto vp[], int ce)
{
    int i;
    for (i=0;i<ce;i++)
    {
        printf ("Ingrese el codigo del producto:");
        scanf("%d",&vp[i].codigo);

        printf("Ingrese la descripcion del producto:");
        fflush(stdin);
        gets(vp[i].descripcion);

        printf("Ingrese el precio del producto:");
        scanf("%f",&vp[i].precio);

        printf("Fecha de vencimiento del producto");
        printf("\nIngrese el dia:");
        scanf("%d",&vp[i].fechaVencimiento.dia);

        printf("Ingrese el mes:");
        scanf("%d",&vp[i].fechaVencimiento.mes);

        printf("Ingrese el anio:");
        scanf("%d",&vp[i].fechaVencimiento.anio);

        printf("\n");
    }

}

void MostrarProductos(Producto vp[], int ce)
{
    int i;
    printf("\n%6s  %-21s%8s %12s","Codigo",   "Descripcion"   ,"Precio", "Vencimiento");
    for (i=0;i<ce;i++)
        printf("\n%6d  %-21s%8.2f %02d/%02d/%02d",vp[i].codigo, vp[i].descripcion,vp[i].precio,vp[i].fechaVencimiento.dia,vp[i].fechaVencimiento.mes,vp[i].fechaVencimiento.anio);

}

void Ordenar(Producto vp[], int ce)
{
    int i,j;
    Producto aux;
    for (i=0;i<ce-1;i++)
        for(j=0;j<ce-1-i;j++)
            if (vp[j].precio < vp[j+1].precio)
            {
                aux = vp[j];
                vp[j]=vp[j+1];
                vp[j+1]=aux;
            }
}

#include <stdio.h>
#include <string.h>
#define TAM 3
typedef struct
{
    char descripcion[21];
    int codigo;
    float precio;
}Producto;

void CargarProductos(Producto[], int);
void MostrarProductos(Producto[], int);
void Ordenar(Producto[], int);
void OrdenarPorDescp(Producto[], int);

int main()
{
    Producto vecProductos[TAM];
    CargarProductos(vecProductos, TAM);
    MostrarProductos(vecProductos, TAM);

    printf("\n\nProductos Ordenados\n");
    //Ordenar(vecProductos,TAM);
    OrdenarPorDescp(vecProductos, TAM);
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

        printf("\n");
    }
}

void MostrarProductos(Producto vp[], int ce)
{
    int i;
    printf("\n%6s  %-21s%8s","Codigo",   "Descripcion"   ,"Precio");
    for (i=0;i<ce;i++)
        printf("\n%6d  %-21s%8.2f",vp[i].codigo, vp[i].descripcion,vp[i].precio);

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

void OrdenarPorDescp(Producto vp[], int ce){
    int i,j;
    Producto aux;
    for (i=0;i<ce-1;i++)
        for(j=0;j<ce-1-i;j++)
            if (strcmpi(vp[j].descripcion, vp[j+1].descripcion)>0)
            {
                aux = vp[j];
                vp[j]=vp[j+1];
                vp[j+1]=aux;
            }
}

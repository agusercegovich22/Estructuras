#include <stdio.h>

typedef struct
{
    int codProd;
    int totalVentas;
    char nombre[50];
}ventas;

int main()
{
    int i;
    ventas vecVentas[5];

    for (i=0;i<5;i++)
       vecVentas[i].totalVentas=0;


    return 0;
}

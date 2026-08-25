#include <stdio.h>
#define TAM 2

typedef struct
{
    char nombre[21];
    int dni;
    int notas[4];
}Alumnos;


void CargarAlumnos(Alumnos[], int);
void MostrarAlumnos(Alumnos[], int);

int main()
{
    Alumnos vecAlumnos[TAM];
    CargarAlumnos(vecAlumnos, TAM);
    MostrarAlumnos(vecAlumnos, TAM);

    return 0;
}

void CargarAlumnos(Alumnos vec[], int ce)
{
    int i,j;
    for (i=0;i<ce;i++)
    {
        printf ("Ingrese el dni:");
        scanf("%d", &vec[i].dni);

        printf ("Ingrese el nombre:");
        getchar();
        gets(vec[i].nombre);

        printf("Notas del alumno\n");
        for(j=0;j<4;j++)
        {
            printf("Ingrese la nota %d:", j+1);
            scanf("%d",&vec[i].notas[j]);
        }

        printf("\n");
    }
}

void MostrarAlumnos(Alumnos vec[], int ce)
{
    int i, j;
    float promedio;
    printf("\n%-8s %-21s%8s","DNI",   "Nombre"   ,"Promedio");
    for (i=0;i<ce;i++)
    {
        promedio=0;
        for (j=0;j<4;j++)
            promedio+=vec[i].notas[j];
        promedio/=4;
        printf("\n%-8d %-21s%8.2f",vec[i].dni, vec[i].nombre, promedio);
    }


}

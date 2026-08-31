/*
1. Gestión de Sensores de Temperatura
Definir una estructura llamada Sensor que contenga:
• un identificador (entero),
• la ubicación del sensor (texto de 30 caracteres máximo)
• y la última lectura de temperatura (float).
Ingresar por teclado los datos de 5 sensores y al finalizar la carga mostrar:
a) el /los sensores con la mayor temperatura registrada mostrando todos sus datos
b) el promedio de las temperaturas de todos los sensores

1
cocina
20
2
living
27.2
3
heladera
3
4
techo
40.5
5
garage
38
6
dormitorio
30.8
*/

#include <stdio.h>
#include <stdlib.h>

#define TAM 5

typedef struct
{
    int s;
    char ubi[31];
    float temp;
}Sensor;

void LeerTexto(char[], int);
Sensor CargaSensor(Sensor[], int);
void MayorTemp(Sensor[], int);
void PromTemps(Sensor[], int);

int main(){
    Sensor sensor[5], sensor1[5];
    sensor1[5] = CargaSensor(sensor, TAM);
    MayorTemp(sensor1, TAM);
    PromTemps(sensor1, TAM);
    printf("\n");
    system("pause");
    return 0;
}

void LeerTexto(char s[], int cant){
    int i=0;
    fgets(s, cant, stdin);
    while(s[i]!='\0') //Recorrer hasta el final del texto
        i++;
    if(i!=0 && s[i-1]=='\n') //i!=0 Previene la sobreescritura de la memoria que precede al vector en caso de que se ingrese directamente un enter(\n)
        s[i-1]='\0';
}

Sensor CargaSensor(Sensor sen[], int ce){
    int i;
    for(i=0; i<ce; i++){
        if(i>0)
            printf("\n");
        printf("Ingresar numero de sensor: ");
        scanf("%d", &sen[i].s);
        printf("Ingresar la ubicacion del sensor: ");
        getchar();
        LeerTexto(sen[i].ubi, 31);
        printf("Ingresar la temperatura: ");
        scanf("%d", &sen[i].temp);
    }
    return sen;
}

void MayorTemp(Sensor sen[], int ce){
    int i;
    float mayor = sen[0].temp;
    for(i=0;i<ce;i++)
        if(sen[i].temp > mayor)
           mayor = sen[i].temp;
    printf("El o los sensores con la mayor temperatura registrada son:\n");
    printf("%-6s %-31s %-15s","Sensor",   "Ubicacion"   ,"Temeperatura(C)\n");
    for(i=0;i<ce;i++)
        if(sen[i].temp == mayor)
            printf("%6d %-31s %-15f\n", sen[i].s, sen[i].ubi, sen[i].temp);
}

void PromTemps(Sensor sen[], int ce){
    int i;
    float suma;

    for(i=0;i<ce;i++)
        suma += sen[i].temp;
    printf("\nSUMA: %f\n", suma);
    printf("El promedio de las temperaturas es: %f", suma/ce);
}
/*
1
cocina
20
2
living
27.2
3
heladera
3
4
techo
40.5
5
garage
38
6
dormitorio
30.8
*/

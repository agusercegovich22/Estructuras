/*2. Medición de Corrientes en Distintos Días
Cree una estructura Corriente con:
• nombre del circuito (texto de 20 caracteres máximo),
• un vector de 7 valores float que representen la corriente medida en ese circuito
durante una semana (un valor por día).
Ingrese los datos de 3 circuitos. Luego:
1. Muestre el promedio semanal de corriente de cada circuito.
2. Indique el día en que se registró la mayor corriente para cada uno.
3. Mostrar el circuito con mayor promedio semanal (considerar único)*/


#include <stdio.h>
#include <stdlib.h>

#define CANT_CIRCUITOS 3
#define CANT_DIAS 7

typedef struct{
    char nombre[21];
    float dia[7];
}Corriente;

void LeerTexto(char[], int);
void CargaDatos(Corriente[], int, int);
int MostrarProms(Corriente[], int, int, int[]);
void CMaxXCircuito(int[], int);

int main(){
    Corriente circuito[3];
    int mayorC[3]={0}, cPromMax;
    CargaDatos(circuito, CANT_CIRCUITOS, CANT_DIAS);
    cPromMax = MostrarProms(circuito, CANT_CIRCUITOS, CANT_DIAS, mayorC);
    CMaxXCircuito(mayorC, CANT_CIRCUITOS);
    printf("El cicuito con mayor promedio semanal es el circuito %d", cPromMax);
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

void CargaDatos(Corriente datos[], int ce, int dias){
    int i, j;
    for(i=0; i<ce; i++){
        printf("Ingresar nombre del circuito: ");
        getchar();
        LeerTexto(datos[i].nombre, 21);
        printf("Ingresar las corrientes medidas en la semana: ");
        for(j=0;j<7;j++){
            printf("Corriente dia %d: ", j+1);
            scanf("%f", &datos[i].dia[j]);
        }
    }
}

int MostrarProms(Corriente datos[], int ce, int dias, int cMax[]){
    int i, j, cPromMax;
    float suma=0, cM, promMax;
    for(i=0;i<ce;i++){
        cM=datos[i].dia[0];
        for(j=0;j<dias;j++){
            suma += datos[i].dia[j];
            if(datos[i].dia[j] > cM)
                cM = datos[i].dia[j];
                cMax[i]=j+1;
        }

        if(i==0)
            promMax=suma/dias;
        else if(suma/dias > promMax){
            promMax = suma/dias;
            cPromMax = i+1;
        }
        printf("El promedio de corriente del circuito %d es: %f", i+1, suma/dias);
        suma=0;
    }
    return cPromMax;
}

void CMaxXCircuito(int mayorC[], int ce){
    int i;
    for(i=0;i<ce;i++){
        printf("El dia %d se registro la mayor corriente para el circuito %d", mayorC[i], i+1);
    }
}

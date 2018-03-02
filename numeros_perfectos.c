#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


bool es_numero_perfecto(int);

int main(){
    int cantidad_evaluaciones;
    scanf("%d", &cantidad_evaluaciones);

    int inicio[cantidad_evaluaciones], evaluaciones[cantidad_evaluaciones];

    for(int i = 0; i < cantidad_evaluaciones; i++)
        scanf("%d%*c%d", &inicio[i], &evaluaciones[i]);
    

    puts("");

    for(int i= 0; i < cantidad_evaluaciones; i++){
        for(int j = 0; j < evaluaciones[i] + 1; j++){
            if(es_numero_perfecto(inicio[i] + j))
                printf("%d es perfecto\n", inicio[i]+j);
            else
                printf("%d no es perfecto\n", inicio[i]+j);
        }
    }
    return EXIT_SUCCESS;
}

bool es_numero_perfecto(int numero){
    int suma = 0;
    for(int i=1; i < numero; i++){
        if(numero % i == 0)
            suma += i;
    }
    if(suma == numero)
        return true;
    else
        return false;  

}
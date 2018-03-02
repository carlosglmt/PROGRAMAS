#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int registros, diferencia_horas, diferencia_minutos, total_minutos = 0, promedio;

int main(){
  
    scanf("%d", &registros);

    int oHora[registros], oMinuto[registros], aHora[registros], aMinuto[registros];


    for(int i=0; i<registros; i++)
        scanf("%d%d%d%d", &oHora[i], &oMinuto[i], &aHora[i], &aMinuto[i]);
    
    for(int i=0; i<registros; i++){
        diferencia_horas = aHora[i] - oHora[i];
        diferencia_minutos = aMinuto[i] - oMinuto[i];
        total_minutos += diferencia_minutos + diferencia_horas*60;
    }

    puts("");

    promedio = total_minutos/registros;
    printf("%d\n", promedio);

    return EXIT_SUCCESS;
}
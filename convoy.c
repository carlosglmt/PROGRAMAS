#include <stdio.h>

int tiempo(int,int);

int main(){

	int peso_maximo,distancia,numero_vehiculos;
	float t = 0;

	scanf("%d%d%d",&peso_maximo,&distancia,&numero_vehiculos);

	int peso_vehiculos[numero_vehiculos];
	int velocidad[numero_vehiculos];

	for (int i = 0; i < numero_vehiculos; ++i){
		scanf("%d%d",&peso_vehiculos[i],&velocidad[i]);
	}

	int contador = 0, suma = 0, i = 0, j = 0, menor;
	while(i < numero_vehiculos){
		suma += peso_vehiculos[i];
		if (suma + peso_vehiculos[i+1] > peso_maximo)
		{
			menor = velocidad[i];
			while(j <= i){

				if (velocidad[j] < menor){
					menor = velocidad[j];
				}
				j++;			

			}
			t =+ t + tiempo(distancia,menor);	
			suma = 0;
		}
		i++;
	}
	printf("%.1f\n",t);
	return 0;
}

int tiempo(int distancia,int s){
	float segundos;
	segundos=((float)distancia/(float)s)*60;
	return segundos;


}

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int n_veces; 

	scanf("%d", &n_veces);

	int contador = 0; 

	while(contador < n_veces){

		int renglones, columnas;
		scanf("%d%d", &renglones,&columnas);

		int matriz_patron[renglones][columnas];

		for(int i = 0; i < renglones; i++)
			for(int j = 0; j < columnas; j++){
				scanf("%d",&matriz_patron[i][j]);
			}

		int renglones_gmat, columnas_gmat;
		scanf("%d%d",&renglones_gmat, &columnas_gmat);

		int matriz_gmat[renglones_gmat][columnas_gmat];

		for(int i = 0; i < renglones_gmat; i++)
			for(int j = 0; j < columnas_gmat; j++){
				scanf("%d",&matriz_gmat[i][j]);
			}


		for(int i = 0; i < renglones_gmat; i++)
			for(int j = 0; j < columnas_gmat; j++){
				int bandera = 1;
				for(int x = 0; x < renglones; x++){
					for(int y = 0; y < columnas; y++){
						if(matriz_patron[x][y] != matriz_gmat[i + x - 1][j + y - 1]){
							bandera = 0;		
						}
					}
				}

				if (bandera == 1){
					for(int w = renglones; w > 0; w--)
						for(int z = columnas; z > 0; z--)
							if(matriz_gmat[i - w + 1][j - z + 1] == 1){
								matriz_gmat[i - w + 1][j - z + 1] = 2;
							}else if(matriz_gmat[i - w + 1][j - z + 1] == 0){
								matriz_gmat[i - w + 1][j - z + 1] = 9;
							}
				}

			}


		puts("");

		for(int i = 0; i < renglones_gmat; i++){
			for(int j = 0; j < columnas_gmat; j++){
				if(matriz_gmat[i][j] == 9)
					printf("* ");
				else
					printf("%d ",matriz_gmat[i][j]);
			}
			puts("");
		}

		puts("");



		contador++;
	}

	return EXIT_SUCCESS;
}
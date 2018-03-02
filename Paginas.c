#include <stdio.h>
#include <stdlib.h>

int main(){
	int digitos, paginas=0;


	printf("Ingresa los digitos del libro:\n");	
	while(scanf("%d", &digitos)){



	while(digitos > 0){
		if(paginas < 9){
			paginas ++;
			digitos --;
		}else if(paginas < 99){
			paginas ++;
			digitos -= 2;
		}else if(paginas < 999){
			paginas ++;
			digitos -= 3;
		}else if(paginas < 9999){
			paginas ++;
			digitos -= 4;
		}else if(paginas < 99999){
			paginas ++;
			digitos -= 5;
		}else if(paginas < 999999){
			paginas ++;
			digitos -= 6;
		}else if(paginas < 9999999){
			paginas ++;
			digitos -= 7;
		}else if(paginas < 99999999){
			paginas ++;
			digitos -= 8;
		}else if(paginas < 999999999){
			paginas ++;
			digitos -= 9;
		}
	}
	if(digitos == 0){
		puts("");
		printf("%d\n", paginas);
		puts("");
		puts("");
	}else{
		puts("");
		printf("Imposible\n");
		puts("");
		puts("");
	}	

	paginas = 0; 
}
	return EXIT_SUCCESS;
}
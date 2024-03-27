#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc,char** argv)
{

int manu_in=0;
	

	meni:printf(" 1. Unos kombinacija\n 2. Prikaz kombinacije \n 3. Brisanje kombinacija \n 4. Izlaz  \n");
	scanf("%d", &manu_in);



while(1){

	switch (manu_in){
		case 1:
			unos_komb();
			manu_in=0;
			goto meni;
			break;
		case 2:
			read_comb();
			manu_in=0;
			goto meni;
			break;
		case 3:
			
			clean_file();
			manu_in=0;
			goto meni;
			break;
		case 4:
			exit(0);
			break;
		default:
			goto meni;
						
	}




}
}
#include "input.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


FILE* fp1;
FILE* intext;
FILE* fp_s;
FILE* fp_d;

void blink_led(){
	FILE* fp_d;

	long int period = 200000L;
	
		for(int i=0;i<6;i++){
		fp_d=fopen("/dev/led","w");
		
		fputs("0x0F\n",fp_d);
		fclose(fp_d);
		usleep(period);
		fp_d=fopen("/dev/led","w");
		
		fputs("0x00\n",fp_d);
		fclose(fp_d);
		return;
	}
}

//unos_komb ->unosimo kombinacije u txt file,max broj kombinacija je 15
//neophodno ubaciti taster
void unos_komb()
{
	
	char sval1 = 0,sval2,sval3,sval4, cond = 0;
	size_t num_of_bytes = 6;
	char *str;
	int button_new = 0, button_old = 0;
	int switch_state = 0;

	
	while(1)
	{
		fp1 = fopen ("/dev/button", "r");
		if(fp1==NULL)
		{
			puts("Problem pri otvaranju /dev/button");
			exit(0);
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp1); 

		if(fclose(fp1))
		{
			puts("Problem pri zatvaranju /dev/button");
			exit(0);
		}

		if (str[5] - 48 == 1)
			cond = 1;
		else if (str[4] - 48 == 1)
			cond = 2;
		else if (str[3] - 48 == 1)
			cond = 3;
		else if (str[2] - 48 == 1)
			cond = 4;
		else
			cond = 0;
		free(str);
		
		button_new = cond;
		
		if (button_new != button_old)
		{
			if (button_new == 1)
			{
				printf("Unos sacuvan");
				return;	
				}
			
	
			button_old = button_new;
		}
		usleep(1);
		
		intext=fopen("comb_in.txt","w");
			
			
			for(int flag1=0;flag1<3;flag1++)
				{
				char temp_comb;
				printf("Unesite zelejnu kombinaciju 0x");
				scanf(" %c", &temp_comb);
				fprintf(intext," 0x%c \n",temp_comb);
				}
						
					
				printf("DOSTIGUNT MAX UNOS \n");
				blink_led();
				fclose(intext);
				return;	




	}


}



//read_comb za citanje kombinacija
void read_comb()
{	
	char *line = NULL;
    size_t len = 0;
    ssize_t read;
	int line_number=0;
	char *str;
	char sval1 = 0,sval2,sval3,sval4, cond = 0;
	size_t num_of_bytes = 6;
	int switch_state = 0;
	int button_new = 0, button_old = 0;
	long int period = 2000000L;
	


	while (1)
	{
	fp_s = fopen ("/dev/switch", "r");
		if(fp_s==NULL)
		{
			puts("Problem pri otvaranju /dev/switch");
			exit(0);
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp_s); 

		if(fclose(fp_s))
		{
			puts("Problem pri zatvaranju /dev/switch");
			exit(0);
		}


		sval1 = str[2] - 48;
		sval2 = str[3] - 48;
		sval3 = str[4] - 48;
		sval4 = str[5] - 48;
		free(str);

		switch_state = 0;
		if (sval4 == 1)
			switch_state += 1;
		if (sval3 == 1)
			switch_state += 2;
		if (sval2 == 1)
			switch_state += 4;
		
		

		//pritisnuto dugme za uzimanje kombinacije
		fp1 = fopen ("/dev/button", "r");
		if(fp1==NULL)
		{
			puts("Problem pri otvaranju /dev/button");
			exit(0);
		}


		str = (char *)malloc(num_of_bytes+1); 
		getline(&str, &num_of_bytes, fp1); 

		if(fclose(fp1))
		{
			puts("Problem pri zatvaranju /dev/button");
			exit(0);
		}

		if (str[5] - 48 == 1)
			cond = 1;
		else if (str[4] - 48 == 1)
			cond = 2;
		else if (str[3] - 48 == 1)
			cond = 3;
		else if (str[2] - 48 == 1)
			cond = 4;
		else
			cond = 0;
		free(str);
		
		button_new = cond;
		
		if (button_new != button_old)
		{
			if (button_new == 2)
			{
				
				line_number=switch_state;

				intext = fopen("comb_in.txt", "r");
				if (intext == NULL) {
					perror("Error opening file");
					exit(0);
				}

				
				for (int i = 0; i < line_number - 1; i++) {
					if ((read = getline(&line, &len, intext)) == -1) {
						
						printf("Linija nije pronadjena\n");
						free(line);
						fclose(intext);
						exit(0);
					}
				}

			
				if ((read = getline(&line, &len, intext)) != -1) {
							
							fp1 = fopen("/dev/led", "w");
							if(fp1 == NULL)
								{
									printf("Problem pri otvaranju /dev/led\n");
									exit(0);
								}
								fputs(line,fp_d);

								if(fclose(fp1))
								{
									printf("Problem pri zatvaranju /dev/led\n");
									exit(0);
								}
								usleep(period);
				} else {
					printf("Linija nije pronadjena\n");
				}

				free(line);
				fclose(intext);

				//Paljenje dioda

				}else if(button_new==1);
				{
					printf("Zavrsen prikaz kombinacije");			
						
				}
			
	
			button_old = button_new;
		}
		usleep(1);
		







	}


}



//clean_file za brisanje txt fajla sa kombinacijama
void clean_file()
{
	FILE *intext;
	intext=fopen("comb_in.txt","w");
	printf("SADRZAJ DATOTEKE USPESNO OBRISAN \n");
	fclose(intext);
	return;

}
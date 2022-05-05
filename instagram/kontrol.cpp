#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include <math.h>
#include <time.h>



int main(){
	setlocale(LC_ALL,"Turkish");
	
	char takipci[1000][100];
	char takip[1000][100];
	char takipEtmeyen[1000][100];
	char takipEtmediklerin[1000][100];
	char bos[100];
	int takipcisayac=0,takipsayac=0,takipEtmeyensayac1=0,takipEtmeyensayac2=0,takipEtmediklerinsayac1=0,takipEtmediklerinsayac2=0;
	
	FILE *Ftakipci=fopen("hasentakipci.txt","r");
	
	while(!feof(Ftakipci))
	{
		fscanf(Ftakipci,"%s",bos);
		if(!strcmp(bos,"resmi"))
		{
			fscanf(Ftakipci,"%s",takipci[takipcisayac]);
			takipcisayac++;
		}
	}
	printf(" takipçi sayýnýz : %d\n",takipcisayac);
	
	fclose(Ftakipci);
	
	/*for(int i=0;i<takipcisayac;i++)
	{
		printf("%s\n",takipci[i]);
	}*/
	
	
	FILE *Ftakip=fopen("hasentakip.txt","r");
	
	while(!feof(Ftakip))
	{
		fscanf(Ftakip,"%s",bos);
		if(!strcmp(bos,"resmi"))
		{
			fscanf(Ftakip,"%s",takip[takipsayac]);
			takipsayac++;
		}
	}
	printf(" takip sayýnýz : %d\n",takipsayac);
	
	fclose(Ftakip);
	
	/*for(int i=0;i<takipsayac;i++)
	{
		printf("%s\n",takip[i]);
	}*/
	
	for(int i1=0;i1<takipsayac;i1++)
	{
		for(int i2=0;i2<takipcisayac;i2++)
		{
			if(!strcmp(takip[i1],takipci[i2]))
			{
				takipEtmeyensayac1++;
			}
		}
		if(takipEtmeyensayac1==0)
		{
			strcpy(takipEtmeyen[takipEtmeyensayac2],takip[i1]);
			takipEtmeyensayac2++;
		}
		takipEtmeyensayac1=0;
	}
	printf("seni takip etmeyen listesi\n");
	for(int i=0;i<takipEtmeyensayac2;i++)
	{
		printf("%s\n",takipEtmeyen[i]);
	}
	
	
	
	for(int i1=0;i1<takipcisayac;i1++)
	{
		for(int i2=0;i2<takipsayac;i2++)
		{
			if(!strcmp(takipci[i1],takip[i2]))
			{
				takipEtmediklerinsayac1++;
			}
		}
		if(takipEtmediklerinsayac1==0)
		{
			strcpy(takipEtmediklerin[takipEtmediklerinsayac2],takipci[i1]);
			takipEtmediklerinsayac2++;
		}
		takipEtmediklerinsayac1=0;
	}
	printf("\n\n\n\n\n\n\n\nsenin takip etmediklerinin listesi\n");
	for(int i=0;i<takipEtmediklerinsayac2;i++)
	{
		printf("%s\n",takipEtmediklerin[i]);
	}
	
	
	
	return 0;
}

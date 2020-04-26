#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <time.h>

int vale(char ape[],int num);
int valenumero(char ape[],int num);
int valecurp(char ape[],int num);
void mrclean();
int validacionedad(char *edad_ingresada,char *anio_ingresado,char *mes_ingresado);
void mens();
char *relole(char s[]);

int vale(char ape[],int num)
{
	int i,vani;
	vani = 1;
    for(i = 0; i < num; i++)
    {
    	if((ape[i] > 32 && ape[i] < 65) || (ape[i] > 90 && ape[i] < 97) || (ape[i] > 122 && ape[i] < 127))
    	{
    		vani = 0;
		}
	}
	return vani;
}

int valenumero(char ape[],int num)
{
	int i,vani;
	vani = 1;
    for(i = 0; i < num; i++)
    {
    	if(isdigit(ape[i])!=0)
    	{
    		vani = 0;
		}
	}
	return vani;
}

int valecurp(char ape[],int num)
{
	int i,vani=1;
    for(i = 0; i < num; i++)
    {
    	if((ape[i] > 32 && ape[i] < 48) || (ape[i] > 57 && ape[i] < 65) || (ape[i] > 90 && ape[i] < 97)|| (ape[i] > 122 && ape[i] < 127))
    	
    		vani = 0;
		
	}
	return vani;
}

void mrclean()
{
	system("cls");
	_flushall();
}

char *relole(char s[]) 
{
	int i,length;
	length = strlen(s);
   	for(i = 0; i < length ; i++) 
        if (s[i] == '\n')
        	s[i]='\0';
    return s;

}

void mens()
{
	system("cls");
	printf("\n----El formulario esta vacio----\n");	
	printf("Presione cualquier tecla\n");
	system("pause");
}


int validacionedad(char edad_ingresada[],char anio_ingresado[],char mes_ingresado[])
{
 
	time_t t;
  struct tm *tm;
  char anio[100],mes[100];
  int edad_resta;

  t=time(NULL);
  tm=localtime(&t);
  strftime(anio, 100, "%Y", tm);
  strftime(mes, 100, "%m", tm);
  edad_resta = atoi(anio)-atoi(anio_ingresado);
  	if(atoi(mes_ingresado) > atoi(mes))
	  {
	  	edad_resta--;
	  }
  return edad_resta;
  
}


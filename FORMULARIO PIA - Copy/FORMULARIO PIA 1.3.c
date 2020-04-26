#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "validacion 1.0.h"
#include <windows.h>

struct dato
{
	int vald;
	char curp[20];
	char nombre[25];
	char apellidopaterno[25];
	char apellidomaterno[25];
	struct dir
	{
		char calle[25];
		char colonia[25];
		char numero[6];
	} direccion;
	char municipio[25]; 
	char CodigoPostal[7]; 
	char estado[25];
	char pais[25];
	struct fecha
	{
		char dia[4];
		char mes[4];
		char anio[6];
	} nacimiento;
	char edad[4];
	char sexo;
	struct d
	{
		char nombres[25];
		char apellidos[25];
	} tutor; 
} A[100];
 
char menu(char op1);
void alta(struct dato a[],int *p);
void baja(struct dato a[],int p);
void cambio(struct dato a[],int p);
void reporte(struct dato a[],int p);
void ordena(struct dato a[],int p);
void detect(struct dato a[],int p);
void creador_de_archivo_nuevo(struct dato a[],int p);
void SetColor(int ForgC);
int main()
{
	char op;
	int i;
	int n = 0;
	system("cls");
	FILE *formulario=fopen("Formulario.txt","r+");
	FILE *numero=fopen("Numero.txt","r");
	fscanf(numero,"%d ",&n);
	for(i=0;i<n;i++)
	{	
		fscanf(formulario,"%d ",&A[i].vald);
		fscanf(formulario,"%s ",A[i].curp);
		fgets(A[i].apellidopaterno,26,formulario);
		strcpy(A[i].apellidopaterno,relole(A[i].apellidopaterno));
		fgets(A[i].apellidomaterno,26,formulario);
		strcpy(A[i].apellidomaterno,relole(A[i].apellidomaterno));
		fgets(A[i].nombre,26,formulario);
		strcpy(A[i].nombre,relole(A[i].nombre));
		fgets(A[i].direccion.calle,26,formulario);
		strcpy(A[i].direccion.calle,relole(A[i].direccion.calle));
		fscanf(formulario,"%s ",A[i].direccion.numero);
		fgets(A[i].direccion.colonia,26,formulario);
		strcpy(A[i].direccion.colonia,relole(A[i].direccion.colonia));
		fscanf(formulario,"%s ",A[i].CodigoPostal);
		fgets(A[i].municipio,26,formulario);
		strcpy(A[i].municipio,relole(A[i].municipio));
		fgets(A[i].estado,26,formulario);
		strcpy(A[i].estado,relole(A[i].estado));
		fgets(A[i].pais,26,formulario);
		strcpy(A[i].pais,relole(A[i].pais));
		fscanf(formulario,"%s ",A[i].nacimiento.dia);
		fscanf(formulario,"%s ",A[i].nacimiento.mes);
		fscanf(formulario,"%s ",A[i].nacimiento.anio);
		A[i].sexo=fgetc(formulario);
		fscanf(formulario,"%s ",A[i].edad);
		fgets(A[i].tutor.apellidos,26,formulario);
		strcpy(A[i].tutor.apellidos,relole(A[i].tutor.apellidos));
		fgets(A[i].tutor.nombres,26,formulario);
		strcpy(A[i].tutor.nombres,relole(A[i].tutor.nombres));

	}
	
	do
	{
	system("cls");
	op = menu(op);
	mrclean();
		switch(op)
		{
			case 'A':
				alta(A,&n);
				break;
			case 'B':
				baja(A,n);
				break;
			case 'C':
				cambio(A,n);
				break;
			case 'D':
				detect(A,n);
			break;
			case 'E': 
				reporte(A,n);
				break;
			case 'F':
				ordena(A,n);
			    break;
		} 
	} 
	while ( toupper(op) != 'G');
	fclose(formulario);
	fclose(numero);
	return 0;
}

void alta(struct dato a[],int *p)
{
//	system("color 17");
	FILE *formulario=fopen("Formulario.txt","a+");
	char curpnuevo[8],curpnuevo2[8],anio[3],aux;
	char gate;
	int d;
	int longitudcurp,sets,i;
 	do 
	{
		mrclean();
		SetColor(15);
		printf("Ingrese los datos que se piden a continuacion\n");
		do 
		{
			SetColor(2);
			printf("\nNombres:\n\n");
			SetColor(7);
			gets(a[*p].nombre);
			fflush(stdin);
		}
		while(vale(a[*p].nombre,25) == 0);
		do
		{
			SetColor(2);
			printf("\nApellido paterno:\n\n");
			SetColor(7);
			gets(a[*p].apellidopaterno);
			fflush(stdin);
		}
		while(vale(a[*p].apellidopaterno,25) == 0);
		do
		{
			SetColor(2);
			printf("\nApellido materno:\n\n");
			SetColor(7);
			gets(a[*p].apellidomaterno);
			fflush(stdin);
		} 
		while(vale(a[*p].apellidomaterno,25) == 0);
		mrclean();
		printf("\nDomicilio\n");
		do
		{
			SetColor(2);
			printf("\nCalle:\n\n");
			SetColor(7);
			gets(a[*p].direccion.calle);
			fflush(stdin);
		} 
		while(valecurp(a[*p].curp,19) == 0);
		do
		{
			SetColor(2);
			printf("\nNumero:\n\n");
			SetColor(7);
			gets(a[*p].direccion.numero);
		} 
		while(valenumero(a[*p].direccion.numero,6) != 0);
		do
		{
			SetColor(2);
			printf("\nColonia:\n\n");
			SetColor(7);
			gets(a[*p].direccion.colonia);
			fflush(stdin);	
		} 
		while(vale(a[*p].direccion.colonia,25) == 0);
		do
		{
			SetColor(2);
			printf("\nCodigo Postal:\n\n");
			SetColor(7);
			scanf("%s",a[*p].CodigoPostal);
			fflush(stdin);
		} 
		while(valenumero(a[*p].CodigoPostal,6) != 0);
		do
		{
			SetColor(2);
			printf("\nMunicipio:\n\n");
			SetColor(7);
			gets(a[*p].municipio);
			fflush(stdin);
		} 
		while(vale(a[*p].municipio,25) == 0);
		do
		{
			SetColor(2);
			printf("\nEstado:\n\n");
			SetColor(7);
			gets(a[*p].estado);
			fflush(stdin);
		} 
		while(vale(a[*p].estado,25) == 0);
		do
		{
			SetColor(2);
			printf("\nPais:\n\n");
			SetColor(7);
			gets(a[*p].pais);
			fflush(stdin);
		} 
		while(vale(a[*p].pais,25) == 0);
		mrclean();	
		printf("\nFecha de nacimiento\nIngrese los datos numericamente\n");
		do
		{	
			do
			{
				do
				{
					SetColor(2);
					printf("\nDia:\n\n");
					SetColor(7);
	 				scanf("%s",a[*p].nacimiento.dia);
	 				fflush(stdin);
	 			}
				while(valenumero(a[*p].nacimiento.dia,2) != 0);
	 		} 
			while(atoi(a[*p].nacimiento.dia) < 1 || atoi(a[*p].nacimiento.dia) > 31 );
	 		if(atoi(a[*p].nacimiento.dia)<10)
		 	{
	 			aux=a[*p].nacimiento.dia[0];
	 			a[*p].nacimiento.dia[0] = '0';
	 			a[*p].nacimiento.dia[1] = aux;
		 	}	
	 		do
	 		{
	 			do
	 			{
	 				SetColor(2);
	 				printf("\nMes\n\n");
	 				SetColor(7);
	 				scanf("%s",a[*p].nacimiento.mes);
	 				fflush(stdin);
	 			}
				while(valenumero(a[*p].nacimiento.mes,2) != 0);
	 		} 
			while(atoi(a[*p].nacimiento.mes) < 1 || atoi(a[*p].nacimiento.mes) > 12 );
			if(atoi(a[*p].nacimiento.mes)<10)
			{
	 			aux=a[*p].nacimiento.mes[0];
	 			a[*p].nacimiento.mes[0] = '0';
	 			a[*p].nacimiento.mes[1] = aux;
			}	
	 		do
	 		{	
	 			do
	 			{
	 				SetColor(2);
			 		printf("\nAnio\n\n");
			 		SetColor(7);
	 				scanf("%s",a[*p].nacimiento.anio);
	 				fflush(stdin);
	 			}
				while(valenumero(a[*p].nacimiento.anio,4) != 0);
	 		} 
			while(atoi(a[*p].nacimiento.anio) < 1900 || atoi(a[*p].nacimiento.anio) > 2019 );
	 		do
	 		{
	 			SetColor(2);
	 			printf("\nSexo: (M - Mujer H - Hombre)\n\n");
	 			SetColor(7);
	 			a[*p].sexo=toupper(getchar());
	 			fflush(stdin);
	 			switch(a[*p].sexo)
		    	{
		    	case 'M':
				case 'H': sets = 1; break;
				default: sets = 0;	
		 		}
			}
			while(sets == 0);
		
			//NO TOCAR!!!!!
	 		for (i=0; a[*p].nacimiento.anio[i+2] != '\0' ;i++)
	 			anio[i]=a[*p].nacimiento.anio[i+2];
	 		///////////////
			strncpy(&curpnuevo[0],&anio[0],2);
			strncpy(&curpnuevo[2],&a[*p].nacimiento.mes[0],2);
			strncpy(&curpnuevo[4],&a[*p].nacimiento.dia[0],2);
			strncpy(&curpnuevo[6],&a[*p].sexo,1);	
	 		mrclean();
	 		do
			{
				do
				{
					SetColor(2);
					printf("\nCURP:\n\n");
					SetColor(7);
					scanf("%s",a[*p].curp);
					fflush(stdin);
					strupr(a[*p].curp);
					longitudcurp=strlen(a[*p].curp);
				} 
				while(longitudcurp!=18);
			} 
			while(valecurp(a[*p].curp,19) == 0);
			for(i=0;i<8;i++)
				curpnuevo2[i]=0;
			for(i=0;i<7;i++)//substring
				curpnuevo2[i]=a[*p].curp[i+4];	
		}
		while(strcmp(curpnuevo,curpnuevo2)!=0);
		do
		{
			do
	    	{
	    	SetColor(2);
	 		printf("\nEdad\n\n");
	 		SetColor(7);
	 		scanf("%s",a[*p].edad);
	 		fflush(stdin);
	 		}
			while(atoi(a[*p].edad)< 0 || atoi(a[*p].edad)> 100 );
	 		validacionedad(a[*p].edad,a[*p].nacimiento.anio,a[*p].nacimiento.mes);
		}
		while(validacionedad(a[*p].edad,a[*p].nacimiento.anio,a[*p].nacimiento.mes) != atoi(a[*p].edad));
		mrclean();
		printf("\nDatos del tutor\n\n");
		do
		{
			SetColor(2);
			printf("\nNombres del tutor:\n\n");
			SetColor(7);
	 		gets(a[*p].tutor.nombres);
	 		fflush(stdin);
	 	} 
		while(vale(a[*p].tutor.nombres,25) == 0);
	 	do
	 	{
	 		SetColor(2);
	 		printf("\nApellidos del tutor:\n\n");
	 		SetColor(7);
	 		gets(a[*p].tutor.apellidos);
	 		fflush(stdin);
	 	}
		 while(vale(a[*p].tutor.apellidos,25) == 0);
	 	fflush(stdin);
		a[*p].vald = 1;
		fprintf(formulario,"%d\n%s\n%s\n%s\n%s\n",a[*p].vald,strupr(a[*p].curp),strupr(a[*p].apellidopaterno),strupr(a[*p].apellidomaterno),strupr(a[*p].nombre));
		fprintf(formulario,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",strupr(a[*p].direccion.calle),strupr(a[*p].direccion.numero),strupr(a[*p].direccion.colonia),strupr(a[*p].CodigoPostal),strupr(a[*p].municipio),strupr(a[*p].estado),strupr(a[*p].pais));	
	 	fprintf(formulario,"%s\n%s\n%s\n%c\n%s\n%s\n%s\n",strupr(a[*p].nacimiento.dia),strupr(a[*p].nacimiento.mes),strupr(a[*p].nacimiento.anio),toupper(a[*p].sexo),strupr(a[*p].edad),strupr(a[*p].tutor.apellidos),strupr(a[*p].tutor.nombres));
		*p = *p + 1;
	    do
		{
	    	mrclean();
	    	SetColor(15);
	    	printf("\nEscriba s para dar de alta alguien mas\n\n");
			SetColor(2);
			printf("\nS --- Si\n\n");
			SetColor(4);
			printf("\nN --- No\n\n");
			SetColor(15);
	    	gate=toupper(getchar());
	    	fflush(stdin);
	    } 
		while (toupper(gate)!='S' && toupper(gate)!='N');
    } 
	while (toupper(gate) == 'S');
	d=*p;
	FILE *numero=fopen("Numero.txt","w");
	fprintf(numero,"%d",d);	
	fclose(formulario);
	fclose(numero);	
}

void ordena(struct dato a[],int p)
{
	system("color 14");
	struct dato aux;
	int i,j;
	for(i=0;i<p-1;i++)
		for(j=i+1;j<p;j++)
			if(strcmp(a[i].apellidopaterno,a[j].apellidopaterno)>0)
			{
				aux=a[i];
				a[i]=a[j];
				a[j]=aux;
			}
		
	creador_de_archivo_nuevo(a,p);
}

char menu(char op1)
{ 
	system("color 07");
	char cadena[25];
 	do
 	{
 		mrclean();
 		SetColor(7);
 	    printf("\n M E N U\n");
 	    SetColor(14);
	    printf("\n A");
		SetColor(15);
		printf(" - Alta\n");
		SetColor(14);
	    printf("\n B");
		SetColor(15);
		printf(" - Baja\n");
		SetColor(14);
	    printf("\n C");
		SetColor(15);
		printf(" - Cambio\n");
		SetColor(14);
	    printf("\n D");
		SetColor(15);
		printf(" - Detecta\n");
		SetColor(14);
	    printf("\n E");
		SetColor(15);
		printf(" - Reporte\n");
		SetColor(14);
	    printf("\n F");
		SetColor(15);
		printf(" - Ordenar alfabeticamente por apellido paterno\n");
		SetColor(12);
	    printf("\n G");
		SetColor(12);
		printf(" - Salir\n");
		SetColor(15);
		printf("\n\n Creado por ");
		SetColor(11);
		printf("ESTER ABIGAIL CELADA LOPEZ ");
		SetColor(15);
		printf("y ");
		SetColor(11);
		printf("OSCAR IVAN MORENO GUITIERREZ\n");
		SetColor(2);
	    printf("\n\n Escribe la opcion\n\n");
	    SetColor(15);
		op1=toupper(getchar());
	} 
	while( op1 < 65 || op1 > 71);
	return op1; 
}

void baja(struct dato a[],int p)
{
	
	char baj[19], cl;
	int i, bg = 0;
	int temp;
	do 
	{
		do
		{
			mrclean();
			SetColor(2);
			printf("\nEscriba CURP del usuario que quiera dar de baja:\n\n");
			SetColor(12);
			scanf("%s",baj);
		}
		while(strlen(baj)>19);
		//----------------------------------------------------------------sistema de busueda 1.0
		for (i = 0; i < p; i++)
		{
			
		    if(strcmp(strupr(a[i].curp),strupr(baj))  == 0)
			{
			    bg = 1;
				if (a[i].vald == 0)
				{
					mrclean();
					SetColor(15);
					printf("\nEste usuario ya se dio de baja\n\a");
			    }
				else
				{
					do
					{
					    mrclean();
					    SetColor(15);
						printf("\nEsta seguro de dar de baja a este usuario?\n");
						SetColor(2);
						printf("\nS--Si\n");
						SetColor(12);
						printf("\nN--No\n\n");
						scanf("%c",&cl);
					}
					while(toupper(cl) != 'S' && toupper(cl) != 'N');
					if(toupper(cl) == 'S')
						a[i].vald = 0;
						SetColor(15);
				printf("\nEscriba una tecla para regresar al menu\n");	
				}
			}
		}
		creador_de_archivo_nuevo(a,p);
		SetColor(15);
		//--------------------------------------------------------------
		(bg == 1)?printf(""):printf("\nEl usuario con este CURP no existe\n\a");
		getch();
		
		
	}
	while(bg != 1);
	mrclean();
}

void detect(struct dato a[],int p)
{

	char baj[19];
	int i=0;
	do
	{
		mrclean();
		SetColor(15);
		printf("\nEscriba el CURP que quiera buscar:\n\n");
		SetColor(11);
		scanf("%s",baj);
		system("cls");
	}
	while(strlen(baj)>19);
	for (i = 0; i < p; i++)
	{
    	if(strcmp(a[i].curp,strupr(baj)) == 0)
		{
			if (a[i].vald == 0)
			{
				mrclean();
				printf("\nEste usuario ya se dio de baja\n\a");
			}
			else
			{
				SetColor(14);
				printf("Datos personales\n");
				SetColor(2);
				printf("CURP:");
				SetColor(7);
				printf("  %s\n",strupr(a[i].curp));
				SetColor(2);
				printf("Nombre(s):");
				SetColor(7);
				printf("  %s\n",strupr(a[i].nombre));
				SetColor(2);
			    printf("Apellido Paterno:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].apellidopaterno));
				SetColor(2);
			    printf("Apellido Materno:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].apellidomaterno));
				SetColor(14);
			    printf("\nDireccion\n");
			    SetColor(2);
		        printf("Calle:");
		        SetColor(7);
				printf("  %s\n",strupr(a[i].direccion.calle));
				SetColor(2);
		        printf("Numero:");
		        SetColor(7);
				printf("  %s\n",a[i].direccion.numero);
				SetColor(2);
		        printf("Colonia:");
		        SetColor(7);
				printf("  %s\n",strupr(a[i].direccion.colonia));
				SetColor(2);
		        printf("Codigo Postal:");
		        SetColor(7);
				printf("  %s\n",a[i].CodigoPostal);
				SetColor(2);
			    printf("Municipio:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].municipio));
				SetColor(2);
			    printf("Estado:");
				SetColor(7);
				printf("  %s\n",strupr(a[i].estado));
				SetColor(2);
			    printf("Pais:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].pais));
				SetColor(14);
			    printf("\nFecha de nacimiento\n");
			    SetColor(2);
			    printf("Dia:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.dia);
				SetColor(2);
			    printf("Mes:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.mes);
				SetColor(2);
			    printf("Anio:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.anio);
				SetColor(2);
			    printf("Sexo:");
			    SetColor(7);
				printf("  %c\n",toupper(a[i].sexo));
				SetColor(2);
			    printf("Edad:");
			    SetColor(7);
				printf("  %s\n",a[i].edad);
			    SetColor(14);
			    printf("\nDatos del tutor\n");
			    SetColor(2);
			    printf("Nombres del tutor:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].tutor.nombres));
			    SetColor(2);
			    printf("Apellidos del tutor:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].tutor.apellidos));  
			}
			getch();
			printf("\n");
		}
		
	}
	SetColor(15);
	printf("Presione una tecla para regresar al menu");
	getch();
}

void reporte(struct dato a[],int p)
{
	mrclean();
	int i=0,j;
	printf("REPORTE DEL FORMULARIO\n");
	for( i=0; i < p ;i++)
	{	
	    if(a[i].vald == 1 )
	    {
	        for( j = i - 1 ; j < i; j++ )
		    {		
		    		SetColor(14);
				printf("\nDatos personales\n");
				SetColor(2);
				printf("\nCURP:");
				SetColor(7);
				printf("  %s\n",strupr(a[i].curp));
				SetColor(2);
				printf("Nombre(s):");
				SetColor(7);
				printf("  %s\n",strupr(a[i].nombre));
				SetColor(2);
			    printf("Apellido Paterno:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].apellidopaterno));
				SetColor(2);
			    printf("Apellido Materno:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].apellidomaterno));
				SetColor(14);
			    printf("\nDireccion\n");
			    SetColor(2);
		        printf("Calle:");
		        SetColor(7);
				printf("  %s\n",strupr(a[i].direccion.calle));
				SetColor(2);
		        printf("Numero:");
		        SetColor(7);
				printf("  %s\n",a[i].direccion.numero);
				SetColor(2);
		        printf("Colonia:");
		        SetColor(7);
				printf("  %s\n",strupr(a[i].direccion.colonia));
				SetColor(2);
		        printf("Codigo Postal:");
		        SetColor(7);
				printf("  %s\n",a[i].CodigoPostal);
				SetColor(2);
			    printf("Municipio:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].municipio));
				SetColor(2);
			    printf("Estado:");
				SetColor(7);
				printf("  %s\n",strupr(a[i].estado));
				SetColor(2);
			    printf("Pais:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].pais));
				SetColor(14);
			    printf("\nFecha de nacimiento\n");
			    SetColor(2);
			    printf("Dia:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.dia);
				SetColor(2);
			    printf("Mes:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.mes);
				SetColor(2);
			    printf("Anio:");
			    SetColor(7);
				printf("  %s\n",a[i].nacimiento.anio);
				SetColor(2);
			    printf("Sexo:");
			    SetColor(7);
				printf("  %c\n",toupper(a[i].sexo));
				SetColor(2);
			    printf("Edad:");
			    SetColor(7);
				printf("  %s\n",a[i].edad);
			    SetColor(14);
			    printf("\nDatos del tutor\n");
			    SetColor(2);
			    printf("Nombres del tutor:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].tutor.nombres));
			    SetColor(2);
			    printf("Apellidos del tutor:");
			    SetColor(7);
				printf("  %s\n",strupr(a[i].tutor.apellidos));   
            }
            SetColor(9);
		    printf("\n-----------------------------\n");
		}
	}
	SetColor(15);
	printf("\nPresione una tecla para regresar al menu\n");
	getch();				
}

void cambio(struct dato a[],int p)
{
	char cam[19],anio[3],curpnuevo[8],curpnuevo2[8];
	int i,cl,bg,sets,longitudcurp,k,buno = 0;
		do
		{
		mrclean();
		
		printf("\nEscriba el CURP que quiera cambiar:\n");
		SetColor(11);
		scanf("%s",cam);
		fflush(stdin);
		}
		while(strlen(cam)>19);
	for (i = 0; i < p; i++)
	{
		if(strcmp(strupr(a[i].curp),strupr(cam)) == 0)
		{
		    bg = 1;	
			if (a[i].vald == 0)
			{
				printf("\nEste usuario se dio de baja");
			}
			else
			{
				do
				{
					SetColor(2);
					printf("\nInserte lo que desea cambiar\n");
					SetColor(7);
					printf("1 ---- Nombres\n");
					printf("2 ---- Apellido paterno\n");
					printf("3 ---- Apellido materno\n");
					printf("4 ---- Calle\n");
					printf("5 ---- Colonia\n");
					printf("6 ---- Numero\n");
					printf("7 ---- Codigo Postal\n");
					printf("8 ---- Municipio\n");
					printf("9 ---- Estado\n");
					printf("10 ---- Pais\n");
					printf("11 ---- Dia\n");
					printf("12 ---- Mes\n");
					printf("13 ---- Anio\n");
					printf("14 ---- Sexo\n");
					printf("15 ---- CURP\n");
					printf("16 ---- Edad\n");
					printf("17 ---- Nombres del tutor\n");
					printf("18 ---- Apellidos del tutor\n");
					printf("19 ---- Salir\n");
					scanf("%d",&cl);
					fflush(stdin);
				}
				while(cl < 1 || cl > 19);
				switch(cl)
				{
						case 1:
							do 
							{
								mrclean();
								SetColor(2);
								printf("\nInserte los nuevos nombres:\n");
								SetColor(14);
							    gets(a[i].nombre);
							}
							while(vale(a[i].nombre,25) == 0);
						break;
						case 2:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo apellido paterno\n");
							    SetColor(14);
							    gets(a[i].apellidopaterno);
							}
							while(vale(a[i].apellidopaterno,25) == 0);
						break;
						case 3:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo apellido materno\n");
							    SetColor(14);
							    gets(a[i].apellidomaterno);
							}
							while(vale(a[i].apellidomaterno,25) == 0);
						break;
						case 4:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte la nueva calle:\n ");
							    SetColor(14);
							    gets(a[i].direccion.calle);
							}
							while(vale(a[i].direccion.calle,25) == 0);
						break;
						
						case 5:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte la nueva colonia:\n");
							    SetColor(14);
							    gets(a[i].direccion.colonia);
							}
							while(vale(a[i].direccion.colonia,25) == 0);
							break;
						case 6:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo numero:\n");
							    SetColor(14);
							    scanf("%s",a[i].direccion.numero);
							}
							while(valenumero(a[i].direccion.numero,5) != 0);
							break;
						case 7:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo codigo postal:\n");
							    SetColor(14);
							    scanf("%s",a[i].CodigoPostal);
							}
							while(valenumero(a[i].CodigoPostal,5) != 0);
							break;
						case 8:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo municipio:\n");
							    SetColor(14);
							    gets(a[i].municipio);
							}
							while(vale(a[i].municipio,25) == 0);
							break;
						case 9:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo estado:\n");
							    SetColor(14);
							    gets(a[i].estado);
							}
							while(vale(a[i].estado,25) == 0);
							break;
						case 10:
							do
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte el nuevo pais:\n");
							    SetColor(14);
							    gets(a[i].pais);
							}
							while(vale(a[i].pais,25) == 0);
							break;
						case 11:
						case 12:
						case 13:
						case 14:
						case 15:
						case 16:
								do
								{	
								    mrclean();
									do
									{
										do
										{
											SetColor(2);
											printf("\nDia:\n");
											SetColor(14);
								 			scanf("%s",a[i].nacimiento.dia);
								 			fflush(stdin);
								 		}
										while(valenumero(a[i].nacimiento.dia,2) != 0);
								 	}
									while(atoi(a[i].nacimiento.dia) < 1 || atoi(a[i].nacimiento.dia) > 31 );
								 	char aux;
								 	if(atoi(a[i].nacimiento.dia)<10)
									{
								 		aux=a[i].nacimiento.dia[0];
								 		a[i].nacimiento.dia[0] = '0';
								 		a[i].nacimiento.dia[1] = aux;
									}	
								 	do
								 	{
								 		do
								 		{
								 			SetColor(2);
								 			printf("Mes\n");
								 			SetColor(14);
								 			scanf("%s",a[i].nacimiento.mes);
								 			fflush(stdin);
								 		}
										while(valenumero(a[i].nacimiento.mes,2) != 0);
								 	}
									while(atoi(a[i].nacimiento.mes) < 1 || atoi(a[i].nacimiento.mes) > 12 );
									if(atoi(a[i].nacimiento.mes)<10)
									{
								 		aux=a[i].nacimiento.mes[0];
								 		a[i].nacimiento.mes[0] = '0';
								 		a[i].nacimiento.mes[1] = aux;
									}	
									do
								 	{
								 		do
								 		{
								 			SetColor(2);
										 	printf("Anio\n");
										 	SetColor(14);
								 			scanf("%s",a[i].nacimiento.anio);
								 			fflush(stdin);
								 		}while(valenumero(a[i].nacimiento.anio,4) != 0);
								 	} while(atoi(a[i].nacimiento.anio) < 1900 || atoi(a[i].nacimiento.anio) > 2019 );
					 		    	do
								 	{
								 		SetColor(2);
								 		printf("Sexo: (M - Mujer H - Hombre)\n");
								 		SetColor(14);
								 		a[i].sexo=toupper(getchar());
								 		fflush(stdin);
								 		switch(a[i].sexo)
									    {
									    	case 'M':
											case 'H': sets = 1; break;
											default: sets = 0;	
									 	}
									}
									while(sets == 0);
								 	//NO TOCAR!!!!!
								 	for (k=0; a[i].nacimiento.anio[k+2] != '\0' ;k++)
								 		anio[k]=a[i].nacimiento.anio[k+2];
								 	//////////////
									strncpy(&curpnuevo[0],&anio[0],2);
									strncpy(&curpnuevo[2],&a[i].nacimiento.mes[0],2);
									strncpy(&curpnuevo[4],&a[i].nacimiento.dia[0],2);
									strncpy(&curpnuevo[6],&a[i].sexo,1);	
								 	mrclean();
								 	do
									{
										do
										{
											SetColor(2);
											printf("CURP:\n");
											SetColor(14);
											scanf("%s",a[i].curp);
								 			fflush(stdin);
											strupr(a[i].curp);
											longitudcurp=strlen(a[i].curp);
										} 
										while(longitudcurp!=18);
									} 
									while(valecurp(a[i].curp,19) == 0);
									for(k=0;k<8;k++)
										curpnuevo2[k]=0;
									for(k=0;k<7;k++)//substring
										curpnuevo2[k]=a[i].curp[k+4];		
								}
								while(strcmp(curpnuevo,curpnuevo2)!=0);
								
								do{
									do
								    {
								    	SetColor(2);
								    	printf("Edad:\n");
								    	SetColor(14);
								 		scanf("%s",a[i].edad);
								 		fflush(stdin);
								 	} 
									while(atoi(a[i].edad)< 0 || atoi(a[i].edad)> 100 );
								 	validacionedad(a[i].edad,a[i].nacimiento.anio,a[i].nacimiento.mes);
								}
								while(validacionedad(a[i].edad,a[i].nacimiento.anio,a[i].nacimiento.mes) != atoi(a[i].edad));
								break;
						case 17:
							do 
							{
								mrclean();
								SetColor(2);
							    printf("\nInserte los nuevos nombres del tutor:\n");
							    SetColor(14);
							    gets(a[i].tutor.nombres);
								fflush(stdin);
							}
							while(vale(a[i].tutor.nombres,25) == 0);
							break;
						case 18:
							do 
							{
								mrclean();
								SetColor(2);
						    	printf("\nInserte los nuevos apellidos del tutor:\n");
						    	SetColor(14);
							    gets(a[i].tutor.apellidos);
								fflush(stdin);
							}
							while(vale(a[i].tutor.apellidos,25) == 0);
							break;
						case 19: 
						    buno = 1;
							break;
					}
					
					mrclean();
					if(buno != 1)
					{
						SetColor(14);
						printf("Datos personales\n");
						SetColor(2);
						printf("CURP:");
						SetColor(7);
						printf("  %s\n",strupr(a[i].curp));
						SetColor(2);
						printf("Nombre(s):");
						SetColor(7);
						printf("  %s\n",strupr(a[i].nombre));
						SetColor(2);
					    printf("Apellido Paterno:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].apellidopaterno));
						SetColor(2);
					    printf("Apellido Materno:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].apellidomaterno));
						SetColor(14);
					    printf("\nDireccion\n");
					    SetColor(2);
				        printf("Calle:");
				        SetColor(7);
						printf("  %s\n",strupr(a[i].direccion.calle));
						SetColor(2);
				        printf("Numero:");
				        SetColor(7);
						printf("  %s\n",a[i].direccion.numero);
						SetColor(2);
				        printf("Colonia:");
				        SetColor(7);
						printf("  %s\n",strupr(a[i].direccion.colonia));
						SetColor(2);
				        printf("Codigo Postal:");
				        SetColor(7);
						printf("  %s\n",a[i].CodigoPostal);
						SetColor(2);
					    printf("Municipio:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].municipio));
						SetColor(2);
					    printf("Estado:");
						SetColor(7);
						printf("  %s\n",strupr(a[i].estado));
						SetColor(2);
					    printf("Pais:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].pais));
						SetColor(14);
					    printf("\nFecha de nacimiento\n");
					    SetColor(2);
					    printf("Dia:");
					    SetColor(7);
						printf("  %s\n",a[i].nacimiento.dia);
						SetColor(2);
					    printf("Mes:");
					    SetColor(7);
						printf("  %s\n",a[i].nacimiento.mes);
						SetColor(2);
					    printf("Anio:");
					    SetColor(7);
						printf("  %s\n",a[i].nacimiento.anio);
						SetColor(2);
					    printf("Sexo:");
					    SetColor(7);
						printf("  %c\n",toupper(a[i].sexo));
						SetColor(2);
					    printf("Edad:");
					    SetColor(7);
						printf("  %s\n",a[i].edad);
					    SetColor(14);
					    printf("\nDatos del tutor\n");
					    SetColor(2);
					    printf("Nombres del tutor:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].tutor.nombres));
					    SetColor(2);
					    printf("Apellidos del tutor:");
					    SetColor(7);
						printf("  %s\n",strupr(a[i].tutor.apellidos));  
							
					}
					SetColor(15);	
					printf("\nEscriba una tecla para regresar al menu\n");
			}
		}
	}
	creador_de_archivo_nuevo(a,p);
	SetColor(15);
	(bg == 1)?printf(""):printf("\nEl usuario con el CURP que ingreso no existe\n\a");
	getch();
}

void creador_de_archivo_nuevo(struct dato a[],int p)
{
	int i;
	FILE *temp =fopen("Formulario.txt","wt");
	for(i = 0; i < p; i++)
	{
		fprintf(temp,"%d\n%s\n%s\n%s\n%s\n",a[i].vald,strupr(a[i].curp),strupr(a[i].apellidopaterno),strupr(a[i].apellidomaterno),strupr(a[i].nombre));
		fprintf(temp,"%s\n%s\n%s\n%s\n%s\n%s\n%s\n",strupr(a[i].direccion.calle),strupr(a[i].direccion.numero),strupr(a[i].direccion.colonia),strupr(a[i].CodigoPostal),strupr(a[i].municipio),strupr(a[i].estado),strupr(a[i].pais));	
		fprintf(temp,"%s\n%s\n%s\n%c\n%s\n%s\n%s\n",strupr(a[i].nacimiento.dia),strupr(a[i].nacimiento.mes),strupr(a[i].nacimiento.anio),toupper(a[i].sexo),strupr(a[i].edad),strupr(a[i].tutor.apellidos),strupr(a[i].tutor.nombres));
	}
	fclose(temp);
}

 void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 //Mask out all but the background attribute, and add in the forgournd     color
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#include <time.h>


struct turno
{
	int tipo_fila; //0 para la fila rapida, 1 para la fila lenta, 2 executive
	char turno_nombre[5]; // A-00 - C-99
	char operacion[30];
	int hora_c;
	int min_c;
	int seg_c;
	struct turno *siguiente; 
};

typedef struct turno TURNO;
typedef TURNO *FAST; // PARA FILAS DE 1 A 2 MOVIMIENTOS
typedef TURNO *SLOW; // PARA FILAS DE 3 A 4 MOVIMIENTOS
typedef TURNO *EXECUTIVE; // PARA FILAS CON EJECUTIVOS


struct turno_t
{
	int tipo_fila; //0 para la fila rapida, 1 para la fila lenta, 2 executive
	char turno_nombre[5]; // A-00 - C-99
	char operacion[30];
	//Tiempo de creacion
	int hora_c;
	int min_c;
	int seg_c;
	//Tiempo de eliminacion
	int hora_e;
	int min_e;
	int seg_e;
	struct turno_t *siguiente; 
};
typedef struct turno_t TURNO_T;
typedef TURNO_T *CABEZA_T;


int menu_principal();
void  fila_fast(FAST *CABEZA,int num,int operacion_n);
void  fila_slow(SLOW *CABEZA,int num,int operacion_n);
void  fila_executive(EXECUTIVE *CABEZA,int num,int operacion_n);
void printlista_fast(FAST);
void printlista_slow(SLOW);
void printlista_executive(EXECUTIVE);
void impresion_ticket(char ticket[5]);
void creacion_de_espera(FAST ,SLOW ,EXECUTIVE );
void eliminacion_ticket();
void SetColor(int ForgC);
int elimi_slow(char name[5],SLOW *);
int elimi_fast(char name[5],FAST *);
int elimi_exec(char name[5],EXECUTIVE *);
void imprimir_lista_tiempos(CABEZA_T actual);
void agregar_a_lista_tiempos(TURNO *copy_me);


void gotoxy(int x,int y){  
      HANDLE hcon;  
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);  
      COORD dwPos;  
      dwPos.X = x;  
      dwPos.Y= y;  
      SetConsoleCursorPosition(hcon,dwPos);  
}
//Variables globales
FAST CABEZA_FAST=NULL;
SLOW CABEZA_SLOW=NULL;
EXECUTIVE CABEZA_EXECUTIVE=NULL;
CABEZA_T CABEZA_TIEMPO=NULL;


int main()
{
	system("color 07");
/*	FAST CABEZA_FAST=NULL;
	SLOW CABEZA_SLOW=NULL;
	EXECUTIVE CABEZA_EXECUTIVE=NULL;*/
	int A=0,B=0,C=0;
	int m_principal;
	
	int i;
	char n;
	do
	{	
		system("cls");
		SetColor(3);
		printf("\n\t\t\t\tMENU PRINCIPAL\n");
		SetColor(7);
		printf("\n\t\t\t Elija una opcion:\n");
		SetColor(3);
		printf("\n\t\t\tA");SetColor(7);printf(" - Crear un ticket\n");
		SetColor(3);
		printf("\n\t\t\tB");SetColor(7);printf(" - Impresion de clientes siendo atendidos\n");
		SetColor(3);
		printf("\n\t\t\tC");SetColor(7);printf(" - Eliminar ticket\n");
		SetColor(3);
		printf("\n\t\t\tD");SetColor(7);printf(" - Impresion de tiempos de tickets eliminados\n");
		SetColor(3);
		printf("\n\t\t\tE");SetColor(7);printf(" - SALIR\n\n\t\t\t");
		scanf("%c",&n);
		n=toupper(n);
		switch(n)
		{
			case 'A':
				system("cls");
				m_principal=menu_principal();
				switch(m_principal)
				{
					case 1:
						system("cls");
						A++;
						fila_fast(&CABEZA_FAST,A,1);
						printlista_fast(CABEZA_FAST);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 2:
						system("cls");
						A++;
						fila_fast(&CABEZA_FAST,A,2);
						printlista_fast(CABEZA_FAST);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 3:
						system("cls");
						A++;
						fila_fast(&CABEZA_FAST,A,3);
						printlista_fast(CABEZA_FAST);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 4:
						system("cls");
						B++;
						fila_slow(&CABEZA_SLOW,B,4);
						printlista_slow(CABEZA_SLOW);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 5:
						system("cls");
						B++;
						fila_slow(&CABEZA_SLOW,B,5);
						printlista_slow(CABEZA_SLOW);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 6:
						system("cls");
						C++;
						fila_executive(&CABEZA_EXECUTIVE,C,6);
						printlista_executive(CABEZA_EXECUTIVE);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 7:
						system("cls");
						C++;
						fila_executive(&CABEZA_EXECUTIVE,C,7);
						printlista_executive(CABEZA_EXECUTIVE);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 8:
						system("cls");
						C++;
						fila_executive(&CABEZA_EXECUTIVE,C,8);
						printlista_executive(CABEZA_EXECUTIVE);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 9:
						system("cls");
						C++;
						fila_executive(&CABEZA_EXECUTIVE,C,9);
						printlista_executive(CABEZA_EXECUTIVE);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
					case 10:
						system("cls");
						C++;
						fila_executive(&CABEZA_EXECUTIVE,C,10);
						printlista_executive(CABEZA_EXECUTIVE);
						gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
						getch();
						break;
				}
				
			break;	
			
			case 'B':
				system("cls");
				creacion_de_espera(CABEZA_FAST,CABEZA_SLOW,CABEZA_EXECUTIVE);
				gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
				getch();
			break;
			
			case 'C':
				system("cls");
				fflush(stdin);
				eliminacion_ticket();
				gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
				getch();
				break;
				
			case 'D':
				system("cls");
			//	gotoxy(10,10);
				imprimir_lista_tiempos(CABEZA_TIEMPO);
				gotoxy(40,25);SetColor(7);printf("Presione cualquier tecla para continuar");
				getch();
				break;
				
		}
		
	}while(n!=69);
	
	return 0;
}



int menu_principal()
{
	system("color 07");
	char op1;
	int op;
	do
	{
		fflush(stdin);
		system("cls");
		SetColor(3);//3 8 y 6 7
		printf("\n\t\t\t\tMENU\n");
		SetColor(7);
		printf("\n\t\t\t Elija lo que desee realizar:\n");
		SetColor(3);
		printf("\n\t\t\tA");SetColor(7);printf(" - Retiro de efectivo\n");
		SetColor(3);
		printf("\n\t\t\tB");SetColor(7);printf(" - Deposito de efectivo\n");
		SetColor(3);
		printf("\n\t\t\tC");SetColor(7);printf(" - Pagos de servicios\n");
		SetColor(3);
		printf("\n\t\t\tD");SetColor(7);printf(" - Solicitud de Estado de Cuenta\n");
		SetColor(3);
		printf("\n\t\t\tE");SetColor(7);printf(" - Movimientos de chequera\n");
		SetColor(3);
		printf("\n\t\t\tF");SetColor(7);printf(" - Asistencia con un ejecutivo\n");
		SetColor(3);
		printf("\n\t\t\tG");SetColor(7);printf(" - Apertura de cuenta\n");
		SetColor(3);
		printf("\n\t\t\tH");SetColor(7);printf(" - Cierre de cuenta\n");
		SetColor(3);
		printf("\n\t\t\tI");SetColor(7);printf(" - Solicitud de prestamo\n");
		SetColor(3);
		printf("\n\t\t\tJ");SetColor(7);printf(" - Aclaraciones\n\t\t\t");
		SetColor(3);
		
		scanf("%c",&op1);
		op1=toupper(op1);
	}while(op1<65||op1>74);	
	
		switch(op1)
		{
			case 'A':
				op=1;
				break;
			case 'B':
				op=2;
				break;
			case 'C':
				op=3;
				break;
			case 'D':
				op=4;
				break;
			case 'E':
				op=5;
				break;
			case 'F':
				op=6;
				break;
			case 'G':
				op=7;
				break;
			case 'H':
				op=8;
				break;
			case 'I':
				op=9;
				break;
			case 'J':
				op=10;
				break;
		}			
			
	return op;	
	
	
}

	
void fila_fast(FAST *CABEZA,int num,int operacion_n)
{
	//creacion de tiempo
	struct tm *local;
	time_t t;	
	t = time(NULL);
	//concatenacion de strings
	char ticket[4]={'A','-'}, ticket2[4]={'B','-'}, ticket3[4]={'C','-'},ticket4[4]={'D','-'},ticket5[4]={'E','-'};
	char decimal[2],decimal2[2],decimal3[2],decimal4[2],decimal5[2];
	char operacion[30];
	num=num-1;
	FAST nuevo,previo,actual;
	switch(operacion_n)
	{
		case 1:
			strcpy(operacion,"Retiro de efectivo");
			break;
		case 2:
			strcpy(operacion,"Deposito de efectivo");
			break;
		case 3:
			strcpy(operacion,"Pago de servicios");
			break;
		case 4:
			strcpy(operacion,"Solicitud de Estado de Cuenta");
			break;
		case 5:
			strcpy(operacion,"Movimientos de chequera");
			break;
		case 6:
			strcpy(operacion,"Asistencia con un ejecutivo");
			break;
		case 7:
			strcpy(operacion,"Apertura de cuenta");
			break;
		case 8:
			strcpy(operacion,"Cierre de cuenta");
			break;
		case 9:
			strcpy(operacion,"Solicitud de prestamo");
			break;
		case 10:
			strcpy(operacion,"Aclaraciones");
			break;
	}
	nuevo=malloc(sizeof(TURNO));
	if(nuevo != NULL)
	{
		nuevo->tipo_fila=0;//indicacion de 0 en la fila rapida
		local=localtime(&t);
		//impresion en el ticket
		nuevo->hora_c=local->tm_hour;
		nuevo->min_c=local->tm_min;
		nuevo->seg_c=local->tm_sec;
		strcpy(nuevo->operacion,operacion);
		if(num<=99)
		{
			itoa(num,decimal,10);
			strcat(ticket,decimal);
			strcpy(nuevo->turno_nombre,ticket);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			 impresion_ticket(ticket); 
			}
			  
		if(num>99&&num<=198)
		{
			itoa(num-99,decimal2,10);
			strcat(ticket2,decimal2);
			strcpy(nuevo->turno_nombre,ticket2);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			impresion_ticket(ticket2);	
		}
		
		if(num>198&&num<=297)
		{
			 
			itoa(num-198,decimal3,10);
			strcat(ticket3,decimal3);
			strcpy(nuevo->turno_nombre,ticket3);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			impresion_ticket(ticket3);	
			
			if(num>297&&num<=396)
			{
				itoa(num-297,decimal4,10);
				strcat(ticket4,decimal4);
				strcpy(nuevo->turno_nombre,ticket4);
				nuevo->siguiente = NULL;
				previo = NULL;
				actual = *CABEZA;
				while (actual != NULL) 
				  {
					previo = actual;
					actual = actual -> siguiente;
				  }
				if (previo == NULL) 
				  {
					nuevo -> siguiente = *CABEZA;
					*CABEZA = nuevo;
				  }
				else 
				  {
					previo -> siguiente = nuevo;
					nuevo -> siguiente = actual;
				  }
				impresion_ticket(ticket4);	
				
				if(num>396&&num<=495)
				{
					itoa(num-396,decimal5,10);
					strcat(ticket5,decimal5);
					strcpy(nuevo->turno_nombre,ticket5);
					nuevo->siguiente = NULL;
					previo = NULL;
					actual = *CABEZA;
					while (actual != NULL) 
					  {
						previo = actual;
						actual = actual -> siguiente;
					  }
					if (previo == NULL) 
					  {
						nuevo -> siguiente = *CABEZA;
						*CABEZA = nuevo;
					  }
					else 
					  {
						previo -> siguiente = nuevo;
						nuevo -> siguiente = actual;
					  }
					impresion_ticket(ticket5);
				}
			}
		}
	}
	else {
		printf("Error por favor consultar a un empleado!!\n");
	}
}

void  fila_slow(SLOW *CABEZA,int num,int operacion_n)
{
	struct tm *local;
	time_t t;	
	t = time(NULL);	
	//concatenacion de strings
	char ticket[4]={'F','-'}; char ticket2[4]={'G','-'}; char ticket3[4]={'H','-'};
	char decimal[2], decimal2[2], decimal3[2];
	char operacion[30];
	num=num-1;
	SLOW nuevo,previo,actual;
	switch(operacion_n)
	{
		case 1:
			strcpy(operacion,"Retiro de efectivo");
			break;
		case 2:
			strcpy(operacion,"Deposito de efectivo");
			break;
		case 3:
			strcpy(operacion,"Pago de servicios");
			break;
		case 4:
			strcpy(operacion,"Solicitud de Estado de Cuenta");
			break;
		case 5:
			strcpy(operacion,"Movimientos de chequera");
			break;
		case 6:
			strcpy(operacion,"Asistencia con un ejecutivo");
			break;
		case 7:
			strcpy(operacion,"Apertura de cuenta");
			break;
		case 8:
			strcpy(operacion,"Cierre de cuenta");
			break;
		case 9:
			strcpy(operacion,"Solicitud de prestamo");
			break;
		case 10:
			strcpy(operacion,"Aclaraciones");
			break;
	}
	nuevo=malloc(sizeof(TURNO));
	if(nuevo != NULL)
	{
		nuevo->tipo_fila=1;//indicacion de 1 en la fila slow
		local=localtime(&t);
		nuevo->hora_c=local->tm_hour;
		nuevo->min_c=local->tm_min;
		nuevo->seg_c=local->tm_sec;
		strcpy(nuevo->operacion,operacion);
		if(num<=99)
		{
				itoa(num,decimal,10);
			strcat(ticket,decimal);
			strcpy(nuevo->turno_nombre,ticket);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			  impresion_ticket(ticket);
		}
		
		if(num>99&&num<=198)
		{
			itoa(num-99,decimal2,10);
			strcat(ticket2,decimal2);
			strcpy(nuevo->turno_nombre,ticket2);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			  impresion_ticket(ticket2);
		}
		
		if(num>198&&num<=297)
		{
			itoa(num-198,decimal3,10);
			strcat(ticket3,decimal3);
			strcpy(nuevo->turno_nombre,ticket3);
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
			  {
				previo = actual;
				actual = actual -> siguiente;
			  }
			if (previo == NULL) 
			  {
				nuevo -> siguiente = *CABEZA;
				*CABEZA = nuevo;
			  }
			else 
			  {
				previo -> siguiente = nuevo;
				nuevo -> siguiente = actual;
			  }
			  impresion_ticket(ticket3);
		}
	}

}

void  fila_executive(EXECUTIVE *CABEZA,int num,int operacion_n)
{
	struct tm *local;
	time_t t;	
	t = time(NULL);
	//concatenacion de strings
	char ticket[4]={'I','-'},ticket2[4]={'J','-'};
	char decimal[2],decimal2[2];
	char operacion[30];
	num=num-1;
	EXECUTIVE nuevo,previo,actual;
	switch(operacion_n)
	{
		case 1:
			strcpy(operacion,"Retiro de efectivo");
			break;
		case 2:
			strcpy(operacion,"Deposito de efectivo");
			break;
		case 3:
			strcpy(operacion,"Pago de servicios");
			break;
		case 4:
			strcpy(operacion,"Solicitud de Estado de Cuenta");
			break;
		case 5:
			strcpy(operacion,"Movimientos de chequera");
			break;
		case 6:
			strcpy(operacion,"Asistencia con un ejecutivo");
			break;
		case 7:
			strcpy(operacion,"Apertura de cuenta");
			break;
		case 8:
			strcpy(operacion,"Cierre de cuenta");
			break;
		case 9:
			strcpy(operacion,"Solicitud de prestamo");
			break;
		case 10:
			strcpy(operacion,"Aclaraciones");
			break;
	}
	nuevo=malloc(sizeof(TURNO));
	if(nuevo != NULL)
	{
		nuevo->tipo_fila=2;//indicacion de 2 en la fila ejecutiva
		local=localtime(&t);
		nuevo->hora_c=local->tm_hour;
		nuevo->min_c=local->tm_min;
		nuevo->seg_c=local->tm_sec;
		strcpy(nuevo->operacion,operacion);
		if(num<=99)
		{
			
			itoa(num,decimal,10);
			strcat(ticket,decimal);
			strcpy(nuevo->turno_nombre,ticket); 
			nuevo->siguiente = NULL;
			previo = NULL;
			actual = *CABEZA;
			while (actual != NULL) 
				  {
					previo = actual;
					actual = actual -> siguiente;
				  }
				if (previo == NULL) 
				  {
					nuevo -> siguiente = *CABEZA;
					*CABEZA = nuevo;
				  }
				else 
				  {
					previo -> siguiente = nuevo;
					nuevo -> siguiente = actual;
				  }
				impresion_ticket(ticket);
		}
		
		if(num>99&&num<=198)
		{
			itoa(num-99,decimal2,10);
			strcat(ticket2,decimal2);
			strcpy(nuevo->turno_nombre,ticket2);
			nuevo->siguiente = NULL;
				previo = NULL;
				actual = *CABEZA;
				while (actual != NULL) 
				  {
					previo = actual;
					actual = actual -> siguiente;
				  }
				if (previo == NULL) 
				  {
					nuevo -> siguiente = *CABEZA;
					*CABEZA = nuevo;
				  }
				else 
				  {
					previo -> siguiente = nuevo;
					nuevo -> siguiente = actual;
				  }
				impresion_ticket(ticket2);
		}
	}
}

void printlista_fast(FAST actual)
{
	if (actual == NULL)
	{
		gotoxy(20,16); 
		SetColor(12);printf("Error, lista vacia");
	}
	else 
	 {
	 	gotoxy(44,16);SetColor(7);
	 	printf(" - - FILA - - \n");
		while (actual != NULL) 
		  {
		  	
			printf("\n\t\t\t\t\t\t%s | %d: %d: %d|--> ",actual -> turno_nombre,actual->hora_c,actual->min_c,actual->seg_c);
			actual = actual -> siguiente;
		  } 
		printf("NULL \n\n");
	 }
}

void printlista_slow(SLOW actual)
{
	if (actual == NULL)
	{
		gotoxy(50,16); 
		SetColor(12);printf("Error, lista vacia");
	}
	else 
	 {
	 	gotoxy(44,16);SetColor(7);
	 	printf(" - - FILA  - - \n");
		while (actual != NULL) 
		  {
		  	
			printf("\n\t\t\t\t\t\t%s | %d: %d: %d|--> ",actual -> turno_nombre,actual->hora_c,actual->min_c,actual->seg_c);
			actual = actual -> siguiente;
		  } 
		printf("NULL \n\n");
	 }
}

void printlista_executive(EXECUTIVE actual)
{
	if (actual == NULL)
	{
		gotoxy(50,16); 
		SetColor(12);printf("Error, lista vacia");
	}
	else 
	 {
	 	gotoxy(37,16);SetColor(7);
	 	printf(" - - FILA DE ASISTENCIA EJECUTIVA - - \n");
		while (actual != NULL) 
		  {
		  	
			printf("\n\t\t\t\t\t\t%s | %d: %d: %d|--> ",actual -> turno_nombre,actual->hora_c,actual->min_c,actual->seg_c);
			actual = actual -> siguiente;
		  } 
		printf("NULL \n\n");
	 }
}

void impresion_ticket(char ticket[5])
{
	system("cls");
	SetColor(3);
	gotoxy(20,5);printf("---------------------------------------------------------------------");
	gotoxy(20,6);printf("|");gotoxy(88,6);printf("|");
	SetColor(3);
	gotoxy(20,7);printf("|"); SetColor(9);gotoxy(50,7);printf("BANCO VVBA");SetColor(3);gotoxy(88,7);printf("|");
	SetColor(3);
	gotoxy(20,8);printf("|"); SetColor(7);gotoxy(49,8);printf("SU TURNO ES:");SetColor(3);gotoxy(88,8);printf("|");
	SetColor(3);
	gotoxy(20,9);printf("|"); SetColor(11);gotoxy(54,9);printf("%s",ticket);SetColor(3);gotoxy(88,9);printf("|");
//	SetColor(3);gotoxy(20,10);printf("|");SetColor(11);gotoxy(45,10);printf("%s",)
	
	SetColor(3);
	gotoxy(20,10);printf("|");SetColor(7);gotoxy(43,10);printf("Gracias por su preferencia.");SetColor(3);gotoxy(88,10);printf("|");
	gotoxy(20,11);printf("|");SetColor(7);gotoxy(43,11);printf("En un momento lo atendemos.");SetColor(3);gotoxy(88,11);printf("|");
	gotoxy(20,12);printf("|");gotoxy(88,12);printf("|");
	gotoxy(20,13);printf("---------------------------------------------------------------------");
}


//creacion de terminal de la fila de espera
void creacion_de_espera(FAST fast_cab,SLOW slow_cab,EXECUTIVE exec_cab)
{
	int i;
	SetColor(3);
	gotoxy(47,5);
	printf("Cajas de atencion\n\n");
	SetColor(10);
	printf("C 1\t\tC 2\t\tC 3\t\tC 4\t\tC 5\t\tEJE 1\t\tEJE 2\n");SetColor(7);
	for(i=0;i<3;i++)
	{
		if(fast_cab == NULL)
		{
			printf("---\t\t");
		}
		else
		{
			printf("%s\t\t",fast_cab->turno_nombre);
			fast_cab=fast_cab->siguiente;
		}
	}
	for(i=0;i<2;i++)
	{
			if(slow_cab == NULL)
		{
			printf("---\t\t");
		}
		else
		{
			printf("%s\t\t",slow_cab->turno_nombre);
			slow_cab=slow_cab->siguiente;
		}
	}
	for(i=0;i<2;i++)
	{
			if(exec_cab == NULL)
		{
			printf("---\t\t");
		}
		else
		{
			printf("%s\t\t",exec_cab->turno_nombre);
			exec_cab=exec_cab->siguiente;
		}
	}
	printf("\n");
	SetColor(3);
	gotoxy(47,10);
	printf("Turnos Proximos\n");
	SetColor(7);
	for(i=0;i<2;i++)
	{
		if(fast_cab == NULL)
		{
			printf("");
		}
		else
		{
			printf("%s\t",fast_cab->turno_nombre);
			fast_cab=fast_cab->siguiente;
		}
	}
	for(i=0;i<2;i++)
	{
			if(slow_cab == NULL)
		{
			printf("");
		}
		else
		{
			printf("%s\t",slow_cab->turno_nombre);
			slow_cab=slow_cab->siguiente;
		}
	}
	for(i=0;i<2;i++)
	{
			if(exec_cab == NULL)
		{
			printf("");
		}
		else
		{
			printf("%s\t",exec_cab->turno_nombre);
			exec_cab=exec_cab->siguiente;
		}
	}
	printf("\n");
}

//eliminacion de ticket
void eliminacion_ticket()
{
	char Name[5];
	int i;
	SetColor(3);
	gotoxy(20,5);
	printf("Escriba el ticket a eliminar:\t");
	
	SetColor(7);
	gets(Name);
	for(i=0;i<5;i++)
		Name[i]=toupper(Name[i]);
	
	switch(toupper(Name[0]))
	{
		case 'A':
		case 'B':
		case 'C':
		case 'D':
		case 'E':
			if(CABEZA_FAST != NULL)
			{
				switch(elemi_fast(Name,&CABEZA_FAST))
				{
					case 0:
						agregar_a_lista_tiempos(CABEZA_FAST);
						free(CABEZA_FAST);
						CABEZA_FAST = NULL;
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					case 1:
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					default:
						gotoxy(25,7);
						printf("El ticket ya fue eliminado o no existe\n");
						break;
				}
			}else{
				gotoxy(45,7);
				printf("No hay fila");
			}
			break;
		case 'F':
		case 'G':
		case 'H':
			if(CABEZA_SLOW != NULL)
			{
				switch(elemi_slow(Name,&CABEZA_SLOW))
				{
					case 0:
						agregar_a_lista_tiempos(CABEZA_SLOW);
						free(CABEZA_SLOW);
						CABEZA_SLOW = NULL;
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					case 1:
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					default:
						gotoxy(25,7);
						printf("El ticket ya fue eliminado o no existe.\n");
						break;
				}
			}else{
				gotoxy(45,5);
				printf("No hay fila");
			}
			
			break;
		case 'I':
		case 'J':
			if(CABEZA_EXECUTIVE != NULL)
			{
				switch(elemi_exec(Name,&CABEZA_EXECUTIVE))
				{
					case 0:
						agregar_a_lista_tiempos(CABEZA_EXECUTIVE);
						free(CABEZA_EXECUTIVE);
						CABEZA_EXECUTIVE = NULL;
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					case 1:
						gotoxy(25,7);
						printf("Eliminado,atienda al siguiente ticket\n");
						break;
					default:
						gotoxy(25,7);
						printf("El ticket ya fue eliminado o no existe.\n");
						break;
				}
	
			}else{
				gotoxy(45,5);
				printf("No hay fila");
			}
			
			
			break;
	}
}
int elemi_fast(char name[5],FAST *og)
{
	FAST previo, eliminar;
	previo = NULL;
	eliminar = *og;
	if(eliminar->siguiente != NULL)
	{
		while(eliminar!= NULL)
		{
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo == NULL)
			{
				*og = eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo != NULL)
			{
				previo->siguiente=eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			previo = eliminar;
			eliminar= eliminar->siguiente;
		}
	}else{
		if(strcmp(eliminar->turno_nombre,name) == 0)
		{
			return 0;
		}
		return 3;
	}
	return 3;
}
int elemi_slow(char name[5],SLOW *og)
{
	SLOW previo, eliminar;
	previo = NULL;
	eliminar = *og;
	if(eliminar->siguiente != NULL)
	{
		while(eliminar!= NULL)
		{
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo == NULL)
			{
				*og = eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo != NULL)
			{
				previo->siguiente=eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			previo = eliminar;
			eliminar= eliminar->siguiente;
		}
	}else{
		if(strcmp(eliminar->turno_nombre,name) == 0)
		{
			return 0;
		}
		return 3;
	}
	return 3;
}
int elemi_exec(char name[5],EXECUTIVE *og)
{
	EXECUTIVE previo, eliminar;
	previo = NULL;
	eliminar = *og;
	if(eliminar->siguiente != NULL)
	{
		while(eliminar!= NULL)
		{
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo == NULL)
			{
				*og = eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			if(strcmp(eliminar->turno_nombre,name) == 0 && previo != NULL)
			{
				previo->siguiente=eliminar->siguiente;
				agregar_a_lista_tiempos(eliminar);
				free(eliminar);
				return 1;
			}
			previo = eliminar;
			eliminar= eliminar->siguiente;
		}
	}else{
		if(strcmp(eliminar->turno_nombre,name) == 0)
		{
			return 0;
		}
		return 3;
	}
	return 3;
}
void agregar_a_lista_tiempos(TURNO *copy_me)
{
	//creacion de tiempo
	struct tm *local;
	time_t t;
	t = time(NULL);
	FILE *archivo;
	archivo=fopen("turno.txt","a+");
	//
	CABEZA_T nuevo_t;
	nuevo_t = malloc(sizeof(TURNO_T));
	if(nuevo_t != NULL)
	{
		local=localtime(&t);
		nuevo_t->hora_c = copy_me->hora_c;
		nuevo_t->min_c = copy_me->min_c;
		nuevo_t->seg_c = copy_me->seg_c;
		nuevo_t->tipo_fila = copy_me->tipo_fila;
		nuevo_t->hora_e = local->tm_hour;
		nuevo_t->min_e = local->tm_min;
		nuevo_t->seg_e = local->tm_sec;	
		strcpy(nuevo_t->turno_nombre,copy_me->turno_nombre);
		strcpy(nuevo_t->operacion,copy_me->operacion);
		fprintf(archivo,"\nTicket: %s",nuevo_t->turno_nombre);
		fprintf(archivo,"\nOperacion: %s",nuevo_t->operacion);
		fprintf(archivo,"\nCreacion");
		fprintf(archivo,"\nHora: %d",nuevo_t->hora_c);
		fprintf(archivo,"\nMinutos: %d",nuevo_t->min_c);
		fprintf(archivo,"\nSegundos: %d",nuevo_t->seg_c);
		fprintf(archivo,"\nEliminacion");
		fprintf(archivo,"\nHora: %d",nuevo_t->hora_e);
		fprintf(archivo,"\nMinutos: %d",nuevo_t->min_e);
		fprintf(archivo,"\nSegundos: %d",nuevo_t->seg_e);
		nuevo_t->siguiente = NULL;
		nuevo_t->siguiente = CABEZA_TIEMPO;
		CABEZA_TIEMPO = nuevo_t;
	}
	fclose(archivo);
}


void imprimir_lista_tiempos(CABEZA_T actual)
{
	if (actual == NULL)
	{
		gotoxy(20,16); 
		SetColor(12);printf("Error, lista vacia");
	}
	else 
	 {
	 	gotoxy(40,5);SetColor(7);
	 	printf(" - - Tickets_eliminados - - ");
	 	gotoxy(40,7);SetColor(3);printf("Creado");
	 	gotoxy(54,7);SetColor(3);printf("Eliminado");
		while (actual != NULL) 
		  {
		  	SetColor(7);
			printf("\n\t\t\t\t%s | %d: %d: %d|   | %d: %d: %d|--> ",actual -> turno_nombre,actual->hora_c,actual->min_c,actual->seg_c,actual->hora_e,actual->min_e,actual->seg_e);
			actual = actual -> siguiente;
		  } 
		printf("NULL \n\n");
	 }
}
void SetColor(int ForgC)
 {
     WORD wColor;

      HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
      CONSOLE_SCREEN_BUFFER_INFO csbi;

                       
     if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
     {
                 
          wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
          SetConsoleTextAttribute(hStdOut, wColor);
     }
     return;
 }
 
 


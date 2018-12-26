

#include <graphics.h>
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

void iniciar_graficos();
void bloques_memoria();
int total_memoria=0,mayor;

void imprime();
void primer_ajuste();
void peor_ajuste();
void mejor_ajuste();
void principal();

struct datos{
	int memory,proceso,total_memoria,id;
      };
struct datos memoria[9];
struct datos procesos_liberados[9],aux3[1];

char msg [15];
int op,s=0,j=0,l;
int posicion[10];
int memo_proceso[10];
int memo_max[6];
int menor[6];
int liberar_proceso[10];
//int procesos_liberados[10];
int aux2[20],aux[20];


void main(){
	iniciar_graficos();
	principal();


}

void principal()
{

int i=0,cantidad,j=0,insertar=0,op=0,insertarmemo=0;

	printf("inserta procesos\n");
	rectangle(249,0,351,641);
	do
	{
		setfillstyle(1,random(14)+1);
		scanf("%d",&aux[i]);
		memo_max[i]=(memoria[i].memory =aux[i]);
		memoria[i].id=i;
		bar(250,total_memoria,350,memoria[i].memory+total_memoria);
		sprintf(msg,"%d kb",memoria[i].memory);outtextxy (355, total_memoria, msg);
		sprintf(msg,"%d ",total_memoria);outtextxy (230, total_memoria, msg);
		total_memoria+=aux[i];
		aux2[i]=total_memoria;

		i++;

	}while(total_memoria<=460);

	gotoxy(10,215);printf("cantidad de procesos a liberar\n");
	scanf("%d",&cantidad);

	for(j;j<cantidad;j++)
	{
		printf("num de proceso\n");
		scanf("%d",&liberar_proceso[j]);
		setfillstyle(1,0);
		bar(250,aux2[liberar_proceso[j]]-memo_max[liberar_proceso[j]],350,aux2[liberar_proceso[j]]);
		procesos_liberados[j].memory=memo_max[liberar_proceso[j]];
		procesos_liberados[j].id=memoria[liberar_proceso[j]].id;


	}

		printf("a.- peor ajuste \nb.- mejor ajuste \n c.- primer ajuste\n");


	do{
		op=getche();

		switch(op)

		{
		   case 'a':
			{
			printf("tamanio proceso: ");
			scanf("%d",&memo_proceso[s]);
			peor_ajuste();
			setfillstyle(1,random(14)+1);
			bar(250,aux2[aux3[0].id-1],350,aux2[aux3[0].id-1]+memo_proceso[insertarmemo]);
			aux2[aux3[0].id-1]=aux2[aux3[0].id-1]+memo_proceso[insertarmemo];
			s++;
			insertarmemo++;
			//j=0;
			getch();
			break;
			}
			 case 'b':
				{
				printf("tamanio proceso: ");
				scanf("%d",&memo_proceso[s]);
				mejor_ajuste();
				setfillstyle(1,random(14)+1);

				bar(250,aux2[aux3[0].id-1],350,aux2[aux3[0].id-1]+memo_proceso[insertarmemo]);
				aux2[aux3[0].id-1]=aux2[aux3[0].id-1]+memo_proceso[insertarmemo];
				s++;
				insertarmemo++;
				//j=0;
				getch();
				break;
				}

			 case 'c':
				{
				printf("tamanio proceso: ");
				scanf("%d",&memo_proceso[s]);
				primer_ajuste();
				setfillstyle(1,random(14)+1);
				bar(250,aux2[aux3[0].id-1],350,aux2[aux3[0].id-1]+memo_proceso[insertarmemo]);
				aux2[aux3[0].id-1]=aux2[aux3[0].id-1]+memo_proceso[insertarmemo];
				s++;
				insertarmemo++;
				//j=0;
				getch();
				break;
				}

		   }
		insertar++;
	  }while(op!='s');




}
void peor_ajuste(){

	mayor =procesos_liberados[0].memory;
	for(int i=0; i<6; i++){

	       if (mayor<=procesos_liberados[i].memory){
		aux3[0].memory=procesos_liberados[i].memory;
		aux3[0].id=procesos_liberados[i].id;
			mayor=procesos_liberados[i].memory;
			posicion[j]=i+1;
			j++;
	       }


	}

		for(int p=0;p<j;p++){
			l = posicion[p];
		}
	 if(procesos_liberados[l-1].memory>=memo_proceso[s]){
		procesos_liberados[l-1].memory = procesos_liberados[l-1].memory - memo_proceso[s];
	 }
	  else{
	       outtextxy(250,250,"<<Espacio>>");
	       outtextxy(250,300,"<<Insuficiente>>");
	  }
}

void mejor_ajuste(){

	for(int i=0; i<6; i++){
	       if (procesos_liberados[i].memory>=memo_proceso[s])
	       {

			menor[i]=procesos_liberados[i].memory-memo_proceso[s];

	       }
	       else{
			menor[i]=100;
	       }

	}
	int min;
	min = menor[0];
	for(int a=0; a<6; a++){

	       if (min>=menor[a]){
			min= menor[a];
			posicion[j]=a+1;
			j++;
	       }

	}
	   for(int p=0;p<j;p++){
			l = posicion[p];
		}
	 if(procesos_liberados[l-1].memory>=memo_proceso[s]);{
		procesos_liberados[l-1].memory=procesos_liberados[l-1].memory-memo_proceso[s];
		aux3[0].memory=procesos_liberados[l-1].memory;
		aux3[0].id=procesos_liberados[l-1].id;
	 }
}
void primer_ajuste(){
	for(int i=0;i<6;i++){
		      if(procesos_liberados[i].memory>=memo_proceso[s]){
			procesos_liberados[i].memory=procesos_liberados[i].memory - memo_proceso[s];
			aux3[0].memory=procesos_liberados[i].memory;
			aux3[0].id=procesos_liberados[i].id;
			  break;
		      }

	  }

}




void iniciar_graficos(){
	int controlador = DETECT, modo;
	initgraph(&controlador, &modo, "d:\\tc\\bgi");
}

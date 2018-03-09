
#include<all_func.h>
#include<new_func.h>
#define NULL 0

void main (void)
{
colores16();
carg();
intro();
setfillstyle(1,RED);
bar(440,420,510,440);/*boton aceptar*/
setcolor(BLACK);
rectangle(440,420,510,440);/*boton aceptar*/
/*sombra boton entrar*/
setcolor(WHITE);
line(441,421,509,421);
line(441,421,441,439);
line(442,421,442,439);
setcolor(DARKGRAY);
line(509,421,509,439);
line(508,421,508,439);
line(441,439,509,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(452,428,"Aceptar");
mver();
do{
if(mclick()==1 && minlimit(1,440,420,510,440))
		{

mocultar();
/*efecto undimiento del boton*/
setfillstyle(1,LIGHTRED);
bar(440,420,510,440);
rectangle(440,420,510,440);
setcolor(DARKGRAY);
line(441,421,509,421);
line(441,421,441,439);
line(442,421,442,439);
setcolor(WHITE);
line(509,421,509,439);
line(508,421,508,439);
line(441,439,509,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(452,428,"Aceptar");
delay(30);
cleardevice();
setfillstyle(1,YELLOW);
bar(0,0,640,479);
setcolor(BLACK);
rectangle(12,100,625,470);
setcolor(BLACK);
rectangle(14,102,623,468);

setfillstyle(1,BLUE);
bar(60,2,80,70);bar(85,2,160,22);bar(85,20,110,45);bar(81,50,135,70);bar(115,27,135,50);bar(140,23,160,70);
bar(160,50,185,70);bar(165,2,185,22);bar(165,25,185,50);

setcolor(BLUE);
settextstyle(1,0,2);outtextxy(197,6,"UNIVERSIDAD NACIONAL DE INGENIERIA");
settextstyle(1,0,1);outtextxy(190,25,"FACULTAD DE ELECTROTECNIA Y COMPUTACION");
outtextxy(350,42,"F.E.C");
setcolor(CYAN);
outtextxy(170,110,"MAPA VIRTUAL DE NICARAGUA");
line(160,130,450,130);
line(170,133,440,133);
setcolor(0);
mapachi();
boton();
do{
if(mclick()==1 && minlimit(1,440,420,510,440))
		{

mocultar();
/*efecto undimiento del boton*/
setfillstyle(1,LIGHTGRAY);
bar(440,420,510,440);
rectangle(440,420,510,440);
setcolor(DARKGRAY);
line(441,421,509,421);
line(441,421,441,439);
line(442,421,442,439);
setcolor(WHITE);
line(509,421,509,439);
line(508,421,508,439);
line(441,439,509,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(452,428,"ENTRAR");
delay(30);

cleardevice();


mocultar();
depar();
do{
detect();mocultar();
}while((!kbhit()));
  }

	else	if(mclick()==1 && minlimit(1,520,420,590,440))
			{/*sombra boton salir*/
			mocultar();
setcolor(DARKGRAY);
line(521,421,589,421);
line(521,421,521,439);
line(522,421,522,439);
setcolor(WHITE);
line(589,421,589,439);
line(588,421,588,439);
line(521,439,589,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(532,428,"SALIR");

delay(30);
cleardevice();
fin();
sleep(5);
			exit(NULL);
			}

	}while((!kbhit()));

}}while((!kbhit()));

getch();

closegraph();	}



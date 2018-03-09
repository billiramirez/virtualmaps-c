
#include<MOUSE.H>
#include<string.h>
#include<stdio.h>
#include<alloc.h>
#include<conio.h>
#include<dos.h>
#include<graphics.h>
#define relleno SOLID_FILL
void fin(void);
void exit( int);
void boton (void);
void botons (void);
void botony (void);
void botonys (void);
void puntos (void);
void mapachi (void);
void detect (void);
void depar (void);
void ret (void);
void intro (void);
void carg (void);
void raan (void);
void raas (void);
void flecha (void);
void rio_s (void);
void click_help(void);
void click_back(void);
void segunda_pagina (void);
void paralelos (void);
void back_help (void);
void chon(void);
void boaco (void);
void mata(void);
void jino(void);
void segovia(void);
void madriz(void);
void esteli(void);
void chinan(void);
void leon(void);
void carazo(void);
void granada(void);
void masaya2 (void);
void Managua2 (void);
void rivas (void);
void selecti (void);
void colores16 (void);
void d256colores (void);

/*****select imag**************/
void click_raan (void);
void click_raas (void);
void click_rio (void);
void click_cho (void);
void click_bo (void);
void click_ma (void);
void click_ji (void);
void click_se (void);
void click_MAD (void);
void click_es (void);
void click_chi (void);
void click_le (void);
void click_mana (void);
void click_car (void);
void click_gra (void);
void click_mas (void);
void click_riv (void);
/***********************IMAGENES 256 COLORES**********************/
int huge DetectVGA256()
{
  return 2;
}


FILE * BMP;
int BIT_PIXEL, PIXEL_BIT,CUERPO, PALETA, PALETA_TAM, TAM_X, TAM_Y;
char alvaro[2]="1";

typedef struct
{
  unsigned char b, g, r, a;
} Color;

int getcol (void);
int ShowBMP (char *fname);

void d256colores (void)
{
int driver = DETECT, mode;
installuserdriver("Svga256",DetectVGA256);
initgraph (&driver,&mode,"C:\\tc20\\bin");
}


int ShowBMP (char *fname)
{
  int k;
  Color col;
  int x, y;

  BMP = fopen (fname, "rb");
  if (BMP == NULL)
    return 1;

  fseek (BMP, 10, SEEK_SET);
  fread (&CUERPO, sizeof (CUERPO), 1, BMP);
  fseek (BMP, 18, SEEK_SET);
  fread (&TAM_X, sizeof (TAM_X), 1, BMP);
  fseek (BMP, 22, SEEK_SET);
  fread (&TAM_Y, sizeof (TAM_Y), 1, BMP);
  fseek (BMP, 28, SEEK_SET);
  fread (&BIT_PIXEL, sizeof (BIT_PIXEL), 1, BMP);
  PIXEL_BIT = 8 / BIT_PIXEL;
  PALETA_TAM = 1 << BIT_PIXEL;
  PALETA = CUERPO - 4 * PALETA_TAM;
  fseek (BMP, PALETA, SEEK_SET);
  for (k = 0; k < PALETA_TAM; k++)
       {
      fread (&col, sizeof (col), 1, BMP);
      setrgbpalette (k, (col.r) >> 2, (col.g) >> 2, (col.b) >> 2);
    }
  for(y=(TAM_Y - 1);y>=0;y--)
      for (x = 0; x < TAM_X; x++)
        putpixel (x, y, getcol ());
  return 0;
}

int getcol (void)
{
  static int x = 0;
  static int n = 0;
  static int col[4];
  unsigned char b;
  if (x >= TAM_X)
    {
      x = 0;
      while (n % 4)
	{
	  fread (&b, sizeof (b), 1, BMP);
	  n++;
	}
      n = 0;
    }
  if (x % PIXEL_BIT == 0)
    {
      int k = PIXEL_BIT;
      int mask = (1 << BIT_PIXEL) - 1;
      fread (&b, sizeof (b), 1, BMP);
      n++;
      while (k--)
	{
	  col[k] = b & mask;
	  b >>= BIT_PIXEL;
	}
    }

 return col[x++ % PIXEL_BIT];

  }







/*****************************..................**************/

void colores16 (void)
{

	int adap=VGA,modo=VGAHI;
	initgraph(&adap,&modo,"C:\\TC20\\BIN");

}




void boton (void){
/*******__________________******/
setfillstyle(1,LIGHTGRAY);
bar(440,420,510,440);/*boton entrar*/
bar(520,420,590,440); /*boton salir*/
setcolor(BLACK);
rectangle(440,420,510,440);/*boton entrar*/
rectangle(520,420,590,440);/*boton salir*/
/*sombra boton entrar*/
setcolor(WHITE);
line(441,421,509,421);
line(441,421,441,439);
line(442,421,442,439);
setcolor(DARKGRAY);
line(509,421,509,439);
line(508,421,508,439);
line(441,439,509,439);
/*sombra boton salir*/
setcolor(WHITE);
line(521,421,589,421);
line(521,421,521,439);
line(522,421,522,439);
setcolor(DARKGRAY);
line(589,421,589,439);
line(588,421,588,439);
line(521,439,589,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(452,428,"ENTRAR");
outtextxy(532,428,"SALIR");
mver();
/*******_________********/
}
void botony (void) {
setfillstyle(1,LIGHTGRAY);
bar(520,160,590,180);
setcolor(BLACK);
rectangle(520,160,590,180);
setcolor(BLUE);
outtextxy(538,168,"AYUDA");
setcolor(WHITE);
line(521,161,589,161);
line(521,161,521,179);
line(522,161,522,179);
setcolor(DARKGRAY);
line(521,179,589,179);
line(589,161,589,179);
line(588,161,588,179);}
/**********cuerpo boton ayuda**************/

void botonys (void) {
int i;
sound(300);delay(300);nosound();
mocultar();
setfillstyle(1,LIGHTGRAY);
bar(520,160,590,180);
setcolor(BLACK);
rectangle(520,160,590,180);
setcolor(BLUE);
settextstyle(0,0,0);
outtextxy(538,168,"AYUDA");
setcolor(DARKGRAY);
line(521,161,589,161);
line(521,161,521,179);
line(522,161,522,179);
setcolor(WHITE);
line(521,179,589,179);
line(589,161,589,179);
line(588,161,588,179);mver();
for(i=0;i<=200;i++){
mocultar();
setfillstyle(1,BLUE);
bar(490,200+i,630,200+i);delay(5);mver();}
setcolor(0);
mocultar();
rectangle(490,200,630,400);
setcolor(WHITE);
outtextxy(492,202,"*Estimado usuario");
outtextxy(492,212,"debe hacer uso ");
outtextxy(492,222,"del mouse para");
outtextxy(492,232,"seleccionar el");
outtextxy(492,242,"departamento que");
outtextxy(492,252,"le interesa,");
outtextxy(492,262,"regresar ");
setcolor(YELLOW);
outtextxy(492,262,"         ('<-') ");
setcolor(WHITE);
outtextxy(492,262,"                o");
outtextxy(492,272,"salir con los");
outtextxy(492,282,"botones");
outtextxy(492,292,"correspondientes");
outtextxy(492,330,"presione x para");
outtextxy(492,340,"salir de ayuda");
setfillstyle(1,RED);
bar(610,375,625,390);/*salir ayuda*/
setcolor(LIGHTRED);
rectangle(610,375,625,390);
setcolor(WHITE);
outtextxy(615,380,"X");
mver();
}
void ret (void){
setfillstyle(1,LIGHTGRAY);
bar(480,420,510,440);
setcolor(BLACK);
rectangle(480,420,510,440);
setcolor(BLUE);
outtextxy(490,427,"<-");
setcolor(WHITE);
line(481,421,481,439);
line(482,421,482,439);
line(481,421,509,421);
setcolor(DARKGRAY);
line(509,421,509,439);
line(508,421,508,439);
line(481,439,509,439);
}
void botons (void) {
mver();

if(mclick()==1 && minlimit(1,520,420,590,440))
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
mver();
delay(30);
cleardevice();
mocultar();
fin();
sleep(5);
			exit(NULL);
			}
}
void mapachi (void){
int mapap[240] = {175, 252,182, 257,185, 264,190, 267,195, 274,203, 281,213, 287,218, 293,225, 304,231, 312
,242, 323,256, 335,263, 345,267, 349,269, 347,273, 343,277, 346,285, 349,293, 350,299, 352,305, 355,307, 357,310, 359
,314, 355,318, 351,323, 353,327, 355,336, 355,342, 359,347, 362,351, 365,355, 365,360, 366,370, 362,368, 358
,360, 343,359, 332,367, 324,372, 319,368, 309,366, 310,366, 301,366, 293,371, 288,373, 284,369, 285,369, 278,370, 272,374, 276,373, 280
,375, 280,379, 280,377, 273,378, 263,378, 249,377, 235,379, 214,382, 199,393, 186,389, 185,387, 182,390, 179,392, 181
,393, 182,393, 178,390, 172,392, 169,390, 158,386, 157,384, 153,389, 154,391, 155,393, 150,395, 145,390, 147,385, 148,380, 151
,377, 154,374, 156,371, 159,351, 161,337, 168,325, 168,319, 156,312, 161,307, 166,302, 168,298, 178,298, 182,292, 187
,284, 191,277, 196,272, 200,270, 205,263, 200,258, 193,248, 200,241, 210,230, 209,219, 210,219, 218,220, 224,222, 231
,219, 235,214, 233,211, 236,211, 242,209, 246,204, 246,197, 248,193, 248,195, 251,191, 251,182, 245,177, 241
,177, 246,175, 249,173, 249,175, 252,175, 252
};
setfillstyle(relleno,GREEN);
fillpoly(120,mapap);drawpoly(120,mapap);
}
void depar (void){



int raan[356] = {
256, 43
,256, 40,254, 37,257, 33,261, 28,266, 24,269, 21,275, 21,278, 21,281, 24,284, 29,286, 31,288, 35,288, 35,297,
35,303, 39,305, 39,309, 40,312, 40,316, 37,319, 34,321, 32,325, 34,327, 36,329, 34,329, 30,330, 27,331, 27
,334, 27,335, 29,336, 31,338, 31,340, 29,342, 29,345, 30,344, 25,346, 23,353, 28,355, 28,358, 27,361, 24,363, 23
,365, 23,367, 23,370, 23,371, 21,373, 20,376, 20,382, 17,388, 14,390, 14,394, 12,397, 10,398, 7,400, 5,402, 2
,403, 1,405, 2,408, 3,409, 2,411, 0,415, 1,419, 3,424, 4,432, 4,437, 3,432, 8,429, 13,425, 20,421, 20,421, 16
,419, 12,415, 15,412, 19,413, 21,415, 27,416, 27,418, 25,420, 23,421, 21,423, 21,423, 25,423, 33,426, 42
,430, 54,434, 64,432, 75,427, 84,422, 91,416, 98,413, 103,410, 108,407, 120,404, 131,399, 156,399, 184,404, 203
,404, 210,397, 210,394, 208,387, 208,385, 206,380, 207,378, 203,372, 200,371, 193,368, 188,362, 183,365, 179
,361, 177,359, 177,357, 179,353, 179,350, 179,343, 181,345, 183,347, 184,347, 186,340, 188,329, 193,321, 201
,319, 202,318, 199,313, 197,304, 195,299, 197,295, 196,288, 196,284, 199,284, 204,282, 206,275, 207,272, 208
,270, 210,267, 212,262, 216,258, 222,254, 220,252, 220,248, 221,247, 222,245, 220,243, 219,241, 217,240, 214
,238, 211,238, 207,238, 202,237, 195,236, 189,236, 187,234, 186,225, 182,222, 182,220, 178,216, 174,213, 170
,209, 168,216, 162,222, 156,227, 150,235, 138,246, 123,257, 116,262, 114,268, 114,274, 111,275, 107,274, 97
,272, 86,268, 82,264, 79,261, 79,259, 76,259, 70,259, 52,257, 44,256, 43

};
int raas[230] = {
256, 223,263, 216,270, 212,276, 207,280, 207,285, 203,285, 197,289, 194,296, 194,297, 197,303, 195,310, 195
,316, 200,320, 202,325, 198,331, 192,338, 188,346, 186,344, 183,347, 179,353, 179,357, 176,360, 177,364, 181
,362, 183,364, 183,370, 191,369, 194,374, 202,376, 201,379, 203,384, 207,388, 210,394, 209,397, 209,403, 210
,404, 217,403, 225,402, 234,403, 243,408, 255,406, 260,399, 261,393, 261,392, 255,392, 245,393, 241,396, 238
,398, 232,398, 222,394, 219,390, 222,394, 226,395, 232,393, 237,388, 243,381, 243,377, 246,378, 249,382, 251
,384, 252,384, 256,384, 263,386, 263,390, 260,391, 261,394, 262,392, 269,389, 277,389, 289,389, 297,386, 300
,383, 295,381, 298,377, 305,374, 312,379, 316,382, 314,385, 312,387, 313,389, 322,389, 331,390, 339,384, 342
,382, 345,379, 354,375, 356,371, 361,371, 371,372, 376,374, 384,377, 389,378, 393,373, 393,368, 389,363, 385
,360, 386,357, 389,352, 387,347, 383,336, 373,325, 359,312, 343,304, 332,295, 321,289, 314,289, 305,275, 283
,267, 269,264, 263,262, 257,258, 250,258, 226,256, 224,256, 223

};

int rio[160] = {
250, 334,254, 331,263, 326,265, 322,268, 318,273, 316,278, 312,282, 312,289, 312,294, 321,301, 329,312, 343
,333, 368,344, 384,350, 385,355, 387,358, 387,361, 387,366, 385,368, 389,371, 393,379, 393,384, 400,389, 403
,391, 402,392, 408,392, 412,392, 416,389, 419,384, 419,377, 422,371, 426,363, 425,357, 419,349, 422,345, 420
,337, 417,336, 416,337, 412,336, 409,328, 405,325, 403,323, 400,319, 402,312, 402,310, 396,302, 393,296, 390
,291, 391,286, 392,285, 396,272, 402,266, 402,254, 397,247, 396,233, 391,236, 385,251, 389,256, 389,259, 389
,265, 391,272, 394,275, 392,282, 391,284, 388,281, 385,282, 378,282, 373,280, 369,276, 366,274, 366,271, 362
,271, 356,267, 354,267, 354,265, 351,262, 347,257, 341,253, 339,250, 334
};

int rivas[110] = {
232, 389,232, 384,227, 382,222, 381,218, 380,215, 378,212, 377,206, 372,199, 372,198, 370,189, 363,187, 360
,184, 355,183, 349,181, 345,181, 343,178, 340,178, 338,179, 336,177, 333,174, 330,171, 329,169, 329,165, 330
,162, 331,159, 335,158, 335,156, 333,153, 335,149, 340,144, 346,149, 349,153, 354,157, 358,160, 361,163, 364
,166, 366,169, 366,172, 371,176, 375,180, 377,181, 379,181, 386,183, 387,186, 387,190, 389,192, 389,196, 386
,197, 381,200, 377,205, 377,214, 384,216, 385,220, 386,232, 389
};

int chontales[96] = {
289, 311,289, 306,277, 287,270, 275,266, 267,264, 263,260, 262,257, 264,253, 266,250, 268,246, 268,242, 266
,227, 267,217, 266,207, 266,202, 269,201, 274,199, 287,196, 292,196, 293,197, 294,200, 294,205, 294,208, 297
,212, 302,216, 308,217, 311,220, 311,224, 311,231, 314,233, 318,234, 321,237, 321,244, 325,247, 329,249, 331
,250, 334,250, 335,252, 332,262, 327,264, 323,267, 320,273, 318,276, 313,279, 311,285, 312,289, 313,289, 311
};

int boaco[116] = {
195, 291,192, 290,188, 289,183, 287,183, 283,183, 277,178, 272,175, 269,175, 266,175, 261,172, 255,170, 252
,170, 247,170, 244,176, 241,184, 237,191, 236,195, 236,203, 233,210, 230,215, 230,219, 227,223, 226,224, 228
,230, 229,233, 234,236, 236,242, 236,246, 232,246, 228,248, 225,248, 220,251, 221,255, 221,257, 222,257, 228
,258, 240,259, 250,261, 258,265, 258,263, 263,259, 262,255, 264,252, 266,249, 268,243, 266,237, 266,231, 266
,225, 266,218, 267,210, 265,207, 265,203, 270,202, 276,199, 287,197, 292,193, 291,195, 291
};

int matagalpa[106] = {
134, 236,151, 240,163, 244,169, 244,174, 243,180, 239,184, 236,196, 235,200, 233,207, 231,217, 229,219, 226
,221, 226,223, 227,227, 227,236, 234,238, 235,245, 232,245, 228,247, 224,245, 219,240, 219,239, 216,237, 212
,237, 208,237, 203,239, 200,236, 195,236, 190,235, 187,233, 184,229, 184,223, 181,218, 175,216, 172,212, 168
,209, 168,205, 171,198, 175,191, 182,184, 188,179, 189,176, 191,170, 199,168, 203,158, 202,150, 203,146, 204
,142, 205,137, 209,137, 211,133, 235,134, 236
};

int jinotega[172] = {
149, 200,146, 187,145, 182,140, 169,138, 166,142, 161,144, 158,148, 157,152, 157,155, 156,156, 152,160, 150
,164, 148,167, 149,170, 153,172, 154,174, 153,177, 151,180, 149,180, 145,181, 138,184, 129,186, 123,188, 118
,191, 117,188, 114,188, 109,190, 106,194, 103,200, 101,206, 99,209, 93,213, 91,216, 88,218, 86,223, 82,225, 77
,228, 76,233, 72,240, 72,244, 69,242, 65,239, 62,244, 54,245, 51,245, 47,247, 43,251, 47,254, 48,256, 46
,259, 46,259, 70,257, 73,258, 79,260, 79,265, 79,268, 81,272, 89,272, 94,274, 108,270, 113,264, 113,255, 114
,246, 126,239, 134,236, 138,231, 144,226, 151,221, 158,214, 165,210, 169,206, 169,202, 173,195, 177,191, 182
,189, 184,185, 186,181, 188,176, 191,174, 197,170, 200,167, 203,158, 201,154, 203,152, 203,149, 200
};

int sego[122] = {
95, 152,93, 146,93, 138,89, 135,91, 128,98, 124,102, 125,106, 125,110, 124,114, 122,115, 124,118, 126,119, 126
,121, 124,126, 127,128, 127,133, 124,136, 121,140, 116,142, 113,144, 106,146, 105,152, 103,156, 100,158, 95
,162, 95,163, 98,162, 100,168, 106,173, 111,178, 112,182, 117,186, 117,188, 117,184, 127,182, 133,182, 138
,182, 142,182, 147,179, 150,174, 152,173, 154,171, 151,161, 148,159, 150,158, 148,158, 143,155, 139,147, 141
,133, 140,131, 139,126, 138,123, 136,116, 139,112, 141,109, 144,106, 146,101, 150,98, 154,95, 155,95, 152
};

int madriz[94] = {
97, 178,100, 175,102, 173,102, 170,105, 166,110, 160,111, 156,116, 155,119, 156,128, 162,132, 164
,134, 164,138, 166,141, 163,143, 161,146, 157,149, 156,153, 156,158, 153,158, 146,157, 142,155, 139
,149, 140,144, 140,141, 140,135, 140,129, 139,126, 137,124, 137,119, 137,112, 143,110, 144,106, 147
,102, 150,100, 152,98, 154,97, 155,95, 155,94, 159,93, 162,98, 166,98, 169,97, 173,93, 174,93, 175
,96, 178,97, 178
};

int esteli[70] = {
102, 192,106, 190,112, 192,119, 193,125, 197,130, 202,133, 208,136, 209,138, 207,143, 205,147, 204
,151, 200,148, 192,145, 185,143, 181,140, 175,138, 171,139, 167,137, 165,135, 165,133, 164,125, 160
,122, 159,120, 158,116, 155,113, 157,110, 159,105, 163,104, 169,99, 176,96, 179,96, 179,100, 183
,101, 191,102, 192
};

int chinandga[150] = {
96, 179,94, 176,91, 174,88, 172,84, 172,80, 173,76, 177,75, 181,75, 184,76, 189,74, 192,71, 194,71, 197
,67, 201,64, 201,61, 200,55, 200,47, 200,40, 201,35, 204,32, 205,32, 207,30, 207,25, 206,22, 199,18, 196
,13, 193,12, 192,11, 194,11, 196,7, 200,4, 203,0, 206,3, 210,9, 213,12, 216,16, 220,19, 220,24, 221,24, 226
,25, 231,29, 231,32, 233,34, 237,37, 238,40, 241,41, 243,43, 246,46, 246,48, 246,49, 250,51, 252,53, 252
,64, 249,68, 246,68, 243,76, 237,76, 231,77, 227,77, 220,80, 217,85, 217,87, 216,90, 215,94, 217,97, 217
,96, 214,97, 209,99, 200,101, 196,100, 187,100, 185,99, 182,95, 179,96, 179
};

int leon[170] = {
102, 192,105, 190,109, 191,111, 191,114, 191,118, 192,121, 196,127, 196,127, 199,134, 209,136, 211,138, 212
,136, 220,135, 226,135, 231,135, 235,132, 238,130, 240,129, 243,129, 248,130, 251,127, 251,124, 254,121, 255
,118, 258,118, 260,115, 259,111, 259,108, 258,108, 255,108, 257,107, 259,107, 262,105, 264,109, 266,109, 269
,111, 270,112, 274,116, 275,118, 276,119, 278,119, 280,116, 283,114, 286,110, 289,102, 296,100, 299,98, 301
,97, 297,93, 292,91, 289,91, 286,89, 282,89, 279,86, 277,76, 271,73, 269,68, 267,66, 264,61, 262,57, 258
,54, 256,51, 253,50, 251,53, 250,57, 249,62, 247,66, 247,69, 243,71, 240,75, 236,76, 230,77, 224,78, 220
,80, 217,86, 217,88, 215,90, 217,92, 217,95, 218,97, 215,97, 213,98, 203,102, 195,102, 192
};

int managua[162] = {
134, 235,156, 243,159, 243,167, 244,169, 245,172, 255,174, 257,176, 264,176, 267,170, 273,165, 278,163, 282
,158, 284,154, 285,148, 288,145, 290,143, 295,140, 298,136, 303,132, 303,129, 306,127, 311,124, 313,115, 317
,114, 320,110, 314,107, 311,105, 308,102, 305,101, 301,100, 300,100, 300,103, 297,104, 292,109, 288,114, 284
,118, 280,117, 278,114, 273,111, 271,113, 268,115, 271,118, 272,120, 273,122, 274,124, 274,125, 273,128, 271
,130, 269,132, 270,135, 273,136, 278,134, 280,134, 282,138, 282,140, 282,144, 282,147, 281,151, 281,155, 276
,155, 272,155, 269,155, 266,152, 265,149, 267,146, 270,145, 268,144, 267,144, 265,142, 261,139, 258,138, 257
,137, 252,134, 249,131, 250,131, 251,129, 248,127, 246,130, 242,131, 238,134, 235
};

int carazo[74] = {
144, 345,148, 341,150, 338,152, 335,157, 333,156, 329,155, 324,155, 320,155, 313,157, 310,154, 307,150, 303
,147, 304,145, 303,142, 302,138, 301,135, 303,128, 308,127, 313,123, 314,118, 315,114, 318,114, 319,116, 323
,119, 325,122, 330,124, 329,128, 332,129, 337,130, 340,132, 339,134, 339,137, 339,139, 343,143, 343,143, 346
,144, 345
};

int masaya[42] = {
138, 300,140, 296,143, 291,146, 289,154, 286,156, 284,159, 284,161, 282,164, 281,168, 285,167, 287,165, 294
,162, 302,159, 307,157, 310,156, 308,153, 307,147, 305,142, 303,137, 301,138, 300
};

int granada[90] = {
155, 335,159, 334,161, 331,162, 331,165, 330,169, 330,172, 328,172, 325,172, 322,175, 321,174, 318,174, 315
,174, 309,172, 308,171, 306,171, 304,172, 296,173, 294,173, 291,176, 290,178, 290,180, 290,183, 288,185, 287
,181, 283,181, 280,183, 276,177, 271,175, 268,169, 272,168, 275,165, 278,164, 280,165, 284,167, 287,165, 293
,161, 303,158, 307,158, 311,156, 314,156, 320,156, 328,154, 334,155, 336,155, 335
};

int ometepe[56] = {
199, 351,195, 350,192, 349,192, 345,195, 342,200, 340,202, 339,205, 339,207, 340,205, 342,205, 344,207, 346
,207, 348,209, 349,213, 348,215, 349,217, 350,218, 357,215, 359,212, 360,207, 357,207, 355,206, 351,203, 351
,203, 349,200, 350,200, 351,199, 351
};

mlimit(1,0,0,640,480);
setfillstyle(1,LIGHTBLUE);
bar(0,0,450,430);
setfillstyle(1,DARKGRAY);
bar(450,0,640,480);
setfillstyle(1,BLACK);
bar(0,430,450,480);
setcolor(WHITE);
rectangle(0,0,450,430);
rectangle(450,0,640,480);
rectangle(1,430,450,480);

setcolor(0);

setfillstyle(relleno,LIGHTRED);
fillpoly(75,chinandga);
drawpoly(75,chinandga);
setfillstyle(relleno,BLUE);
fillpoly(85,leon);
drawpoly(85,leon);
setfillstyle(relleno,LIGHTGREEN);
fillpoly(81,managua);
drawpoly(81,managua);
setfillstyle(relleno,YELLOW);
fillpoly(37,carazo);
drawpoly(37,carazo);
setfillstyle(relleno,LIGHTRED);
fillpoly(21,masaya);
drawpoly(21,masaya);
setfillstyle(relleno,BLUE);
fillpoly(45,granada);
drawpoly(45,granada);
setfillstyle(relleno,LIGHTMAGENTA);
fillpoly(55,rivas);
drawpoly(55,rivas);
setfillstyle(relleno,GREEN);
fillpoly(61,sego);
drawpoly(61,sego);
setfillstyle(relleno,CYAN);
fillpoly(47,madriz);
drawpoly(47,madriz);
setfillstyle(relleno,DARKGRAY);
fillpoly(35,esteli);
drawpoly(35,esteli);
setfillstyle(relleno,BLUE);
fillpoly(86,jinotega);
drawpoly(86,jinotega);
setfillstyle(relleno,MAGENTA);
fillpoly(53,matagalpa);
drawpoly(53,matagalpa);
setfillstyle(relleno,RED);
fillpoly(58,boaco);
drawpoly(58,boaco);
setfillstyle(relleno,BROWN);
fillpoly(48,chontales);
drawpoly(48,chontales);
setfillstyle(relleno,LIGHTCYAN);
fillpoly(80,rio);
drawpoly(80,rio);
setfillstyle(relleno,YELLOW);
fillpoly(178,raan);
drawpoly(178,raan);
setfillstyle(relleno,GREEN);
fillpoly(115,raas);
drawpoly(115,raas);
setfillstyle(relleno,LIGHTMAGENTA);
fillpoly(28,ometepe);
drawpoly(28,ometepe);
setfillstyle(1,LIGHTGRAY);
bar(520,420,590,440); /*boton salir*/
setcolor(BLACK);
rectangle(520,420,590,440);/*boton salir*/
/*sombra boton salir*/
setcolor(WHITE);
line(521,421,589,421);
line(521,421,521,439);
line(522,421,522,439);
setcolor(DARKGRAY);
line(589,421,589,439);
line(588,421,588,439);
line(521,439,589,439);
setcolor(BLUE);
settextstyle(0,0,1);
outtextxy(532,428,"SALIR");
/*boton ayuda*/
botony();
ret();
puntos();
paralelos();
flecha();


}
void paralelos (void){
setcolor(WHITE);
line(0,100,450,100);
line(0,200,450,200);
line(0,300,450,300);
line(0,400,450,400);
line(100,0,100,430);
line(200,0,200,430);
line(300,0,300,430);
line(400,0,400,430);}
void puntos (void)
{


setcolor(BLACK);
ellipse(326,124,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK);
fillellipse(326,124,2,2);/* RAAN */


ellipse(324,254,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* RAAS*/
fillellipse(324,254,2,2);

ellipse(300,360,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK);  /* RIO SAN JUAN*/
fillellipse(300,360,2,2);

ellipse(240,290,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* CHONTALES*/
fillellipse(240,290,2,2);

ellipse(220,250,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* BOACO*/
fillellipse(220,250,2,2);

ellipse(195,205,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* MATAGALPA*/
fillellipse(195,205,2,2);

ellipse(205,140,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* JINOTEGA */
fillellipse(205,140,2,2);

ellipse(155,120,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* NUEVA SEGOVIA*/
fillellipse(155,120,2,2);

ellipse(130,150,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /*madriz*/
fillellipse(130,150,2,2);

ellipse(125,185,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK);  /* ESTELI */
fillellipse(125,185,2,2);

ellipse(50,220,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK);  /* CHINANDEGA */
fillellipse(50,220,2,2);

ellipse(105,230,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK);  /* LEON */
fillellipse(105,230,2,2);

ellipse(135,285,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /*MANAGUA */
fillellipse(135,285,2,2);

ellipse(152,297,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* MASAYA*/
fillellipse(152,297,2,2);

ellipse(140,320,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* CARAZO*/
fillellipse(140,320,2,2);

ellipse(170,350,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* RIVAS*/
fillellipse(170,350,2,2);

ellipse(163,318,200,199,2,2);
setfillstyle(SOLID_FILL,BLACK); /* GRANADA */
fillellipse(163,318,2,2);



}
void detect (void){
settextstyle(1,0,2);
 do{ 

settextstyle(1,0,2);
		if(minlimit(1,323,120,338,130)==1)
	{

	setcolor(WHITE);


	outtextxy(30,450,"RAAN"); sleep(1);




setcolor(0);


outtextxy(30,450,"RAAN");

		 }


	 if(minlimit(1,320,252,330,260)==1)
		 {
	setcolor(WHITE);
	outtextxy(30,450,"RAAS");sleep(1);


setcolor(0);
outtextxy(30,450,"RAAS");
}



 if (minlimit(1,240,290,250,300)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"CHONTALES");sleep(1);
setcolor(0);
outtextxy(30,450,"CHONTALES"); }

 if (minlimit(1,300,360,310,370)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"RIO SAN JUAN");sleep(1);
setcolor(0);
outtextxy(30,450,"RIO SAN JUAN"); }

 if (minlimit(1,220,250,230,260)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"BOACO");sleep(1);
setcolor(0);
outtextxy(30,450,"BOACO"); }

 if (minlimit(1,195,205,205,215)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"MATAGALPA");sleep(1);
setcolor(0);
outtextxy(30,450,"MATAGALPA"); }

if (minlimit(1,205,140,215,150)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"JINOTEGA");sleep(1);
setcolor(0);
outtextxy(30,450,"JINOTEGA");}

 if (minlimit(1,155,120,165,130)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"NUEVA SEGOVIA");sleep(1);
setcolor(0);
outtextxy(30,450,"NUEVA SEGOVIA"); }

if (minlimit(1,130,150,140,160)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"MADRIZ");sleep(1);
setcolor(0);
outtextxy(30,450,"MADRIZ");}

if (minlimit(1,125,185,135,195)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"ESTELI");sleep(1);
setcolor(0);
outtextxy(30,450,"ESTELI");}

 if (minlimit(1,105,230,115,240)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"LEON");sleep(1);
setcolor(0);
outtextxy(30,450,"LEON");}

if (minlimit(1,50,220,60,230)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"CHINANDEGA");sleep(1);
setcolor(0);
outtextxy(30,450,"CHINANDEGA");}

 if (minlimit(1,135,285,145,295)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"MANAGUA");sleep(1);
setcolor(0);
outtextxy(30,450,"MANAGUA"); }

if (minlimit(1,152,297,162,307)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"MASAYA");sleep(1);
setcolor(0);
outtextxy(30,450,"MASAYA");}

 if (minlimit(1,120,310,150,320)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"CARAZO");sleep(1);
setcolor(0);
outtextxy(30,450,"CARAZO"); }

if (minlimit(1,170,350,180,360)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"RIVAS");sleep(1);
setcolor(0);
outtextxy(30,450,"RIVAS");}


 if (minlimit(1,163,318,173,328)==1)
{
  setcolor(WHITE);
outtextxy(30,450,"GRANADA");sleep(1);
setcolor(0);
outtextxy(30,450,"GRANADA");}

 


 mver();

mver();

  }while(mclick()!=1);


/* -------------seleccion de la  raan -------------*/
do{

if (mclick()==1 && minlimit(1,281,41,375,165)){  mocultar();

cleardevice();

  raan();
mver();
do{
  mlimit(1,450,0,640,480);
click_raan();
selecti();
	
}while((!kbhit())); }
	}while((mclick()!=1));
/*----------------------------------------------------*/

/* -----------------seleccion de la raas--------------------- */

do{
if (mclick()==1 && minlimit(1,270,229,363,328)){  mocultar();
cleardevice();
  raas();
      mver();
	do{
  mlimit(1,450,0,640,480);
click_raas();
selecti();
	
}while((!kbhit())); }
	}while((mclick()!=1));
/*------------------------------------------------------------*/
 /* ------------seleccion del rio san juan ----------------------------*/

do{
		if (mclick()==1 && minlimit(1,275,354,351,404)){  mocultar();
			cleardevice();
  			rio_s();
  			mver();
		do{
  			mlimit(1,450,0,640,480);
			click_rio();
			selecti();
	
		}while((!kbhit()));
		}
}while((mclick()!=1));


/*------------------------------------------------------------*/

 /* ------------seleccion de chontales ----------------------------*/

do{
if (mclick()==1 && minlimit(1,195,281,292,311)){  mocultar();
cleardevice();
  chon();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_cho();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de boaco ----------------------------*/

do{
if (mclick()==1 && minlimit(1,171,243,262,262)){  mocultar();
cleardevice();
  boaco();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_bo();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Matagalpa ----------------------------*/

do{
if (mclick()==1 && minlimit(1,130,209,244,222)){  mocultar();
cleardevice();
  mata();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_ma();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Jinotega ----------------------------*/

do{
if (mclick()==1 && minlimit(1,160,100,266,131)){  mocultar();
cleardevice();
  jino();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_ji();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Nueva segovia ----------------------------*/

do{
if (mclick()==1 && minlimit(1,84,112,185,132)){  mocultar();
cleardevice();
  segovia();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_se();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de MADRIZ ----------------------------*/

do{
if (mclick()==1 && minlimit(1,95,146,162,160)){  mocultar();
cleardevice();
  madriz();
 mver();
  do{
  			mlimit(1,450,0,640,480);
			click_MAD();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/
/* ------------seleccion de Esteli ----------------------------*/

do{
if (mclick()==1 && minlimit(1,98,172,149,198)){  mocultar();
cleardevice();
  esteli();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_es();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de CHINANDEGA ----------------------------*/

do{
if (mclick()==1 && minlimit(1,2,195,104,216)){  mocultar();
cleardevice();
  chinan();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_chi();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Leon ----------------------------*/

do{
if (mclick()==1 && minlimit(1,66,235,138,247)){  mocultar();
cleardevice();
  leon();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_le();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Carazo ----------------------------*/

do{
if (mclick()==1 && minlimit(1,112,313,159,335)){  mocultar();
cleardevice();
  carazo();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_car();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Granada ----------------------------*/

do{
if (mclick()==1 && minlimit(1,159,303,202,317)){  mocultar();
cleardevice();
  granada();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_gra();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de masaya ----------------------------*/

do{
if (mclick()==1 && minlimit(1,135,293,170,300)){  mocultar();
cleardevice();
  masaya2();
   mver();
  do{
  			mlimit(1,450,0,640,480);
			click_mas();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de managua ----------------------------*/

do{
if (mclick()==1 && minlimit(1,89,271,180,282)){  mocultar();
cleardevice();
  Managua2();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_mana();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

/* ------------seleccion de Rivas ----------------------------*/

do{
if (mclick()==1 && minlimit(1,146,340,253,379)){  mocultar();
cleardevice();
  rivas();
  mver();
  do{
  			mlimit(1,450,0,640,480);
			click_riv();
			selecti();
	
		}while((!kbhit()));
		}}while((mclick()!=1));


/*------------------------------------------------------------*/

do{
botons();
}while((mclick()!=1));
click_help();
click_back();
back_help();

}

void selecti (void){
do{
botons();
}while((mclick()!=1));
click_help();
back_help();
click_back();


}






void back_help (void){
do{
   if(mclick()==1 && minlimit(1,610,375,625,390)){
   setfillstyle(1,DARKGRAY);
   mocultar();
    bar(490,200,630,400);
    mver();

}
}while((mclick()!=1));}


void click_help (void){
do{
   if(mclick()==1 && minlimit(1,520,160,590,180)){
   /*boton ayuda*/

	botonys();delay(30);
    botony();}
	}while((mclick()!=1));
}


void click_back (void){

do{
if(mclick()==1 && minlimit(1,480,420,510,440)){
mocultar();
depar();
do{
detect();
mver();}while((!kbhit()));}}while((mclick()!=1));}



void carg (void)
{
int b,p,y;
for(y=0;y<=200;y++){
setfillstyle(relleno,WHITE);
bar(0,y,640,y);delay(10);  }
setfillstyle(relleno,BLUE);
bar(220,50,245,150);
bar(245,125,290,150);
bar(255,50,280,115);
bar(290,85,315,150);
bar(280,50,350,75);
bar(325,50,350,150);
bar(350,125,385,150);
bar(360,50,385,75);
bar(360,85,385,150);
setcolor(BLUE);
settextstyle(5,0,0);
outtextxy(90,140,"Lideres en ciencias y tecnologia");
for(p=0;p<=5;p++){
setcolor(WHITE);
settextstyle(0,0,0);
outtextxy(270,260,"CARGANDO");

settextstyle(5,0,0);
outtextxy(90,350,"Feria Tecnologica 2013  F.E.C");

for(b=0;b<=100;b+=20){
setcolor(WHITE);
setfillstyle(SOLID_FILL,WHITE);
fillellipse(250+b,240,3,3);}
for(b=0;b<=100;b+=20){
setfillstyle(SOLID_FILL,WHITE);
fillellipse(250+b,240,6,6);delay(180);
setfillstyle(SOLID_FILL,BLACK);
setcolor(BLACK);
fillellipse(250+b,240,6,6);
setfillstyle(relleno,WHITE);
setcolor(WHITE);
fillellipse(250+b,240,3,3);
}

}cleardevice();}




void click_raan (void){
do{
/*************************rann******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\raan.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
do{
		if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			raan();
			mver();
			do{
  				mlimit(1,450,0,640,480);
				click_raan();
				selecti();
	
			}while((!kbhit())); 


		}

}while((!kbhit()));


}}while((mclick()!=1));

}

void click_raas (void){
do{
/*************************RAAS******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\raas.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			raas();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_raas();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}
void click_rio (void){
do{
/*************************RIO SAN JUAN******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\sanjuan.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			rio_s();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_rio();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_cho (void){
do{
/*************************CHONTALES******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\tales.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			chon();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_cho();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}
void click_bo (void){
do{
/*************************BOACO******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\boaco.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			boaco();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_bo();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_ma (void){
do{
/*************************MATAGALPA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\mata.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			mata();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_ma();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_ji (void){
do{
/*************************JINOTEGA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\jinotega.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			jino();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_ji();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_se (void){
do{
/*************************NUEVA SEGOVIA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\segovia.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			segovia();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_se();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_MAD (void){
do{
/*************************MADRIZ******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\madriz.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			madriz();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_MAD();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_es (void){
do{
/*************************ESTELI******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\esteli.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			esteli();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_es();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_chi (void){
do{
/*************************CHINANDEGA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\chinan.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			chinan();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_chi();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_le (void){
do{
/*************************LEON******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\leon.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			leon();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_le();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_mana (void){
do{
/*************************MANAGUA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\mana.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			Managua2();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_mana();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_car (void){
do{
/*************************CARAZO******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\carazo.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			carazo();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_car();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}
void click_gra (void){
do{
/*************************GRANADAO******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\granada.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			granada();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_gra();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}
void click_mas (void){
do{
/*************************MASAYA******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\masaya.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			masaya2();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_mas();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}

void click_riv (void){
do{
/*************************RIVAS******************************/
		if(mclick()==1 && minlimit(1,455,0,560,40)){
		closegraph();
		d256colores();
		ShowBMP ("c:\\tc20\\bin\\imagenes\\rivas.bmp");
/*****************regreso*****************/
	setfillstyle(1,LIGHTGRAY);
	bar(455,0,560,20);
	setcolor(0);
	rectangle(455,0,560,20);
	setcolor(BLUE);
	outtextxy(460,5,"Regresar");
	mver();
 do{
	if (mclick()==1 && minlimit(1,455,0,560,20)){
			closegraph();
			colores16();
			mlimit(1,450,0,640,480);
			rivas();
      			mver();
				do{
  					mlimit(1,450,0,640,480);
					click_riv();
					selecti();
	
				}while((!kbhit()));

	}

 }while((!kbhit()));


}}while((mclick()!=1));

}
void intro (void)
{

   /*------------------RECTANGULO GRIS------------------------------------*/
  setfillstyle(1,LIGHTGRAY);
  bar(0,0,640,479);
  /*------------------RECTANGULO GRIS CLARO----------------------------------*/
  setfillstyle(1,DARKGRAY);
  bar(39,39,601,410);
  /*------------------RECTANGULO negro--------------------------------------*/
  setfillstyle(1,0);
  bar(40,40,600,409);
  /*----------------LLENADOS DE LOS RECTANGULOS DEL LOGO-------------------*/
  setfillstyle(1,BLUE);
  bar(5,2,20,35);
  bar(10,25,50,35);
  bar(40,15,50,35);
  bar(27,2,37,20);

  bar(30,2,70,10);
  bar(55,2,70,35);
  bar(55,25,90,35);
  bar(78,13,90,35);
  bar(78,2,90,10);
  /*-------------------------------------------------------------------*/

settextstyle(0,0,1);
setcolor(CYAN);
outtextxy(40,60,"                            INSTRUCCIONES");

outtextxy(80,80," En toda la aplicacion debera hacer uso del mouse,al");
outtextxy(80,95,"momento de haber ingresado a la pantalla pricipal podra ver ");
outtextxy(80,110,"un mapa de Nicaragua con su respectiva Divion Politica,");
outtextxy(80,125,"posicionando el mouse en los distintos puntos ubicados ");
outtextxy(80,140,"en cada region podra ver el nombre del departamento.");
outtextxy(80,155,"Habran distintos botones:");
outtextxy(80,170,"-Ayuda: Le brindara una pequeña informacion acerca del");
outtextxy(80,185,"acceso dentro de la pantalla principal de la aplicacion.");
outtextxy(80,200,"-Regresar: Permite volver a la pantalla principal.");
outtextxy(80,215,"-Salir: Sale de la aplicacion.");
outtextxy(80,230,"Un Hipervinculo ubicado en la parte superior derecha");
outtextxy(80,245,"que le permitira ver imagenes de los departamentos:");
outtextxy(80,260,"-Dando clic en el nombre del departamento abrira una imagen");
outtextxy(80,275,"de dicho departamento,podra regresar  a la pantalla principal");
outtextxy(80,290,"dando clic en su respectivo boton.");
outtextxy(80,305,"Para poder acceder a cualquier departamendo debera dar");
outtextxy(80,320,"clic en la region (excluyendo el punto que le indica el");
outtextxy(80,335,"nombre) , desplegandose otra ventana en la cual podra verse el"); 
outtextxy(80,355,"croquis y una pequeña descripcion del departamento.");

}
  


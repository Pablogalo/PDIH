#include <dos.h>

#define BYTE unsigned char

int COLOR_TEXTO = 15;
int COLOR_FONDO = 0; 

// Coloca el cursor en la posición indicada
void gotoxy(int x, int y){ // 1
	union REGS inregs, outregs;
 	inregs.h.ah = 0x02;
 	inregs.h.bh = 0x00;
 	inregs.h.dh = x;
 	inregs.h.dl = y;
    int86(0x10, &inregs, &outregs);
}

// Modificar color texto
void textcolor(int color){ // 5
	COLOR_TEXTO = color;
}

// Modificar color fondo
void textbackground(int color){ // 6
	COLOR_FONDO = color;
}

// Borrar pantalla
void clrscr(){ // 7
	union REGS inregs, outregs;
 	inregs.h.ah = 0x06;
 	inregs.h.al = 0x00;
 	inregs.h.bh = COLOR_FONDO << 4 | COLOR_TEXTO;;
 	inregs.h.ch = 0x00;
 	inregs.h.cl = 0x00;
 	inregs.h.dh = 0x24;
 	inregs.h.dl = 0x79;
    int86(0x10, &inregs, &outregs);
}

// Escribir caracter con los colores actuales
void cputchar(char letra){ // 8
	union REGS inregs, outregs;
	inregs.h.ah = 0x09;
	inregs.h.al = letra;
	inregs.h.bl = COLOR_FONDO << 4 | COLOR_TEXTO;
	inregs.h.bh = 0x00;
	inregs.x.cx = 1;
	int86(0x10,&inregs,&outregs);
}

void recuadro(int xSup, int ySup, int xInf, int yInf, int colorT, int colorF){
   int i;

   textcolor(colorT);
   textbackground(colorF);

   clrscr();

   // Dibujar linea superior
   for(i = ySup; i <= yInf; i++){
      gotoxy(xSup, i);
      cputchar('*');
   }
   // Dibujar linea inferior
   for(i = ySup; i <= yInf; i++){
      gotoxy(xInf, i);
      cputchar('*');
   }
   // Dibujar linea izquierda
   for(i = xSup; i <= xInf; i++){
      gotoxy(i, ySup);
      cputchar('*');
   }
   // Dibujar linea derecha
   for(i = xSup; i <= xInf; i++){
      gotoxy(i, yInf);
      cputchar('*');
   }
}


/*#################################################################################*/
int main(){
   int xSup, xInf, ySup, yInf, colorF, colorT;

   printf("Introduzca la fila en la que situar la esquina superior izquierda: ");
   scanf("%d", &xSup);

   printf("Introduzca la columna en la que situar la esquina superior izquierda: ");
   scanf("%d", &ySup);

   printf("Introduzca la fila en la que situar la esquina inferior derecha: ");
   scanf("%d", &xInf);

   printf("Introduzca la columna en la que situar la esquina inferior derecha: ");
   scanf("%d", &yInf);

   printf("Introduzca el color del texto: ");
   scanf("%d", &colorT);

   printf("Introduzca el color del fondo: ");
   scanf("%d", &colorF);   

   recuadro(xSup, ySup, xInf, yInf, colorT, colorF);

   return 0;
}

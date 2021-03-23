#include <dos.h>

#define BYTE unsigned char

int COLOR_TEXTO = 15;
int COLOR_FONDO = 0; 

// hace una pausa
void pausa(){
   union REGS inregs, outregs;
   inregs.h.ah = 0x00;
   int86(0x16, &inregs, &outregs);
}

// Coloca el cursor en la posición indicada
void gotoxy(int x, int y){ // 1
	union REGS inregs, outregs;
 	inregs.h.ah = 0x02;
 	inregs.h.bh = 0x00;
 	inregs.h.dh = x;
 	inregs.h.dl = y;
    int86(0x10, &inregs, &outregs);
}

// Fijar aspecto del cursor 
void setcursortype(int tipo_cursor){ // 2
	union REGS inregs, outregs;
	inregs.h.ah = 0x01;
	switch(tipo_cursor){
		case 0: //invisible
			inregs.h.ch = 010;
			inregs.h.cl = 000;
			break;
		case 1: //normal
			inregs.h.ch = 010;
			inregs.h.cl = 010;
			break;
		case 2: //grueso
			inregs.h.ch = 000;
			inregs.h.cl = 010;
			break;
	}
	int86(0x10, &inregs, &outregs);
}

// Establece el modo de vídeo
void setvideomode(BYTE modo){ // 3
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

// Obtener modo de video actual
BYTE getvideomode(){ // 4
	union REGS inregs, outregs;
 	inregs.h.ah = 0x0F;
    int86(0x10, &inregs, &outregs);

    return outregs.h.al;
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

// Obtener caracter de teclado y mostrarlo en pantalla
void getche(){ // 9
	union REGS inregs, outregs;
	inregs.h.ah = 0x00;
	int86(0x16,&inregs,&outregs);
	cputchar(outregs.h.al);
}


/*#################################################################################*/
int main(){
   BYTE modo;

   modo = getvideomode();
   printf("\nModo de video seleccionado: %d ", modo);

   printf("\nCursor invisible: ");
   setcursortype(0);
   pausa();

   printf("\nEscribir caracter en la posicion actual: ");
   cputchar('A');
   pausa();

   printf("\nCursor grueso: ");
   setcursortype(2);
   pausa();

   printf("\nCambiar color a texto en azul claro y fondo en azul");
   textcolor(9);
   textbackground(1);

   printf("\nPulse una tecla (se mostrara por pantalla): ");
   getche();


   printf("\nCursor normal: ");
   setcursortype(1);
   pausa();

   textcolor(15);
   textbackground(0);

   printf("\nBorrar la pantalla (pulsar alguna tecla)");
   pausa();
   clrscr();
   gotoxy(0,0);
   printf("\nNos desplazamos a la fila 15 columna 30 y escribimos una 'P': ");
   gotoxy(15,30);
   cputchar('P');

   return 0;
}

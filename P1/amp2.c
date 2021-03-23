#include <dos.h>

#define BYTE unsigned char

int COLOR_TEXTO = 15;
int COLOR_FONDO = 0; 
BYTE MODOTEXTO = 3;
BYTE MODOGRAFICO = 4;

// hace una pausa
void pausa(){
   union REGS inregs, outregs;
   inregs.h.ah = 0x00;
   int86(0x16, &inregs, &outregs);
}

// Establece el modo de vídeo
void setvideomode(BYTE modo){ // 3
   union REGS inregs, outregs;
   inregs.h.al = modo;
   inregs.h.ah = 0x00;
   int86(0x10, &inregs, &outregs);
}

// pone un pixel en la coordenada X,Y de color C
void pixel(int x, int y, BYTE C){
   union REGS inregs, outregs;
   inregs.x.cx = x;
   inregs.x.dx = y;
   inregs.h.al = C;
   inregs.h.ah = 0x0C;
   int86(0x10, &inregs, &outregs);
}


/*#################################################################################*/
int main(){
   int i, j;

   setvideomode(MODOGRAFICO);

   // Cuadrado
   for(i = 100; i <= 180; i++){
      for(j = 70; j <= 71; j++){
         pixel(i, j, 1);
      }
   }

   for(i = 100; i <= 180; i++){
      for(j = 150; j <= 151; j++){
         pixel(i, j, 1);
      }
   }

   for(i = 100; i <= 101; i++){
      for(j = 70; j <= 150; j++){
         pixel(i, j, 1);
      }
   }

   for(i = 179; i <= 180; i++){
      for(j = 70; j <= 150; j++){
         pixel(i, j, 1);
      }
   }

   // Tejado
   j = 70;
   for(i = 100; i <= 140; i++){
      pixel(i, j, 1);
      j--;
   }

   j = 69;
   for(i = 100; i <= 140; i++){
      pixel(i, j, 1);
      j--;
   }

   j = 30;
   for(i = 140; i <= 180; i++){
      pixel(i, j, 1);
      j++;
   }

   j = 29;
   for(i = 140; i <= 180; i++){
      pixel(i, j, 1);
      j++;
   }

   // Puerta
   for(i = 130; i <= 131; i++){
      for(j = 115; j <= 150; j++){
         pixel(i, j, 1);
      }
   }

   for(i = 150; i <= 151; i++){
      for(j = 115; j <= 150; j++){
         pixel(i, j, 1);
      }
   }

   for(i = 130; i <= 151; i++){
      for(j = 115; j <= 116; j++){
         pixel(i, j, 1);
      }
   }

   pixel(145, 133, 1);
   pixel(144, 133, 1);
   pixel(146, 133, 1);
   pixel(145, 132, 1);
   pixel(145, 134, 1);

   // Ventana
   for(i = 110; i <= 130; i++){
         pixel(i, 80, 1);
   }

   for(i = 110; i <= 130; i++){
         pixel(i, 95, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(110, j, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(130, j, 1);
   }

   for(i = 110; i <= 130; i++){
         pixel(i, 87, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(120, j, 1);
   }

   // Ventana
   for(i = 150; i <= 170; i++){
         pixel(i, 80, 1);
   }

   for(i = 150; i <= 170; i++){
         pixel(i, 95, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(150, j, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(170, j, 1);
   }

   for(i = 150; i <= 170; i++){
         pixel(i, 87, 1);
   }

   for(j = 80; j <= 95; j++){
         pixel(160, j, 1);
   }

   pausa();
   setvideomode(MODOTEXTO);

   return 0;
}

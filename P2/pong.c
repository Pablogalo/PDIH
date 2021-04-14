#include <ncurses.h>
#include <unistd.h>
#include <math.h>

#define DELAY 50000
#define X_PLAYER 2
#define X_COMPUTER 78

void draw_bar(int player, int y){
	int x;
	if(player == 0){ // user
		x = X_PLAYER;
	} else{
		x = X_COMPUTER;
	}

	int y_aux = y;

	for(int i = 0; i < 2; i++){
 	y_aux--;
 	mvprintw(y_aux, x, "|");
 	} 
 	mvprintw(y, x, "|");
 	y_aux = y;
 	for(int i = 0; i < 2; i++){
 	y_aux++;
 	mvprintw(y_aux, x, "|");
 	} 
}

int main(int argc, char *argv[]) {
 int x = 0, y = 0;
 int max_x, max_y;
 int next_x = 0, next_y = 0;
 int directionx = 1,  directiony = 1;
 int pos_player, pos_computer;
 int aux, mov;
 int playerScore = 0, computerScore = 0;
 char playerScoreC[10];
 char computerScoreC[10];

 initscr();
 noecho();
 curs_set(FALSE);
 nodelay(stdscr, TRUE);

 getmaxyx(stdscr, max_y, max_x);
 pos_player = pos_computer = max_y / 2;
 x = max_x / 2;
 y = max_y / 2;
 
 WINDOW *window = newwin(8, 40, 5, 20);
 wbkgd(window, COLOR_PAIR(0));
 box(window, '|', '-');
 mvwprintw(window, 0, 8, "PONG");
 mvwprintw(window, 1, 5, "Controles:");
 mvwprintw(window, 3, 1, "'w' -> Desplazar barra arriba");
 mvwprintw(window, 4, 1, "'s' -> Desplazar barra abajo");
 mvwprintw(window, 6, 1, "Usted es el jugador de la izquierda");

 wrefresh(window);
 usleep(10000000);

 while(1) {
 	clear();
 	mvprintw(y, x, "o");
 	draw_bar(0, pos_player);
 	draw_bar(1, pos_computer);

 	// Marcador
 	sprintf(playerScoreC, "%d", playerScore);
 	sprintf(computerScoreC, "%d", computerScore);
 	mvprintw(0, 39, playerScoreC);
 	mvprintw(0, 40, "-");
 	mvprintw(0, 41, computerScoreC);

 	refresh();

 	usleep(DELAY);

 	next_x = x + directionx;
 	next_y = y + directiony;

 	// Rebote superior
 	if (next_y >= max_y || next_y < 0) {
 		directiony*= -1;
 	} else {
 		y+= directiony;
 	}

 	// Rebote con jugador
 	if(next_x == X_PLAYER){
 		aux = abs(pos_player - next_y);
 		if(aux < 3){
 			directionx *= -1;
 		}
 	}

 	// Rebote con maquina
 	if(next_x == X_COMPUTER){
 		aux = abs(pos_computer - next_y);
 		if(aux < 3){
 			directionx *= -1;
 		}
 	}

 	// Movimiento jugador
 	mov = getch();
 	if(mov == 'w' && (pos_player - 2) > 0){
 		pos_player -= 1;
 	}
 	if(mov == 's' && (pos_player + 2) < (max_y - 1)){
 		pos_player += 1;
 	}

 	// Movimiento maquina
 	pos_computer = next_y;

 	// Goles
 	if (next_x >= max_x || next_x < 0){
 		if(next_x >= max_x){
 			mvprintw(max_y/2, (max_x/2)-7, "Gol del jugador");
 			refresh();
 			usleep(1000000);
 			playerScore++;
 			x = max_x / 2;
 			directionx *= -1;
 		}else{
 			mvprintw(max_y/2, (max_x/2)-7 , "Gol de la maquina");
 			refresh();
 			usleep(1000000);
 			computerScore++;
 			x = max_x / 2;
 			directionx *= -1;
 		}
 		
 	}else{
 		x += directionx;
 	} 	
 }

 endwin();
}

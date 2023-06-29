#include "ListaPiezas.h"


ListaPiezas::ListaPiezas() {
	numero = 0;
	turno = EQUIPO_B; //Empiezan las blancas
	for (int i = 0;i < MAX_PIEZAS;i++) {
		lista[i] = 0;
	}
	casillax= casillay = 0;
	casillax1 = casillay1=0;
	seleccion = COORD_DEST;
	piezaComida = false;
	promocionflag = promocioncheck = wait = false;
	Torre_A_Izq = true;
	Torre_A_Drh = true;
	Torre_B_Izq = true;
	Torre_B_Drh = true;
	Enroque_rey_A = true;
	Enroque_rey_B = true;

	promo = pDAMA;
	selecciona = seleccionb = false;
}


bool ListaPiezas::agregar(pieza*p) {
	if (numero < MAX_PIEZAS) {
		lista[numero++] = p;
		bool flag = 0;
		for (int i = 0; i < numero; i++) {
			if (lista[i] == p) flag = 1;
		}
		if (flag == 0) lista[numero++] = p;
		if (flag == 1) return false;
	}
	else {
		return false;
	}
	return true;
}
void ListaPiezas::dibuja()
{
	for (int i = 0;i < numero;i++)
		if (lista[i] != 0) {
			lista[i]->dibujarPieza();
		}
}

void ListaPiezas::eliminarPieza(int ref)
{
	if ((ref < 0) || (ref >= numero))
		return;
	delete lista[ref];
	numero--;
	for (int i = ref; i < numero; i++) {
		lista[i] = lista[i + 1];
	}
}

void ListaPiezas::eliminarPieza(pieza* p)
{
	for (int i = 0;i < numero;i++) {
		if (lista[i] == p) {
			eliminarPieza(i);
		}
	}
}
void ListaPiezas::lista_inicial(paises p1,paises p2) {
	for (int i = 1;i < 9;i++) {
		agregarPeon(p1, EQUIPO_A, 2, i);
		agregarPeon(p2, EQUIPO_B, 7, i);
	}
	for (int i = 1;i < 3;i++) {
		agregarTorre(p1, EQUIPO_A, 1, i*7-6);
		agregarTorre(p2, EQUIPO_B, 8, i*7-6);
		agregarCaballo(p1, EQUIPO_A, 1, i*5-3);
		agregarCaballo(p2, EQUIPO_B, 8, i*5-3);
		agregarAlfil(p1, EQUIPO_A, 1, i*3);
		agregarAlfil(p2, EQUIPO_B, 8, i*3);
	}
		agregarDama(p1, EQUIPO_A, 1, 4);
		agregarDama(p2, EQUIPO_B, 8, 4);
		agregarRey(p1, EQUIPO_A, 1, 5);
		agregarRey(p2, EQUIPO_B, 8, 5);
}
void ListaPiezas::agregarPeon(paises p,equipos e,int fil,int col) {
	Peon* aux = new Peon;
	aux->inicializa(p, e, PEON, fil, col);
	agregar(aux);
}
void ListaPiezas::agregarTorre(paises p, equipos e, int fil, int col) {
	torre* aux = new torre;
	aux->inicializa(p, e, TORRE, fil, col);
	agregar(aux);
}
void ListaPiezas::agregarCaballo(paises p, equipos e, int fil, int col) {
	Caballo* aux = new Caballo;
	aux->inicializa(p, e, CABALLO, fil, col);
	agregar(aux);
}
void ListaPiezas::agregarAlfil(paises p, equipos e, int fil, int col) {
	alfil* aux = new alfil;
	aux->inicializa(p, e, ALFIL, fil, col);
	agregar(aux);
}
void ListaPiezas::agregarDama(paises p, equipos e, int fil, int col) {
	dama* aux = new dama;
	aux->inicializa(p, e, REINA, fil, col);
	agregar(aux);
}
void ListaPiezas::agregarRey(paises p, equipos e, int fil, int col) {
	rey* aux = new rey;
	aux->inicializa(p, e, REY, fil, col);
	agregar(aux);

}
bool ListaPiezas::piezaencasilla(int fil, int col) {
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getFila() == fil && lista[i]->getColumna() == col)return true;
	}
	return false;
}

void ListaPiezas::mousePress(int button, int state, int x, int y)
{
	
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		
		switch (seleccion) {
		case COORD_INI:
		
			casillax = (x - 207) * 8 / (791 - 207) + 1;
			casillay = (y - 67) * 8 / (651 - 67) + 1;
			seleccion = COORD_DEST;
			if (turno == EQUIPO_B){
				click12 = true;
				
			}
			if (turno == EQUIPO_A){
				click22 = true;
				
			}
			break;
		case COORD_DEST:
			casillax1 = (x - 207) * 8 / (791 - 207) + 1;
			casillay1 = (y - 67) * 8 / (651 - 67) + 1;
			seleccion = COORD_INI;
			if (piezaencasilla(casillay1, casillax1)&& turno == EQUIPO_B && piezaseleccionada(casillay1,casillax1)!=nullptr && piezaseleccionada(casillay1, casillax1)->getequipo()==EQUIPO_B) {
				click1 = true;
				
			}
			if(piezaencasilla(casillay1, casillax1) && turno == EQUIPO_A && piezaseleccionada(casillay1, casillax1) != nullptr && piezaseleccionada(casillay1, casillax1)->getequipo() == EQUIPO_A) {
				click2 = true;
			
			}
			break;
		}
	}
}

bool ListaPiezas::colisionalfil(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

	//Si se desplaza en diagonal hacia arriba a la derecha
	if ((desfilas > 0) && (descolumnas > 0)) {
		for (i = pi->getFila() + 1, j = pi->getColumna() + 1; i < fil  && j < col ; i++, j++) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	//Si se desplaza en diagonal hacia abajo a la derecha
	if ((desfilas < 0) && (descolumnas > 0)) {
		for (i = pi->getFila() - 1, j = pi->getColumna() + 1; i > fil  && j < col ; i--, j++) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	//Si se desplaza en diagonal hacia abajo a la izquierda
	if ((desfilas < 0) && (descolumnas < 0)) {
		for (i = pi->getFila() - 1, j = pi->getColumna() - 1; i > fil  && j > col ; i--, j--) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	//Si se desplaza hacia arriba a la izquierda
	if ((desfilas > 0) && (descolumnas < 0)) {
		for (i = pi->getFila() + 1, j = pi->getColumna() - 1; i < fil && j > col; i++, j--) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	return false;
}

bool ListaPiezas::colisiontorre(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

		//Si se desplaza en horizontal derecha
		if (descolumnas > 0) {
			for (i = pi->getFila(), j = pi->getColumna()+1; j < col; j++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		//Si se desplaza en horizontal izquierda
		if (descolumnas < 0) {
			for (i = pi->getFila(), j = pi->getColumna()-1; j > col; j--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		//Si se desplaza vetical arriba
		if (desfilas > 0) {
			for (i = pi->getFila()+1, j = pi->getColumna(); i < fil; i++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		//Si se desplaza vertical abajo
		if (desfilas < 0) {
			for (i = pi->getFila()-1, j = pi->getColumna(); i > fil; i--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		return false;
}

bool ListaPiezas::colisionreina(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

	//Colision de alfil y torre segun la casilla que quiera desplazar

	if (abs(desfilas) == abs(descolumnas)) {
		return colisionalfil(pi, fil, col);
	}
	if (desfilas == 0) {
		return colisiontorre(pi, fil, col);
	}
	if (descolumnas == 0) {
		return colisiontorre(pi, fil, col);
	}
	return false;
}

bool ListaPiezas::colisionpeon(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

	pieza* posicion = piezaseleccionada(fil, col);

	//Para el peon del equipo A
	if (pi->getequipo() == EQUIPO_A) {

		//Si se mueve una casilla
		if ((desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() + 1, pi->getColumna()) == 1)return true;
		}
		//Si se mueve dos casillas
		if ((desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()+1, j = pi->getColumna(); i < fil+1; i++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		//Si no hay pieza no tiene permitido moverse en diagonal y se considora colision
		if (posicion == nullptr) {
			if ((desfilas == 1) && (descolumnas == 1)) {
				return true;
			}
			if ((desfilas == 1) && (descolumnas == -1)) {
				return true;
			}
		}
		//Si hay pieza en la casilla final se considera que va a comer en diagonal y no hay colision
		else if (posicion != nullptr) {
			if ((desfilas == 1) && (descolumnas == 1)) {
				return false;
			}
			if ((desfilas == 1) && (descolumnas == -1)) {
				return false;
			}
		}
		return false;
	}
	//Equivalente al equipo A para el caso del equipo B
	else if (pi->getequipo() == EQUIPO_B) {

		if ((-desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() - 1, pi->getColumna()) == 1)return true;
		}
		if ((-desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()-1, j = pi->getColumna(); i > fil-1; i--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
	}
	if (posicion == nullptr) {
		if ((-desfilas == 1) && (-descolumnas == 1)) {
			return true;
		}
		if ((-desfilas == 1) && (-descolumnas == -1)) {
			return true;
		}
	}
	else if (posicion != nullptr) {
		if ((-desfilas == 1) && (-descolumnas == 1)) {
			return false;
		}
		if ((-desfilas == 1) && (-descolumnas == -1)) {
			return false;
		}
	}
		return false;
}

bool ListaPiezas::colisionrey(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i = pi->getFila();
	int j = pi->getColumna();

	if ((abs(desfilas) <= 1) && (abs(descolumnas) <= 1)) {
		return false;
	}

	//Si se permite el enroque en el rey A 
	if (Enroque_rey_A == true) {
		//Si se mueve hacia la izquierda
		if ((pi->getequipo() == EQUIPO_B) && (fil == 8) && (col == 3)) {
			//Si la torre puede enrocar
			if (Torre_A_Izq == true) {
				if (piezaencasilla(i, j - 1) == 1)return true;
				if (piezaencasilla(i, j - 3) == 1)return true;
				return false;
			}
		}

		if ((pi->getequipo() == EQUIPO_B) && (fil == 8) && (col == 2)) {
			//Si la torre puede enrocar
			if (Torre_A_Drh == true) {
				if (piezaencasilla(8, 2) == 1)return true;
				return false;
			}
		}
		//Si se mueve a la derecha
		if ((pi->getequipo() == EQUIPO_B) && (fil == 8) && (col == 7)) {
			//Si la torre puede enrocar
			if (Torre_A_Drh == true) {
				if (piezaencasilla(i, j + 1) == 1)return true;
				return false;
			}
		}
	}
	//Si se permite el enroque en el rey B
	if (Enroque_rey_B == true) {
		//Si se mueve hacia la izquierda
		if ((pi->getequipo() == EQUIPO_A) && (fil == 1) && (col == 3)) {
			//Si la torre puede enrocar
			if (Torre_B_Izq == true) {
				if (piezaencasilla(i, j - 1) == 1)return true;
				if (piezaencasilla(i, j - 3) == 1)return true;
				return false;
			}
		}
		if ((pi->getequipo() == EQUIPO_A) && (fil == 1) && (col == 2)) {
			//Si la torre puede enrocar
			if (Torre_B_Drh == true) {
				if (piezaencasilla(1, 2) == 1)return true;
				return false;
			}
		}

		//Si se mueve a la derecha
		if ((pi->getequipo() == EQUIPO_A) && (fil == 1) && (col == 7)) {
			//Si la torre puede enrocar
			if (Torre_B_Drh == true) {
				if (piezaencasilla(i, j + 1) == 1)return true;
				return false;
			}
		}
	}
	return true;
}

bool ListaPiezas::colisionpieza(pieza* pi, int fil, int col) {
	bool resul;

	if (pi->getpieza() == TORRE) {
		resul = colisiontorre(pi, fil, col);
		return resul;
	}
	if (pi->getpieza() == PEON) {
		resul = colisionpeon(pi, fil, col);
		return resul;
	}
	if (pi->getpieza() == ALFIL) {
		resul = colisionalfil(pi, fil, col);
		return resul;
	}
	if (pi->getpieza() == REINA) {
		resul = colisionreina(pi, fil, col);
		return resul;
	}
	if (pi->getpieza() == CABALLO) {
		return false;
	}
	if (pi->getpieza() == REY) {
		resul = colisionrey(pi, fil, col);
		return resul;
	}
}

pieza* ListaPiezas::piezaseleccionada(int fil, int col) {
	//Seleciona la pieza que esta en la casilla
	for (int i = 0; i < numero; i++) {
		if ((lista[i]->getFila() == fil) && (lista[i]->getColumna() == col)){
			aux = true;
			return lista[i];
		}
	}
	return nullptr; //si no encuentra devuelve nada
}

void ListaPiezas::MoverPieza() {
	
	pieza* pi = piezaseleccionada(casillay1, casillax1);
	if (pi == nullptr)seleccion = COORD_DEST;
	if (pi != nullptr) {
		if (seleccion == COORD_DEST) {
			moverPieza(pi, casillay, casillax);
		}
	}
}
bool ListaPiezas::turnocorrecto(pieza* pi) {
	//Se gestiona el turno
	if (pi->getequipo() == turno)return true;
	return false;
}

bool ListaPiezas::movimientovalido(pieza* pi, int fil, int col) {

	//Se busca si hay alguna pieza en la posicion donde me quiero mover
	pieza* posicionfinal = piezaseleccionada(fil, col);

	// Si hay una pieza en esa posicion
	if (posicionfinal != nullptr) {
		//Si la pieza es del mismo equipo de la mia devuelve false
		if (pi->getequipo() == posicionfinal->getequipo())return false;
		//Si al pieza es de distinto equipo
		if (pi->getequipo() != posicionfinal->getequipo()) {
			//Si no es su turno devuelve false
			if (turnocorrecto(pi) == 0)return false;
			//Si es su turno entonces
			if (turnocorrecto(pi) == 1) {
				//Si la pieza comida es un rey
				if (posicionfinal->getpieza() == REY)return false;
				//Si la pieza comida no es un rey
				else if (posicionfinal->getpieza() != REY) {
					//Si el desplazamiento invalido devuelve false
					if (pi->desplazamientovalido(fil, col) == 0)return false;
					//Si el desplazamiento es valido entonces
					if (pi->desplazamientovalido(fil, col) == 1) {
						//Si la pieza colisiona con otra en su camino devuelve false
						if (colisionpieza(pi, fil, col) == 1)return false;
						//Si la pieza no colisiona con otras entonces el movimiento es valido
						if (colisionpieza(pi, fil, col) == 0) {
							if (jaqueposible(pi, fil, col) == 1)return false;
							if (jaqueposible(pi, fil, col) == 0) {

								return true;
							}
						}
					}
				}
			}
		}
	}
	// Si no hay una pieza en esa posicion
	else if (posicionfinal == nullptr) {
		//Si no es su turno devuelve false
		if (turnocorrecto(pi) == 0)return false;
		//Si es su turno entonces
		if (turnocorrecto(pi) == 1) {
			//Si el desplazamiento invalido devuelve false
			if (pi->desplazamientovalido(fil, col) == 0)return false;
			//Si el desplazamiento es valido entonces
			if (pi->desplazamientovalido(fil, col) == 1) {
				//Si la pieza colisiona con otra en su camino devuelve false
				if (colisionpieza(pi, fil, col) == 1)return false;
				//Si la pieza no colisiona con otras entonces el movimiento es valido
				if (colisionpieza(pi, fil, col) == 0) {
					if (jaqueposible(pi, fil, col) == 1)return false;
					if (jaqueposible(pi, fil, col) == 0) {
						return true;
					}
				}
			}
		}
	}
}
void ListaPiezas::moverPieza(pieza* pi, int fil, int col) {
	switch (turno) {
		//Turno del equipo A
	case EQUIPO_A:
		//Si el movimiento es válido
		if (movimientovalido(pi, fil, col) == 1) {
			//Come la pieza
			comer(fil, col);
			//Si hay enroque hazlo
			if (enroquevalido(pi, fil, col) == 1) {
				//Hacer enroque
				hacerenroque(pi, fil, col);
				ETSIDI::play("sonidos/castle.mp3");
			}
			//Si no hay enroque 
			if (enroquevalido(pi, fil, col) == 0 && !piezaComida) {
				ETSIDI::play("sonidos/move1.wav");
			}
			if (piezaComida&& !comprobarPromocion(pi,fil,col)) {
				piezaComida = false;
				ETSIDI::play("sonidos/capture.mp3");
			}
				anularenroque(pi, fil, col);
				//mueve la pieza
				pi->moverPieza(fil, col);
				//Si hay jaques
				if (jaque(EQUIPO_B) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (jaque(EQUIPO_A) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (comprobarPromocion(pi, fil, col))ETSIDI::play("sonidos/promote.mp3");
				turno = EQUIPO_B;
				if (JaqueMate(EQUIPO_B))
					ganaJUG1 = true;
		}
		else seleccion = COORD_DEST;
		break;
		//Turno del equipo B
	case EQUIPO_B:
		//Si el movimiento es válido
		if (movimientovalido(pi, fil, col) == 1) {
			//Come la pieza
			comer(fil, col);
			//Si hay enroque hazlo
			if (enroquevalido(pi, fil, col) == 1) {
				//Hacer enroque
				hacerenroque(pi, fil, col);
				ETSIDI::play("sonidos/castle.mp3");
			}
			//Si no hay enroque
			if (enroquevalido(pi, fil, col) == 0 && !piezaComida) {
				ETSIDI::play("sonidos/move1.wav");
			}
			if (piezaComida && !comprobarPromocion(pi, fil, col)) {
				piezaComida = false;
					ETSIDI::play("sonidos/capture.mp3");
			}
				anularenroque(pi, fil, col);
				//mueve la pieza
				pi->moverPieza(fil, col);
				//Si hay jaques
				if (jaque(EQUIPO_A) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (jaque(EQUIPO_B) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if(comprobarPromocion(pi,fil,col))ETSIDI::play("sonidos/promote.mp3");
				turno = EQUIPO_A;
				if (JaqueMate(EQUIPO_A))
					ganaJUG2 = true;
					//std::cout << "JAQUE MATE A";
		}
		else  seleccion = COORD_DEST;
		break;
	}
}

void ListaPiezas::destruirPiezas() {
	//Destruye las piezas de la lista
	for(int i=1;i<9;i++){
		for (int j = 1; j < 9; j++) {
			eliminarPieza(piezaseleccionada(i, j));
		}
	}
}

void ListaPiezas::dibujarbalon(int fil, int col) {

	glEnable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/balon.png").id);
	glDisable(GL_LIGHTING);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.0);
	glBegin(GL_POLYGON);

	glTexCoord2d(0, 0);
	glVertex3d(-4.0 + fil - 1, 4.0  - col + 1, 1.5);
	glTexCoord2d(0, 1);
	glVertex3d(-4.0  + fil - 1, 3.0 - col + 1, 1.5);
	glTexCoord2d(1, 1);
	glVertex3d(-3.0  + fil - 1, 3.0  - col + 1, 1.5);
	glTexCoord2d(1, 0);
	glVertex3d(-3.0  + fil - 1, 4.0  - col + 1, 1.5);

	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_ALPHA_TEST);
	glEnable(GL_LIGHTING);
	glDisable(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glEnable(GL_TEXTURE_2D);
}

bool ListaPiezas::enroquevalido(pieza* pi, int fil, int col) {

	pieza* torres;

	//Si la pieza que se mueve es un rey
	if (pi->getpieza() == REY) {
		if ((fil == 1) && (col == 3)) {
			//Busca la torre de la casilla(1,1)
			torres = piezaseleccionada(1, 1);
			//Si no hay torre
			if (torres == nullptr)return false;
			//Si hay torre
			else if (torres != nullptr) {
				if (torres->getmovimientos() != 0)return false;
				else if (torres->getmovimientos() == 0) {
					if (colisionpieza(pi, 1, 2) == 1)return false;
					return true;//No hay colisiones y la torre no se ha movido
				}
			}
		}
		if ((fil == 1) && (col == 7)) {
			//Busca la torre de la casilla(1,8)
			torres = piezaseleccionada(1, 8);
			//Si no hay torre
			if (torres == nullptr)return false;
			//Si hay torre
			else if (torres != nullptr) {
				if (torres->getmovimientos() != 0)return false;
				else if (torres->getmovimientos() == 0) {
					return true;//No hay colisiones y la torre no se ha movido
				}
			}
		}
		if ((fil == 8) && (col == 3)) {
			//Busca la torre de la casilla(8,1)
			torres = piezaseleccionada(8, 1);
			//Si no hay torre
			if (torres == nullptr)return false;
			//Si hay torre
			else if (torres != nullptr) {
				if (torres->getmovimientos() != 0)return false;
				else if (torres->getmovimientos() == 0) {
					if (colisionpieza(pi, 8, 2) == 1)return false;
					return true; //No hay colisiones y la torre no se ha movido
				}
			}
		}
		if ((fil == 8) && (col == 7)) {
			//Busca la torre de la casilla(8,8)
			torres = piezaseleccionada(8, 8);
			//Si no hay torre
			if (torres == nullptr)return false;
			//Si hay torre
			else if (torres != nullptr) {
				if (torres->getmovimientos() != 0)return false;
				else if (torres->getmovimientos() == 0) {
					return true;//No hay colisiones y la torre no se ha movido
				}
			}
		}
	}
	return false;
}
//
void ListaPiezas::hacerenroque(pieza* pi, int fil, int col) {

		//Si el movimiento es hacia la casilla(1,3) 
		if ((fil == 1) && (col == 3)) {
			pieza* torr = piezaseleccionada(1, 1);
			//Mover torre a la casilla(1,4);
			torr->moverPieza(1, 4);
		}
		//Si el movimiento es hacia la casilla(1,7) 
		if ((fil == 1) && (col == 7)) {
			pieza* torr = piezaseleccionada(1, 8);
			//Mover torre a la casilla(1,6);
			torr->moverPieza(1, 6);
		}
		//Si el movimiento es hacia la casilla(8,3) 
		if ((fil == 8) && (col == 3)) {
				pieza* torr = piezaseleccionada(8, 1);
				//Mover torre a la casilla(8,4);
				torr->moverPieza(8, 4);
		}
		//Si el movimiento es hacia la casilla(8,7) 
		if ((fil == 8) && (col == 7)) {
				pieza* torr = piezaseleccionada(8, 8);
				//Mover torre a la casilla(8,6);
				torr->moverPieza(8, 6);
			}
		}

void ListaPiezas::anularenroque(pieza *pi, int fil, int col) {

	//Si la pieza que se mueve es una torre
	if (pi->getpieza() == TORRE) {
		//Si pertence al equipo A
		if (pi->getequipo() == EQUIPO_A) {
			//Desactiva la flag de enroque  segun la torre que se mueva
			if (pi->getColumna() == 1) {
				Torre_B_Izq = false;
			}
			if (pi->getColumna() == 8) {
				Torre_B_Drh = false;
			}
		}
		//Si pertence al equipo B
		if (pi->getequipo() == EQUIPO_B) {
			//Desactiva la flag de enroque  segun la torre que se mueve
			if (pi->getColumna() == 1) {
				Torre_A_Izq = false;
			}
			if (pi->getColumna() == 8) {
				Torre_A_Drh = false;
			}
		}
	}
	//Si la pieza que se mueve es un rey
	if (pi->getpieza() == REY) {
		//Desactiva la flag de enroque segun el rey que se mueva
		if ((pi->getFila() == 8) && (pi->getColumna() == 5))Enroque_rey_A = true;
		if ((pi->getFila() == 1) && (pi->getColumna() == 5))Enroque_rey_B = true;
	}
}

void ListaPiezas::comer(int fil,int col) {

	//Busca la pieza en la casilla
	pieza* comida = piezaseleccionada(fil, col);
	int posicion = -1;
	//Si hay una pieza en la casilla
	if (comida != nullptr) {
		//Busca la pieza en la lista
		for (int i = 0; i < numero; i++) {
			if ((lista[i]->getFila() == comida->getFila()) && (lista[i]->getColumna() == comida->getColumna())) {
				posicion = i;
				piezaComida = true;
				//Elimina la pieza de la lista
				eliminarPieza(posicion);
			}
		}
	}
	else return;
}

bool ListaPiezas::jaque(equipos equipo) {
	
		pieza* rey = nullptr;

		//Busca el rey de mi equipo en la lista
		for (int i = 0; i < numero; i++) {
			if (lista[i]->getequipo() == equipo && lista[i]->getpieza() == REY) {
				rey = lista[i];
			}
		}
		
		//Mira para todas las piezas del equipo contrario que no sean reyes si pueden comer a mi rey
		for (int i = 0; i < numero; i++) {
			if (lista[i]->getequipo() != equipo && lista[i]->getpieza() != REY) {
				if (lista[i]->desplazamientovalido(rey->getFila(), rey->getColumna()) == 1) {
						if (colisionpieza(lista[i], rey->getFila(), rey->getColumna()) == 0)return true;//Si pueden comer
				}
			}
		}
		return false;
}
bool ListaPiezas::jaqueposible(pieza* pi, int fil, int col) {

	int fila_inicial = pi->getFila();
	int col_inicial = pi->getColumna();

	pieza* rey_mio = nullptr;


	//Buscar al rey de mi equipo
	for (int j = 0; j < numero; j++) {
		if (lista[j]->getequipo() == pi->getequipo() && lista[j]->getpieza() == REY) {
			rey_mio = lista[j];
		}
	}

	//Buscar si hay pieza en la casilla
	pieza* pieza_rival = piezaseleccionada(fil, col);

	if (pieza_rival != nullptr) {


		//Mueve la pieza rival fuera del tablero
		pieza_rival->setFila(10);
		pieza_rival->setColumna(10);


		pi->setFila(fil);
		pi->setColumna(col);

		//Si hay jaque
		if (jaque(rey_mio->getequipo()) == 1) {

			//Devuelve la pieza rival a la posicion de inicio
			pieza_rival->setFila(fil);
			pieza_rival->setColumna(col);

			//Devuelve la pieza a la posicion de inicio
			pi->setFila(fila_inicial);
			pi->setColumna(col_inicial);

			return true;
		}
		else {
			//Devuelve la pieza rival a la posicion de inicio
			pieza_rival->setFila(fil);
			pieza_rival->setColumna(col);

			//Devuelve la pieza a la posicion de inicio
			pi->setFila(fila_inicial);
			pi->setColumna(col_inicial);

			return false;
		}
	}

	// Si no hay una pieza en esa posicion
	else if (pieza_rival == nullptr) {

		//mueve la pieza a la posicion deseada
		pi->setFila(fil);
		pi->setColumna(col);

		//Comprueba si hay jaque y yo no estoy en jaque
		if (jaque(rey_mio->getequipo()) == 1) {

			//Devuelve la pieza a la posicion de inicio
			pi->setFila(fila_inicial);
			pi->setColumna(col_inicial);

			return true;
		}
		else {

			//Devuelve la pieza a la posicion de inicio
			pi->setFila(fila_inicial);
			pi->setColumna(col_inicial);

			return false;
		}		
	}
}

bool ListaPiezas::JaqueMate(equipos equipo) {

	//Mira para todas las piezas de mi equipo si pueden realizar algun movimiento para que no haya jaque
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getequipo() == equipo) {
			for (int fil = 1; fil < 9; fil++) {
				for (int col = 1; col < 9; col++) {
					if (movimientovalido(lista[i], fil, col))
						return false;//Si pueden realizar algun movimiento
				}
			}
		}
	}
	return true;//No pueden realizar ningun movimiento
}

void ListaPiezas::dibujarmovimientosposibles(pieza* pi) {

	//Dibuja todos los movimientos de la pieza seleccionada para todas las casillas del tablero
	for (int fil = 1; fil < 9; fil++) {
		for (int col = 1; col < 9; col++) {
			if (movimientovalido(pi, fil, col) == 1)dibujarbalon(col, fil);
		}
	}
}

void ListaPiezas::dibujarmovpos(pieza* pi, int fil, int col) {
	switch (turno) {
	case EQUIPO_A:
		dibujarmovimientosposibles(pi);
		break;

	case EQUIPO_B:
		dibujarmovimientosposibles(pi);
		break;
	}
}
void ListaPiezas::dibujarmovs() {
	pieza* pi = piezaseleccionada(casillay1, casillax1);
	if (pi != nullptr) {
		if (seleccion == COORD_INI) {
			dibujarmovpos(pi, casillay, casillax);
		}
	}
}
void ListaPiezas::seleccionPromocion(int button, int state, int x, int y) {
	if ((button == GLUT_LEFT_BUTTON) && (state == GLUT_DOWN)) {
		std::cout << x << " , " << y << std::endl;
		if (x >= 852 && x <= 905 && y >= 569 && y <= 623) {
			//dama
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pDAMA;
			wait = true;
			std::cout << "wait true" << std::endl;
		}
		if (x >= 911 && x <= 962 && y >= 569 && y <= 621) {
			//torre
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pTORRE;
			wait = true;
		}
		if (x >= 853 && x <= 904 && y >= 628 && y <= 680) {
			//alfil
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pALFIL;
			wait = true;
		}
		if (x >= 910 && x <= 963 && y >= 629 && y <= 680) {
			//caballo
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pCABALLO;
			wait = true;
		}
		if (x >= 89 && x <= 142 && y >= 569 && y <= 622) {
			//dama
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pDAMA;
			wait = true;
			std::cout << "wait true" << std::endl;
		}
		if (x >= 29 && x <= 82 && y >= 568 && y <= 621) {
			//torre
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pTORRE;
			wait = true;
		}
		if (x >= 90 && x <= 141 && y >= 628 && y <= 680) {
			//alfil
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pALFIL;
			wait = true;
		}
		if (x >= 31 && x <= 82 && y >= 629 && y <= 680) {
			//caballo
			SetCursor(LoadCursor(NULL, IDC_HAND));
			promo = pCABALLO;
			wait = true;
		}
	}
}
bool ListaPiezas::comprobarPromocion(pieza* pi, int fil, int col) {
	if (pi->getpieza() != PEON) {
		return false;
	}
	if (pi->getequipo() == EQUIPO_A) {
		if (pi->getFila() == 8) {
			if (promo == pDAMA) {
				agregarDama(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				std::cout << "spawn de dama";
				eliminarPieza(pi);
			}
			if (promo == pTORRE) {
				agregarTorre(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
			if (promo == pALFIL) {
				agregarAlfil(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
			if (promo == pCABALLO) {
				agregarCaballo(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
				return true;
		}
		else return false;
	}
	if (pi->getequipo() == EQUIPO_B) {
		if (pi->getFila() == 1) {
			if (promo == pDAMA) {
				agregarDama(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				std::cout << "spawn de dama";
				eliminarPieza(pi);
			}
			if (promo == pTORRE) {
				agregarTorre(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
			if (promo == pALFIL) {
				agregarAlfil(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
			if (promo == pCABALLO) {
				agregarCaballo(pi->getPais(), pi->getequipo(), pi->getFila(), pi->getColumna());
				eliminarPieza(pi);
			}
			//esperar();
			return true;
		}
		else return false;
	}
}
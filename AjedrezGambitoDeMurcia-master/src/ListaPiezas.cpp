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
}

ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < MAX_PIEZAS; i++) {
		delete lista[i];
	}
	numero = 0;
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
			break;
		case COORD_DEST:
			casillax1 = (x - 207) * 8 / (791 - 207) + 1;
			casillay1 = (y - 67) * 8 / (651 - 67) + 1;
			seleccion = COORD_INI;
			//dibujarmovposibles(casillay1, casillax1);
			break;
		}
	}
}
bool ListaPiezas::colisionalfil(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

		if ((desfilas > 0) && (descolumnas > 0)) {
			for (i = pi->getFila()+1, j = pi->getColumna()+1; i < fil, j < col; i++, j++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if ((desfilas < 0) && (descolumnas > 0)) {
			for (i = pi->getFila()-1, j = pi->getColumna()+1; i > fil, j < col; i--, j++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if ((desfilas < 0) && (descolumnas < 0)) {
			for (i = pi->getFila()-1, j = pi->getColumna()-1; i > fil, j > col; i--, j--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if ((desfilas > 0) && (descolumnas < 0)) {
			for (i = pi->getFila()+1, j = pi->getColumna()-1; i < fil, j > col; i++, i--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		return false;
}

bool ListaPiezas::colisiontorre(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

		if (descolumnas > 0) {
			for (i = pi->getFila(), j = pi->getColumna()+1; j < col; j++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if (descolumnas < 0) {
			for (i = pi->getFila(), j = pi->getColumna()-1; j > col; j--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if (desfilas > 0) {
			for (i = pi->getFila()+1, j = pi->getColumna(); i < fil; i++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
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

	//Movimientos de alfil
	if ((desfilas > 0) && (descolumnas > 0)) {
		for (i = pi->getFila()+1, j = pi->getColumna()+1; i < fil, j < col; i++, j++) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if ((desfilas < 0) && (descolumnas > 0)) {
		for (i = pi->getFila()-1, j = pi->getColumna()+1; i > fil, j < col; i--, j++) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if ((desfilas < 0) && (descolumnas < 0)) {
		for (i = pi->getFila()-1, j = pi->getColumna()-1; i > fil, j > col; i--, j--) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if ((desfilas > 0) && (descolumnas < 0)) {
		for (i = pi->getFila()+1, j = pi->getColumna()-1; i < fil, j > col; i++, i--) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}

	//movimientos de torre
	if (descolumnas > 0) {
		for (i = pi->getFila(), j = pi->getColumna()+1; j < col; j++) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if (descolumnas < 0) {
		for (i = pi->getFila(), j = pi->getColumna()-1; j > col; j--) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if (desfilas > 0) {
		for (i = pi->getFila()+1, j = pi->getColumna(); i < fil; i++) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	if (desfilas < 0) {
		for (i = pi->getFila()-1, j = pi->getColumna(); i > fil; i--) {
			if (piezaencasilla(i, j) == 1)return true;
		}
	}
	return true;
}

bool ListaPiezas::colisionpeon(pieza* pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();
	int i, j;

	if (pi->getequipo() == EQUIPO_A) {

		if ((desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() + 1, pi->getColumna()) == 1)return true;
		}
		if ((desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()+1, j = pi->getColumna(); i < fil; i++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if ((desfilas == 1) && (descolumnas == 1)) {
			if (piezaencasilla(fil, col) == 1)return true;
			return false;
		}
		if ((desfilas == 1) && (descolumnas == -1)) {
			if (piezaencasilla(fil, col) == 1)return true;
			return false;
		}
		return false;
	}
	else if (pi->getequipo() == EQUIPO_B) {

		if ((-desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() - 1, pi->getColumna()) == 1)return true;
		}
		if ((-desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()-1, j = pi->getColumna(); i > fil; i--) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if ((-desfilas == 1) && (-descolumnas == 1)) {
			if (piezaencasilla(fil, col) == 1)return true;
			return false;
		}
		if ((-desfilas == 1) && (-descolumnas == -1)) {
			if (piezaencasilla(fil, col) == 1)return true;
			return false;
		}
		return false;
	}
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
		//resul = colisionreina(pi, fil, col);
		//return resul;
		return false;
	}
	if (pi->getpieza() == CABALLO) {
		return false;
	}
	if (pi->getpieza() == REY) {
		return false;
	}
}

pieza* ListaPiezas::piezaseleccionada(int fil, int col) {
	for (int i = 0; i < numero; i++) {
		if ((lista[i]->getFila() == fil) && (lista[i]->getColumna() == col))return lista[i];
	}
	return nullptr;
}
void ListaPiezas::MoverPieza() {
	pieza* pi = piezaseleccionada(casillay1, casillax1);
	if (pi == nullptr)seleccion = COORD_DEST;
	//std::cout << pi->comprobarPieza() << std::endl;
	if (pi != nullptr) {
		if (seleccion == COORD_DEST) {
			moverPieza(pi, casillay, casillax);
		}
	}
}
bool ListaPiezas::turnocorrecto(pieza* pi) {
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
				//Si el desplazamiento invalido devuelve false
				if (pi->desplazamientovalido(fil, col) == 0)return false;
				//Si el desplazamiento es valido entonces
				if (pi->desplazamientovalido(fil, col) == 1) {
					//Si la pieza colisiona con otra en su camino devuelve false
					if (colisionpieza(pi, fil, col) == 1)return false;
					//Si la pieza no colisiona con otras entonces el movimiento es valido
					if (colisionpieza(pi, fil, col) == 0)return true;
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
				if (colisionpieza(pi, fil, col) == 0)return true;
			}
		}
	}
}
void ListaPiezas::moverPieza(pieza* pi, int fil, int col) {
	switch (turno) {
	case EQUIPO_A:
		if (movimientovalido(pi, fil, col) == 1) {
			pi->moverPieza(fil, col);
			turno = EQUIPO_B;
			ETSIDI::play("sonidos/move.mp3");
		}
		else seleccion = COORD_DEST;
		break;
	case EQUIPO_B:
		if (movimientovalido(pi, fil, col) == 1) {
			pi->moverPieza(fil, col);
			turno = EQUIPO_A;
			ETSIDI::play("sonidos/move2.mp3");
		}
		else seleccion = COORD_DEST;
		break;
	}
}

void ListaPiezas::destruirPiezas(pieza* p, int fil, int col) {
	if (colisionpieza(p, fil, col) == true) {
		eliminarPieza(p);
	}
	//delete p;
}

//void ListaPiezas::dibujarmovposibles(int fil,int col) {
//	pieza* pi = piezaseleccionada(fil, col);
//
//	int i, j;
//
//	if (pi != nullptr) {
//		if (pi->getpieza() == ALFIL) {
//			for (i = pi->getFila() - 1, j = pi->getColumna() +1; j < 8;i--, j++) {
//				if (colisionalfil(pi, i, j) == 0) {
//					dibujarbalon(i, j);
//				}
//			}
//			for (i = pi->getFila() - 1, j = pi->getColumna() - 1; j > 1; i--, j--) {
//				if (colisionalfil(pi, i, j) == 0) {
//					dibujarbalon(i, j);
//				}
//			}
//			for (i = pi->getFila() + 1, j = pi->getColumna() - 1; j > 1; i++, j--) {
//				if (colisionalfil(pi, i, j) == 0) {
//					dibujarbalon(i, j);
//				}
//			}
//			for (i = pi->getFila() - 1, j = pi->getColumna() + 1; j < 8; i--, j++) {
//				if (colisionalfil(pi, i, j) == 0) {
//					dibujarbalon(i, j);
//				}
//			}
//		}
//	}
//}
//
//void ListaPiezas::dibujarbalon(int fil, int col) {
//
//	glEnable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/balon.png").id);
//	glDisable(GL_LIGHTING);
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
//	glEnable(GL_ALPHA_TEST);
//	glAlphaFunc(GL_GREATER, 0.0);
//	glBegin(GL_POLYGON);
//
//	glTexCoord2d(0, 0);
//	glVertex3d(-4.0 + fil - 1, 4.0 - col + 1, 1.5);
//	glTexCoord2d(0, 1);
//	glVertex3d(-4.0 + fil - 1, 3.0 - col + 1, 1.5);
//	glTexCoord2d(1, 1);
//	glVertex3d(-3.0 + fil - 1, 3.0 - col + 1, 1.5);
//	glTexCoord2d(1, 0);
//	glVertex3d(-3.0 + fil - 1, 4.0 - col + 1, 1.5);
//
//	glEnd();
//	glDisable(GL_BLEND);
//	glDisable(GL_ALPHA_TEST);
//	glEnable(GL_LIGHTING);
//	glDisable(GL_TEXTURE_2D);
//	glBindTexture(GL_TEXTURE_2D, 0);
//	glEnable(GL_TEXTURE_2D);
//}
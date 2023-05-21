#include "ListaPiezas.h"
ListaPiezas::ListaPiezas() {
	numero = 0;
	for (int i = 0;i < MAX_PIEZAS;i++) {
		lista[i] = 0;
	}
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
		agregarDama(p1, EQUIPO_A, 1, 4);
		agregarDama(p2, EQUIPO_B, 8, 4);
		agregarRey(p1, EQUIPO_A, 1, 5);
		agregarRey(p2, EQUIPO_B, 8, 5);
	}
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
bool ListaPiezas::movimientovalido(pieza * pi, int fil, int col) {

	int desfilas = fil - pi->getFila();
	int descolumnas = col - pi->getColumna();

	int i, j;

	if (pi->getpieza()==ALFIL) {
		if (pi->desplazamientovalido(fil, col) == 1) {
			if ((desfilas > 0) && (descolumnas > 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil, j < col; i++, j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas < 0) && (descolumnas > 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil, j < col; i--, j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas < 0) && (descolumnas < 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil, j > col; i--, j--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas > 0) && (descolumnas < 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil, j > col; i++, i--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			return true;
		}
		else return false;
	}

	if (pi->getpieza() == TORRE) {
		if (pi->desplazamientovalido(fil, col) == 1) {
			if (descolumnas > 0) {
				for (i = pi->getFila(), j = pi->getColumna(); j < col; j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (descolumnas < 0) {
				for (i = pi->getFila(), j = pi->getColumna();j > col; j--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (desfilas > 0) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil; i++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (desfilas < 0) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil; i--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			return true;
		}
		else return false;
	}

	if (pi->getpieza() == REINA) {
		if (pi->desplazamientovalido(fil, col) == 1) {

			//Movimientos de alfil
			if ((desfilas > 0) && (descolumnas > 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil, j < col; i++, j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas < 0) && (descolumnas > 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil, j < col; i--, j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas < 0) && (descolumnas < 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil, j > col; i--, j--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if ((desfilas > 0) && (descolumnas < 0)) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil, j > col; i++, i--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}

			//movimientos de torre
			if (descolumnas > 0) {
				for (i = pi->getFila(), j = pi->getColumna(); j < col; j++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (descolumnas < 0) {
				for (i = pi->getFila(), j = pi->getColumna(); j > col; j--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (desfilas > 0) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil; i++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (desfilas < 0) {
				for (i = pi->getFila(), j = pi->getColumna(); i > fil; i--) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			return true;
		}
		else return false;
	}

	if (pi->getpieza() == PEON) {
		if (pi->desplazamientovalido(fil, col) == 1) {
			if (desfilas == 2) {
				for (i = pi->getFila(), j = pi->getColumna(); i < fil; i++) {
					if (piezaencasilla(i, j) == 1)return false;
				}
			}
			if (desfilas == 1) {
				i = pi->getFila();
				j = pi->getColumna();
				if (piezaencasilla(i + 1, j) == 1)return false;
			}
			return true;
		}
		else return false;
	}

	//Caracteristicas especiales (falta por a�adir)
	if (pi->getpieza() == CABALLO) {
		if (pi->desplazamientovalido(fil, col) == 1)return true;
		return false;
	}

	if (pi->getpieza() == REY) {
		if (pi->desplazamientovalido(fil, col) == 1)return true;
		return false;
	}
}

void ListaPiezas::moverPieza(pieza* pi, int fil, int col) {
	if (pi->desplazamientovalido(fil, col) == 1)pi->moverPieza(fil, col);
}
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
	

}

/*ListaPiezas::~ListaPiezas()
{
	for (int i = 0; i < MAX_PIEZAS; i++) {
		delete lista[i];
	}
	numero = 0;
}
*/
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
				click22 = false;	
			}
			if (turno == EQUIPO_A){
				click22 = true;
				click12 = false;
			}
			break;
		case COORD_DEST:
			casillax1 = (x - 207) * 8 / (791 - 207) + 1;
			casillay1 = (y - 67) * 8 / (651 - 67) + 1;
			seleccion = COORD_INI;
			if (piezaencasilla(casillay1, casillax1)&& turno == EQUIPO_B) {
				click1 = true;
				click2 = false; // Asegurarse de que click2 se establezca en falso en este punto
			}
			if(piezaencasilla(casillay1, casillax1) && turno == EQUIPO_A) {
				click2 = true;
				click1 = false; // Asegurarse de que click1 se establezca en falso en este punto
			}
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
		for (i = pi->getFila() + 1, j = pi->getColumna() + 1; i < fil  && j < col ; i++, j++) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	if ((desfilas < 0) && (descolumnas > 0)) {
		for (i = pi->getFila() - 1, j = pi->getColumna() + 1; i > fil  && j < col ; i--, j++) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
	if ((desfilas < 0) && (descolumnas < 0)) {
		for (i = pi->getFila() - 1, j = pi->getColumna() - 1; i > fil  && j > col ; i--, j--) {
			if (piezaencasilla(i, j) == 1) return true;
		}
	}
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

	if (pi->getequipo() == EQUIPO_A) {

		if ((desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() + 1, pi->getColumna()) == 1)return true;
		}
		if ((desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()+1, j = pi->getColumna(); i < fil; i++) {
				if (piezaencasilla(i, j) == 1)return true;
			}
		}
		if (posicion == nullptr) {
			if ((desfilas == 1) && (descolumnas == 1)) {
				return true;
			}
			if ((desfilas == 1) && (descolumnas == -1)) {
				return true;
			}
		}
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
	else if (pi->getequipo() == EQUIPO_B) {

		if ((-desfilas == 1) && (col == pi->getColumna())) {
			if (piezaencasilla(pi->getFila() - 1, pi->getColumna()) == 1)return true;
		}
		if ((-desfilas == 2) && (col == pi->getColumna())) {
			for (i = pi->getFila()-1, j = pi->getColumna(); i > fil; i--) {
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
	if ((desfilas == 0) && (descolumnas == 2))  {
			if (piezaencasilla(i, j+1) == 1)return true;
			return false;
	}
	if ((desfilas == 0) && (descolumnas == -2)) {
			if (piezaencasilla(i, j-1) == 1)return true;
			if (piezaencasilla(i, j - 3) == 1)return true;
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
	for (int i = 0; i < numero; i++) {
		if ((lista[i]->getFila() == fil) && (lista[i]->getColumna() == col)){
			aux = true;
			return lista[i];
			//if (dibujarmovposibles(lista[i]) == true)dibujarbalon(fil, col);
		}
		/*if ((lista[i]->getFila() == fil) && (lista[i]->getColumna() == col)) {
			dibujarmovposibles(lista[i], fil, col);
			return lista[i];
		}*/
	}
	return nullptr;
}
void ListaPiezas::MoverPieza() {
	
	pieza* pi = piezaseleccionada(casillay1, casillax1);
	//if (aux) dibujarmovposibles(pi);
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
								comer(pi, fil, col);
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
	case EQUIPO_A:
		
		if (movimientovalido(pi, fil, col) == 1) {
			if (enroquevalido(pi, fil, col) == 1) {
				hacerenroque(pi, fil, col);
				ETSIDI::play("sonidos/castle.mp3");
			}
			if (enroquevalido(pi, fil, col) == 0 && !piezaComida) {
				ETSIDI::play("sonidos/move1.wav");
			}
			if (piezaComida) {
				piezaComida = false;
				ETSIDI::play("sonidos/capture.mp3");
			}
				pi->moverPieza(fil, col);
				if (jaque(EQUIPO_B) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (jaque(EQUIPO_A) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (promocion(pi, fil, col))ETSIDI::play("sonidos/promote.mp3");
				turno = EQUIPO_B;
				if (JaqueMate(EQUIPO_B) == 1)std::cout << "JAQUE MATE B";
		}
		else seleccion = COORD_DEST;
		break;
	case EQUIPO_B:
		
		if (movimientovalido(pi, fil, col) == 1) {
			if (enroquevalido(pi, fil, col) == 1) { 
				hacerenroque(pi, fil, col);
				ETSIDI::play("sonidos/castle.mp3");
			}
			if (enroquevalido(pi, fil, col) == 0 && !piezaComida) {
				ETSIDI::play("sonidos/move1.wav");
			}
			if (piezaComida) {
				piezaComida = false;
				ETSIDI::play("sonidos/capture.mp3");
			}
				pi->moverPieza(fil, col);
				if (jaque(EQUIPO_A) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if (jaque(EQUIPO_B) == 1)ETSIDI::play("sonidos/move-check.mp3");
				if(promocion(pi,fil,col))ETSIDI::play("sonidos/promote.mp3");
				turno = EQUIPO_A;
				if (JaqueMate(EQUIPO_A) == 1)std::cout << "JAQUE MATE A";
		}
		else seleccion = COORD_DEST;
		break;
	}
}

/*void ListaPiezas::destruirPiezas(pieza* p, int fil, int col) {
	if (colisionpieza(p, fil, col) == true) {
		eliminarPieza(p);
	}
}*/

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
	glVertex3d(-4.0 + fil - 1, 4.0 - col + 1, 1.5);
	glTexCoord2d(0, 1);
	glVertex3d(-4.0 + fil - 1, 3.0 - col + 1, 1.5);
	glTexCoord2d(1, 1);
	glVertex3d(-3.0 + fil - 1, 3.0 - col + 1, 1.5);
	glTexCoord2d(1, 0);
	glVertex3d(-3.0 + fil - 1, 4.0 - col + 1, 1.5);

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

	if ((fil == 1) && (col == 3)) {
		torres = piezaseleccionada(1, 1);
		if (torres == nullptr)return false;
		else if (torres != nullptr) {
			if (torres->getmovimientos() != 0)return false;
			else if (torres->getmovimientos() == 0) {
					if (colisionpieza(pi,1, 2) == 1)return false;
					return true;
			}
		}
	}
	if ((fil == 1) && (col == 7)) {
		torres = piezaseleccionada(1, 8);
		if (torres == nullptr)return false;
		else if (torres != nullptr) {
			if (torres->getmovimientos() != 0)return false;
			else if (torres->getmovimientos() == 0) {
					return true;
			}
		}
	}
	if ((fil == 8) && (col == 3)) {
		torres = piezaseleccionada(8, 1);
		if (torres == nullptr)return false;
		else if (torres != nullptr) {
			if (torres->getmovimientos() != 0)return false;
			else if (torres->getmovimientos() == 0) {
					if (colisionpieza(pi, 8, 2) == 1)return false;
					return true;
			}
		}
	}
	if ((fil == 8) && (col == 7)) {
		torres = piezaseleccionada(8, 8);
		if (torres == nullptr)return false;
		else if (torres != nullptr) {
			if (torres->getmovimientos() != 0)return false;
			else if (torres->getmovimientos() == 0) {
					return true;
			}
		}
	}
	return false;
}
//
void ListaPiezas::hacerenroque(pieza* pi, int fil, int col) {

	if(pi->getpieza()==REY){

		if ((fil == 1) && (col == 3)) {
			if (enroquevalido(pi,fil,col) == 1) {
				pieza* torr = piezaseleccionada(1, 1);
				torr->moverPieza(1, 4);
			}
		}
		if ((fil == 1) && (col == 7)) {
			if (enroquevalido(pi,fil,col) == 1) {
				pieza* torr = piezaseleccionada(1, 8);
				torr->moverPieza(1, 6);
			}
		}
		if ((fil == 8) && (col == 3)) {
			if (enroquevalido(pi,fil,col) == 1) {
				pieza* torr = piezaseleccionada(8, 1);
				torr->moverPieza(8, 4);
			}
		}
		if ((fil == 8) && (col == 7)) {
			if (enroquevalido(pi,fil,col) == 1) {
				pieza* torr = piezaseleccionada(8, 8);
				torr->moverPieza(8, 6);
			}
		}
	}
}

/*void ListaPiezas::jaque(equipos equipo)
{
	bool jaqueEquipo_A = false;
	bool jaqueEquipo_B = false;
	
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getpieza() == REY && lista[i]->getequipo() != equipo) {
			if (equipo == EQUIPO_A) {
				jaqueEquipo_B = true;
				ETSIDI::play("sonidos/jaque.mp3");
			}
			if (equipo == EQUIPO_B) {
				jaqueEquipo_A = true;
				ETSIDI::play("sonidos/jaque.mp3");
			}
		}
	}
}*/

void ListaPiezas::comer(pieza* pi, int fil,int col) {

	pieza* comida = piezaseleccionada(fil, col);
	int posicion = -1;
		for (int i = 0; i < numero; i++) {
			if ((lista[i]->getFila() == comida->getFila()) && (lista[i]->getColumna() == comida->getColumna())) {
				posicion = i;
				piezaComida = true;
				eliminarPieza(posicion);
			}
		}
}

/*bool ListaPiezas::jaqueMate(equipos equipo)
{
	bool PosibleJaqueMate = false;
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getequipo() == equipo) {
			for (int fil = 1; fil < 9; fil++) {
				for (int col = 1; col < 9; col++) {
					if (movimientovalido(lista[i], fil, col)) {
						PosibleJaqueMate = true;
					}
				}
			}
		}
	}
	if (PosibleJaqueMate == true) {
		return false;
	}
	else return true;
}*/

/*void ListaPiezas::dibujarmovposibles(pieza* pi)
{
	int i = 0;
	for (int fila = 1; fila <= 8; fila++) {
		for (int colu = 1; colu <= 8; colu++) {
			if (movimientovalido(pi,fila,colu)) {
				Coordenadas aux(fila, colu);
				vector[i] = aux;
				i++;
				dibujarbalon(fila, colu);
			}
		}
	}

}*/
bool ListaPiezas::dibujarmovposibles(pieza* pi)
{
	//pieza* pi = nullptr;
	for (int i = 0; i < numero; i++) {
		int fil = lista[i]->getFila();
		int col = lista[i]->getColumna();
		if (lista[i]->desplazamientovalido(pi->getFila(), pi->getColumna()) == 1) {
			if (colisionpieza(lista[i], pi->getFila(), pi->getColumna()) == 0)return true;
		}
	}
	return false;

}

bool ListaPiezas::jaque(equipos equipo) {
	
		pieza* rey = nullptr;

		for (int i = 0; i < numero; i++) {
			if (lista[i]->getequipo() == equipo && lista[i]->getpieza() == REY) {
				rey = lista[i];
			}
		}

		/*if (rey == nullptr) {
			return false;
		}
		*/
		
		for (int i = 0; i < numero; i++) {
			if (lista[i]->getequipo() != equipo && lista[i]->getpieza() != REY) {
				int fil = lista[i]->getFila();
				int col = lista[i]->getColumna();
				if (lista[i]->desplazamientovalido(rey->getFila(), rey->getColumna()) == 1) {
						if (colisionpieza(lista[i], rey->getFila(), rey->getColumna()) == 0)return true;
				}
			}
		}
		return false;
}
bool ListaPiezas::promocion(pieza* pi, int fil, int col) {
	if (pi->getpieza() != PEON) {
		return false;
	}
	if (pi->getequipo() == EQUIPO_A) {
		if (pi->getFila() == 8) {
			agregarDama(pi->getPais(), EQUIPO_A, pi->getFila(), pi->getColumna());
			eliminarPieza(pi);
			return true;
		}
		else return false;
	}
	if (pi->getequipo() == EQUIPO_B) {
		if (pi->getFila() == 1) {
			agregarDama(pi->getPais(), EQUIPO_B, pi->getFila(), pi->getColumna());
			eliminarPieza(pi);
			return true;
		}
		else return false;
	}
}

bool ListaPiezas::jaqueposible(pieza* pi, int fil, int col) {

	int fila_inicial = pi->getFila();
	int col_inicial = pi->getColumna();

	/*pieza* rey_rival = nullptr;

	//Buscar al rey rival
	for (int i = 0; i < numero; i++) {
		if (lista[i]->getequipo() != pi->getequipo() && lista[i]->getpieza() == REY) {
			rey_rival = lista[i];
		}
	}*/

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

	for (int i = 0; i < numero; i++) {
		if (lista[i]->getequipo() == equipo) {
			for (int fil = 1; fil < 9; fil++) {
				for (int col = 1; col < 9; col++) {
					if (movimientovalido(lista[i],fil,col)==1)return false;
				}
			}
			return true;
		}
	}
}


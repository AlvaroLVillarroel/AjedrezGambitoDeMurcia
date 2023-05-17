#include "ListaPiezas.h"
ListaPiezas::ListaPiezas() {
	numero = 0;
	for (int i = 0;i < MAX_PIEZAS;i++) {
		lista[i] = 0;
	}
}
bool ListaPiezas::agregar(pieza*p) {
	if (numero < MAX_PIEZAS) {
		lista[numero++] = p; // último puesto sin rellenar
		return true;
	}
	else
		return false; // capacidad máxima alcanzada
	for (int i = 0; i < numero;i++) {
		for (int j = 0;j < numero; j++) {
			if (i != j) {
				if ((lista[i]) == (lista[j])) {
					return false;
				}
			}
		}
	}
}
void ListaPiezas::dibuja()
{
	for (int i = 0;i < numero;i++)
		lista[i]->dibujarPieza();
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

#include "ListaPiezas.h"
ListaPiezas::ListaPiezas() {
	numero = 0;
	for (int i = 0;i < MAX_PIEZAS;i++) {
		lista[i] = 0;
	}
}
bool ListaPiezas::agregar(pieza*p) {
	if (numero < MAX_PIEZAS) {
		lista[numero++] = p; // �ltimo puesto sin rellenar
		return true;
	}
	else
		return false; // capacidad m�xima alcanzada
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
#pragma once
#include "pieza.h"
class torre : public pieza
{

public:
	torre(paises pais, equipos equipo, tipoPieza pieza, Coordenadas coord);
	torre();
	void dibujarPieza();
};


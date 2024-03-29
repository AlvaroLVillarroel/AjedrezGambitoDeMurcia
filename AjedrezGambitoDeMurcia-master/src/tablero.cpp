#include <iostream>
#include "freeglut.h"
#include "tablero.h"
#include "coordenadas.h"


void Tablero::inicializa() {
    jugador1.setPos(-5, 0);
    jugador2.setPos(5, 0);
    piezas.setTurno(EQUIPO_B);
    if (!damaslocas)piezas.lista_inicial(pa1, pa);
    else piezas.damasLocas(pa1, pa);
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            if ((i == 0) || (i == 1) || (i == 6) || (i == 7)) {
                posiciones[i][j] = 1;
            }
            else {
                posiciones[i][j] = 0;
            }
        }
    }
   
}
void Tablero::dibujarTablero() {
    piezas.dibuja();
    piezas.dibujarmovs();
    piezas.dibujarPuntito();


	int i, j;
    //resizeTablero(tecla);
    //cord.setCord();
   // glTranslatef(0.5f, -0.5f, 0.0f);
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        for (j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0)
            {
                glColor3ub(0, 0, 0);
            }
            else
            {
                glColor3ub(255, 255, 255);
            }
            GLfloat x=(float)i, y =(float)j;
            glTranslatef(-4.0, -4.0, 0);
            glBegin(GL_QUADS);
            glVertex3f(x,y,+1);
            glVertex3f(x+1,y,+1);
            glVertex3f(x+1,y+1,+1);
            glVertex3f(x,y+1,+1);
            glEnd();
            glTranslatef(4.0, 4.0, 0);
            //dibujarCoordenadasx(i);
            //dibujarCoordenadasy(j);
            glEnable(GL_LIGHTING);
           
        }
        
    }

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
        
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/tab.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(-4.0f, -4.0f, 1.5f);
    glTexCoord2d(1, 1); glVertex3f(4.0f, -4.0f, 1.5f);
    glTexCoord2d(1, 0); glVertex3f(4.0f, 4.0f, 1.5f);
    glTexCoord2d(0, 0); glVertex3f(-4.0f, 4.0f, 1.5f);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/fondoTablero12.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(-7.6f, -5.5f, 0.0f);
    glTexCoord2d(1, 1); glVertex3f(7.6f, -5.5f, 0.0f);
    glTexCoord2d(1, 0); glVertex3f(7.6f, 5.5f, 0.0f);
    glTexCoord2d(0, 0); glVertex3f(-7.6f, 5.5f, 0.0f);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    
    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/marcotab31.png").id);
    glDisable(GL_LIGHTING);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(-4.5f, -4.5f, 1.5f);
    glTexCoord2d(1, 1); glVertex3f(4.5f, -4.5f, 1.5f);
    glTexCoord2d(1, 0); glVertex3f(4.5f, 4.5f, 1.5f);
    glTexCoord2d(0, 0); glVertex3f(-4.5f, 4.5f, 1.5f);
    glEnd();
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);

    glEnable(GL_TEXTURE_2D);
    glColor3f(1, 1, 1);

    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/letrapausa.png").id);
    glDisable(GL_LIGHTING);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.0);
    glBegin(GL_POLYGON);
    glTexCoord2d(0, 1); glVertex3f(-7.1f, -6.7f, 2.0f);
    glTexCoord2d(1, 1); glVertex3f(-3.3f, -6.7f, 2.0f);
    glTexCoord2d(1, 0); glVertex3f(-3.3f, -2.4f, 2.0f);
    glTexCoord2d(0, 0); glVertex3f(-7.1f, -2.4f, 2.0f);

    glEnd();
    glDisable(GL_BLEND);
    glDisable(GL_ALPHA_TEST);
    glEnable(GL_LIGHTING);
    glDisable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, 0);
    
   
}

void Tablero::dibujarJugadores()
{
    jugador1.dibuja();

    jugador2.dibuja();
    
    Vector2d d1 = jugador1.getPos();
    Vector2d d2 = jugador2.getPos();

    if (piezas.click1) {
        jugador1.setVel(0.0f, -4.5f);
        if (d1.y < -4) {
            jugador1.setVel(0, 0);
            d1.y = 0;
            piezas.click1 = false; // Actualizar el estado de piezas.click1
        }
    }

    if (piezas.click12) {
        jugador1.setVel(0.0f, 4.5f);
        if (d1.y > 0) {
            jugador1.setVel(0.0f, 0.0f);
            //d1.y = 0;
            piezas.click12 = false;
            piezas.click1 = false;// Actualizar el estado de piezas.click12
        }
    }
    if (piezas.click2) {
        jugador2.setVel(0.0f, 4.5f);
        if (d2.y > 4) {
            jugador2.setVel(0, 0);
            d2.y = 0;
            piezas.click2 = false; // Actualizar el estado de piezas.click2
        }
    }

    if (piezas.click22) {
        jugador2.setVel(0.0f, -4.5f);
        if (d2.y < 0) {
            jugador2.setVel(0.0f, 0.0f);
            d2.y = 0;
            piezas.click22 = false;
            piezas.click2 = false;// Actualizar el estado de piezas.click22
        }
    }
}


void Tablero::juega(int button, int state, int x, int y) {
    piezas.mousePress(button, state, x, y);
    piezas.MoverPieza();
    piezas.seleccionPromocion(button, state, x, y);
}

void Tablero::mueve()
{
    jugador1.mueve(0.025f);
    jugador2.mueve(0.025f);
}
void Tablero::dibujarPromocion()
{
        //TURNO A
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);

        glScalef(0.8f, 0.8f, 1);
    if (piezas.getTurno() == EQUIPO_B) {
        glPushMatrix();
        glTranslatef(1.7, -4.8, 0);
        if (pa == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promospain.png").id);
        if (pa == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promojapan.png").id);
        if (pa == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promobrazil.png").id);
        if (pa == PORTUGAL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promoportugal.png").id);
        if (pa == ARGENTINA) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promoargentina.png").id);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glTexCoord2d(0, 1); glVertex3f(4.05f, -0.6f, 1.9f);
        glTexCoord2d(1, 1); glVertex3f(6.05f, -0.6f, 1.9f);
        glTexCoord2d(1, 0); glVertex3f(6.05f, 1.4f, 1.9f);
        glTexCoord2d(0, 0); glVertex3f(4.05f, 1.4f, 1.9f);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix();
        glEnable(GL_TEXTURE_2D);
        glColor3f(1, 1, 1);
    }
    if (piezas.getTurno() == EQUIPO_A) {
        glPushMatrix();
        //TURNO B
        if (pa1 == SPAIN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promospain.png").id);
        if (pa1 == JAPAN) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promojapan.png").id);
        if (pa1 == BRAZIL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promobrazil.png").id);
        if (pa1 == PORTUGAL) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promoportugal.png").id);
        if (pa1 == ARGENTINA) glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/promocion/promoargentina.png").id);
        glTranslatef(-1.4, -4.4, 0);
        glDisable(GL_LIGHTING);
        glBegin(GL_POLYGON);
        glTexCoord2d(0, 1); glVertex3f(-4.45f, -1.0f, 1.9f);
        glTexCoord2d(1, 1); glVertex3f(-6.45f, -1.0f, 1.9f);
        glTexCoord2d(1, 0); glVertex3f(-6.45f, 1.0f, 1.9f);
        glTexCoord2d(0, 0); glVertex3f(-4.45f, 1.0f, 1.9f);
        glEnd();
        glEnable(GL_LIGHTING);
        glDisable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D, 0);
        glPopMatrix();
    }
}

void Tablero::reiniciarTablero() {
    piezas.destruirPiezas();
}
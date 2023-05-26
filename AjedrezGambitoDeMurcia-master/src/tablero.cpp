#include <iostream>
#include "freeglut.h"
#include "tablero.h"
#include "coordenadas.h"


void Tablero::inicializa() {
  
    piezas.lista_inicial(pa1, pa);
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
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/fondoTablero1.png").id);
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
    

}
void Tablero::juega(int button, int state, int x, int y) {
    piezas.mousePress(button, state, x, y);
    piezas.MoverPieza();
}
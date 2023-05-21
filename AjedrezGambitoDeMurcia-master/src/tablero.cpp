#include <iostream>
#include "freeglut.h"
#include "tablero.h"
#include "coordenadas.h"


void Tablero::inicializa() {
    piezas.lista_inicial(JAPAN, SPAIN);
    f1c3.inicializa(SPAIN, EQUIPO_A, ALFIL, 1, 3);
    f1c6.inicializa(SPAIN, EQUIPO_A, ALFIL, 1, 6);
    f8c3.inicializa(BRAZIL, EQUIPO_B, ALFIL, 8, 3);
    f8c6.inicializa(BRAZIL, EQUIPO_B, ALFIL, 8, 6);
    Cb8.inicializa(SPAIN, EQUIPO_A, CABALLO, 1, 2);
    Cg8.inicializa(SPAIN, EQUIPO_A, CABALLO, 1, 7);
    Cb1.inicializa(ARGENTINA, EQUIPO_B, CABALLO, 8, 2);
    Cg1.inicializa(ARGENTINA, EQUIPO_B, CABALLO, 8, 7);
    f1cd.inicializa(SPAIN, EQUIPO_A, REINA, 1, 4);
    f8cd.inicializa(JAPAN, EQUIPO_B, REINA, 8, 4);
    f1ce.inicializa(SPAIN, EQUIPO_A, REY, 1, 5);
    f8ce.inicializa(PORTUGAL, EQUIPO_B, REY, 8, 5);

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
    f1c3.dibujarPieza();
    f1c6.dibujarPieza();
    f8c3.dibujarPieza();
    f8c6.dibujarPieza();
    Cb8.dibujarPieza();
    Cg8.dibujarPieza();
    Cb1.dibujarPieza();
    Cg1.dibujarPieza();
    f1cd.dibujarPieza();
    f8cd.dibujarPieza();
    f1ce.dibujarPieza();
    f8c3.dibujarPieza();
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
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/fondoTablero.png").id);
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
    glBindTexture(GL_TEXTURE_2D, ETSIDI::getTexture("fotos/marcotab3.png").id);
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
    
    /*glColor3ub(128, 64, 0);
    glTranslatef(-4.5, -3.5, 0);
    glBegin(GL_QUADS);
    glVertex3f(x1-0.5, y1-0.5, -1);
    glVertex3f(x2+0.5, y1-0.5,-1);
    glVertex3f(x2 + 0.5, y2 + 0.5, -1);
    glVertex3f(x1-0.5, y2+0.5, 0);
    glEnd();
    glEnable(GL_LIGHTING);
    //cord.dibujarPrueba();
    glTranslatef(4.5, 3.5, 1);
    glDepthRange(0, 0.5);
    */

}


/*void Tablero::resizeTablero(unsigned char key) {
    if (key == 'm') {
        flagrz++;
        a +=0.5;
    }
    if (flagrz == 3) {
        flagrz = 0;
            a = 1.5;
    }
    glScalef(a, a, 0);
    tecla = key;

    //prueba.dibujarPieza();
}
/void Tablero::arrayCasillas(int a, int b) {
    filas[a];
    columnas[b];
}
void Tablero::dibujarCoordenadasx(int a) {
    glColor3ub(255, 255, 255);
    glRasterPos2f(a- 4, -3.9);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, filas[a]);
}
void Tablero::dibujarCoordenadasy(int a) {
    glColor3ub(255, 255, 255);
    glRasterPos2f(+3.7, a- 3);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, columnas[a]);
}*/
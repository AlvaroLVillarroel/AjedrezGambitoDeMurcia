#include <iostream>
#include "freeglut.h"
#include "tablero.h"
#include "coordenadas.h"

alfil f1c3(SPAIN, EQUIPO_A, ALFIL, 1, 3);
alfil f1c6(SPAIN, EQUIPO_A, ALFIL, 1, 6);
alfil f8c3(SPAIN, EQUIPO_B, ALFIL, 8, 3);
alfil f8c6(SPAIN, EQUIPO_B, ALFIL, 8, 6);

void Tablero::dibujarTablero() {
    prueba.dibujarPieza();
	int i, j;
    //resizeTablero(tecla);
    //cord.setCord();
    for (i = 0; i < 8; i++)
    {
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
            glTranslatef(-4.5, -3.5, 0);
            glBegin(GL_QUADS);
            glVertex3f(x,y,+1);
            glVertex3f(x+1,y,+1);
            glVertex3f(x+1,y+1,+1);
            glVertex3f(x,y+1,+1);
            glEnd();
            glTranslatef(4.5, 3.5, 0);
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
    glTexCoord2d(0, 1); glVertex3f(-4.5f, -3.5f, 1.5f);
    glTexCoord2d(1, 1); glVertex3f(3.5, -3.5, 1.5f);
    glTexCoord2d(1, 0); glVertex3f(3.5f, 4.5f, 1.5f);
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
/*void Tablero::arrayCasillas(int a, int b) {
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
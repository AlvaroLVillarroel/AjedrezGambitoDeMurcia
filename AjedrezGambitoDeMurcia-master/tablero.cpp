#include <iostream>
#include "freeglut.h"
#include "tablero.h"
#include "coordenadas.h"



void Tablero::dibujarTablero() {
	int i, j;
    resizeTablero(tecla);
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
            dibujarCoordenadasx(i);
            dibujarCoordenadasy(j);
            glEnable(GL_LIGHTING);
        }
    }
    glColor3ub(128, 64, 0);
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
    

    prueba.dibujarPieza();
}
void Tablero::resizeTablero(unsigned char key) {
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
}
void Tablero::arrayCasillas(int a, int b){
    filas[a];
    columnas[b];
}
void Tablero::dibujarCoordenadasx(int a){
    glColor3ub(255, 255, 255);
    glRasterPos2f(a- 4, -3.9);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, filas[a]);
}
void Tablero::dibujarCoordenadasy(int a) {
    glColor3ub(255, 255, 255);
    glRasterPos2f(+3.7, a- 3);
    glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, columnas[a]);
}
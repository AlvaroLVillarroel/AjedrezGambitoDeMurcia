#include <iostream>
#include "freeglut.h"
#include "coordenadas.h"
void Coordenadas::setCord() {
    int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
        {
            x[i][j]= 3+i;
            y[i][j]= 3+j;
        }
    }
}
void Coordenadas::dibujarPrueba() {
  int i, j;
    for (i = 0; i < 8; i++) {
        for (j = 0; j < 8; j++)
        {
            glColor3ub(0, 0, 255);
            glTranslatef(x[i][j], y[i][j], 5);
            glutSolidCube(0.1);
            glTranslatef(-x[i][j],-y[i][j],5);
            glEnable(GL_LIGHTING);
        }
    }
}
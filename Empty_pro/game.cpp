#include <windows.h>
#include <gl/Gl.h>
#include <glut.h>
#include "game.h"

int gridx,gridy;

void inirGrid(int x, int y) {

	gridx = x;
	gridy = y;
}

void drawGrid() {

}

void unit(int x, int y) {

	glBegin(GL_LINE_LOOP);


	glEnd();

}
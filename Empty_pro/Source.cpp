// Includes
#include <windows.h>
#include <gl/Gl.h>
#include <glut.h>
#include "game.h"


#define columns 40
#define rows 40

// Function Decleration
void myInit();
void myDisplay();
void reshape(int,int); 

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 150); // Position the window's initial top-left corner
    glutInitWindowSize(500, 500);   // Set the window's initial width & height
    glutCreateWindow("Snake Game"); // Create a window with the given title
    glutDisplayFunc(myDisplay); // Register display callback handler for window re-paint
    glutReshapeFunc(reshape);
    myInit();
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}                              //begin..................................
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
    //glColor3f(0.0, 0.0, 0.0);
    
//glBegin();


    //glEnd();
    //glFlush();

}
void reshape(int w , int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,columns,0.0,rows,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void myInit()
{

    glClearColor(0.0, 0.0, 0.0, 1.0);
    inirGrid(columns, rows);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
}



// Includes
//#include <cstring>
#include <iostream>
#include <fstream>
//#include <sstream>

#include <windows.h>
#include <glut.h>
#include <gl/Gl.h>
#include "game.h"

//#include <math.h>
//#include <stdio.h>
//#include <string.h>





#define windowwidth 800
#define windowheight 800

#define columns windowheight/20
#define rows windowwidth/20
#define fps 5

int fpss = fps;

extern short sDiraction;
bool gameOver = false;


//int live = 3;
int score = 0;

std::ofstream ofile;
std::ifstream ifile;

// Function Decleration
void myInit();
void myDisplay();
void reshape(int,int);
void timer(int);
void mykeyboard(int, int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowPosition(100, 150); // Position the window's initial top-left corner
    glutInitWindowSize(windowwidth, windowheight);   // Set the window's initial width & height
    glutCreateWindow("Snake Game"); // Create a window with the given title
    
    glutDisplayFunc(myDisplay); 
    
    glutReshapeFunc(reshape);
    glutTimerFunc(0, timer, 0);
    glutSpecialFunc(mykeyboard);
    //timer(0);
    
    myInit();
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}                           

//begin..................................

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawGrid();
    drawfood();
    drawsnake();
    lineDenger();
    glutSwapBuffers();
    /*
    if (live == 3) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawGrid();
        drawfood();
        drawsnake();
        glutSwapBuffers();
    }
    else if (live == 2) {
        glClear(GL_COLOR_BUFFER_BIT);
        drawGrid();
        drawfood();
        drawsnake();
        glutSwapBuffers();
    }
    else {
        glClear(GL_COLOR_BUFFER_BIT);
        drawGrid();
        drawfood();
        drawsnake();
        glutSwapBuffers();
    }
      */  

    if (gameOver)
    {
        ofile.open("score.dat", std::ios::trunc);
        ofile << score << std::endl;
        ofile.close();
        ifile.open("score.dat", std::ios::in);
        char a[4];
        ifile >> a;
        std::cout << a;
        char text[50] ;
        //char txt[50] = text + a;
        //strcat(text, a);
        //sprintf_s(text, "Your score : ", a);
        MessageBoxA(NULL,a , "Your score : ", 0);

        exit(0);

        //MessageBox(NULL,L"Your Score : ", NULL, MB_OK); 
    }
    
    
     //glFlush();

}
/*
void reshape(int w , int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,columns,0.0,rows,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}
*/
void reshape(int w, int h) {

    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
    glMatrixMode(GL_PROJECTION);

    GLdouble aspect = (GLdouble)w / (GLdouble)h;
    glLoadIdentity();

    //glOrtho(0.0,columns,0.0,rows,-1.0,1.0);

    if (w >= h) {// aspect >= 1, set the height from -250 to 250, with larger width
        gluOrtho2D(0 * aspect, rows * aspect, 0, columns);
    }
    else {// aspect < 1, set the width to -1 to 1, with larger height
        gluOrtho2D(0, rows, 0 / aspect, columns / aspect);
    }
    glMatrixMode(GL_MODELVIEW);


}





void timer(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/fpss, timer, 0);

}

void mykeyboard(int key, int, int) {

    switch (key)
    {
    case GLUT_KEY_UP:
        if (sDiraction != down)
            sDiraction = up;
        break;
    case GLUT_KEY_DOWN:
        if (sDiraction != up)
            sDiraction = down;
        break;
    case GLUT_KEY_RIGHT:
        if (sDiraction != left)
            sDiraction = rigth;
        break;
    case GLUT_KEY_LEFT:
        if (sDiraction != rigth)
            sDiraction = left;
        break;
    
    }
}

void myInit()
{

    glClearColor(0.6745, 0.8431, 0.3215, 1.0);
    inirGrid(rows, columns,fps);
    glLoadIdentity();
    //gluOrtho2D(0 , rows, 0, columns);
    
}



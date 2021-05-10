// Includes
#include <windows.h>
#include <gl/Gl.h>
#include <glut.h>

// Function Decleration
void myInit();
void myDisplay();
void reshape(int, int);

int main(int argc, char** argv) {
    glutInit(&argc, argv);                 // Initialize GLUT
    glutInitDisplayMode(GLUT_RGB);
    glutInitWindowPosition(100, 150); // Position the window's initial top-left corner
    glutInitWindowSize(500, 500);   // Set the window's initial width & height
    glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
    myInit();
    glutDisplayFunc(myDisplay); // Register display callback handler for window re-paint
    glutReshapeFunc(reshape);
    glutMainLoop();           // Enter the event-processing loop
    return 0;
}                              //begin..................................
void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 0.0, 0.0);

    glBegin();


    glEnd();
    glFlush();

}

void myInit()
{

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glLoadIdentity();
    gluOrtho2D(-250, 250, -250, 250);
}

void reshape(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);

    GLfloat as = (GLfloat)w / (GLfloat)h;
    glLoadIdentity();
    if (w >= h)
    {
        gluOrtho2D(-250 * as, 250 * as, -250, 250);
    }
    else
    {
        gluOrtho2D(-250, 250, -250 / as, 250 / as);
    }
}

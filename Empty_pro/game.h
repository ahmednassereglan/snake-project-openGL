#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define up 1
#define down -1
#define rigth 2
#define left -2

#define maxx 60

//Adding Decliration
void inirGrid(int, int,int);
void drawGrid();
void drawsnake();
void drawfood();
void lineDenger();
void drawsqrss(int, int);
void random(int&,int&);
void drawShap(GLfloat center_x, GLfloat center_y, GLfloat radius, GLfloat number_of_points, GLenum drawType, GLfloat rotation);
void randomwall(int& , int& );
#endif

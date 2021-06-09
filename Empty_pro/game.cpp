#include <windows.h>
#include <gl/Gl.h>
#include <glut.h>
#include <iostream>
#include <ctime>
#include "game.h"
#include <math.h>

extern int live;



extern int score;
int gridx, gridy;

bool food = true;
int foodx, foody;

short sDiraction = rigth;

extern bool gameOver;

int snake_length = 5;
int posx[60] = { 20,20,20,20,20 }, posy[60] = { 20,19,18,17,16 };  //make snake in center of screen  (20,20)

#define PI 3.1415926535898


int wallx, wally;
bool wallflag = true;


extern int fpss;
void inirGrid(int x, int y,int z) {

	gridx = x;
	gridy = y;
	fpss = z;
}

void unit(int x, int y, GLenum mode);

void drawGrid() {

	
	
	for (int x=0 ; x < gridx ;x++) {
		for (int y=0 ; y < gridy ;y++) {
			if (((x + y) % 2) == 0) {
				glColor3f(0.6352, 0.8156, 0.2862);
				
				unit(x, y, GL_POLYGON);
			}
			else {
									          //ÑÓã ãÑÈÚÇÊ ÈÚÑÖ æØæá ÇáÔÇÔå 
				unit(x, y, GL_LINE_LOOP);
			}                                 
		} 
	}
	

}
void unit(int x, int y ,GLenum mode) {
	if (x==0 || y==0 || x==gridx-1 || y==gridy-1) {
		glLineWidth(5.0);
		glColor3f(0.0, 0.25, 0.0);   // Úãá ÝÑíã Èáæä ãÚíä
	}
	else {
		glLineWidth(0.5);
		//glColor3f(0.5,0.5,0.5);    //áæä ÇáÑÈÚÇÊ 
	}
	glBegin(mode);
	glVertex2f(x,y);
	glVertex2f(x+1,y);
	glVertex2f(x+1,y+1);
	glVertex2f(x,y+1);
	glEnd();

}

void drawfood(){

	if (food) 
		random(foodx, foody); //foodx=50,foody=50
	food = false;
		glColor3f(0.8, 0.0, 0.0);
		//glRectd(foodx, foody, foodx + 1, foody + 1);

		drawShap(foodx+0.5, foody+0.5, 0.5, 5, GL_POLYGON, PI / 2); // any shape

		/*
		glBegin(GL_POLYGON);            // triangle
		glVertex2f(foodx, foody);
		glVertex2f(foodx + 0.5, foody + 1);
		glVertex2f(foodx + 1, foody);
		glEnd();
		*/
		/*
		glBegin(GL_LINE_LOOP);            // star
		glVertex2f(foodx, foody);
		glVertex2f(foodx+0.5 ,foody+1);
		glVertex2f(foodx+1, foody);
		glVertex2f(foodx, foody+0.5);
		glVertex2f(foodx+1, foody+0.5);
		glEnd();
		*/
}



void drawsnake() {
	for (int i = snake_length - 1; i > 0;i-- )
	{
		posx[i] = posx[i - 1];
		posy[i] = posy[i - 1];
	}
	if (sDiraction == up) 
		posy[0]++;
	
	else if (sDiraction == down) 
		posy[0]--;
	
	else if (sDiraction == rigth) 
		posx[0]++;
	
	else if (sDiraction == left) 
		posx[0]--;
	
	for (int i = 0;i < snake_length;i++) {
		if(i==0)
			glColor3f(0.286, 0.4588, 0.949); //rgb 73,117,242
		else
			glColor3f(0.1215, 0.2784, 0.6588);  //rgb 31,71,168

		glRectd(posx[i], posy[i], posx[i] + 1, posy[i] + 1);   //snake	
	}


	for (int j = 1;j < snake_length;j++)
	{
		if (posx[j] == posx[0] && posy[j] == posy[0])  // snake hit his body
			//live--;
			//if (live == 0) {
				gameOver = true;
			//}
	}
	
	if (posx[0] == 0 || posx[0] == gridx - 1 || posy[0] == 0 || posy[0] == gridy - 1) {  // snake hit wall
		//gameOver = true;
		//live--;
		//if (live == 0) {
			gameOver = true;
		//}
	 }



	if (posx[0] == foodx && posy[0] == foody) {
		
		score++;
		//snake_length=snake_length+10;
		snake_length++;
		fpss = fpss + 5;
		if (snake_length > maxx)
			snake_length = maxx;
		food = true;
	}
}


void lineDenger(){
	
	if (score >= 2) {
		glColor3f(0.5490, 0.4666, 0.5411);
		for (int i = 5;i < 15;i++) {
			drawsqrss(i, 5);
			if (posx[0] == i && posy[0] == 5) {
				
					gameOver = true;
				
			}
		}

	}
	if (score >= 3) {
		for (int i = 20;i < 35;i++) {
			glColor3f(0.6745, 0.6666, 0.6901);
			drawsqrss(35, i);
			if (posx[0] == 35 && posy[0] == i) {
				gameOver = true;
			}
		}
		
	}
	if (score >= 4) {
		glColor3f(0.6745, 0.6666, 0.6901);
		for (int i = 5;i < 15;i++) {
			drawsqrss(i, 35);
			if (posx[0] == i && posy[0] == 35) {
				gameOver = true;
			}
		}
		

	}
	if (score >= 5) {
		glColor3f(0.6745, 0.6666, 0.6901);
		for (int i = 20;i < 30;i++) {
			drawsqrss(10, i);
			if (posx[0] == 10 && posy[0] == i) {
				gameOver = true;
			}
		}
	}

	if (score >= 6) {
		glColor3f(0.6745, 0.6666, 0.6901);
		for (int i = 25;i < 35;i++) {
			drawsqrss(i, 28);
			if (posx[0] == i && posy[0] == 28) {

				gameOver = true;

			}
		}

	}

	if (score >= 7) {
		glColor3f(0.6745, 0.6666, 0.6901);
		for (int i = 15;i < 30;i++) {
			drawsqrss(i, 10);
			if (posx[0] == i && posy[0] == 10) {

				gameOver = true;

			}
		}

	}

	/*
	if (score >= 0) {
		if(wallflag)
		randomwall(wallx, wally);
		wallflag = false;

			glColor3f(0.6745, 0.6666, 0.6901);
			for (int i = wallx;i < wallx +6;i++) {
			drawsqrss(i, wally);
			if (posx[0] == i && posy[0] == wally) { // hit wall you will die
				gameOver = true;
				}
			}
	}

	if (score >= 0) {
		if (wallflag)
		randomwall(wallx, wally);
		wallflag = false;

		glColor3f(0.6745, 0.6666, 0.6901);
		for (int i = wally+10;i < wally+20;i++) {
			drawsqrss(wallx, i);
			if (posx[0] == wallx && posy[0] == i) {
				gameOver = true;
			}
		}

	}
	*/


}

void drawsqrss(int x,int y) {
	glBegin(GL_POLYGON);
	glVertex2f(x, y);
	glVertex2f(x + 1, y);
	glVertex2f(x + 1, y + 1);
	glVertex2f(x, y + 1);
	glEnd();
}

void randomwall(int& x, int& y) {

	int _maxX = gridx - 7;
	int _maxY = gridy - 7;
	int _min = 1;
	srand(time(NULL));
	x = _min + rand() % (_maxX - _min);
	y = _min + rand() % (_maxY - _min);

}

void random(int &x, int &y) {
	
	int _maxX = gridx -1;
	int _maxY = gridy -1;
	int _min = 1;
	srand(time(NULL));
	x = _min+rand()%(_maxX - _min);
	y = _min+rand()%(_maxY - _min);
	
}

void drawShap(GLfloat center_x, GLfloat center_y, GLfloat radius, GLfloat number_of_points, GLenum drawType, GLfloat rotation) {
	glBegin(drawType);
	for (int i = 0; i < number_of_points; i++)
	{
		GLfloat angle = 2 * PI * i / number_of_points;//angle in radians
		glVertex2f(center_x + radius * cos(angle + rotation), center_y + radius * sin(angle + rotation));
	}
	glEnd();
}



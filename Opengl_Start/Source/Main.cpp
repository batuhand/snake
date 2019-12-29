#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GLFW/glfw3.h>
#include <gl/GL.h>
#include <gl\glut.h>
#include <gl\freeglut.h>
#include <iostream>
#include <ctime>


int x = 100, y = 250;
int counter = 0;
int direction = 6;
int heightOfSnake = 3;
int headPositionX = x;
int headPositionY = y;
int positionX[1600] = {100,75,50};
int positionY[1600] = { 250,250,250 };
bool target = true;
int targetX = 550;
int targetY = 300;
bool gameOver=false;
int score = 0;
void render_loop()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	GLint p1[4][2] = { {x,y},{ x + 25,y },{ x+25 ,y+25 },{x,y+25} };
	glColor3f(1.0f, 1.0f, 1.0f);
	//yýlanýn basýný cýzdýren kod
		glColor3f(1.0f, 1.0f, 0.0f);

	//glRectd(positionX[0],positionY[0],positionX[0]+25,positionY[0]+25);

	//glBegin(GL_LINE_LOOP);
	//glColor3f(1.0f, 1.0f, 0.0f);
	//glVertex2iv(positionX,);
	//glVertex2iv(p1[1]);
	//glVertex2iv(p1[2]);
	//glVertex2iv(p1[3]);
	//glEnd();
	glColor3f(1.0f, 1.0f, 0.0f);

	

	
	for (int i = heightOfSnake - 1; i >= 0; i--) {

		glRectd(positionX[i], positionY[i], positionX[i] + 25, positionY[i] + 25);

	}
	
	

	counter += 1;
	if (gameOver==false) {
		if (counter % 50 == 0 && direction == 6) {
			for (int i = heightOfSnake - 1; i > 0; i--) {

				positionX[i] = positionX[i - 1];
				positionY[i] = positionY[i - 1];


			}
			positionX[0] += 25;
		}
		else if (counter % 50 == 0 && direction == 4) {
			for (int i = heightOfSnake - 1; i > 0; i--) {

				positionX[i] = positionX[i - 1];
				positionY[i] = positionY[i - 1];


			}
			positionX[0] -= 25;
		}
		else if (counter % 50 == 0 && direction == 8) {
			for (int i = heightOfSnake - 1; i > 0; i--) {

				positionX[i] = positionX[i - 1];
				positionY[i] = positionY[i - 1];


			}
			positionY[0] += 25;
		}
		else if (counter % 50 == 0 && direction == 2) {
			for (int i = heightOfSnake - 1; i > 0; i--) {

				positionX[i] = positionX[i - 1];
				positionY[i] = positionY[i - 1];


			}
			positionY[0] -= 25;
		}
	}
	else {
		MessageBox(NULL,"Your Score:"+score,"GAME OVER",0);
		/*glColor3f(1.0f, 0.0f, 0.0f);
		GLbyte ad[] = { 'G','A','M','E',' ', 'O','V','E','R' };
		glRasterPos2i(450, 525);
		for (int i = 0; i < 9; i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, ad[i]);
		}
		glColor3f(1.0f, 0.0f, 0.0f);
		
		GLbyte score[] = { 'Y','O','U','R',' ', 'S','C','O','R','E',':' };
		glRasterPos2i(450, 500);
		for (int i = 0; i < sizeof(score); i++) {
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, score[i]);
		}*/
	}
	
	
	
		/*	headPositionX = x;
			headPositionY = y;
			for (int i = 1; i <= heightOfSnake - 1; i++) {

				GLint p2[4][2] = { {headPositionX,headPositionY},{ headPositionX - 25 ,headPositionY },{ headPositionX - 25 ,headPositionY + 25 },{headPositionX,headPositionY + 25} };

				glBegin(GL_LINE_LOOP);
				glColor3f(1.0f, 1.0f, 0.0f);
				glVertex2iv(p2[0]);
				glVertex2iv(p2[1]);
				glVertex2iv(p2[2]);
				glVertex2iv(p2[3]);
				glEnd();
				headPositionX = headPositionX - 25;

			}*/

	
		
		
	
	

	if (positionX[0] > 1000) {
		positionX[0] = 0;
	}
	else if (positionX[0] < 0) {
		positionX[0] = 1000;
	}
	if (positionY[0] > 1000) {
		positionY[0] = 0;
	}
	else if (positionY[0] < 0) {
		positionY[0] = 1000;
	}

	if (target != true) {
		srand(time(NULL));
		 int x = (2 + rand() % 39)*25;
		 int y = (2 + rand() % 39)*25;
		
		 targetX = x;
		 targetY = y;
			 target = true;
		 

		 //glRectd(targetX, targetY, targetX + 25, targetY + 25);

	}
	else {
		glColor3f(1.0f, 0.0f, 0.0f);

		glRectd(targetX, targetY, targetX + 25, targetY + 25);

	}
	if (positionX[0] == targetX && positionY[0] == targetY) {
		glColor3f(0.0f, 0.0f, 0.0f);
		score += 1;
		glRectd(targetX, targetY, targetX + 25, targetY + 25);
		if (heightOfSnake <= 1599) {
			switch (direction)
			{
			case 6:
				positionX[heightOfSnake] = positionX[heightOfSnake - 1] - 25;
				positionY[heightOfSnake] = positionY[heightOfSnake - 1];
			case 4:
				positionX[heightOfSnake] = positionX[heightOfSnake - 1] + 25;
				positionY[heightOfSnake] = positionY[heightOfSnake - 1];
			case 2:
				positionX[heightOfSnake] = positionX[heightOfSnake - 1];
				positionY[heightOfSnake] = positionY[heightOfSnake - 1] + 25;
			case 8:
				positionX[heightOfSnake] = positionX[heightOfSnake - 1];
				positionY[heightOfSnake] = positionY[heightOfSnake - 1] - 25;
			default:
				break;
			}

			heightOfSnake = heightOfSnake + 1;
		}
		

		target = false;
	}
	for (int i = 1; i < heightOfSnake; i++) {
		if (positionX[0]==positionX[i] && positionY[0]==positionY[i]) {
			gameOver = true;
		}
	}
	
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_LEFT && direction != 6) {
		direction = 4;

	}


	if (key == GLFW_KEY_RIGHT && direction != 4) {
		direction = 6;
	

	}
		

	if (key == GLFW_KEY_UP && direction != 2) {
		direction = 8;
	

	}
		
	if (key == GLFW_KEY_DOWN && direction != 8) {
		direction = 2;


	}
	
	
	
}
/* program entry */
int main(int argc, char *argv[])
{
	GLFWwindow* window;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		exit(EXIT_FAILURE);
	}
	glutInit(&argc, argv);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	window = glfwCreateWindow(1000, 1000, "Hareket Eden Ucgen", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "Failed to open GLFW window\n");
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);
	// set up view
	glViewport(0, 0, 1000, 1000);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	// see https://www.opengl.org/sdk/docs/man2/xhtml/glOrtho.xml
	glOrtho(0.0, 1000.0, 0.0, 1000.0, 0.0, 1.0); // this creates a canvas you can do 2D drawing on

											   // Main loop
	while (!glfwWindowShouldClose(window))
	{
		// Draw gears
		render_loop();

		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	// Terminate GLFW
	glfwTerminate();

	// Exit program
	exit(EXIT_SUCCESS);
}
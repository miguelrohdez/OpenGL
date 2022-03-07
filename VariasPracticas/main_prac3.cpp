//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************		Rojas Hernández Miguel Alejandro	******//
//*************											******//
//************************************************************//

//#include <gl/gl.h>     // The GL Header File
//#include <GL/glut.h>   // The GL Utility Toolkit (Glut) Header
//#include <stdlib.h>
#include "Main.h"

float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
int i;



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(1.0f, 1.0f, 1.0f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(int color)
{
	float colores[][3] = {
		{ 0.82 ,0.41, 0.11 },    //Cafe
		{ 0.0, 0.0, 0.0 }, //Negro
		{ 1.0, 1.0, 1.0 },  //Blanco

	};

	GLfloat vertice [8][3] = {
				{0.5 ,-0.5, 0.5},    //Coordenadas Vértice 0 V0
				{-0.5 ,-0.5, 0.5},    //Coordenadas Vértice 1 V1
				{-0.5 ,-0.5, -0.5},    //Coordenadas Vértice 2 V2
				{0.5 ,-0.5, -0.5},    //Coordenadas Vértice 3 V3
				{0.5 ,0.5, 0.5},    //Coordenadas Vértice 4 V4
				{0.5 ,0.5, -0.5},    //Coordenadas Vértice 5 V5
				{-0.5 ,0.5, -0.5},    //Coordenadas Vértice 6 V6
				{-0.5 ,0.5, 0.5},    //Coordenadas Vértice 7 V7
				};

	
	
		glBegin(GL_POLYGON);	//Front
			glColor3fv(colores[color]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glColor3fv(colores[color]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glColor3fv(colores[color]);	
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glColor3fv(colores[color]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glColor3fv(colores[color]);
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glColor3fv(colores[color]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		//Poner Código Aquí.
	glTranslatef(transX, transY, transZ);
	glRotatef(angleY,0.0f,1.0f,0.0f);
	glRotatef(angleX, 1.0f, 0.0f, 0.0f);
	glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
	
	glTranslatef(-10, 15, 0.2);
	//prisma(1); //Inicio
	glTranslatef(4.0, 0.0, 0.0);
	for (i = 0; i < 3; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}
	glTranslatef(0.0, -1.0, 0.0);
	
	for (i = 0; i < 3; i++) {
		prisma(0);
		glTranslatef(-1.0, 0.0, 0.0);
	}
	glTranslatef(0.0, -1.0, 0.0);
	
	for (i = 0; i < 5; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}
	glTranslatef(-1.0, -1.0, 0.0);

	for (i = 0; i < 5; i++) {
		prisma(0);
		glTranslatef(-1.0, 0.0, 0.0);
	}
	glTranslatef(0.0, -1.0, 0.0);
	
	for (i = 0; i < 7; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}
	glTranslatef(0.0, -1.0, 0.0);
	prisma(0);
	glTranslatef(-4.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(-4.0, 0.0, 0.0);
	prisma(0);

	glTranslatef(0.0, -1.0, 0.0);
	prisma(0);
	glTranslatef(2.0, 0.0, 0.0);
	prisma(1);
	glTranslatef(2.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(2.0, 0.0, 0.0);
	prisma(1);
	glTranslatef(2.0, 0.0, 0.0);
	prisma(0);

	glTranslatef(0.0, -1.0, 0.0);
	prisma(0);
	glTranslatef(-2.0, 0.0, 0.0);
	prisma(1);
	glTranslatef(-2.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(-2.0, 0.0, 0.0);
	prisma(1);
	glTranslatef(-2.0, 0.0, 0.0);
	prisma(0);
	//9
	glTranslatef(-1.0, -1.0, 0.0);
	prisma(0);
	glTranslatef(1.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(4.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(4.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(1.0, 0.0, 0.0);
	prisma(0);
	glTranslatef(0.0, -1.0, 0.0);
	//10
	for (i = 0; i < 11; i++) {
		prisma(0);
		glTranslatef(-1.0, 0.0, 0.0);
	}
	glTranslatef(0.0, -1.0, 0.0);

	for (i = 0; i < 4; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}
	glTranslatef(5.0, 0.0, 0.0);
	for (i = 0; i < 4; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}
	glTranslatef(-1.0, -1.0, 0.0);

	for (i = 0; i < 5; i++) {
		prisma(0);
		glTranslatef(-1.0, 0.0, 0.0);
	}
	glTranslatef(-3.0, 0.0, 0.0);
	for (i = 0; i < 5; i++) {
		prisma(0);
		glTranslatef(-1.0, 0.0, 0.0);
	}
	glTranslatef(2.0, -1.0, 0.0);

	for (i = 0; i < 11; i++) {
		prisma(0);
		glTranslatef(1.0, 0.0, 0.0);
	}



    glutSwapBuffers ( );
    // Swap The Buffers
}

void reshape ( int width , int height )   // Creamos funcion Reshape
{
  if (height==0)										// Prevenir division entre cero
	{
		height=1;
	}

	glViewport(0,0,width,height);	

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista
	glOrtho(-20,20,-20,20,0.1,20);	
	//glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 100.0);
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':
		case 'W':
			transZ +=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 's':
		case 'S':
			transZ -=0.2f;
			printf("Posicion en Z: %f\n", transZ);
			break;
		case 'a':
		case 'A':
			transX -=0.2f;
			break;
		case 'd':
		case 'D':
			transX +=0.2f;
			break;
		case 'e':
		case 'E':
			transY += 0.2f;
			break;
		case 'r':
		case 'R':
			transY -= 0.2f;
			break;
		case 27:        // Cuando Esc es presionado...
			exit ( 0 );   // Salimos del programa
		break;        
		default:        // Cualquier otra
		break;
  }
	glutPostRedisplay();
}

void arrow_keys ( int a_keys, int x, int y )  // Funcion para manejo de teclas especiales (arrow keys)
{
  switch ( a_keys ) {
    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		angleX += 1.0f;
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		angleX -= 1.0f;
		break;
	case GLUT_KEY_LEFT:
		angleY += 1.0f;
		break;
	case GLUT_KEY_RIGHT:
		angleY -= 1.0f;
		break;
	case GLUT_KEY_PAGE_UP:
		angleZ += 1.0f;
		break;
	case GLUT_KEY_PAGE_DOWN:
		angleZ -= 1.0f;
		break;
    default:
      break;
  }
  glutPostRedisplay();
}


int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (1500, 1500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 3"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}




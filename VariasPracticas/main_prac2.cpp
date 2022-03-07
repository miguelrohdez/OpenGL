//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************	Rojas Hernández Miguel Alejandro		******//
//*************											******//
//************************************************************//
#include "Main.h"
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Color del fondo
	
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();									// Reinicializamos la actual matriz Modelview

	//Poner aqui codigo ha dibujar
	//glBegin(GL_POINTS); Mapea puntos 
	//glBegin(GL_LINES); Lineas usando vertices cercanos
	//glBegin(GL_LINE_STRIP); Une en orden los vertices
	//glBegin(GL_LINE_LOOP); Une en orden los vertices y lo cierra
	//glBegin(GL_TRIANGLE_FAN); en abanico
	//glBegin(GL_TRIANGLE_STRIP); une los vertices 
	//glBegin(GL_QUAD_STRIP);
	//glBegin(GL_POLYGON);
	//glBegin(GL_LINE_LOOP);
	//Letra C
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-75.0f, 25.0f, -1.2f);//1
		glVertex3f(-44.4f, 25.0f, -1.2f);//2
		glVertex3f(-44.0f, 12.5f, -1.2f);//3
		glVertex3f(-62.0f, 12.5f, -1.2f);//4
		glVertex3f(-75.0f, 12.5f, -1.2f);//4.5
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-75.0f, 12.5f, -1.2f);//4.5
		glVertex3f(-62.0f, 12.5f, -1.2f);//4
		glVertex3f(-62.0f, -12.5f, -1.2f);//5
		glVertex3f(-75.0f, -12.5f, -1.2f);//5.5
	glEnd();
	glColor3f(1.0f, .5f, 0.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-75.0f, -12.5f, -1.2f);//5.5
		glVertex3f(-44.0f, -12.5f, -1.2f);//6
		glVertex3f(-44.0f, -25.0f, -1.2f);//7
		glVertex3f(-75.0f, -25.0f, -1.2f);//8
	glEnd();
	
	//Letra M
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-25.0f, -25.0f, -1.2f);//A
		glVertex3f(-25.0f, 25.0f, -1.2f);//B
		glVertex3f(-12.5f, 25.0f, -1.2f);//C
		glVertex3f(-12.5f, -25.0f, -1.2f);//L
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(-12.5f, 25.0f, -1.2f);//C
		glVertex3f(-12.5f, 0.0f, -1.2f);//K
		glVertex3f(0.0f, -12.5f, -1.2f);//J
		glVertex3f(0.0f, 0.0f, -1.2f);//D
	glEnd();
	glColor3f(0.3f, 0.1f, 1.0f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(0.0f, 0.0f, -1.2f);//D
		glVertex3f(0.0f, -12.5f, -1.2f);//J
		glVertex3f(12.5f, 0.0f, -1.2f);//I
		glVertex3f(12.5f, 25.0f, -1.2f);//E
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(12.5f, 25.0f, -1.2f);//E
		glVertex3f(12.5f, -25.0f, -1.2f);//H
		glVertex3f(25.0f, -25.0f, -1.2f);//G
		glVertex3f(25.0f, 25.0f, -1.2f);//F
	glEnd();

	glColor3f(0.3f, 0.1f, 0.3f);
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(37.5f, 25.0f, -1.2f);//a
		glVertex3f(50.0f, 25.0f, -1.2f);//a.5
		glVertex3f(50.0f, -25.0f, -1.2f);//h
		glVertex3f(37.5f, -25.0f, -1.2f);//i
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(50.0f, 25.0f, -1.2f);//a.5
		glVertex3f(75.0f, 25.0f, -1.2f);//b
		glVertex3f(62.5f, 17.0f, -1.2f);//l
		glVertex3f(50.0f, 17.0f, -1.2f);//j
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(62.5f, 17.0f, -1.2f);//l
		glVertex3f(75.0f, 25.0f, -1.2f);//b
		glVertex3f(75.0f, 12.5f, -1.2f);//c
		glVertex3f(62.5f, 0.0f, -1.2f);//d
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(50.0f, 8.0f, -1.2f);//k
		glVertex3f(62.5f, 8.0f, -1.2f);//m
		glVertex3f(62.5f, 0.0f, -1.2f);//d
		glVertex3f(50.0f, 0.0f, -1.2f);//g
	glEnd();
	glBegin(GL_TRIANGLE_FAN);
		glVertex3f(50.0f, 0.0f, -1.2f);//g
		glVertex3f(62.5f, 0.0f, -1.2f);//d
		glVertex3f(75.0f, -25.0f, -1.2f);//e
		glVertex3f(62.5f, -25.0f, -1.2f);//f
	glEnd();

	glColor3f(0.6f, 0.89f, 0.83f);
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 100.0 + 0.0f, -1.2f);//11
		glVertex3f(-12.0f, 12+100.0f, -1.2f);//10
		glVertex3f(0.0f, 100.0 + 36.0f, -1.2f);//1
		glVertex3f(12.0f, 100.0 + 12.0f, -1.2f);//2
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 100.0 + 0.0f, -1.2f);//11
		glVertex3f(12.0f, 100.0 + 12.0f, -1.2f);//2
		glVertex3f(36.0f, 100.0 + 12.0f, -1.2f);//3
		glVertex3f(18.0f, -6+ 100.0f, -1.2f);//4
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 100.0 + 0.0f, -1.2f);//11
		glVertex3f(18.0f, -6+ 100.0f, -1.2f);//4
		glVertex3f(30.0f, -30+100.0f, -1.2f);//5
		glVertex3f(0.0f, -20 + 100.0f, -1.2f);//6
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 100.0 + 0.0f, -1.2f);//11
		glVertex3f(0.0f, -20+100.0f, -1.2f);//6
		glVertex3f(-30.0f, -30+100.0f, -1.2f);//7
		glVertex3f(-18.0f, -6+100.0f, -1.2f);//8
	glEnd();
	glBegin(GL_QUADS);
		glVertex3f(0.0f, 100.0 + 0.0f, -1.2f);//11
		glVertex3f(-18.0f, -6+100.0f, -1.2f);//8
		glVertex3f(-36.0f, 12+100.0f, -1.2f);//9
		glVertex3f(-12.0f, 12+100.0f, -1.2f);//10
	glEnd();
	
	
		
	

	glFlush(); //Mandar informacion al monitor para ser mostrada
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

	// Ortogonal
	glOrtho(-150,150,-150,150,0.1,2);   //Ventana de Trabajo

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();									
}

// Termina la ejecucion del programa cuando se presiona ESC
void keyboard(unsigned char key, int x, int y)
{
	 switch (key) 
	 {
		case 27: exit(0);
				 break;
	 }
	  glutPostRedisplay();
}    

int main ( int argc, char** argv )   // Main Function
{
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGBA | GLUT_SINGLE); // Display Mode (Clores RGB y alpha | Buffer Sencillo )
  glutInitWindowSize  (30000,5000);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 2"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc	  ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutMainLoop        ( );          // 

  return 0;
}


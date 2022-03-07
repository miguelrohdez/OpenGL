//Semestre 2019 - 1
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************	Rojas Hernandez Miguel Alejandro		******//
//************************************************************//
#include "Main.h"


// Variables used to calculate frames per second: (Windows)
DWORD dwFrames = 0;
DWORD dwCurrentTime = 0;
DWORD dwLastUpdateTime = 0;
DWORD dwElapsedTime = 0;


//Variables used to create movement

int sol=0;
int year = 0;
int date = 0;
int moon = 0;
int mars = 0;
int y_saturno = 0;
int d_saturno = 0;


float camaraZ = 0.0;
float camaraX = 0.0;

GLfloat SunDiffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };			// Diffuse Light Values
GLfloat SunSpecular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat SunPosition[]= { 0.0f, 0.0f, 0.0f, 1.0f };			// Light Position

GLfloat EarthDiffuse[]= { 0.2f, 0.2f, 1.0f, 1.0f };			// Tierra
GLfloat EarthSpecular[] = { 0.8, 0.8, 0.8, 1.0 };
GLfloat EarthShininess[] = { 50.0 };

GLfloat MarsDiffuse[]= { 0.8f, 0.4f, 0.1f, 1.0f };			// Marte
GLfloat MarsSpecular[] = { 1.0, 0.5, 0.0, 1.0 };
GLfloat MarsShininess[] = { 50.0 };

GLfloat MoonDiffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };			// Luna
GLfloat MoonSpecular[] = { 1.0, 1.0, 1.0, 1.0 };
GLfloat MoonShininess[] = { 60.0 };

GLfloat JupiterDiffuse[] = { 0.804f, 0.361f, 0.361f };			// Jup
GLfloat JupiterSpecular[] = { 1.000f, 0.627f, 0.478f };
GLfloat JupiterShininess[] = { 10.0 };

GLfloat SaturnoDiffuse[] = { 1.000f, 0.753f, 0.796f };			// Sat
GLfloat SaturnoSpecular[] = { 0.780f, 0.082f, 0.522f };
GLfloat SaturnoShininess[] = { 70.0 };

GLfloat AnilloDiffuse[] = { 0.678f, 1.000f, 0.184f };			// Luna_M
GLfloat AnilloSpecular[] = { 0.196f, 0.804f, 0.196f };
GLfloat AnilloShininess[] = { 15.0 };



void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	
	glLightfv(GL_LIGHT1, GL_DIFFUSE, SunDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);
	
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHTING);

}

void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	glTranslatef(camaraX, 0.0, -5.0 + camaraZ);			//camara


	glPushMatrix();
	glRotatef(sol, 0.0, 1.0, 0.0);	//El Sol gira sobre su eje
	glColor3f(1.0, 1.0, 0.0);	//Sol amarillo
	glDisable(GL_LIGHTING);
	glutSolidSphere(1.9, 12, 12);  //Draw Sun (radio,H,V);
	glEnable(GL_LIGHTING);
	glLightfv(GL_LIGHT1, GL_POSITION, SunPosition);
	glLightfv(GL_LIGHT1, GL_SPECULAR, SunSpecular);

	glPopMatrix();

	glPushMatrix();
	glRotatef(year, 0.0, 1.0, 0.0);
	glTranslatef(5.0, 0.0, 0.0);
	glPushMatrix();
	glRotatef(date, 0.0, 1.0, 0.0);
	//glColor3f(0.0, 0.0, 1.0); //Tierra
	glLightfv(GL_LIGHT1, GL_DIFFUSE, EarthDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, EarthSpecular);
	glutSolidSphere(1.0, 20, 20);  //Draw Tierra (radio,H,V);
	glPopMatrix();

	glRotatef(moon, 1.0, 0.0, 0.0);
	glTranslatef(0.0, 2.5, 0.0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, MoonDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, MoonSpecular);
	glLightfv(GL_LIGHT1, GL_SHININESS, MoonShininess);
	glutSolidSphere(0.3, 20, 20);  //Draw Luna (radio,H,V);

	glPopMatrix();

	glPushMatrix();
	glRotatef(mars, 0.0, 0.0, 1.0);
	glTranslatef(9.5, 0.0, 0.0);
	glRotatef(date, 0.0, 1.0, 0.0);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, MarsDiffuse);
	glLightfv(GL_LIGHT1, GL_SPECULAR, MarsSpecular);
	glLightfv(GL_LIGHT1, GL_SHININESS, MarsShininess);
	glutSolidSphere(0.8, 20, 20);  //Draw Marte (radio,H,V);
	glPopMatrix();
	
	glPushMatrix();
		glRotatef(36.0, 0.0, 0.0, 1.0);
		glRotatef(sol, 0.0, 1.0, 0.0);
		glTranslatef(-13.0, 0.0, 0.0);
		glRotatef(date, 0.0, 1.0, 0.0);
		//glColor3f(1.0, 0.0, 0.0); //Jupiter
		glLightfv(GL_LIGHT1, GL_DIFFUSE, JupiterDiffuse);
		glLightfv(GL_LIGHT1, GL_SPECULAR, JupiterSpecular);
		glLightfv(GL_LIGHT1, GL_SHININESS, JupiterShininess);
		glutSolidSphere(1.8, 20, 20);
	glPopMatrix();

	glPushMatrix();
		glRotatef(-43.0, 0.0, 1.0, 0.0);
		glRotatef(180.0, 0.0, 1.0, 0.0);
		glRotatef(y_saturno, 0.0, 0.0, -1.0);
		glTranslatef(18.0, 0.0, 0.0);
		glPushMatrix();
			glRotatef(d_saturno, 0.0, 1.0, 0.0);
			glLightfv(GL_LIGHT1, GL_DIFFUSE, SaturnoDiffuse);
			glLightfv(GL_LIGHT1, GL_SPECULAR, SaturnoSpecular);
			glLightfv(GL_LIGHT1, GL_SHININESS, SaturnoShininess);
			glutSolidSphere(2.0, 20, 20);//Saturno
			glLightfv(GL_LIGHT1, GL_DIFFUSE, AnilloDiffuse);
			glLightfv(GL_LIGHT1, GL_SPECULAR, AnilloSpecular);
			glLightfv(GL_LIGHT1, GL_SHININESS, AnilloShininess);
			glutSolidTorus(.2, 2.5, 20, 20);//Anillo
		glPopMatrix();
		
	glPopMatrix();


	glutSwapBuffers(); //545456456


}

void animacion()
{
	// Calculate the number of frames per one second:
	//dwFrames++;
	dwCurrentTime = GetTickCount(); // Even better to use timeGetTime()
	dwElapsedTime = dwCurrentTime - dwLastUpdateTime;

	if(dwElapsedTime >= 30)
	{
		sol = (sol - 1) % 360;
		year = (year - 3) % 360;
		date = (date + 16) % 360;
		moon = (date + 3) % 360;
		mars = (mars- 4) % 360;
		d_saturno = (mars - 4) % 360;
		y_saturno = (mars - 4) % 360;
		dwLastUpdateTime = dwCurrentTime;
	}

	glutPostRedisplay();
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			camaraZ +=0.5f;
			break;
		case 's':
		case 'S':
			camaraZ -=0.5f;
			break;
		case 'a':
		case 'A':
			camaraX -= 0.5f;
			break;
		case 'd':
		case 'D':
			camaraX += 0.5f;
			break;

		case 'i':		
		case 'I':
			
			break;
		case 'k':
		case 'K':
			
			break;

		case 'l':   
		case 'L':
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
		
		break;
    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		
		break;
	case GLUT_KEY_LEFT:
		
		break;
	case GLUT_KEY_RIGHT:
		
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
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (20, 60);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 6 Sistema Solar"); // Nombre de la Ventana
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );
  glutMainLoop        ( );          // 

  return 0;
}
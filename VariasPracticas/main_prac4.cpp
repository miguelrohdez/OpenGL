//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************	Rojas Hernández Miguel Alejandro		******//
//************************************************************//
#include "Main.h"


float angleX = 0.0f;
float angleY = 0.0f;
float angleZ = 0.0f;
float transX = 0.0f;
float transY = 0.0f;
float transZ = -5.0f;
int screenW = 0.0;
int screenH = 0.0;

float red[3] = { 1.0, 0.0, 0.0 };
float green[3] = { 0.0,1.0,0.0 };
float blue[3] = { 0.0,0.0,1.0 };
float white[3] = { 1.0,1.0,1.0 };
float purple[3] = { 0.6, 0.196, 0.8 };
float dark_purple[3] = { 0.502, 0.0, 0.502 };
float violet[3] = { 0.580, 0.000, 0.827 };
float gold[3] = { 1.0, 0.843, 0.0 };
float pink[3] = {1.000, 0.894, 0.882};
float black[3] = {0.0, 0.0, 0.0};
float brown[3] = { 0.545, 0.271, 0.075 };




void InitGL ( void )     // Inicializamos parametros
{

	//glShadeModel(GL_SMOOTH);							// Habilitamos Smooth Shading
	glClearColor(0.863f, 0.863f, 0.86f, 0.0f);				// Negro de fondo
	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void prisma(float color[3])
{
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

	glColor3fv(color);
		glBegin(GL_POLYGON);	//Front		
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[1]);
		glEnd();

		glBegin(GL_POLYGON);	//Right
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[4]);
		glEnd();

		glBegin(GL_POLYGON);	//Back
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[3]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Left
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[7]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[2]);
		glEnd();

		glBegin(GL_POLYGON);  //Bottom
			glVertex3fv(vertice[0]);
			glVertex3fv(vertice[1]);
			glVertex3fv(vertice[2]);
			glVertex3fv(vertice[3]);
		glEnd();

		glBegin(GL_POLYGON);  //Top
			glVertex3fv(vertice[4]);
			glVertex3fv(vertice[5]);
			glVertex3fv(vertice[6]);
			glVertex3fv(vertice[7]);
		glEnd();
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	// Limpiamos pantalla y Depth Buffer
	//glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		
		glTranslatef(transX, transY, transZ);
		glRotatef(angleY, 0.0f, 1.0f, 0.0f);
		glRotatef(angleX, 1.0f, 0.0f, 0.0f);
		glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
		//Poner Código Aquí.
	
		glPushMatrix();
			glScalef(4.0,6.0,1.0);//Cuerpo
			prisma(red);
		glPopMatrix();
		glTranslatef(0.0, 3.25, 0.0);
		glPushMatrix();
			glScalef(0.5 / 1.0, 0.5 / 1.0, 1.0); //Cuello
			prisma(pink);
		glPopMatrix();
		glTranslatef(0.0, 1.5, 0.0);
		glPushMatrix();
			glScalef(2.0, 2.5, 1.0); //Cabeza
			prisma(pink);
		glPopMatrix();
		glTranslatef(0.0, -4.75, 0.0); //CentroCuerpo
		glPushMatrix();
			glTranslatef(-2.75, 2.5, 0.0);
			glPushMatrix();
				glScalef(1.5, 1.0, 1.0); //left_Brazo
				prisma(red);
			glPopMatrix();
			glTranslatef(-0.25, -3.5, 0.0);
			glScalef(1.0, 6.0, 1.0); //left_hand
			prisma(pink);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(2.75, 2.5, 0.0);
				glPushMatrix();
					glScalef(1.5, 1.0, 1.0); //right_Brazo
					prisma(red);
				glPopMatrix();
			glTranslatef(0.25, -3.5, 0.0);
			glPushMatrix();
				glTranslatef(0.25, -3.25, 0.0);
				glPushMatrix();
					glTranslatef(1.0, 0.0, 0.0);
					glPushMatrix();
						glTranslatef(2.5, 0.0, 0.0);
						glScalef(4.5, 0.5, 1.0); //3_sword
						prisma(blue);
					glPopMatrix();
					glScalef(0.5, 1.5, 1.0); //2_sword
					prisma(gold);
				glPopMatrix();
				glScalef(1.5, 0.25, 1.0); //1_sword
				prisma(blue);
			glPopMatrix();
			
			glScalef(1.0, 6.0, 1.0); //right_hand
			prisma(pink);
		glPopMatrix();
		glPushMatrix();
			glTranslatef(0.0, -3.5, 0.0);
			glScalef(4.0, 1.0, 1.0); 
			prisma(blue); //cintura
		glPopMatrix();
		glPushMatrix();
			glTranslatef(-1.25, -7.0, 0.0);
			glPushMatrix();
				glTranslatef(-0.75, -3.75, 0.0);
				glScalef(3.0, 1.5, 1.0);
				prisma(black); //pie
			glPopMatrix();
			glScalef(1.5, 6.0, 1.0);
			prisma(blue); //pierna izq
		glPopMatrix();
			glPushMatrix();
				glTranslatef(1.25, -7.0, 0.0);
				glPushMatrix();
					glTranslatef(0.75, -3.75, 0.0);
					glScalef(3.0, 1.5, 1.0);
					prisma(black);
				glPopMatrix();
				glScalef(1.5, 6.0, 1.0);
				prisma(blue); //pierna der
		glPopMatrix();
		
		//POS HIppo
		glTranslatef(15.0, -5.0, 0.0);

		glPushMatrix();
			glScalef(6.0, 6.0, 10.0);
			prisma(dark_purple); //body
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(0.0, 0.75, -5.75);
			glScalef(2.0, 2.0, 1.5);
			prisma(purple); //cola
		glPopMatrix();
		
		glPushMatrix();
			glTranslatef(2.0, -5.0, -3.5);
			glPushMatrix();
				glTranslatef(.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una3
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una2
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-0.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una1
			glPopMatrix();
			glScalef(2.0, 4.0, 2.0);
			prisma(purple); //pata_atr_der
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.0, -5.0, -3.5);
			glPushMatrix();
				glTranslatef(.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una3
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una2
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-0.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una1
			glPopMatrix();
			glScalef(2.0, 4.0, 2.0);
			prisma(purple); //pata_atr_izq
		glPopMatrix();

		glPushMatrix();
			glTranslatef(2.0, -5.0, 3.5);
			glPushMatrix();
				glTranslatef(.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una3
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una2
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-0.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una1
			glPopMatrix();
			glScalef(2.0, 4.0, 2.0);
			prisma(purple); //pata_del_der
		glPopMatrix();

		glPushMatrix();
			glTranslatef(-2.0, -5.0, 3.5);
			glPushMatrix();
				glTranslatef(.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una3
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.0, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una2
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-0.5, -1.7, 1.05);
				glScalef(.4, .4, .1);
				prisma(white); //una1
			glPopMatrix();
			glScalef(2.0, 4.0, 2.0);
			prisma(purple); //pata_del_izq
		glPopMatrix();

		glPushMatrix();
			glTranslatef(0.0, 2.0, 7.0);
			glPushMatrix();
				glScalef(4.0, 4.0, 4.0);
				prisma(purple); //head
			glPopMatrix();
			glPushMatrix();
				glTranslatef(1.0, 2.75, 0.5);
				glPushMatrix();
					glTranslatef(0.0, 0.0, .4);
					glScalef(1.1, 1.1, 0.2);
					prisma(pink); //oido
				glPopMatrix();
				glScalef(1.5, 1.5, .7);
				prisma(dark_purple); //oreja der
			glPopMatrix();

			glPushMatrix();
				glTranslatef(-1.0, 2.75, 0.5);
				glPushMatrix();
					glTranslatef(0.0, 0.0, .4);
					glScalef(1.1, 1.1, 0.2);
					prisma(pink); //oido
				glPopMatrix();
				glScalef(1.5, 1.5, .7);
				prisma(dark_purple); //oreja izq
			glPopMatrix();

			glPushMatrix();
				glTranslatef(1.0, 1.0, 2.1);
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.1);
					glScalef(.6, .6, .2);
						prisma(black); //iris
				glPopMatrix();
				glScalef(1.0, 1.0, 0.2);
				prisma(white); //ojo der
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1.0, 1.0, 2.1);
				glPushMatrix();
					glTranslatef(0.0, 0.0, 0.1);
					glScalef(.6, .6, .2);
					prisma(black); //iris
				glPopMatrix();
				glScalef(1.0, 1.0, 0.2);
				prisma(white); //ojoizq
			glPopMatrix();
			glPushMatrix();
				glTranslatef( 1.0, -2.5, 1.5);
				glScalef(.5, 1.0, .5);
				prisma(white); //diente-der
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-1.0, -2.5, 1.5);
				glScalef(.5, 1.0, .5);
				prisma(white); //diente-izq
			glPopMatrix();
			glTranslatef(0.0, -1.0, 2.5);
			glPushMatrix();
				glScalef(2.0, 1.0, 1.0);
				prisma(violet); //nariz
			glPopMatrix();
			glPushMatrix();
				glTranslatef(0.5, 0.0, 0.55);
				glScalef(0.5, 0.5, 0.1);
				prisma(pink); //nariz-izq
			glPopMatrix();
			glPushMatrix();
				glTranslatef(-0.5, 0.0, 0.55);
				glScalef(0.5, 0.5, 0.1);
				prisma(pink); //nariz-izq
			glPopMatrix();
		glPopMatrix();

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
	//glOrtho(-20,20,-15,15,100,100);
	glFrustum (-0.5, 0.5,-0.5, 0.5, 0.5, 50.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
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
  screenW = glutGet(GLUT_SCREEN_WIDTH);
  screenH = glutGet(GLUT_SCREEN_HEIGHT);
  glutInitWindowSize  (screenW, screenH);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 4"); // Nombre de la Ventana
  printf("Resolution H: %i \n", screenW);
  printf("Resolution V: %i \n", screenH);
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutMainLoop        ( );          // 

  return 0;
}




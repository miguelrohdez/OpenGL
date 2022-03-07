//Semestre 2018 - 2
//************************************************************//
//************************************************************//
//************** Alumno (s): *********************************//
//*************											******//
//*************											******//
//************************************************************//
//************************************************************//

#include "texture.h"
#include "figuras.h"
#include "Camera.h"

//#include "cmodel/CModel.h"

//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////
//static GLuint ciudad_display_list;	//Display List for the Monito


//NEW// Keyframes
//Variables de dibujo y manipulacion
float posX =0, posY = 2.5, posZ =-3.5, rotRodIzq = 0;
float giroMonito = 0;

#define MAX_FRAMES 5
int i_max_steps = 90;
int i_curr_steps = 0;

typedef struct _frame
{
	//Variables para GUARDAR Key Frames
	float posX;		//Variable para PosicionX
	float posY;		//Variable para PosicionY
	float posZ;		//Variable para PosicionZ
	float incX;		//Variable para IncrementoX
	float incY;		//Variable para IncrementoY
	float incZ;		//Variable para IncrementoZ
	float rotRodIzq;
	float rotInc;
	float giroMonito;
	float giroMonitoInc;
	
}FRAME;

FRAME KeyFrame[MAX_FRAMES];
int FrameIndex=0;			//introducir datos
bool play=false;
int playIndex=0;


//NEW//////////////////NEW//////////////////NEW//////////////////NEW////////////////

int w = 500, h = 500;
int frame=0,time,timebase=0;
char s[30];

CCamera objCamera;	//Create objet Camera
CCamera auxCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

int font=(int)GLUT_BITMAP_HELVETICA_18;


//GLfloat Diffuse[]= { 1.0f, 1.0f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat Diffuse[]= { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[]= { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[]= { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

GLfloat m_dif1[] = { 0.0f, 0.2f, 1.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec1[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb1[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s1[] = {18};

GLfloat m_dif2[] = { 0.8f, 0.2f, 0.0f, 1.0f };				// Diffuse Light Values
GLfloat m_spec2[] = { 0.0, 0.0, 0.0, 1.0 };				// Specular Light Values
GLfloat m_amb2[] = { 0.0, 0.0, 0.0, 1.0 };				// Ambiental Light Values
GLfloat m_s2[] = {22};

CTexture text2;
CTexture text3;	//Flecha
CTexture text4;	//Pavimento
CTexture text5;	//Pasto01
CTexture text6;	//Casa01
//Texturas NUEVAS
CTexture ParedExt;
CTexture PisoBlanco;
CTexture ParedBlanca;
CTexture ParedDurazno;
CTexture PisoBeige;
CTexture TechoCafe;
CTexture Pasto;
CTexture VentanaGrande;
CTexture VentanaPequeña;
CTexture Cielo;
CTexture PuerAlumFron;
CTexture Zaguan;
CTexture PuertaIn;

///PuerAlumFron
CTexture textWall;





float abrirPuerta = 0;
//END NEW//////////////////////////////////////////

CFiguras fig1;
CFiguras fig3;
CFiguras fig5;
CFiguras Exterior;
CFiguras Terreno;

void saveFrame ( void )
{
	
	printf("frameindex %d\n",FrameIndex);			

	KeyFrame[FrameIndex].posX=posX;
	KeyFrame[FrameIndex].posY=posY;
	KeyFrame[FrameIndex].posZ=posZ;

	KeyFrame[FrameIndex].rotRodIzq=rotRodIzq;
	KeyFrame[FrameIndex].giroMonito=giroMonito;
			
	FrameIndex++;
}

void resetElements( void )
{
	posX=KeyFrame[0].posX;
	posY=KeyFrame[0].posY;
	posZ=KeyFrame[0].posZ;

	rotRodIzq=KeyFrame[0].rotRodIzq;
	giroMonito=KeyFrame[0].giroMonito;

}

void interpolation ( void )
{
	KeyFrame[playIndex].incX = (KeyFrame[playIndex + 1].posX - KeyFrame[playIndex].posX) / i_max_steps;	
	KeyFrame[playIndex].incY = (KeyFrame[playIndex + 1].posY - KeyFrame[playIndex].posY) / i_max_steps;	
	KeyFrame[playIndex].incZ = (KeyFrame[playIndex + 1].posZ - KeyFrame[playIndex].posZ) / i_max_steps;	

	KeyFrame[playIndex].rotInc = (KeyFrame[playIndex + 1].rotRodIzq - KeyFrame[playIndex].rotRodIzq) / i_max_steps;	
	KeyFrame[playIndex].giroMonitoInc = (KeyFrame[playIndex + 1].giroMonito - KeyFrame[playIndex].giroMonito) / i_max_steps;

}




			
void InitGL ( GLvoid )     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel (GL_SMOOTH);

	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	//Nuevas Texturas Casa
	ParedExt.LoadTGA("Texturas/ParedesExt.tga");
	ParedExt.BuildGLTexture();
	ParedExt.ReleaseImage();

	PisoBlanco.LoadTGA("Texturas/PisoBlanco.tga");
	PisoBlanco.BuildGLTexture();
	PisoBlanco.ReleaseImage();

	ParedBlanca.LoadTGA("Texturas/ParedBlanca.tga");
	ParedBlanca.BuildGLTexture();
	ParedBlanca.ReleaseImage();

	ParedDurazno.LoadTGA("Texturas/ParedDur.tga");
	ParedDurazno.BuildGLTexture();
	ParedDurazno.ReleaseImage();

	PisoBeige.LoadTGA("Texturas/PisoBeige.tga");
	PisoBeige.BuildGLTexture();
	PisoBeige.ReleaseImage();

	TechoCafe.LoadTGA("Texturas/ParedCafe.tga");
	TechoCafe.BuildGLTexture();
	TechoCafe.ReleaseImage();
	
	Cielo.LoadBMP("Texturas/Cielo.bmp");
	Cielo.BuildGLTexture();
	Cielo.ReleaseImage();
	
	Pasto.LoadBMP("Texturas/Pasto.bmp");
	Pasto.BuildGLTexture();
	Pasto.ReleaseImage();

	VentanaGrande.LoadTGA("Texturas/VentGra.tga");
	VentanaGrande.BuildGLTexture();
	VentanaGrande.ReleaseImage();

	VentanaPequeña.LoadTGA("Texturas/Ventana.tga");
	VentanaPequeña.BuildGLTexture();
	VentanaPequeña.ReleaseImage();

	PuerAlumFron.LoadTGA("Texturas/PuerAlumFron.tga");
	PuerAlumFron.BuildGLTexture();
	PuerAlumFron.ReleaseImage();

	PuertaIn.LoadTGA("Texturas/PuertaIn.tga");
	PuertaIn.BuildGLTexture();
	PuertaIn.ReleaseImage();

	Zaguan.LoadTGA("Texturas/Zaguan.tga");
	Zaguan.BuildGLTexture();
	Zaguan.ReleaseImage();

	
	objCamera.Position_Camera(0,2.5f,3, 0,2.5f,0, 0, 1, 0);

	
	//NEW Iniciar variables de KeyFrames
	for(int i=0; i<MAX_FRAMES; i++)
	{
		KeyFrame[i].posX =0;
		KeyFrame[i].posY =0;
		KeyFrame[i].posZ =0;
		KeyFrame[i].incX =0;
		KeyFrame[i].incY =0;
		KeyFrame[i].incZ =0;
		KeyFrame[i].rotRodIzq =0;
		KeyFrame[i].rotInc =0;
		KeyFrame[i].giroMonito =0;
		KeyFrame[i].giroMonitoInc =0;
	}


}

void pintaTexto(float x, float y, float z, void *font,char *string)
{
  
  char *c;     //Almacena los caracteres a escribir
  glRasterPos3f(x, y, z);	//Posicion apartir del centro de la ventana
  //glWindowPos2i(150,100);
  for (c=string; *c != '\0'; c++) //Condicion de fin de cadena
  {
    glutBitmapCharacter(font, *c); //imprime
  }
}

void display ( void )   // Creamos la funcion donde se dibuja
{
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	
	
	glPushMatrix();
	glRotatef(g_lookupdown,1.0f,0,0);

		gluLookAt(	objCamera.mPos.x,  objCamera.mPos.y,  objCamera.mPos.z,	
					objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,	
					objCamera.mUp.x,   objCamera.mUp.y,   objCamera.mUp.z);
	

		glPushMatrix();
			glPushMatrix(); //Creamos cielo
				glDisable(GL_LIGHTING);
				glTranslatef(0,60,0);
				fig1.skybox(200.0, 200.0, 200.0, Cielo.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			glRotatef(90, 0, 1, 0);
			glPushMatrix(); //terreno
				glDisable(GL_LIGHTING);
				glRotatef(90, 1, 0, 0);
				glTranslatef(0, 0, 40);
				Terreno.Wall(80, 80, 1, Pasto.GLindex, Pasto.GLindex, Pasto.GLindex, Pasto.GLindex, Pasto.GLindex, Pasto.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Piso
				glDisable(GL_LIGHTING);
				glRotatef(90, 1, 0, 0);
				glTranslatef(0, 7.5, 39);
				Terreno.Wall(7.5, 12.5, 0.5, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();
			//Muros Ext P.Baja
			glTranslatef(0, -36.0, 0);
			glPushMatrix();
				glPushMatrix();
					glTranslatef(0,0,15); //vecino
					Exterior.Wall(2.5, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				glPopMatrix();
				glPushMatrix(); //privada
					glTranslatef(0, -1.5, 0); 
					Exterior.Wall(1.0, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(0, 3.6,0 ); //parte arriba
					Exterior.Wall(.4, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(12.0, -1.50, 0); //murito
					Exterior.Wall(1.1, 0.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-2.1, 0, 0); //ventana
					Exterior.Wall(1.1, 1.6, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
					glTranslatef(-5.1, 0, 0); //murito
					Exterior.Wall(1.1, 3.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-10.4, -.5, 0); //muritobajoVen
					Exterior.Wall(.6, 7, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(6.3, 1.1, 0); //ventanaCocina
					Exterior.Wall(.5, .6, 0.1, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex);
					glTranslatef(-3.1, 0, 0); //muritolat
					Exterior.Wall(.5, 2.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-3.1,0, 0); //ventanaGarage1
					Exterior.Wall(.5, .6, 0.1, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex);
					glTranslatef(-2.1, 0, 0); //muritolat
					Exterior.Wall(.5, 1.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-2.1, 0, 0); //ventanaGarage2
					Exterior.Wall(.5, .6, 0.1, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex);
					glTranslatef(-1.7, 0, 0); //muritolat
					Exterior.Wall(.5, 1.15, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

				glPopMatrix();
				
				glPushMatrix(); //atras
					glTranslatef(12.5, -1.5, 10.5);
					glRotatef(90, 0, 1, 0);
					Exterior.Wall(1.0, 4.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(5.1, 1.5, 0);
					Exterior.Wall(2.5, 0.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(2.5,0 , 0); //entradaPatio
					Exterior.Wall(2.5, 2, 0.1, PuerAlumFron.GLindex, PuerAlumFron.GLindex, PuerAlumFron.GLindex, PuerAlumFron.GLindex, PuerAlumFron.GLindex, PuerAlumFron.GLindex);
					glTranslatef(2.4,0 , 0); //murito
					Exterior.Wall(2.5, 0.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-10, 2.1, 0); //murito
					Exterior.Wall(.4, 4.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-3.9, -1.5, 0); //muritolat
					Exterior.Wall(1.1, .6, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(4.2, 0, 0); //ventanaCocina
					Exterior.Wall(1.1, 3.6, 0.1, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex);
					glTranslatef(3.9, 0, 0); //muritolat
					Exterior.Wall(1.1, .3, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

				glPopMatrix();
				glPushMatrix(); //frente
					glTranslatef(-12.5, 0,0.5);
					glRotatef(90, 0, 1, 0);
					Exterior.Wall(2.5, .5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-3.0,0,0);//zaguanizq
					Exterior.Wall(2.5, 2.5, 0.1, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex);
					glTranslatef(-2.8, 0, 0);//murito
					Exterior.Wall(2.5, .4, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-1.3, 0, 0);//puerta
					Exterior.Wall(2.5, .9, 0.1, PuertaIn.GLindex, PuertaIn.GLindex, PuertaIn.GLindex, PuertaIn.GLindex, PuertaIn.GLindex, PuertaIn.GLindex);
					glTranslatef(-1.3, 0, 0);//murito
					Exterior.Wall(2.5, .4, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glTranslatef(-2.8, 0, 0);//zaguander
					Exterior.Wall(2.5, 2.5, 0.1, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex, Zaguan.GLindex);
					glTranslatef(-2.9, 0, 0);//murito
					Exterior.Wall(2.5, .45, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				glPopMatrix();
			//Muros Int P.Baja
				glPushMatrix();
					glRotatef(90, 0, 1, 0);
					glTranslatef(-3., 0.0, -2.8);
					Exterior.Wall(2.5, 3.0, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex);
					glTranslatef(-9.0, 0.0, 0.0);
					Exterior.Wall(2.5, 3.0, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex);
					glPushMatrix(); //escaleras
						glRotatef(90, 0, 1, 0);
						glTranslatef(-3.4, -2.3, 1.5);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, -.35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, -.35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, -.35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, -.35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, -1.6);
						Exterior.Wall(.2, 1, 1.4, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(2.2, .35, 0);
						Exterior.Wall(.2, 1.2, 1.4, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(0, .35, 1.6);
						Exterior.Wall(.2, 1.2, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .35, .35);
						Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						glTranslatef(-0, .3, .4);
						Exterior.Wall(.1, 1, 0.3, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
						
					glPopMatrix();
					glPushMatrix(); //escaleras2
					glRotatef(90, 0, 1, 0);
					glTranslatef(-3.0, 2.5, 1.0);
					Exterior.Wall(.2, .8, 0.8, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, -.35);
					Exterior.Wall(.2, .8, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, -.35);
					Exterior.Wall(.2, .8, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, -.35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, -.35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, -1.6);
					Exterior.Wall(.2, 1, 1.4, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(2.2, .35, 0);
					Exterior.Wall(.2, 1.2, 1.4, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(0, .35, 1.6);
					Exterior.Wall(.2, 1.2, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .35, .35);
					Exterior.Wall(.2, 1, 0.2, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);
					glTranslatef(-0, .3, .4);
					Exterior.Wall(.1, 1, 0.3, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex, PisoBlanco.GLindex);

					glPopMatrix();
					glTranslatef(0.0, 0.0, 4.5);
					Exterior.Wall(2.5, 3.0, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex);
					glPushMatrix();
						glTranslatef(10.5, -1.3, 0.0);
						Exterior.Wall(1.2, 1.5, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex);
						glTranslatef(-1.5, 1.25 , 0.0);
						Exterior.Wall(2.5, 0.25, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, textWall.GLindex);
					glPopMatrix();
					glPushMatrix();
						glRotatef(90, 0, 1, 0);
						glTranslatef(2.25, 0.0, 6.0);
						Exterior.Wall(2.5, 2.25, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, textWall.GLindex);
					glPopMatrix();
					glRotatef(90, 0, 1, 0);
					glTranslatef(-8.5, 0.0, 6.0);
					Exterior.Wall(2.5, 2.5, 0.1, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, ParedDurazno.GLindex, textWall.GLindex);
				glPopMatrix();
				//PisoPlanta1
				glPushMatrix(); //Piso
					glDisable(GL_LIGHTING);
					glRotatef(90, 1, 0, 0);
					glTranslatef(0, 4.5,-2.5 );
					Terreno.Wall(4.5, 12.5, 0.1, TechoCafe.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex);
					glTranslatef(7.0, 7.5, 0);
					Terreno.Wall(3, 5.5, 0.1, TechoCafe.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex);
					glTranslatef(-14.6, 0 , 0);
					Terreno.Wall(3, 4.8, 0.1, TechoCafe.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex, PisoBeige.GLindex);
					//Terreno.Wall(7.5, 12.5, 0.1, textTecho.GLindex, textTecho.GLindex, textTecho.GLindex, textTecho.GLindex, textTecho.GLindex, textTecho.GLindex);

					glEnable(GL_LIGHTING);
				glPopMatrix();
				//Paredes2doPiso
				glPushMatrix();
					glTranslatef(0, 3.5, 0);
					glPushMatrix();
						glPushMatrix();
							glTranslatef(0,.5,0);
							glPushMatrix();
							glTranslatef(0, -0.5, 0);
								Exterior.Wall(1.0, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

							glPopMatrix();
							glPushMatrix();
								glTranslatef(0, 1.0, 15);
								Exterior.Wall(2.5, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glTranslatef(-12.5, 1.0,  -.1);
								glRotatef(90, 0, 1, 0);
								Exterior.Wall(1.5, .2, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glTranslatef(7.6, 1.35, 0);
								Exterior.Wall(.15, 7.4, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glPushMatrix(); //atras
									glTranslatef(-.2, 0, 25);
									Exterior.Wall(.15, 7.6, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(-7, -1.23, 0); //Murito
									Exterior.Wall(1.1, .6, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(2.8, 0, 0); //ventanaKaren
									Exterior.Wall(1.1, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
									glTranslatef(4.2, 0, 0); //Murito
									Exterior.Wall(1.1, 2.0, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(4.2, 0, 0); //ventanaMiguel
									Exterior.Wall(1.1, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
									glTranslatef(2.8, 0, 0); //Murito
									Exterior.Wall(1.1, .60, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

								glPopMatrix();
								
								glPushMatrix(); //privada
									glTranslatef(0, 3.4, 0);
									Exterior.Wall(.15, 12.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(12, -1.26, 0); //Murito
									Exterior.Wall(1.11, .60, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(-2.8, 0, 0); //ventanaMiguel
									Exterior.Wall(1.11, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
									glTranslatef(-4.2, 0, 0); //Murito
									Exterior.Wall(1.11, 2, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(-4.2, 0, 0); //ventanaEst
									Exterior.Wall(1.11, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
									glTranslatef(-3.5, 0, 0); //Murito
									Exterior.Wall(1.11, 1.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(-2, -.6, 0); //MuritoBajVen
									Exterior.Wall(.5, .5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(0, 1.11, 0); //VentanaBaño
									Exterior.Wall(.61, .5, 0.1, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex, VentanaPequeña.GLindex);
									glTranslatef(-1.5, -.50, 0); //Murito
									Exterior.Wall(1.11, 1.0, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
									glTranslatef(-3.1, 0, 0); //ventanaPablo
									Exterior.Wall(1.11, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
									glTranslatef(-2.7, 0, 0); //Murito
									Exterior.Wall(1.11, .53, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glPopMatrix();
							glPopMatrix();

							glPushMatrix(); //enfrente
								glRotatef(90, 0, 1, 0);
								glTranslatef(-7.5, 0.0, 12.5);
								Exterior.Wall(1.0, 7.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glTranslatef(0, 3.32, -25);
								glTranslatef(-7, -1.23, 0); //Murito
								Exterior.Wall(1.1, .6, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glTranslatef(2.8, 0, 0); //ventanaPablo
								Exterior.Wall(1.1, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
								glTranslatef(4.2, 0, 0); //Murito
								Exterior.Wall(1.1, 2.0, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
								glTranslatef(4.2, 0, 0); //ventanaPaps
								Exterior.Wall(1.1, 2.2, 0.1, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex, VentanaGrande.GLindex);
								glTranslatef(2.8, 0, 0); //Murito
								Exterior.Wall(1.1, .60, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

							glPopMatrix();
							glPushMatrix();
								Exterior.Wall(2.5, .60, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
							glPopMatrix();

							glPushMatrix();
								glRotatef(90, 0, 1, 0);
								glTranslatef(-7.5, 0.0, -12.5);
								Exterior.Wall(1.0, 7.5, 0.1, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);

							glPopMatrix();
						glPopMatrix();
					glPopMatrix();


			glPopMatrix();
		glPopMatrix();
	/*
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_LIGHTING);
			glColor3f(1.0,0.0,0.0);
			pintaTexto(-11,12.0,-14.0,(void *)font,"Proyecto final");
			pintaTexto(-11,8.5,-14,(void *)font,s);
			glColor3f(1.0,1.0,1.0);
		glEnable(GL_LIGHTING);
		glEnable(GL_TEXTURE_2D);
		*/
	glutSwapBuffers ( );

}

void animacion()
{
	fig3.text_izq-= 0.001;
	fig3.text_der-= 0.001;
	if(fig3.text_izq<-1)
		fig3.text_izq=0;
	if(fig3.text_der<0)
		fig3.text_der=1;

	//Movimiento del monito
	if(play)
	{		
		
		if(	i_curr_steps >= i_max_steps) //end of animation between frames?
		{			
			playIndex++;		
			if(playIndex>FrameIndex-2)	//end of total animation?
			{
				printf("termina anim\n");
				playIndex=0;
				play=false;
			}
			else //Next frame interpolations
			{
				i_curr_steps = 0; //Reset counter
				//Interpolation
				interpolation();

			}
		}
		else
		{
			//Draw animation
			posX+=KeyFrame[playIndex].incX;
			posY+=KeyFrame[playIndex].incY;
			posZ+=KeyFrame[playIndex].incZ;

			rotRodIzq+=KeyFrame[playIndex].rotInc;
			giroMonito+=KeyFrame[playIndex].giroMonitoInc;

			i_curr_steps++;
		}
		
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
	
	glFrustum (-0.1, 0.1,-0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard ( unsigned char key, int x, int y )  // Create Keyboard Function
{
	switch ( key ) {
		case 'w':   //Movimientos de camara
		case 'W':
			objCamera.Move_Camera( CAMERASPEED+0.2 );
			/* objCamera.Position_Camera(0, 2.5f, 3,
				 0, 2.5f, 0,
				 0, .5, 0);*/

			break;

		case 's':
		case 'S':
			objCamera.Move_Camera(-(CAMERASPEED+0.2));
			break;

		case 'a':
		case 'A':
			objCamera.Strafe_Camera(-(CAMERASPEED+0.4));
			break;

		case 'd':
		case 'D':
			objCamera.Strafe_Camera( CAMERASPEED+0.4 );
			break;

		case 'k':		//
		case 'K':
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}

			break;

		case 'l':						
		case 'L':
			if(play==false && (FrameIndex>1))
			{

				resetElements();
				//First Interpolation				
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;

		case '1':
			// Animación del Avión
			auxCamera.Position_Camera(-650, 800, -750, 40, 700, -750, 0, 1, 0);

			break;
		case '2':
			// Alberca
			auxCamera.Position_Camera(-100, 400, 700, -100, 0, 500, 0, 1, 0);

			break;
		case '3':
			// Animación Cohéte
			auxCamera.Position_Camera(800, 50, 0, 100, 150, 800, 0, 1, 0);

			break;
		case '4':
			// Animación Reloj
			auxCamera.Position_Camera(90, 70, 0, 100, 70, -100, 0, 1, 0);

			break;
		case '5':
			// Animación refrigerador
			auxCamera.Position_Camera(-30, 50, 30, -50, 47, 30, 0, 1, 0);

			break;
		case '6':
			// Animación Avion casa
			auxCamera.Position_Camera(-650, 80, -750, 40, 80, -750, 0, 1, 0);

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
	case GLUT_KEY_PAGE_UP:
		objCamera.UpDown_Camera(CAMERASPEED);
		break;

	case GLUT_KEY_PAGE_DOWN:
		objCamera.UpDown_Camera(-CAMERASPEED);
		break;

    case GLUT_KEY_UP:     // Presionamos tecla ARRIBA...
		g_lookupdown -= 1.0f;
		break;

    case GLUT_KEY_DOWN:               // Presionamos tecla ABAJO...
		g_lookupdown += 1.0f;
		break;

	case GLUT_KEY_LEFT:
		objCamera.Rotate_View(-CAMERASPEED);
		break;

	case GLUT_KEY_RIGHT:
		objCamera.Rotate_View( CAMERASPEED);
		break;

    default:
		break;
  }
  glutPostRedisplay();
}

void menuKeyFrame( int id)
{
	switch (id)
	{
		case 0:	//Save KeyFrame
			if(FrameIndex<MAX_FRAMES)
			{
				saveFrame();
			}
			break;

		case 1:	//Play animation
			if(play==false && FrameIndex >1)
			{

				resetElements();
				//First Interpolation
				interpolation();

				play=true;
				playIndex=0;
				i_curr_steps = 0;
			}
			else
			{
				play=false;
			}
			break;


	}
}


void menu( int id)
{
	
}



int main ( int argc, char** argv )   // Main Function
{
  int submenu;
  glutInit            (&argc, argv); // Inicializamos OpenGL
  glutInitDisplayMode (GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
  glutInitWindowSize  (500, 500);	// Tamaño de la Ventana
  glutInitWindowPosition (0, 0);	//Posicion de la Ventana
  glutCreateWindow    ("Practica 11"); // Nombre de la Ventana
  //glutFullScreen     ( );         // Full Screen
  InitGL ();						// Parametros iniciales de la aplicacion
  glutDisplayFunc     ( display );  //Indicamos a Glut función de dibujo
  glutReshapeFunc     ( reshape );	//Indicamos a Glut función en caso de cambio de tamano
  glutKeyboardFunc    ( keyboard );	//Indicamos a Glut función de manejo de teclado
  glutSpecialFunc     ( arrow_keys );	//Otras
  glutIdleFunc		  ( animacion );

  submenu = glutCreateMenu	  ( menuKeyFrame );
  glutAddMenuEntry	  ("Guardar KeyFrame", 0);
  glutAddMenuEntry	  ("Reproducir Animacion", 1);
  glutCreateMenu	  ( menu );
  glutAddSubMenu	  ("Animacion Monito", submenu);
 
  glutAttachMenu	  (GLUT_RIGHT_BUTTON);


  glutMainLoop        ( );          // 

  return 0;
}
#include "texture.h"
#include "figuras.h"
#include "Camera.h"
#include "cmodel/CModel.h"

#if (_MSC_VER >= 1900)
#   pragma comment( lib, "legacy_stdio_definitions.lib" )
#endif

int w = 500, h = 500;
int frame = 0, time, timebase = 0;
int deltaTime = 0;
float movHeliX, movHeliY, movHeliZ = 0.0;
int estado = 0;
bool g_fanimacion = false;
int giro_heli=0;


CCamera objCamera;	//Create objet Camera

GLfloat g_lookupdown = 0.0f;    // Look Position In The Z-Axis (NEW) 

GLfloat Diffuse[] = { 0.5f, 0.5f, 0.5f, 1.0f };				// Diffuse Light Values
GLfloat Specular[] = { 1.0, 1.0, 1.0, 1.0 };				// Specular Light Values
GLfloat Position[] = { 0.0f, 7.0f, -5.0f, 0.0f };			// Light Position
GLfloat Position2[] = { 0.0f, 0.0f, -5.0f, 1.0f };			// Light Position

CTexture text1;
CTexture text2;
CTexture text3;	//Flecha
CTexture prueba;
//Mis texturas
CTexture PastoJardinera;
CTexture TierraJardinera;
CTexture ParedInterior;
CTexture TechoBlanco;
CTexture Terreno;
CTexture TechoExt;
CTexture ParedExt;
CTexture ParedCnVentana;
CTexture Escaleras;
CTexture PisoLadrilloGris;
CTexture VidrioAzul;
CTexture VidrioAzulPuerta;
CTexture arbolFrente;
CTexture arbolAtras;
CTexture BoteBasura;
CTexture BoteBasuraB;
CTexture Hidrante;
CTexture EntradaAzulPuerta;
CTexture EntradaAzul;
CTexture Concreto;
CTexture Lampara;
CTexture Persona;
CTexture PuertaCafe;
CTexture PuertaCafeSola;
CTexture PupitreIzq;
CTexture PupitreDer;
CTexture PupitreAtras;
CTexture PupitreFrente;
CTexture PupitreSup;
CTexture ProyIzq;
CTexture ProyDer;
CTexture ProySup;
CTexture ProyFrente;
CTexture ProyAtras;
CTexture Otros;
CTexture MesaLat;
CTexture MesaAtras;
CTexture MesaFrente;
CTexture MesaSup;
CTexture Pizarra;


CFiguras sky;
CFiguras objeto;

//Modelos
CModel Helicop;
CModel Aves;



void Jardinera2(GLuint TexturaBorde, GLuint TexturaSuperior) {
	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //Arriba
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, 0.0, 29.0); //2
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, 0.0, 29); //4
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, 0.0, 0.0); //5
	glEnd();

	glBegin(GL_POLYGON); //Abajo
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, -1.0, 29.0); //2-
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, -1.0, 29); //4-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LatDer
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(13.5, 0.0, 0.0); //5
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(13.5, 0.0, 29); //4
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, -1.0, 29); //4-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
	glEnd();

	glBegin(GL_POLYGON); //LatIzq
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 29.0); //2
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 29.0); //2-
	glEnd();

	glBegin(GL_POLYGON); //Fron
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(13.5, 0.0, 0.0); //5-
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //ArribaTrian
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 29); //2
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, 0.0, 40.4); //3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(13.5, 0.0, 29); //4
	glEnd();

	glBegin(GL_POLYGON); //AbajoTrian
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, -1.0, 29.0); //2-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 40.4); //3-
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(13.5, -1.0, 29); //4-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //L1_3-2
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 40.4); //3
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0, 0.0, 29.0); //2
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0, -1.0, 29.0); //2-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 40.4); //3
	glEnd();

	glBegin(GL_POLYGON); //L2_3-4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(13.5, 0.0, 29); //4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0, 0.0, 40.4); //3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0, -1.0, 40.4); //3-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 29); //4-
	glEnd();

}

void Jardinera3(GLuint TexturaBorde, GLuint TexturaSuperior) {
	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //Arriba
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, 0.0, 31.6); //2
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, 0.0, 31.6); //4
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, 0.0, 0.0); //5
	glEnd();

	glBegin(GL_POLYGON); //Abajo
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, -1.0, 31.6); //2-
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, -1.0, 31.6); //4-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LatDer
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(13.5, 0.0, 0.0); //5
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(13.5, 0.0, 31.6); //4
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(13.5, -1.0, 31.6); //4-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
	glEnd();

	glBegin(GL_POLYGON); //LatIzq
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 31.6); //2
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 31.6); //2-
	glEnd();

	glBegin(GL_POLYGON); //Fron
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //1-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(13.5, 0.0, 0.0); //5-
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(13.5, -1.0, 0.0); //5-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //1-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //ArribaTrian
		glVertex3f(0.0, 0.0, 31.6); //2
		glVertex3f(0.0, 0.0, 44.3); //3
		glVertex3f(13.5, 0.0, 31.6); //4
	glEnd();

	glBegin(GL_POLYGON); //AbajoTrian
		glVertex3f(0.0, -1.0, 31.6); //2-
		glVertex3f(0.0, -1.0, 44.3); //3-
		glVertex3f(13.5, -1.0, 31.6); //4-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //L1_3-2
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 44.3); //3
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0, 0.0, 31.6); //2
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0, -1.0, 31.6); //2-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 44.3); //3
	glEnd();

	glBegin(GL_POLYGON); //L2_3-4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(13.5, 0.0, 31.6); //4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0, 0.0, 44.3); //3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0, -1.0, 44.3); //3-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.5, -1.0, 31.6); //4-
	glEnd();

}

void Jardinera6(GLuint TexturaBorde, GLuint TexturaSuperior) {
	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //1
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(25.0, 0.0, 17.9); //2
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(23.3, 0.0, 11.38); //3
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(20.5, 0.0, 5.3); //4
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.5, 0.0, 17.9); //4-
	glEnd();

	glBegin(GL_POLYGON); //2			17.9
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.5, 0.0, 5.3); //4
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(16.8, 0.0, 0.4); //5
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.8, 0.0, 17.9); //5-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.5, 0.0, 17.9); //4-
	glEnd();

	glBegin(GL_POLYGON); //3
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.8, 0.0, 0.4); //5
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(14.7, 0.0, 1.62); //6
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(14.7, 0.0, 17.9); //6-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(16.8, 0.0, 17.9); //5-
	glEnd();

	glBegin(GL_POLYGON); //4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(14.7, 0.0, 1.62); //6
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(3.28, 0.0, 3.9); //7
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(3.28, 0.0, 17.9); //7-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(14.7, 0.0, 17.9); //6-
	glEnd();

	glBegin(GL_POLYGON); //5
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(3.28, 0.0, 3.9); //7
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.4,  0.0, 3.6); //8
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.4,  0.0, 17.9); //8-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(3.28, 0.0, 17.9); //7-
	glEnd();

	glBegin(GL_POLYGON); //1a
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(25.0, -1.0, 17.9); //2
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(23.3, -1.0, 11.38); //3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(20.5, -1.0, 5.3); //4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.5, -1.0, 17.9); //4-
	glEnd();

	glBegin(GL_POLYGON); //2a			17.9
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.5, -1.0, 5.3); //4
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(16.8, -1.0, 0.4); //5
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.8, -1.0, 17.9); //5-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.5, -1.0, 17.9); //4-
	glEnd();

	glBegin(GL_POLYGON); //3a
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.8, -1.0, 0.4); //5
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(14.7, -1.0, 1.62); //6
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(14.7, -1.0, 17.9); //6-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(16.8, -1.0, 17.9); //5-
	glEnd();

	glBegin(GL_POLYGON); //4a
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(14.7, -1.0, 1.62); //6
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(3.28, -1.0, 3.9); //7
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(3.28, -1.0, 17.9); //7-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(14.7, -1.0, 17.9); //6-
	glEnd();

	glBegin(GL_POLYGON); //5a
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(3.28, -1.0, 3.9); //7
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.4,  -1.0, 3.6); //8
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.4,  -1.0, 17.9); //8-
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(3.28, -1.0, 17.9); //7-
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LatCorto
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.4,0.0,17.9); //1
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.4, 0.0, 3.6); //8
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(0.4, -1.0, 3.6); //8-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.4, -1.0,17.9); //1-
		
	glEnd();

	glBegin(GL_POLYGON); //LatLargo
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.4, 0.0, 17.9); //1
		glTexCoord2f(2.0f, 0.0f);	glVertex3f(25.0, 0.0, 17.7); //2
		glTexCoord2f(2.0f, 1.0f);	glVertex3f(25.0, -1.0, 17.7); //2-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.4, -1.0, 17.9); //1-
	glEnd();

	glBegin(GL_POLYGON); //2-3
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(25, 0.0, 17.7); //2
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(23.3, 0.0, 11.38); //3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(23.3, -1.0, 11.38); //3-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(25, -1.0, 17.7); //2-
	glEnd();

	glBegin(GL_POLYGON); //3-4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(23.3, 0.0, 11.38); //3
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.5, 0.0, 5.3); //4
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(20.5, -1.0, 5.3); //4-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(23.3, -1.0, 11.38); //3-
	glEnd();
	glBegin(GL_POLYGON); //4-5
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.5, 0.0, 5.3); //4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(16.8, 0.0, 0.4); //5
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.8, -1.0, 0.4); //5-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(20.5, -1.0, 5.3); //4-
	glEnd();
	glBegin(GL_POLYGON); //5-6
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.8, 0.0, 0.4); //5
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(14.7, 0.0, 1.62); //6
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(14.7, -1.0, 1.62); //6-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(16.8, -1.0, 0.4); //5-
	glEnd();
	glBegin(GL_POLYGON); //6-7
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(14.7, 0.0, 1.62); //6
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(3.28, 0.0, 3.9); //7
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(3.28, -1.0, 3.9); //7-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(14.7, -1.0, 1.62); //6-
	glEnd();
	glBegin(GL_POLYGON); //7-8
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(3.28, 0.0, 3.9); //7
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.4, 0.0, 3.6); //8
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.4, -1.0, 3.6); //8-
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(3.28, -1.0, 3.9); //7-
	glEnd();
}

void JardineraMi(GLuint TexturaBorde, GLuint TexturaSuperior) {
	glBindTexture(GL_TEXTURE_2D, TexturaSuperior);
	glBegin(GL_POLYGON); //1
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0,  0.0, 0.0); //a
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.0, 0.0, 0.0);//b
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.7, 0.0, 12.8);//1
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 12.8);//1-
	glEnd();
	
	glBegin(GL_POLYGON); //2
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.7, 0.0, 12.8);//1
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(20.4, 0.0, 18.6);//2
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  0.0, 18.6);//2-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 12.8);//1-
	glEnd();

	glBegin(GL_POLYGON); //3
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.4,  0.0, 18.6);//2
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.75, 0.0, 23.5);//3
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,   0.0, 23.5);//3-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,   0.0, 18.6);//2-
	glEnd();

	glBegin(GL_POLYGON); //4
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.75, 0.0, 23.5);//3
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(24.6,  0.0, 25);//4
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,   0.0, 25);//4-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,   0.0, 23.5);//3-
	glEnd();

	glBegin(GL_POLYGON); //5
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(24.6, 0.0, 25);//4
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(27.0, 0.0, 27.2);//5
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  0.0, 27.2);//5-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 25);//4-
	glEnd();

	glBegin(GL_POLYGON); //6
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(27.0, 0.0, 27.2);//5
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.3, 0.0, 31);//6
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  0.0, 31);//6-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 27.2);//5-
	glEnd();

	glBegin(GL_POLYGON); //7
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.3, 0.0, 31);//6
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(18.5, 0.0, 34.6);//7
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  0.0, 34.6);//7-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 31);//6-
	glEnd();
	
	glBegin(GL_POLYGON); //8
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(18.5, 0.0, 34.6);//7
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(10.0, 0.0, 38.7);//8
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  0.0, 40.0);//c
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  0.0, 34.6);//7
	glEnd();

	glBegin(GL_POLYGON); //1a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0,  -1.0, 0.0); //a
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.0, -1.0, 0.0);//b
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.7, -1.0, 12.8);//1
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 12.8);//1-
	glEnd();
	
	glBegin(GL_POLYGON); //2a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.7, -1.0, 12.8);//1
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(20.4, -1.0, 18.6);//2
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  -1.0, 18.6);//2-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 12.8);//1-
	glEnd();

	glBegin(GL_POLYGON); //3a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.4,  -1.0, 18.6);//2
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.75, -1.0, 23.5);//3
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,   -1.0, 23.5);//3-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,   -1.0, 18.6);//2-
	glEnd();

	glBegin(GL_POLYGON); //4a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.75, -1.0, 23.5);//3
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(24.6,  -1.0, 25);//4
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,   -1.0, 25);//4-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,   -1.0, 23.5);//3-
	glEnd();

	glBegin(GL_POLYGON); //5a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(24.6, -1.0, 25);//4
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(27.0, -1.0, 27.2);//5
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  -1.0, 27.2);//5-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 25);//4-
	glEnd();

	glBegin(GL_POLYGON); //6a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(27.0, -1.0, 27.2);//5
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.3, -1.0, 31);//6
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  -1.0, 31);//6-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 27.2);//5-
	glEnd();

	glBegin(GL_POLYGON); //7a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.3, -1.0, 31);//6
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(18.5, -1.0, 34.6);//7
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  -1.0, 34.6);//7-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 31);//6-
	glEnd();
	
	glBegin(GL_POLYGON); //8a
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(18.5, -1.0, 34.6);//7
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(10.0, -1.0, 38.7);//8
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0,  -1.0, 40.0);//c
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0,  -1.0, 34.6);//7
	glEnd();

/*
	glBegin(GL_POLYGON); //Abajo
	glVertex3f(0.0, -1.0, 0.0); //a-
	glVertex3f(13.0, -1.0, 0.0);//b-
	glVertex3f(16.7, -1.0, 12.8);//1-
	glVertex3f(20.4, -1.0, 18.6);//2-
	glVertex3f(22.75, -1.0, 23.5);//3-
	glVertex3f(24.6, -1.0, 25);//4-
	glVertex3f(27.0, -1.0, 27.2);//5-
	glVertex3f(22.3, -1.0, 31);//6-
	glVertex3f(18.5, -1.0, 34.6);//7-
	glVertex3f(10, -1.0, 38.7);//8-
	glVertex3f(0.0, -1.0, 40.0);//c-
	glEnd();
*/
	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LadoLargo
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //a
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //a-
	glTexCoord2f(2.0f, 1.0f);	glVertex3f(0.0, -1.0, 40.0);//c-
	glTexCoord2f(2.0f, 0.0f);	glVertex3f(0.0, 0.0, 40.0);//c
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LadoAtras
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0.0, 0.0, 0.0); //a
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0.0, -1.0, 0.0); //a-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(13.0, -1.0, 0.0);//b-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(13.0, 0.0, 0.0);//b
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //LadoB-1
	glColor3f(1, 1, 1);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(13.0, 0.0, 0.0);//b
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(13.0, -1.0, 0.0);//b-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(16.7, -1.0, 12.8);//1-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(16.7, 0.0, 12.8);//1
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado1-2
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(16.7, 0.0, 12.8);//1
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(16.7, -1.0, 12.8);//1-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(20.4, -1.0, 18.6);//2-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(20.4, 0.0, 18.6);//2
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado2-3
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(20.4, 0.0, 18.6);//2
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(20.4, -1.0, 18.6);//2-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(22.75, -1.0, 23.5);//3-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(22.75, 0.0, 23.5);//3
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado3-4
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.75, 0.0, 23.5);//3
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.75, -1.0, 23.5);//3-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(24.6, -1.0, 25);//4-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(24.6, 0.0, 25);//4
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado4-5
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(24.6, 0.0, 25);//4
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(24.6, -1.0, 25);//4-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(27.0, -1.0, 27.2);//5-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(27.0, 0, 27.2);//5
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado5-6
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(27.0, 0, 27.2);//5
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(27.0, -1.0, 27.2);//5-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(22.3, -1.0, 31);//6-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(22.3, 0.0, 31);//6
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado6-7
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.3, 0.0, 31);//6
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.3, -1.0, 31);//6-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(18.5, -1.0, 34.6);//7-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(18.5, 0.0, 34.6);//7
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado7-8
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(18.5, 0.0, 34.6);//7
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(18.5, -1.0, 34.6);//7-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(10, -1.0, 38.7);//8-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(10, 0.0, 38.7);//8
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaBorde);
	glBegin(GL_POLYGON); //Lado8-C
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(10, 0.0, 38.7);//8
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(10, -1.0, 38.7);//8-
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(0.0, -1.0, 40.0);//c-
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(0.0, 0.0, 40.0);//c
	glEnd();
}
void Domo(GLuint Textura, GLuint Puerta, GLuint TexturaPared) {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//Arriba
	glBindTexture(GL_TEXTURE_2D, Textura);
	glBegin(GL_POLYGON); //1
	glNormal3f(0.0f, -1.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, 0, 0);//1
	glTexCoord2f(1.0f, 0.0f);	glVertex3f(25, 0, 0);//2
	glTexCoord2f(1.0f, 1.0f);	glVertex3f(25, -0.5, 9);//3
	glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -0.5, 9);//12
	glEnd();
	
	glBegin(GL_POLYGON); //2
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(25, -0.5, 9);//3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(24.125, -.625, 11.5);//4
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(.875, -.625, 11.5);//11
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -0.5, 9);//12
	glEnd();

	glBegin(GL_POLYGON); //3
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(24.125, -.625, 11.5);//4
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(23.25, -.75, 14.5);//5
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(1.75, -0.75, 14.5);//10
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(.875, -.625, 11.5);//11
	glEnd();

	glBegin(GL_POLYGON); //4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(23.25, -.75, 14.5);//5
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(22.375, -.875, 16.5);//6
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(2.625, -.875, 16.5);//9
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(1.75, -0.75, 14.5);//10
	glEnd();

	glBegin(GL_POLYGON); //5
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(22.375, -.875, 16.5);//6
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(21.5, -1, 19);//7
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(3.5, -1, 19);//8
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(2.625, -.875, 16.5);//9
	glEnd();
	//Arriba

	//LateralIzquierdo
	glBindTexture(GL_TEXTURE_2D, Textura);
	glBegin(GL_POLYGON); //1
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, 0, 0);//1
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(0, -0.5, 9);//12
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(0, -3.6, 9);//17
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -3.6, 0);//18
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaPared);
	glBegin(GL_POLYGON); //2
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(0, -0.5, 9);//12
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(.875, -.625, 11.5);//11
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(.875, -3.6, 11.5);//16
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(0, -3.6, 9);//17
	glEnd();

	glBegin(GL_POLYGON); //3
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(.875, -.625, 11.5);//11
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(1.75, -0.75, 14.5);//10
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(1.75, -3.6, 14.5);//15
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(.875, -3.6, 11.5);//16
	glEnd();

	glBegin(GL_POLYGON); //4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(1.75, -0.75, 14.5);//10
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(2.625, -.875, 16.5);//9
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(2.625, -3.6, 16.5);//14
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(1.75, -3.6, 14.5);//15
	glEnd();

	glBegin(GL_POLYGON); //5
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(2.625, -.875, 16.5);//9
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(3.5, -1, 19);//8
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(3.5, -3.6, 19);//13
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(2.625, -3.6, 16.5);//14
	glEnd();
	
	//LateralDerecho
	glBindTexture(GL_TEXTURE_2D, Textura);
	glBegin(GL_POLYGON); //1
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(25, 0, 0);//2
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(25, -0.5, 9);//3
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(25, -3.6, 9);//23
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(25, -3.6, 0);//24
	glEnd();

	glBindTexture(GL_TEXTURE_2D, TexturaPared);
	glBegin(GL_POLYGON); //2
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(25, -0.5, 9);//3
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(24.125, -.625, 11.5);//4
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(24.125, -3.6, 11.5);//22
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(25, -3.6, 9);//23
	glEnd();

	glBegin(GL_POLYGON); //3
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(24.125, -.625, 11.5);//4
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(23.25, -.75, 14.5);//5
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(23.25, -3.6, 14.5);//21
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(24.125, -3.6, 11.5);//22
	glEnd();

	glBegin(GL_POLYGON); //4
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(23.25, -.75, 14.5);//5
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(22.375, -.875, 16.5);//6
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(22.375, -3.6, 16.5);//20
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(23.25, -3.6, 14.5);//21
	glEnd();

	glBegin(GL_POLYGON); //5
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(22.375, -.875, 16.5);//6
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(21.5, -1, 19);//7
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(21.5, -3.6, 19);//19
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(22.375, -3.6, 16.5);//20
	glEnd();
	//LateralDerecho

	glBindTexture(GL_TEXTURE_2D, Puerta);
	glBegin(GL_POLYGON); //Front
		glTexCoord2f(1.0f, 1.0f);	glVertex3f(3.5, -1, 19);//8
		glTexCoord2f(0.0f, 1.0f);	glVertex3f(21.5, -1, 19);//7
		glTexCoord2f(0.0f, 0.0f);	glVertex3f(21.5, -3.6, 19);//25
		glTexCoord2f(1.0f, 0.0f);	glVertex3f(3.5, -3.6, 19);//26
	glEnd();
	glDisable(GL_BLEND);
}

void Pared(float altura, float largo, float profundidad,
	GLuint textura1, GLuint textura2, GLuint textura3,
	GLuint textura4, GLuint textura5, GLuint textura6)  {


	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-0.5*altura, 0.5*profundidad },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 2 V2
		{ -0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 5 V5
		{ 0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 7 V7
		{ -0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front
	
	glNormal3f(0.0f, 0.0f, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura4);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura5);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura6);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0, 0.0f);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 1.0); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void Pupitre(float altura, float largo, float profundidad,
	GLuint textura1, GLuint textura2, GLuint textura3,
	GLuint textura4, GLuint textura5, GLuint textura6) {


	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-0.5*altura, 0.5*profundidad },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 2 V2
		{ -0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 5 V5
		{ 0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 7 V7
		{ -0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front

	glNormal3f(0.0f, 0.0f, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 0.0); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura4);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0f, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(0.0, 1.0); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0, 0.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura5);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura6);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0, 0.0f);
	glTexCoord2f(1.0, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0, 1.0); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0, 0.0); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void Techo(float altura, float largo, float profundidad,
	GLuint textura1, GLuint textura2, GLuint textura3,
	GLuint textura4, GLuint textura5, GLuint textura6) {


	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-0.5*altura, 0.5*profundidad },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 2 V2
		{ -0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 5 V5
		{ 0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 7 V7
		{ -0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front

	glNormal3f(0.0f, 0.0f, 1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[1]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura2);
	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[4]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura3);
	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 1.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura4);
	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0, 1.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(1.0, 1.0); glVertex3fv(vertice[6]);
	glTexCoord2f(1.0f, 0.0); glVertex3fv(vertice[2]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura5);
	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(10.0, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(10.0, 10.0); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 10.0); glVertex3fv(vertice[3]);
	glEnd();

	glBindTexture(GL_TEXTURE_2D, textura6);   // choose the texture to use.
	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0, 0.0f);
	glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(10.0, 0.0); glVertex3fv(vertice[5]);
	glTexCoord2f(10.0, 10.0); glVertex3fv(vertice[6]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[7]);
	glEnd();
}

void Suelo(float altura, float largo, float profundidad,GLuint textura1) {


	GLfloat vertice[8][3] = {
		{ 0.5*largo ,-0.5*altura, 0.5*profundidad },    //Coordenadas Vértice 1 V1
		{ -0.5*largo ,-0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 2 V2
		{ -0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 3 V3
		{ 0.5*largo ,-0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 4 V4
		{ 0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 5 V5
		{ 0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 6 V6
		{ -0.5*largo ,0.5*altura , -0.5*profundidad },    //Coordenadas Vértice 7 V7
		{ -0.5*largo ,0.5*altura , 0.5*profundidad },    //Coordenadas Vértice 8 V8
	};

	glBindTexture(GL_TEXTURE_2D, textura1);
	glBegin(GL_POLYGON);	//Front

	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(0.0, 10.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(10.0f, 0.0); glVertex3fv(vertice[1]);
	glEnd();

	glBegin(GL_POLYGON);	//Right
	glNormal3f(1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(10.0f, 0.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[4]);
	glEnd();

	glBegin(GL_POLYGON);	//Back
	glNormal3f(0.0f, 0.0f, -1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(10.0f, 0.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[3]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Left
	glNormal3f(-1.0f, 0.0f, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(0.0, 10.0f); glVertex3fv(vertice[7]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(10.0f, 0.0); glVertex3fv(vertice[2]);
	glEnd();

	glBegin(GL_POLYGON);  //Bottom
	glNormal3f(0.0f, -1.0, 0.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3fv(vertice[0]);
	glTexCoord2f(10.0f, 0.0f); glVertex3fv(vertice[1]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[2]);
	glTexCoord2f(0.0f, 10.0f); glVertex3fv(vertice[3]);
	glEnd();

	glBegin(GL_POLYGON);  //Top
	glNormal3f(0.0f, 1.0f, 0.0f);
	glTexCoord2f(0.0, 0.0f); glVertex3fv(vertice[4]);
	glTexCoord2f(0.0, 10.0f); glVertex3fv(vertice[5]);
	glTexCoord2f(10.0f, 10.0f); glVertex3fv(vertice[6]);
	glTexCoord2f(10.0f, 0.0f); glVertex3fv(vertice[7]);
	glEnd();
}


void arbol(GLuint Textura)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, Textura);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(-45, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	glPushMatrix();
	glRotatef(90, 0, 1, 0);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);

	glPopMatrix();
}

void lampara(GLuint Textura)
{
	glPushMatrix();
	glDisable(GL_LIGHTING);
	glEnable(GL_ALPHA_TEST);
	//glDisable(GL_DEPTH_TEST);   // Turn Depth Testing Off
	glAlphaFunc(GL_GREATER, 0.1);
	//glEnable(GL_BLEND);     // Turn Blending On
	//glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
	glBindTexture(GL_TEXTURE_2D, Textura);
	glBegin(GL_QUADS); //plano
	glColor3f(1.0, 1.0, 1.0);
	glNormal3f(0.0f, 0.0f, 1.0f);
	glTexCoord2f(0.0f, 0.0f); glVertex3f(-10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 0.0f); glVertex3f(10.0, 0.0, 0.0);
	glTexCoord2f(1.0f, 1.0f); glVertex3f(10.0, 20.0, 0.0);
	glTexCoord2f(0.0f, 1.0f); glVertex3f(-10.0, 20.0, 0.0);
	glEnd();
	glPopMatrix();

	
	glDisable(GL_ALPHA_TEST);
	//glDisable(GL_BLEND);        // Turn Blending Off
	//glEnable(GL_DEPTH_TEST);    // Turn Depth Testing On
	glEnable(GL_LIGHTING);
	
	glPopMatrix();
}


void InitGL(GLvoid)     // Inicializamos parametros
{
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);				// Negro de fondo	

	glEnable(GL_TEXTURE_2D);

	glShadeModel(GL_SMOOTH);
	glLightfv(GL_LIGHT1, GL_POSITION, Position);
	glLightfv(GL_LIGHT1, GL_DIFFUSE, Diffuse);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glEnable(GL_COLOR_MATERIAL);

	glClearDepth(1.0f);									// Configuramos Depth Buffer
	glEnable(GL_DEPTH_TEST);							// Habilitamos Depth Testing
	glDepthFunc(GL_LEQUAL);								// Tipo de Depth Testing a realizar
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	/* setup blending */
	glEnable(GL_BLEND);			// Turn Blending On

	text1.LoadBMP("01.bmp");
	text1.BuildGLTexture();
	text1.ReleaseImage();

	
	//Nuevas Texturas
	ParedInterior.LoadTGA("Texturas/ParedInterior.tga");
	ParedInterior.BuildGLTexture();
	ParedInterior.ReleaseImage();

	ParedExt.LoadTGA("Texturas/ParedDur.tga");
	ParedExt.BuildGLTexture();
	ParedExt.ReleaseImage();

	Escaleras.LoadTGA("Texturas/Escaleras.tga");
	Escaleras.BuildGLTexture();
	Escaleras.ReleaseImage();
	
	TechoBlanco.LoadTGA("Texturas/TechoBlanco.tga");
	TechoBlanco.BuildGLTexture();
	TechoBlanco.ReleaseImage();

	PisoLadrilloGris.LoadTGA("Texturas/PisoLadrilloGris.tga");
	PisoLadrilloGris.BuildGLTexture();
	PisoLadrilloGris.ReleaseImage();

	PastoJardinera.LoadTGA("Texturas/pasto1.tga");
	PastoJardinera.BuildGLTexture();
	PastoJardinera.ReleaseImage();

	TierraJardinera.LoadTGA("Texturas/TierraJardinera.tga");
	TierraJardinera.BuildGLTexture();
	TierraJardinera.ReleaseImage();

	Terreno.LoadTGA("Texturas/Suelo.tga");
	Terreno.BuildGLTexture();
	Terreno.ReleaseImage();

	VidrioAzul.LoadTGA("Texturas/VidrioAzul.tga");
	VidrioAzul.BuildGLTexture();
	VidrioAzul.ReleaseImage();

	VidrioAzulPuerta.LoadTGA("Texturas/VidrioAzulPuerta.tga");
	VidrioAzulPuerta.BuildGLTexture();
	VidrioAzulPuerta.ReleaseImage();

	arbolFrente.LoadTGA("Texturas/ArbolFrente.tga");
	arbolFrente.BuildGLTexture();
	arbolFrente.ReleaseImage();

	arbolAtras.LoadTGA("Texturas/ArbolAtras.tga");
	arbolAtras.BuildGLTexture();
	arbolAtras.ReleaseImage();
	
	BoteBasura.LoadTGA("Texturas/BoteBasura.tga");
	BoteBasura.BuildGLTexture();
	BoteBasura.ReleaseImage();

	BoteBasuraB.LoadTGA("Texturas/BoteBasuraB.tga");
	BoteBasuraB.BuildGLTexture();
	BoteBasuraB.ReleaseImage();

	Hidrante.LoadTGA("Texturas/Hidrante.tga");
	Hidrante.BuildGLTexture();
	Hidrante.ReleaseImage();
	
	EntradaAzulPuerta.LoadTGA("Texturas/EntradaAzulPuerta.tga");
	EntradaAzulPuerta.BuildGLTexture();
	EntradaAzulPuerta.ReleaseImage();

	EntradaAzul.LoadTGA("Texturas/EntradaAzul.tga");
	EntradaAzul.BuildGLTexture();
	EntradaAzul.ReleaseImage();

	Concreto.LoadTGA("Texturas/Concreto.tga");
	Concreto.BuildGLTexture();
	Concreto.ReleaseImage();

	Lampara.LoadTGA("Texturas/Lampara.tga");
	Lampara.BuildGLTexture();
	Lampara.ReleaseImage();

	PuertaCafe.LoadTGA("Texturas/PuertaCafe.tga");
	PuertaCafe.BuildGLTexture();
	PuertaCafe.ReleaseImage();

	PuertaCafeSola.LoadTGA("Texturas/PuertaCafeSola.tga");
	PuertaCafeSola.BuildGLTexture();
	PuertaCafeSola.ReleaseImage();

	PupitreIzq.LoadTGA("Texturas/PupiIzq.tga");
	PupitreIzq.BuildGLTexture();
	PupitreIzq.ReleaseImage();

	PupitreDer.LoadTGA("Texturas/PupiDer.tga");
	PupitreDer.BuildGLTexture();
	PupitreDer.ReleaseImage();

	PupitreAtras.LoadTGA("Texturas/PupiAtras.tga");
	PupitreAtras.BuildGLTexture();
	PupitreAtras.ReleaseImage();

	PupitreFrente.LoadTGA("Texturas/PupiFrente.tga");
	PupitreFrente.BuildGLTexture();
	PupitreFrente.ReleaseImage();

	PupitreSup.LoadTGA("Texturas/PupiSup.tga");
	PupitreSup.BuildGLTexture();
	PupitreSup.ReleaseImage();

	ProyIzq.LoadTGA("Texturas/ProyL.tga");
	ProyIzq.BuildGLTexture();
	ProyIzq.ReleaseImage();

	ProyDer.LoadTGA("Texturas/ProyR.tga");
	ProyDer.BuildGLTexture();
	ProyDer.ReleaseImage();

	ProySup.LoadTGA("Texturas/ProyArriba.tga");
	ProySup.BuildGLTexture();
	ProySup.ReleaseImage();

	ProyFrente.LoadTGA("Texturas/ProyF.tga");
	ProyFrente.BuildGLTexture();
	ProyFrente.ReleaseImage();

	ProyAtras.LoadTGA("Texturas/ProyT.tga");
	ProyAtras.BuildGLTexture();
	ProyAtras.ReleaseImage();

	MesaAtras.LoadTGA("Texturas/MesaAtras.tga");
	MesaAtras.BuildGLTexture();
	MesaAtras.ReleaseImage();

	MesaFrente.LoadTGA("Texturas/MesaFrente3.tga");
	MesaFrente.BuildGLTexture();
	MesaFrente.ReleaseImage();

	MesaLat.LoadTGA("Texturas/MesaLat.tga");
	MesaLat.BuildGLTexture();
	MesaLat.ReleaseImage();

	MesaSup.LoadTGA("Texturas/MesaSup1.tga");
	MesaSup.BuildGLTexture();
	MesaSup.ReleaseImage();

	Pizarra.LoadTGA("Texturas/Pizarra.tga");
	Pizarra.BuildGLTexture();
	Pizarra.ReleaseImage();
	
	//Modelos
	Helicop._3dsLoad("Modelos/md500.3ds");
	Aves._3dsLoad("Modelos/bird.3ds");

	objCamera.Position_Camera(0, 2.5f, 3, 0, 2.5f, 0, 0, 1, 0);

}


void display(void)   // Creamos la funcion donde se dibuja
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glPushMatrix(); //Todo
		glRotatef(g_lookupdown, 1.0f, 0, 0);

		gluLookAt(objCamera.mPos.x, objCamera.mPos.y, objCamera.mPos.z,
			objCamera.mView.x, objCamera.mView.y, objCamera.mView.z,
			objCamera.mUp.x, objCamera.mUp.y, objCamera.mUp.z);

		glPushMatrix(); //Principal
			glPushMatrix(); //Creamos cielo
			glDisable(GL_LIGHTING);
			glTranslatef(0, 60, 0);
			sky.skybox(200, 150, 200, text1.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //Suelo
				glTranslatef(0, -1, 0);
				glDisable(GL_LIGHTING);
				Suelo(1, 200, 200, Terreno.GLindex);
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix();//BoteBasura
			glDisable(GL_LIGHTING);
			glTranslatef(-62, -0.5, 62);
			objeto.cilindro(.2, 0.5, 20, BoteBasuraB.GLindex, BoteBasura.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();//BoteBasura

			glPushMatrix();//BoteBasuraDer
			glDisable(GL_LIGHTING);
			glTranslatef(62, -0.5, 62);
			objeto.cilindro(.2, 0.5, 20, BoteBasuraB.GLindex, BoteBasura.GLindex);
			glEnable(GL_LIGHTING);
			glPopMatrix();//BoteBasuraDer

			glPushMatrix();//LamparaIzq
			glTranslatef(-62, -0.5, 62);
			//	objeto.cilindro_nb(.2, 5, 20, 0, Lampara.GLindex);
			glScalef(0.25,0.25,0.25);
			lampara(Lampara.GLindex);
			
			glPopMatrix();//LamparaIzq



			glPushMatrix();//ArbolFrenteIzq
				glTranslatef(-57, 0.5, 45);
				arbol(arbolFrente.GLindex);
			glPopMatrix();//ArbolFrenteIzq

			glPushMatrix();//ArbolFrenteDer
				glTranslatef(57, 0.5, 45);
				arbol(arbolFrente.GLindex);
			glPopMatrix();//ArbolFrenteDer

			glPushMatrix();//ArbolAtrasIzq
				glTranslatef(35, 0.5, -30);
				arbol(arbolAtras.GLindex);
			glPopMatrix();//ArbolAtrasIzq

			glPushMatrix();//ArbolAtrasIzq
				glTranslatef(-35, 0.5, -30);
				arbol(arbolAtras.GLindex);
			glPopMatrix();//ArbolAtrasIzq

			glDisable(GL_LIGHTING);
			glPushMatrix();//Jardinera2Izq
				glTranslatef(-64.5, -0.5, 12);
				glRotatef(180, 0, 1, 0);
				glRotatef(180, 0, 0, 1);
				Jardinera2(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//Jardinera2Izq

			glPushMatrix();//Jardinera2Der
			glTranslatef(64.5, 0.5, 12);
			glRotatef(180, 0, 1, 0);
			Jardinera2(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//Jardinera2Der

			glPushMatrix();//Jardinera3Izq
				glRotatef(-90, 0, 1, 0);
				glTranslatef(-38, 0.5,20);
				Jardinera2(TierraJardinera.GLindex, PastoJardinera.GLindex);
				glTranslatef(6.75, -1, 0);
				glRotatef(180, 0, 1, 0);
				objeto.m_cilindro(6.75,1,20,PastoJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();//Jardinera3

			glPushMatrix();//Jardinera3Der
			glRotatef(180,0,0,1);
			glRotatef(-90, 0, 1, 0);

			glTranslatef(-38,0.5,20);
			Jardinera2(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glTranslatef(6.75, -1, 0);
			glRotatef(180, 0, 1, 0);
			objeto.m_cilindro(6.75, 1, 20, PastoJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();//Jardinera3Der

			glPushMatrix();//Jardinera5Izq
			glRotatef(-90,0,1,0);
			glTranslatef(21.2, -0.5, 9.5);
			objeto.c4_cilindro(19, 1, 20, PastoJardinera.GLindex, TierraJardinera.GLindex);
			glPushMatrix();
			glTranslatef(9.5, .5, 0);
			Pared(1, 19, .01, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();
			glTranslatef(0, .5, 9.5);
			Pared(1, 0.01, 19, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();//Jardinera5Izq

			glPushMatrix();//Jardinera5Der
			//glRotatef(0, 0, 1, 0);
			glTranslatef(9.5, -0.5, 21.2);
			objeto.c4_cilindro(19, 1, 20, PastoJardinera.GLindex, TierraJardinera.GLindex);
			glPushMatrix();
			glTranslatef(9.5, .5, 0);
			Pared(1, 19, .01, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();
			glTranslatef(0, .5, 9.5);
			Pared(1, 0.01, 19, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex, TierraJardinera.GLindex);
			glPopMatrix();//Jardinera5Der
			
			glPushMatrix(); //JardineraM1Izq
			glTranslatef(-64,0.5,21.1);//0.5
			//glScalef(.5,1,.5);
			JardineraMi(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//JardineraM1Izq

			glPushMatrix(); //JardineraM1DER
			glRotatef(180,0,0,1);
			glTranslatef(-64, 0.5, 21.1);
			//glScalef(.5,1,.5);
			JardineraMi(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//JardineraM1DER
			
			glPushMatrix();//Jardinera6Izq
			glRotatef(180, 0, 0, 1);
				glTranslatef(18,0.5,65);
				Jardinera6(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//Jardinera6Izq

			glPushMatrix();//Jardinera6Der
//			glRotatef(180, 0, 0, 1);
			glTranslatef(18, 0.5, 65);
			Jardinera6(TierraJardinera.GLindex, PastoJardinera.GLindex);
			glPopMatrix();//Jardinera6Der
			glEnable(GL_LIGHTING);
			
			
			glPushMatrix(); //HELI
				glDisable(GL_COLOR_MATERIAL);
				glEnable(GL_LIGHTING);
				glEnable(GL_ALPHA_TEST);
				glAlphaFunc(GL_GREATER, 0.2);
				glEnable(GL_BLEND);
				glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
				glTranslatef(-90, 80 ,-80 );
				glTranslatef(movHeliX, 0, 0);
				glTranslatef(0, movHeliY, 0);
				glTranslatef(0, 0, movHeliZ);
				glRotatef(giro_heli,0,1,0);
				glScalef(3,3,3);
				glRotatef(90,0,1,0);
				Helicop.GLrender(NULL, _SHADED, 1.0);
				glDisable(GL_BLEND);
			glPopMatrix(); //HELI
			
			glPushMatrix(); //Ave
			glTranslatef(0, 50, -35);
			glScalef(0.1,0.1,0.1);
			glRotatef(180, 0, 0, 1);
			Aves.GLrender(NULL, _SHADED, 1.0);
			glPopMatrix(); //Ave
			
			glPushMatrix(); //Pupitres
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.2);
				glTranslatef(-49, 0.7, 5);
				Pupitre(0.5, 0.4, 0.4,PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//1
				glTranslatef(1.2,0,0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//2
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//3
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//4
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//5
				glTranslatef(0, 0, 1.5);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//6
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//7
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//8
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//9
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//10
				glTranslatef(0, 0, 1.5);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//11
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//12
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//13
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//14
				glTranslatef(1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//15
				glTranslatef(0, 0, 1.5);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//16
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//17
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//18
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//19
				glTranslatef(-1.2, 0, 0);
				Pupitre(0.5, 0.4, 0.4, PupitreAtras.GLindex,PupitreDer.GLindex,PupitreFrente.GLindex,PupitreIzq.GLindex,0,PupitreSup.GLindex);//20
				glDisable(GL_ALPHA_TEST);
			glPopMatrix();//Pupitres

			glPushMatrix(); //Mesa
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.2);
			glTranslatef(-50, 1.3, 1.5);
			Pared(1.0, 1, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix(); //Mesa

			glPushMatrix(); //Mesa Labo
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.2);
			glTranslatef(-45, 1.3, 13);
			Pared(1.0, 1, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glDisable(GL_ALPHA_TEST);
			glPopMatrix(); //Mesa

			glPushMatrix(); //Mesas Labo alumnos
			glEnable(GL_ALPHA_TEST);
			glAlphaFunc(GL_GREATER, 0.2);
			glTranslatef(-43.5, 1.3, 15);
			glRotatef(180,0,1,0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			//Lado2

			glTranslatef(1.2, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			//Segunda fila
			glTranslatef(0, 0, -1.5);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			//Lado2
			glTranslatef(-1.2, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(-0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			//Tercerafila
			glTranslatef(0, 0, -1.5);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			//Lado 2
			glTranslatef(1.2, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);
			glTranslatef(0.9, 0, 0);
			Pared(1.0, .8, .4, MesaAtras.GLindex, MesaLat.GLindex, MesaFrente.GLindex, MesaLat.GLindex, MesaSup.GLindex, MesaSup.GLindex);





			glDisable(GL_ALPHA_TEST);
			glPopMatrix(); //Mesa



			glPushMatrix(); //Pizarron
			glTranslatef(-47, 1.8, 1.5);
			Pared(1.5, 2, 0.05, Pizarra.GLindex, 1, 0, 0, 0, 0);
			glPopMatrix(); //Pizarron

			glPushMatrix(); //Proyector
			glTranslatef(-47, 4.8, 7);
			Pared(.2, .30, .30, ProyAtras.GLindex, ProyDer.GLindex, ProyFrente.GLindex, ProyIzq.GLindex, ProySup.GLindex, 0);
			glPopMatrix(); //Proyector

			glPushMatrix(); //EdIzquierdo
				glTranslatef(-30.2, 0, 0);
				glDisable(GL_LIGHTING);
				Techo(1, 42.0, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, PisoLadrilloGris.GLindex); //Base
				
				glPushMatrix(); //PlantaBaja
					glPushMatrix(); //Frente
						glTranslatef(0, 3.0, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 3.0, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 3.0, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 3.0, -9.1);
						Pared(5, 0.2, 24, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();

					glPushMatrix(); //Muros1-Parte de arriba
						glTranslatef(-0.7, 3.9, .1);
						Pared(3, 23, 0.2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros1

					glPushMatrix(); //Muros2-lateral-escalera
						glTranslatef(10.75, 2.9,-10.5 );
						Pared(5, .2, 21, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros2

					glPushMatrix(); //Muros2-lateral-Divisorios-Baño
					glTranslatef(6.75, 2.9, -10.5);
					Pared(5, .2, 21, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros2

					glPushMatrix(); //Muros3-Parte de arriba-Conserje
					glTranslatef(8.8, 1.5, 0);
					Pared(2, 4, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3

					glPushMatrix(); //Muros2-lateral-Divisorios-LaboMultimea-Baño
					glTranslatef(0.75, 2.9, -10.5);
					Pared(5, .2, 21, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros2

					glPushMatrix(); //Muros3-ParteAbajo-ParedBaño
					glTranslatef(4.3, 1.5, 0);
					Pared(2, 5, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-3.1, 0, 0);
					Pared(2,1.2 , .2, PuertaCafe.GLindex, ParedInterior.GLindex, PuertaCafe.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3

					glPushMatrix(); //Muros3-ParteAbajo-Multimedi
					glTranslatef(-1.3, 1.5, 0);
					Pared(2, 4, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-2.5, 0, 0);
					Pared(2, 1.0, .2, PuertaCafeSola.GLindex, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-1.75, 0, 0);
					Pared(2, 2.5, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3

					glPushMatrix(); //Muros3-ParteAbajo-Otro
					glTranslatef(-8.5, 1.5, 0);
					Pared(2, 4, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-2.5, 0, 0);
					Pared(2, 1.0, .2, PuertaCafeSola.GLindex, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-1.0, 0, 0);
					Pared(2, 1.0, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(-4.6, 1.5, 0);
					Pared(5, 8.6, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(0, 0, 12);
					Pared(5, 8.6, .2, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3
					

					glPushMatrix(); //Muros2-lateral-Divisorios-LaboMultimea-Baño
					glTranslatef(-6.75, 2.9, -10.5);
					Pared(5, .2, 21, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros2

					glPushMatrix(); //Muros3-Parte de arriba
					glTranslatef(-12.3, 3.9, 0);
					Pared(3, .2, 41.8, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3

					glPushMatrix(); //Muros3-ParteAbajo-Lateral
					glTranslatef(-12.3, 1.5, 4);
					Pared(2, .2, 8, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(0, -.05, 4.5);
					Pared(1.95, .2, 1, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(0, 0.0, 4.5);
					Pared(2, .2, 8, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(0, 0.0, 4.5);
					Pared(1.95, .2, 1, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, PuertaCafeSola.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glTranslatef(0, 0.0, 2);
					Pared(1.95, .2, 3, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex, ParedInterior.GLindex);
					glPopMatrix();  //Muros3

					glPushMatrix();//Escaleras
						glTranslatef(18.4, .65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(-5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//PlantaBaja

				glPushMatrix(); //PrimerPiso
					glPushMatrix(); //Techo
						glTranslatef(-5, 5.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(20.9, 0, 2.75);
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 8, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 8, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 8, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 8, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(18.4, 5.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(-5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//PrimerPiso

				glPushMatrix(); //SegundoPiso
					glPushMatrix(); //Techo
						glTranslatef(-5, 10.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 13, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 13, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 13, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 13, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(18.4, 10.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(-5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//SegundoPiso

				glPushMatrix(); //TercerPiso
					glPushMatrix(); //Techo
						glTranslatef(-5, 15.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 18, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
						//Pared(5, 41.6, 0.2, 0, 0, 0, 0, 0, 0);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 18, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 18, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 18, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(18.4, 15.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(-5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//TercerPiso
				glPushMatrix(); //CuartoPiso
					glPushMatrix(); //Techo
						glTranslatef(-5, 20.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 23, 21);
						//Pared(5, 41.6, 0.2, prueba.GLindex, 0, 0, 0, 0, 0);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 23, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 23, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 23, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(18.4, 20.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(-5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//CuartoPiso
				glPushMatrix(); //QuintoPiso
				glPushMatrix(); //Techo
				glTranslatef(0, 25.4, 0);
				Techo(.2, 41.8, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, ParedExt.GLindex);
				//glTranslatef(20.9, 0, 10.2);
				//Pared(.2, 9.8, 21.6, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex);
				glPopMatrix();
				glPushMatrix(); //Frente
				glTranslatef(0, 26.25, 21);
				Pared(1.5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				//Pared(1.5, 41.6, 0.2, 0, 0, 0, 0, 0, 0);
				glPopMatrix();
				glPushMatrix(); //Atras
				glTranslatef(0, 26.25, -21);
				Pared(1.5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				glPopMatrix();
				glPushMatrix(); //Izquierdo
				glTranslatef(-20.9, 26.25, 0);
				Pared(1.5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				glPopMatrix();
				glPushMatrix(); //Derecho
				glTranslatef(+20.9, 26.25, 0);
				Pared(1.5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
				glPopMatrix();
				glPopMatrix();//QuintoPiso
				glEnable(GL_LIGHTING);
			glPopMatrix();

			glPushMatrix(); //EdCentro
				glTranslatef(0, 0, 12.0);
				glDisable(GL_LIGHTING);
				Techo(1, 18.6, 18.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, PisoLadrilloGris.GLindex); //Base
				glTranslatef(0,5.4,0);
				Techo(.5, 18.6, 18.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, ParedExt.GLindex); //techo
				glPushMatrix();//Domo
				glTranslatef(-12.5,-1.3,9.5);
					Domo(VidrioAzul.GLindex,VidrioAzulPuerta.GLindex,ParedExt.GLindex);
				glPopMatrix();//Domo
				glPushMatrix();
					glTranslatef(0, -1, 9.0);
					Pared(2, 18.8, .2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, ParedExt.GLindex); //ParedFrente
					glTranslatef(0, -1.5, 0);
					Pared(1, 18.8, .2, EntradaAzul.GLindex, 0, EntradaAzul.GLindex, 0, 0, 0); //EntradaFrontal
					glTranslatef(0, -1.5, 0);
					Pared(2, 18.8, .2, EntradaAzulPuerta.GLindex, 0, EntradaAzulPuerta.GLindex, 0, 0, 0); //EntradaPuertaFrontal
				glPopMatrix();
				glPushMatrix();//Atras
					glTranslatef(0, -1, -9);
					Pared(2, 18.6, .2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, ParedExt.GLindex); //ParedAtras
					glTranslatef(0, -1.5, 0);
					Pared(1, 18.6, .2, EntradaAzul.GLindex, 0, EntradaAzul.GLindex, 0, 0, 0); //Entrada
					glTranslatef(0, -1.5, 0);
					Pared(2, 18.6, .2, EntradaAzulPuerta.GLindex, 0, EntradaAzulPuerta.GLindex, 0, 0, 0); //EntradaPuerta
				glPopMatrix();//Atras

				glPushMatrix();//ParteAtras
				glTranslatef(0, -5.5, -14.2);
				Suelo(1, 18.6, 10, Concreto.GLindex); //Base
				glPushMatrix();//Escaleras
				glEnable(GL_LIGHTING);
					glTranslatef(0, 0.4, -5.5);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
					glTranslatef(0, -0.1, -1);
					Suelo(.2, 18.6, 1, Concreto.GLindex);
				glDisable(GL_LIGHTING);
				glPopMatrix();//Escaleras

				glPopMatrix();//ParteAtras
			glPopMatrix();//EdCentro

			glPushMatrix(); //EdDerecho
				glTranslatef(30.2, 0, 0);
				glDisable(GL_LIGHTING);
				Techo(1, 42.0, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex,PisoLadrilloGris.GLindex);
				
				glPushMatrix();//PlantaBaja
					glPushMatrix(); //Frente
						glTranslatef(0, 3.0, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 3.0, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(20.9, 3.0, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(-20.9, 3.0, -9.1);
						Pared(5, 0.2, 24, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(-18.4, .65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//PlantaBaja

				glPushMatrix(); //PrimerPiso
					glPushMatrix(); //Techo
						glTranslatef(5, 5.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(-20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 8, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 8, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 8, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 8, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(-18.4, 5.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//PrimerPiso

				glPushMatrix(); //SegundoPiso
					glPushMatrix(); //Techo
						glTranslatef(5, 10.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(-20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 13, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 13, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 13, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 13, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(-18.4, 10.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//SegundoPiso

				glPushMatrix(); //TercerPiso
					glPushMatrix(); //Techo
						glTranslatef(5, 15.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(-20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 18, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 18, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 18, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 18, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(-18.4, 15.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//TercerPiso

				glPushMatrix(); //CuartoPiso
					glPushMatrix(); //Techo
						glTranslatef(5, 20.4, 0);
						Techo(.2, 32, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
						glTranslatef(-20.9, 0, 2.75);//Pedacito
						Techo(.2, 9.8, 36.5, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, PisoLadrilloGris.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 23, 21);
						Pared(5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 23, -21);
						Pared(5, 41.6, 0.2, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 23, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 23, 0);
						Pared(5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedInterior.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix();//Escaleras
						glTranslatef(-18.4, 20.65, -15.6);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //1
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //2
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //3
						glTranslatef(0.0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //4
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //5
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //6
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //7
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //8
						glTranslatef(0, .25, -.5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //9
						glTranslatef(0, .25, -.75);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //10
						glTranslatef(5, 0, 0);
						Pared(.25, 5, 1, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //11-Descanso
						glTranslatef(0, .25, .75);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //12
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //13
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //14
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //15
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //16
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //17
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //18
						glTranslatef(0, .25, .5);
						Pared(.25, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //19
						glTranslatef(0, .28, .5);
						Pared(.3, 5, .5, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex, Escaleras.GLindex); //20
					glPopMatrix();//Escaleras
				glPopMatrix();//CuartoPiso
				glPushMatrix(); //QuintoPiso
					glPushMatrix(); //Techo
						glTranslatef(0, 25.4, 0);
						Techo(.2, 41.8, 41.8, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, TechoBlanco.GLindex, ParedExt.GLindex);
						//glTranslatef(20.9, 0, 10.2);
						//Pared(.2, 9.8, 21.6, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex, prueba.GLindex);
					glPopMatrix();
					glPushMatrix(); //Frente
						glTranslatef(0, 26.25, 21);
						Pared(1.5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
						//Pared(1.5, 41.6, 0.2, 0, 0, 0, 0, 0, 0);
					glPopMatrix();
					glPushMatrix(); //Atras
						glTranslatef(0, 26.25, -21);
						Pared(1.5, 41.6, 0.2, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Izquierdo
						glTranslatef(-20.9, 26.25, 0);
						Pared(1.5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glPushMatrix(); //Derecho
						glTranslatef(+20.9, 26.25, 0);
						Pared(1.5, 0.2, 42.0, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex, ParedExt.GLindex);
					glPopMatrix();
					glEnable(GL_LIGHTING);
				glPopMatrix();//QuintoPiso

			glPopMatrix();

			

		glPopMatrix(); //Principal
		
	glPopMatrix(); //Todo

	glutSwapBuffers();

}

void animacion()
{
	if (g_fanimacion) {
		
			
			switch (estado) {
			case 0:
				printf("Entra edo 0\n");
			/*	movKit = 0;
				movKitY = 0;*/
				estado = 1;
				break;
			case 1:
				printf("Entra edo 1\n");
				if (movHeliX < 130) {
					movHeliX += 1.6;
					if (movHeliX >= 130) {
						giro_heli = -90;
						estado = 2;
					}
				}
				
				
				break;
			case 2:
				printf("Entra edo 2\n");
				
				if (movHeliZ < 70) {
					movHeliZ += 1.6;
					if (movHeliZ >= 70) {
						giro_heli = 180;
						//movHeliX = 0;
						estado = 3;
					}
				}		
				break;
			case 3:
				printf("Entra edo 3\n");
				if (movHeliY < -10) {
					movHeliY -= 0.6;
					if (movHeliZ <= -10) {
						
						//movHeliX = 0;
						
					}
				}
				break;

			case 4:
				printf("Entra edo 4\n");
				
				
				break;

			default:
				printf("SALIO");
				break;
			}
	}

	glutPostRedisplay();
}

void reshape(int width, int height)   // Creamos funcion Reshape
{
	if (height == 0)										// Prevenir division entre cero
	{
		height = 1;
	}

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);						// Seleccionamos Projection Matrix
	glLoadIdentity();

	// Tipo de Vista

	glFrustum(-0.1, 0.1, -0.1, 0.1, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);							// Seleccionamos Modelview Matrix
	glLoadIdentity();
}

void keyboard(unsigned char key, int x, int y)  // Create Keyboard Function
{
	switch (key) {

	case 'w':   //Movimientos de camara
	case 'W':
		objCamera.Move_Camera(CAMERASPEED + 0.2);
		break;

	case 's':
	case 'S':
		objCamera.Move_Camera(-(CAMERASPEED + 0.2));
		break;

	case 'a':
	case 'A':
		objCamera.Strafe_Camera(-(CAMERASPEED + 0.4));
		break;

	case 'd':
	case 'D':
		objCamera.Strafe_Camera(CAMERASPEED + 0.4);
		break;

	case ' ':		//Poner algo en movimiento
		g_fanimacion ^= true; //Activamos/desactivamos la animacíon

		
		break;

	case 27:        // Cuando Esc es presionado...
		exit(0);   // Salimos del programa
		break;
	default:        // Cualquier otra
		break;
	}

	glutPostRedisplay();
}

void arrow_keys(int a_keys, int x, int y)  // Funcion para manejo de teclas especiales (arrow keys)
{
	switch (a_keys) {
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
		objCamera.Rotate_View(CAMERASPEED);
		break;

	default:
		break;
	}
	glutPostRedisplay();
}

int main(int argc, char** argv)   // Main Function
{

	glutInit(&argc, argv); // Inicializamos OpenGL
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH); // Display Mode (Clores RGB y alpha | Buffer Doble )
	glutInitWindowSize(2000, 2000);	// Tamaño de la Ventana
	glutInitWindowPosition(0, 0);	//Posicion de la Ventana
	glutCreateWindow("Proyecto"); // Nombre de la Ventana
								   //glutFullScreen     ( );         // Full Screen
	InitGL();						// Parametros iniciales de la aplicacion
	glutDisplayFunc(display);  //Indicamos a Glut función de dibujo
	glutReshapeFunc(reshape);	//Indicamos a Glut función en caso de cambio de tamano
	glutKeyboardFunc(keyboard);	//Indicamos a Glut función de manejo de teclado
	glutSpecialFunc(arrow_keys);	//Otras
	glutIdleFunc(animacion);


	glutMainLoop();          // 

	return 0;
}

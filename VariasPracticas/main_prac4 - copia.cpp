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
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

		
		//glTranslatef(transX, transY, transZ);
		//glRotatef(angleY, 0.0f, 1.0f, 0.0f);
		//glRotatef(angleX, 1.0f, 0.0f, 0.0f);
		//glRotatef(angleZ, 0.0f, 0.0f, 1.0f);
		//Poner Código Aquí.
	glBegin(GL_POINTS);
	glColor3f(0.0625, 0.09765625, 0.28125);
	glVertex3f(188.05, 491.7, -1.2);
	glVertex3f(423.7, 492.13, -1.2);
	glVertex3f(431.09, 490.95, -1.2);
	glVertex3f(435.54, 490.15, -1.2);
	glVertex3f(439.42, 489.13, -1.2);
	glVertex3f(443.36, 488.03, -1.2);
	glVertex3f(446.59, 486.98, -1.2);
	glVertex3f(449.39, 485.99, -1.2);
	glVertex3f(451.96, 484.9, -1.2);
	glVertex3f(454.24, 484.02, -1.2);
	glVertex3f(456.36, 483.12, -1.2);
	glVertex3f(458.74, 482.06, -1.2);
	glVertex3f(460.6, 481.03, -1.2);
	glVertex3f(462.3, 480.03, -1.2);
	glVertex3f(464.14, 479.06, -1.2);
	glVertex3f(466.13, 477.95, -1.2);
	glVertex3f(467.34, 477.07, -1.2);
	glVertex3f(469.29, 475.9, -1.2);
	glVertex3f(470.32, 475.16, -1.2);
	glVertex3f(471.85, 474.14, -1.2);
	glVertex3f(473.1, 473.19, -1.2);
	glVertex3f(474.65, 471.98, -1.2);
	glVertex3f(476.13, 470.96, -1.2);
	glVertex3f(477.08, 470.05, -1.2);
	glVertex3f(478.38, 469.04, -1.2);
	glVertex3f(480.13, 467.93, -1.2);
	glVertex3f(481.05, 467.04, -1.2);
	glVertex3f(481.98, 466.13, -1.2);
	glVertex3f(484.39, 464.01, -1.2);
	glVertex3f(486.32, 461.81, -1.2);
	glVertex3f(489.1, 459.29, -1.2);
	glVertex3f(491.25, 456.88, -1.2);
	glVertex3f(493.37, 454.29, -1.2);
	glVertex3f(495.03, 451.98, -1.2);
	glVertex3f(496.96, 449.59, -1.2);
	glVertex3f(498.67, 447.32, -1.2);
	glVertex3f(499.92, 445.81, -1.2);
	glVertex3f(502.04, 443.12, -1.2);
	glVertex3f(503.19, 441.03, -1.2);
	glVertex3f(504.32, 438.91, -1.2);
	glVertex3f(505.47, 436.9, -1.2);
	glVertex3f(506.89, 434.33, -1.2);
	glVertex3f(508.2, 431.6, -1.2);
	glVertex3f(509.27, 429.11, -1.2);
	glVertex3f(510.5, 425.71, -1.2);
	glVertex3f(512.03, 421.88, -1.2);
	glVertex3f(513.61, 417.54, -1.2);
	glVertex3f(514.25, 414.8, -1.2);
	glVertex3f(515.33, 410.2, -1.2);
	glVertex3f(516.37, 406.02, -1.2);
	glVertex3f(517.33, 401.81, -1.2);
	glVertex3f(518.17, 396.46, -1.2);
	glVertex3f(518.19, 393.78, -1.2);
	glVertex3f(517.23, 371.87, -1.2);
	glVertex3f(516.1, 365.55, -1.2);
	glVertex3f(515.25, 361.58, -1.2);
	glVertex3f(513.96, 357.27, -1.2);
	glVertex3f(513.13, 353.74, -1.2);
	glVertex3f(512.14, 351.0, -1.2);
	glVertex3f(511.15, 348.14, -1.2);
	glVertex3f(510.16, 345.78, -1.2);
	glVertex3f(509.06, 342.89, -1.2);
	glVertex3f(508.17, 341.01, -1.2);
	glVertex3f(507.1, 338.74, -1.2);
	glVertex3f(505.98, 336.78, -1.2);
	glVertex3f(505.09, 334.93, -1.2);
	glVertex3f(504.08, 333.49, -1.2);
	glVertex3f(502.04, 329.95, -1.2);
	glVertex3f(500.11, 327.11, -1.2);
	glVertex3f(499.01, 325.59, -1.2);
	glVertex3f(496.95, 321.73, -1.2);
	glVertex3f(495.77, 319.8, -1.2);
	glVertex3f(494.33, 317.36, -1.2);
	glVertex3f(491.7, 312.19, -1.2);
	glVertex3f(488.84, 307.53, -1.2);
	glVertex3f(487.2, 304.69, -1.2);
	glVertex3f(485.78, 302.31, -1.2);
	glVertex3f(484.07, 299.28, -1.2);
	glVertex3f(482.81, 297.17, -1.2);
	glVertex3f(481.02, 294.06, -1.2);
	glVertex3f(479.6, 291.41, -1.2);
	glVertex3f(478.15, 288.7, -1.2);
	glVertex3f(393.22, 139.86, -1.2);
	glVertex3f(386.57, 130.97, -1.2);
	glVertex3f(377.57, 121.65, -1.2);
	glVertex3f(368.47, 114.69, -1.2);
	glVertex3f(359.36, 108.37, -1.2);
	glVertex3f(351.54, 104.4, -1.2);
	glVertex3f(343.72, 101.83, -1.2);
	glVertex3f(338.79, 100.01, -1.2);
	glVertex3f(332.04, 98.24, -1.2);
	glVertex3f(319.02, 95.56, -1.2);
	glVertex3f(313.51, 95.35, -1.2);
	glVertex3f(296.26, 95.29, -1.2);
	glVertex3f(287.36, 96.53, -1.2);
	glVertex3f(280.29, 98.19, -1.2);
	glVertex3f(273.18, 100.65, -1.2);
	glVertex3f(265.56, 103.76, -1.2);
	glVertex3f(257.0, 107.81, -1.2);
	glVertex3f(249.88, 112.02, -1.2);
	glVertex3f(245.15, 115.11, -1.2);
	glVertex3f(239.1, 119.83, -1.2);
	glVertex3f(232.89, 125.56, -1.2);
	glVertex3f(226.56, 132.31, -1.2);
	glVertex3f(221.88, 138.15, -1.2);
	glVertex3f(218.23, 143.43, -1.2);
	glVertex3f(216.13, 146.83, -1.2);
	glVertex3f(202.8, 170.43, -1.2);
	glVertex3f(193.86, 186.34, -1.2);
	glVertex3f(102.87, 341.6, -1.2);
	glVertex3f(97.3, 355.75, -1.2);
	glVertex3f(94.99, 370.27, -1.2);
	glVertex3f(94.01, 379.59, -1.2);
	glVertex3f(93.93, 395.06, -1.2);
	glVertex3f(95.0, 402.94, -1.2);
	glVertex3f(96.18, 410.33, -1.2);
	glVertex3f(99.28, 419.38, -1.2);
	glVertex3f(101.96, 426.56, -1.2);
	glVertex3f(105.34, 433.47, -1.2);
	glVertex3f(109.46, 441.03, -1.2);
	glVertex3f(115.46, 449.87, -1.2);
	glVertex3f(120.93, 456.99, -1.2);
	glVertex3f(125.37, 461.38, -1.2);
	glVertex3f(132.6, 467.54, -1.2);
	glVertex3f(140.1, 473.28, -1.2);
	glVertex3f(148.09, 478.36, -1.2);
	glVertex3f(157.51, 483.08, -1.2);
	glVertex3f(168.39, 487.31, -1.2);
	glVertex3f(178.73, 490.36, -1.2);
	glEnd();
	/*glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(375.82, 391.12, -1.2);
	glVertex3f(332.77, 391.11, -1.2);
	glVertex3f(331.33, 390.68, -1.2);
	glVertex3f(330.12, 390.09, -1.2);
	glVertex3f(328.89, 389.18, -1.2);
	glVertex3f(327.5, 387.38, -1.2);
	glVertex3f(326.05, 384.87, -1.2);
	glVertex3f(325.68, 382.19, -1.2);
	glVertex3f(325.78, 379.51, -1.2);
	glVertex3f(327.34, 376.56, -1.2);
	glVertex3f(329.26, 374.9, -1.2);
	glVertex3f(331.84, 373.35, -1.2);
	glVertex3f(355.78, 373.3, -1.2);
	glVertex3f(381.82, 373.3, -1.2);
	glVertex3f(381.07, 377.85, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(280.29, 405.46, -1.2);
	glVertex3f(339.75, 405.14, -1.2);
	glVertex3f(341.25, 405.56, -1.2);
	glVertex3f(342.43, 406.05, -1.2);
	glVertex3f(343.61, 407.06, -1.2);
	glVertex3f(344.63, 408.14, -1.2);
	glVertex3f(345.92, 409.9, -1.2);
	glVertex3f(346.67, 411.24, -1.2);
	glVertex3f(347.31, 413.28, -1.2);
	glVertex3f(347.2, 415.58, -1.2);
	glVertex3f(346.83, 418.96, -1.2);
	glVertex3f(345.81, 421.05, -1.2);
	glVertex3f(344.9, 422.22, -1.2);
	glVertex3f(342.0, 424.53, -1.2);
	glVertex3f(339.17, 425.76, -1.2);
	glVertex3f(337.4, 426.03, -1.2);
	glVertex3f(281.53, 426.03, -1.2);
	glVertex3f(278.85, 425.33, -1.2);
	glVertex3f(277.08, 423.62, -1.2);
	glVertex3f(274.94, 421.53, -1.2);
	glVertex3f(273.54, 418.9, -1.2);
	glVertex3f(273.12, 416.33, -1.2);
	glVertex3f(273.44, 412.31, -1.2);
	glVertex3f(274.62, 409.74, -1.2);
	glVertex3f(276.6, 407.49, -1.2);
	glVertex3f(278.47, 406.31, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(286.64, 289.43, -1.2);
	glVertex3f(281.58, 357.03, -1.2);
	glVertex3f(337.27, 357.02, -1.2);
	glVertex3f(332.59, 289.17, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(353.54, 373.32, -1.2);
	glVertex3f(348.29, 313.59, -1.2);
	glVertex3f(396.42, 314.06, -1.2);
	glVertex3f(381.81, 373.31, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(348.3, 313.6, -1.2);
	glVertex3f(368.47, 289.44, -1.2);
	glVertex3f(404.78, 289.64, -1.2);
	glVertex3f(396.41, 314.07, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(332.59, 289.17, -1.2);
	glVertex3f(404.79, 289.64, -1.2);
	glVertex3f(414.0, 269.82, -1.2);
	glVertex3f(415.07, 265.75, -1.2);
	glVertex3f(414.75, 254.61, -1.2);
	glVertex3f(413.57, 251.18, -1.2);
	glVertex3f(410.89, 246.47, -1.2);
	glVertex3f(408.49, 243.0, -1.2);
	glVertex3f(405.95, 240.06, -1.2);
	glVertex3f(402.9, 237.08, -1.2);
	glVertex3f(399.42, 234.64, -1.2);
	glVertex3f(395.68, 232.32, -1.2);
	glVertex3f(392.18, 230.17, -1.2);
	glVertex3f(388.63, 228.68, -1.2);
	glVertex3f(386.28, 227.93, -1.2);
	glVertex3f(369.31, 227.24, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(310.59, 289.29, -1.2);
	glVertex3f(311.96, 213.58, -1.2);
	glVertex3f(326.59, 213.91, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(310.59, 289.29, -1.2);
	glVertex3f(326.58, 213.91, -1.2);
	glVertex3f(335.37, 215.88, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(335.37, 215.88, -1.2);
	glVertex3f(344.77, 220.58, -1.2);
	glVertex3f(310.59, 289.28, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(344.76, 220.58, -1.2);
	glVertex3f(356.9, 225.43, -1.2);
	glVertex3f(310.57, 289.31, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(356.9, 225.43, -1.2);
	glVertex3f(369.32, 227.27, -1.2);
	glVertex3f(332.59, 289.17, -1.2);
	glVertex3f(310.58, 289.3, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(286.67, 289.44, -1.2);
	glVertex3f(214.85, 290.06, -1.2);
	glVertex3f(205.18, 270.01, -1.2);
	glVertex3f(204.09, 265.94, -1.2);
	glVertex3f(204.26, 260.22, -1.2);
	glVertex3f(204.6, 254.71, -1.2);
	glVertex3f(205.62, 251.37, -1.2);
	glVertex3f(208.37, 246.66, -1.2);
	glVertex3f(210.77, 243.16, -1.2);
	glVertex3f(213.52, 240.14, -1.2);
	glVertex3f(217.05, 236.98, -1.2);
	glVertex3f(220.29, 234.5, -1.2);
	glVertex3f(223.96, 232.52, -1.2);
	glVertex3f(227.22, 230.5, -1.2);
	glVertex3f(231.17, 228.88, -1.2);
	glVertex3f(234.52, 228.25, -1.2);
	glVertex3f(250.96, 227.44, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(310.59, 289.31, -1.2);
	glVertex3f(311.97, 213.58, -1.2);
	glVertex3f(294.73, 214.11, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(310.58, 289.28, -1.2);
	glVertex3f(294.74, 214.11, -1.2);
	glVertex3f(286.03, 216.37, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(286.03, 216.37, -1.2);
	glVertex3f(275.96, 220.81, -1.2);
	glVertex3f(310.6, 289.32, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(276.1, 220.78, -1.2);
	glVertex3f(263.69, 225.63, -1.2);
	glVertex3f(310.6, 289.32, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(263.69, 225.62, -1.2);
	glVertex3f(250.96, 227.45, -1.2);
	glVertex3f(286.65, 289.43, -1.2);
	glVertex3f(310.58, 289.3, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(244.77, 392.28, -1.2);
	glVertex3f(287.82, 392.27, -1.2);
	glVertex3f(289.27, 391.84, -1.2);
	glVertex3f(290.47, 391.25, -1.2);
	glVertex3f(291.7, 390.34, -1.2);
	glVertex3f(293.1, 388.54, -1.2);
	glVertex3f(294.54, 386.03, -1.2);
	glVertex3f(294.92, 383.35, -1.2);
	glVertex3f(294.81, 380.67, -1.2);
	glVertex3f(293.26, 377.72, -1.2);
	glVertex3f(291.33, 376.06, -1.2);
	glVertex3f(288.76, 374.51, -1.2);
	glVertex3f(264.81, 374.46, -1.2);
	glVertex3f(238.96, 374.47, -1.2);
	glVertex3f(239.53, 379.01, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(267.03, 374.46, -1.2);
	glVertex3f(272.51, 315.11, -1.2);
	glVertex3f(224.24, 315.15, -1.2);
	glVertex3f(238.97, 374.46, -1.2);
	glEnd();
	glBegin(GL_POLYGON);
	glColor3f(0.78125, 0.625, 0.08203125);
	glVertex3f(272.48, 315.12, -1.2);
	glVertex3f(250.99, 289.73, -1.2);
	glVertex3f(214.88, 290.06, -1.2);
	glVertex3f(224.23, 315.15, -1.2);
	glEnd();*/
glFlush();
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
	glOrtho(0,800,800,0,-2,2);
	//glFrustum (-0.5, 0.5,-0.5, 0.5, 0.8, 50.0);

	glMatrixMode(GL_MODELVIEW);		
	glLoadIdentity();// Seleccionamos Modelview Matrix
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




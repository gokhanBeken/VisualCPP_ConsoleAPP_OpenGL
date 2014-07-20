//  main project file.

#include "stdafx.h"

#include <iostream>
#include <sstream>
#include <iomanip>

#include <string> //katardan çevirme iþlemi için

#include <GL/glut.h>


GLfloat rtri;
GLfloat rquad;

//yeni denemeler
GLfloat x_derece = 0;
GLfloat y_derece = 0;
GLfloat z_derece = 0;



GLfloat x_durum, y_durum, z_durum;
static int hangiSekil = 9; //menudeki degisiklikler bu degiskene yazilir(9=demlik)



using namespace std;







void ayarlar(void)
{
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-7.0, 7.0, -2.0, 2.0, -5.0, 5.0);

	rtri = 0.0f;
}



void idle()
{


	float bilgi;

	//x_durum=1.0; y_durum=1.0; z_durum=0.0; //bu kýsým birþey deðiþtirmiyor, aþaðýda "gosterim" fonksiyonunda ayarlanýyor çünkü

	//rtri +=0.01f;
	//rquad+=0.15f; //bunun ne iþe yaradýðýný daha çözemedim




	glutPostRedisplay();

}


void keyboardCB(unsigned char key, int x, int y)
{
	rtri += 0.5f;

	switch (key)
	{
	case 27: // ESCAPE
		//clearSharedMem();
		exit(0);
		break;

	case 'w':
		x_derece -= 1.0;
		x_durum = 1.0; y_durum = 0.0; z_durum = 0.0;
		break;

	case 'a':
		z_derece += 1.0;
		x_durum = 0.0; y_durum = 0.0; z_durum = 0.1;
		break;

	case 's':
		x_derece += 1.0;
		x_durum = 0.1; y_durum = 0.0; z_durum = 0.0;
		break;

	case 'd':
		z_derece -= 1.0;
		x_durum = 0.0; y_durum = 0.0; z_durum = 0.1;
		break;

		//kumpas:
	case 'z':
		y_derece -= 1.0;
		x_durum = 0.0; y_durum = 0.1; z_durum = 0.0;
		break;

	case 'x':
		y_derece += 1.0;
		x_durum = 0.0; y_durum = 0.1; z_durum = 0.0;
		break;

		//sýfýrla
	case 'o':
		x_durum = 0.1;
		y_durum = 0.1;
		z_durum = 0.1;

		x_derece = 45.0;
		y_derece = 0.0;
		z_derece = 0.0;
		break;


	default:
		//x_aci=-0.00f; y_aci=-0.00f;  z_aci=-0.00f;   
		;
	}

	//iþi saðlama alalým diye yazdýk þart deðil:
	if (x_derece == 360.0 || x_derece == -360.0)x_derece = 0.0;
	if (y_derece == 360.0 || y_derece == -360.0)x_derece = 0.0;
	if (y_derece == 360.0 || z_derece == -360.0)x_derece = 0.0;

	glutPostRedisplay();

}

void gosterim(void)
{
	glEnable(GL_DEPTH_TEST);
	glColor3f(1.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Pencereyi temizle



	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();



	//nesneyi taþýmak: Nesneyi taþýmak: glTranslate{fd}( x, y, z )
	//bilgi: http://ozlemerden.wordpress.com/category/opengl/
	//Nesneyi bir eksen etrafýnda döndürmek: glRotate{fd}( açý, x, y, z )

	glPopMatrix(); // Transformasyonlari geri yukle
	//glTranslatef(4.0f,0.0f,0.0f); 
	glPushMatrix(); // Matris durumunu kaydet ve donusu yap



	//glRotatef(rtri,x_aci,y_aci,z_aci); //açý dediði aslýnda ne kadar çok döneceðini ayarlýyor

	//if(x_durum==1)glRotatef(rtri,0.1f,0.0f,0.0f);
	//if(y_durum==1)glRotatef(rtri,0.0f,0.1f,0.0f);
	//if(z_durum==1)glRotatef(rtri,0.0f,0.0f,0.1f);


	glRotatef(x_derece, 0.1f, 0.0f, 0.0f);
	glRotatef(y_derece, 0.0f, 0.1f, 0.0f);
	glRotatef(z_derece, 0.0f, 0.0f, 0.1f);


	if (hangiSekil == 21)//derece sifirlama
	{
		x_derece = 0;
		y_derece = 0;
		z_derece = 0;
		hangiSekil = 9;
	}


	//isiklandirma ve golgelendirme (harika sonuc üretiyor)////////////////////////
	//kaynak : http://web.media.mit.edu/~gordonw/OpenGL/
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glColor4f(1.0, 1.0, 1.0, 1.0); //rengi beyaz yapar
	GLfloat	lightpos[4] = { 5.0, 15.0, 10.0, 1.0 };
	///////////////////////////////////////////////////////////////////////////////

	switch (hangiSekil)
	{
	case 1:
		glutWireSphere(1.0f, 25, 25);
		break;

	case 2:
		glutWireCube(1.0f);
		break;

	case 3:
		glutWireCone(0.30f, 1.1f, 20, 20);
		break;

	case 4:
		glutWireTorus(0.3f, 1.0f, 10, 25);
		break;

	case 5:
		glutWireDodecahedron();
		break;

	case 6:
		glutWireOctahedron();
		break;

	case 7:
		glutWireTetrahedron();
		break;

	case 8:
		glutWireIcosahedron();
		break;

	case 9:
		glutWireTeapot(2.0f);
		break;

	case 11:
		glutSolidSphere(1.0f, 25, 25);
		break;

	case 12:
		glutSolidCube(1.0f);
		break;

	case 13:
		glutSolidCone(0.30, 1.1f, 20, 20);
		break;

	case 14:
		glutSolidTorus(0.3f, 1.0f, 10, 25);
		break;

	case 15:
		glutSolidDodecahedron();
		break;

	case 16:
		glutSolidOctahedron();
		break;

	case 17:
		glutSolidTetrahedron();
		break;

	case 18:
		glutSolidIcosahedron();
		break;

	case 19:
		glutSolidTeapot(2.0f);
		break;

	case 20: //kendi cizdigim kup sekli
		glBegin(GL_QUADS);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glColor3f(1.0f, 0.5f, 0.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, 1.0f);
		glVertex3f(-1.0f, 1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, -1.0f);
		glVertex3f(-1.0f, -1.0f, 1.0f);
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex3f(1.0f, 1.0f, -1.0f);
		glVertex3f(1.0f, 1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, 1.0f);
		glVertex3f(1.0f, -1.0f, -1.0f);
		glEnd();
		break;
	default:
		//glutSolidTeapot(1.0f);
		break;
	}



	//degisik sekiller cikartmak icin ornek: http://www.godoro.com/Divisions/Ehil/Mahzen/Programming/OpenGL/txt/html/document_AnimasyonAnd3D.html

	glPopMatrix(); // Transformasyonlari geri yukle
	glutSwapBuffers(); // Cizim komutlarini akit   	

}

void ProcessMenu(int value) //menu icin
{
	hangiSekil = value;

	glutPostRedisplay();
}

//int main()
//int main(array<System::String ^> ^args)
int main(int argc, char** argv)
{

	int i;

	int nWireMenu; //menu icin
	int nMainMenu; //menu icin
	int nSolidMenu; //menu icin   
	int nDigerMenu; //menu icin   

	printf("Merhaba\r\n");

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(900, 400);
	glutCreateWindow("OpenGL Uygulamasý www.GokhanBeken.com");
	ayarlar();

	//Sað click Menu olustur/////////////////////////////////////////////////////////////////////////////
	nWireMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Kure", 1);
	glutAddMenuEntry("Kup", 2);
	glutAddMenuEntry("Koni", 3);
	glutAddMenuEntry("Torus", 4);
	glutAddMenuEntry("Dodecahedron", 5);
	glutAddMenuEntry("Sekizgen", 6);
	glutAddMenuEntry("Tetrahedron", 7);
	glutAddMenuEntry("Icosahedron", 8);
	glutAddMenuEntry("Caydanlik", 9);

	nSolidMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Kure", 11);
	glutAddMenuEntry("Kup", 12);
	glutAddMenuEntry("Koni", 13);
	glutAddMenuEntry("Torus", 14);
	glutAddMenuEntry("Dodecahedron", 15);
	glutAddMenuEntry("Sekizgen", 16);
	glutAddMenuEntry("Tetrahedron", 17);
	glutAddMenuEntry("Icosahedron", 18);
	glutAddMenuEntry("Caydanlik", 19);
	glutAddMenuEntry("Ozel Kup", 20);

	nDigerMenu = glutCreateMenu(ProcessMenu);
	glutAddMenuEntry("Sifirla", 21);

	nMainMenu = glutCreateMenu(ProcessMenu);
	glutAddSubMenu("Tel", nWireMenu);
	glutAddSubMenu("Kati", nSolidMenu);
	glutAddSubMenu("Diger", nDigerMenu);
	glutAttachMenu(GLUT_RIGHT_BUTTON);
	//////////////////////////////////////////////////////////////////////////////////////////  


	glutDisplayFunc(gosterim); //sekillerin cizildigi fonksiyon
	glutKeyboardFunc(keyboardCB); //klavye fonksiyonum
	glutIdleFunc(idle); //arka planda deðer deðiþtirmek için genel fonksiyon
	glutMainLoop();


	return 0;
}


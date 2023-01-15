#include <GL/glut.h>
float angle = 0.0, x=-4;

void bicycle()
{
   glPushMatrix(); //Right Wheel
   glColor3f(0,0,1); glTranslated(0.75,-0.5, -0.5);
   glRotated(angle,0,0,1); glutSolidTorus (0.3,0.1,100,100);
   glPopMatrix();

   glPushMatrix(); //Left Wheel
   glColor3f(0,0,1); glTranslated(-0.75,-0.5, -0.5);
   glRotated(angle,0,0,1); glutSolidTorus (0.3,0.1,100,100);
   glPopMatrix();

   glPushMatrix(); //bicycle bottom horizontal pipe
   glColor3f(0,0,0); glTranslated(0,-0.5, -0.5); glScaled(1.5,0.1,0); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   
	glPushMatrix(); //bicycle top vertical pipe
   glColor3f(0,0,0); glTranslated(0,0.3, 0); glScaled(1.7,0.1,0); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   
	glPushMatrix(); //bicycle vertical pipes supportive cube + seat
   glColor3f(0,0,0); glTranslated(-0.1,0.1, 0); glScaled(0.5,0.8,0); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   
	glPushMatrix(); //bicycle handle
   glColor3f(0,0,0); glTranslated(0.6,0.2, 0); glScaled(0.06,1.2,0); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
 	glPushMatrix();
   glColor3f(0,0,0); glTranslated(0.6,0.8, 0); glScaled(0.06,0,1); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();
   
	glPushMatrix(); //paddle
   glColor3f(0,0,1); glTranslated(0,-0.4, 0); glScaled(0.06,0.2,0.8); glutSolidCube(1);
   glColor3f(0,0,0); glutWireCube(1);
   glPopMatrix();


   angle-=1;
}


void renderScene (void)
{
   glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
   glMatrixMode (GL_PROJECTION); glLoadIdentity();
   glOrtho (-3,3,-2,2,-4,4);  
   glRotatef(10,1.0,1.0,0.0);
   glPushMatrix (); glColor3f(255,255,255); //track
   glTranslated (0,-0.4,0); glScaled (9,0.1,0.1);
   glutSolidCube(1);
   glPopMatrix();
   {
   
   glTranslatef(x,0,0); // to move bicycle
   glScaled(0.5,0.5,0.5);
   
 
   
   glPushMatrix();
   glTranslated (-2.4,0,0); 
   bicycle();
   glPopMatrix();
   
   if (x<6)
  	x+=0.01;
   else
  	x=-6;
 

   glutSwapBuffers();
   }
}

int main(int argc,char** argv) {
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
glutInitWindowPosition (10,10);
glutInitWindowSize (1200,600);
glutCreateWindow("Bicycle");
glutDisplayFunc(renderScene);
glutIdleFunc (renderScene);
glClearColor(1,1,1,1);
glutMainLoop();
return 0;
}

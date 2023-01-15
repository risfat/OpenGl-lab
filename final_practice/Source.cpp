#include <windows.h>
#include <GL/glut.h>
#include <stdio.h>
#include <iostream>

void display(void) {

    glClear(GL_COLOR_BUFFER_BIT);

    //cube1

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(8, 15);
    glVertex2d(14, 15);
    glVertex2d(16, 10);
    glVertex2d(10, 10);

    glEnd();


    //cube1

    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(10, 10);
    glVertex2d(16, 10);
    glVertex2d(14, 5);
    glVertex2d(8, 5);

    glEnd();



    //cube1

    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(16, 10);
    glVertex2d(20, 15);
    glVertex2d(20, 5);

    glEnd();


    glBegin(GL_POLYGON);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(20, 12);
    glVertex2d(30, 12);
    glVertex2d(30, 8);
    glVertex2d(20, 8);

    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex2d(30, 5);
    glVertex2d(30, 15);
    glVertex2d(35, 10);

    glEnd();


    glFlush();

} 





void init() {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 50, 0, 40);
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(900, 720);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
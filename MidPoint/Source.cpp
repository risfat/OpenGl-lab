#include <GL/glut.h>
float x = 0, y, x2, y2, m, i, j, p;
int dx = 0, dy = 0, r;

void display(void)
{
    /* clear all pixels */
    glClear(GL_COLOR_BUFFER_BIT);
    /* draw white polygon (rectangle) with corners at
    * (0.25, 0.25, 0.0) and (0.75, 0.75, 0.0)
    */
    glEnd();

    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_POINTS);
    p = 1 - r;

    while ((x <= y)) {

        if (p < 0) {

            x = x + 1;
           
            p = p + (2 * x) + 1;

        }
        else {
            x = x + 1;
            y = y - 1;

            p = p + (2 * x) + 1 - (2 * y);
        }
        glVertex2f(((x / 50)), ((y / 50)));
        glVertex2f(-((x / 50)), -((y / 50)));
        glVertex2f(-((x / 50)), ((y / 50)));
        glVertex2f(((x / 50)), -((y / 50)));

        glVertex2f(((y / 50)), ((x / 50)));
        glVertex2f(-((y / 50)), -((x / 50)));
        glVertex2f(-((y / 50)), ((x / 50)));
        glVertex2f(((y / 50)), -((x / 50)));
    }
    glEnd();

    /* don't wait!
    * start processing buffered OpenGL routines
    */
    glFlush();
}
void init(void)
{
    /* select clearing (background) color */
    glClearColor(0.0, 0.0, 0.0, 0.0);
    /* initialize viewing values */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    /**
    gluOrtho2D(-300, 300, 0, 600);

    */
}
/*
* Declare initial window size, position, and display mode
* (single buffer and RGBA). Open window with "hello"
* in its title bar. Call initialization routines.
* Register callback function to display graphics.
* Enter main loop and process events.
*/
int main(int argc, char** argv)
{

    r = 10;
    y = r;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Mid Point Circle");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0; /* ISO C requires main to return int. */
}
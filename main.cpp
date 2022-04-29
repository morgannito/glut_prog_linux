#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>

float angle = 0;
float angle2 = 0;


GLvoid rotate_angle_1(int value) {
    // fait un random entre 0 et 360
//    angle = rand() % 180;
    angle -= 0.1;
    glutPostRedisplay(); //Tell GLUT that the scene has changed
}

GLvoid rotate_angle_2(int value) {
    // fait un random entre 0 et 360
//    angle = rand() % 180;
    angle2 -= 0.5;
    glutPostRedisplay(); //Tell GLUT that the scene has changed
}


void DrawCircle(float cx, float cy, float r, int num_segments)
{
    glBegin(GL_LINE_LOOP);
    for(int ii = 0; ii < num_segments; ii++)
    {
        float theta = 2.0f * 3.1415926f * float(ii) / float(num_segments);//get the current angle
        float x = r * cosf(theta);//calculate the x component
        float y = r * sinf(theta);//calculate the y component
        glVertex2f(x + cx, y + cy);//output vertex
    }
    glEnd();
}

void DrawSquare()
{
    glBegin(GL_QUADS);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
    glVertex2f(0.5, -0.5);
    glEnd();
}



void mon_window_display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();	//initialisation de la matrice courant GL_MODELVIEW
//    glTranslatef(0.2, 0.2, 0.0);
//    glRotatef(angle, 0, 0, 1);

// LA BASE
    glColor3f(0, 0, 1);
    glTranslatef(-0.4, -0.8, 0.0);
    glRectd(-0.2, -0.2, 0.2, 0.2);

    // joint 1
    glRotatef(angle, 0, 0, 1);


    //link 1
    glColor3f(1, 0, 0);
    glTranslatef(0.0, 0.8, 0.0);
    glRectf(-0.1, -0.8, 0.1, 0.8);

    // joint 2
    glColor3f(0, 1, 0);
    glTranslatef(0.0, 0.8, 0.0);
    glRotatef(angle2, 0, 0, 1);

    // link 2
    glTranslatef(0.0, 0.8, 0.0);
    glRectf(-0.1, -0.8, 0.1, 0.8);



    // le bras
//    glColor3f(0, 1, 0);
//    glTranslatef(0.0, 0.0, 0.0);
//    glRotatef(angle, 0, 0, 1);
//    glRectd(-0.2, -0.2, 0.2, 0.2);




//    DrawSquare();

//    DrawCircle(0, 0, 0.5, 100);
//    glTranslatef(-2, -0.8, 0.0);


    glFlush();
    glutSwapBuffers();
}

GLvoid monclavier(unsigned char key, int x, int y)
{
    int clicbouton = 0;
    switch (key) {
        case 'a':
            glutIdleFunc(mon_window_display);
            rotate_angle_2(200);
            break;
        case 'b':
            std::cout << "la souris est à " << x <<" "<< y << std::endl;
            break;
        case'n':
            glutIdleFunc(mon_window_display);
            rotate_angle_1(200);
            break;
        default:
            printf("La touche %d n'est pas active.\n", key);
            break;
    }
    glutPostRedisplay();
}



int main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutCreateWindow(argv[0]);
    glutKeyboardFunc(monclavier);
    glutDisplayFunc(mon_window_display);
    glutMainLoop();
    return 0;
}






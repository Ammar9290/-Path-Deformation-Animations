#include <GL/glut.h>
#include <cmath>
#include <vector>
#include <iostream>

const int WIDTH = 800, HEIGHT = 600;
float timeElapsed = 0.0f;

// Path deformation parameters
const int POINTS = 100;
std::vector<float> pathX(POINTS), pathY(POINTS);

void generateInitialPath() {
    for (int i = 0; i < POINTS; ++i) {
        pathX[i] = i * 2.0f / POINTS - 1.0f;
        pathY[i] = 0.0f;
    }
}

void deformPath() {
    timeElapsed += 0.05f;
    for (int i = 0; i < POINTS; ++i) {
        pathY[i] = 0.1f * std::sin(10 * pathX[i] + timeElapsed);
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    deformPath();

    glBegin(GL_LINE_STRIP);
    glColor3f(1.0f, 0.0f, 0.0f);
    for (int i = 0; i < POINTS; ++i) {
        glVertex2f(pathX[i], pathY[i]);
    }
    glEnd();

    glutSwapBuffers();
}

void idle() {
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Path Deformation Animation");
    glOrtho(-1.0f, 1.0f, -0.5f, 0.5f, -1.0f, 1.0f);
    generateInitialPath();
    glutDisplayFunc(display);
    glutIdleFunc(idle);
    glutMainLoop();
    return 0;
}

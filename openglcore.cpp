#include "openglcore.h"


OpenGlCore::OpenGlCore(QWidget *parent) : QOpenGLWidget(parent)
{

}

void OpenGlCore::initializeGL()
{
    //        initializeOpenGLFunctions();
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

}

void OpenGlCore::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    float aspectRatio = static_cast<float>(w) / static_cast<float>(h);
    glFrustum(-1.0, 1.0, -1.0 / aspectRatio, 1.0 / aspectRatio, 1.0, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void OpenGlCore::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glLoadIdentity();
    glTranslatef(0.0f, 0.0f, -5.0f); // Move the cube away from the camera


    glRotatef(rotationAngleX, 1.0f, 0.0f, 0.0f); // Rotate around the x-axis
    glRotatef(rotationAngleY, 0.0f, 1.0f, 0.0f); // Rotate around the y-axis
    glRotatef(rotationAngleZ, 0.0f, 0.0f, 1.0f); // Rotate around the z-axis

    // Render the cube
    glBegin(GL_QUADS);

    // Front face
    glColor3f(1.0f, 0.0f, 0.0f); // Red color
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Back face
    glColor3f(0.0f, 1.0f, 0.0f); // Green color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Left face
    glColor3f(0.0f, 0.0f, 1.0f); // Blue color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, -1.0f);

    // Right face
    glColor3f(1.0f, 1.0f, 0.0f); // Yellow color
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);

    // Top face
    glColor3f(1.0f, 0.0f, 1.0f); // Magenta color
    glVertex3f(-1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, -1.0f);
    glVertex3f(1.0f, 1.0f, 1.0f);
    glVertex3f(-1.0f, 1.0f, 1.0f);

    // Bottom face
    glColor3f(0.0f, 1.0f, 1.0f); // Cyan color
    glVertex3f(-1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, -1.0f);
    glVertex3f(1.0f, -1.0f, 1.0f);
    glVertex3f(-1.0f, -1.0f, 1.0f);

    glEnd();
}


void OpenGlCore::xRotate(int x)
{
    rotationAngleX=x;
    update();
}


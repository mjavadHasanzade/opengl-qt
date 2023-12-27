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

    // Start the timer to trigger animation
    QTimer* timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(animate()));
    timer->start(16); // Update every 16 milliseconds (approximately 60 FPS)
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

    glRotatef(rotationAngle, 1.0f, 0.0f, 0.0f); // Rotate the cube

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

void OpenGlCore::animate()
{
    rotationAngle += 1.6;
    update();
}


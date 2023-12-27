#ifndef OPENGLCORE_H
#define OPENGLCORE_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QTimer>
class OpenGlCore : public QOpenGLWidget
{
    Q_OBJECT

public:
    OpenGlCore(QWidget *parent = nullptr);

protected:
    void initializeGL() override;

    void resizeGL(int w, int h) override;

    void paintGL() override;


public slots:
    void xRotate(int x);
    void yRotate(int y);
    void zRotate(int z);

private:
    float rotationAngleX = 0.0f;
    float rotationAngleY = 0.0f;
    float rotationAngleZ = 0.0f;

};


#endif // OPENGLCORE_H

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

private slots:
    void animate();

private:
    float rotationAngle = 0;
};


#endif // OPENGLCORE_H

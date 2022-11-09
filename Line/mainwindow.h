#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <Point.h>
#include<QWidget>
#include <QMainWindow>

#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <GL/gl.h>
#include <GL/glu.h>
#include <QTimer>
#include <QMouseEvent>

class MainWindow : public QOpenGLWidget
{
    Q_OBJECT
private:
    float xRot, yRot, zRot;
    QPoint mPos;
    QTimer tmr;
    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;
    void drawLine();
    void _DrawGridXY(float cx, float cy, float step);
    void _DrawGridXZ(float cx, float cy, float step);
    void _DrawGridYZ(float cx, float cy, float step);
    void DrawGrid();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

   //const float arr[12] = {0.9, -0.9, 0.1, 0.5,	-0.1,	0.1, 1,	-0.4,	0.4, 1,	-0.13,	0.111};


public:
    MainWindow(QOpenGLWidget *parent = nullptr);

    ~MainWindow();
};
#endif // MAINWINDOW_H

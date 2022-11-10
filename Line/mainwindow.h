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
    void MasOfPoint();
    void drawLine();
    void _DrawGridXY();
    void _DrawGridXZ();
    void _DrawGridYZ();
    void DrawGrid();
    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

    const float arr[12] = {0.9, -0.9, 0.1, 0.5, -0.1, 0.1, 1, -0.4, 0.4, 1, -0.13, 0.111};
    Point vect[4] = {};
    float max_x;
    float max_y;
    float max_z;
    float min_x;
    float min_y;
    float min_z;

public:
    MainWindow(QOpenGLWidget *parent = nullptr);

    ~MainWindow();
};
    #endif // MAINWINDOW_H


#include "mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QOpenGLWidget *parent)
: QOpenGLWidget(parent)
{
setGeometry(400, 200, 800, 600);
}


void MainWindow::initializeGL(){
glClearColor(0.1, 0.1, 0.1, 0.3);
glEnable(GL_DEPTH_TEST);

}

void MainWindow::resizeGL(int w, int h){
glViewport(0, 0, (GLint)w, (GLint)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-1,1,-1,1,1,3);

}

void MainWindow::paintGL(){
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();

glTranslatef(0,0,-2);
glRotatef(xRot, 1, 0, 0);
glRotatef(yRot, 0, 1, 0);
//drawLine();
DrawGrid();

}

void MainWindow::DrawGrid(){
    _DrawGridXY(2.0, 2.0, 0.1);
    _DrawGridXZ(2.0, 2.0, 0.1);
    _DrawGridYZ(2.0, 2.0, 0.1);

}

void MainWindow:: _DrawGridXY(float cx, float cy, float step)
    {
        float _cx = cx / 2;
        float _cy = cy / 2;

        for(float x = 0/*-_cx*/; x <= _cx; x += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(x, _cy, 0.0);
            glVertex3f(x, 0.0, 0.0);//-_cy
            glEnd();
        }

        for(float y = 0/*-_cy*/; y <= _cy; y += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(_cx, y, 0.0);
            glVertex3f(0.0, y, 0.0);//-_cx
            glEnd();
        }
    }

void MainWindow:: _DrawGridXZ(float cx, float cz, float step)
    {
        float _cx = cx / 2;
        float _cz = cz / 2;

        for(float x = 0/*-_cx*/; x <= _cx; x += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(x, 0.0, _cz);
            glVertex3f(x, 0.0, 0.0);//-_cz
            glEnd();
        }

        for(float z = 0/*-_cz*/; z <= _cz; z += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(_cx, 0.0, z);
            glVertex3f(0.0, 0.0, z);//-_cx
            glEnd();
        }
    }

void MainWindow:: _DrawGridYZ(float cy, float cz, float step)
    {
        float _cy = cy / 2;
        float _cz = cz / 2;

        for(float y = 0/*-_cy*/; y <= _cy; y += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(0.0, y, _cz);
            glVertex3f(0.0, y, 0.0);//-_cz
            glEnd();
        }

        for(float z = 0/*-_cz*/; z <= _cz; z += step)
        {
            glLineWidth(1);
            glBegin(GL_LINES);
            glVertex3f(0.0, _cy, z);
            glVertex3f(0.0, 0.0, z);//-_cy
            glEnd();
        }
    }

void MainWindow::drawLine(){
const float arr[12] = { 0.9, -0.9, 0.1,
0.5,-0.1,0.1,
1.0,-0.4,0.4,
1.0,-0.13,0.111 };
int vert = 4;
Point vect[4] = {};
int i = 0;

for (int j = 0; j < vert; j++) {
if (i < 12) {
vect[j].x = arr[i];
vect[j].y = arr[i + 1];
vect[j].z = arr[i + 2];

}
i += 3;
}

float vertices[6] = { 0 };
int j = 0;
for (int i = 0; i < 4; i++) {
// int j = 0;
if (j < 6) {
vertices[j] = vect[i].x;
vertices[j + 1] = vect[i].y;
vertices[j + 2] = vect[i].z;
j += 3;
}
else {
glVertexPointer(3, GL_FLOAT, 0, &vertices);
glEnableClientState(GL_VERTEX_ARRAY);

glLineWidth(5);

glDrawArrays(GL_LINES, 0 ,2);
j = 0;
i -= 2;
for(int k=0;k<6;k++){
vertices[k]=0;
}
}

}
glVertexPointer(3, GL_FLOAT, 0, &vertices);
glEnableClientState(GL_VERTEX_ARRAY);

glLineWidth(5);

glDrawArrays(GL_LINES, 0 ,2);
glDisableClientState(GL_VERTEX_ARRAY);


}

void MainWindow::mousePressEvent(QMouseEvent * mo){
mPos = mo->pos();
}

void MainWindow::mouseMoveEvent(QMouseEvent * mo){
xRot += 1/M_PI*(mo->pos().y() - mPos.y());
yRot += 1/M_PI*(mo->pos().x() - mPos.x());

mPos = mo->pos();
update();
}

MainWindow::~MainWindow()
{
}

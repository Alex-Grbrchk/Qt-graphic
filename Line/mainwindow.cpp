#include "mainwindow.h"
#include <math.h>

MainWindow::MainWindow(QOpenGLWidget *parent): QOpenGLWidget(parent)
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
    MasOfPoint();
    drawLine();
    DrawGrid();

}

void MainWindow::MasOfPoint(){

    int vert = 4;

    int i = 0;

    for (int j = 0; j < vert; j++) {
        if (i < 12) {
            vect[j].x = arr[i];
            vect[j].y = arr[i + 1];
            vect[j].z = arr[i + 2];

        }
        i += 3;
    }
}

void MainWindow::drawLine(){
    float vertices[6] = { 0 };
    int j = 0;
    for (int i = 0; i < 4; i++) {

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

void MainWindow::DrawGrid(){
    max_x=vect[0].x;
    max_y=vect[0].y;
    max_z=vect[0].z;
    min_x=vect[0].x;
    min_y=vect[0].y;
    min_z=vect[0].z;
    for(int i = 0; i < 4;i++){
        if (vect[i].x>max_x){
            max_x=vect[i].x;
        }
        if (vect[i].y>max_y){
            max_y=vect[i].y;
        }
        if (vect[i].z>max_z){
            max_z=vect[i].z;
        }

        if (vect[i].x<min_x){
            min_x=vect[i].x;
        }
        if (vect[i].y<min_y){
            min_y=vect[i].y;
        }
        if (vect[i].z<min_z){
            min_z=vect[i].z;
        }
    }

    max_x+=0.1;
    max_y+=0.1;
    max_z+=0.1;
    min_x-=0.1;
    min_y-=0.1;
    min_z-=0.1;
    _DrawGridXY();
    _DrawGridXZ();
    _DrawGridYZ();

}

void MainWindow:: _DrawGridXY()
{
     float vertices[6] = {0, 0, min_z, 0, 0, min_z};
     vertices[1]=max_y;
     vertices[4]=min_y;


    for(float x = min_x; x <= max_x; x += 0.1){
        vertices[0]=x;
        vertices[3]=x;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);

    }
    vertices[0]=max_x;
    vertices[3]=min_x;

    for(float y = min_y; y <= max_y; y += 0.1){
        vertices[1]=y;
        vertices[4]=y;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);
      
    }
}

void MainWindow:: _DrawGridXZ()
{
    float vertices[6] = {0, min_y, 0, 0, min_y, 0};
    vertices[2] = max_z;
    vertices[5] = min_z;
    for(float x = min_x; x <= max_x; x += 0.1){
        vertices[0] = x;
        vertices[3] = x;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);
        
    }
    vertices[0] = max_x;
    vertices[3] = min_x;
    for(float z = min_z; z <= max_z; z += 0.1)
    {
        vertices[2] = z;
        vertices[5] = z;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);
      
    }
}

void MainWindow:: _DrawGridYZ()
{
    float vertices[6] = {min_x, 0, 0, min_x, 0, 0};
    vertices[2] = max_z;
    vertices[5] = min_z;

    for(float y = min_y; y <= max_y; y += 0.1)
    {
        vertices[1] = y;
        vertices[4] = y;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);
        
    }
    vertices[1] = max_y;
    vertices[4] = min_y;
    for(float z = min_z; z <= max_z; z += 0.1)
    {
        vertices[2] = z;
        vertices[5] = z;

        glVertexPointer(3, GL_FLOAT, 0, &vertices);
        glEnableClientState(GL_VERTEX_ARRAY);

        glLineWidth(1);

        glDrawArrays(GL_LINES, 0 ,2);
        glDisableClientState(GL_VERTEX_ARRAY);
        
    }
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


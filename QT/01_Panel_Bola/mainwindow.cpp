#include "mainwindow.h"
#include <QTextEdit>
#include <QtGui>
#include <QLabel>
#include <QStatusBar>
#include <QTextCursor>
#include <QPainter>
#include <QTimer>
#include <stdlib.h>
#include <math.h>

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    	resize(800,600);
	posicionX = 20;
	posicionY = 10;
	velocidadX = 10;
	velocidadY = 10;
	temporizador = new QTimer();
	temporizador->setInterval(50);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::paintEvent(QPaintEvent *e)
{
	QPainter pintor(this);
	pintor.drawEllipse(posicionX,posicionY,100,100);

	posicionY += velocidadY;
	posicionX += velocidadX;

	if(posicionX <= 0){
		//velocidadX = velocidadX * -1;
		velocidadX = fabs(velocidadX);
	}
	if(posicionX >= width() - 100){
		//velocidadX = velocidadX * -1;
		velocidadX = -fabs(velocidadX);
	}

	if(posicionY <= 0){
		//velocidadY = velocidadY * -1;
		velocidadY = fabs(velocidadY);
	}
	if(posicionY >= height() - 100){
		//velocidadY = velocidadY * -1;
		velocidadY = -fabs(velocidadY);
	}
	
	//pintor.drawEllipse(10,10,100,100);//dibujar un circulo siempre en el mismo sitio	
}	

void MainWindow::repintar()
{
    this->update();
}





#include "mainwindow.h"
#include "bola.h"

#include <QTextEdit>
#include <QtGui>
#include <QLabel>
#include <QStatusBar>
#include <QTextCursor>
#include <QPainter>
#include <QTimer>
#include <QMenu>
#include <QBrush>
#include <QColor>
#include <stdlib.h>
#include <math.h>

//variable = (condicion) ? valorTRUE : valorFALSE; es similar al IF{}ELSE{}

void inicializarBolas(int numBolas, QVector<Bola> & lasBolas){
	for(int i = 0; i < numBolas; i++){
		float velocidadX = (float) (((rand() % Bola::diametro )/ 20) - 5);
		float velocidadY = (float) (((rand() % Bola::diametro )/ 20) - 5);
				
		float posicionX = (float) (rand() % 200);
		float posicionY = (float) (rand() % 200);
		
		lasBolas.push_back(Bola(posicionX,posicionY,velocidadX,velocidadY)); 
	}
}

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
	inicializaConfiguracion();
    	resize(laConfiguracion.anchuraPantalla,laConfiguracion.alturaPantalla);

	Bola::diametro = 100;//3 INICIALIZAR VARIABLE DE CLASE

	temporizador = new QTimer();
	temporizador->setInterval(laConfiguracion.intervaloAnimacion);
	temporizador->setSingleShot(false);
	connect(temporizador, SIGNAL(timeout()), this, SLOT(repintar()));
	temporizador->start();

	inicializarBolas(2,lasBolas);

	crearMenu();

	dialogoConf = new DialogoConfiguracion();
	
	connect(dialogoConf->sliderTamanyoBola, SIGNAL(valueChanged(int)), this, SLOT(cambiaTamanyoBola(int)));

	bolaUsuario = new Bola(20,20,0,0);

	dialogoSuperConfiguracion = NULL;
}

MainWindow::~MainWindow()
{
	//destructor
}

void MainWindow::crearMenu(){
	accionAbrir = new QAction(tr("Configuracion Bolas"),this);
	connect(accionAbrir, SIGNAL(triggered()),this, SLOT(abrirConfiguracion()));

	QMenu *menu;
	menu = menuBar()->addMenu(tr("&Configuracion"));
	menu->addAction(accionAbrir);

	accionConfiguracion = new QAction(tr("Configuracion General"),this);
	connect(accionConfiguracion, SIGNAL(triggered()),this, SLOT(abrirConfiguracionGeneral()));

	QMenu *menuCon;
	menuCon = menuBar()->addMenu(tr("&Configuracion General"));
	menuCon->addAction(accionConfiguracion);
}

void MainWindow::paintEvent(QPaintEvent *e){
	QPainter pintor(this);
	QColor rojo(255,0,0);
	QColor gris(120,120,120);
	QColor blanco(255,255,255);
	
	if(laConfiguracion.bolaJugadorSolida){
		pintor.setBrush(QBrush(gris));
		pintor.drawEllipse(bolaUsuario->posX,bolaUsuario->posY,Bola::diametro,Bola::diametro);
	}else{
		pintor.setBrush(QBrush(blanco));
		pintor.drawEllipse(bolaUsuario->posX,bolaUsuario->posY,Bola::diametro,Bola::diametro);
	}
	
	bolaUsuario->mueve();	
	bolaUsuario->rebotan(width(), height());
	pintor.setBrush(QBrush(rojo));

	for(QVector<Bola>::iterator it=lasBolas.begin(); it != lasBolas.end(); it++){
		pintor.drawEllipse(it->posX,it->posY,Bola::diametro,Bola::diametro);

		it->mueve();
		it->rebotan(width(), height());

		it->bolasRebotan(bolaUsuario);

		for(QVector<Bola>::iterator it2 = it + 1; it2 != lasBolas.end(); it2++){	
			it->bolasRebotan(it2);
		}
	}
}	



void MainWindow::mousePressEvent(QMouseEvent *e){
	if(laConfiguracion.activarControlRaton){
		float distanciaX = (e->x() - bolaUsuario->posX) / 150;
		float distanciaY = (e->y() - bolaUsuario->posY) / 150;	

		bolaUsuario->velX += distanciaX;
		bolaUsuario->velY += distanciaY;
	}else{
		float velocidadX = (float) (((rand() % Bola::diametro )/ 20) - 5);
		float velocidadY = (float) (((rand() % Bola::diametro )/ 20) - 5);
				
		
		lasBolas.push_back(Bola(e->x() - 50, e->y() - 50,velocidadX,velocidadY));
	}
}

void MainWindow::repintar(){
    if(laConfiguracion.configuracionActualizada){
	temporizador->setInterval(laConfiguracion.intervaloAnimacion);
	laConfiguracion.configuracionActualizada = false;
    }

    if(vidas == 0){
	close();
    }
    this->update();
}

void MainWindow::abrirConfiguracion(){
	dialogoConf->show();
}

void MainWindow::abrirConfiguracionGeneral(){	
	if(dialogoSuperConfiguracion == NULL){	
		dialogoSuperConfiguracion = new DialogoSuperConfiguracion();
		dialogoSuperConfiguracion->configuracion = &laConfiguracion;	
	}
	dialogoSuperConfiguracion->show();
}

void MainWindow::cambiaTamanyoBola(int tamanyo){
	Bola::diametro = tamanyo;
}

void MainWindow::inicializaConfiguracion(){
	laConfiguracion.intervaloAnimacion = 30;
	laConfiguracion.ratonActuaJugador = false;
	laConfiguracion.diametroBolas = Bola::diametro = 100;
	laConfiguracion.anchuraPantalla = 900;
	laConfiguracion.alturaPantalla = 700;
	laConfiguracion.bolaJugadorSolida = false;
	laConfiguracion.activarControlRaton = false;
	laConfiguracion.configuracionActualizada = false;
}

void MainWindow::keyPressEvent(QKeyEvent *e){
	int pulsada = e->key();

	switch(pulsada){
		case Qt::Key_Right:
			bolaUsuario->velX += 0.3;
		break;

		case Qt::Key_Left:
			bolaUsuario->velX -= 0.3;
		break;

		case Qt::Key_Down:
			bolaUsuario->velY += 0.3;
		break;

		case Qt::Key_Up:
			bolaUsuario->velY -= 0.3;
		break;
	}
}



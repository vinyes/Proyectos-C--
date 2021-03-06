#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QAction>
#include <QStatusBar>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QVector>
#include <QKeyEvent>
#include "bola.h"
#include "dialogoConfiguracion.h"
#include "dialogoSuperConfiguracion.h"
#include "dialogoBolas.h"
#include "configuracion.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
    
    	QTimer *temporizador;
	QVector<Bola> lasBolas;
	DialogoConfiguracion *dialogoConf;
	DialogoSuperConfiguracion *dialogoSuperConfiguracion;
	Bola *bolaUsuario;
	Configuracion laConfiguracion;
	DialogoBolas *dialogoBolas;

    	public:
        	MainWindow(QWidget *parent = 0);
		void crearMenu();
        	~MainWindow();
   	private:
		QAction *accionAbrir;
		QAction *accionConfiguracion;
		QAction *accionAbrirBolas;
		void inicializaConfiguracion();
		int vidas;

    	protected:
		void paintEvent(QPaintEvent *e);
		void mousePressEvent(QMouseEvent *e);
		void keyPressEvent(QKeyEvent *e);

    	public slots:
        	void repintar();
		void abrirConfiguracion();
		void abrirConfiguracionGeneral();
		void cambiaTamanyoBola(int tamanyo);
		void abrirConfiguracionBolas();
};

#endif // MAINWINDOW_H

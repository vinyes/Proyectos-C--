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

class MainWindow : public QMainWindow
{
	Q_OBJECT
    
    	QTimer *temporizador;
	QVector<Bola> lasBolas;
	DialogoConfiguracion *dialogoConf;
	Bola *bolaUsuario;

    	public:
        	MainWindow(QWidget *parent = 0);
		void crearMenu();
        	~MainWindow();
   	private:
		QAction *accionAbrir;

    	protected:
		void paintEvent(QPaintEvent *e);
		void mousePressEvent(QMouseEvent *e);
		void keyPressEvent(QKeyEvent *e);

    	public slots:
        	void repintar();
		void abrirConfiguracion();
		void cambiaTamanyoBola(int tamanyo);
};

#endif // MAINWINDOW_H

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui/QMainWindow>
#include <QTextEdit>
#include <QLabel>
#include <QStatusBar>
#include <QPaintEvent>
#include <QMouseEvent>
#include <QTimer>
#include <QVector>
#include "bola.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
    
    	QTimer *temporizador;
	QVector<Bola> lasBolas;

    	public:
        	MainWindow(QWidget *parent = 0);
        	~MainWindow();
   	private:

    	protected:
		void paintEvent(QPaintEvent *e);
		void mousePressEvent(QMouseEvent *e);

    	public slots:
        	void repintar();
};

#endif // MAINWINDOW_H

#include "dialogoSuperConfiguracion.h"

DialogoSuperConfiguracion::DialogoSuperConfiguracion(QWidget *parent) : QDialog(parent)
{
	setupUi(this);

	connect(checkSolido,SIGNAL(clicked()),this,SLOT(cambiarSolidez()));
	connect(checkBoxRaton,SIGNAL(clicked()),this,SLOT(controlarClickRaton()));

	connect(rbLenta,SIGNAL(clicked()),this,SLOT(cambiarIntervalo()));
	connect(rbMedia,SIGNAL(clicked()),this,SLOT(cambiarIntervalo()));
	connect(rbRapida,SIGNAL(clicked()),this,SLOT(cambiarIntervalo()));
}

void DialogoSuperConfiguracion::cambiarSolidez(){
	if(configuracion == NULL){
		return;		
	}	
	configuracion->bolaJugadorSolida = checkSolido->isChecked();
}

void DialogoSuperConfiguracion::controlarClickRaton(){
	if(configuracion == NULL){
		return;		
	}
	
	configuracion->activarControlRaton = checkBoxRaton->isChecked();
}

void DialogoSuperConfiguracion::cambiarIntervalo(){
	if(configuracion == NULL){
		return;		
	}
	
	if(rbLenta->isChecked()){
		configuracion->intervaloAnimacion = Configuracion::INTERVALO_LENTO;
	}else{
		if(rbMedia->isChecked()){
			configuracion->intervaloAnimacion = Configuracion::INTERVALO_MEDIO;
		}else{
			configuracion->intervaloAnimacion = Configuracion::INTERVALO_RAPIDO;
		}
	}
	configuracion->configuracionActualizada = true;
}

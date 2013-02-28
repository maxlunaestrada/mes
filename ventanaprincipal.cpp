#include "ventanaprincipal.h"
#include "ui_ventanaprincipal.h"
#include <variablesglobales.h>
#include <manejodearchivoscsv.h>

VentanaPrincipal::VentanaPrincipal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::VentanaPrincipal)
{
    ui->setupUi(this);
    ///##############################
    ///### Variable de control de la base de datos funcional en uso
    ///##############################
    baseDeDatosFuncionalEnUso = false;
}

VentanaPrincipal::~VentanaPrincipal()
{
    delete ui;
}

//##############################
///### Procedimiento reimplementado para salir de la aplicación cuando se oprime la [X] de la ventana principal
///##############################
void VentanaPrincipal::closeEvent(QCloseEvent *event)
 {
    event->ignore();
    ///##############################
    ///### Verificar si hay una base de datos funcional activa antes de salir
    ///##############################
    if (baseDeDatosFuncionalEnUso)
    {
        guardarBaseDeDatosFuncional = new DialogoParaGuardarArchivoDeDatosSiONo(0, true);
        guardarBaseDeDatosFuncional->show();
    }
    ///##############################
    ///### Salir de la aplicación
    ///##############################
    else
    {
        cerrarConexionALaBdFuncional();
        eliminarArchivoDeLaBdFuncional();
        exit(0);
    }
 }

///##############################
///### Procedimiento para salir de la aplicación desde el menú y la barra de herramientas
///##############################
void VentanaPrincipal::on_accionSalir_triggered()
{
    close();
}
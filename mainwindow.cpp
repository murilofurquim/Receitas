#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listaingredientes.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionIngredientes_triggered()
{
    ListaIngredientes *lista = new ListaIngredientes(this);
    lista->show();
}

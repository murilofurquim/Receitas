#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "listaingredientes.h"
#include "listareceitas.h"
#include "telareceita.h"

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

void MainWindow::on_actionReceitas_triggered()
{
    ListaReceitas *lista = new ListaReceitas(this);
    lista->show();
}

void MainWindow::on_actionReceita_Novo_triggered()
{
    TelaReceita * receita = new TelaReceita(this);
    receita->setAttribute( Qt::WA_DeleteOnClose );
    receita->show();
}

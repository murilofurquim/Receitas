#include "listaingredientes.h"
#include "ui_listaingredientes.h"
#include "utils.h"
#include "ingrediente.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPushButton>

ListaIngredientes::ListaIngredientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaIngredientes)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("default");

    model = new QSqlQueryModel();

    model->setQuery("SELECT id, descricao FROM ingrediente", db);
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Descrição"));

    ui->tableView->setModel(model);

    QPushButton *btnNovo = new QPushButton("Novo...");

    connect(btnNovo, &QPushButton::released, this, &ListaIngredientes::handleNew);

    ui->buttonBox->addButton(btnNovo, QDialogButtonBox::ApplyRole);
}

ListaIngredientes::~ListaIngredientes()
{
    delete ui;
}

void ListaIngredientes::handleNew()
{
    meuDebug("handleNew");

    Ingrediente ing(this);
    ing.exec();
    meuDebug("refresh query");
    QString queryStr = model->query().executedQuery();
    model->clear();
    model->query().clear();
    model->setQuery(queryStr, QSqlDatabase::database("default"));
}

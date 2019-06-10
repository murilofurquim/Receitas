#include "listareceitas.h"
#include "ui_listareceitas.h"
#include "utils.h"
#include "receita.h"
#include <QPushButton>
#include <QSqlQuery>

ListaReceitas::ListaReceitas(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaReceitas)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("default");

    model = new QSqlQueryModel();

    model->setQuery("SELECT id, descricao FROM receita", db);
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Descrição"));

    ui->tableView->setModel(model);

    QPushButton *btnNovo = new QPushButton("Novo...");

    connect(btnNovo, &QPushButton::released, this, &ListaReceitas::handleNew);

    ui->buttonBox->addButton(btnNovo, QDialogButtonBox::ApplyRole);
}

ListaReceitas::~ListaReceitas()
{
    delete ui;
}

void ListaReceitas::handleNew()
{
    meuDebug("ListaReceitas::handleNew");

    Receita rec(this);
    rec.exec();
    meuDebug("refresh query");
    QString queryStr = model->query().executedQuery();
    model->clear();
    model->query().clear();
    model->setQuery(queryStr, QSqlDatabase::database("default"));
}

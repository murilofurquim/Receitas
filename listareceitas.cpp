#include "listareceitas.h"
#include "ui_listareceitas.h"
#include "utils.h"
#include "receita.h"
#include <QPushButton>
#include <QSqlQuery>
#include <QSqlRecord>
#include "telareceita.h"

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

    QPushButton *btnVisualizar = new QPushButton("Visualizar");
    connect(btnVisualizar, &QPushButton::released, this, &ListaReceitas::handleVisualizar);

    ui->buttonBox->addButton(btnNovo, QDialogButtonBox::ApplyRole);
    ui->buttonBox->addButton(btnVisualizar, QDialogButtonBox::ApplyRole);

}

ListaReceitas::~ListaReceitas()
{
    delete ui;
}

void ListaReceitas::refreshGrid()
{
    QString queryStr = model->query().executedQuery();
    model->clear();
    model->query().clear();
    model->setQuery(queryStr, QSqlDatabase::database("default"));
}

void ListaReceitas::handleNew()
{
    meuDebug("ListaReceitas::handleNew");

    TelaReceita *rec = new TelaReceita(this, 0);

    connect(rec, &TelaReceita::registroAlterado, this, [=](){refreshGrid();});

    rec->show();
    meuDebug("refresh query");
//    refreshGrid();
}

void ListaReceitas::handleVisualizar()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    auto row = ui->tableView->selectionModel()->currentIndex().row();

    auto dado = model->record(row).value(0);
    meuDebug("indice:" + dado.toString());

//    Receita rec(this, dado.toInt());
//    rec.exec();
    TelaReceita *rec = new TelaReceita(this, dado.toInt());

    rec->show();
    refreshGrid();
}

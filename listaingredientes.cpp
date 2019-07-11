#include "listaingredientes.h"
#include "ui_listaingredientes.h"
#include "utils.h"
#include "ingrediente.h"
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QPushButton>
#include <QSqlRecord>

ListaIngredientes::ListaIngredientes(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ListaIngredientes)
{
    ui->setupUi(this);

    QSqlDatabase db = QSqlDatabase::database("default");

    model = new QSqlQueryModel();

    model->setQuery("SELECT ID,"
                    "       DESCRICAO,"
                    "       UNIDADE,"
                    "       QTD_PACOTE,"
                    "       VALOR_PACOTE"
                    "  FROM INGREDIENTE;"
                    , db);
    model->setHeaderData(0, Qt::Horizontal, tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, tr("Descrição"));
    model->setHeaderData(2, Qt::Horizontal, tr("Unidade"));
    model->setHeaderData(3, Qt::Horizontal, tr("Qtd. Pacote"));
    model->setHeaderData(4, Qt::Horizontal, tr("Valor Pacote"));

    ui->tableView->setModel(model);

    QPushButton *btnNovo = new QPushButton("Novo...");

    connect(btnNovo, &QPushButton::released, this, &ListaIngredientes::handleNew);    

    QPushButton *btnVisualizar = new QPushButton("Visualizar");
    connect(btnVisualizar, &QPushButton::released, this, &ListaIngredientes::handleVisualizar);

    ui->buttonBox->addButton(btnNovo, QDialogButtonBox::ApplyRole);
    ui->buttonBox->addButton(btnVisualizar, QDialogButtonBox::ApplyRole);
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

void ListaIngredientes::handleVisualizar()
{
    QItemSelectionModel *select = ui->tableView->selectionModel();
    auto row = ui->tableView->selectionModel()->currentIndex().row();


    auto dado = model->record(row).value(0);
    meuDebug("indice:" + dado.toString());

    Ingrediente ing(this, dado.toInt());
    ing.exec();
    QString queryStr = model->query().executedQuery();
    model->clear();
    model->query().clear();
    model->setQuery(queryStr, QSqlDatabase::database("default"));
}


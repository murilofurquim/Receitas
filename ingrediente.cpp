#include "ingrediente.h"
#include "ui_ingrediente.h"
#include "utils.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>

Ingrediente::Ingrediente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingrediente)
{
    ui->setupUi(this);
}

Ingrediente::~Ingrediente()
{
    delete ui;
}

void Ingrediente::on_Ingrediente_accepted()
{
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);
    qry.prepare("insert into ingrediente('descricao') "
                "values (:desc)");
    qry.bindValue(":desc", ui->lineEdit->text());
    if (qry.exec())
    {
        meuDebug("inseriu ingrediente" + ui->lineEdit->text());
    }
    else
    {
        meuDebug("`não inseriu ingrediente");
    }
}

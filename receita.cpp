#include "receita.h"
#include "ui_receita.h"
#include <QSqlDatabase>
#include "utils.h"
#include <QSqlQuery>
#include <QSqlError>

Receita::Receita(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Receita)
{
    ui->setupUi(this);
}

Receita::~Receita()
{
    delete ui;
}

void Receita::on_Receita_accepted()
{
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);
    qry.prepare("insert into receita(descricao, modo_preparo) "
                "values (:desc, :modo_prep)");
    qry.bindValue(":desc", ui->lineEdit->text());
    qry.bindValue(":modo_prep", ui->plainTextEdit->toPlainText());
    if (qry.exec())
    {
        meuDebug("inseriu receita" + ui->lineEdit->text());
    }
    else
    {

        meuDebug("`não inseriu ingrediente");
        meuDebug(qry.lastError().text());

    }
}

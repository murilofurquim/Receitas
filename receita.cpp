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

Receita::Receita(QWidget *parent, int id) : Receita(parent)
{
    this->id = id;

    if (this->id > 0)
    {
        meuDebug("Receita");
        CarregarReceita(this->id);
    }

}

Receita::~Receita()
{
    delete ui;
}

void Receita::on_Receita_accepted()
{
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);

    if (id ==0)
    {
        qry.prepare("insert into receita(descricao, modo_preparo) "
                    "values (:desc, :modo_prep)");
        qry.bindValue(":desc", ui->lineEdit->text());
        qry.bindValue(":modo_prep", ui->plainTextEdit->toPlainText());
        if (qry.exec())
        {
            meuDebug("inseriu receita" + ui->lineEdit->text());
        }
        else
        {   meuDebug("`não inseriu ingrediente");
            meuDebug(qry.lastError().text());
        }
    }
    else {
        qry.prepare("update receita "
                    "   set descricao = :desc"
                    "     , modo_preparo = :modo_prep"
                    " where id = :id"
                    );
        qry.bindValue(":desc", ui->lineEdit->text());
        qry.bindValue(":modo_prep", ui->plainTextEdit->toPlainText());
        qry.bindValue(":id", id);

        if (qry.exec())
        {
            meuDebug("alterou receita" + ui->lineEdit->text());
        }
        else
        {   meuDebug("`não alterou ingrediente");
            meuDebug(qry.lastError().text());
        }

    }
}

void Receita::CarregarReceita(int id_receita)
{
    meuDebug("Carregando receita");
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);
    qry.prepare("select id, descricao, modo_preparo"
                "  from receita"
                " where id = :id_receita");
    qry.bindValue(":id_receita", id_receita);


    if (qry.exec())
    {
        qry.first();
        ui->lineEdit->setText(qry.value("descricao").toString());
        ui->plainTextEdit->setPlainText(qry.value("modo_preparo").toString());
    }
}

#include "ingrediente.h"
#include "ui_ingrediente.h"
#include "utils.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlError>

Ingrediente::Ingrediente(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Ingrediente)
{
    ui->setupUi(this);
}

Ingrediente::Ingrediente(QWidget *parent, int id): Ingrediente(parent)
{
    this->id = id;

    if (this->id > 0)
        carregar(this->id);
}

Ingrediente::~Ingrediente()
{
    delete ui;
}

void Ingrediente::on_Ingrediente_accepted()
{
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);

    if (id == 0)
    {
        qry.prepare("INSERT INTO INGREDIENTE ("
                    "                            ID,"
                    "                            DESCRICAO,"
                    "                            UNIDADE,"
                    "                            QTD_PACOTE,"
                    "                            VALOR_PACOTE"
                    "                        )"
                    "                        VALUES ("
                    "                            :ID,"
                    "                            :DESCRICAO,"
                    "                            :UNIDADE,"
                    "                            :QTD_PACOTE,"
                    "                            :VALOR_PACOTE"
                    "                        );"
                    );


        qry.bindValue(":DESCRICAO", ui->edtDescricao->text());
        qry.bindValue(":UNIDADE", ui->edtUnidade->currentText());
        qry.bindValue(":QTD_PACOTE", ui->edtQtdePacote->text());
        qry.bindValue(":VALOR_PACOTE", ui->edtValorPacote->text());

        if (qry.exec())
        {
            meuDebug("inseriu ingrediente" + ui->edtDescricao->text());
        }
        else
        {
            auto erro = qry.lastError();
            erro.text();

            qDebug () << "Não inseriu ingrediente: " << erro.text();
        }
    }
    else {
        qry.prepare("UPDATE INGREDIENTE"
                    "   SET DESCRICAO = :DESCRICAO,"
                    "       UNIDADE = :UNIDADE,"
                    "       QTD_PACOTE = :QTD_PACOTE,"
                    "       VALOR_PACOTE = :VALOR_PACOTE"
                    " WHERE ID = :ID"
                    );
        qry.bindValue(":ID", id);
        qry.bindValue(":DESCRICAO", ui->edtDescricao->text());
        qry.bindValue(":UNIDADE", ui->edtUnidade->currentText());
        qry.bindValue(":QTD_PACOTE", ui->edtQtdePacote->text());
        qry.bindValue(":VALOR_PACOTE", ui->edtValorPacote->text());

        if (qry.exec())
        {
            meuDebug("alterou ingrediente" + ui->edtDescricao->text());
        }
        else
        {   meuDebug("`não alterou ingrediente");
            meuDebug(qry.lastError().text());
        }

    }

}

void Ingrediente::carregar(int id_ingrediente)
{
    meuDebug("Carregando Ingrediente " + QString::number(id_ingrediente));
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);
    qry.prepare("SELECT ID,"
                "       DESCRICAO,"
                "       UNIDADE,"
                "       QTD_PACOTE,"
                "       VALOR_PACOTE"
                "  FROM INGREDIENTE"
                " where id = :id_ingrediente");
    qry.bindValue(":id_ingrediente", id_ingrediente);

    if (qry.exec())
    {
        qry.first();
        ui->edtDescricao->setText(qry.value("DESCRICAO").toString());
        ui->edtUnidade->setCurrentText(qry.value("UNIDADE").toString());
        ui->edtQtdePacote->setText(qry.value("QTD_PACOTE").toString());
        ui->edtValorPacote->setText(qry.value("VALOR_PACOTE").toString());
    }
    else {
        qDebug() << "Erro ao abrir ingrediente: " << qry.lastError().text();
    }
}

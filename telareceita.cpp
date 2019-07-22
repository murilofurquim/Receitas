#include "telareceita.h"
#include "ui_telareceita.h"
#include <QDebug>
#include "utils.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlError>

TelaReceita::TelaReceita(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaReceita)
{
    ui->setupUi(this);
    setAttribute(Qt::WA_DeleteOnClose);

}

TelaReceita::TelaReceita(QWidget *parent, int id): TelaReceita(parent)
{
    this->id = id;
    CarregarReceita();
}

TelaReceita::~TelaReceita()
{
    qDebug() << "Destruindo receita";
    delete ui;
}

int TelaReceita::getId() const
{
    return id;
}

void TelaReceita::setId(int value)
{
    id = value;
}

void TelaReceita::CarregarReceita()
{

    meuDebug("Carregando receita");
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);
    qry.prepare("select id, descricao, modo_preparo"
                "  from receita"
                " where id = :id_receita");
    qry.bindValue(":id_receita", id);


    if (qry.exec())
    {
        qry.first();

        ui->edtDescricao->setText(qry.value("descricao").toString());
        ui->edtModoPreparo->setPlainText(qry.value("modo_preparo").toString());
    }

}

void TelaReceita::salvarReceita()
{
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry(db);

    if (id ==0)
    {
        qry.prepare("insert into receita(descricao, modo_preparo) "
                    "values (:desc, :modo_prep)");
        qry.bindValue(":desc", ui->edtDescricao->text());
        qry.bindValue(":modo_prep", ui->edtModoPreparo->toPlainText());
        if (qry.exec())
        {
            meuDebug("inseriu receita" + ui->edtDescricao->text());
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
        qry.bindValue(":desc", ui->edtDescricao->text());
        qry.bindValue(":modo_prep", ui->edtModoPreparo->toPlainText());
        qry.bindValue(":id", id);

        if (qry.exec())
        {
            meuDebug("alterou receita" + ui->edtDescricao->text());
        }
        else
        {   meuDebug("`não alterou ingrediente");
            meuDebug(qry.lastError().text());
        }

    }

    emit registroAlterado();
}

void TelaReceita::on_actionSalvar_triggered()
{
    salvarReceita();
}

#include "telaingredientereceita.h"
#include "ui_telaingredientereceita.h"
#include <QtSql/QSqlQuery>

TelaIngredienteReceita::TelaIngredienteReceita(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TelaIngredienteReceita)
{
    ui->setupUi(this);
    setWindowFlags(Qt::Dialog);

    ingredienteModel = new QSqlQueryModel(this);
    QSqlDatabase db = QSqlDatabase::database("default");

    QSqlQuery qry = QSqlQuery("select id, descricao from ingrediente", db);

    if (qry.exec())
    {
        qDebug() << "abriu combo ingredientes";

        while (qry.next())
        {
            qDebug() << qry.value(0).toString() << " " << qry.value(1).toString();
        }

    }
    else {
        qDebug() << "NÃO abriu combo ingredientes";
    }

    ingredienteModel->setQuery(qry);


    qDebug() << "combo ingredientes: " << ingredienteModel->rowCount();

    ui->cbIngrediente->setModel(ingredienteModel);
    ui->cbIngrediente->setModelColumn(1);
}

TelaIngredienteReceita::~TelaIngredienteReceita()
{
    delete ui;
}

void TelaIngredienteReceita::on_buttonBox_accepted()
{
    qDebug() << "combo ingrediente: " << ui->cbIngrediente->currentText();
    qDebug() << "combo ingrediente: " << ui->cbIngrediente->currentData().toString();

    auto i = ui->cbIngrediente->currentIndex();
    auto mo = ui->cbIngrediente->model()->index(i, 0);
    qDebug() << "combo ingrediente: " << ui->cbIngrediente->model()->data(mo).toString();


    setId_ingreidente(ui->cbIngrediente->currentData().toInt());
    setUnidade(ui->edtUnidade->currentText());
    setQuantidade(ui->edtQuantidade->text().toInt());
    emit(aceitou());
}

double TelaIngredienteReceita::quantidade() const
{
    return m_quantidade;
}

void TelaIngredienteReceita::setQuantidade(double quantidade)
{
    m_quantidade = quantidade;
}

QString TelaIngredienteReceita::unidade() const
{
    return m_unidade;
}

void TelaIngredienteReceita::setUnidade(const QString &unidade)
{
    m_unidade = unidade;
}

int TelaIngredienteReceita::id_ingreidente() const
{
    return m_id_ingreidente;
}

void TelaIngredienteReceita::setId_ingreidente(int id_ingreidente)
{
    m_id_ingreidente = id_ingreidente;
}

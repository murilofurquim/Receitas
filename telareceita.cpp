#include "telareceita.h"
#include "ui_telareceita.h"
#include <QDebug>
TelaReceita::TelaReceita(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TelaReceita)
{
    ui->setupUi(this);
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

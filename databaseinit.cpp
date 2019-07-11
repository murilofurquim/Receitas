#include "databaseinit.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include "utils.h"

DatabaseInit::DatabaseInit()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE", "default");
    db.setDatabaseName("C:\\Dados\\receitas.db");

    if (db.open())
    {
        meuDebug("Abriu");
    }
    else {
        meuDebug("Não abriu");
    }

    auto tabelas = db.tables();

    if (tabelas.indexOf("ingrediente") == -1)
    {
        meuDebug("criando tabela ingrediente");

        auto qry = db.exec("CREATE TABLE RECEITA (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, DESCRICAO TEXT NOT NULL, MODO_PREPARO TEXT);"
                           );

        qry = db.exec("CREATE TABLE INGREDIENTE (ID INTEGER PRIMARY KEY AUTOINCREMENT NOT NULL, DESCRICAO TEXT NOT NULL, UNIDADE TEXT, QTD_PACOTE REAL, VALOR_PACOTE REAL);");

        qry = db.exec("CREATE TABLE RECEITA_INGREDIENTE (ID INTEGER PRIMARY KEY, ID_RECEITA INTEGER, ID_INGREDIENTE INTEGER, ID_SUBRECEITA INTEGER, UNIDADE TEXT, QTDE REAL, FOREIGN KEY (ID_INGREDIENTE) REFERENCES INGREDIENTE (ID) ON DELETE NO ACTION, FOREIGN KEY (ID_RECEITA) REFERENCES RECEITA (ID) ON DELETE CASCADE, FOREIGN KEY (ID_SUBRECEITA) REFERENCES RECEITA (ID) ON DELETE NO ACTION);");

    }

    db.close();
}

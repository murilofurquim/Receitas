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


        auto qry = db.exec("CREATE TABLE `ingrediente` ( `id` INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT, `descricao` TEXT )");
    }

    db.close();
}

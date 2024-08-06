#include<principal.h>
#include<QApplication>

int main(int argc, char *argv[])
{
    QApplication app(argc,argv);
   /*     QPushButton bouton("bonjour");
    bouton.show();*/

    PRINCIPAL fen;
    fen.show();

    return app.exec();
}

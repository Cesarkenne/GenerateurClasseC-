#ifndef GENER_H
#define GENER_H
#include <QtWidgets>
#include <QMessageBox>


class ELEMENT
{
public:
    ELEMENT();
    ~ELEMENT();

    QString nom;
    QString mere;
    QString auteur;
    QString role;
    QDate date;
    bool bol1;
    bool bol2;
    bool bol3;

};

class GENERE: public QDialog
{
        Q_OBJECT
public:
    GENERE();
    GENERE(ELEMENT *dat);
    ~GENERE();
public slots:
    void enregist();
private:
    ELEMENT m_dat;
    QString m_base;
    QString m_class;
    QString m_mult1;
    QString m_mult2;
    QString m_private;
    QString m_public;
    QString m_protected;
    QVBoxLayout *m_vlay;
    QTextEdit *m_text;
    QPushButton *m_buton;
    QPushButton *m_buton1;
    QHBoxLayout *m_hlay;

};


#endif // GENER_H

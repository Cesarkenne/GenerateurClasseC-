#ifndef PRINCIPAL_H
#define PRINCIPAL_H
#include<QtWidgets>
#include <gener.h>


class PRINCIPAL: public QWidget
{
    Q_OBJECT
public:
    PRINCIPAL();
    ~PRINCIPAL();
public slots:
   void dialogue();
private:
    QVBoxLayout *m_vlay;

    QHBoxLayout *m_hlay;
    QFormLayout *m_form;
    QLineEdit *m_line1;
    QLineEdit *m_line2;
    QGroupBox *m_box1;

    QGroupBox *m_box2;
    QVBoxLayout *m_vlay1;
    QCheckBox *m_check1;
    QCheckBox *m_check2;
    QCheckBox *m_check3;

    QGroupBox *m_box3;
    QFormLayout *m_form2;
    QLineEdit *m_line3;
    QDateEdit *m_date;
    QTextEdit *m_text;

    QHBoxLayout *m_hlay2;
    QPushButton *m_buton;
    QPushButton *m_buton1;
    ELEMENT *m_capt;
    GENERE *m_gen;


};




#endif // PRINCIPAL_H

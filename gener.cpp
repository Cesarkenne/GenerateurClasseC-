#include <gener.h>

GENERE::GENERE(): QDialog()
{




}

GENERE::GENERE(ELEMENT *dat)
{

    m_vlay= new QVBoxLayout(this);
    m_hlay= new QHBoxLayout();
    m_text= new QTextEdit();
    m_buton1= new QPushButton("Enregistrer");
    m_buton= new QPushButton("Fermer");
    m_vlay->addWidget(m_text);
    m_hlay->addWidget(m_buton);
    m_hlay->addWidget(m_buton1);
    m_vlay->addLayout(m_hlay);
    m_base= "Auteur : "+dat->auteur+"\n"+"Date de creation : "+dat->date.toString()+"\n"+"Role :"+"\n\t"+dat->role+"";
    m_mult1= "#ifndef __"+dat->nom.toUpper()+"__"+"\n"+"#define __"+dat->nom.toUpper()+"__"+"\n";
    m_mult2= "#endif //__"+dat->nom.toUpper()+"__";
    m_public="public : \n";
    m_class= "class "+dat->nom.toUpper()+" ";
    m_private= "\n\t private : \n\n";
    m_protected= "\t protected :\n\n";
    m_text->setReadOnly(true);
    QObject::connect(m_buton,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
    QObject::connect(m_buton1,SIGNAL(clicked()),this,SLOT(enregist()));


    if(dat->nom.isEmpty())
    {
        int rep = QMessageBox::warning(this, "Erreur", "Attention, vous devriez entrer le nom de la classe !");
        if(rep == QMessageBox::Ok)
        {
            return;
        }
    }
    else if(dat->bol1!= true)
    {
        QMessageBox::critical(this, "Attention", "La protection contre les instrusions multilple est primodiale !");
    }
    else if (dat->bol3==true&&dat->bol2==true&&dat->mere.isEmpty()==false)
    {
        m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+": public "+dat->mere.toUpper()+"{"+"\n\n"+"\t"+m_public+"\n\t"+dat->nom.toUpper()+"();"+"\n\t~"+dat->nom.toUpper()+"();\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);
    }
    else if (dat->bol3==true&&dat->bol2==true)
    {
    m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+" {"+"\n\n"+"\t"+m_public+"\n\t"+dat->nom.toUpper()+"();"+"\n\t~"+dat->nom.toUpper()+"();\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);
    }
    else if(dat->mere.isEmpty()!= true)
    {
        m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+": public "+dat->mere.toUpper()+" {"+"\n\n"+"\t"+m_public+"\n\t"+dat->nom.toUpper()+"();\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);
    }
    else if(dat->bol2==true)
    {
        m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+" {"+"\n\n"+"\t"+m_public+"\n\t"+"\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);
    }
    else if(dat->bol3==true)
    {
    m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+" {"+"\n\n"+"\t"+m_public+"\n\t~"+dat->nom.toUpper()+"();\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);    }
    else if (dat->nom.isEmpty()!=true)
    {
        m_text->setPlainText(m_base+"\n\n"+m_mult1+"\n"+m_class+" {"+"\n\n"+"\t"+m_public+"\n\t"+dat->nom.toUpper()+"();\n"+m_private+m_protected+"};\n"+"\n"+m_mult2);
    }

}
void GENERE::enregist()
{
    QFileDialog::getSaveFileName(this,"Enregister ce fichier",QString(),"*.txt");
}

GENERE::~GENERE()
{
    delete m_vlay;
    delete m_hlay;
    delete m_text;
    delete m_buton;
    delete m_buton1;
}

ELEMENT::ELEMENT()
{



}

ELEMENT::~ELEMENT()
{


}

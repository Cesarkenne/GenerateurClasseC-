#include<principal.h>


PRINCIPAL::PRINCIPAL(): QWidget()
{
	//creation du layout principal
    m_vlay= new QVBoxLayout(this);

    //definition du 1er layout avec insertion des GroupBox et le formulaire principal Grace au QFormLayout
   m_box1= new QGroupBox("Définition de la classe");
   m_hlay=new QHBoxLayout;
   m_form= new QFormLayout;
   m_line1= new QLineEdit;
   m_line2= new QLineEdit;
   m_form->addRow("&Nom: ",m_line1);
   m_form->addRow("Classe &mère: ", m_line2);
   m_box1->setLayout(m_form);
   m_hlay->addWidget(m_box1);
   	//Ajout du 1er layout dans le layout principal
    m_vlay->addLayout(m_hlay);

    //definition du 1er layout avec insertion des CheckBox(case a cochée) 
   m_vlay1= new QVBoxLayout;
   m_box2= new QGroupBox("Options");
   m_box2->setLayout(m_vlay1);
   m_check1=new QCheckBox("Protéger le &Header contre les intrusions multiples");
   m_check1->setChecked(true);
   m_check2=new QCheckBox("Générer un &Constructeur par defaut");
   m_check3=new QCheckBox("Générer un &Destructeur");
   m_vlay1->addWidget(m_check1);
   m_vlay1->addWidget(m_check2);
   m_vlay1->addWidget(m_check3);
   m_box2->setLayout(m_vlay1);

   	//Ajout du 2em layout dans le layout principal
    m_vlay->addWidget(m_box2);

    //definition du dernier groupBox contenant des les commentaires, role et date de creation de la classe
   m_box3= new QGroupBox("Ajouter des commentaires");
   m_box3->setCheckable(true);
   m_form2= new QFormLayout;
   m_line3= new QLineEdit;
   m_date= new QDateEdit;
   m_text= new QTextEdit;
   m_form2->addRow("&Auteur: ",m_line3);
   m_form2->addRow("Da&te de creation: ",m_date);
   m_form2->addRow("&Rôle de la classe: ", m_text);
   m_box3->setLayout(m_form2);
   //m_hlay->addWidget(m_box1);

   //Ajout du 3em layout dans le layout principal
   m_vlay->addWidget(m_box3);

   //definition des boutons et creation d'une conection des touche au slot personnalisé et au 
   m_hlay2= new QHBoxLayout;
   m_buton= new QPushButton("Generer");
   m_buton1= new QPushButton("Quitter");
   m_hlay2->addWidget(m_buton,1,Qt::AlignRight);
   m_hlay2->addWidget(m_buton1,0);
   m_buton1->setCursor(Qt::PointingHandCursor);
   m_buton->setCursor(Qt::PointingHandCursor);
   m_vlay->addLayout(m_hlay2);
   m_buton1->setToolTip("Quitter le programme");
   m_buton->setToolTip("Générer la classe");
   //connection du bouton quiter au slot predefini quit
   QObject::connect(m_buton1,SIGNAL(clicked(bool)),qApp,SLOT(quit()));
   //connection du bouton gernere au slot personnalise
   QObject::connect(m_buton,SIGNAL(clicked(bool)),this,SLOT(dialogue()));


}
void PRINCIPAL:: dialogue()
{
	//implementation du slot personnalisé dialogue, qui fais appel au m_capt qui capture les information entrée par l'utilisateur
   m_capt= new ELEMENT;
   m_capt->nom= m_line1->text();
   m_capt->mere= m_line2->text();
   m_capt->auteur= m_line3->text();
   m_capt->role= m_text->toPlainText();
   m_capt->date= m_date->date();
   m_capt->bol1=m_check1->isChecked();
   m_capt->bol2=m_check2->isChecked();
   m_capt->bol3=m_check3->isChecked();
   m_gen= new GENERE(m_capt);
   m_gen->show();

}

	//implementation du destructeur
PRINCIPAL::~PRINCIPAL()
{
  delete m_vlay;
  delete m_hlay;
  delete m_form;
  delete m_line1;
  delete m_line2;
  delete m_box1;
  delete m_box2;
  delete m_vlay1;
  delete m_check1;
  delete m_check2;
  delete m_check3;
  delete m_box3;
  delete m_form2;
  delete m_line3;
  delete m_date;
  delete m_text;
  delete m_hlay2;
  delete m_buton;
  delete m_buton1;
  delete m_capt;
}

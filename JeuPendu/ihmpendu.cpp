#include "ihmpendu.h"
#include "ui_ihmpendu.h"
#include "CUJeuPendu.h"
#include <QFile>
#include <QMessageBox>
#include <QSignalMapper>
#include <time.h>

//const QString signature = "Jeu du pendu"; //le nom du programme

IHMPendu::IHMPendu(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::IHMPendu)
{
    ui->setupUi(this);


    afficherPendu(0);
    ui->nombreErreur->hide();
}

IHMPendu::~IHMPendu()
{
    delete ui;
}

void IHMPendu::initHMDebutJeu()
{
    //BoutonJouerOnOff(false);
    addJeuPendu->updateWordsFiles();
    afficherNomFichierMots(addJeuPendu->getWordsFile());
    afficherNombreDeMots(addJeuPendu->getWordsNumber());
    afficherPendu(0);
    ui->nombreErreur->show();
}

void IHMPendu::RecupAddJeu(CUJeuPendu *uneAddJeu)
{
    addJeuPendu = uneAddJeu;
}
void IHMPendu::RecupAddFenetreConfig(QWidget *uneAddFenetre)
{
    addFenetreConfig = uneAddFenetre;
}
void IHMPendu::RecupAddLineEdit(QLineEdit *uneAddLine)
{
    addLineEdit = uneAddLine;
}

void IHMPendu::LabelMotATrouverVisible(bool active)
{
    if(active == true)
    {   ui->MotaTrouverLabel->show();   }
    else
    {   ui->MotaTrouverLabel->hide();   }
}
void IHMPendu::BoutonJouerOnOff(bool active)
{
    if(active == true)
    {   ui->JouerBut->setEnabled(true);     }
    else
    {   ui->JouerBut->setDisabled(true);    }
}
void IHMPendu::BoutonConfigOnOff(bool active)
{
    if(active == true)
    {   ui->ConfigBut->setEnabled(true);    }
    else
    {   ui->ConfigBut->setDisabled(true);   }
}
void IHMPendu::NomOnOff(bool active)
{
    if(active == true)
    {   ui->nomduJoueurLabel->setEnabled(true);     }
    else
    {   ui->nomduJoueurLabel->setDisabled(true);    }
}

void IHMPendu::afficher(QString mess)
{
    ui->MotCacher->setText(mess);
    ui->MotCacher->show();
}

void IHMPendu::afficherPendu(int etapeP)
{
    ui->PhotoErreur->setPixmap(QPixmap("Ressource/ImagePendu"+QString::number(etapeP)+".png"));
    if(etapeP!=0)
    {
        ui->nombreErreur->setText(QString::number(etapeP) + " Erreur");
    }
    else
    {
        ui->nombreErreur->setText("Aucune erreur");
    }
}

void IHMPendu::afficherNomFichierMots(QString nomFichierM)
{
    ui->FichierMots->setText("Fichier de mots : " + nomFichierM);
}
void IHMPendu::afficherNombreDeMots(int nbmots)
{
    ui->MotsDispo->setText("Mots disponible: " + QString::number(nbmots));
}

QString IHMPendu::saisirNom()
{
    QString name;
    if(ui->NameLine->text().isEmpty()==false)
    {
        name = ui->NameLine->text();
    }
    else
    {
        QMessageBox msgBox; QString x;
        msgBox.setIcon(QMessageBox::Information);
        x="le nom du joueur est mal rentrée !";
        msgBox.setText(x);
        msgBox.exec();
    }
    return name;
}

void IHMPendu::on_ConfigBut_clicked()
{
    QWidget* configWindow = new QWidget();

    configWindow->setFixedWidth(600);
    configWindow->setFixedHeight(400);
    configWindow->setWindowTitle("Configuration");
    configWindow->show();

    QLayout* layoutConfig = new QGridLayout(configWindow);
    layoutConfig[0].setGeometry(QRect(0,0,600,400));
    layoutConfig->setContentsMargins(0,0,0,0);

    QLabel* labelConfig = new QLabel(configWindow);

    //font
    QFont fontConfig;
    fontConfig.setPointSize(16);
    fontConfig.setBold(true);

    //labelConfig
    labelConfig[0].setText("Saisir le nom du fichier contenant les mots :");
    labelConfig[0].setFont(fontConfig);
    layoutConfig->addWidget(&labelConfig[0]);
    //layoutConfig->setAlignment(&labelConfig[0],)

    labelConfig[0].show();

    QLineEdit* lineEditConfig = new QLineEdit(configWindow);
    lineEditConfig[0].setGeometry(100,300,150,30);
    lineEditConfig[0].show();
    //layoutConfig[0].addWidget(labelConfig);

    RecupAddFenetreConfig(configWindow);
}

void IHMPendu::on_JouerBut_clicked()
{

    BoutonConfigOnOff(false);
    //BoutonJouerOnOff(false);
    NomOnOff(false);

    addJeuPendu->startGame();
    initHMDebutJeu();
    slotBouton();
    ui->MotCacher->setText(addJeuPendu->getWordSelect());
    afficherPendu(addJeuPendu->getErrorNb());
}

void IHMPendu::boutonclic()
{
    QPushButton* button = (QPushButton*)sender();
    QChar letterclick = button->text()[0];
    QString wordS=addJeuPendu->getWordSelect(),
            wordP = addJeuPendu->getWordPlay();
    int flag=0,nberror = addJeuPendu->getErrorNb();

    for(int pt=0;pt<wordS.size();pt++)
    {
        QString motfinal;

        if(wordS[pt]==letterclick)
        {
            flag=1;
            button->setEnabled(false);

            wordP[pt] = letterclick; //remplacer la ieme lettre du mot par la lettre cliquee

            addJeuPendu->setWordPlay(wordP);
            ui->MotCacher->setText(wordP);
        }
        else
        {
            button->setEnabled(false);
        }
    }
    if(flag==0)
    {
        nberror=nberror+1;
        addJeuPendu->setErrorNb(nberror);
        afficherPendu(nberror);
    }
    else
    {
        if(flag==1)
        {
            //mettre le fond vert du bouton ici
        }
    }
}






    /*for(int pt=0;pt<word.size();pt++)
    {
        if(letterclick==word[pt])
        {
            flag =1;
        }
        if(pt == word.size() && flag == 0)
        {
            //button->
            QString motfini = addJeuPendu->getWordPlay();
            if(motfini.contains('-',Qt::CaseSensitivity())==false)
            {
                //blahblah fini
            }
        }
    }


QString a; a=addJeuDuPendu->getmotEnCours();
int boll=0;
for(int i=0;i<addJeuDuPendu->getmotEnCours().size();i++)
{

    QString motfinal;
    lettremot=a[i];

        if(lettremot==letterclick)
        {
            boll=1;
            button->setEnabled(false);

            QString motc =addJeuDuPendu->getmotChoisi();
            motc[i] = lettremot[0]; //remplacer la ieme lettre du mot par la lettre cliquee

            addJeuDuPendu->setMotChoisi(motc);
            ui->motatrouver->setText(motc);
        }
        else
        {
            button->setEnabled(false);

             }
}
if(boll==0)
{
    afficherPendu(pendu);


ui->nbrerreur->setText(QString::number( pendu));pendu++;}
else {
    if(boll==1)
    {
        //mettre le fond vert du bouton ici
    }
}
}*/



void IHMPendu::slotBouton()
{
    int alpha=65;
    QSignalMapper *signalMapper = new QSignalMapper(this);
    for (int i=0;i<26;i++)
    {
        Bouton[i]=new QPushButton (QString(alpha++));
        Bouton[i]->setMinimumWidth(5);
        Bouton[i]->setMinimumHeight(5);

        ui->gridLayout->addWidget(Bouton[i],i/10,i%10);
        signalMapper->setMapping(Bouton[i],i);
        QObject::connect(Bouton[i], SIGNAL(clicked()), this, SLOT(boutonclic()));
    }
    //https://www.siloged.fr/cours/QTCreator/Evenements.html
    //https://www.siloged.fr/cours/QTCreator/Damierabasedeboutons.html
}


void IHMPendu::slotBoutonActualiser()
{

}
void IHMPendu::slotBoutonParcourir()
{

}
void IHMPendu::slotBoutonAnnuler()
{
    addFenetreConfig->close();
}


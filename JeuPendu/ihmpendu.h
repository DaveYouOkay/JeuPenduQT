#ifndef IHMPENDU_H
#define IHMPENDU_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>


QT_BEGIN_NAMESPACE
namespace Ui { class IHMPendu; }
QT_END_NAMESPACE

class IHMPendu : public QMainWindow
{
    Q_OBJECT

private:
    Ui::IHMPendu *ui;

    class CUJeuPendu* addJeuPendu;
    QPushButton* Bouton[26];
    QWidget* addFenetreConfig;
    QLineEdit* addLineEdit;

public:
    IHMPendu(QWidget *parent = nullptr);
    ~IHMPendu();

    void initHMDebutJeu();
    //recupe l'adresse des objets d'autre classe
    void RecupAddJeu(CUJeuPendu* uneAddJeu);
    void RecupAddFenetreConfig(QWidget* uneAddFenetre);
    void RecupAddLineEdit(QLineEdit* uneAddLine);

    //methode
    void LabelMotATrouverVisible(bool active);
    void BoutonJouerOnOff(bool active);
    void BoutonConfigOnOff(bool active);
    void NomOnOff(bool active);
    void afficher(QString mess);
    void afficherPendu(int etapeP);
    void afficherNomFichierMots(QString nomFichierM);
    void afficherNombreDeMots(int nbmots);
    QString saisirNom();

    //methode bouton generer dynamiquement
    void slotBouton();
    void slotBoutonActualiser();
    void slotBoutonParcourir();
    void slotBoutonAnnuler();

private slots:
    void boutonclic();
    void on_JouerBut_clicked();
    void on_ConfigBut_clicked();
};
#endif // IHMPENDU_H

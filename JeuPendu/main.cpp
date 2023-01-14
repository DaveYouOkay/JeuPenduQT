
#include <QApplication>
#include "ihmpendu.h"
#include "CUJeuPendu.h"
#include <time.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IHMPendu ihm;
    CUJeuPendu jeuP;

    ihm.RecupAddJeu(&jeuP); //recupere l'adresse de l'objet jeuP
    jeuP.RecupAddIHM(&ihm); //recupere l'adresse de l'objet ihm
    ihm.show();
    return a.exec();
}

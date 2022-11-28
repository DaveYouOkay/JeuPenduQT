
#include <QApplication>
#include "ihmpendu.h"
#include "CUJeuPendu.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    IHMPendu ihm;
    CUJeuPendu jeuP;

    ihm.RecupAddJeu(&jeuP);
    jeuP.RecupAddIHM(&ihm);

    ihm.show();
    return a.exec();
}

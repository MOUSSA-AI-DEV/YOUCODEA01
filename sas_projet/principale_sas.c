#include "heads.h"

int main()
{

    int choix;

    do
    {

        printf("1. cree compte si vous  plait ");
        cre_compte();
        prinf("vous pouvez afectuer choix de 1:modifier \n 2:consulter profile\n 3:Effectuer Achat\n 4:Mes Statistique\n 0: sortir");
        printf("enter votre action sur profile");
        scanf("%d", choix);

        switch (choix)
        {
        case 1:

            modifie();
            break;
        case 2:
            consulter();
            break;
        case 3:
            Effectuer_Achat();
            break;
        case 4:
            Afficher_s();
            break;
        case 5:
          

        
            break;
        case 0:
            printf("Thalla ");
            return;

        default:
        }

    } while (choix != 0)
}

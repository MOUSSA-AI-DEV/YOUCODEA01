#include "heads.h"

int main() {
    int choix, sousChoix;
    Client client;
    Produit produits[MAX_PRODUCTS] = {
        {1, "Ordinateur Portable", "Electronique", 799.0, 5, "PC portable avec Intel i5, 8GB RAM"},
        {2, "Smartphone", "Electronique", 499.0, 10, "Smartphone avec ecran 6 pouces"},
        {3, "Casque Audio", "Accessoire", 89.0, 15, "Casque audio filaire avec micro"},
        {4, "Souris", "Accessoire", 25.0, 20, "Souris optique USB"},
        {5, "Clavier", "Accessoire", 45.0, 12, "Clavier mecanique USB"}
    };
    int nombre_produitProduits = 5;
    char nomRecherche[MAX_NAME];
    char catRecherche[MAX_NAME];

    printf("CREER VOTRE COMPTE\n");
    client = cre_compte();

    do {
        printf("\n=== SYSTEME D'ACHAT CLIENT ===\n");
        printf("1: Gestion profil\n");
        printf("2: Gestion solde\n");
        printf("3: Catalogue produits\n");
        printf("4: Effectuer achat\n");
        printf("5: Mes statistiques\n");
        printf("0: Sortir\n");
        printf("Entrer votre choix: ");
        scanf("%d", &choix);

        switch(choix) {
            case 1:
                printf("\n--- GESTION PROFIL ---\n");
                printf("1: Modifier profil\n");
                printf("2: Consulter profil\n");
                printf("Entrer sous-choix: ");
                scanf("%d", &sousChoix);
                if(sousChoix == 1) client = modifie(client);
                else if(sousChoix == 2) consulter(client);
                else printf("Sous-choix invalide\n");
                break;

            case 2:
                printf("\n--- GESTION SOLDE ---\n");
                printf("1: Consulter solde\n");
                printf("2: Deposer argent\n");
                printf("Entrer sous-choix: ");
                scanf("%d", &sousChoix);
                if(sousChoix == 1) consulterSolde(client);
                else if(sousChoix == 2) {
                    float montant;
                    printf("Entrer montant a deposer: ");
                    scanf("%f", &montant);
                    client = deposerSolde(client, montant);
                } else printf("Sous-choix invalide\n");
                break;

            case 3:
                printf("\n--- CATALOGUE PRODUITS ---\n");
                printf("1: Afficher catalogue\n");
                printf("2: Trier par prix\n");
                printf("3: Trier par nom\n");
                printf("4: Rechercher par nom\n");
                printf("5: Rechercher par categorie\n");
                printf("Entrer sous-choix: ");
                scanf("%d", &sousChoix);

                if(sousChoix == 1) afficherProduits(produits, nombre_produitProduits);
                else if(sousChoix == 2) {
                    trierProduitsParPrix(produits, nombre_produitProduits);
                    afficherProduits(produits, nombre_produitProduits);
                }
                else if(sousChoix == 3) {
                    trierProduitsParNom(produits, nombre_produitProduits);
                    afficherProduits(produits, nombre_produitProduits);
                }
                else if(sousChoix == 4) {
                    printf("Entrer nom produit: ");
                    scanf("%s", nomRecherche);
                    rechercherProduitParNom(produits, nombre_produitProduits, nomRecherche);
                }
                else if(sousChoix == 5) {
                    printf("Entrer categorie: ");
                    scanf("%s", catRecherche);
                    rechercherProduitParCategorie(produits, nombre_produitProduits, catRecherche);
                }
                else printf("Sous-choix invalide\n");
                break;

            case 4:
                client = Effectuer_Achat(client, produits, nombre_produitProduits);
                break;

            case 5:
                Afficher_s(client);
                break;

            case 0:
                printf("Au revoir\n");
                break;

            default:
                printf("Choix invalide\n");
        }

    } while(choix != 0);

    return 0;
}

#include "heads.h"
Client cre_compte()
{
    Client c;
    int id = 1;
    char nome[MAX_NAME] = "";
    char prenom[MAX_NAME] = "";

    c.idClient = id++;

    printf("Entrer nom:\n");
    scanf(" %[^\n]", c.nom);

    printf("Entrer prenom:\n");
    scanf(" %[^\n]", c.prenom);

    int n = 0, p = 0;
    for (int i = 0; i < strlen(c.nom); i++)
    {
        if (c.nom[i] != ' ')
        {
            nome[n] = c.nom[i];
            n++;
        }
    }
    nome[n] = '\0';

    for (int j = 0; j < strlen(c.prenom); j++)
    {
        if (c.prenom[j] != ' ')
        {
            prenom[p] = c.prenom[j];
            p++;
        }
    }
    prenom[p] = '\0';

    sprintf(c.email, "%s.%s@gmail.com", nome, prenom);
    c.solde = 5200;
    printf("compte cree: ID=%d, Email=%s, Solde=%.2fdh\n", c.idClient, c.email, c.solde);
    return c;
}

Client modifie(Client c)
{
    printf("Modifier nom: ");
    scanf("%s", c.nom);
    printf("Modifier prenom: ");
    scanf("%s", c.prenom);
    sprintf(c.email, "%s.%s@gmail.com", c.prenom, c.nom);
    printf("Profil modifie: Nom=%s, Prenom=%s, Email=%s\n", c.nom, c.prenom, c.email);
    return c;
}

void consulter(Client c)
{
    printf("ID=%d\n Nom=%s\n Prenom=%s\n Email=%s\n Solde=%.2f\n", c.idClient, c.nom, c.prenom, c.email, c.solde);
}

void consulterSolde(Client c)
{
    printf("Solde actuel: %.2f\n", c.solde);
}

Client deposerSolde(Client c, float montant)

{
    if (montant>=0)
    {
        c.solde += montant;
        printf("Nouveau solde: %.2f\n", c.solde);
        return c;
    }else{
        printf("enter positive montant");
    }
    
}

void afficherProduits(Produit produits[], int nombre_produit)
{
    printf("\n=== CATALOGUE PRODUITS ===\n");
    for (int i = 0; i < nombre_produit; i++)
    {
        printf("%d: %s | Categorie: %s | Prix: %.2f | Stock: %d\n",
               produits[i].idProduit, produits[i].nom, produits[i].categorie, produits[i].prix, produits[i].stock);
    }
}

void afficherProduitDetails(Produit p)
{
    printf("ID=%d\n Nom=%s\n Categorie=%s\n Prix=%.2f\n Stock=%d\n Description=%s\n",
           p.idProduit, p.nom, p.categorie, p.prix, p.stock, p.description);
}

Client Effectuer_Achat(Client c, Produit produits[], int nombre_produit)
{
    int id=0;
    printf("Entrer id du produit a acheter: ");
    scanf("%d", &id);
    for (int i = 0; i < nombre_produit; i++)
    {
        if (produits[i].idProduit == id)
        {
            if (produits[i].stock > 0 && c.solde >= produits[i].prix)
            {
                produits[i].stock--;
                produits[i].quntite_consome += 1;
                c.solde -= produits[i].prix;

                printf("Achat effectue: %s | Nouveau solde: %.2f\n", produits[i].nom, c.solde);
            }
            else
            {
                printf("Stock insuffisant ou solde insuffisant\n");
            }
            return c;
        }
    }
    printf("Produit non trouve\n");
    return c;
}

void Afficher_s(Client c, Produit p[], int nombre_produitProduits)
{
   
    
        for (int i = 0; i < nombre_produitProduits; i++)
        {
            if (p[i].quntite_consome > 0)
            {

                printf("id: %d, solde:  %.2f produit_in %d ", c.idClient, c.solde, p[i].quntite_consome);
            }else{
                printf ("pas  produit effetuer achat by lindice 4");
                break;
            }
        }
}

void trierProduitsParPrix(Produit produits[], int nombre_produit)
{
    for (int i = 0; i < nombre_produit - 1; i++)
    {
        for (int j = i + 1; j < nombre_produit; j++)
        {
            if (produits[i].prix > produits[j].prix)
            {
                Produit tmp = produits[i];
                produits[i] = produits[j];
                produits[j] = tmp;
            }
        }
    }
}

void trierProduitsParNom(Produit produits[], int nombre_produit)
{
    for (int i = 0; i < nombre_produit - 1; i++)
    {
        for (int j = 1; j < nombre_produit; j++)
        {
            if (strcmp(produits[i].nom, produits[j].nom) > 0)
            {
                Produit tmp = produits[i];
                produits[i] = produits[j];
                produits[j] = tmp;
            }
        }
    }
}

void rechercherProduitParNom(Produit produits[], int nombre_produit, char nom[])
{

    int trouve = 0;
    for (int i = 0; i < nombre_produit; i++)
    {

        if (strstr(produits[i].nom, nom) != NULL)
        {
            afficherProduitDetails(produits[i]);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Produit non trouve\n");
}

void rechercherProduitParCategorie(Produit produits[], int nombre_produit, char cat[])
{
    int trouve = 0;
    for (int i = 0; i < nombre_produit; i++)
    {
        if (strstr(produits[i].categorie, cat) != NULL)
        {
            afficherProduitDetails(produits[i]);
            trouve = 1;
        }
    }
    if (!trouve)
        printf("Aucun produit trouve\n");
}

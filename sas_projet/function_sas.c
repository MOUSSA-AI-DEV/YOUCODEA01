#include "heads.h"
Client cre_compte() {
    Client c;
     int id = 1;
    c.idClient = id++;
    printf("Entrer nom: ");
    scanf("%s", c.nom);
    printf("Entrer prenom: ");
    scanf("%s", c.prenom);
    snprintf(c.email, "%s.%s@client.com", c.prenom, c.nom);
    c.solde = 5200;
    printf("Compte cree: ID=%d, Email=%s, Solde=%.2fdh\n", c.idClient, c.email, c.solde);
    return c;

}

Client modifie(Client c) {
    printf("Modifier nom: ");
    scanf("%s", c.nom);
    printf("Modifier prenom: ");
    scanf("%s", c.prenom);
    snprintf(c.email,  "%s.%s@client.com", c.prenom, c.nom);
    printf("Profil modifie: Nom=%s, Prenom=%s, Email=%s\n", c.nom, c.prenom, c.email);
    return c;
}

void consulter(Client c) {
    printf("ID=%d\nNom=%s\nPrenom=%s\nEmail=%s\nSolde=%.2f\n", c.idClient, c.nom, c.prenom, c.email, c.solde);
}

void consulterSolde(Client c) {
    printf("Solde actuel: %.2f\n", c.solde);
}

Client deposerSolde(Client c, float montant) {
    c.solde += montant;
    printf("Nouveau solde: %.2f\n", c.solde);
    return c;
}

void afficherProduits(Produit produits[], int nombre_produit) {
    printf("\n=== CATALOGUE PRODUITS ===\n");
    for(int i=0; i<nombre_produit; i++) {
        printf("%d: %s | Categorie: %s | Prix: %.2f | Stock: %d\n", 
            produits[i].idProduit, produits[i].nom, produits[i].categorie, produits[i].prix, produits[i].stock);
    }
}

void afficherProduitDetails(Produit p) {
    printf("ID=%d\nNom=%s\nCategorie=%s\nPrix=%.2f\nStock=%d\nDescription=%s\n",
           p.idProduit, p.nom, p.categorie, p.prix, p.stock, p.description);
}

Client Effectuer_Achat(Client c, Produit produits[], int nombre_produit) {
    int id;
    printf("Entrer id du produit a acheter: ");
    scanf("%d", &id);
    for(int i=0; i<nombre_produit; i++) {
        if(produits[i].idProduit == id) {
            if(produits[i].stock > 0 && c.solde >= produits[i].prix) {
                produits[i].stock--;
                produits[i].quntite_consome+=1;
                c.solde -= produits[i].prix;
                
                printf("Achat effectue: %s | Nouveau solde: %.2f\n", produits[i].nom, c.solde);
            } else {
                printf("Stock insuffisant ou solde insuffisant\n");
            }
            return c;
        }
    }
    printf("Produit non trouve\n");
    return c;
}

void Afficher_s(Client c,int nombre_produitProduits,Produit produits) {
    printf("IDProduit=%d | NomProduit=%s | categorie=%s | stock=%d\n quntity_consome=%s", produits.idProduit, produits.nom, produits.categorie, produits.stock,produits.quntite_consome );

}

void trierProduitsParPrix(Produit produits[], int nombre_produit) {
    for(int i=0;i<nombre_produit-1;i++) {
        for(int j=i+1;j<nombre_produit;j++) {
            if(produits[i].prix > produits[j].prix) {
                Produit tmp = produits[i];
                produits[i] = produits[j];
                produits[j] = tmp;
            }
        }
    }
}

void trierProduitsParNom(Produit produits[], int nombre_produit) {
    for(int i=0;i<nombre_produit-1;i++) {
        for(int j=i+1;j<nombre_produit;j++) {
            if(strcmp(produits[i].nom, produits[j].nom) > 0) {
                Produit tmp = produits[i];
                produits[i] = produits[j];
                produits[j] = tmp;
            }
        }
    }
}

void rechercherProduitParNom(Produit produits[], int nombre_produit, char nom[]) {
    int trouve = 0;
    for(int i=0;i<nombre_produit;i++) {
        if(strcmp(produits[i].nom, nom) == 0) {
            afficherProduitDetails(produits[i]);
            trouve = 1;
        }
    }
    if(!trouve) printf("Produit non trouve\n");
}

void rechercherProduitParCategorie(Produit produits[], int nombre_produit, char cat[]) {
    int trouve = 0;
    for(int i=0;i<nombre_produit;i++) {
        if(strcmp(produits[i].categorie, cat) == 0) {
            afficherProduitDetails(produits[i]);
            trouve = 1;
        }
    }
    if(!trouve) printf("Aucun produit trouve\n");
}

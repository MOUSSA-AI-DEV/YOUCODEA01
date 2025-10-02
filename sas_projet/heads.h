#ifndef HEADR_H
#define HEADR_H

#include <stdio.h>
#include <string.h>

#define MAX_NAME 50
#define MAX_EMAIL 200
#define MAX_DESCRIPTION 100
#define MAX_PRODUCTS 100

typedef struct {
    int idClient;
    char nom[MAX_NAME];
    char prenom[MAX_NAME];
    char email[MAX_EMAIL];
    float solde;
} Client;

typedef struct {
    int idProduit;
    char nom[MAX_NAME];
    char categorie[MAX_NAME];
    float prix;
    int stock;
    char description[MAX_DESCRIPTION];
    int quntite_consome;
} Produit;

Client cre_compte();
Client modifie(Client c);
void consulter(Client c);

void consulterSolde(Client c);
Client deposerSolde(Client c, float montant);

void afficherProduits(Produit produits[], int nombre_produit);
void afficherProduitDetails(Produit p);
void trierProduitsParPrix(Produit produits[], int nombre_produit);
void trierProduitsParNom(Produit produits[], int nombre_produit);
void rechercherProduitParNom(Produit produits[], int nombre_produit, char nom[]);
void rechercherProduitParCategorie(Produit produits[], int nombre_produit, char cat[]);

Client Effectuer_Achat(Client c, Produit produits[], int nombre_produit);

void Afficher_s(Client c,Produit produits[],int nombre_produit);

#endif

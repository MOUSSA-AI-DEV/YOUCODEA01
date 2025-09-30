#ifndef H_HEADER
#define H_HEADER

#define  NOMBER_CATEGORIE 5
#define NOMBER_PRODUIT 10
#define SIZE_WORD 30
#define EXIST_STOCK 5
#define EMAIL_SIZE 100
# define TEXT 200
typedef struct 
{
   int id_categorie;
   char nom_categorie[SIZE_WORD]
} CATEGORIE;


typedef struct 
{
    int d;
    int m;
    int y
} date;
struct Produit
{
  int  idProduit;
  char nom[SIZE_WORD];
  CATEGORIE categorie[NOMBER_CATEGORIE];
  int  prix;
  int  stock;
  char description[TEXT]
};

struct Client 

{
   int  idClient ;
   char nom[SIZE_WORD];
   char pernom[SIZE_WORD];
   char email[EMAIL_SIZE];
   int solde
};





#endif
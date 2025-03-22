#include <stdio.h>
#include <stdlib.h>

// Structure pour représenter un livre
typedef struct Livre {
    char titre[100];
    char auteur[100];
    int annee;
    struct Livre* suivant;
    struct Livre* precedent;
} Livre;

// 1. Créer un livre en demandant les informations à l'utilisateur
Livre* creer_livre() {
    Livre* nouveau_livre = (Livre*)malloc(sizeof(Livre));
    printf("Entrez le titre du livre : ");
    scanf("%s", nouveau_livre->titre); 
    printf("Entrez l'auteur : ");
    scanf("%s", nouveau_livre->auteur); 
    printf("Entrez l'année : ");
    scanf("%d", &nouveau_livre->annee);
    nouveau_livre->suivant = NULL;
    nouveau_livre->precedent = NULL;
    return nouveau_livre;
}

// 2. Créer un livre avec des données fournies
Livre* creer_livre_donnees(const char titre[], const char auteur[], int annee) {
    Livre* nouveau_livre = (Livre*)malloc(sizeof(Livre));
    int i = 0;
    while (titre[i] != '\0') {
        nouveau_livre->titre[i] = titre[i];
        i++;
    }
    nouveau_livre->titre[i] = '\0'; 
    i = 0;
    while (auteur[i] != '\0') {
        nouveau_livre->auteur[i] = auteur[i];
        i++;
    }
    nouveau_livre->auteur[i] = '\0'; 

    nouveau_livre->annee = annee;
    nouveau_livre->suivant = NULL;
    nouveau_livre->precedent = NULL;
    return nouveau_livre;
}

// 3. Retourner la longueur de la liste
int longueur_liste(Livre* tete) {
    int longueur = 0;
    Livre* temp = tete;
    while (temp != NULL) {
        longueur++;
        temp = temp->suivant;
    }
    return longueur;
}

// 4. Insérer un livre à une position donnée
Livre* inserer_a_position(Livre* tete, Livre* nouveau_livre, int position) {
    if (position == 1) {
        nouveau_livre->suivant = tete;
        if (tete != NULL) tete->precedent = nouveau_livre;
        return nouveau_livre;
    }

    Livre* temp = tete;
    for (int i = 1; temp != NULL && i < position - 1; i++) {
        temp = temp->suivant;
    }

    if (temp != NULL) {
        nouveau_livre->suivant = temp->suivant;
        if (temp->suivant != NULL) temp->suivant->precedent = nouveau_livre;
        temp->suivant = nouveau_livre;
        nouveau_livre->precedent = temp;
    }
    return tete;
}

// 5. Supprimer un livre à une position donnée
Livre* supprimer_a_position(Livre* tete, int position) {
    if (tete == NULL) return NULL;

    if (position == 1) {
        Livre* nouvelle_tete = tete->suivant;
        if (nouvelle_tete != NULL) nouvelle_tete->precedent = NULL;
        free(tete);
        return nouvelle_tete;
    }

    Livre* temp = tete;
    for (int i = 1; temp != NULL && i < position; i++) {
        temp = temp->suivant;
    }

    if (temp != NULL) {
        if (temp->precedent != NULL) temp->precedent->suivant = temp->suivant;
        if (temp->suivant != NULL) temp->suivant->precedent = temp->precedent;
        free(temp);
    }
    return tete;
}

// 6. Supprimer tous les livres publiés une année donnée
Livre* supprimer_tous_livres_par_annee(Livre* tete, int annee) {
    Livre* courant = tete;
    while (courant != NULL) {
        Livre* suivant = courant->suivant;
        if (courant->annee == annee) {
            if (courant->precedent != NULL) courant->precedent->suivant = courant->suivant;
            if (courant->suivant != NULL) courant->suivant->precedent = courant->precedent;
            if (courant == tete) tete = courant->suivant;
            free(courant);
        }
        courant = suivant;
    }
    return tete;
}

// 7. Afficher la liste dans l'ordre
void afficher_liste_avant(Livre* tete) {
    Livre* temp = tete;
    while (temp != NULL) {
        printf("Titre : %s, Auteur : %s, Année : %d\n", temp->titre, temp->auteur, temp->annee);
        temp = temp->suivant;
    }
}

// 8. Afficher la liste dans l'ordre inverse
void afficher_liste_arriere(Livre* tete) {
    if (tete == NULL) return;
    Livre* temp = tete;
    while (temp->suivant != NULL) temp = temp->suivant; 
    while (temp != NULL) {
        printf("Titre : %s, Auteur : %s, Année : %d\n", temp->titre, temp->auteur, temp->annee);
        temp = temp->precedent;
    }
}

// 9. Rechercher un livre par titre
Livre* rechercher_livre_par_titre(Livre* tete, const char titre[]) {
    Livre* temp = tete;
    while (temp != NULL) {
        int i = 0;
        while (temp->titre[i] != '\0' && titre[i] != '\0' && temp->titre[i] == titre[i]) {
            i++;
        }
        if (temp->titre[i] == '\0' && titre[i] == '\0') return temp; // Les chaînes sont égales
        temp = temp->suivant;
    }
    return NULL;
}

// 10. Vérifier si la liste est un palindrome
int est_liste_palindrome(Livre* tete) {
    if (tete == NULL) return 1;
    Livre* debut = tete;
    Livre* fin = tete;
    while (fin->suivant != NULL) fin = fin->suivant; 

    while (debut != fin && debut->precedent != fin) {
        int i = 0;
        while (debut->titre[i] != '\0' && fin->titre[i] != '\0' && debut->titre[i] == fin->titre[i]) {
            i++;
        }
        if (debut->titre[i] != '\0' || fin->titre[i] != '\0') return 0; // Pas égal
        debut = debut->suivant;
        fin = fin->precedent;
    }
    return 1;
}

// 11. Inverser la liste
Livre* inverser_liste(Livre* tete) {
    Livre* temp = NULL;
    Livre* courant = tete;
    while (courant != NULL) {
        temp = courant->precedent;
        courant->precedent = courant->suivant;
        courant->suivant = temp;
        courant = courant->precedent;
    }
    if (temp != NULL) tete = temp->precedent;
    return tete;
}

// 12. Fusionner deux listes
Livre* fusionner_listes(Livre* liste1, Livre* liste2) {
    if (liste1 == NULL) return liste2;
    Livre* temp = liste1;
    while (temp->suivant != NULL) temp = temp->suivant;
    temp->suivant = liste2;
    if (liste2 != NULL) liste2->precedent = temp;
    return liste1;
}

// 13. Insérer dans une liste triée (année croissante)
Livre* inserer_trie(Livre* tete, Livre* nouveau_livre) {
    if (tete == NULL || nouveau_livre->annee < tete->annee) {
        nouveau_livre->suivant = tete;
        if (tete != NULL) tete->precedent = nouveau_livre;
        return nouveau_livre;
    }

    Livre* temp = tete;
    while (temp->suivant != NULL && temp->suivant->annee < nouveau_livre->annee) {
        temp = temp->suivant;
    }

    nouveau_livre->suivant = temp->suivant;
    if (temp->suivant != NULL) temp->suivant->precedent = nouveau_livre;
    temp->suivant = nouveau_livre;
    nouveau_livre->precedent = temp;
    return tete;
}

// 14. Supprimer les doublons (même titre et auteur)
void supprimer_doublons(Livre* tete) {
    Livre* courant = tete;
    while (courant != NULL) {
        Livre* coureur = courant->suivant;
        while (coureur != NULL) {
            Livre* suivant = coureur->suivant;
            int titre_match = 1;
            int auteur_match = 1;
            int i = 0;
            while (courant->titre[i] != '\0' && coureur->titre[i] != '\0' && courant->titre[i] == coureur->titre[i]) {
                i++;
            }
            if (courant->titre[i] != '\0' || coureur->titre[i] != '\0') titre_match = 0;

            i = 0;
            while (courant->auteur[i] != '\0' && coureur->auteur[i] != '\0' && courant->auteur[i] == coureur->auteur[i]) {
                i++;
            }
            if (courant->auteur[i] != '\0' || coureur->auteur[i] != '\0') auteur_match = 0;

            if (titre_match && auteur_match) {
                if (coureur->precedent != NULL) coureur->precedent->suivant = coureur->suivant;
                if (coureur->suivant != NULL) coureur->suivant->precedent = coureur->precedent;
                free(coureur);
            }
            coureur = suivant;
        }
        courant = courant->suivant;
    }
}

// Fonction principale
int main() {
    Livre* bibliotheque = NULL;
    Livre* livre1 = creer_livre_donnees("LivreA", "AuteurX", 2000);
    Livre* livre2 = creer_livre_donnees("LivreB", "AuteurY", 2010);
    bibliotheque = inserer_trie(bibliotheque, livre1);
    bibliotheque = inserer_trie(bibliotheque, livre2);

    printf("Livres dans l'ordre :\n");
    afficher_liste_avant(bibliotheque);

    printf("\nLivres dans l'ordre inverse :\n");
    afficher_liste_arriere(bibliotheque);

    return 0;
}
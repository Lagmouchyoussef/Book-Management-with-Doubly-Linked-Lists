#include <stdio.h>
#include <stdlib.h>

typedef struct Livre {
    char titre[100];
    char auteur[100];
    int annee;
    struct Livre* suivant;
    struct Livre* precedent;
} Livre;
// Fonction pour créer un nouveau livre
Livre* creer_livre() {
    Livre* nouveau_livre = (Livre*)malloc(sizeof(Livre));
    printf("entrez le titre du livre : ");
    fgets(nouveau_livre->titre, 100, stdin); 
    printf("entrez l auteur : ");
    fgets(nouveau_livre->auteur, 100, stdin);
    printf("entrez l annee : ");
    fgets(nouveau_livre->annee, 100, stdin);
    nouveau_livre->suivant = NULL;
    nouveau_livre->precedent = NULL;
    return nouveau_livre;
}
// Fonction pour créer un nouveau livre avec des données spécifiques
Livre* creer_livre_donnees(const char titre[], const char auteur[], int annee) {
    Livre* nouveau_livre = (Livre*)malloc(sizeof(Livre));
  if (nouveau_livre == NULL) {
    return NULL;
  }
    strcpy(nouveau_livre->titre, titre);
    strcpy(nouveau_livre->auteur, auteur);
    nouveau_livre->annee = annee;
    nouveau_livre->suivant = NULL;
    nouveau_livre->precedent = NULL;
    return nouveau_livre;
}
// Fonction pour libérer la mémoire d'un livre
int longueur_liste(Livre* tete) {
    int longueur = 0;
    Livre* courant = tete;
    while (courant != NULL) {
        longueur++;
        courant = courant->suivant;
    }
    return longueur;
}
// Fonction pour libérer la mémoire d'une liste de livres
Livre* inserer_a_position(Livre* tete, Livre* nouveau_livre, int position) {
    if (position < 0) {
        return tete;
    }
    if (position == 0) {
        nouveau_livre->suivant = tete;
        if (tete != NULL) {
            tete->precedent = nouveau_livre;
        }
        return nouveau_livre;
    }
    Livre* courant = tete;
    int i = 0;
    while (i < position - 1 && courant != NULL) {
        courant = courant->suivant;
        i++;
    }
    if (courant == NULL) {
        return tete;
    }
    nouveau_livre->suivant = courant->suivant;
    if (courant->suivant != NULL) {
        courant->suivant->precedent = nouveau_livre;
    }
    courant->suivant = nouveau_livre;
    nouveau_livre->precedent = courant;
    return tete;
}
// Fonction pour supprimer un livre à une position donnée
Livre* supprimer_a_position(Livre* tete, int position) {
    if (position < 0) {
        return tete;
    }
    if (position == 0) {
        Livre* suivant = tete->suivant;
        free(tete);
        if (suivant != NULL) {
            suivant->precedent = NULL;
        }
        return suivant;
    }
    Livre* courant = tete;
    int i = 0;
    while (i < position - 1 && courant != NULL) {
        courant = courant->suivant;
        i++;
    }
    if (courant == NULL || courant->suivant == NULL) {
        return tete;
    }
    Livre* a_supprimer = courant->suivant;
    courant->suivant = a_supprimer->suivant;
    if (a_supprimer->suivant != NULL) {
        a_supprimer->suivant->precedent = courant;
    }
    free(a_supprimer);
    return tete;
}
// Fonction pour supprimer tous les livres d'une année donnée
Livre* supprimer_tous_livres_par_annee(Livre* tete, int annee) {
    Livre* courant = tete;
    while (courant != NULL) {
        if (courant->annee == annee) {
            Livre* a_supprimer = courant;
            if (courant->precedent != NULL) {
                courant->precedent->suivant = courant->suivant;
            }
            if (courant->suivant != NULL) {
                courant->suivant->precedent = courant->precedent;
            }
            courant = courant->suivant;
            free(a_supprimer);
        } else {
            courant = courant->suivant;
        }
    }
    return tete;
}
// Fonction pour afficher la liste des livres dans l'ordre avant
void afficher_liste_avant(Livre* tete) {
    Livre* courant = tete;
    while (courant != NULL) {
        printf("%s, %s, %d\n", courant->titre, courant->auteur, courant->annee);
        courant = courant->suivant;
    }
}
// Fonction pour afficher la liste des livres dans l'ordre arrière
void afficher_liste_arriere(Livre* tete) {
    Livre* courant = tete;
    while (courant != NULL) {
        courant = courant->suivant;
    }
    while (courant != NULL) {
        printf("%s, %s, %d\n", courant->titre, courant->auteur, courant->annee);
        courant = courant->precedent;
    }
}
// Fonction pour rechercher un livre par titre
Livre* rechercher_livre_par_titre(Livre* tete, char titre[]) {
    Livre* courant = tete;
    while (courant != NULL) {
        if (strcmp(courant->titre, titre) == 0) {
            return courant;
        }
        courant = courant->suivant;
    }
    return NULL;
}
// Fonction pour vérifier si la liste est un palindrome
int est_liste_palindrome(Livre* tete) { 
    Livre* debut = tete;
    Livre* fin = tete;
    while (debut->suivant != NULL) {
        debut = debut->suivant;
    }
    while (debut != fin && debut->precedent != fin) {
        if (strcmp(debut->titre, fin->titre) != 0) {
        }
        debut = debut->suivant;
        fin = fin->precedent;
    }
    return tete;
}
// Fonction pour inverser la liste
Livre* inverser_liste(Livre* tete) {
    Livre* courant = tete;
    Livre* precedent = NULL;
    while (courant != NULL) {
        Livre* suivant = courant->suivant;
        courant->suivant = precedent;
        courant->precedent = suivant;
        precedent = courant;
        courant = suivant;
    }
    return precedent;
}
// Fonction pour fusionner deux listes
Livre* fusionner_listes(Livre* liste1, Livre* liste2) {
    if (liste1 == NULL) {
        return liste2;
    }
    if (liste2 == NULL) {
        return liste1;
    }
    Livre* tete = liste1;
    Livre* courant = liste1;
    while (courant->suivant != NULL) {
        courant = courant->suivant;
    }
    courant->suivant = liste2;
    liste2->precedent = courant;
    return tete;
}
// Fonction pour trier la liste par titre
Livre* inserer_trie(Livre* tete, Livre* nouveau_livre) {
    if (tete == NULL || strcmp(nouveau_livre->titre, tete->titre) < 0) {
        nouveau_livre->suivant = tete;
        if (tete != NULL) {
            tete->precedent = nouveau_livre;
        }
        return nouveau_livre;
    }
    Livre* courant = tete;
    while (courant->suivant != NULL && strcmp(nouveau_livre->titre, courant->suivant->titre) > 0) {
        courant = courant->suivant;
    }
    nouveau_livre->suivant = courant->suivant;
    if (courant->suivant != NULL) {
        courant->suivant->precedent = nouveau_livre;
    }
    courant->suivant = nouveau_livre;
    nouveau_livre->precedent = courant;
    return tete;
}
// Fonction pour supprimer les doublons dans la liste
void supprimer_doublons(Livre* tete) {
    Livre* courant = tete;
    while (courant != NULL) {
        Livre* suivant = courant->suivant;
        while (suivant != NULL) {
            if (strcmp(courant->titre, suivant->titre) == 0) {
                Livre* a_supprimer = suivant;
                courant->suivant = suivant->suivant;
                if (suivant->suivant != NULL) {
                    suivant->suivant->precedent = courant;
                }
                free(a_supprimer);
            } else {
                suivant = suivant->suivant;
            }
        }
        courant = courant->suivant;
    }
}
// Fonction principale
int main() {
    Livre* tete = NULL;
    int choix;

    do {
        printf("Menu de gestion des livres :\n");
        printf("1. Ajouter un livre\n");
        printf("2. Afficher la liste des livres (avant)\n");
        printf("3. Afficher la liste des livres (arrière)\n");
        printf("4. Supprimer un livre par position\n");
        printf("5. Supprimer tous les livres d'une année donnée\n");
        printf("6. Rechercher un livre par titre\n");
        printf("7. Supprimer les doublons\n");
        printf("8. Quitter\n");
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
        getchar(); 

        switch (choix) {
            case 1: {
                char titre[100], auteur[100];
                int annee;
                printf("Entrez le titre : ");
                fgets(titre, 100, stdin);
                titre[strcspn(titre, "\n")] = '\0'; 
                printf("Entrez l'auteur : ");
                fgets(auteur, 100, stdin);
                auteur[strcspn(auteur, "\n")] = '\0'; // '
                printf("Entrez l'année : ");
                scanf("%d", &annee);
                getchar(); 
                Livre* nouveau_livre = creer_livre_donnees(titre, auteur, annee);
                tete = inserer_trie(tete, nouveau_livre);
                break;
            }
            case 2:
                printf("Liste des livres (avant) :\n");
                afficher_liste_avant(tete);
                break;
            case 3:
                printf("Liste des livres (arriere) :\n");
                afficher_liste_arriere(tete);
                break;
            case 4: {
                int position;
                printf("Entrez la position a supprimer : ");
                scanf("%d", &position);
                getchar(); 
                tete = supprimer_a_position(tete, position);
                break;
            }
            case 5: {
                int annee;
                printf("Entrez l annee a supprimer : ");
                scanf("%d", &annee);
                getchar(); 
                tete = supprimer_tous_livres_par_annee(tete, annee);
                break;
            }
            case 6: {
                char titre[100];
                printf("Entrez le titre à rechercher : ");
                fgets(titre, 100, stdin);
                titre[strcspn(titre, "\n")] = '\0'; 
                Livre* resultat = rechercher_livre_par_titre(tete, titre);
                if (resultat != NULL) {
                    printf("Livre trouvé : %s, %s, %d\n", resultat->titre, resultat->auteur, resultat->annee);
                } else {
                    printf("Livre non trouvé.\n");
                }
                break;
            }
            case 7:
                supprimer_doublons(tete);
                printf("Doublons supprimes.\n");
                break;
            case 8:
                printf("Au revoir !\n");
                break;
            default:
                printf("Choix invalide. Veuillez reessayer.\n");
        }
    } while (choix != 8);

    while (tete != NULL) {
        tete = supprimer_a_position(tete, 0);
    }

    return 0;
}
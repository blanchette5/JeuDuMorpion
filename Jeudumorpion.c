#include <stdio.h>
// AUGER LOICK
// CARPENTIER LUDIVINE
// L2 INFO

 // Voici le code du jeu le morpion 3 par 3, pour l'executer telecharger le main
char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//Ensemble des caractères initialiser


int main()
{
    int joueur = 1;
    int i;
    int choix;
     // Voici le code du jeu le morpion 3 par 3, pour l'executer telecharger le main

int gagne();
//Fonction gagne permet de savoir si la partie a été remporter par un joueur ou a fini en match nul



//Boucle plateau permettant le placement du choix saisie par l'utilisateur.
void plateau();

    char implanter; //Caractère a implanter sur le plateau
    do
    {
        plateau();
        joueur = (joueur % 2) ? 1 : 2; // Tours des joueur

        printf("Joueur %d, entrez un chiffre:  ", joueur); // Affiche le numéro décidez au dessus pour savoir qui commence
        scanf("%d", &choix); // Scan le choix ( numéro entre 1 et 9)
        implanter = (joueur == 1) ? 'x' : 'o'; // Symbole qui vont être utiliser dans l'affichage
        if (choix == 1 && square[1] == '1') // Si le choix est égale a 1 ainsi que la case 1, alors la case une prend la valeur implanter soit x ou o;
            square[1] = implanter;
        else if (choix == 2 && square[2] == '2')
            square[2] = implanter;
        else if (choix == 3 && square[3] == '3')
            square[3] = implanter;
        else if (choix == 4 && square[4] == '4')
            square[4] = implanter;
        else if (choix == 5 && square[5] == '5')
            square[5] = implanter;
        else if (choix == 6 && square[6] == '6')
            square[6] = implanter;
        else if (choix == 7 && square[7] == '7')
            square[7] = implanter;
        else if (choix == 8 && square[8] == '8')
            square[8] = implanter;
        else if (choix == 9 && square[9] == '9')
            square[9] = implanter;
        else //Sinon
        {
            joueur--; //Demande de rejoué au joueur 1

        }
        i = gagne(); // I nous sert d'indice : il prend la valeur de la fonction gagne
        joueur++;// Joueur suivant
    }while (i ==  - 1);// Tant que i = -1
    plateau();  // On rentre dans notre boucle plateau
    if (i == 1) // Si il est égale a 1 alors
        printf("==>\aJoueur %d win ", --joueur);// le joueur qui a jouer le dernier tour est affiché vainqueur.
    else
        printf("==>\aPartie nul"); // Sinon partie nul
    return 0;
}


//1 si la partie est remporter par l'un des deux joueurs.
//O si il y match nul entre les deux joueurs.

//fonction de vérification qui gagne

int gagne()
{
    if (square[1] == square[2] && square[2] == square[3]) //Premier alignement  1 2 3
        return 1; // Retourne 1 si les mêmes symbole sont sur les cases 1,2 et 3
    else if (square[4] == square[5] && square[5] == square[6])
        return 1;
    else if (square[7] == square[8] && square[8] == square[9])
        return 1;
    else if (square[1] == square[4] && square[4] == square[7])
        return 1;
    else if (square[2] == square[5] && square[5] == square[8])
        return 1;
    else if (square[3] == square[6] && square[6] == square[9])
        return 1;
    else if (square[1] == square[5] && square[5] == square[9])
        return 1;
    else if (square[3] == square[5] && square[5] == square[7])
        return 1;
    else if (square[1] != '1' && square[2] != '2' && square[3] != '3' &&
        square[4] != '4' && square[5] != '5' && square[6] != '6' && square[7]
        != '7' && square[8] != '8' && square[9] != '9')

        return 0; // Si il y match nul entre les deux joueurs.
    else
        return  - 1;
}


// Boucle qui permet d'afficher visuellement le morpion

void plateau()
{
    system("cls");//Sert a effacer l'affichage de saisie incorrect
    printf("\n\n\tLe Morpion\n\n");
    printf("Joueur 1 (X)  -  Joueur 2 (O)\n\n\n"); // Savoir a qui appartient les symboles
    printf("     *     *     \n");
    printf("  %c  *  %c  *  %c \n", square[1], square[2], square[3]); // Chaque case représenter dans l'ordre, utilisation de %c pour lire un seul caractère.
    printf("*****************\n");
    printf("     *     *     \n");
    printf("  %c  *  %c  *  %c \n", square[4], square[5], square[6]);// Chaque case représenter dans l'ordre
    printf("*****************\n");
    printf("     *     *     \n");
    printf("  %c  *  %c  *  %c \n", square[7], square[8], square[9]);// Chaque case représenter dans l'ordre
    printf("     *     *     \n\n");
}

#include <stdio.h>
#include <conio.h>

char square[10] = { 'o', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
//Ensemble des caractères initialiser

int gagne();
//Fonction gagne permet de savoir si la partie a été remporter par un joueur ou a fini en match nul



//Boucle plateau permettant le placement du choix saisie par l'utilisateur.
void plateau();
int main()
{
    int joueur = 1, i, choix;

    char implanter;
    do
    {
        plateau();
        joueur = (joueur % 2) ? 1 : 2;

        printf("Joueur %d, entrez un chiffre:  ", joueur);
        scanf("%d", &choix);

        implanter = (joueur == 1) ? 'X' : 'O';

        if (choix == 1 && square[1] == '1')
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

        else
        {
            printf("Saisie incorrect ");

            joueur--;
            getch();
        }





        i = gagne();

        joueur++;
    }while (i ==  - 1);

    plateau();

    if (i == 1)
        printf("==>\aJoueur %d win ", --joueur);
    else
        printf("==>\aPartie nul");

    getch();

    return 0;
}


//1 si la partie est remporter par l'un des deux joueurs.
//-1 est l'état du jeu en progression.
//O si il y match nul entre les deux joueurs.


int gagne()
{
    if (square[1] == square[2] && square[2] == square[3])
        return 1;

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

        return 0;
    else
        return  - 1;
}


// Fonction qui permet d'afficher visuellement le morpion

void plateau()
{
    system("cls");//Sert a effacer par exemple la saisie incorrect
    printf("\n\n\tLe Morpion\n\n");

    printf("Joueur 1 (X)  -  Joueur 2 (O)\n\n\n");


    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c \n", square[1], square[2], square[3]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[4], square[5], square[6]);

    printf("_____|_____|_____\n");
    printf("     |     |     \n");

    printf("  %c  |  %c  |  %c \n", square[7], square[8], square[9]);

    printf("     |     |     \n\n");
}

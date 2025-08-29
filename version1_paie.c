#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Définition de la structure Employe
typedef struct {
    char nom[50];
    float heuresTravaillees;
    float tauxHoraire;
    float salaireBrut;
    float deductions;
    float salaireNet;
    char categorie[20];  // Catégorie : Temps plein ou Temps partiel
} Employe;

// Fonction pour vider le tampon d'entrée
void viderTampon() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Fonction pour ajouter un employé
void addEmployee(Employe *employe) {
    printf("Nom: ");
    scanf("%s", employe->nom);
    viderTampon();

    printf("Heures travaillées: ");
    scanf("%f", &employe->heuresTravaillees);
    viderTampon();

    printf("Taux horaire: ");
    scanf("%f", &employe->tauxHoraire);
    viderTampon();

    printf("Catégorie (Temps plein/Temps partiel): ");
    fgets(employe->categorie, sizeof(employe->categorie), stdin);
    employe->categorie[strcspn(employe->categorie, "\n")] = '\0';

    employe->salaireBrut = 0;
    employe->deductions = 0;
    employe->salaireNet = 0;
}

// Fonction pour calculer les salaires
void calculatePayroll(Employe *employe) {
    employe->salaireBrut = employe->heuresTravaillees * employe->tauxHoraire;
    employe->deductions = employe->salaireBrut * 0.10; // 10% d'impôts
    employe->salaireNet = employe->salaireBrut - employe->deductions;
}

// Fonction pour afficher les fiches de paie
void displayPayslip(Employe employe) {
    printf("Nom: %s\n", employe.nom);
    printf("Catégorie: %s\n", employe.categorie);
    printf("Salaire Brut: %.2f\n", employe.salaireBrut);
    printf("Déductions: %.2f\n", employe.deductions);
    printf("Salaire Net: %.2f\n", employe.salaireNet);
    printf("------------------------\n");
}

// Fonction principale avec le menu
int main() {
    Employe listeEmployes[100];
    int choix, nombreEmployes = 0;

    while (1) {
        printf("Menu:\n1. Ajouter un employé\n2. Calculer les salaires\n3. Afficher les fiches de paie\n4. Quitter\n");
        printf("Choix: ");
        scanf("%d", &choix);
        viderTampon();

        if (choix == 4) {
            break;
        }

        switch (choix) {
            case 1:
                addEmployee(&listeEmployes[nombreEmployes]);
                nombreEmployes++;
                break;
            case 2:
                for (int i = 0; i < nombreEmployes; i++) {
                    calculatePayroll(&listeEmployes[i]);
                }
                break;
            case 3:
                for (int i = 0; i < nombreEmployes; i++) {
                    displayPayslip(listeEmployes[i]);
                }
                break;
            default:
                printf("Choix invalide.\n");
        }
    }
    return 0;
}
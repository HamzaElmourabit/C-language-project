# Projet : Système de Gestion de Paie

Ce projet regroupe trois implémentations différentes d'un système de gestion de paie :

## Version 1 (C pur - traitement en mémoire)
- Gestion des employés dans un tableau statique.
- Calcul du salaire brut, déductions (10%) et salaire net.
- Affichage des fiches de paie via la console.

## Version 2 (C + SQLite)
- Création d'une base SQLite `gestion_paie.db`.
- Table `Employes` stockant les informations principales.
- Extension possible pour insérer, calculer et afficher les paies via SQL.

## Version 3 (Interface Web - HTML, CSS, JavaScript)
- Formulaire pour ajouter des employés.
- Calcul automatique des salaires côté client.
- Affichage des employés et fiches de paie sous forme de tableau dynamique.

## Utilisation
- Compiler la version C avec `gcc version1_paie.c -o version1_paie`.
- Compiler la version SQLite avec `gcc version2_sqlite.c -lsqlite3 -o version2_sqlite`.
- Ouvrir `index.html` dans un navigateur pour la version web.

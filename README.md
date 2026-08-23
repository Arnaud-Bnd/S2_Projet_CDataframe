# Projet CDataframe

Implémentation en langage C d'une structure de données inspirée du **DataFrame** de la librairie Python **Pandas**, 
réalisée dans le cadre du cours *Algorithmique et Structures de Données 1* à l'EFREI (2ᵉ semestre).

L'objectif : proposer, en C pur, une structure tabulaire organisée en colonnes (titre + données), avec les opérations de 
base qu'on attend d'un tableur ou d'un DataFrame — création, saisie, affichage, recherche, tri, statistiques, 
import/export CSV.

## Fonctionnalités

Le programme s'utilise via un menu interactif en console qui permet de :

**Alimentation**
- Créer un CDataframe vide ou pré-rempli (`hardFilling`)
- Remplir le CDataframe via saisie utilisateur
- Charger des données depuis un fichier CSV

**Affichage**
- Afficher le CDataframe entier
- Afficher une plage de lignes ou de colonnes
- Afficher les noms des colonnes

**Opérations sur les données**
- Ajouter / supprimer une ligne
- Ajouter / supprimer / renommer une colonne
- Accéder ou remplacer une cellule via ses indices (ligne, colonne)
- Rechercher une valeur dans le CDataframe

**Analyse & statistiques**
- Nombre de lignes / de colonnes
- Nombre de cellules égales à / supérieures à / inférieures à une valeur donnée

**Tri & recherche avancée**
- Trier une colonne (croissant / décroissant) sans déplacer les données, grâce à un **tableau d'index**
- Afficher une colonne selon son index trié
- Recherche dichotomique dans une colonne triée
- Gestion de la validité de l'index (`checkIndex`, `updateIndex`, `eraseIndex`)

**Fichiers**
- Import / export au format CSV

## Structure du projet

```text
.
├── include/            # Fichiers d'en-tête (.h)
│ ├── cdataframe.h      # API du CDataframe
│ ├── column.h          # API des colonnes
│ ├── SortType.h        # Types/constantes de tri
│ ├── features.h        # Fonctions du menu / CSV
│ └── Errors.h          # Gestion des erreurs (macros de vérification de pointeurs)
├── src/                # Implémentation (.c)
│ ├── cdataframe.c
│ ├── column.c
│ ├── features.c
│ ├── Errors.c
│ └── main.c            # Point d'entrée + menu interactif
├── CMakeLists.txt
├── Dockerfile
└── data.csv            # Jeu de données d'exemple
```


### Modèle de données

Un **CDataframe** est un tableau dynamique de pointeurs vers des **colonnes**. Chaque colonne possède :

- un titre,
- un tableau de données de type `int`,
- une taille physique (capacité allouée, réallouée par blocs de 256) et une taille logique (nombre de valeurs réellement 
insérées),
- un tableau d'**index** utilisé pour trier la colonne sans déplacer les données, avec un attribut de validité 
(`mValidIndex`) permettant de savoir si l'index est à jour, invalidé partiellement (après une insertion) ou totalement.

## Compilation

### Avec CMake

```bash
mkdir build && cd build
cmake ..
cmake --build .
./Projet_CDataframe
```

### Avec Docker

```bash
docker build -t cdataframe .
docker run --rm -it cdataframe
```

## Utilisation

Au lancement, le programme affiche un menu numéroté dans le terminal. Il suffit de saisir le numéro de l'action 
souhaitée puis de suivre les instructions à l'écran (nom de colonne, valeurs, bornes de lignes, etc.).

Le programme lit et écrit les fichiers CSV (`data.csv`, `data2.csv`, `CDataFrame.csv`) dans le **répertoire courant 
d'exécution**. Le plus simple est donc de lancer l'exécutable depuis la racine du projet (là où se trouve `data.csv`) :

```bash
# depuis la racine du dépôt, après compilation
./build/Projet_CDataframe
```

Si tu compiles dans un sous-dossier (ex. `build/`), pense à copier `data.csv` à côté de l'exécutable, ou à lancer le 
programme depuis la racine comme ci-dessus.

## Contexte pédagogique

Ce projet a été réalisé en binôme dans le cadre du cours d'Algorithmique et Structures de Données à l'EFREI (Mars-Mai 
2024), en trois parties :

1. **Partie 1** — CDataframe d'entiers, opérations de base
2. **Partie 2** — Ajout d'un système d'index pour un tri efficace (Quicksort / tri par insertion selon l'état de la 
colonne) et recherche dichotomique
3. **Partie 3** *(fonctionnalités avancées)* — Import/export CSV

## Pistes d'amélioration

- Généraliser la colonne à des types génériques (`union`), pour stocker autre chose que des entiers
- Ajouter des tests unitaires
- Vérifier systématiquement les retours de `malloc`/`realloc`

## Auteur

**Arnaud BERNARD** — EFREI Paris, Data Engineering

**Sami BENABDALLAH** — EFREI Paris

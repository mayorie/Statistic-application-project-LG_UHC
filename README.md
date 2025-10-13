# LGSTATS_projet_v1

Récupération des logs de minecraft vanilla. Pour récupérer le chat et les déconnexion du joueur.
Pour analyser des parties du mode de jeu LG UHC sur le serveur UHCWORLD.

## Organistaion du code : 

### Création de la base de donnée : 

Permet de créer, modifier et ajouter des données dans la base de donnée de l'extérieur, de manière sécurisé.

### Recup des données brut : 

Créé un fichier ifstream pour naviguer dans le fichier de log choisit.

### Traitement : 

#### Main traitement : 

Trouve sur quels mode de jeu on joue.

#### init traitement LGUHC : 

Regarde le rôle du joueur et ses information jusqu'à 45mins de jeu.

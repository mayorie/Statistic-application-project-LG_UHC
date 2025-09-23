# Mise en place du compilateur de Visual Studio sous vscode

Visual Studio doit etre installe sur la machine

# Ajout d'extensions vscode

- C/C++ Extension Pack
- Git Graph

## ajout du teminal de developpement dans vscode

Voir le fichier .vscode/settings.json

## creation d'un fichier de configurationpour Cmake

Voir le fichier CMakeLists.txt

## generation des fichiers projet

Taper, dans le terminal de developpement:
```
cmake -G "Visual Studio 17 2022" .
```

## compilation

```
msbuild StatisticApplication.sln /p:Configuration=Debug /p:Platform=x64
```

## generation et compilation

```
setup_build_env.bat
```

## utilisation de git

### installation de git

- Telecharger Git for Windows depuis https://git-scm.com/
- Suivre les instrctions d'installation

### cloner le repo github sur son PC

- Aller sur le repo github https://github.com/mayorie/Statistic-application-project-LG_UHC
- Cliquer sur le bouton "code"
- Choisir Clone : https
- Copier l'url du repo: https://github.com/mayorie/Statistic-application-project-LG_UHC
- ouvrir un terminal dans le dossier ou on veut installer la copie locale du repo
- Taper "git clone https://github.com/mayorie/Statistic-application-project-LG_UHC"
- ouvrir vscode dans ce dossier

### faire une modification en local et la pousser sur github

- Cliquer sur l'icone en forme d'arbre
- La liste de fichiers modifies depuis le dernier commit est sous "Changes"
- Pour ajouter les  modifications au prochain commit, cliquer sur le "+" a droite du nom de fichier
- Le fichier apparait maintenant dans la "Staged Changes"
- faire la meme chose pour tous les fichier qu'on veut ajouter au prochain commit
- Pour committer, il faut mettre un message de commit dans la zone de texte "Message", puis cliquer sur  le bouton "Commit"
- Pour pousser le commit sur le github, cliquer sur le bouton "Sync Changes"
- On peut aussi faire "Commit & Push" (dans la liste deroulante du bouton "Commit") pour faire les 2 d'un coup
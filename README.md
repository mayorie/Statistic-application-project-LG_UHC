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
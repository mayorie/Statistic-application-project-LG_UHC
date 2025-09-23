# CMakeLists.txt
cmake_minimum_required(VERSION 3.10)
project(StatisticApplication)

set(SOURCES
    main.cpp
    recup_donnee_brut.cpp
    banque_donnee_traite.cpp
    doc_regex.cpp
    traitement_donnees.cpp
)

add_executable(StatisticApplication ${SOURCES})
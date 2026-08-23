cmake_minimum_required(VERSION 3.25)
project(Projet_CDataframe C)

# Standards de langages
set(CMAKE_C_STANDARD 17)
#set(CMAKE_CXX_STANDARD 17)

# S'assurer que les standards sont requis
set(CMAKE_C_STANDARD_REQUIRED ON)
#set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Extensions des compilateurs (optionnel, peut être désactivé)
set(CMAKE_C_EXTENSIONS OFF)
#set(CMAKE_CXX_EXTENSIONS OFF)

# --- Configuration Doxygen ---
find_package(Doxygen)

if (DOXYGEN_FOUND)
    # Configurer le Doxyfile à partir du modèle
    configure_file(Doxyfile.in Doxyfile @ONLY)

    # Créer la cible de documentation
    add_custom_target(doc
        COMMAND ${DOXYGEN_EXECUTABLE} Doxyfile
        WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
        COMMENT "Génération de la documentation avec Doxygen"
    )

    # Rendre la documentation dépendante de la compilation (optionnel)
    # add_dependencies(my_app doc)
endif()

# Exécutable principal
add_executable(Projet_CDataframe
        include/Errors.h
        src/Errors.c
        include/SortType.h
        src/main.c
        src/column.c
        include/column.h
        include/cdataframe.h
        src/cdataframe.c
        include/features.h
        src/features.c
)

# Si tu veux forcer la compilation en C++ même pour les fichiers .c
# set_source_files_properties(main.c column.c cdataframe.c features.c 
#                              PROPERTIES LANGUAGE CXX)

# Options de compilation recommandées
if(CMAKE_C_COMPILER_ID STREQUAL "GNU" OR CMAKE_C_COMPILER_ID STREQUAL "Clang")
    target_compile_options(Projet_CDataframe PRIVATE -Wall -Wextra -Werror -O3)
    #target_compile_options(Projet_CDataframe PRIVATE -Wall -Wextra -O3)
endif()

# Définir des macros pour la compatibilité C/C++
#target_compile_definitions(Projet_CDataframe PRIVATE
#    $<$<COMPILE_LANGUAGE:CXX>:__cplusplus>
#)

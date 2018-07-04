/** \mainpage Module image


\section intro Introduction :

Voici la documentation pour le jeu Clone Wars développé par Vincent BORNE, Thibault Dumeni et Adrien Perrier. <br>
Ce jeu a été codé en C++ et compile avec g++. Petit projet avec une quinzaine de classes.

\section rule Règle du jeu :
C'est un jeu de stratégie en temps réel en 2D où le but est de détruire son adversaire en créant des unités. Il reprend la même idée d'un jeu flash très célèbre "Age of Wars". Vous devez donc acheter des unités pour combattre l'ennemi.

\section compil Pour compiler :
Tester sous Linux (Ubuntu).

Dépendances :
 - SDL2 : http://www.libsdl.org/
 - SDL2 Mixer
 - SDL2 Image
 - SDL2 Ttf

$ make all ou make

Pour supprimer les .o :
$ make clean



\section exec Pour executer :

Les trois exécutables :
	- le programme de testRegression => $ bin/testCloneWars
	- le programme en version texte => $ bin/CloneWarsText
	- le programme en version SDL :
        => $ bin/CloneWars
        => Il se peut qu'il y est un bug durant l'éxécution du jeu alors lancer :
            - $ LIBGL_ALWAYS_SOFTWARE=1 bin/CloneWars



\section doc Pour générer la documentation de code

Dépendance : doxygen http://www.stack.nl/~dimitri/doxygen/
$ cd doc <br>
$ doxygen image.doxy <br>
Puis ouvrir doc/html/index.html

*/

# DOOM-NUKEM

A simple raycasting game renderer and game editor.

## Features :

* HUD (Stickman sprites PJ movements, Energy bar, minimap)
* Display sprites, multi-sprites and door animations.
* Camera controls with mouse

## Download format :

```git clone https://github.com/bede-fre/Doom-nukem.git```

## Compilation :

Enter in the dowloaded folder ```cd Doom-nukem/``` and compile two executables with command ```make``` after that run the editor with or without a map argument ```./editor map``` or you can run the game with a map argument ```./doom-nukem map```

## Commands :

- W : Move forward
- S : Move backward
- D : Right strafe
- A : Left strafe
- Q : Camera left rotation
- E : Camera right rotation
- F : Open doors
- X : Active/desactivate jetpack (if you have it on your inventory)
- Left shift : run (until you have no more energy)
- Left ctrl : crunch
- F : Down height
- SPACE : Reset initial position
- ESC : Quit program

## Screenshots :

![screenshot](/screens/screen.png?raw=true)

![screenshot](/screens/screen2.png?raw=true)


## Utilisation:

### doom-nukem

* 'w' / 'a' / 's' / 'd' = deplacement

* 'q' / 'e' / mouvement de souris = rotation camera

* 'f' = ouvrir les portes

* 'x' = activer / desactiver le jetpack (apres ramassage de celui-ci)

* 'space' = sauter / voler (jetpack)

* 'left ctrl = s'accroupir

* 'left shift' = courrir

* 'h' = activer / desactiver le fisheye

* 'm' = activer / desactiver le son

* 'l' = exectuer leaks

* 'left clic' = afficher la distance du mur pointe

* 'esc' = quitter

### editor

* 'enter' = generer la map

* 'm' = activer / desactiver le son

* 'l' = executer leaks

* 'esc' = quitter

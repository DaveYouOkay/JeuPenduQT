# JeuPenduQT
## Jeu du Pendu sur QT Creator 5.0.2 avec Interface Graphique 

<p>
Tous les programmes demandés sont à réaliser sous Qt (sous Linux).
  
### 1. Exercice: Jeu du pendu :
  
Principe général du jeu : Un mot à deviner est choisi au hasard. Le joueur, après avoir saisi sor nom, a 10 essais maximum, pour retrouver ce mot en proposant des lettres. A la 11eme erreur, le joueur a perdu, et le mot s'affiche. 
</p>

<p>
  
### 2. Fichier de mots :
  
Le mot à deviner est choisi au hasard dans un fichier texte. Le fichier par défaut se nomme : "liste_mots_sans_accents.txt"
L'utilisateur doit pouvoir changer ce fichier et ce changement doit rester valable à la prochaine utilisation du jeu.
Un fichier de configuration nommé "config.txt" va être utilisé. Ce fichier doit contenir uniquement (pour simplifier) le nom du fichier contenant la liste des mots disponibles.
</p>

<p>
  
### 3. Contraintes techniques :
  
Pour programmer ce jeu, 2 classes doivent être utilisées. Elles devront être reliées dans une relation d'association.
Un diagramme de classes est donné à titre indicatif :
  
  ///Image classe
  
  Dans ce cas, au début, les 2 classes ne se connaissent pas. 
  C'est donc au programme principal de créer 1 objet de chaque classe et d'appeler les méthodes RecupAdd... de façon à ce que les classes puissent utiliser les méthodes de l'autre classe  
</p>

<p>

  ### 4. Capture d'écran :

</p>

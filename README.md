# Minishell

Minishell est une implémentation simplifiée d'un shell UNIX, développé en C dans le cadre du projet Epitech. Il gère les commandes de base ainsi que plusieurs built-ins.

## Fonctionnalités

- Exécution de commandes externes via `execve`
- Gestion des arguments et des chemins d'exécution
- Implémentation des built-ins suivants :
  - `cd` : changer de répertoire
  - `exit` : quitter le shell
  - `setenv` : ajouter/modifier une variable d'environnement
  - `env` : afficher les variables d'environnement
  - `unsetenv` : supprimer une variable d'environnement
  - `>` : Redirige la sortie d'une commande vers un fichier (écrase le fichier s'il existe).
  - `>>` : Redirige la sortie d'une commande vers un fichier en mode ajout (sans écraser le fichier).
  - `<` : Redirige l'entrée d'une commande depuis un fichier.
  - Gestion des variables d'environnement avec une liste chaînée

## Lancement :
  ```
make && ./mysh
  ```

## Utilisation

Lancez le shell avec
`./mysh`

Vous pouvez ensuite entrer des commandes comme vous le feriez dans un terminal classique.

### Exemple d'utilisation

```bash
$ ./mysh
$ ls -l
$ cd Documents
$ setenv MY_VAR EPITECH
$ env
$ unsetenv MY_VAR
$ ls > test.txt
$ whoami >> test.txt
$ cat < Makefile
$ exit
```

## Auteur

Eren Turkoglu - PGE 1 
Projet réalisé dans le cadre de l'école `Epitech`

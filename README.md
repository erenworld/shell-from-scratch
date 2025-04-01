![TCSH](https://upload.wikimedia.org/wikipedia/commons/1/1f/Tcsh_ejecut%C3%A1ndose_en_escritorio_Mac_OSX.png)

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
- Gestion des variables d'environnement avec une liste chaînée

## Compilation

Pour compiler le projet, utilisez :
`make`

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
$ exit
```

## Auteur

Eren Turkoglu - PGE 1 
Projet réalisé dans le cadre de l'école `Epitech`

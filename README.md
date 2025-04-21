# 🛩️ my_radar

Projet Epitech de première année – Simulation graphique du trafic aérien avec la SFML.

## 📌 Objectif

Créer une **simulation 2D du trafic aérien** où des avions se déplacent d’un point A à un point B en évitant les collisions grâce à des tours de contrôle.

## 🎮 Contrôles

| Action             | Touche / Option CLI       |
|--------------------|---------------------------|
| Lancer la simulation | `./my_radar config.txt`   |
| Afficher l'aide | `./my_radar -h`                      |
| Active/Desactive l'affichage des hitboxs |  `L`     |
| Active/Desactive l'affichage des sprites |  `S`     |

---

## 📁 Format du fichier de configuration

Le fichier `config.txt` contient la liste des avions (`A`) et des tours (`T`) :

```text
A x1 y1 x2 y2 speed delay
T x y radius
```

## 🖼️ Captures d’écran 
![Screenshot from 2025-04-21 23-39-07](https://github.com/user-attachments/assets/0e9691fc-8ec5-4049-9e7d-8901c3bb9205)

https://github.com/user-attachments/assets/c1729fad-9747-4d4a-aa19-fd8b0d620588

## 🧰 Technologies utilisées

- Langage : **C**
- Bibliothèque : **CSFML** (bindings C de la SFML)
- Compilation : `Makefile`

## ▶️ Compilation et exécution

### 📦 Dépendances
```bash
sudo apt install libcsfml-dev
```
```bash
make
./my_radar file.txt
```

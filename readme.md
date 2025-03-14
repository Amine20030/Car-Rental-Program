# Car Rental Management System

## Overview

This is a **Car Rental Management System** written in C. The program allows users to:

Add cars to the system

Modify car details

Delete cars

Display the list of available cars

Search for cars based on brand and availability

Sort cars by price or brand

All car records are stored in a file named `voitures.txt` to ensure data persistence.

## Features

**User Authentication:** The system requires a login with the default password `admin` to prevent unauthorized access.

**Dynamic Memory Allocation:** The program dynamically resizes the array of cars as needed.

**File Handling:** Car details are saved to a text file so that data is retained even after the program exits.

**Sorting & Searching:** Users can sort cars by price or brand and search based on specific criteria.

## Installation & Compilation

### Prerequisites

A C compiler (GCC, MinGW, or MSVC)

Windows OS (for `system("PAUSE")` and `system("CLS")`, though it can be modified for Linux)

### Compilation Command

```sh
gcc -o car_management car_management.c
```

### Running the Program

```sh
./car_management
```

## How It Works

### 1. **Login System**

Upon launching the program, users must enter the password. The default password is:

```plaintext
admin
```

If the password is incorrect, the program will prompt the user to retry.

### 2. **Main Menu**

The system presents the following options:

```
1. Ajouter une voiture
2. Modifier une voiture
3. Supprimer une voiture
4. Afficher les voitures
5. Rechercher une voiture
6. Trier les voitures
7. Sauvegarder et Quitter
```

Users can select an option by entering the corresponding number.

### 3. **Adding a Car**

Users can input details such as:

Brand

User

Model

Fuel type

Number of seats

Price

Availability

Each entry is automatically assigned a unique ID.

### 4. **Modifying a Car**

The user enters the **ID** of the car they want to modify and updates its details.

### 5. **Deleting a Car**

Cars are removed based on their **ID**, and the list is adjusted accordingly.

### 6. **Displaying Cars**

All stored cars are displayed in a formatted table.

### 7. **Searching for Cars**

Users can filter cars by **brand** and **availability (yes/no).**

### 8. **Sorting Cars**

Cars can be sorted by **price** (ascending/descending) or by **brand** alphabetically.

### 9. **Saving and Exiting**

Before quitting, the program saves all modifications to `voitures.txt` to ensure data persistence.

- The data format in the file is:
  ```plaintext
  ID,Brand,User,Model,FuelType,Seats,Price,Availability
  ```
  This ensures that car data persists even after exiting the program.

## Possible Improvements

**Enhanced Security:** Encrypt stored passwords.

**Graphical Interface:** Replace the text-based UI with a GUI.

**Database Integration:** Use a relational database instead of a text file.

**Multi-User Authentication:** Allow different levels of access.

**More Sorting Options:** Provide additional filters such as rental history and user ratings.

## ELHEZZAM MOHAMED AMINE

This project was created for learning purposes in C programming and file management.


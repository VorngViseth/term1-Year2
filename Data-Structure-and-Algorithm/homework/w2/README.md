[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ZzWjpcfF)
# OOP - Exercise 2

## 1. Objective

- Understand the core concepts of Object-Oriented Programming (OOP).
- Implement OOP principles such as classes, objects, and methods.
- Learn how to define and use a class and its objects.

## 2. Instructions

In this exercise, you are required to define a Hero class in the [utils/Hero.hpp](./utils/Hero.hpp) file. Once the class is defined, implement the logic in [main.cpp](./main.cpp) to test if the Hero class is functioning as expected.

### Hero Class Specifications

#### Attributes

- `name`: (string) The name of the hero.
- `health`: (int) The health level of the hero.
- `armor`: (int) The armor level, which provides damage resistance.
- `power`: (int) The hero's power, which determines the damage dealt during a strike.
- `weapon`: (string) The weapon that the hero uses.

#### Methods

- `Constructor`: Accepts values for all attributes and initializes the hero's properties.
- `info()`: Displays detailed information about the hero (name, health, armor, power, weapon).
- `strike(Hero& target)`: Simulates an attack on another hero. The attack logic should reduce the target's armor first, and if the power exceeds the armor, the remaining damage should reduce the target's health.

## 3. Example

Imagine there are two heroes in the scene: a `knight` and his `enemy`.

- Hero 1: Knight
    - Name: Richard
    - Health: 50
    - Armor: 50
    - Power: 25
    - Weapon: Sword
- Hero 2: Enemy
    - Name: Rascal
    - Health: 40
    - Armor: 15
    - Power: 10
    - Weapon: Bow and Arrow

Scenario:
When they encounter each other in a forest, a battle begins:

Richard attacks Rascal: Rascal's armor is reduced from `15` to `0`, and his health drops from `40` to `30` after the strike since Rascal's armor can handle only `15`.


***Happy Coding!***
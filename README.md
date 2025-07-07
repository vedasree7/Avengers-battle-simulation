# Avengers Quantum Battle Simulation

A **C++ OOP mini-project** that manages **dynamic Quantum Suit upgrades** and **simulates real-time battles** between Avengers and enemies.

---

## 🚀 Project Title
**Avengers Quantum Suit Upgrade and Battle Manager**

---

## 🎯 Objective

To design and build a **Quantum Suit Management and Battle Simulation System** using **Object-Oriented Programming (OOP)**, applying **polymorphism, operator overloading, and function overloading**.

The system models **live combat between Avengers and their enemies** while handling **dynamic suit upgrades, durability management, and overheating constraints** effectively.

---

##  Background

As they prepare for cosmic threats, the **Avengers are equipped with Quantum Nanotech Suits (QNS)**, engineered by Tony Stark, which:

- Adapt in real-time by absorbing energy and enhancing power levels.
- Reinforce durability during attacks.
- Overclock for delivering high-damage blows.

However, **excessive enhancements can cause overheating**, rendering suits inoperable. Managing these suits efficiently is critical to ensuring victory in battles.

---

## 🧩 Core Components

### 1️⃣ QNS (Quantum Nanotech Suit)

Represents an **adaptive, upgradeable combat suit**.

- **Attributes:**
  - `powerLevel`
  - `durability`
  - `energyStorage`
  - `heatLevel`

- **Features:**
  - Operator overloading for upgrades, attacks, and repairs (`+`, `-`, `*`, `/`).
  - Function overloading for boosting and upgrading.
  - Comparison operators to evaluate suit effectiveness.
  - Enforces safety constraints for overheating and durability checks.

---

### 2️⃣ Avenger

Models an Avenger equipped with a **QNS**.

- **Attributes:**
  - `name`
  - `attackStrength`
  - `QNS` instance

- **Capabilities:**
  - Perform attacks on enemies.
  - Repair and boost their suit.
  - Upgrade using spare suits.
  - Display real-time status of their suit.

- **Constraints:**
  - Only operational Avengers can participate.
  - Suit overheating disables participation until repaired.

---

### 3️⃣ Battle

Manages and **orchestrates the entire simulation** of the battle.

- **Attributes:**
  - Hero and enemy lists.
  - Battle log tracking significant events.

- **Capabilities:**
  - Start and progress the battle through commands.
  - Record key actions (attacks, boosts, repairs, upgrades).
  - Evaluate the current state of the battle:
    - Heroes are winning
    - Enemies are winning
    - Tie

- **Features:**
  - Command-driven architecture for structured control.
  - Real-time dynamic suit management and battle flow.
  - Careful suit assignment and usage tracking to avoid overuse.

---

##  Input Format

- Initialization:
  - Number of suits, heroes, and enemies.
  - Suit details: `P D E H`.
  - Avengers: `name attackStrength`.

- Commands during simulation:
  - `BattleBegin`
  - `Attack <Avenger1> <Avenger2>`
  - `Repair <AvengerName> x`
  - `BoostPowerByFactor <AvengerName> y`
  - `BoostPower <AvengerName> <P> <D> <E> <H>`
  - `Upgrade <AvengerName>`
  - `AvengerStatus <AvengerName>`
  - `PrintBattleLog`
  - `BattleStatus`
  - `End`

---

##  Constraints

- Suits overheat and shut down when `heatLevel > 500`.
- Suits are destroyed if `durability <= 0`.
- `powerLevel` cannot exceed 5000.
- Suits are assigned on a **first-come-first-serve** basis.

---

##  Project Highlights

✅ **Real-Time Combat Simulation** using advanced OOP principles.  
✅ **Dynamic suit upgrades and effective overheating management.**  
✅ **Strategic resource and battle state management.**  
✅ **Extensible and cleanly structured for additional features (new suit types, battle modes).**

---

## 🎉 Outcome

This project **demonstrates advanced OOP and design principles** creatively while building an engaging simulation that requires **strategic thinking, resource optimization, and careful planning** during combat.

[Avengers Quantum Suit Upgrade.pdf](https://github.com/user-attachments/files/20345318/Avengers.Quantum.Suit.Upgrade.pdf)

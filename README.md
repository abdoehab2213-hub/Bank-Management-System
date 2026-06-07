# 🏦 Advanced Bank Management System (C++)

An enterprise-level Console Bank Management System built with modern **Object-Oriented Programming (OOP)** principles in C++. The system supports multiple account types, runtime polymorphism, and persistent data storage.

## 🚀 Key Features
* **Account Types:** Supports both `Savings` and `Current` accounts with unique behaviors.
* **Polymorphic Operations:** Implements dynamic binding for specialized withdrawal rules.
* **File Handling (Persistence):** Automatically saves and loads account data to/from `accounts.txt`.
* **Encapsulation & Safety:** Core data fields are protected from direct external modification.

## 🏗️ OOP Concepts Applied
* **Encapsulation:** Data hiding via `private` and `protected` access modifiers.
* **Inheritance:** Specialized accounts inherit from a robust base `Account` class.
* **Polymorphic Behavior:** Virtual functions used to override standard transaction fees and limits.
* **Separation of Concerns:** Distinct decoupled layers for Data (`Account`), Logic (`BankSystem`), and Presentation (`main`).

## 🛠️ Tech Stack & Requirements
* **Language:** C++11 or higher
* **IDE:** Microsoft Visual Studio 2022 (or any standard C++ Compiler)
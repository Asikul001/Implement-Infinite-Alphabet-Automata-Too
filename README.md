# Implementation of Tools for Infinite Alphabet Automata

## 📖 Description

This project focuses on the implementation of tools and algorithms for automata operating over finite and infinite alphabets.  
The system supports simulation and analysis of multiple automata models including:

- Deterministic Finite Automata (DFA)
- Nondeterministic Finite Automata (NFA)
- Register Automata (RA)

The project is designed for learning, research, and experimentation in Automata Theory and Formal Languages.

---

## 🚀 Features

- DFA simulation and validation
- NFA simulation with multiple transition paths
- Register Automata implementation
- Infinite alphabet handling
- Register comparison and update operations
- Custom transition system
- Input string acceptance/rejection checking
- Modular and extensible architecture

---

## 🛠️ Technologies Used

- C++
- CMake
- STL (Standard Template Library)
- Automata Theory Concepts

---
## ⚙️ Requirements

Before running the project, make sure the following tools are installed:

- C++ Compiler (G++ / Clang++)
- CMake (version 3.10 or higher)

### Required Libraries

This project mainly uses the C++ Standard Library (STL):

- `<vector>`
- `<map>`
- `<set>`
- `<string>`
- `<algorithm>`
- `<iostream>`

---

## 🔧 Installation & Build

Clone the repository:

```bash
git clone https://github.com/Asikul001/Implement-Infinite-Alphabet-Automata-Too
```

Move into the project directory:

```bash
cd Implement-Infinite-Alphabet-Automata-Too
```

Create a build directory:

```bash
mkdir build
```

Move into the build directory:

```bash
cd build
```

Generate build files using CMake:

```bash
cmake ..
```

Build the project:

```bash
cmake --build .
```

Run the executable:

```bash
./infinite_Automata_Tool
```

---

## ⚙️ How to Set Automata Rules 
Create a Simple txt file where need to follow some particular format 
### DFA/NFA Text File structure
```
dfa   //automata name
3     //Number of state
1     // Initial State
2 3   //final state
0 a 1 //transition
...
...

```
```
aaa  //input Structure
```
### RA Text File structure
```
ra        //automata name
3           //No Of State
0           // initial State
2           // No Of Register
2           // final State
{0 a 1}     // Update Register Function
{0 b 1}
{1 a 2}
...
...
0 a 1 0     // Transition
0 b 1 0
0 a 1 1
...
...
...
```
```
(a,0)(a,1)(a,0)  //input Structure
```


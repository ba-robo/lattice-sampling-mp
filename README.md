
# Effective Sampling for Robot Motion Planning Through the Lens of Lattices

[![Ask DeepWiki](https://deepwiki.com/badge.svg)](https://deepwiki.com/ba-robo/lattice-sampling-mp)
[![zread](https://img.shields.io/badge/Ask_Zread-_.svg?style=flat&color=00b0aa&labelColor=000000&logo=data%3Aimage%2Fsvg%2Bxml%3Bbase64%2CPHN2ZyB3aWR0aD0iMTYiIGhlaWdodD0iMTYiIHZpZXdCb3g9IjAgMCAxNiAxNiIgZmlsbD0ibm9uZSIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj4KPHBhdGggZD0iTTQuOTYxNTYgMS42MDAxSDIuMjQxNTZDMS44ODgxIDEuNjAwMSAxLjYwMTU2IDEuODg2NjQgMS42MDE1NiAyLjI0MDFWNC45NjAxQzEuNjAxNTYgNS4zMTM1NiAxLjg4ODEgNS42MDAxIDIuMjQxNTYgNS42MDAxSDQuOTYxNTZDNS4zMTUwMiA1LjYwMDEgNS42MDE1NiA1LjMxMzU2IDUuNjAxNTYgNC45NjAxVjIuMjQwMUM1LjYwMTU2IDEuODg2NjQgNS4zMTUwMiAxLjYwMDEgNC45NjE1NiAxLjYwMDFaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00Ljk2MTU2IDEwLjM5OTlIMi4yNDE1NkMxLjg4ODEgMTAuMzk5OSAxLjYwMTU2IDEwLjY4NjQgMS42MDE1NiAxMS4wMzk5VjEzLjc1OTlDMS42MDE1NiAxNC4xMTM0IDEuODg4MSAxNC4zOTk5IDIuMjQxNTYgMTQuMzk5OUg0Ljk2MTU2QzUuMzE1MDIgMTQuMzk5OSA1LjYwMTU2IDE0LjExMzQgNS42MDE1NiAxMy43NTk5VjExLjAzOTlDNS42MDE1NiAxMC42ODY0IDUuMzE1MDIgMTAuMzk5OSA0Ljk2MTU2IDEwLjM5OTlaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik0xMy43NTg0IDEuNjAwMUgxMS4wMzg0QzEwLjY4NSAxLjYwMDEgMTAuMzk4NCAxLjg4NjY0IDEwLjM5ODQgMi4yNDAxVjQuOTYwMUMxMC4zOTg0IDUuMzEzNTYgMTAuNjg1IDUuNjAwMSAxMS4wMzg0IDUuNjAwMUgxMy43NTg0QzE0LjExMTkgNS42MDAxIDE0LjM5ODQgNS4zMTM1NiAxNC4zOTg0IDQuOTYwMVYyLjI0MDFDMTQuMzk4NCAxLjg4NjY0IDE0LjExMTkgMS42MDAxIDEzLjc1ODQgMS42MDAxWiIgZmlsbD0iI2ZmZiIvPgo8cGF0aCBkPSJNNCAxMkwxMiA0TDQgMTJaIiBmaWxsPSIjZmZmIi8%2BCjxwYXRoIGQ9Ik00IDEyTDEyIDQiIHN0cm9rZT0iI2ZmZiIgc3Ryb2tlLXdpZHRoPSIxLjUiIHN0cm9rZS1saW5lY2FwPSJyb3VuZCIvPgo8L3N2Zz4K&logoColor=ffffff)](https://zread.ai/ba-robo/lattice-sampling-mp)

This repository contains the code used to run the experiments for the paper. It was accepted to RSS 2025, and this version contains the sum of work that this paper included.

* [RSS 2025](https://roboticsconference.org/program/papers/48/).
* [ArXiv](https://arxiv.org/abs/2502.04908)

| ![UM_scenarios.png](https://github.com/user-attachments/assets/e3f8765f-6441-442c-9174-8381a05413dc) | ![sleeve_manipulator.png](https://github.com/user-attachments/assets/3ed5eccc-fe39-4ced-ac05-c54a0aeeb45d) |
|:--:|:--:|
| *Example scenario with multiple translated disks in a maze. Implemented in OMPL.* | * Example scenario relying on the VAMP library.*  |

## Authors

- [@Itai Panasoff, Technion](https://ItaiRobotics.github.io)
- [@Kiril Solovey, Technion](https://kirilsol.github.io/)

We are both from the [@MRS lab](https://mrstechnion.github.io/) at the Technion.



## Paper abstract

Sampling-based methods for motion planning, which
capture the structure of the robot’s free space via (typically
random) sampling, have gained popularity due to their scalability,
simplicity, and for offering global guarantees, such as probabilis-
tic completeness and asymptotic optimality. Unfortunately, the
practicality of those guarantees remains limited as they do not
provide insights into the behavior of motion planners for a finite
number of samples (i.e., a finite running time). In this work,
we harness lattice theory and the concept of (δ, ε)-completeness
by Tsao et al. (2020) to construct deterministic sample sets
that endow their planners with strong finite-time guarantees
while minimizing running time. In particular, we introduce a
highly-efficient deterministic sampling approach based on the $A_d^*$
lattice, which is the best-known geometric covering in dimensions
≤ 21. Using our new sampling approach, we obtain at least
an order-of-magnitude speedup over existing deterministic and
uniform random sampling methods for complex motion-planning
problems. Overall, our work provides deep mathematical insights
while advancing the practical applicability of sampling-based
motion planning.

## Code
### Prerequisites

To successfully run the code (as tested on Linux), several things are needed.

* OMPL: The [open motion-planning library](https://ompl.kavrakilab.org/) is the motion planning framework with which we write the tests. Follow the instructions on the site to install it.

* VAMP: The [VAMP](https://github.com/KavrakiLab/vamp) repo implements extremely quick manipulator planning. We showcase it in the paper, and so it is needed in the project. Follow the instructions to install it. 

* Eigen3: [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page) is a C++ library for performing linear-algebra operations. Installing shouldn't be an issue here.

* NTL: The [Number-Theory Library](https://libntl.org/) is used in the project for some operations (like Cholesky decomposition) we were considering for the paper, but didn't use in the end. Still, it is included and needed, as it is a baseline for future work on the matter.

### Features

* Explicit construction of the lattices in the paper (see the `CreateLatticeParameters()` function in `ImplicitPRM.cpp`). 
* The iA* algorithm as used on lattices (see the `constructSolutionImplicitlyLattice(..)` function in `ImplicitPRM.cpp`).
* Testing both on a manipulator model (see the `VAMPTests.h/cpp` files) and on multiple-moving-disks scenarios (see the `implicit_PRM_2D_multi(..)` function).

### Usage/Examples

The code contains two parts. 
* The python files mostly helped me with plotting the figures for the paper: the graphs (A as a function of B), and the lattice illustrations.
* The C++ files contain the bulk of the work in the paper. This means:
    * Comparing lattices to each other.
    * Comparing $A_d^*$ to random sets.
    * Calibrating a lattice, i.e. finding the best density (in terms of runtime).
    * VAMP tests with the $A_d^*$ lattice.

To use run the tests you can focus on the `main.cpp` file, and within it the normal `int main(int argc, char **)` function. There, you will find several test options:

```cpp
    /// Comparative test sets
    compareLatticesToEachother(folderBase);
    calibrateLattices(folderBase);
    AnstarVSImplicitPRM(folderBase);

    /// Vamp tests
    VAMPTests::runVampTests(argc, folderBase);
    /// counting samples
    findNumberOfSamples();

```

The main point of concern needs to be in the `std::vector<TestData> getTests()` function, which returns the functions you currently test. In there, you will have several `TestData` structures (representing tests), which are later added to the test list. That is where you need to choose what to add:

```cpp
    /// Zn vs Dn* vs An*
    std::vector<TestData> lattice_tests;

    /// d=6
    // lattice_tests.push_back(bugtrapT1B);
    // lattice_tests.push_back(bugtrapT2);
    // lattice_tests.push_back(bugtrapT2B);
    // lattice_tests.push_back(bugtrapT3);
    // lattice_tests.push_back(bugtrapT5);
    // lattice_tests.push_back(bugtrapT6);
    // lattice_tests.push_back(bugtrapT8);
    // lattice_tests.push_back(bugtrapT8B);
    // lattice_tests.push_back(bugtrapT11);

    lattice_tests.push_back(kennyT1);

    // lattice_tests.push_back(UniqueMaze1);
    // lattice_tests.push_back(UniqueMaze2);
    // lattice_tests.push_back(UniqueMaze4B3);
    // lattice_tests.push_back(UniqueMaze5);


    // lattice_tests.push_back(UniqueMaze3);
```

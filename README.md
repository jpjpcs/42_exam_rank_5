## Main Repository README

The rank 5 exam is composed by 3 different questions/three modules:

1. **Module 00**: Contains the initial setup and basic concepts for the exam. [Module 00](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module00)
2. **Module 01**: Introduces the Warlock class, along with spells and targets, and covers concepts such as polymorphism and abstract classes. [Module 01](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module01)
3. **Module 02**: Expands on the Warlock class with a SpellBook and TargetGenerator, and introduces new spells and targets. [Module 02](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module02)

# 🧙‍♂️ C++ Module Summary Guide

## ADVICE: MY ADVICE STRATEGY IS TO DO THE EXAM JUST BY FOLLOWING THE SUBJECT AND WHAT´S ASKED IN THE SUBJECT.
---

## 📘 CPP00

### Exercise 00

In this exercise, **we are not required** to use the **copy constructor** or the **assignment operator**, but **it’s considered good practice** to implement them.

We simply need to create a `Warlock` class with **private attributes**, including:
- A **copy constructor**
- An **assignment operator**

These are used to avoid copy construction or instantiation by copy.

---

## 📗 CPP01

### Exercise 01

This exercise can be broken down into **five parts**:

1. `ASpell` class  
2. `ATarget` class  
3. `Fwoosh` class  
4. `Dummy` class  
5. `Warlock` class modifications

#### 🔹 ASpell

- It is essentially a **copy** of the `Warlock` class.
- Use `Ctrl + Shift + L` (or right-click > "Change All Occurrences") in Visual Studio to quickly replace all instances of `"Warlock"` with `"ASpell"`.
- Move the **default constructor**, **copy constructor**, **assignment operator**, and create the `launch()` method to the **public** section.
- ASpell will inherit to Fwoosh, so we use virtual in the destructor, to allow that the destructor of the son could be used instead of the one that belongs to the father (in this case ASpell). This prevents memory leaks, as well as allows the creation of customized phrases when the son it´s destroyed. 

```cpp 
virtual ~ASpell();
````

- Also, the clone function needs to be virtual. Otherwise, it will give a compiler error. And why? Because the clone will be implemented by the son classes.

```cpp
virtual ASpell *clone const() = 0;
``` 
- We also need to declare class ATarget before implementing the ASPell class in the ASpell.hpp file, to allow the compiler to know that we are invoking that class before using it in the launch function.

```cpp
void launch (ATarget const &target);
```

#### 🔹 ATarget

- A **copy** of `ASpell`, replacing all occurrences of `"ASpell"` with `"ATarget"`, deleting effects and changing "name for type" and getName for getType.
- Replace the `launch()` method with `getHitBySpell()`.
- ATarget will inherit to Dummy, so we use virtual in the destructor, to allow that the destructor of the son could be used instead of the one that belongs to the father (in this case ATarget). This prevents memory leaks, as well as allows the creation of customized phrases when the son it´s destroyed. 

```cpp 
virtual ~ATarget();
````

- Also, the clone function needs to be virtual. Otherwise, it will give a compiler error. And why? Because the clone will be implemented by the son classes.

```cpp
virtual ATarget *clone const() = 0;
``` 

- We also need to declare the class ASPell before implementing the ATarget class in the ATarget.hpp file, to allow the compiler to know that we are invoking that class before using it in the getHitBySpell function.

```cpp
void getHitBySpell (ASpell const &spell) const;

```

#### 🔹 Fwoosh

- Inherits from `ASpell`:
  ```cpp
  class Fwoosh : public ASpell

Implementation example:
 ```cpp
Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed") {}
ASpell* Fwoosh::clone() const { return new Fwoosh(); }
```

- Don´t need to use virtual in the destructor once we are already using it in the mother class ASpell.

#### 🔹 Dummy
Similar to Fwoosh, but inherits from ATarget.

➡️ Both Fwoosh and Dummy are derived classes.


Fwoosh is just ASpell with fewer things and using "public ASpell" after "class Fwoosh" in the hpp file, and with "Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed" in the cpp and a clone. DUMMY IS THE SAME but referring to the ATARGET class. BOTH ARE inherited Classes.


- Don´t need to use virtual in the destructor once we are already using it in the mother class ATarget.

## 📙 CPP02

#### Exercise 02

This exercise also consists of five main components:

1. Fireball and Polymorph classes

2. BrickWall class

3. SpellBook class

4. Warlock class modifications

5. TargetGenerator class

#### 🔹 Fireball & Polymorph
Both are copies of Fwoosh, with different names and string values.

#### 🔹 BrickWall
A copy of Dummy.

#### 🔹 SpellBook
A copy of the Warlock class.

Use Ctrl + Shift + L to replace "Warlock" with "SpellBook".

Remove unnecessary functions such as the parameterized constructor.

Make the default constructor public.

Implement the createSpell() function like this (with a clone like is asked in the subject):
ASpell* SpellBook::createSpell(std::string const &spell) {
    if (spells.count(spell))
        return spells[spell]->clone();
    return NULL;
}


#### 🔹 Warlock Modifications
Update to work seamlessly with SpellBook and the new spells, calling learnSpell and forgetSpell of the SpellBook in the Warlock learnSpell and forgetSpell functions, and
changing launchSpell to use createSpell:

void Warlock::launchSpell(std::string const &spell, ATarget &target)
{
    ASpell *newspell = spells.createSpell(spell);
    if(newspell)
    {
        newspell->launch(target);
        delete newspell;
    }
}

#### 🔹 TargetGenerator
A copy of SpellBook, with:

spells ➜ targets

spell ➜ target

ASpell ➜ ATarget

learnSpell() ➜ learnTargetType()

forgetSpell() ➜ forgetTargetType()

createSpell() ➜ createTarget()

Change getName for getType otherwise you will have a compilation error, because getName doesn´t exist in ATarget (instead it´s getType).


# 🧙‍♂️ C++ Module DETAILED Guide

## 📦 C++ Module 00 - Warlock Class

### 🧙 Assignment Name
**cpp_module_00**

### 📁 Expected Files
- `Warlock.hpp`
- `Warlock.cpp`

---

### 📖 Exercise Objective

In this exercise, the student must implement a `Warlock` class in C++, following the **Coplien's form**. The goal is to practice **encapsulation**, **constructors and destructors**, **copy prevention**, and overall good **object-oriented design** principles.

---

### 🧠 Key Theoretical Concepts Covered

#### ✅ Coplien's Form (The Rule of Three)
- Implementation of:
  - **Custom constructor** that requires parameters.
  - **Destructor** that prints a message when called.
  - Explicitly **deleting**:
    - The **copy constructor**
    - The **copy assignment operator**

#### ✅ Encapsulation
- Private attributes (`name`, `title`)
- Controlled access via **getters**:
  - `getName()` and `getTitle()` return a constant reference to a string.
- Controlled modification via **setter**:
  - `setTitle()` updates the warlock’s title.

#### ✅ Const-Correctness
- Ensure that methods not modifying the object are marked as `const`.
- Getters and `introduce()` must be callable on `const` Warlocks.

#### ✅ Custom Messages on Lifecycle Events
- Upon creation:
<NAME>: This looks like another boring day.
- Upon destruction:
<NAME>: My job here is done!


#### ✅ Operation Restrictions
- The class must **not allow**:
- Instantiation without parameters.
- Copying or assigning Warlock objects.

---

### 🧪 Example Behavior

```cpp
int main()
{
Warlock const richard("Richard", "Mistress of Magma");
richard.introduce();
std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;

Warlock* jack = new Warlock("Jack", "the Long");
jack->introduce();
jack->setTitle("the Mighty");
jack->introduce();

delete jack;

return 0;
}

💡 Expected Output

Richard: This looks like another boring day.
Richard: I am Richard, Mistress of Magma!
Richard - Mistress of Magma
Jack: This looks like another boring day.
Jack: I am Jack, the Long!
Jack: I am Jack, the Mighty!
Jack: My job here is done!
Richard: My job here is done!

```


### 🎯 What the Student Should Learn
Understanding and application of Coplien’s form in C++.

How to delete copy constructors and assignment operators to prevent object copying.

Proper use of const-correctness in class design.

Writing constructors, destructors, getters, and setters correctly.

Practicing clean and safe object-oriented programming.

Applying these principles confidently in exams and future projects.





----------------------------------------





## 📦 C++ Module 01 - Spellcasting System

### 🧙 Assignment Name
**cpp_module_01**

### 📁 Expected Files

- `Warlock.hpp`, `Warlock.cpp`
- `ASpell.hpp`, `ASpell.cpp`
- `ATarget.hpp`, `ATarget.cpp`
- `Fwoosh.hpp`, `Fwoosh.cpp`
- `Dummy.hpp`, `Dummy.cpp`

---

### 📖 Exercise Objective

This module builds upon the previous one by introducing **abstract classes**, **inheritance**, **polymorphism**, and **dynamic object behavior**. The student is expected to implement a small spellcasting system using proper **object-oriented programming (OOP)** techniques in C++.

🚫 **IMPORTANT:** Use of `switch` statements is strictly forbidden and will result in a **-42**.

---

### 🧠 Key Theoretical Concepts Covered

#### ✅ Abstract Classes and Polymorphism

- `ASpell` and `ATarget` are **abstract base classes**.
- Both must implement a `clone()` **pure virtual function** to enable polymorphic copying.

#### ✅ Coplien's Form (Rule of Three)

- Each class must follow **Coplien’s form**:
  - Proper constructor(s)
  - Destructor
  - Copy constructor and assignment operator (if needed)

#### ✅ Const-Correctness

- All getters and polymorphic methods must be callable on `const` objects.

#### ✅ Encapsulation and Class Design

- `ASpell` holds:
  - `name` and `effects`
  - `getName()`, `getEffects()`, `launch()`
- `ATarget` holds:
  - `type`
  - `getType()`, `getHitBySpell()`

#### ✅ Concrete Implementations

- `Fwoosh`: a concrete spell class (`ASpell`) with:
  - Name: `"Fwoosh"`
  - Effects: `"fwooshed"`
  - `clone()` returns `new Fwoosh()`
- `Dummy`: a concrete target class (`ATarget`) with:
  - Type: `"Target Practice Dummy"`
  - `clone()` returns `new Dummy()`

#### ✅ Warlock Spell System

- `Warlock` must manage learned spells:
  - `learnSpell(ASpell*)` – copies and stores the spell
  - `forgetSpell(string)` – removes the spell by name
  - `launchSpell(string, ATarget&)` – casts the named spell on the target
- The spells must be stored internally using an appropriate container (e.g., `std::map`, `std::vector`, etc.).

---

### 🧪 Example Behavior

```cpp
int main()
{
  Warlock richard("Richard", "the Titled");

  Dummy bob;
  Fwoosh* fwoosh = new Fwoosh();

  richard.learnSpell(fwoosh);

  richard.introduce();
  richard.launchSpell("Fwoosh", bob);

  richard.forgetSpell("Fwoosh");
  richard.launchSpell("Fwoosh", bob);

  // WE MUST INCLUDE THIS IN THE MAIN GIVEN IN THE SUBJECT. Otherwise will return MEMORY LEAKS:
delete fwoosh;
}

💡 Expected Output
Richard: This looks like another boring day.
Richard: I am Richard, the Titled!
Target Practice Dummy has been fwooshed!
Richard: My job here is done!
```

### 🎯 Learning Outcomes
By completing this module, students should:

Understand and apply abstract classes and pure virtual functions in C++.

Use inheritance to model reusable behavior (spell/target hierarchies).

Correctly implement object cloning via clone() methods to enable safe polymorphic copying.

Use const-correctness and encapsulation in real-world class designs.

Store and manage dynamic objects using standard containers and appropriate memory management.

Build scalable and modular code that reflects solid OOP practices.





----------------------------------------





## 📦 C++ Module 02 - Spellbook & Target System

### 🧙 Assignment Name
**cpp_module_02**

### 📁 Expected Files

- `Warlock.hpp`, `Warlock.cpp`
- `ASpell.hpp`, `ASpell.cpp`
- `ATarget.hpp`, `ATarget.cpp`
- `Fwoosh.hpp`, `Fwoosh.cpp`
- `Fireball.hpp`, `Fireball.cpp`
- `Polymorph.hpp`, `Polymorph.cpp`
- `Dummy.hpp`, `Dummy.cpp`
- `BrickWall.hpp`, `BrickWall.cpp`
- `SpellBook.hpp`, `SpellBook.cpp`
- `TargetGenerator.hpp`, `TargetGenerator.cpp`

---

### 📖 Exercise Objective

In this module, the spellcasting system introduced in previous exercises is expanded. The goal is to consolidate understanding of:

- **Abstract factories**
- **Deep copying via clone**
- **Polymorphism**
- **Encapsulation and delegation**
- **Composition over inheritance**

⚠️ **Important Rule:** The use of `switch` statements is **strictly forbidden** in `Warlock`, `SpellBook`, and `TargetGenerator`, and will result in a **-42**.

---

### 🧠 Key Theoretical Concepts Covered

#### ✅ Concrete Spell and Target Classes

You must implement two new spells and one new target:

- `Fireball` – Name: `"Fireball"`, Effects: `"burnt to a crisp"`
- `Polymorph` – Name: `"Polymorph"`, Effects: `"turned into a critter"`
- `BrickWall` – Type: `"Inconspicuous Red-brick Wall"`

Each must override `clone()` and follow the same structure as `Fwoosh` and `Dummy`.

---

#### ✅ SpellBook Class (Factory + Container)

- Must follow **canonical form**.
- Cannot be copied.
- Responsibilities:
  - `learnSpell(ASpell*)` – clones and stores the spell.
  - `forgetSpell(const std::string&)` – removes spell by name.
  - `createSpell(const std::string&)` – returns a *new* clone of the requested spell.

---

#### ✅ Warlock Enhancements

- The `Warlock` now **contains a SpellBook**.
- `learnSpell`, `forgetSpell`, and `launchSpell` must delegate to the `SpellBook`.
- `launchSpell` must create the spell on-demand from the book before casting it on a target.

---

#### ✅ TargetGenerator Class (Target Factory)

- Also follows **canonical form** and is **non-copyable**.
- Responsibilities:
  - `learnTargetType(ATarget*)` – stores a clone of a new target type.
  - `forgetTargetType(const std::string&)` – removes a target type by name.
  - `createTarget(const std::string&)` – returns a *new* instance of the requested type.

---

### 🧪 Example Behavior

```cpp
int main()
{
  Warlock richard("Richard", "foo");
  richard.setTitle("Hello, I'm Richard the Warlock!");
  BrickWall model1;

  Polymorph* polymorph = new Polymorph();
  TargetGenerator tarGen;

  tarGen.learnTargetType(&model1);
  richard.learnSpell(polymorph);

  Fireball* fireball = new Fireball();

  richard.learnSpell(fireball);

  ATarget* wall = tarGen.createTarget("Inconspicuous Red-brick Wall");

  richard.introduce();
  richard.launchSpell("Polymorph", *wall);
  richard.launchSpell("Fireball", *wall);

  // WE MUST INCLUDE THIS IN THE MAIN GIVEN IN THE SUBJECT. Otherwise, it will return MEMORY LEAKS:
delete fireball;
delete polymorph;
delele wall;
}

💡 Expected Output

Richard: This looks like another boring day.
Richard: I am Richard, Hello, I'm Richard the Warlock!!
Inconspicuous Red-brick Wall has been turned into a critter!
Inconspicuous Red-brick Wall has been burnt to a crisp!
Richard: My job here is done!
```

### 🎯 Learning Outcomes
By completing this module, students will:

Practice and apply polymorphism with abstract classes and virtual functions.

Understand and implement the Factory design pattern through SpellBook and TargetGenerator.

Deepen knowledge of composition, delegating logic to internal helper classes.

Improve memory management by handling dynamic object creation and deep copies correctly.

Respect const-correctness, clean class design, and canonical form requirements.

Learn to build modular, scalable, and extensible C++ applications.










Happy coding! 🚀

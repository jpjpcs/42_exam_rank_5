## Main Repository README

The rank 5 exam is composed by 3 different questions/three modules:

1. **Module 00**: Contains the initial setup and basic concepts for the exam. [Module 00](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module00)
2. **Module 01**: Introduces the Warlock class, along with spells and targets, and covers concepts such as polymorphism and abstract classes. [Module 01](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module01)
3. **Module 02**: Expands on the Warlock class with a SpellBook and TargetGenerator, and introduces new spells and targets. [Module 02](https://github.com/jpjpcs/42_exam_rank_5/tree/main/cpp_module02)

## ADVICE: MY ADVICE STRATEGY IS TO DO THE EXAM JUST BY FOLLOWING THE SUBJECT AND WHAT´S ASKED IN THE SUBJECT.
### CPP00 
- IN CASE OF EX00 WE DON´T NEED TO USE COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR, but we should once it´s a good practice. IN CASE OF EX00 WE JUST NEED TO CREATE A WARLOCK CLASS WITH PRIVATE ELEMENTS (INCLUDING COPY CONSTRUCTOR AND ASSIGNMENT OPERATOR TO AVOID COPY OR INSTANTIATION BY COPY).
### CPP01
- IN CASE OF EX01, I DIVIDED MY SUBJECT INTO 5 POINTS THAT WERE ASKED: 1.ASpell CLASS, 2.ATarget CLASS, 3.Fwoosh, 4.Dummy, AND 5.Warlock ALTERATIONS. 
ASPELL CLASS IS "A COPY" OF WARLOCK...WE JUST NEED TO CHANGE SOMETHINGS. To do that, just use "ctrl + shift + L" in visual studio (or right click on the mouse and choose "change all occurrences") after selecting the word to substitute. ASPELL IS A "COPY" OF WARLOCK, only changing all occurrences of Warlock for ASpell and putting pattern and copy constructor, and assignment operator the  public side, as well as including the launch function. ATarget is "copy" of ASpell, changing all occurrences of ASpell and substituting the launch function for getHitBySpell. 
FWOOSH is just ASPELL with fewer things and using "public ASpell" after "class Fwoosh" in the hpp file, and with "Fwoosh::Fwoosh() : ASpell("Fwoosh", "fwooshed" in the cpp and a clone. DUMMY IS THE SAME but referring to the ATARGET class. BOTH ARE inherited Classes.
### CPP02
- IN CASE OF EX02, I DIVIDED MY SUBJECT INTO 5 POINTS THAT WERE ASKED: 1.Fireball and Polymorph CLASSES, 2.BrickWall CLASS, 3.SpellBook, 4.Warlock modifications, AND 5.TargetGenerator Class.
Fireball and Polymorph are "copy" of Fwoosh. BrickWall is a "copy" of Dummy. 
SPELLBOOK is a copy of Warlock with "ctrl + shift + L" in some parameters (change name of Warlock to SpellBook and erase unnecessary functions such as the  parametrized constructor and put the pattern constructor in the public parameters, changing also the createSpell for:
ASpell *SpellBook::createSpell(std::string const &spell)
{
    if(spells.count(spell))
        return(spells[spell]->clone());
    return(NULL);
}) 

TARGETGENERATOR a copy of SpellBook changing the name of "spells for targets" and "spell for target", also changing ASpell for ATArget, and learnSpell/forgetSpell/createSpell for learnTargetType/forgetTargetType/createTarget).




# 📦 C++ Module 00 - Warlock Class

## 🧙 Assignment Name
**cpp_module_00**

## 📁 Expected Files
- `Warlock.hpp`
- `Warlock.cpp`

---

## 📖 Exercise Objective

In this exercise, the student must implement a `Warlock` class in C++, following the **Coplien's form**. The goal is to practice **encapsulation**, **constructors and destructors**, **copy prevention**, and overall good **object-oriented design** principles.

---

## 🧠 Key Theoretical Concepts Covered

### ✅ Coplien's Form (The Rule of Three)
- Implementation of:
  - **Custom constructor** that requires parameters.
  - **Destructor** that prints a message when called.
  - Explicitly **deleting**:
    - The **copy constructor**
    - The **copy assignment operator**

### ✅ Encapsulation
- Private attributes (`name`, `title`)
- Controlled access via **getters**:
  - `getName()` and `getTitle()` return a constant reference to a string.
- Controlled modification via **setter**:
  - `setTitle()` updates the warlock’s title.

### ✅ Const-Correctness
- Ensure that methods not modifying the object are marked as `const`.
- Getters and `introduce()` must be callable on `const` Warlocks.

### ✅ Custom Messages on Lifecycle Events
- Upon creation:
<NAME>: This looks like another boring day.
- Upon destruction:
<NAME>: My job here is done!


### ✅ Operation Restrictions
- The class must **not allow**:
- Instantiation without parameters.
- Copying or assigning Warlock objects.

---

## 🧪 Example Behavior

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


## 🎯 What the Student Should Learn
Understanding and application of Coplien’s form in C++.

How to delete copy constructors and assignment operators to prevent object copying.

Proper use of const-correctness in class design.

Writing constructors, destructors, getters, and setters correctly.

Practicing clean and safe object-oriented programming.

Applying these principles confidently in exams and future projects.





----------------------------------------





# 📦 C++ Module 01 - Spellcasting System

## 🧙 Assignment Name
**cpp_module_01**

## 📁 Expected Files

- `Warlock.hpp`, `Warlock.cpp`
- `ASpell.hpp`, `ASpell.cpp`
- `ATarget.hpp`, `ATarget.cpp`
- `Fwoosh.hpp`, `Fwoosh.cpp`
- `Dummy.hpp`, `Dummy.cpp`

---

## 📖 Exercise Objective

This module builds upon the previous one by introducing **abstract classes**, **inheritance**, **polymorphism**, and **dynamic object behavior**. The student is expected to implement a small spellcasting system using proper **object-oriented programming (OOP)** techniques in C++.

🚫 **IMPORTANT:** Use of `switch` statements is strictly forbidden and will result in a **-42**.

---

## 🧠 Key Theoretical Concepts Covered

### ✅ Abstract Classes and Polymorphism

- `ASpell` and `ATarget` are **abstract base classes**.
- Both must implement a `clone()` **pure virtual function** to enable polymorphic copying.

### ✅ Coplien's Form (Rule of Three)

- Each class must follow **Coplien’s form**:
  - Proper constructor(s)
  - Destructor
  - Copy constructor and assignment operator (if needed)

### ✅ Const-Correctness

- All getters and polymorphic methods must be callable on `const` objects.

### ✅ Encapsulation and Class Design

- `ASpell` holds:
  - `name` and `effects`
  - `getName()`, `getEffects()`, `launch()`
- `ATarget` holds:
  - `type`
  - `getType()`, `getHitBySpell()`

### ✅ Concrete Implementations

- `Fwoosh`: a concrete spell class (`ASpell`) with:
  - Name: `"Fwoosh"`
  - Effects: `"fwooshed"`
  - `clone()` returns `new Fwoosh()`
- `Dummy`: a concrete target class (`ATarget`) with:
  - Type: `"Target Practice Dummy"`
  - `clone()` returns `new Dummy()`

### ✅ Warlock Spell System

- `Warlock` must manage learned spells:
  - `learnSpell(ASpell*)` – copies and stores the spell
  - `forgetSpell(string)` – removes the spell by name
  - `launchSpell(string, ATarget&)` – casts the named spell on the target
- The spells must be stored internally using an appropriate container (e.g., `std::map`, `std::vector`, etc.).

---

## 🧪 Example Behavior

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

´´´


## 🎯 Learning Outcomes
By completing this module, students should:

Understand and apply abstract classes and pure virtual functions in C++.

Use inheritance to model reusable behavior (spell/target hierarchies).

Correctly implement object cloning via clone() methods to enable safe polymorphic copying.

Use const-correctness and encapsulation in real-world class designs.

Store and manage dynamic objects using standard containers and appropriate memory management.

Build scalable and modular code that reflects solid OOP practices.





----------------------------------------





# 📦 C++ Module 02 - Spellbook & Target System

## 🧙 Assignment Name
**cpp_module_02**

## 📁 Expected Files

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

## 📖 Exercise Objective

In this module, the spellcasting system introduced in previous exercises is expanded. The goal is to consolidate understanding of:

- **Abstract factories**
- **Deep copying via clone**
- **Polymorphism**
- **Encapsulation and delegation**
- **Composition over inheritance**

⚠️ **Important Rule:** The use of `switch` statements is **strictly forbidden** in `Warlock`, `SpellBook`, and `TargetGenerator`, and will result in a **-42**.

---

## 🧠 Key Theoretical Concepts Covered

### ✅ Concrete Spell and Target Classes

You must implement two new spells and one new target:

- `Fireball` – Name: `"Fireball"`, Effects: `"burnt to a crisp"`
- `Polymorph` – Name: `"Polymorph"`, Effects: `"turned into a critter"`
- `BrickWall` – Type: `"Inconspicuous Red-brick Wall"`

Each must override `clone()` and follow the same structure as `Fwoosh` and `Dummy`.

---

### ✅ SpellBook Class (Factory + Container)

- Must follow **canonical form**.
- Cannot be copied.
- Responsibilities:
  - `learnSpell(ASpell*)` – clones and stores the spell.
  - `forgetSpell(const std::string&)` – removes spell by name.
  - `createSpell(const std::string&)` – returns a *new* clone of the requested spell.

---

### ✅ Warlock Enhancements

- The `Warlock` now **contains a SpellBook**.
- `learnSpell`, `forgetSpell`, and `launchSpell` must delegate to the `SpellBook`.
- `launchSpell` must create the spell on-demand from the book before casting it on a target.

---

### ✅ TargetGenerator Class (Target Factory)

- Also follows **canonical form** and is **non-copyable**.
- Responsibilities:
  - `learnTargetType(ATarget*)` – stores a clone of a new target type.
  - `forgetTargetType(const std::string&)` – removes a target type by name.
  - `createTarget(const std::string&)` – returns a *new* instance of the requested type.

---

## 🧪 Example Behavior

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
´´´

## 🎯 Learning Outcomes
By completing this module, students will:

Practice and apply polymorphism with abstract classes and virtual functions.

Understand and implement the Factory design pattern through SpellBook and TargetGenerator.

Deepen knowledge of composition, delegating logic to internal helper classes.

Improve memory management by handling dynamic object creation and deep copies correctly.

Respect const-correctness, clean class design, and canonical form requirements.

Learn to build modular, scalable, and extensible C++ applications.










Happy coding! 🚀

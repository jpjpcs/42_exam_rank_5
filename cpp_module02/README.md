# Warlock Spellbook and Target Generator

## Description

In this module, we expand the capabilities of the Warlock class by introducing a SpellBook and a TargetGenerator. Additionally, we create new spells and targets for the Warlock to interact with.

## Warlock Class

The `Warlock` class represents a mystical practitioner of arcane arts, capable of wielding powerful spells against their foes. The Warlock now possesses a SpellBook to manage their repertoire of spells.

### Class Structure

- **Private Attributes**:
  - `name` (string): The name of the warlock.
  - `title` (string): The title or epithet of the warlock.
  - `spells` (SpellBook): A SpellBook object to manage the warlock's spells.

- **Public Member Functions**:
  - `Warlock(std::string const name, std::string const title)`: Constructor that initializes a warlock with the given name and title.
  - `~Warlock()`: Destructor that cleans up memory and prints a message when the warlock's life cycle ends.
  - `std::string const getName() const`: Getter function that returns the name of the warlock.
  - `std::string const getTitle() const`: Getter function that returns the title of the warlock.
  - `void setTitle(std::string const &title)`: Setter function that sets the title of the warlock.
  - `void introduce() const`: Function that displays an introduction message, including the name and title of the warlock.
  - `void learnSpell(ASpell *spell)`: Function that allows the warlock to learn a new spell.
  - `void forgetSpell(std::string const &spell)`: Function that makes the warlock forget a previously learned spell.
  - `void launchSpell(std::string const &spell, ATarget &target)`: Function that casts a spell on a target.

## SpellBook Class

The `SpellBook` class manages a collection of spells known by the warlock.

### Class Structure

- **Private Attributes**:
  - `spells` (map<string, ASpell *>): A collection of spells known by the warlock, stored as key-value pairs where the key is the spell name and the value is a pointer to the corresponding `ASpell` object.

- **Public Member Functions**:
  - `SpellBook()`: Default constructor.
  - `~SpellBook()`: Destructor that cleans up memory.
  - `void learnSpell(ASpell *spell)`: Function that allows adding a new spell to the spell book.
  - `void forgetSpell(std::string const &spell)`: Function that removes a spell from the spell book.
  - `ASpell *createSpell(std::string const &spell)`: Function that creates a spell object based on its name.

## TargetGenerator Class

The `TargetGenerator` class manages a collection of target types that can be generated for spells.

### Class Structure

- **Private Attributes**:
  - `targets` (map<string, ATarget *>): A collection of target types known by the target generator, stored as key-value pairs where the key is the target type and the value is a pointer to the corresponding `ATarget` object.

- **Public Member Functions**:
  - `TargetGenerator()`: Default constructor.
  - `~TargetGenerator()`: Destructor that cleans up memory.
  - `void learnTargetType(ATarget *target)`: Function that allows adding a new target type to the target generator.
  - `void forgetTargetType(std::string const &target)`: Function that removes a target type from the target generator.
  - `ATarget *createTarget(std::string const &target)`: Function that creates a target object based on its type.

## Concrete Spell Implementations

- **Fireball**: A concrete implementation of the `ASpell` class representing a fire-based spell. Default constructor sets the name to "Fireball" and the effects to "burnt to a crisp".
- **Polymorph**: A concrete implementation of the `ASpell` class representing a transformation spell. Default constructor sets the name to "Polymorph" and the effects to "turned into a critter".

## Concrete Target Implementations

- **BrickWall**: A concrete implementation of the `ATarget` class representing an inconspicuous red-brick wall. Constructor sets the type to "Inconspicuous Red-brick Wall".

## Usage

To create a warlock, manage spells, and generate targets, follow these steps:

1. **Instantiate a Warlock**: Create a `Warlock` object with a name and title.
2. **Learn Spells**: Use the `learnSpell()` function to teach the warlock new spells.
3. **Cast Spells**: Launch spells using the `launchSpell()` function.
4. **Manage SpellBook**: Add, remove, and create spells using the SpellBook.
5. **Manage TargetGenerator**: Add, remove, and create targets using the TargetGenerator.

## File Structure

- **`Warlock.hpp` / `Warlock.cpp`**: Declaration and implementation of the `Warlock` class.
- **`ASpell.hpp` / `ASpell.cpp`**: Declaration and implementation of the `ASpell` abstract class.
- **`ATarget.hpp` / `ATarget.cpp`**: Declaration and implementation of the `ATarget` abstract class.
- **`SpellBook.hpp` / `SpellBook.cpp`**: Declaration and implementation of the `SpellBook` class.
- **`TargetGenerator.hpp` / `TargetGenerator.cpp`**: Declaration and implementation of the `TargetGenerator` class.
- **Spell-specific files**: Declaration and implementation of concrete spell classes (`Fwoosh.hpp`, `Fwoosh.cpp`, `Fireball.hpp`, `Fireball.cpp`, `Polymorph.hpp`, `Polymorph.cpp`).
- **Target-specific files**: Declaration and implementation of concrete target classes (`Dummy.hpp`, `Dummy.cpp`, `BrickWall.hpp`, `BrickWall.cpp`).

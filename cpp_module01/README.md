# Warlock and Spell Casting

## Description

The `Warlock` class represents a mystical practitioner of arcane arts, capable of wielding powerful spells against their foes. In addition to the `Warlock` class, this module introduces abstract classes for spells (`ASpell`) and spell targets (`ATarget`), along with concrete implementations for specific spells and targets.

## Warlock Class

The `Warlock` class encapsulates the attributes and behavior of a warlock, including their name, title, and ability to cast spells.

### Class Structure

- **Private Attributes**:
  - `name` (string): The name of the warlock.
  - `title` (string): The title or epithet of the warlock.
  - `spells` (map<string, ASpell*>): A collection of spells known by the warlock, stored as key-value pairs where the key is the spell name and the value is a pointer to the corresponding `ASpell` object.

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

## ASpell Abstract Class

The `ASpell` class is an abstract base class for all spells cast by the warlock.

### Class Structure

- **Protected Attributes**:
  - `name` (string): The name of the spell.
  - `effects` (string): The effects of the spell.

- **Public Member Functions**:
  - `ASpell(std::string const &name, std::string const &effects)`: Constructor that initializes a spell with the given name and effects.
  - `virtual ~ASpell()`: Virtual destructor for proper polymorphic behavior.
  - `std::string const getName() const`: Getter function that returns the name of the spell.
  - `std::string const getEffects() const`: Getter function that returns the effects of the spell.
  - `virtual ASpell *clone() const = 0`: Pure virtual function for cloning the spell.
  - `void launch(ATarget const &target) const`: Function to launch the spell at a target.

## ATarget Abstract Class

The `ATarget` class is an abstract base class for all spell targets.

### Class Structure

- **Private Attributes**:
  - `type` (string): The type of the target.

- **Public Member Functions**:
  - `ATarget(std::string const &type)`: Constructor that initializes a target with the given type.
  - `virtual ~ATarget()`: Virtual destructor for proper polymorphic behavior.
  - `std::string const getType() const`: Getter function that returns the type of the target.
  - `virtual ATarget *clone() const = 0`: Pure virtual function for cloning the target.
  - `void getHitBySpell(ASpell const &spell) const`: Function to handle being hit by a spell.

## Concrete Spell Implementations

- **Fwoosh**: A concrete implementation of the `ASpell` class representing a basic spell. Default constructor sets the name to "Fwoosh" and the effects to "fwooshed".

## Concrete Target Implementations

- **Dummy**: A concrete implementation of the `ATarget` class representing a practice target. Constructor sets the type to "Target Practice Dummy".

## Usage

To create a warlock and interact with spells and targets, follow these steps:

1. **Instantiate a Warlock**: Create a `Warlock` object with a name and title.
2. **Learn Spells**: Use the `learnSpell()` function to teach the warlock new spells.
3. **Cast Spells**: Launch spells using the `launchSpell()` function.
4. **Forget Spells**: Remove spells from the warlock's repertoire with `forgetSpell()`.
5. **Interact with Targets**: Spells interact with targets via the `getHitBySpell()` function in the `ATarget` class.

## File Structure

- **`Warlock.hpp` / `Warlock.cpp`**: Declaration and implementation of the `Warlock` class.
- **`ASpell.hpp` / `ASpell.cpp`**: Declaration and implementation of the `ASpell` abstract class.
- **`ATarget.hpp` / `ATarget.cpp`**: Declaration and implementation of the `ATarget` abstract class.
- **`Fwoosh.hpp` / `Fwoosh.cpp`**: Declaration and implementation of the `Fwoosh` concrete spell class.
- **`Dummy.hpp` / `Dummy.cpp`**: Declaration and implementation of the `Dummy` concrete target class.

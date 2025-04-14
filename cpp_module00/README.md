# Warlock Class

## Description

The `Warlock` class represents a powerful sorcerer in a magical world. It encapsulates the attributes and behavior of a warlock, including their name, title, and ability to introduce themselves.

## Class Structure

The `Warlock` class consists of the following components:

- **Private Attributes**:
  - `name` (string): The name of the warlock.
  - `title` (string): The title or epithet of the warlock.

- **Public Member Functions**:
  - `Warlock(std::string const name, std::string const title)`: Constructor that initializes a warlock with the given name and title.
  - `~Warlock()`: Destructor that prints a message when the warlock's life cycle ends.
  - `std::string const getName() const`: Getter function that returns the name of the warlock.
  - `std::string const getTitle() const`: Getter function that returns the title of the warlock.
  - `void setTitle(std::string const &title)`: Setter function that sets the title of the warlock.
  - `void introduce() const`: Function that displays an introduction message, including the name and title of the warlock.

## Usage

To create and interact with a `Warlock` object, follow these steps:

1. **Instantiate a Warlock**: Create a `Warlock` object by providing a name and a title.
   ```cpp
   Warlock const richard("Richard", "Mistress of Magma");
   ```

2. **Access Attributes**: Retrieve the name and title of the warlock using the `getName()` and `getTitle()` functions.
   ```cpp
   std::cout << richard.getName() << " - " << richard.getTitle() << std::endl;
   ```

3. **Modify Title**: Update the title of the warlock using the `setTitle()` function.
   ```cpp
   Warlock* jack = new Warlock("Jack", "the Long");
   jack->setTitle("the Mighty");
   ```

4. **Introduction**: Display an introduction message for the warlock using the `introduce()` function.
   ```cpp
   richard.introduce();
   ```

5. **Cleanup**: Ensure proper memory management by deleting dynamically allocated objects.
   ```cpp
   delete jack;
   ```

## Example Output

```plaintext
Richard: This looks like another boring day.
Richard: I am Richard, Mistress of Magma!
Richard - Mistress of Magma
Jack: This looks like another boring day.
Jack: I am Jack, the Long!
Jack: I am Jack, the Mighty!
Jack: My job here is done!
Richard: My job here is done!
```

## File Structure

The `Warlock` class implementation is divided into two files:

- **`Warlock.hpp`**: Header file containing the class declaration.
- **`Warlock.cpp`**: Source file containing the implementation of the class member functions.


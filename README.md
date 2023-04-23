# Contact List Manager CLI

This is a command-line interface (CLI) program that allows the user to manage a contact list. It is written in C and stores the contact list on disk.

## Features

- Add a new contact (name, email, phone number)
- List all contacts
- Search for a contact by name
- Update an existing contact's information
- Delete a contact
- Save the contact list to disk
- Load the contact list from disk on startup
- Automatically save new contacts to disk

## Requirements

- C compiler (GCC or Clang recommended)
- Make utility (to build the program)

## Usage

To build the program, run the following command:

```bash
make
```

To run the program, use the following command:

```bash
./contact_manager
```

The program will display a menu with the available operations. Follow the prompts to perform the desired operation.

The contact list is saved to a file called contacts.txt in the same directory as the program. When the program starts, it will load any existing contacts from this file.

## Notes

- Proper error handling is implemented for user input and file operations.
- The code is well-organized and commented for readability.
- New contacts are automatically saved to the contacts.txt file.
- The contact list is saved in a simple comma-separated value (CSV) format.

## Author
- ...
- Max Base

## License

This program is licensed under the GPL-3.0 License.

Copyright 2023, Max Base

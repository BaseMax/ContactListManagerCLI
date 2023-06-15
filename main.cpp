/*
 *    @Author:   MaximilianEdison (MaxianEdison)
 *    @Date:     2023-06-15 06:39:51
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <limits>

#ifdef _WIN32
#define CLEAR_COMMAND "cls"
#else
#define CLEAR_COMMAND "clear"
#endif

/**
 * @brief Contact class.
 *
 */
class Contact
{
private:
    std::string name;
    std::string email;
    std::string phone;

public:
    Contact(const std::string &name, const std::string &email, const std::string &phone)
        : name(name), email(email), phone(phone) {}

    const std::string &getName() const
    {
        return name;
    }

    const std::string &getEmail() const
    {
        return email;
    }

    const std::string &getPhone() const
    {
        return phone;
    }

    void display() const
    {
        std::cout << name << ", " << email << ", " << phone << std::endl;
    }

    static Contact createFromUserInput()
    {
        std::string name, email, phone;

        while (true)
        {
            std::cout << "Enter name: ";
            std::getline(std::cin, name);
            if (!name.empty())
            {
                break;
            }
            std::cout << "Name can't be empty. Please try again." << std::endl;
        }

        while (true)
        {
            std::cout << "Enter email: ";
            std::getline(std::cin, email);
            if (ifValidEmail(email))
            {
                break;
            }
            std::cout << "Invalid email format. Please try again." << std::endl;
        }

        while (true)
        {
            std::cout << "Enter phone number: ";
            std::getline(std::cin, phone);
            if (isValidPhoneNumber(phone))
            {
                break;
            }
            std::cout << "Invalid email format. Please try again." << std::endl;
        }

        return Contact(name, email, phone);
    }

    static bool ifValidEmail(const std::string &email)
    {
        // TODO: write email validator.
        return !email.empty();
    }

    static bool isValidPhoneNumber(const std::string &email)
    {
        // TODO: write phone validator.
        return !email.empty();
    }
};

/**
 * @brief Clear terminal screen based on OS (Windows or Unix).
 *
 */
void clearScreen()
{
    std::system(CLEAR_COMMAND);
}

/**
 * @brief Display menu for user.
 *
 */
void displayMenu()
{
    std::cout << "Contact List Manager" << std::endl;
    std::cout << "\nSelect and option:" << std::endl;
    std::cout << "1. Add new contact" << std::endl;
    std::cout << "2. List all contact" << std::endl;
    std::cout << "3. Search for a contact" << std::endl;
    std::cout << "4. Update a contact" << std::endl;
    std::cout << "5. Delete a contact" << std::endl;
    std::cout << "6. Quit" << std::endl;
}

/**
 * @brief Add contact to contacts.csv file.
 *
 * @param contacts
 */
void addContact(std::vector<Contact> &contacts)
{
    clearScreen();
    std::cout << "Add a new Contact" << std::endl;
    Contact contact = Contact::createFromUserInput();
    contacts.push_back(contact);
    std::cout << "\nContact added successfully!" << std::endl;
}

/**
 * @brief List all contacts.
 *
 * @param contacts
 */
void listContacts(const std::vector<Contact> &contacts)
{
    clearScreen();
    std::cout << "List of all contacts" << std::endl;
    for (const Contact &contact : contacts)
    {
        contact.display();
    }
}

/**
 * @brief Search for contacts in contacts.csv file.
 *
 * @param contacts
 */
void searchContact(const std::vector<Contact> &contacts)
{
    clearScreen();
    std::cout << "Search for contact" << std::endl;
    std::string searhTerm;
    std::cout << "Enter search term: ";
    std::getline(std::cin, searhTerm);

    bool found = false;
    std::cout << "\nSearch results:" << std::endl;
    for (const Contact &contact : contacts)
    {
        if (contact.getName().find(searhTerm) != std::string::npos ||
            contact.getEmail().find(searhTerm) != std::string::npos ||
            contact.getPhone().find(searhTerm) != std::string::npos)
        {
            contact.display();
            found = true;
        }
    }
    if (!found)
        std::cout << "No matching contacts found." << std::endl;
}

/**
 * @brief Update info for one contact.
 *
 * @param contacts
 */
void updateContact(std::vector<Contact> &contacts)
{
    clearScreen();
    std::cout << "Update contact" << std::endl;
    std::string searchTerm;
    std::cout << "Enter the name of the contact to update: ";
    std::getline(std::cin, searchTerm);

    bool found = false;
    for (Contact &contact : contacts)
    {
        if (contact.getName() == searchTerm)
        {
            contact = Contact::createFromUserInput();
            std::cout << "\nContact updated successfully!" << std::endl;
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "Contact not found." << std::endl;
}

/**
 * @brief Delete contact from contacts.csv file.
 *
 * @param contacts
 */
void deleteContact(std::vector<Contact> &contacts)
{
    clearScreen();
    std::cout << "Delete a contact" << std::endl;
    std::string searchTerm;
    std::cout << "Enter the name of the contact to delete: ";
    std::getline(std::cin, searchTerm);

    bool found = false;
    for (auto it = contacts.begin(); it != contacts.end(); ++it)
    {
        if (it->getName() == searchTerm)
        {
            contacts.erase(it);
            std::cout << "\nContact deleted successfully!" << std::endl;
            found = true;
            break;
        }
    }
    if (!found)
        std::cout << "Contact not found." << std::endl;
}

/**
 * @brief When program exit save contacts to disk.
 *
 * @param contacts
 * @param filename
 */
void saveContacts(const std::vector<Contact> &contacts, const std::string &filename)
{
    std::ofstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file for writing." << std::endl;
        return;
    }

    for (const Contact &contact : contacts)
    {
        file << contact.getName() << "," << contact.getEmail() << "," << contact.getPhone() << std::endl;
    }

    file.close();
}

/**
 * @brief When programm run load contacts to memory.
 *
 * @param filename
 * @return std::vector<Contact>
 */
std::vector<Contact> loadContacts(const std::string &filename)
{
    std::vector<Contact> contacts;

    std::ifstream file(filename);
    if (!file)
    {
        std::cerr << "Error opening file for reading." << std::endl;
        return contacts;
    }

    std::string line;
    while (std::getline(file, line))
    {
        size_t pos1 = line.find(",");
        size_t pos2 = line.rfind(",");
        if (pos1 != std::string::npos && pos2 != std::string::npos)
        {
            std::string name = line.substr(0, pos1);
            std::string email = line.substr(pos1 + 1, pos2 - pos1 - 1);
            std::string phone = line.substr(pos2 + 1);
            contacts.push_back(Contact(name, email, phone));
        }
    }

    file.close();
    return contacts;
}

int main()
{
    const std::string filename = "contacts.csv";
    std::vector<Contact> contacts = loadContacts(filename);

    int choice;
    while (true)
    {
        clearScreen();
        displayMenu();
        std::cout << "\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch (choice)
        {
        case 1:
            addContact(contacts);
            break;
        case 2:
            listContacts(contacts);
            break;
        case 3:
            searchContact(contacts);
            break;
        case 4:
            updateContact(contacts);
            break;
        case 5:
            deleteContact(contacts);
            break;
        case 6:
            saveContacts(contacts, filename);
            clearScreen();
            std::cout << "Goodbye!" << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
            break;
        }

        std::cout << "\nPress Enter to continue...";
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
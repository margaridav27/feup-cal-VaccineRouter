#include <fstream>
#include "Interface.h"

bool Interface::checkInRange(int optionsRange, int input) {
    return (input >= 1 && input <= optionsRange);
}

bool Interface::checkFilenameValidity(const std::string& filename) {
    std::ifstream istream("../../cityMaps/" + filename + "/" + filename + "_strong_edges.txt"); // comback
    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        return false;
    }
    istream.close();
    return true;
}

bool Interface::checkGeneralInputValidity(int optionsRange, int input) {
    if (checkInRange(optionsRange, input)) return true;

    std::cin.clear();
    std::cin.ignore(100000, '\n');

    std::cerr << "Invalid input. Please choose again.\n\n";
    return false;
}

std::vector<int> Interface::checkACSelectionValidity(bool multiple, int optionsRange) {
    int input;
    std::vector<int> selected;

    while (std::cin.peek() != std::cin.eof()) {
        std::cin >> input;

        // invalid input error
        if (std::cin.fail() || !checkInRange(optionsRange, input)) {
            std::cerr << "Invalid input. Please choose again.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // multiple inputs when only single was permitted error
        if (!multiple && std::cin.peek() != std::cin.eof()) {
            std::cerr << "You chose more than one Application Center.\n"
                         "Please make sure to choose only one.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // updates return vector with selected option
        selected.push_back(input);
    }

    return selected;
}

Interface::Interface() { this->vaccineRouter = new VaccineRouter(); }

void Interface::initInterface() { initialMenu(); }

// todo: this method will be responsible to actually run VaccineRouter given the previous selections
void Interface::initApplication() {

}

void Interface::initialMenu() {
    int input;
    do {
        std::cout << "1. Run Program\n"
                     "2. Exit\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (!checkGeneralInputValidity(2, input) && std::cin.fail());

    switch (input) { //comback
        case 1: runProgramMenu();
        default: return;
    }
}

void Interface::runProgramMenu() {
    int input;
    do {
        std::cout << "1. Select Map\n"
                     "2. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (!checkGeneralInputValidity(2, input) && std::cin.fail());

    switch (input) {
        case 1: selectMapMenu();
        case 2: initialMenu();
        default: return;
    }
}

// todo: allow more options!!
// todo: fazer load para um array dos mapas existentes e depois percorrer
void Interface::selectMapMenu() {
    int input;
    int option = 1;
    do {
        std::cout << "1. Porto\n"
                     "2. Espinho\n"
                     "3. Penafiel\n"
                     "4. Exit\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (!checkGeneralInputValidity(4, input) && std::cin.fail());

    switch (input) {
        case 1: this->vaccineRouter->selectMap("porto");
        case 2: this->vaccineRouter->selectMap("espinho");
        case 3: this->vaccineRouter->selectMap("penafiel");
        case 4: return;
    }

    selectSingleOrMultipleACMenu();
}

void Interface::selectSingleOrMultipleACMenu() {
    int input;
    do {
        std::cout << "1. Single Application Center\n"
                     "2. Multiple Application Centers\n"
                     "3. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (checkGeneralInputValidity(3, input) && std::cin.fail());

    switch (input) {
        case 1:
            selectSingleACMenu();
        case 2:
            selectMultipleACMenu();
        case 3:
            selectMapMenu();
        default:
            return;
    }
}

// todo
void Interface::selectSingleACMenu() {
    std::vector<int> input;
    bool invalidInput;

    do {
        // todo: display all available application centers
        std::cout << "Please select the Application Center from the above list [usage: >2]: ";
        input = checkACSelectionValidity(false, 0); // todo: fix optionsRange

        invalidInput = input.empty();
        if (invalidInput) continue;

        // todo: finish

    } while (invalidInput);

    orderVaccinesMenu(input);
}

// todo
void Interface::selectMultipleACMenu() {
    std::vector<int> input;
    bool invalidInput;

    do {
        // todo: display all available application centers
        std::cout << "Please select the Application Center from the above list [usage: >2]: ";
        input = checkACSelectionValidity(true, 0); // todo: fix optionsRange

        invalidInput = input.empty();
        if (invalidInput) continue;

        // todo: finish

    } while (invalidInput);

    orderVaccinesMenu(input);
}

// todo
void Interface::orderVaccinesMenu(const std::vector<int> &selected) {
    initApplication();
}













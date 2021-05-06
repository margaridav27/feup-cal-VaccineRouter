#include "Interface.h"

bool Interface::checkInRange(int optionsRange, int input) {
    for (int i = 1; i <= optionsRange; ++i) {
        if (input == i) return true;
    }
    return false;
}

bool Interface::checkInputValidity(int optionsRange, int input) {
    if (checkInRange(optionsRange, input)) return true;

    std::cin.clear();
    std::cin.ignore(100000, '\n');

    std::cout << "Invalid input. Please choose again.\n\n";
    return false;
}

std::vector<int> Interface::checkACSelectionValidity(bool multiple, int optionsRange) {
    int input;
    std::vector<int> selected;

    while (std::cin.peek() != std::cin.eof()) {
        std::cin >> input;

        // invalid input error
        if (std::cin.fail() || !checkInRange(optionsRange, input)) {
            std::cout << "Invalid input. Please choose again.\n\n";
            return std::vector<int>();
        }

        // multiple inputs when only single was permitted error
        if (!multiple && std::cin.peek() != std::cin.eof()) {
            std::cout << "You chose more than one Application Center.\n"
                         "Please make sure to choose only one.\n\n";
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
        std::cout << "1. Load Map\n"
                     "2. Run Program\n"
                     "3. Exit\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (checkInputValidity(3, input) && std::cin.fail());

    switch (input) {
        case 1:
            loadMapMenu();
        case 2:
            runProgramMenu();
        default:
            return;
    }
}

// todo
void Interface::loadMapMenu() {
    int input;
    do {
        std::cout << "Map's text file path (CTRL-C to go back): ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (1);
}

void Interface::runProgramMenu() {
    int input;
    do {
        std::cout << "1. Select Map\n"
                     "2. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (checkInputValidity(2, input) && std::cin.fail());

    switch (input) {
        case 1:
            selectMapMenu();
        case 2:
            initialMenu();
        default:
            return;
    }
}

// todo
void Interface::selectMapMenu() {
    int input;
    do {
        // todo: display all available map options
        std::cout << "Please select your option: ";
        std::cin >> input;
        std::cout << "\n\n";
    } while (checkInputValidity(3, input) && std::cin.fail());

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
    } while (checkInputValidity(3, input) && std::cin.fail());

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











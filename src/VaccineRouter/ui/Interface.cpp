#include "Interface.h"
#include <fstream>

bool Interface::checkInRange(int optionsRange, int input) {
    return (input >= 1 && input <= optionsRange);
}

bool Interface::checkGeneralInputValidity(int optionsRange, int input) {
    if (checkInRange(optionsRange, input))
        return true;

    std::cin.clear();
    std::cin.ignore(100000, '\n');

    std::cerr << "Invalid input. Please choose again.\n\n";
    return false;
}

std::vector<int> Interface::checkACSelectionValidity(bool multiple,
                                                     int optionsRange) {
    int input = 0;
    bool read = false;
    std::vector<int> selected;

    while (!read || !checkInRange(optionsRange, input)) {
        std::cin >> input;

        // invalid input error
        if (std::cin.fail() || !checkInRange(optionsRange, input)) {
            std::cerr << "Invalid input. Please choose again.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // multiple inputs when only single was permitted error
        if (!multiple && std::cin.eof()) {
            std::cerr << "You chose more than one Application Center.\n"
                         "Please make sure to choose only one.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        } else {
            read = true;
        }

        // updates return vector with selected option
        selected.push_back(input);
    }

    return selected;
}

std::vector<std::pair<int, std::string>> Interface::getAvailableACs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        std::vector<std::pair<int, std::string>>();
    }

    std::vector<std::pair<int, std::string>> options;

    unsigned int id;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        std::pair<int, std::string> acData(id, name);
        options.push_back(acData);
    }

    istream.close();
    return options;
}

std::vector<std::pair<int, std::string>> Interface::getAvailableSCs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cerr << "File does not exist or could not be open.\n\n";
        std::vector<std::pair<int, std::string>>();
    }

    std::vector<std::pair<int, std::string>> options;

    unsigned int id;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        std::pair<int, std::string> acData(id, name);
        options.push_back(acData);
    }

    istream.close();
    return options;
}

void Interface::displayAvailableSCs(std::vector<std::pair<int, std::string>> &options) {
    if (options.empty())
        std::cout << "There are no available Storage Centers.\n";
    else {
        for (int i = 0; i < options.size(); ++i)
            std::cout << i << ". " << options[i].second << '\n';
    }
}

void Interface::displayAvailableACs(std::vector<std::pair<int, std::string>> &options) {
    if (options.empty())
        std::cout << "There are no available Storage Centers.\n";
    else {
        for (int i = 0; i < options.size(); ++i)
            std::cout << i << ". " << options[i].second << '\n';
    }
}

Interface::Interface() { this->vaccineRouter = new VaccineRouter(); }

void Interface::initInterface() { initialMenu(); }

void Interface::initialMenu() {
    int input;
    do {
        std::cout << "----- INITIAL MENU -----\n"
                     "1. Run Program\n"
                     "2. Modify Data\n"
                     "3. Exit\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n";
    } while (!checkGeneralInputValidity(3, input) && std::cin.fail());

    switch (input) {
        case 1:
            runProgramMenu();
        case 2:
            modifyDataMenu();
        default:
            return;
    }
}

void Interface::runProgramMenu() {
    int input;
    do {
        std::cout << "----- RUN PROGRAM MENU -----\n"
                     "1. Select Map\n"
                     "2. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n";
    } while (!checkGeneralInputValidity(2, input) && std::cin.fail());

    switch (input) {
        case 1:
            selectMapMenu();
        case 2:
            initialMenu();
        default:
            return;
    }
}

void Interface::modifyDataMenu() {
    int chosenCityIx;
    int optionCounter = 1;
    std::vector<std::string> cityOptions;

    do {
        // file containing the names of the available cities
        std::ifstream istream("../../cityMaps/availableCities.txt");

        if (!istream.is_open()) {
            std::cerr << "File containing the available cities could not be open.\n\n";
            return;
        }

        std::cout << "----- MODIFY DATA MENU - MAP SELECTION -----\n";
        std::string cityName;

        std::cin.ignore(100000, '\n');
        while (getline(istream, cityName)) {
            std::cout << optionCounter << ". " << cityName << '\n';
            cityOptions.push_back(cityName);
            optionCounter++;
        }

        istream.close();

        std::cout << optionCounter << ". Go Back\n\n"
                                      "Please select your option: ";
        std::cin >> chosenCityIx;
        std::cout << "\n";
    } while (!checkGeneralInputValidity(optionCounter, chosenCityIx) && std::cin.fail());

    if (chosenCityIx == optionCounter) initialMenu(); // chose to go back
    std::string chosenCityStr = cityOptions[chosenCityIx - 1];

    int input;
    do {
        std::cout << "----- MODIFY DATA MENU -----\n"
                     "1. Add Application Center\n"
                     "2. Add Storage Center\n"
                     "3. Remove Application Center\n"
                     "4. Remove Storage Center\n"
                     "5. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n";
    } while (!checkGeneralInputValidity(5, input) && std::cin.fail());

    switch (input) {
        case 1:
            addCenterMenu(false, chosenCityStr);
        case 2:
            addCenterMenu(true, chosenCityStr);
        case 3:
            removeCenterMenu(false, chosenCityStr);
        case 4:
            removeCenterMenu(true, chosenCityStr);
        case 5:
            modifyDataMenu();
        default:
            return;
    }
}

void Interface::addCenterMenu(bool sc, const std::string &mapFilename) {

}

void Interface::removeCenterMenu(bool sc, const std::string &mapFilename) {
    int input;
    std::vector<std::pair<int, std::string>> options;

    // sc variable controls whether the user is about to remove a SC or not
    if (sc) {
        do {
            options = getAvailableSCs(mapFilename);
            displayAvailableSCs(options);
            std::cout << options.size() << ". Go Back\n\n"
                                           "Select one of the following Storage Centers to remove: ";
            std::cin >> input;
        } while (checkInRange(options.size(), input) && std::cin.fail());

        if (input == options.size()) modifyDataMenu();

        std::cout << "Your option is being processed...\n\n";

        options.erase(options.begin() + input - 1);

        std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_SCs.txt", std::ios::trunc);
        if (!ostream.is_open()) {
            std::cerr << "File does not exist or could not be open.\n\n";
            return;
        }

        // outputting remaining options to the file
        for (const std::pair<int, std::string> &op : options) ostream << op.first << ' ' << op.second << '\n';

        std::cout << "Storage Center successfully removed!\n\n";
    } else {
        do {
            options = getAvailableACs(mapFilename);
            displayAvailableACs(options);
            std::cout << options.size() << ". Go Back\n\n"
                                           "Select one of the following Application Centers to remove: ";
            std::cin >> input;
        } while (checkInRange(options.size(), input) && std::cin.fail());

        if (input == options.size()) modifyDataMenu();

        std::cout << "Your option is being processed...\n\n";
        options.erase(options.begin() + input - 1);

        std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_ACs.txt", std::ios::trunc);
        if (!ostream.is_open()) {
            std::cerr << "File does not exist or could not be open.\n\n";
            return;
        }

        // outputting remaining options to the file
        for (const std::pair<int, std::string> &op : options) ostream << op.first << ' ' << op.second << '\n';

        std::cout << "Application Center successfully removed!\n\n";
    }

    modifyDataMenu();
}

void Interface::selectMapMenu() {
    int input;
    int optionCounter = 1;
    std::vector<std::string> options;
    do {
        // file containing the names of the available cities
        std::ifstream istream("../../cityMaps/availableCities.txt");

        if (!istream.is_open()) {
            std::cerr
                    << "File containing the available cities could not be open.\n\n";
            return;
        }

        std::cout << "----- AVAILABLE CITIES -----\n";
        std::string cityName;

        std::cin.ignore(100000, '\n');
        while (getline(istream, cityName)) {
            std::cout << optionCounter << ". " << cityName << '\n';
            options.push_back(cityName);
            optionCounter++;
        }

        istream.close();

        std::cout << optionCounter << ". Go Back\n\n"
                                      "Please select your option: ";
        std::cin >> input;
        std::cout << "\n";
    } while (!checkGeneralInputValidity(optionCounter, input) && std::cin.fail());

    if (input == optionCounter)
        runProgramMenu(); // user chose to go back
    this->vaccineRouter->selectMap(options[input - 1]);
    this->vaccineRouter->setCityName(options[input - 1]);
    selectSingleOrMultipleACMenu(options[input - 1]);
}

void Interface::selectSingleOrMultipleACMenu(const std::string &mapFilename) {
    int input;
    do {
        std::cout << "----- SINGLE OR MULTIPLE APPLICATION CENTER SELECTION -----\n"
                     "1. Single Application Center\n"
                     "2. Multiple Application Centers\n"
                     "3. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
        std::cout << "\n";
    } while (checkGeneralInputValidity(3, input) && std::cin.fail());

    switch (input) {
        case 1:
            selectSingleACMenu(mapFilename);
        case 2:
            selectMultipleACMenu(mapFilename);
        case 3:
            selectMapMenu();
        default:
            return;
    }
}

void Interface::selectSingleACMenu(const std::string &mapFilename) {
    std::vector<int> selected;
    bool invalidInput = false;
    std::vector<std::pair<int, std::string>> availableACs;

    do {
        availableACs = getAvailableACs(mapFilename);
        std::cout << "----- SINGLE APPLICATION CENTER -----\n";
        displayAvailableACs(availableACs);
        std::cout << "Please select the Application Center from the above list "
                     "[usage: >2]: ";
        selected = checkACSelectionValidity(false, availableACs.size());
        invalidInput = selected.empty();
    } while (invalidInput);

    orderVaccinesMenu(availableACs, selected);
    singleAC();
}

void Interface::selectMultipleACMenu(const std::string &mapFilename) {
    std::vector<int> selected;
    bool invalidInput = false;
    std::vector<std::pair<int, std::string>> availableACs;

    do {
        availableACs = getAvailableACs(mapFilename);
        std::cout << "----- MULTIPLE APPLICATION CENTERS -----\n";
        displayAvailableACs(availableACs);
        std::cout << "Please select the Application Center from the above list "
                     "[usage: >2 3 4]: ";
        selected = checkACSelectionValidity(true, availableACs.size());
        invalidInput = selected.empty();
    } while (invalidInput);

    orderVaccinesMenu(availableACs, selected);
    multipleAC();
}

void Interface::orderVaccinesMenu(std::vector<std::pair<int, std::string>> &options, const std::vector<int> &selected) {
    int order;
    std::cout << "----- ORDER VACCINES MENU -----\n";
    for (int i : selected) {
        std::cout << "Vaccine's order for " << options[i].second << ": ";
        std::cin >> order;

        Node *acNode = this->vaccineRouter->getGraph()->getNode(options[i].first);
        std::string acName = options[i].second;
        auto *newAC = new ApplicationCenter(acNode, acName);
        newAC->setVaccinesToReceive(order);
        this->vaccineRouter->addApplicationCenter(newAC);
    }
}

// TODO Apply method and display
void Interface::singleAC() {
    vaccineRouter->calculateRouteSingleSCSingleAC();
    //vaccineRouter->displayOutput();
}

// TODO Apply both methods and display
void Interface::multipleAC() {
    vaccineRouter->calculateRouteSingleSCMultipleAC();
}

void Interface::multipleACWithTW() {
    vaccineRouter->calculateRouteSingleSCMultipleACWithTW();
    vaccineRouter->calculateRouteMultipleSCMultipleACWithTW();
}

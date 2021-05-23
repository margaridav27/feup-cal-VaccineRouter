#include "Interface.h"
#include "../graph/GraphProcessor.h"
#include <fstream>

bool Interface::checkCinFail() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        return false;
    }
    return true;
}

bool Interface::checkInRange(int optionsRange, int input) {
    return (input >= 1 && input <= optionsRange);
}

bool Interface::checkGeneralInputValidity(int optionsRange, int input) {
    if (checkInRange(optionsRange, input))
        return true;

    std::cout << "[VaccineRouter] Invalid input. Please choose again.";
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
        if (!checkCinFail() || !checkInRange(optionsRange, input)) {
            std::cout << "[VaccineRouter] Invalid input. Please choose again.";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // multiple inputs when only single was permitted error
        if (!multiple && std::cin.eof()) {
            std::cout << "[VaccineRouter] You chose more than one Application Center. "
                         "Please make sure to choose only one.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        } else read = true;

        // updates return vector with selected option
        selected.push_back(input);
    }

    return selected;
}

std::vector<std::pair<int, std::string>> Interface::getAvailableACs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        std::vector<std::pair<int, std::string>>();
    }

    std::vector<std::pair<int, std::string>> options;

    unsigned int id;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        options.emplace_back(id, name);
    }

    istream.close();
    return options;
}

std::vector<std::pair<int, std::string>> Interface::getAvailableSCs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        std::vector<std::pair<int, std::string>>();
    }

    std::vector<std::pair<int, std::string>> options;

    unsigned int id;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        options.emplace_back(id, name);
    }

    istream.close();
    return options;
}

std::map<int, std::string> Interface::getAvailableCities() {
    std::ifstream istream("../../cityMaps/availableCities.txt");
    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File containing the available cities could not be open.";
        return std::map<int, std::string>();
    }

    std::map<int, std::string> availableCities;
    std::string cityName;
    int optionCounter = 1;
    while (getline(istream, cityName)) {
        availableCities.insert(std::pair<int, std::string>(optionCounter, cityName));
        optionCounter++;
    }

    istream.close();
    return availableCities;
}

void Interface::displayAvailableSCs(std::vector<std::pair<int, std::string>> &options) {
    if (options.empty())
        std::cout << "[VaccineRouter] There are no available Storage Centers.";
    else {
        for (int i = 0; i < options.size(); ++i)
            std::cout << i + 1 << ". " << options[i].second << '\n';
    }
}

void Interface::displayAvailableACs(std::vector<std::pair<int, std::string>> &options) {
    if (options.empty())
        std::cout << "[VaccineRouter] There are no available Storage Centers.";
    else {
        for (int i = 0; i < options.size(); ++i)
            std::cout << i + 1 << ". " << options[i].second << '\n';
    }
}

void Interface::displayAvailableCities(std::map<int, std::string> cities) {
    for (const auto& op : cities) {
        std::cout << op.first << ". " << op.second << '\n';
    }
}

Interface::Interface() { this->vaccineRouter = new VaccineRouter(); }

void Interface::initInterface() { initialMenu(); }

void Interface::initialMenu() {
    int initialMenuInput = 0;
    do {
        std::cout << "\n----- INITIAL MENU -----\n"
                     "1. Run Program\n"
                     "2. Analyse Connectivity\n"
                     "3. Modify Data\n"
                     "4. Exit\n\n"
                     "Please select your option: ";
        std::cin >> initialMenuInput;
    } while (!checkCinFail() || !checkGeneralInputValidity(4, initialMenuInput));

    switch (initialMenuInput) {
        case 1: runProgramMenu();
        case 2: analyseConnectivityMenu();
        case 3: modifyDataMenu();
        default: return;
    }
}

void Interface::runProgramMenu() {
    int runProgramMenuInput = 0;
    do {
        std::cout << "\n----- RUN PROGRAM MENU -----\n"
                     "1. Select Map\n"
                     "2. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> runProgramMenuInput;
    } while (!checkCinFail() || !checkGeneralInputValidity(2, runProgramMenuInput));

    switch (runProgramMenuInput) {
        case 1: selectMapMenu();
        case 2: initialMenu();
        default: return;
    }
}

void Interface::analyseConnectivityMenu() {
    int input = 0;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n----- AVAILABLE CITIES TO ANALYSE CONNECTIVITY -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter << ". Go Back\n\n"
                                      "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) initialMenu(); // user chose to go back

    std::string mapFilename = availableCities.find(input)->second;
    Graph *graph = processGraph(mapFilename, false);
    // TODO: display graph before being processed
    graph->DFSConnectivity(graph->getNodeSet()[0]);
    graph->removeUnvisitedNodes();
    // TODO: display graph after connectivity analysis

    initialMenu();
}

void Interface::modifyDataMenu() {
    int input;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n----- MODIFY DATA MENU - MAP SELECTION -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter << ". Go Back\n\n"
                                      "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) initialMenu(); // user chose to go back

    std::string chosenCity = availableCities.find(input)->second;
    input = 0;

    do {
        std::cout << "\n----- MODIFY DATA MENU -----\n"
                     "1. Add Application Center\n"
                     "2. Add Storage Center\n"
                     "3. Remove Application Center\n"
                     "4. Remove Storage Center\n"
                     "5. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(5, input));

    switch (input) {
        case 1: addACMenu(chosenCity);
        case 2: addSCMenu(chosenCity);
        case 3: removeACMenu(chosenCity);
        case 4: removeSCMenu(chosenCity);
        case 5: modifyDataMenu();
        default: return;
    }
}

void Interface::addSCMenu(const std::string &mapFilename) {
    bool alreadyExists = false;
    int newID;
    std::string newName;

    std::vector<std::pair<int, std::string>> availableACs;
    std::vector<std::pair<int, std::string>> availableSCs;

    do {
        std::cout << "\n----- ADD STORAGE CENTER MENU -----\n"
                     "Introduce the ID of the node about to become a Storage Center: ";
        std::cin >> newID;
        std::cin.ignore();

        availableACs = getAvailableACs(mapFilename);
        availableSCs = getAvailableSCs(mapFilename);

        // checking the existent ACs
        for (const std::pair<int, std::string>& op : availableACs) {
            if (newID == op.first) {
                alreadyExists = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to an Application Center.";
                break;
            }
        }

        // checking the existent SCs
        for (const std::pair<int, std::string>& op : availableSCs) {
            if (newID == op.first) {
                alreadyExists = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to a Storage Center.";
                break;
            }
        }

        if (!alreadyExists) {
            std::cout << "Introduce a name for the Storage Center: ";
            std::getline(std::cin, newName);

            std::cout << "[VaccineRouter] Your option is being processed...";

            std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_SCs.txt", std::fstream::app);
            if (!ostream.is_open()) {
                std::cout << "[VaccineRouter] File does not exist or could not be open.";
                return;
            }
            ostream << newID << ' ' << newName << '\n';
            ostream.close();

            std::cout << "[VaccineRouter] Storage Center successfully added!";
            break;
        }
    } while (true);

    modifyDataMenu();
}

void Interface::addACMenu(const std::string &mapFilename) {
    bool alreadyExists = false;
    int newID;
    std::string newName;
    std::vector<std::pair<int, std::string>> availableACs;
    std::vector<std::pair<int, std::string>> availableSCs;

    do {
        std::cout << "\n----- ADD APPLICATION CENTER MENU -----\n"
                     "Introduce the ID of the node about to become an Application Center: ";
        std::cin >> newID;
        std::cin.ignore();

        availableACs = getAvailableACs(mapFilename);
        availableSCs = getAvailableSCs(mapFilename);

        for (const std::pair<int, std::string>& op : availableACs) {
            if (newID == op.first) {
                alreadyExists = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to an Application Center.";
                break;
            }
        }

        for (const std::pair<int, std::string>& op : availableSCs) {
            if (newID == op.first) {
                alreadyExists = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to a Storage Center.";
                break;
            }
        }

        if (!alreadyExists) {
            std::cout << "Introduce a name for the Application Center: ";
            std::getline(std::cin, newName);

            std::cout << "[VaccineRouter] Your option is being processed...";

            std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_ACs.txt", std::fstream::app);
            if (!ostream.is_open()) {
                std::cout << "[VaccineRouter] File does not exist or could not be open.";
                return;
            }
            ostream << newID << ' ' << newName << '\n';
            ostream.close();

            std::cout << "[VaccineRouter] Application Center successfully added!";
            break;
        }
    } while (true);

    modifyDataMenu();
}

void Interface::removeSCMenu(const std::string &mapFilename) {
    int removeSCMenuInput = 0;
    std::vector<std::pair<int, std::string>> options;

    do {
        std::cout << "\n----- REMOVE STORAGE CENTER MENU -----\n";
        options = getAvailableSCs(mapFilename);
        displayAvailableSCs(options);
        std::cout << options.size() + 1 << ". Go Back\n\n"
                                       "Select one of the following Storage Centers to remove: ";
        std::cin >> removeSCMenuInput;
    } while (checkCinFail() || !checkInRange(options.size() + 1, removeSCMenuInput));

    if (removeSCMenuInput == options.size() + 1) modifyDataMenu();

    std::cout << "[VaccineRouter] Your option is being processed...";

    options.erase(options.begin() + removeSCMenuInput - 1);
    std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_SCs.txt", std::fstream::trunc);
    if (!ostream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        return;
    }
    // outputting remaining options to the file
    for (const std::pair<int, std::string> &op : options) ostream << op.first << ' ' << op.second << '\n';
    ostream.close();

    std::cout << "[VaccineRouter] Storage Center successfully removed!";

    modifyDataMenu();
}

void Interface::removeACMenu(const std::string &mapFilename) {
    int removeACMenuInput = 0;
    std::vector<std::pair<int, std::string>> options;

    do {
        std::cout << "\n----- REMOVE APPLICATION CENTER MENU -----\n";
        options = getAvailableACs(mapFilename);
        displayAvailableACs(options);
        std::cout << options.size() + 1 << ". Go Back\n\n"
                                       "Select one of the following Application Centers to remove: ";
        std::cin >> removeACMenuInput;
    } while (!checkCinFail() || !checkInRange(options.size() + 1, removeACMenuInput));

    if (removeACMenuInput == options.size() + 1) modifyDataMenu();

    std::cout << "[VaccineRouter] Your option is being processed...";

    options.erase(options.begin() + removeACMenuInput - 1);
    std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename + "_ACs.txt", std::fstream::trunc);
    if (!ostream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        return;
    }
    // outputting remaining options to the file
    for (const std::pair<int, std::string> &op : options) ostream << op.first << ' ' << op.second << '\n';
    ostream.close();

    std::cout << "[VaccineRouter] Application Center successfully removed!";
    modifyDataMenu();
}

void Interface::selectMapMenu() {
    int input = 0;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n----- AVAILABLE CITIES -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter << ". Go Back\n\n"
                                      "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) runProgramMenu(); // user chose to go back

    std::string mapFilename = availableCities.find(input)->second;
    this->vaccineRouter->selectMap(mapFilename);
    this->vaccineRouter->setCityName(mapFilename);
    selectSingleOrMultipleACMenu(mapFilename);
}

void Interface::selectSingleOrMultipleACMenu(const std::string &mapFilename) {
    int selectSingleOrMultipleACMenuInput = 0;
    do {
        std::cout << "\n----- SINGLE OR MULTIPLE APPLICATION CENTER SELECTION -----\n"
                     "1. Single Application Center\n"
                     "2. Multiple Application Centers\n"
                     "3. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> selectSingleOrMultipleACMenuInput;
    } while (!checkCinFail() || !checkGeneralInputValidity(3, selectSingleOrMultipleACMenuInput));

    switch (selectSingleOrMultipleACMenuInput) {
        case 1: selectSingleACMenu(mapFilename);
        case 2: selectMultipleACMenu(mapFilename);
        case 3: selectMapMenu();
        default: return;
    }
}

void Interface::selectSingleACMenu(const std::string &mapFilename) {
    std::vector<int> selected;
    bool invalidInput = false;
    std::vector<std::pair<int, std::string>> availableACs;

    do {
        availableACs = getAvailableACs(mapFilename);
        std::cout << "\n----- SINGLE APPLICATION CENTER -----\n";
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
        std::cout << "\n----- MULTIPLE APPLICATION CENTERS -----\n";
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
    std::cout << "\n----- ORDER VACCINES MENU -----\n";
    for (int i : selected) {
        std::cout << "Vaccine's order for " << options[i].second << ": ";
        std::cin >> order;

        // constructing order and setting up AC
        Node *acNode = this->vaccineRouter->getGraph()->findNode(options[i].first);
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



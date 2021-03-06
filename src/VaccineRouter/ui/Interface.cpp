#include "Interface.h"
#include "../graph/GraphProcessor.h"
#include "../GraphViewer/graphViewer.h"
#include <fstream>
#include <sstream>

bool Interface::checkCinFail() {
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore(100000, '\n');
        std::cout << "[VaccineRouter] Invalid input. Please choose again.";
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

std::vector<int> Interface::checkACSelectionValidity(bool multiple, int optionsRange) {
    std::string input;
    std::vector<int> selected;
    std::cin.ignore(1000, '\n');
    std::getline(std::cin, input);
    std::stringstream ss(input);

    while (ss >> input || !checkInRange(optionsRange, std::stoi(input))) {

        // invalid input error
        if (!checkCinFail() || !checkInRange(optionsRange, std::stoi(input))) {
            std::cout << "[VaccineRouter] Invalid input. Please choose again.";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // multiple inputs when only single was permitted error
        if (!multiple && !ss.eof()) {
            std::cout << "[VaccineRouter] You chose more than one Application Center. "
                         "Please make sure to choose only one.\n\n";
            std::cin.clear();
            std::cin.ignore(100000, '\n');
            return std::vector<int>();
        }

        // updates return vector with selected option
        selected.push_back(std::stoi(input));
    }

    return selected;
}

bool Interface::checkTimeValidity(std::string time) {
    std::stringstream ss(time);
    int hour, minute, second;
    char foo;

    ss >> hour >> foo >> minute >> foo >> second;

    return !(hour > 24 || hour < 0 ||
             minute > 60 || minute < 0 ||
             second > 60 || second < 0);
}

std::map<int, std::pair<unsigned int, std::string>>
Interface::getAvailableACs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt");

    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        std::vector<std::pair<int, std::string>>();
    }

    std::map<int, std::pair<unsigned int, std::string>> options;

    unsigned int id;
    int optionCounter = 1;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        options.insert(std::pair<int, std::pair<unsigned int, std::string>>(
                optionCounter, std::pair<unsigned int, std::string>(id, name)));
        optionCounter++;
    }

    istream.close();
    return options;
}

std::map<int, std::pair<unsigned int, std::string>>
Interface::getAvailableSCs(const std::string &mapFilename) {
    std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_SCs.txt");

    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        std::vector<std::pair<int, std::string>>();
    }

    std::map<int, std::pair<unsigned int, std::string>> options;

    unsigned int id;
    int optionCounter = 1;
    std::string name;
    while (istream >> id) {
        istream.ignore();
        std::getline(istream, name);
        options.insert(std::pair<int, std::pair<unsigned int, std::string>>(
                optionCounter, std::pair<unsigned int, std::string>(id, name)));
        optionCounter++;
    }

    istream.close();
    return options;
}

std::map<int, std::string> Interface::getAvailableCities() {
    std::ifstream istream("../../cityMaps/availableCities.txt");
    if (!istream.is_open()) {
        std::cout << "[VaccineRouter] File containing the available cities could "
                     "not be open.";
        return std::map<int, std::string>();
    }

    std::map<int, std::string> availableCities;
    std::string cityName;
    int optionCounter = 1;
    while (getline(istream, cityName)) {
        availableCities.insert(
                std::pair<int, std::string>(optionCounter, cityName));
        optionCounter++;
    }

    istream.close();
    return availableCities;
}

void Interface::displayAvailableACs(
        std::map<int, std::pair<unsigned int, std::string>> &options) {
    if (options.empty())
        std::cout << "[VaccineRouter] There are no available Application Centers.";
    else {
        for (auto op : options) {
            std::cout << op.first << ". " << op.second.second << '\n';
        }
    }
}

void Interface::displayAvailableSCs(
        std::map<int, std::pair<unsigned int, std::string>> &options) {
    if (options.empty())
        std::cout << "[VaccineRouter] There are no available Storage Centers.";
    else {
        for (auto op : options) {
            std::cout << op.first << ". " << op.second.second << '\n';
        }
    }
}

void Interface::displayAvailableCities(std::map<int, std::string> &cities) {
    if (cities.empty()) {
        std::cout << "[VaccineRouter] There are no available cities.";
    } else {
        for (const auto &op : cities) {
            std::cout << op.first << ". " << op.second << '\n';
        }
    }
}

Interface::Interface() { this->vaccineRouter = new VaccineRouter(); }

void Interface::initInterface() {
    initialMenu();
    return;
}

void Interface::initialMenu() {
    int initialMenuInput = 0;
    do {
        std::cout << "\n\n----- INITIAL MENU -----\n"
                     "1. Run Program\n"
                     "2. Analyse Connectivity\n"
                     "3. Modify Data\n"
                     "4. Exit\n\n"
                     "Please select your option: ";
        std::cin >> initialMenuInput;
    } while (!checkCinFail() || !checkGeneralInputValidity(4, initialMenuInput));

    switch (initialMenuInput) {
        case 1: runProgramMenu(); break;
        case 2: analyseConnectivityMenu(); break;
        case 3: modifyDataMenu(); break;
        default: break;
    }
    return;
}

void Interface::runProgramMenu() {
    int runProgramMenuInput = 0;
    do {
        std::cout << "\n\n----- RUN PROGRAM MENU -----\n"
                     "1. Select Map\n"
                     "2. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> runProgramMenuInput;
    } while (!checkCinFail() ||
             !checkGeneralInputValidity(2, runProgramMenuInput));

    switch (runProgramMenuInput) {
        case 1: selectMapMenu(); break;
        case 2: initialMenu(); break;
        default: break;
    }
    return;
}

void Interface::analyseConnectivityMenu() {
    int input = 0;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n\n----- AVAILABLE CITIES TO ANALYSE CONNECTIVITY -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter
                  << ". Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) { // user chose to go back
        initialMenu();
        return;
    }

    std::string mapFilename = availableCities.find(input)->second;
    Graph *graph = processGraph(mapFilename, false);
    vaccineRouter->setGraph(graph);
    vaccineRouter->setUpSCs(mapFilename);
    Graph copy = *graph;
    for (StorageCenter *sc : vaccineRouter->getSCs()) graph->DFSConnectivity(sc->getNode());
    graph->removeUnvisitedNodes();

    displayConnectivityAnalysis(&copy, graph);

    initialMenu();
    return;
}

void Interface::modifyDataMenu() {
    int input;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n\n----- MODIFY DATA MENU - MAP SELECTION -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter
                  << ". Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) { // user chose to go back
        initialMenu();
        return;
    }

    std::string chosenCity = availableCities.find(input)->second;
    input = 0;

    do {
        std::cout << "\n\n----- MODIFY DATA MENU -----\n"
                     "1. Add Application Center\n"
                     "2. Add Storage Center\n"
                     "3. Remove Application Center\n"
                     "4. Remove Storage Center\n"
                     "5. Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(5, input));

    switch (input) {
        case 1: addACMenu(chosenCity); break;
        case 2: addSCMenu(chosenCity); break;
        case 3: removeACMenu(chosenCity); break;
        case 4: removeSCMenu(chosenCity); break;
        case 5: modifyDataMenu(); break;
        default: break;
    }
    return;
}

void Interface::addSCMenu(const std::string &mapFilename) {
    bool error;
    int newID;
    std::string newName;
    std::map<int, std::pair<unsigned int, std::string>> availableACs;
    std::map<int, std::pair<unsigned int, std::string>> availableSCs;

    do {
        error = false;

        std::cout
                << "\n\n----- ADD STORAGE CENTER MENU -----\n"
                   "Introduce the ID of the node about to become a Storage Center: ";
        std::cin >> newID;
        std::cin.ignore();

        availableACs = getAvailableACs(mapFilename);
        availableSCs = getAvailableSCs(mapFilename);

        // checking the existent selectedACs
        for (auto ac : availableACs) {
            if (newID == ac.second.first) {
                error = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to "
                             "an Application Center.";
                break;
            }
        }

        // checking the existent SCs
        for (auto sc : availableSCs) {
            if (newID == sc.second.first) {
                error = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to "
                             "a Storage Center.";
                break;
            }
        }

        // checking if given node ID exists
        Graph *tempGraph = nullptr;
        tempGraph = processGraph(mapFilename, true);
        error = tempGraph->findNode(newID) == nullptr;
        if (error) {
            std::cout << "[VaccineRouter] The given node ID does not exist.";
        }
        delete tempGraph;

        if (!error) {
            std::cout << "Introduce a name for the Storage Center: ";
            std::getline(std::cin, newName);

            std::cout << "[VaccineRouter] Your option is being processed...";

            std::ofstream ostream("../../cityMaps/" + mapFilename + "/" +
                                  mapFilename + "_SCs.txt",
                                  std::fstream::app);
            if (!ostream.is_open()) {
                std::cout
                        << "[VaccineRouter] File does not exist or could not be open.\n";
                return;
            }
            ostream << newID << ' ' << newName << '\n';
            ostream.close();

            std::cout << "[VaccineRouter] Storage Center successfully added!";
            break;
        }
    } while (true);

    modifyDataMenu();
    return;
}

void Interface::addACMenu(const std::string &mapFilename) {
    bool error;
    int newID;
    std::string newName;
    std::map<int, std::pair<unsigned int, std::string>> availableACs;
    std::map<int, std::pair<unsigned int, std::string>> availableSCs;

    do {
        error = false;

        std::cout << "\n\n----- ADD APPLICATION CENTER MENU -----\n"
                     "Introduce the ID of the node about to become an Application "
                     "Center: ";
        std::cin >> newID;
        std::cin.ignore();

        availableACs = getAvailableACs(mapFilename);
        availableSCs = getAvailableSCs(mapFilename);

        // checking the existent selectedACs
        for (auto ac : availableACs) {
            if (newID == ac.second.first) {
                error = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to "
                             "an Application Center.";
                break;
            }
        }

        // checking the existent SCs
        for (auto sc : availableSCs) {
            if (newID == sc.second.first) {
                error = true;
                std::cout << "[VaccineRouter] The given node ID already corresponds to "
                             "a Storage Center.";
                break;
            }
        }

        // checking if given node ID exists
        Graph *tempGraph = nullptr;
        tempGraph = processGraph(mapFilename, true);
        error = tempGraph->findNode(newID) == nullptr;
        if (error) {
            std::cout << "[VaccineRouter] The given node ID does not exist.";
        }
        delete tempGraph;

        if (!error) {
            std::cout << "Introduce a name for the Application Center: ";
            std::getline(std::cin, newName);

            std::cout << "[VaccineRouter] Your option is being processed...\n";

            std::ofstream ostream("../../cityMaps/" + mapFilename + "/" +
                                  mapFilename + "_ACs.txt",
                                  std::fstream::app);
            if (!ostream.is_open()) {
                std::cout
                        << "[VaccineRouter] File does not exist or could not be open.";
                return;
            }
            ostream << newID << ' ' << newName << '\n';
            ostream.close();

            std::cout << "[VaccineRouter] Application Center successfully added!";
            break;
        }
    } while (true);

    modifyDataMenu();
    return;
}

void Interface::removeSCMenu(const std::string &mapFilename) {
    int removeSCMenuInput = 0;
    int optionCounter;
    std::map<int, std::pair<unsigned int, std::string>> options;

    do {
        std::cout << "\n\n----- REMOVE STORAGE CENTER MENU -----\n";
        options = getAvailableSCs(mapFilename);
        displayAvailableSCs(options);
        optionCounter = options.empty() ? 1 : options.size() + 1;
        std::cout << optionCounter
                  << ". Go Back\n\n"
                     "Select one of the following Storage Centers to remove: ";
        std::cin >> removeSCMenuInput;
    } while (!checkCinFail() || !checkInRange(optionCounter, removeSCMenuInput));

    if (removeSCMenuInput == optionCounter) {
        modifyDataMenu();
        return;
    }

    std::cout << "[VaccineRouter] Your option is being processed...\n";

    options.erase(removeSCMenuInput);
    std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_SCs.txt",
                          std::fstream::trunc);
    if (!ostream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.";
        return;
    }
    // outputting remaining options to the file
    for (auto op : options)
        ostream << op.second.first << ' ' << op.second.second << '\n';
    ostream.close();

    std::cout << "[VaccineRouter] Storage Center successfully removed!";

    modifyDataMenu();
    return;
}

void Interface::removeACMenu(const std::string &mapFilename) {
    int removeACMenuInput = 0;
    int optionCounter;
    std::map<int, std::pair<unsigned int, std::string>> options;

    do {
        std::cout << "\n\n----- REMOVE APPLICATION CENTER MENU -----\n";
        options = getAvailableACs(mapFilename);
        displayAvailableACs(options);
        optionCounter = options.empty() ? 1 : options.size() + 1;
        std::cout << optionCounter
                  << ". Go Back\n\n"
                     "Select one of the following Application Centers to remove: ";
        std::cin >> removeACMenuInput;
    } while (!checkCinFail() || !checkInRange(optionCounter, removeACMenuInput));

    if (removeACMenuInput == optionCounter) {
        modifyDataMenu();
        return;
    }

    std::cout << "[VaccineRouter] Your option is being processed...";

    options.erase(removeACMenuInput);
    std::ofstream ostream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                          "_ACs.txt",
                          std::fstream::trunc);
    if (!ostream.is_open()) {
        std::cout << "[VaccineRouter] File does not exist or could not be open.\n";
        return;
    }
    // outputting remaining options to the file
    for (auto op : options)
        ostream << op.second.first << ' ' << op.second.second << '\n';
    ostream.close();

    std::cout << "[VaccineRouter] Application Center successfully removed!";

    modifyDataMenu();
    return;
}

void Interface::selectMapMenu() {
    int input = 0;
    int optionCounter;
    std::map<int, std::string> availableCities = getAvailableCities();

    do {
        std::cout << "\n\n----- AVAILABLE CITIES -----\n";
        displayAvailableCities(availableCities);
        optionCounter = availableCities.empty() ? 1 : availableCities.size() + 1;
        std::cout << optionCounter
                  << ". Go Back\n\n"
                     "Please select your option: ";
        std::cin >> input;
    } while (!checkCinFail() || !checkGeneralInputValidity(optionCounter, input));

    if (input == optionCounter) { // user chose to go back
        runProgramMenu();
        return;
    }

    std::string mapFilename = availableCities.find(input)->second;
    this->vaccineRouter->selectMap(mapFilename);
    this->vaccineRouter->setCityName(mapFilename);
    selectSingleOrMultipleACMenu(mapFilename);
    return;
}

void Interface::selectSingleOrMultipleACMenu(const std::string &mapFilename) {
    int selectSingleOrMultipleACMenuInput = 0;
    do {
        std::cout
                << "\n\n----- SINGLE OR MULTIPLE APPLICATION CENTER SELECTION -----\n"
                   "1. Single Application Center\n"
                   "2. Multiple Application Centers\n"
                   "3. Go Back\n\n"
                   "Please select your option: ";
        std::cin >> selectSingleOrMultipleACMenuInput;
    } while (!checkCinFail() ||
             !checkGeneralInputValidity(3, selectSingleOrMultipleACMenuInput));

    switch (selectSingleOrMultipleACMenuInput) {
        case 1:
            std::cout<<"Loading Graph so that ACs can be visualised!\n";
            displayACsVisually(this->vaccineRouter);
            selectSingleACMenu(mapFilename);
            break;
        case 2:
            std::cout<<"Loading Graph so that ACs can be visualised!\n";
            displayACsVisually(this->vaccineRouter);
            selectMultipleACMenu(mapFilename);
            break;
        case 3:
            selectMapMenu();
            break;
        default:
            return;
    }

    vaccineRouter->outputDataResults();
    return;
}

void Interface::selectSingleACMenu(const std::string &mapFilename) {
    std::vector<int> selected;
    bool invalidInput = false;
    std::map<int, std::pair<unsigned int, std::string>> availableACs;

    do {
        availableACs = getAvailableACs(mapFilename);
        std::cout << "\n\n----- SINGLE APPLICATION CENTER -----\n";
        std::cout << "\nPlease note that by selecting a single Application Center, "
                     "you will not\n"
                     "be given the chance of taking into account the vaccine's "
                     "lifetime.\n\n";
        displayAvailableACs(availableACs);
        std::cout << "Please select the Application Center from the above list "
                     "[usage: >2]: ";
        selected = checkACSelectionValidity(false, availableACs.size());
        invalidInput = selected.empty();
    } while (invalidInput);

    orderVaccinesMenu(availableACs, selected);
    singleSCSingleAC(); // here we don't give the option of taking into account the vaccine's lifetime
    return;
}

void Interface::selectMultipleACMenu(const std::string &mapFilename) {
    std::vector<int> selected;
    bool invalidInput = false;
    std::map<int, std::pair<unsigned int, std::string>> availableACs;

    do {
        availableACs = getAvailableACs(mapFilename);
        std::cout << "\n\n----- MULTIPLE APPLICATION CENTERS -----\n";
        std::cout << "\nAfter the selection, you will be redirected to a menu "
                     "where you will\n"
                     "be given the chance of taking into account the vaccine's "
                     "lifetime.\n\n";
        displayAvailableACs(availableACs);
        std::cout << "Please select the Application Center from the above list "
                     "[usage: >2 3 4]: ";
        selected = checkACSelectionValidity(true, availableACs.size());
        invalidInput = selected.empty();
    } while (invalidInput);

    orderVaccinesMenu(availableACs, selected);
    setAdditionalSpecsMenu(); // here we give the option of taking into account the vaccine's lifetime
    return;
}

void Interface::orderVaccinesMenu(
        std::map<int, std::pair<unsigned int, std::string>> &options,
        const std::vector<int> &selected) {
    int order;
    std::cout << "\n\n----- ORDER VACCINES MENU -----\n";
    for (int i : selected) {
        std::cout << '\n';
        std::cout << "Vaccine's order for " << options[i].second << ": ";
        std::cin >> order;

        // constructing order and setting up AC
        Node *acNode = this->vaccineRouter->getGraph()->findNode(options[i].first);
        std::string acName = options[i].second;
        auto *newAC = new ApplicationCenter(acNode, acName);
        newAC->setVaccinesToReceive(order);
        this->vaccineRouter->selectApplicationCenter(newAC);
    }
    return;
}

void Interface::setAdditionalSpecsMenu() {
    // check if user wants to limit route duration
    char tw = '\0';
    do {
        std::cout << "\nDo you want to consider the vaccine's lifetime? [y/n] ";
        std::cin >> tw;
    } while (!checkCinFail() ||
             (tw != 'y' && tw != 'Y' && tw != 'n' && tw != 'N'));

    // sets time window
    std::string time;
    if (tw == 'y' || tw == 'Y') {
        do {
            std::cout << "\nEnter the vaccine's lifetime: [hh:mm:ss] ";
            std::cin >> time;
        } while (!checkCinFail() || !checkTimeValidity(time));

        vaccineRouter->setVaccineLifetime(time);
    }

    // check if user wants the deliveries to be made by a single SC
    char single = '\0';
    do {
        std::cout << "\nDo you want to force the deliveries to be made by a single "
                     "Storage Center? [y/n] ";
        std::cin >> single;
    } while (!checkCinFail() ||
             (single != 'y' && single != 'Y' && single != 'n' && single != 'N'));

    if ((tw == 'n' || tw == 'N')) {
        singleSCMultipleAC();
        return;
    }
    else if ((tw == 'y' || tw == 'Y') && (single == 'y' || single == 'Y')) {
        singleSCMultipleACWithTW();
        return;
    }
    else if ((tw == 'y' || tw == 'Y') && (single == 'n' || single == 'N')) {
        multipleSCMultipleACWithTW();
        return;
    }
    return;
}

void Interface::singleSCSingleAC() {
    vaccineRouter->calculateRouteSingleSCSingleAC();
    return;
}

void Interface::singleSCMultipleAC() {
    vaccineRouter->calculateRouteSingleSCMultipleAC();
    return;
}

void Interface::singleSCMultipleACWithTW() {
    vaccineRouter->calculateRouteSingleSCMultipleACWithTW();
    return;
}

void Interface::multipleSCMultipleACWithTW() {
    vaccineRouter->calculateRouteMultipleSCMultipleACWithTW();
    return;
}

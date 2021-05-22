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

  while (!read || !checkInRange(optionsRange,input)) {
    std::cin >> input;

    // invalid input error
    if (std::cin.fail() || !checkInRange(optionsRange, input)) {
      std::cerr << "Invalid input. Please choose again.\n\n";
      std::cin.clear();
      std::cin.ignore(100000, '\n');
      return std::vector<int>();
    }



    // multiple inputs when only single was permitted error
    if (!multiple &&  std::cin.eof()) {
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
//TODO reading name is wrong
void Interface::getAndDisplayAvailableACs(
    const std::string &mapFilename, std::vector<ApplicationCenter *> &options) {
  std::ifstream istream("../../cityMaps/" + mapFilename + "/" + mapFilename +
                        "_ACs.txt");

  if (!istream.is_open()) {
    std::cerr << "File does not exist or could not be open.\n\n";
    return;
  }

  unsigned int id;
  std::string name;
  while (istream >> id) {;
    std::getline(istream,name);
    ApplicationCenter *newAC = new ApplicationCenter(
        this->vaccineRouter->getGraph()->getNode(id), name);
    options.push_back(newAC);
  }

  // displaying the different options
  if (options.empty())
    std::cout << "There are no available Application Centers.\n";
  else
    for (int i = 0; i < options.size(); ++i)
      std::cout << i << ". " << options[i]->getName() << '\n';

  istream.close();
}

Interface::Interface() { this->vaccineRouter = new VaccineRouter(); }

void Interface::initInterface() { initialMenu(); }

void Interface::initialMenu() {
  int input;
  do {
    std::cout << "----- INITIAL MENU -----\n"
                 "1. Run Program\n"
                 "2. Exit\n\n"
                 "Please select your option: ";
    std::cin >> input;
    std::cout << "\n";
  } while (!checkGeneralInputValidity(2, input) && std::cin.fail());

  if (input == 1)
    runProgramMenu();
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

    std::cout << optionCounter << ". "
              << "Go Back\n\n"
                 "Please select your option: ";
    std::cin >> input;
    std::cout << "\n";
  } while (!checkGeneralInputValidity(optionCounter, input) && std::cin.fail());

  if (input == optionCounter)
    runProgramMenu(); // user chose to go back
  this->vaccineRouter->selectMap(options[input - 1]);
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
  std::vector<int> input;
  bool invalidInput = false;
  std::vector<ApplicationCenter *> availableACs;

  do {
    std::cout << "----- SINGLE APPLICATION CENTER -----\n";
    getAndDisplayAvailableACs(mapFilename, availableACs);
    std::cout << "Please select the Application Center from the above list "
                 "[usage: >2]: ";
    input = checkACSelectionValidity(false, availableACs.size());
    invalidInput = input.empty();
  } while (invalidInput);
  orderVaccinesMenu(input, availableACs);
  setupACs(availableACs, input);
  singleAC();
}

void Interface::selectMultipleACMenu(const std::string &mapFilename) {
  std::vector<int> input;
  bool invalidInput = false;
  std::vector<ApplicationCenter *> availableACs;

  do {
    std::cout << "----- MULTIPLE APPLICATION CENTERS -----\n";
    getAndDisplayAvailableACs(mapFilename, availableACs);
    std::cout << "Please select the Application Center from the above list "
                 "[usage: >2 3 4]: ";
    input = checkACSelectionValidity(true, availableACs.size());
    invalidInput = input.empty();
  } while (invalidInput);

  orderVaccinesMenu(input, availableACs);
  setupACs(availableACs, input);
  multipleAC();
}

void Interface::orderVaccinesMenu(
    const std::vector<int> &selected,
    const std::vector<ApplicationCenter *> &options) {
  int order;
  std::cout << "----- ORDER VACCINES MENU -----\n";
  for (int i : selected) {
    std::cout << "Vaccine's order for " << options[i]->getName() << ": ";
    std::cin >> order;

    ApplicationCenter *ac = options[i];
    ac->setVaccinesToReceive(order);
    this->vaccineRouter->addApplicationCenter(ac);
  }
}

// TODO
void Interface::singleAC() {}

// TODO
void Interface::multipleAC() {}
void Interface::setupACs(std::vector<ApplicationCenter *> selectedACs,
                         std::vector<int> index) {
  for (int ix : index) {
    this->vaccineRouter->addApplicationCenter(selectedACs[ix]);
  }
}

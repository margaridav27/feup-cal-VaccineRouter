#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H

#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;
    bool checkInRange(int optionsRange, int input);
    bool checkGeneralInputValidity(int optionsRange, int input);
    std::vector<int> checkACSelectionValidity(bool multiple, int optionsRange);

    std::vector<std::pair<int, std::string>> getAvailableACs(const std::string &mapFilename);
    std::vector<std::pair<int, std::string>> getAvailableSCs(const std::string &mapFilename);

    void displayAvailableACs(std::vector<std::pair<int, std::string>> &options);
    void displayAvailableSCs(std::vector<std::pair<int, std::string>> &options);

    void initialMenu();
    void runProgramMenu();
    void modifyDataMenu();
    void addSCMenu(const std::string &mapFilename);
    void addACMenu(const std::string &mapFilename);
    void removeSCMenu(const std::string &mapFilename);
    void removeACMenu(const std::string &mapFilename);
    void selectMapMenu();
    void selectSingleOrMultipleACMenu(const std::string &mapFilename);
    void selectSingleACMenu(const std::string &mapFilename);
    void selectMultipleACMenu(const std::string &mapFilename);
    void orderVaccinesMenu(std::vector<std::pair<int, std::string>> &options, const std::vector<int> &selected);

    void singleAC();
    void multipleACWithTW();
    void multipleAC();
public:
    Interface();
    void initInterface();
};


#endif //SRC_INTERFACE_H

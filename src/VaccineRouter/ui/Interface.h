#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H

#include <map>
#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;
    bool checkCinFail();
    bool checkInRange(int optionsRange, int input);
    bool checkGeneralInputValidity(int optionsRange, int input);
    std::vector<int> checkACSelectionValidity(bool multiple, int optionsRange);

    std::map<int, std::pair<unsigned int, std::string>> getAvailableACs(const std::string &mapFilename);
    std::map<int, std::pair<unsigned int, std::string>> getAvailableSCs(const std::string &mapFilename);
    std::map<int, std::string> getAvailableCities();

    void displayAvailableACs(std::map<int, std::pair<unsigned int, std::string>> &options);
    void displayAvailableSCs(std::map<int, std::pair<unsigned int, std::string>> &options);
    void displayAvailableCities(std::map<int, std::string> &cities);

    void initialMenu();
    void runProgramMenu();
    void analyseConnectivityMenu();
    void modifyDataMenu();
    void addSCMenu(const std::string &mapFilename);
    void addACMenu(const std::string &mapFilename);
    void removeSCMenu(const std::string &mapFilename);
    void removeACMenu(const std::string &mapFilename);
    void selectMapMenu();
    void selectSingleOrMultipleACMenu(const std::string &mapFilename);
    void selectSingleACMenu(const std::string &mapFilename);
    void selectMultipleACMenu(const std::string &mapFilename);
    void orderVaccinesMenu(std::map<int, std::pair<unsigned int, std::string>> &options, const std::vector<int> &selected);
    void setAdditionalSpecsMenu();

    void singleSCSingleAC();
    void singleSCMultipleAC();
    void singleSCMultipleACWithTW();
    void multipleSCMultipleACWithTW();
public:
    Interface();
    void initInterface();
};


#endif //SRC_INTERFACE_H

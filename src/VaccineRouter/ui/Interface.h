#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H

#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;
    bool checkInRange(int optionsRange, int input);
    bool checkGeneralInputValidity(int optionsRange, int input);
    std::vector<int> checkACSelectionValidity(bool multiple, int optionsRange);
    void getAndDisplayAvailableACs(const std::string &mapFilename, std::vector<ApplicationCenter> &options);
    void initialMenu();
    void runProgramMenu();
    void selectMapMenu();
    void selectSingleOrMultipleACMenu(const std::string &mapFilename);
    void selectSingleACMenu(const std::string &mapFilename);
    void selectMultipleACMenu(const std::string &mapFilename);
    void orderVaccinesMenu(const std::vector<int> &selected, const std::vector<ApplicationCenter>& options);
    void singleAC();
    void multipleAC();
public:
    Interface();
    void initInterface();
};


#endif //SRC_INTERFACE_H

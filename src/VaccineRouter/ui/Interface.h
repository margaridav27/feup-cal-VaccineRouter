#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H


#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;

    bool _checkInRange(int optionsRange, int input);
    bool _checkGeneralInputValidity(int optionsRange, int input);
    std::vector<int> _checkACSelectionValidity(bool multiple, int optionsRange);
    void _displayAndGetAvailableACs(const std::string &mapFilename, std::vector<ApplicationCenter> &options);

public:
    Interface();
    void initInterface();
    void initialMenu();
    void runProgramMenu();
    void selectMapMenu();
    void selectSingleOrMultipleACMenu(const std::string &mapFilename);
    void selectSingleACMenu(const std::string &mapFilename);
    void selectMultipleACMenu(const std::string &mapFilename);
    void orderVaccinesMenu(const std::vector<int> &selected, const std::vector<ApplicationCenter>& options);
    void singleAC();
    void multipleAC();
};


#endif //SRC_INTERFACE_H

#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H


#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;

    bool checkInRange(int optionsRange, int input);
    bool checkGeneralInputValidity(int optionsRange, int input);
    bool checkFilenameValidity(const std::string& filename);
    std::vector<int> checkACSelectionValidity(bool multiple, int optionsRange);
public:
    Interface();
    void initInterface();
    void initApplication();
    void initialMenu();
    void loadMapMenu();
    void runProgramMenu();
    void selectMapMenu();
    void selectSingleOrMultipleACMenu();
    void selectSingleACMenu();
    void selectMultipleACMenu();
    void orderVaccinesMenu(const std::vector<int> &selected);
    void singleAC();
  };


#endif //SRC_INTERFACE_H

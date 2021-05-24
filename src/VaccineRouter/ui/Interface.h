#ifndef SRC_INTERFACE_H
#define SRC_INTERFACE_H

#include <map>
#include "../model/VaccineRouter.h"

class Interface {
private:
    VaccineRouter *vaccineRouter;

    /**
     * checks invalid input
     * @return true if valid, false otherwise
     */
    bool checkCinFail();

    /**
     * checks if input is in range
     * @param optionsRange
     * @param input
     * @return true if it is, false otherwise
     */
    bool checkInRange(int optionsRange, int input);

    /**
     * checks if input is valid
     * @param optionsRange
     * @param input
     * @return true if input is valid, false otherwise
     */
    bool checkGeneralInputValidity(int optionsRange, int input);

    /**
     * checks if Application Center selection is valid
     * @param multiple determines if the user can choose multiple Application Centers or not
     * @param optionsRange
     * @return vector containing the index of the selected options
     */
    std::vector<int> checkACSelectionValidity(bool multiple, int optionsRange);

    /**
     * checks if time is valid
     * @param time time in string format
     * @return true if valid, false otherwise
     */
    bool checkTimeValidity(std::string time);

    /**
     * gets the available Application Centers in the city correspondent to mapFilename
     * @param mapFilename
     * @return map with option index as key and pair of Application Center's ID and name as value
     */
    std::map<int, std::pair<unsigned int, std::string>> getAvailableACs(const std::string &mapFilename);

    /**
     * gets the available Storage Centers in the city correspondent to mapFilename
     * @param mapFilename
     * @return map with option index as key and pair of Storage Center's ID and name as value
     */
    std::map<int, std::pair<unsigned int, std::string>> getAvailableSCs(const std::string &mapFilename);

    /**
     * gets the available cities
     * @return map with option index as key and city's name as value
     */
    std::map<int, std::string> getAvailableCities();

    /**
     * displays available Application Centers on the screen in a human friendly way
     * @param options map with option index as key and pair of Application Center's ID and name as value
     */
    void displayAvailableACs(std::map<int, std::pair<unsigned int, std::string>> &options);

    /**
     * displays available Storage Centers on the screen in a human friendly way
     * @param options map with option index as key and pair of Storage Center's ID and name as value
     */
    void displayAvailableSCs(std::map<int, std::pair<unsigned int, std::string>> &options);

    /**
     * displays available cities on the screen in a human friendly way
     * @param cities map with option index as key and city's name as value
     */
    void displayAvailableCities(std::map<int, std::string> &cities);

    void initialMenu();

    void runProgramMenu();

    void analyseConnectivityMenu();

    void modifyDataMenu();

    /**
     * gives user the chance to add an Application Center to the city correspondent to mapFilename
     * @param mapFilename
     */
    void addSCMenu(const std::string &mapFilename);

    /**
     * gives user the chance to add a Storage Center to the city correspondent to mapFilename
     * @param mapFilename
     */
    void addACMenu(const std::string &mapFilename);

    /**
     * gives user the chance to remove an Application Center from the city correspondent to mapFilename
     * @param mapFilename
     */
    void removeSCMenu(const std::string &mapFilename);

    /**
     * gives user the chance to remove a Storage Center from the city correspondent to mapFilename
     * @param mapFilename
     */
    void removeACMenu(const std::string &mapFilename);

    void selectMapMenu();

    /**
     * gives user the chance to select if he will want to order vaccines
     * for a single Application Center or for multiple Application Centers
     * @param mapFilename city from which he will be given the chance to select the Application Centers from
     */
    void selectSingleOrMultipleACMenu(const std::string &mapFilename);

    /**
     * gives user the chance to select a single Application Center to order vaccines for
     * @param mapFilename city from which he will select the Application Center
     */
    void selectSingleACMenu(const std::string &mapFilename);

    /**
     * gives user the chance to select multiple Application Centers to order vaccines for
     * @param mapFilename city from which he will select the Application Centers
     */
    void selectMultipleACMenu(const std::string &mapFilename);

    /**
     * menu where the user is solicited to introduce the amount of vaccines he wants to order for each Application Center selected
     * @param options available Application Centers
     * @param selected selected Application Centers correspondent menu index
     */
    void orderVaccinesMenu(std::map<int, std::pair<unsigned int, std::string>> &options, const std::vector<int> &selected);

    /**
     * menu where the user is solicited to set some additional details required for program execution
     * i.e.,
     * if he will want to limit the route's duration,
     * in case he wants to limit the route's duration, the correspondent time window
     * if he will want to force the deliveries to be made by a single Storage Center
     */
    void setAdditionalSpecsMenu();

    /**
     * single Storage Center and single Application Center - 1st Iteration
     * calls correspondent VaccineRouter's method
     */
    void singleSCSingleAC();

    /**
     * single Storage Center and multiple Application Center - 2st Iteration
     * calls correspondent VaccineRouter's method
     */
    void singleSCMultipleAC();

    /**
     * single Storage Center and multiple Application Center with time constraint - 3rd Iteration
     * calls correspondent VaccineRouter's method
     */
    void singleSCMultipleACWithTW();

    /**
     * multiple Storage Center and multiple Application Center with time constraint - 4rd Iteration
     * calls correspondent VaccineRouter's method
     */
    void multipleSCMultipleACWithTW();

public:
    /**
     * constructor
     */
    Interface();

    /**
     * inits Interface by making a call to initialMenu
     */
    void initInterface();
};


#endif //SRC_INTERFACE_H

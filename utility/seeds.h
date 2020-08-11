#include <iostream>
#include <vector>
#include <string>

// vector<string> nameOfBuilding = [Name, Monopoly Block, Purchase Cost, Improvement Cost, Impr price 0, Impr price 1, Impr price 2, Impr price 3, Impr price 4, Impr price 5]
// the according index of the vector
// index 0 => Name
// index 1 => Monopoly Block
// index 2 => Purchase Cost
// index 3 => Improvement Cost
// index 4 => Impr price 0
// index 5 => Impr price 1
// index 6 => Impr price 2
// index 7 => Impr price 3
// index 8 => Impr price 4
// index 9 => Impr price 5

const std::vector<std::string> AL = {"AL", "Arts1", "40", "50", "2", "10", "30", "90", "160", "250"};
const std::vector<std::string> ML = {"ML", "Arts1", "60", "50", "4", "20", "60", "180", "320", "450"};
const std::vector<std::string> ECH = {"ECH", "Arts2", "100", "50", "6", "30", "90", "270", "400", "550"};
const std::vector<std::string> PAS = {"PAS", "Arts2", "100", "50", "6", "30", "90", "270", "400", "550"};
const std::vector<std::string> HH = {"HH", "Arts2", "120", "50", "8", "40", "100", "300", "450", "600"};
const std::vector<std::string> RCH = {"RCH", "Eng", "140", "100", "10", "50", "150", "450", "625", "750"};
const std::vector<std::string> DWE = {"DWE", "Eng", "140", "100", "10", "50", "150", "450", "625", "750"};
const std::vector<std::string> CPH = {"CPH", "Eng", "160", "100", "12", "60", "180", "500", "700", "900"};
const std::vector<std::string> LHI = {"LHI", "Health", "180", "100", "14", "70", "200", "550", "750", "950"};
const std::vector<std::string> BMH = {"BMH", "Health", "180", "100", "14", "70", "200", "550", "750", "950"};
const std::vector<std::string> OPT = {"OPT", "Health", "200", "100", "16", "80", "220", "600", "800", "1000"};
const std::vector<std::string> EV1 = {"EV1", "Env", "220", "150", "18", "90", "250", "700", "875", "1050"};
const std::vector<std::string> EV2 = {"EV2", "Env", "220", "150", "18", "90", "250", "700", "875", "1050"};
const std::vector<std::string> EV3 = {"EV3", "Env", "240", "150", "20", "100", "300", "750", "925", "1100"};
const std::vector<std::string> PHYS = {"PHYS", "Sci1", "260", "150", "22", "110", "330", "800", "975", "1150"};
const std::vector<std::string> B1 = {"B1", "Sci1", "260", "150", "22", "110", "330", "800", "975", "1150"};
const std::vector<std::string> B2 = {"B2", "Sci1", "280", "150", "24", "120", "360", "850", "1025", "1200"};
const std::vector<std::string> EIT = {"EIT", "Sci2", "300", "200", "26", "130", "390", "900", "1100", "1275"};
const std::vector<std::string> ESC = {"ESC", "Sci2", "300", "200", "26", "130", "390", "900", "1100", "1275"};
const std::vector<std::string> C2 = {"C2", "Sci2", "320", "200", "28", "150", "450", "1000", "1200", "1400"};
const std::vector<std::string> MC = {"MC", "Math", "350", "200", "35", "175", "500", "1100", "1300", "1500"};
const std::vector<std::string> DC = {"DC", "Math", "400", "200", "50", "200", "600", "1400", "1700", "2000"};
const std::vector<std::vector<std::string>> ACADEMIC = {AL, ML, ECH, PAS, HH, RCH, DWE, CPH, LHI, BMH, OPT, EV1, EV2, EV3, PHYS, B1, B2, EIT, ESC, C2, MC, DC};
const int ACADEMIC_SIZE = ACADEMIC.size();

void traveseAcademic() { // for testing
    int size = ACADEMIC.size();
    int sizeProp = 9;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < sizeProp; j++) {
            std::cout << ACADEMIC[i][j] << " " ;
        }
        std::cout << std::endl;
    }
}
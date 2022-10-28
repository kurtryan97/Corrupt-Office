#include "CQhead2.h"

int main() {
    SQSimulation("lineup","John","regular");
    SQSimulation("lineup","Bob","regular");
    SQSimulation("lineup","Tom","regular");
    SQSimulation("lineup","Sarah","VIP");
    SQSimulation("lineup","Marie","VIP");
    SQSimulation("lineup","Joan","VIP");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("serve");


    return 0;

}
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
    SQSimulation("arrive","supervisor");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("lineup","Bea","VIP");
    SQSimulation("lineup","Hank","regular");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("leave","supervisor");
    SQSimulation("lineup","Art","regular");
    SQSimulation("lineup","Daisy","VIP");
    SQSimulation("lineup","Marius","regular");
    SQSimulation("lineup","Dane","VIP");
    SQSimulation("serve");
    SQSimulation("arrive","supervisor");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("serve");
    SQSimulation("leave","supervisor");

    return 0;

}
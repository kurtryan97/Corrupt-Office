//
// Created by Jfr on 26/10/2022.
//
#include "CQhead.h"

int main() {
    // creating an object
    CQSimulation simulate;

    /*
    *     implementation without using an object
    *     (uncomment/comment this if you want to use/unused without object).
    */

    CQSimulation("lineup","John","regular");
    CQSimulation("lineup","Bob","regular");
    CQSimulation("lineup","Tom","regular");
    CQSimulation("lineup","Sarah","VIP");
    CQSimulation("lineup","Marie","VIP");
    CQSimulation("lineup","Joan","VIP");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("arrive","supervisor");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("lineup","Bea","VIP");
    CQSimulation("lineup","Hank","regular");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("leave","supervisor");
    CQSimulation("lineup","Art","regular");
    CQSimulation("lineup","Daisy","VIP");
    CQSimulation("lineup","Marius","regular");
    CQSimulation("lineup","Dane","VIP");
    CQSimulation("serve");
    CQSimulation("arrive","supervisor");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("serve");
    CQSimulation("leave","supervisor");

    /*
     *  implementation using object (simulate).
     *  (uncomment/comment this if you want to use/unuse with object instead).
     */

//    simulate.lineup("lineup","John","regular");
//    simulate.lineup("lineup","Bob","regular");
//    simulate.lineup("lineup","Tom","regular");
//    simulate.lineup("lineup","Sarah","VIP");
//    simulate.lineup("lineup","Marie","VIP");
//    simulate.lineup("lineup","Joan","VIP");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.supervisor_status("arrive","supervisor");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.lineup("lineup","Bea","VIP");
//    simulate.lineup("lineup","Hank","regular");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.supervisor_status("leave","supervisor");
//    simulate.lineup("lineup","Art","regular");
//    simulate.lineup("lineup","Daisy","VIP");
//    simulate.lineup("lineup","Marius","regular");
//    simulate.lineup("lineup","Dane","VIP");
//    simulate.serve("serve");
//    simulate.supervisor_status("arrive","supervisor");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.serve("serve");
//    simulate.supervisor_status("leave","supervisor");

    return 0;

}
#include "includes/BankSimulator.h"

int main(){
    BankSimulator sim;
    sim.readSimulationParameters();
    sim.run();        
    sim.printStat();    
    return 0;
}
#include "Battle.cpp"
using namespace std;
int main()
{
    // Created a instance of battle
    Battle b;
    // Give 3 integer Inputs in order
    // <No.of Suits>  <No.of Heros>  <No.of Enimies>
    b.takeAllCount();
    // Give Qualification of each Suit Like
    // <Power> <Durability> <energy> <HeatLevel>
    b.takeSuitInput();
    // Give Avenger details in order as
    //  <name> <attackStrength>
    // Avengers will be assigned suits in first come first serve order
    // If no suit is left for an avenger X , then will print  "X is out of fight"
    b.takeAvengersInput();
    /*
        Battle starts, give the commands such as
        
        Attack <Avenger1> <Avenger2>: Avenger1 attacks Avenger2..
        Repair <AvengerName> x: Repairs Avenger's suit by x durability.
        BoostPowerByFactor <AvengerName> y:Boost the avenger suit by factor of y.
        BoostPower <AvengerName> <P> <D> <E> <H>: 
            Boost the avenger suit by transferring the power of the suit2(assume it as newly created suit) to Avenger’s suit .
        AvengerStatus <AvengerName>: print the suit status of the avenger in the format.
        Upgrade <AvengerName>: Upgrades Avenger's suit if extra suits exist.
        End: Ends the simulation
        PrintBattleLog – Displays the battle log.
        BattleStatus – Prints "heroes are winning" or "enemies are winning" or “tie”.

    */
    b.startBattle();
}
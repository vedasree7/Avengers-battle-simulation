#include"QNS.cpp"
using  std::cin, std::cout, std:: string ;
class Avenger
{
private:
    string name;
    QNS suit; // assign ion first come first serve basis
    int attackStrength;
public:
    Avenger(){} // default constructor
    Avenger(std::string avName, QNS avSuit, int strength);   // parametered constructor      

    void attack(Avenger &enemy);     // simulates attack

    inline void upgradeSuit(QNS &q) { suit = suit + q; }   // upgrades suits power by left over suits
    inline void repair(int x) { suit = suit / x; }         // cools down the suit
    inline void powerup(int x) { suit = suit * x;}         // Powerup the suit

    inline void printStatus()
    {
        cout << name << " " << suit.getPower() << " " << suit.getDurability() << " " << suit.getEnergy() << " " << suit.getHeat() << "\n";
    }
    //checking Suit status  
    inline bool isDestroyed() { return suit.getDurability() <= 0; }
    inline bool isOverHeated() { return suit.getHeat() > 500; } 

    inline int getsuitpower() { return suit.getPower(); }
    inline int getsuitDuarability() {return suit.getDurability();}
};

Avenger::Avenger(std::string avName, QNS avSuit, int strength) 
{   
    name = avName; 
    suit = avSuit; 
    attackStrength = strength;
}

void Avenger::attack(Avenger &enemy)
{
    // Checking conditions for attack
    if(suit.getHeat() <= 500 && suit.getDurability() > 0 && enemy.suit.getDurability() > 0)
        enemy.suit - attackStrength;  
} 

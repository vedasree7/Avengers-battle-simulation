#include<string>
#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using std::min, std::max;

class QNS
{
private:
    int powerLevel;int durability;int energyStorage;int heatLevel;

public:
    QNS();  // default constructor
    QNS(int p, int d, int e, int h); // parameterd constructor                        
    QNS(const QNS &q); // copy constructor 

    // getters and setters
    inline int getPower() { return powerLevel; }
    inline int getDurability() { return durability; }
    inline int getEnergy() { return energyStorage; }
    inline int getHeat() { return heatLevel; }

    // operation overloading
    QNS operator+(QNS &q);
    QNS operator-(int X);
    QNS operator*(int X);
    QNS operator/(int X);

    // function overloading
    inline void boostPower(int factor) { (*this) * factor; }
    inline void boostPower(QNS &otherSuit) { (*this) + otherSuit; }


};

QNS::QNS() 
{
    powerLevel = 1000; 
    durability = 500;
    energyStorage = 300;
    heatLevel = 0; 
}

QNS::QNS(int p, int d, int e, int h)
{ 
    powerLevel = min(p,5000); 
    durability = d;  
    energyStorage = e; 
    heatLevel = max(h,0);
}  

QNS::QNS(const QNS &q) // copy constructor
{ 
    powerLevel = min(q.powerLevel,5000); 
    durability = q.durability;  
    energyStorage = q.energyStorage; 
    heatLevel = max(q.heatLevel,0); 
} 

QNS QNS::operator+(QNS &q)
{
    this -> powerLevel = this -> powerLevel + q.energyStorage;
    durability = durability + q.durability;
    energyStorage = energyStorage + q.powerLevel;
    if (powerLevel > 5000) // Check condition such that power doesn't exceed 5000
        powerLevel = 5000;
    return *this;
}

QNS QNS::operator-(int X)
{
    durability = durability - X;
    energyStorage = energyStorage + X;
    heatLevel = heatLevel + X;
    return *this;
}
QNS QNS::operator*(int X) 
{
    powerLevel = powerLevel + ((powerLevel * X) / 100);
    energyStorage = energyStorage + 5 * X;
    heatLevel = heatLevel + X;
    if (powerLevel > 5000)
        powerLevel = 5000;
    return *this;
}

QNS QNS::operator/(int X)
{
    if (heatLevel - X <= 0) { heatLevel = 0; }
    else { heatLevel = heatLevel - X; }
    durability = durability + X;
    return *this;
}
#include "Avengers.cpp"
using std::string;

class Battle
{
private:
    // Stores log of battle events
    vector<string> battleLog;

    // Maps hero names to their Avenger objects
    unordered_map<string, Avenger> heros;

    // Maps enemy names to their Avenger objects
    unordered_map<string, Avenger> enemies;

    // Queue of available Quantum Nanotech Suits (QNS) for assignment/upgrade
    queue<QNS> suits;

    // Number of suits, heroes, and enemies as per input
    int noOfSuitsInput;
    int noOfHerosInput;
    int noOfEnimesInput;

public:
    // Takes input for counts of suits, heroes, and enemies
    inline void takeAllCount()
    {
        cin >> noOfSuitsInput >> noOfHerosInput >> noOfEnimesInput;
    }

    // Takes input for all suits and pushes into the suits queue
    void takeSuitInput();

    // Takes input for Avengers and assigns suits in first-come-first-serve order
    void takeAvengersInput();

    // Handles attack from hero/enemy 'name1' to hero/enemy 'name2'
    void Attack(string name1, string name2);

    // Repairs the specified Avenger's suit by the given amount
    void Repair(string name,int amount);

    // Boosts the specified Avenger's suit power by a multiplication factor
    void BoostPowerByFactor(string name,int amount);

    // Boosts the specified Avenger's suit power using another QNS suit
    void BoostPower(string name,QNS & newSuit);

    // Attempts to upgrade the specified Avenger's suit with the next available suit
    bool Upgrade(string name);

    // Prints the entire battle log with all recorded events
    void printBattleLog();

    // Returns the battle result:
    // 1 if heroes are winning, 0 for tie, -1 if enemies are winning
    int Result();

    // Starts the battle simulation and processes all commands
    void startBattle()
    {
        string cmd;
        cin >> cmd;
        while (true)
        {
            if (cmd == "Attack")
            {
                string name1, name2;
                cin >> name1 >> name2;
                this -> Attack(name1,name2);
            }
            else if (cmd == "Repair")
            {
                string name;
                int amount;
                cin >> name >> amount;
                this -> Repair(name,amount); 
            }
            else if (cmd == "BoostPowerByFactor")
            {
                string name;
                int x;
                cin >> name >> x;
                this -> BoostPowerByFactor(name,x);
            }
            else if (cmd == "BoostPower")
            {
                // Takes QNS details, creates a temporary QNS, and boosts power
                string name;
                int p1, d1, e1, h1;
                cin >> name >> p1 >> d1 >> e1 >> h1;
                if (p1 > 5000)
                    p1 = 5000;
                if (h1 < 0)
                    h1 = 0;
                QNS newsuit(p1, d1, e1, h1);
                this -> BoostPower(name,newsuit);
            }
            else if (cmd == "AvengerStatus")
            {
                // Prints the status of the specified Avenger
                string name;
                cin >> name;
                if (heros.find(name) != heros.end())
                    heros[name].printStatus();
                else
                    enemies[name].printStatus();
            }
            else if (cmd == "Upgrade")
            {
                // Attempts suit upgrade for the specified Avenger
                string name;
                cin >> name;
                bool isUpgraded = this -> Upgrade(name);
                if(isUpgraded)
                    battleLog.push_back(name + " upgraded");
                else
                    battleLog.push_back(name + " upgrade Fail");
            }
            else if (cmd == "End")
                break;
            else if (cmd == "PrintBattleLog")
                this -> printBattleLog();
            else if (cmd == "BattleStatus")
            {
                // Prints the current battle status
                int result = this -> Result();
                if (result == 1)
                    cout << "heroes are winning\n";
                else if (result == 0)
                    cout << "tie\n";
                else if(result == -1)
                    cout << "enemies are winning\n";
            }
            cin >> cmd;
        }
    }
};


void Battle::takeSuitInput()
{
    int p, d, e, h;
    for (int i = 0; i < noOfSuitsInput; i++)
    {
        cin >> p >> d >> e >> h;
        // checking for suit to be in limit
        if (p > 5000)
            p = 5000;
        if (h < 0)
            h = 0;
        QNS q(p, d, e, h);
        suits.push(q);
    }
}


void Battle::takeAvengersInput()
{
    string name;
    int s;
    for (int i = 0; i < (noOfHerosInput + noOfEnimesInput); i++)
    {
        cin >> name >> s;
        if (!suits.empty())
        {
            QNS q = suits.front();
            suits.pop();
            Avenger a(name, q, s);
            if (i < noOfHerosInput)
                heros[name] = a;
            else
                enemies[name] = a;
        }
        else
            cout << name << " is out of fight\n"; // constraint handling if no suits left
    }
}

void Battle::Attack(std::string name1, std::string name2)
{
    Avenger *attacker;
    Avenger *defender;
    if (heros.find(name1) != heros.end())
        attacker = &heros[name1];
    else
        attacker = &enemies[name1];

    if (enemies.find(name2) != enemies.end())
        defender = &enemies[name2];
    else
        defender = &heros[name2];

    attacker->attack(*defender);
    battleLog.push_back(name1 + " attacks " + name2);

    // Logs based on destruction or overheating status
    if (defender->isDestroyed())
        battleLog.push_back(name2 + " suit destroyed");
    else if (defender->isOverHeated())
        battleLog.push_back(name2 + " suit overheated");
}

void Battle::Repair(string name, int amount)
{
    if (heros.find(name) != heros.end())
        heros[name].repair(amount);
    else
        enemies[name].repair(amount);

    battleLog.push_back(name + " repaired");
}

void Battle::BoostPowerByFactor(string name,int amount)
{
    Avenger *avenger;
    if (heros.find(name) != heros.end())
        avenger = &heros[name];
    else
        avenger = &enemies[name];

    avenger->powerup(amount);
    string l = name + " boosted";
    battleLog.push_back(l);

    if (heros[name].isOverHeated())
        battleLog.push_back(name + " suit overheated");
}

void Battle::BoostPower(string name, QNS & newSuit)
{
    Avenger *avenger;
    if (heros.find(name) != heros.end())
        avenger = &heros[name];
    else
        avenger = &enemies[name];

    avenger->upgradeSuit(newSuit);
    string l = name + " boosted";
    battleLog.push_back(l);
    if (heros[name].isOverHeated())
        battleLog.push_back(name + " suit overheated");
}

bool Battle::Upgrade(string name)
{
    if (!suits.empty())
    {
        QNS q1 = suits.front();
        suits.pop();

        if (heros.find(name) != heros.end()) 
            heros[name].upgradeSuit(q1);
        else 
            enemies[name].upgradeSuit(q1);
        return true;
    }
    return false;
}

int Battle::Result()
{
    int heropower = 0, enemypower = 0;
    for (auto x : heros)
    {
        if (x.second.getsuitDuarability() > 0)
            heropower = heropower + x.second.getsuitDuarability() + x.second.getsuitpower();
    }
    for (auto x : enemies)
    {
        if (x.second.getsuitDuarability() > 0)
            enemypower = enemypower + x.second.getsuitDuarability() + x.second.getsuitpower();
    }
    if (heropower > enemypower) return 1;
    else if (heropower == enemypower) return 0;
    else return -1;
}

void Battle::printBattleLog()
{
    for (auto y : battleLog)
        cout << y << "\n";
}

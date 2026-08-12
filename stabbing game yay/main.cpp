#include <iostream>
#include <string>
class Player{
    private:
        std::string name;
        int health;
        int attackPower;
    public:
        Player(std::string n, int h, int a)
        : name(n), health(h), attackPower(a) {}

        void displayStats(){
            std::cout << "Name: " << name << '\n';
            std::cout << "Health: " << health << '\n';
            std::cout << "Attack: " << attackPower << '\n';
        }
        void attack(Player &enemy){
            std::cout << "*" << name << " stabs " << enemy.name << " in the chest with a knife*\n";
            enemy.health -= attackPower;
            if (enemy.health < 0){
                enemy.health = 0;
            }
        }
        void heal(int amount){
            health += amount;
            std::cout << "*Hardik (The Healer) heals " << name << " by " << amount << "*" << '\n';
            if (health > 100){
                health = 100;
            }
        }
        void displayHealth(){
            std::cout << "Remaining health of " << name << " = " << health << '\n';
        }
        int getHealth() const{
            return health;
        }
        std::string getName() const{
            return name;
        }
};
int main(){
    Player p1("Kanika", 100, 75);
    Player p2("Shaksham", 100, 75);
    p1.displayStats();
    std::cout << '\n' ;
    p2.displayStats();
    std::cout << '\n' ;
    p1.attack(p2);
    p2.displayHealth();
    std::cout << '\n' ;
    p2.heal(20);
    p2.displayHealth();
    return 0;
}
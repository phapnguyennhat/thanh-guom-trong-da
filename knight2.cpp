#include "knight2.h"
bool is_Paladin(int maxhp)
{
    if (maxhp < 1)
        return 0;
    int count = 0;
    for (int i = 0; i <= sqrt(maxhp); i++)
    {
        if (maxhp % i == 0)
            count++;
    }
    if (count == 1)
        return 1;
    return 0;
}
bool is_Lancelot(int maxhp)
{
    if (maxhp == 888)
        return 1;
    return 0;
}
bool is_Dragon(int maxhp)
{
    int a = maxhp % 10;
    maxhp /= 10;
    int b = maxhp % 10;
    maxhp /= 10;
    int c = maxhp % 10;
    maxhp /= 10;
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a)
        return 1;
    return 0;
}

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events)
{
    ifstream file(file_events);
    file >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    file.close();
}
Events::~Events()
{
    delete[] arr;
}
int Events::count() const
{
    return n;
}
int Events::get(int i) const
{
    return arr[i];
}
/* * * END implementation of class Events * * */

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
int BaseKnight::getlevel(){
    return level;
}
void BaseKnight::changehp(BaseOpponent*opponent)
{
    hp=hp-opponent->baseDamage*(opponent->level-level);
}
BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    BaseKnight *newKnight = nullptr;
    bool paradin = is_Paladin(maxhp);
    bool lancelot = is_Lancelot(maxhp);
    bool dragon = is_Dragon(maxhp);
    if (paradin)
    {
        newKnight = new ParadinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(PALADIN);
    }
    else if (lancelot)
    {
        newKnight = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(LANCELOT);
    }
    else if (lancelot)
    {
        newKnight = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(DRAGON);
    }
    else
    {
        newKnight = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(NORMAL);
    }
    return newKnight;
}
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}
void BaseKnight::setknighttype(KnightType type)
{
        knightType = type;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class BaseOpponent * * */
void BaseOpponent::setinfo_monster(int i, int eventid)
{
    level = (i + eventid) % 10 + 1;
    int arr_baseDamage[6] = {0, 10, 15, 45, 75, 95};
    int arr_gil[6] = {0, 100, 150, 450, 750, 800};
    baseDamage = arr_baseDamage[eventid];
    gil = arr_gil[eventid];
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class ArmyKnights * * */
ArmyKnights ::ArmyKnights(const string &file_armyknights)
{
    ifstream file(file_armyknights);
    file >> n;
    quandoi = new BaseKnight *[n + 1];
    int hp;
    int level;
    int phoenixdownI;
    int gil;
    int antidote;
    BaseKnight *newKnight;
    for (int i = 1; i <= n; i++)
    {
        newKnight = new BaseKnight;
        file >> hp >> level >> phoenixdownI >> gil >> antidote;
        quandoi[i] = newKnight->create(i, hp, level, gil, antidote, phoenixdownI);
        delete newKnight;
    }
    file.close();
}
ArmyKnights::~ArmyKnights()
{
    for (int i = 0; i < n + 1; i++)
    {
        delete[] quandoi[i];
    }
    delete[] quandoi;
}
//  return false neu hiep si cuoi chet
bool ArmyKnights::fight(BaseOpponent*opponent)  //nhung thay doi cua mang doi quan se viet tren ham nay 
{
    if(lastKnight()->getlevel()<opponent->level) //danh thua thiet lap lai hp, ham hoi sinh se de rieng
    {
        lastKnight()->changehp(opponent); // goi them ham hoi sinh
    }

    if(lastKnight()==NULL) return false;
}
//return true neu danh bai boss
bool ArmyKnights::adventure(Events*events)  
{
    BaseOpponent *monster=new BaseOpponent();
    for (int i = 0; i < events->count(); i++)
    {
        monster->setinfo_monster(i,events->get(i));
        if(fight(monster)==0){
            return false;
        }
    }
    
}
int ArmyKnights::count() const //tra ve so luong knight
{
    return n;
}
void ArmyKnights::printInfo() const
{
    cout << "No. knights: " << this->count();
    if (this->count() > 0)
    {
        BaseKnight *lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
         << ";LancelotSpear:" << this->hasLancelotSpear()
         << ";GuinevereHair:" << this->hasGuinevereHair()
         << ";ExcaliburSword:" << this->hasExcaliburSword()
         << endl
         << string(50, '-') << endl;
}
void ArmyKnights::printResult(bool win) const
{
    cout << (win ? "WIN" : "LOSE") << endl;
}
BaseKnight *ArmyKnights::lastKnight() const
{
    return quandoi[n];
}
bool ArmyKnights::hasExcaliburSword() const{
    return excaliburSword;
}
bool ArmyKnights::hasPaladinShield() const{
    return paladinshield;
}
bool ArmyKnights::hasLancelotSpear() const{
    return lancelotspear;
}
bool ArmyKnights::hasGuinevereHair() const{
    return guineverehair;
}
/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */
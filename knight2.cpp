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

/* * * BEGIN implementation of class BaseItem * * */
bool Antidote::canUse(BaseKnight *knight)
{
    if(knight->hasPoison()&&quantity!=0) return 1;
    return 0;
}
void Antidote::use(BaseKnight*knight)
{
    knight->giai_doc();
    quantity--;
}
bool PhoenixdownI::canUse(BaseKnight*knight)
{
    if(quantity!=0&&knight->gethp()<=0) return 1;
    return 0;
}
void PhoenixdownI::use(BaseKnight*knight)
{
    knight->sethp(knight->getmaxhp());
    quantity--;
}
bool PhoenixdownII::canUse(BaseKnight*knight)
{
    if(quantity!=0&&knight->gethp()<knight->getmaxhp()/4) return 1;
    return 0;
}
void PhoenixdownII::use(BaseKnight*knight)
{
    knight->sethp(knight->getmaxhp());
    quantity--;
}
bool PhoenixdownIII::canUse(BaseKnight*knight)
{
    if(quantity!=0&&knight->gethp()<knight->getmaxhp()/3) return 1;
    return 0;
}
void PhoenixdownIII::use(BaseKnight*knight)
{
    if(knight->gethp()<=0) knight->sethp(knight->getmaxhp()/3);
    else knight->sethp(knight->gethp()+knight->getmaxhp()/4);
    quantity--;
}
bool PhoenixdownIV::canUse(BaseKnight*knight)
{
    if(quantity!=0&&knight->gethp(),knight->getmaxhp()/2) return 1;
    return 0;
}
void PhoenixdownIV::use(BaseKnight *knight)
{
    if(knight->gethp()<=0) knight->sethp(knight->getmaxhp()/2);
    else knight->sethp(knight->gethp()+knight->getmaxhp()/5);
    quantity--;
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseKnight * * */
KnightType BaseKnight::getknighttype()
{
    return knightType;
}
void BaseKnight::setgil(int gi)
{
    gil=gi;
}
int BaseKnight::getgil()
{
    return gil;
}
void BaseKnight::sethp(int mau)
{
    hp=mau;
}
int BaseKnight::gethp()
{
    return hp;
}
int BaseKnight::getmaxhp()
{
    return maxhp;
}
bool BaseKnight::hasPoison()
{
    return poison;
}
void BaseKnight::trung_doc(){
    poison=1;
}
void BaseKnight::giai_doc(){
    poison=0;
}
int BaseKnight::getlevel(){
    return level;
}
void BaseKnight::setlevel(int le)
{
    level=le;
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
void OmegaWeapon::fight(BaseKnight*knight)
{

}
void DurianGarden::fight(BaseKnight*knight)
{
    knight->sethp(knight->getmaxhp());
}
void Tornbery::fight(BaseKnight*knight)
{
    if(knight->getlevel()<level)
    {
        knight->trung_doc();
        //luc tui do de giai doc
        //neu khong giai doc duoc
        if(knight->hasPoison()==1)
        {
            knight->sethp(knight->gethp()-10);
            //bo 3 vat pham
        }
        if(knight->gethp()<=0)
        {
            //hien thuc ham hoi sinh
        }

    }
    else
    {
        knight->setlevel(knight->getlevel()+1);
    }
}
void QueenOfCards::fight(BaseKnight*knight)
{
    if(knight->getlevel()<level)
    {
        knight->setgil(knight->getgil()/2);
    }
    else
    {
        knight->setgil(knight->getgil()*2);
        knight->setlevel(knight->getlevel()+1);
        //hien thuc ham chuyen tien len tren
    }
}
void NinaDeRings::fight(BaseKnight*knight)
{
    if(knight->getgil()>=50&&knight->gethp()<knight->getmaxhp()/3)
    {
        knight->setgil(knight->getgil()-50);
        knight->sethp(knight->gethp()+knight->getmaxhp()/5);
    }
}
void BaseOpponent::fight(BaseKnight*knight)
{
    if (knight->getlevel() < level)
    {
        knight->sethp(knight->gethp() - baseDamage * (knight->getlevel() - level));
        if(knight->gethp()<=0);  //tim tui do hien thuc ham hoi sinh
    }
    else
    {
        knight->setgil(knight->getgil() + gil);
        // hien thuc ham chuyen tien len tren
        knight->setlevel(knight->getlevel() + 1);
    }
}
void BaseOpponent::set_info(int i,int eventid)
{
    level=(i+eventid)%10+1;
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
    
    if(lastKnight()==NULL) return false;
    return true;
}
//return true neu danh bai boss
bool ArmyKnights::adventure(Events*events)  
{
    // BaseOpponent *monster=new BaseOpponent();
    // for (int i = 0; i < events->count(); i++)
    // {
    //     monster->setinfo_monster(i,events->get(i));
    //     if(fight(monster)==0){
    //         return false;
    //     }
    // }
    
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
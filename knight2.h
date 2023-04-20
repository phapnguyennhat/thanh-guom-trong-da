#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
bool is_Paladin(int maxhp);
bool is_Lancelot(int maxhp);
bool is_Dragon(int maxhp);
enum ItemType
{ ANTIDOTE,PHOENIXDOWNI,PHOENIXDOWNII,PHOENIXDOWNIII,PHOENIXDOWNIV};
enum KnightType
{
    PALADIN = 0,
    LANCELOT = 1,
    DRAGON = 2,
    NORMAL = 3
};

class Events
{
public:
    int count() const;
    int get(int i) const;
    Events();
    Events(const string &file_events);
    ~Events();

private:
    int *arr;
    int n;
};
class BaseKnight;
class BaseItem
{
protected:
    ItemType type;
public:
    ItemType getTypeItem();
    void setItemType(ItemType type);
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
   static BaseItem*create(ItemType type);
};
class Antidote:public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
     Antidote()
     {
        type=ANTIDOTE;
     }
};
class PhoenixdownI :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownI()
    {
        type=PHOENIXDOWNI;
    }
};
class PhoenixdownII :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownII()
    {
        type=PHOENIXDOWNII;
    }
};
class PhoenixdownIII :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownIII()
    {
        type=PHOENIXDOWNIII;
    }
};
class PhoenixdownIV :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownIV()
    {
        type=PHOENIXDOWNIV;
    }
};
class BaseBag
{
protected:
    BaseItem*item;
    BaseBag*next;
    int size;
public:
    BaseBag*getnext();
    BaseItem*getitem();
    void popFront(BaseBag**head);
    void swap(BaseBag**head,int vitri);
    int getSoluongItem(BaseBag*head);
    void nhat_item(BaseBag**head,BaseItem*item);
    BaseBag*makeItem(BaseItem*take_item);   //tao phan tu
    virtual bool insertFirst(BaseItem *item,BaseKnight*knight);
    virtual BaseItem *get(ItemType itemType,BaseBag*Bag);
    virtual string toString(BaseBag*bag) const;
};
class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int gil;
    int antidote;
    int phoenixdownI;   //chua chac co cai nay
    BaseBag *bag=NULL;       //tui do
    KnightType knightType;
    bool poison=0;
public:
    BaseBag**getdiachibag();
    int getAntidote();
    void setAntidote(int anti);
    int getPhoenixI();
    void setPhoenixI(int phoenix);
    void setbag(BaseBag*tmp);
    void tim_do(BaseKnight*knight);
    BaseBag* getbag();
    KnightType getknighttype();
    void setgil(int gi);
    int getgil();
    void sethp(int mau);
    int gethp();
    int getmaxhp();
    void trung_doc();
    void giai_doc();
    bool hasPoison();
    void setlevel(int le);
    int getlevel();
    void setknighttype(KnightType type);
    string toString() const;
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class BagPaladin:public BaseBag
{
public:
    // BagPaladin();
    BagPaladin(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagLancelot:public BaseBag
{
public:
    // BagLancelot();
    BagLancelot(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagDragon:public BaseBag
{
public:
    bool insertFirst(BaseItem *item,BaseKnight*knight);
    // BagDragon();
    BagDragon(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagNormal:public BaseBag
{
public:
    // BagNormal();
    BagNormal(BaseKnight*knight,int phoenidownI,int antidote);
};

class BaseOpponent
{
    protected:
    int level;
    int gil;
    int baseDamage;
    public:
    bool winOmegaWeapon=0;
    bool winHades=0;
    void set_info(int i,int eventid);       //set level
    virtual void fight(BaseKnight*knight);
    static BaseOpponent*create(int eventid);
};
class MadBear :public BaseOpponent
{
public:
    MadBear();
};
class Bandit:public BaseOpponent
{
public:
    Bandit();
};
class LordLupin :public BaseOpponent
{
public:
    LordLupin();
};
class Elf:public BaseOpponent
{
public:
    Elf();
};
class Troll:public BaseOpponent
{
public:
    Troll();
};
class Tornbery:public BaseOpponent
{
public:
    void fight(BaseKnight*knight);
};
class QueenOfCards:public BaseOpponent
{
    public:
    void fight(BaseKnight*knight);
};
class NinaDeRings:public BaseOpponent
{
public:
    void fight(BaseKnight*knight);
};
class DurianGarden:public BaseOpponent
{
    public:
    void fight(BaseKnight*knight);
};
class OmegaWeapon :public BaseOpponent
{
    public:
    void fight(BaseKnight*knight);
};
class Hades :public BaseOpponent
{
public:
    void fight(BaseKnight*knight);

};

class ParadinKnight : public BaseKnight
{
public:
    // ParadinKnight();
    ParadinKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
        knightType=PALADIN;
    }
};
class LancelotKnight : public BaseKnight
{
public:
    // LancelotKnight();
    LancelotKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
        knightType=LANCELOT;
    }
};
class DragonKnight : public BaseKnight
{
public:
    // DragonKnight();
    DragonKnight(int i, int max, int le, int gi, int anti, int pho)
    {

        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
        knightType=DRAGON;
    }
};
class NormalKnight : public BaseKnight
{
public:
    // NormalKnight();
    NormalKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
        knightType=NORMAL;
    }
};

class ArmyKnights
{
private:
    bool winBoss=0;
    bool winOmegaWeapon=0;
    bool winhades=0;
    BaseKnight **quandoi;
    int n;
    bool paladinshield=0;
    bool lancelotspear=0;
    bool guineverehair=0;
    bool excaliburSword=0;
public:
    void fightUltimecia();
    void take_item(BaseKnight*knight,BaseItem*item);
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure(Events *events);
    int count() const;
    BaseKnight *lastKnight() const;
    bool win();
    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
};



class KnightAdventure
{
private:
    ArmyKnights *armyKnights;
    Events *events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__

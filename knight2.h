#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

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
    int *arr=NULL;
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
       this-> type=ANTIDOTE;
     }
};
class PhoenixdownI :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownI()
    {
       this-> type=PHOENIXDOWNI;
    }
};
class PhoenixdownII :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownII()
    {
       this-> type=PHOENIXDOWNII;
    }
};
class PhoenixdownIII :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownIII()
    {
       this-> type=PHOENIXDOWNIII;
    }
};
class PhoenixdownIV :public BaseItem
{
    public:
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
    PhoenixdownIV()
    {
       this-> type=PHOENIXDOWNIV;
    }
};
class BaseBag
{
public:
    BaseItem*item=NULL;
    BaseBag*next=NULL;
    static BaseBag*create(KnightType type);
    BaseBag();
    virtual BaseItem *get(ItemType itemType,BaseBag*Bag);
    // virtual string toString(BaseBag*bag) const;
    //insertfirst
};
// CAC SETUP CHO NODE
BaseBag*makeNode(BaseItem*item);
void swap(BaseBag**head,int vitri);
void popFront(BaseBag**head);
int getSoluongItem(BaseBag*head);
void nhat_item(BaseBag**head,BaseItem*item);
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
    int sizebag;
public:
   virtual bool insertFirst(BaseItem*item);
    static bool is_Lancelot(int maxhp);
    static bool is_Dragon(int maxhp);
    static bool is_Paladin(int maxhp);
    BaseBag**getdiachibag();
    int getAntidote();
    void setAntidote(int anti);
    int getPhoenixI();
    void setPhoenixI(int phoenix);
    void setbag();
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
    string ToString(BaseBag*bag) const;
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    ~BaseKnight();
};
class BagPaladin:public BaseBag
{
public:
    // BagPaladin();
    // BagPaladin(int phoenixdownI,int antidote);
};
class BagLancelot:public BaseBag
{
public:
    // BagLancelot();
    // BagLancelot(int phoenixdownI,int antidote);
};
class BagDragon:public BaseBag
{
public:
    // BagDragon();
    // BagDragon(int phoenixdownI,int antidote);
};
class BagNormal:public BaseBag
{
public:
    // BagNormal();
    // BagNormal(int phoenixdownI,int antidote);
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
    OmegaWeapon();
};
class Hades :public BaseOpponent
{
public:
    void fight(BaseKnight*knight);
    Hades();
};

class PaladinKnight : public BaseKnight
{
public:
    // PaladinKnight();
    // BaseBag*makeItem(BaseItem*take_item);
    PaladinKnight(int i, int max, int le, int gi, int anti, int pho);
};
class LancelotKnight : public BaseKnight
{
public:
    // LancelotKnight();
    // BaseBag*makeItem(BaseItem*take_item);
    LancelotKnight(int i, int max, int le, int gi, int anti, int pho);
};
class DragonKnight : public BaseKnight
{
public:
    // DragonKnight();
    // bool insertFirst(BaseItem*item);
    // BaseBag*makeItem(BaseItem*take_item);
    bool insertFirst(BaseItem*item);
    DragonKnight(int i, int max, int le, int gi, int anti, int pho);
};
class NormalKnight : public BaseKnight
{
public:
    // NormalKnight();
    // BaseBag*makeItem(BaseItem*take_item);
    NormalKnight(int i, int max, int le, int gi, int anti, int pho);
   
};

class ArmyKnights
{
private:
    bool winBoss;
    bool winOmegaWeapon;
    bool winhades;
    BaseKnight **quandoi=NULL;
    int n;
    bool paladinshield;
    bool lancelotspear;
    bool guineverehair;
    bool excaliburSword;
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
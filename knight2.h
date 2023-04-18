#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
bool is_Paladin(int maxhp);
bool is_Lancelot(int maxhp);
bool is_Dragon(int maxhp);
enum ItemType
{ ANTIDOTE,PHOENIXDOWNI,PHOENIXDOWNII,PHOENIXDOWNIII,PHOENIXDOWNIV};
string nameItem[5]={"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
enum KnightType
{
    PALADIN = 0,
    LANCELOT = 1,
    DRAGON = 2,
    NORMAL = 3
};

class BaseItem
{
protected:
    ItemType itemType;
    int quantity;
public:
    ItemType getTypeItem();
    void setItemType(ItemType type);
    BaseItem*create(ItemType type);
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class BaseBag
{
public:
    int size;
    BaseItem*item;
    int soluongitem=0;
    BaseBag*next;
    // BaseBag*Bag;
public:
    BaseItem*getitem();
    void popFront(BaseBag**head);
    void swap(BaseBag**head,int vitri);
    int set_soluongitem(BaseBag*head);
    void nhat_item(BaseBag**head,BaseItem*item);
    BaseBag*makeItem(BaseItem*take_item);   //tao phan tu
    virtual bool insertFirst(BaseItem *item);
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
    static BaseBag *bag;       //tui do
    KnightType knightType;
    bool poison=0;
public:
    void tim_do(BaseKnight*knight);
    BaseBag* getbag();
    int getsize();
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
    BaseKnight();
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class BagPaladin:public BaseBag,public BaseKnight
{
public:
    BagPaladin();
    BagPaladin(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagLancelot:public BaseBag,public BaseKnight
{
public:
    BagLancelot();
    BagLancelot(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagDragon:public BaseBag ,public BaseKnight
{
public:
    bool insertFirst(BaseItem *item);
    BagDragon();
    BagDragon(BaseKnight*knight,int phoenidownI,int antidote);
};
class BagNormal:public BaseBag,public BaseKnight
{
public:
    BagNormal();
    BagNormal(BaseKnight*knight,int phoenidownI,int antidote);
};

class BaseOpponent
{
    protected:
    int level;
    int gil;
    int baseDamage;
    public:
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
    bool winOmegaWeapon=0;
    void fight(BaseKnight*knight);
};
class Hades :public BaseOpponent
{
public:
    bool winHades=0;
    void fight(BaseKnight*knight);

};

class ParadinKnight : public BaseKnight
{
public:
    ParadinKnight();
    ParadinKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
    }
};
class LancelotKnight : public BaseKnight
{
public:
    LancelotKnight();
    LancelotKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
    }
};
class DragonKnight : public BaseKnight
{
public:
    DragonKnight();
    DragonKnight(int i, int max, int le, int gi, int anti, int pho)
    {

        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
    }
};
class NormalKnight : public BaseKnight
{
public:
    NormalKnight();
    NormalKnight(int i, int max, int le, int gi, int anti, int pho)
    {
        id = i;
        maxhp = max;
        level = le;
        gil = gi;
        antidote = anti;
        phoenixdownI = pho;
    }
};

class ArmyKnights
{
private:
    bool winOmegaWeapon=0;
    bool winhades=0;
    BaseKnight **quandoi;
    int n;
    bool paladinshield;
    bool lancelotspear;
    bool guineverehair;
    bool excaliburSword;
public:
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure(Events *events);
    int count() const;
    BaseKnight *lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;
    void printInfo() const;
    void printResult(bool win) const;
};


class Antidote:public BaseItem
{
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
};
class PhoenixdownI :public BaseItem
{
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
};
class PhoenixdownII :public BaseItem
{
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
};
class PhoenixdownIII :public BaseItem
{
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
};
class PhoenixdownIV :public BaseItem
{
    bool canUse(BaseKnight *knight);
    void use(BaseKnight *knight);
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
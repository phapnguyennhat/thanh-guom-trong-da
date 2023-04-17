#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG
bool is_Paladin(int maxhp);
bool is_Lancelot(int maxhp);
bool is_Dragon(int maxhp);
enum ItemType
{ /* TODO: */ };

class BaseBag
{
public:
    virtual bool insertFirst(BaseItem *item);
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const;
};

class BaseOpponent
{
    public:
    int level;
    int gil;
    int baseDamage;
    public:
    void setinfo_monster(int i,int eventid);
};

enum KnightType
{
    PALADIN = 0,
    LANCELOT = 1,
    DRAGON = 2,
    NORMAL = 3
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
    BaseBag *bag;       //tui do
    KnightType knightType;

public:
    void revival(int hp,int gil,int phoenixdown);
    int getlevel();
    void changehp(BaseOpponent*opponent);
    void setknighttype(KnightType type);
    string toString() const;
    BaseKnight();
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
};

class ArmyKnights
{
private:
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

class BaseItem
{
public:
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class Events
{
public:
    int count() const;
    int get(int i) const;
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
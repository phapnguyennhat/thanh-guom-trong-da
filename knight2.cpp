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
BaseItem* BaseBag::getitem()
{
    return item;
}
string BaseBag::toString(BaseBag*bag) const
{
BaseBag*tmp=bag;
string nameItem[5]={"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
string str="";
str="Bag[count="+to_string(soluongitem)+";"+nameItem[bag->item->getTypeItem()];
while(bag->next!=NULL)
{
    tmp=tmp->next;
    str=str+","+nameItem[tmp->item->getTypeItem()];
}
str=str+"]";
return str;
}
void BaseBag::popFront(BaseBag**head)
{
    if((*head)==NULL) return;
    BaseBag*del=(*head);
    (*head)=(*head)->next;
    delete del;
}
void BaseBag:: swap(BaseBag**head,int vitri)
{
    BaseBag*tmp=(*head);
    for (int i = 1; i <= vitri-1; i++)
    {
        tmp=tmp->next;
    }
    BaseItem*trunggian=(*head)->item;
    (*head)->item=tmp->item;
    tmp->item=trunggian;
    
}
int BaseBag::set_soluongitem(BaseBag*head)
{
    int count=0;
    while(head!=NULL)
    {
        count++;
        head=head->next;
    }
    soluongitem=count;
    return count;
}
void BaseBag::nhat_item(BaseBag**head,BaseItem* item)
{
    BaseBag*newItem=makeItem(item);
    newItem->next=(*head);
    (*head)=newItem;
}
BaseBag* BaseBag::makeItem(BaseItem* take_item)
{
    BaseBag*newitem=new BaseBag();
    newitem->item=take_item;
    newitem->next=NULL;
    return newitem;
}
bool BaseBag::insertFirst(BaseItem*item)
{
    if(soluongitem>=size) return 0;
    return 1;
}
bool BagDragon::insertFirst(BaseItem*item)
{
    if(item->getTypeItem()==ANTIDOTE)return 0;
    else if(soluongitem>=size) return 0;
    return 1;
}
BaseItem* BaseBag::get(ItemType itemType,BaseBag*bag)
{
    if(bag->item->getTypeItem()!=itemType) return NULL;
    else if(bag->item->getTypeItem()==itemType) return bag->item;
    //nếu đối tượng đầu danh sách cùng kiểu với itemtype thì tra về cái đó không thì return null
}
BagPaladin:: BagPaladin(BaseKnight*knight,int phoenixdowI,int antidote)
{
    size=9999;
     BaseItem*item=nullptr;
    for (int i = 0; i < phoenixdowI; i++)
    {
        if(knight->bag->insertFirst(item)==1)
        {
        item->create(PHOENIXDOWNI);
        item->setItemType(PHOENIXDOWNI);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
    for (int i = 0; i < antidote; i++)
    {
         if(knight->bag->insertFirst(item))
        {
        item->create(ANTIDOTE);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
}
BagLancelot:: BagLancelot(BaseKnight*knight,int phoenixdowI,int antidote)
{
    size=16;
    BaseItem*item;
  for (int i = 0; i < phoenixdowI; i++)
    {
        if(knight->bag->insertFirst(item)==1)
        {
        item->create(PHOENIXDOWNI);
        item->setItemType(PHOENIXDOWNI);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
    for (int i = 0; i < antidote; i++)
    {
         if(knight->bag->insertFirst(item))
        {
        item->create(ANTIDOTE);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
}
BagDragon:: BagDragon(BaseKnight*knight,int phoenixdowI,int antidote)
{
    size=14;
    BaseItem*item;
    for (int i = 0; i < phoenixdowI; i++)
    {
        if(knight->bag->insertFirst(item)==1)
        {
        item->create(PHOENIXDOWNI);
        item->setItemType(PHOENIXDOWNI);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
    for (int i = 0; i < antidote; i++)
    {
         if(knight->bag->insertFirst(item))
        {
        item->create(ANTIDOTE);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
}
BagNormal:: BagNormal(BaseKnight*knight,int phoenixdowI,int antidote)
{
    size=19;
    BaseItem*item;
    for (int i = 0; i < phoenixdowI; i++)
    {
        if(knight->bag->insertFirst(item)==1)
        {
        item->create(PHOENIXDOWNI);
        item->setItemType(PHOENIXDOWNI);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
    for (int i = 0; i < antidote; i++)
    {
         if(knight->bag->insertFirst(item))
        {
        item->create(ANTIDOTE);
        nhat_item(&knight->bag,item);
        knight->bag->set_soluongitem(knight->bag);
        }
    }
}

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseItem * * */
ItemType BaseItem::getTypeItem()
{
    return type;
}
void BaseItem::setItemType(ItemType type)
{
    this->type=type;
}
BaseItem* BaseItem::create(ItemType type)
{
    static BaseItem* newItem=nullptr;
    switch (type)
    {
    case ANTIDOTE:
        newItem=new Antidote();
        newItem->setItemType(type);
        break;
    case PHOENIXDOWNI:
        newItem=new PhoenixdownI();
        newItem->setItemType(type);
        break;
    case PHOENIXDOWNII:
        newItem=new PhoenixdownII();
        newItem->setItemType(type);
        break;
    case PHOENIXDOWNIII:
        newItem=new PhoenixdownIII();
        newItem->setItemType(type);
        break;
    case PHOENIXDOWNIV:
        newItem=new PhoenixdownIV();
        newItem->setItemType(type);
        break;
    return newItem;
    }
}
bool Antidote::canUse(BaseKnight *knight)
{
    if(knight->hasPoison()) return 1;
    return 0;
}
void Antidote::use(BaseKnight*knight)
{
    knight->giai_doc();
}
bool PhoenixdownI::canUse(BaseKnight*knight)
{
    if(knight->gethp()<=0) return 1;
    return 0;
}
void PhoenixdownI::use(BaseKnight*knight)
{
    knight->sethp(knight->getmaxhp());
}
bool PhoenixdownII::canUse(BaseKnight*knight)
{
    if(knight->gethp()<knight->getmaxhp()/4) return 1;
    return 0;
}
void PhoenixdownII::use(BaseKnight*knight)
{
    knight->sethp(knight->getmaxhp());
}
bool PhoenixdownIII::canUse(BaseKnight*knight)
{
    if(knight->gethp()<knight->getmaxhp()/3) return 1;
    return 0;
}
void PhoenixdownIII::use(BaseKnight*knight)
{
    if(knight->gethp()<=0) knight->sethp(knight->getmaxhp()/3);
    else knight->sethp(knight->gethp()+knight->getmaxhp()/4);
}
bool PhoenixdownIV::canUse(BaseKnight*knight)
{
    if(knight->gethp(),knight->getmaxhp()/2) return 1;
    return 0;
}
void PhoenixdownIV::use(BaseKnight *knight)
{
    if(knight->gethp()<=0) knight->sethp(knight->getmaxhp()/2);
    else knight->sethp(knight->gethp()+knight->getmaxhp()/5);
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseKnight * * */

void BaseKnight::tim_do(BaseKnight*knight)
{
    BaseBag*tmp=knight->bag;
    int i=0;
    while(tmp!=NULL){
        i++;
        if(tmp->getitem()->canUse(knight)==1)
        {
            tmp->swap(&knight->bag,i);
            knight->bag->getitem()->use(knight);
            knight->bag->popFront(&knight->bag);
            knight->bag->set_soluongitem(bag);
            break;
        }
        tmp=tmp->next;
    }
}
BaseBag* BaseKnight::getbag()
{
    return bag;
}
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
        bag=new BagPaladin(newKnight,phoenixdownI,antidote);
    }
    else if (lancelot)
    {
        newKnight = new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(LANCELOT);
        bag=new BagLancelot(newKnight,phoenixdownI,antidote);
    }
    else if (dragon)
    {
        newKnight = new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(DRAGON);
        bag=new BagDragon(newKnight,phoenixdownI,antidote);
    }
    else
    {
        newKnight = new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        newKnight->setknighttype(NORMAL);
        bag=new BagNormal(newKnight,phoenixdownI,antidote);
    }
    return newKnight;
}
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString(bag) + ",knight_type:" + typeString[knightType] + "]";
    return s;
}
void BaseKnight::setknighttype(KnightType type)
{
        knightType = type;
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class BaseOpponent * * */
MadBear::MadBear()
{
    gil=100;
    baseDamage=10;
}
Bandit::Bandit()
{
    gil=150;
    baseDamage=15;
}
LordLupin::LordLupin()
{
    gil=450;
    baseDamage=45;
}
Elf::Elf()
{
    gil=750;
    baseDamage=75;
}
Troll::Troll()
{
    gil=800;
    baseDamage=95;
}
void Hades::fight(BaseKnight*knight)
{
    if(knight->getlevel()==10||(knight->getknighttype()==PALADIN&&knight->getlevel()>8))
    {
        winHades=1;
        // nhan khien paladin
    }
    else 
    {
        knight->sethp(0);
    }
}
void OmegaWeapon::fight(BaseKnight*knight)
{
    if(knight->getknighttype()==DRAGON||(knight->gethp()==knight->getmaxhp()&&knight->getlevel()==10))
    {
        knight->setlevel(10);
        knight->setgil(999);
        winOmegaWeapon=1;
    }
    else
    {
        knight->sethp(0);
    }
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
BaseOpponent* BaseOpponent::create(int eventid)
{
   static BaseOpponent*newopponent=NULL;
    switch (eventid)
    {
    case 1:
        newopponent=new MadBear();
        break;
    case 2:
        newopponent=new Bandit();
        break;
    case 3:
        newopponent=new LordLupin();
        break;
    case 4:
        newopponent=new Elf();
        break;
    case 5:
        newopponent=new Troll();
        break;
    case 6:
        newopponent=new Tornbery();
        break;
    case 7:
        newopponent=new QueenOfCards();
        break;
    case 8:
        newopponent=new NinaDeRings();
        break;
    case 9:
        newopponent=new DurianGarden();
        break;
    case 10:
        newopponent=new OmegaWeapon();
        break;
    case 11:
        newopponent=new Hades();
        break;
    default:
        break;
    }
    return newopponent;
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
    opponent->fight(quandoi[n]);
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
void KnightAdventure::loadArmyKnights(const string &file_armyknights)
{
    armyKnights=new ArmyKnights(file_armyknights);
}
void KnightAdventure::loadEvents(const string &file_events)
{
    events=new Events(file_events);
}
/* * * END implementation of class KnightAdventure * * */
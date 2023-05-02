#include "knight2.h"

/* * * BEGIN implementation of class Events * * */
Events::Events(const string &file_events)
{
    ifstream file(file_events);
    file >> n;
    arr=new int[n];
    for (int i = 0; i < n; i++)
    {
        file>> arr[i];
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

BaseBag**BaseKnight::getdiachibag()
{
    return &bag;
}

BaseItem* BaseBag::get(ItemType itemType,BaseBag*bag)
{
    if(bag->item->getTypeItem()==itemType) return bag->item;
    return nullptr;
    //nếu đối tượng đầu danh sách cùng kiểu với itemtype thì tra về cái đó không thì return null
}
BaseBag::BaseBag()
{
    this->next=NULL;
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
    // static BaseItem* newItem=nullptr;
    if(type== ANTIDOTE)
    {
        // newItem=new Antidote();
        // newItem->setItemType(type);
        return new Antidote();
    }
    else if(type== PHOENIXDOWNI)
    {
        // newItem=new PhoenixdownI();
        // newItem->setItemType(type);
        return new PhoenixdownI();
    }
    else if(type==PHOENIXDOWNII)
    {
        // newItem=new PhoenixdownII();
        // newItem->setItemType(type);
        return new PhoenixdownII();
    }
    else if(type==PHOENIXDOWNIII)
    {
        // newItem=new PhoenixdownIII();
        // newItem->setItemType(type);
        return new PhoenixdownIII();
    }
    else if(type==PHOENIXDOWNIV)
    {
        // newItem=new PhoenixdownIV();
        // newItem->setItemType(type);
        return new PhoenixdownIV();
    }
    return nullptr;
}
bool Antidote::canUse(BaseKnight *knight)
{
    if(knight->hasPoison()) return true;
    return false;
}
void Antidote::use(BaseKnight*knight)
{
    knight->giai_doc();
    // cout<<"giai doc ne";
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
    if(knight->gethp()<knight->getmaxhp()/2) return 1;
    return 0;
}
void PhoenixdownIV::use(BaseKnight *knight)
{
    if(knight->gethp()<=0) knight->sethp(knight->getmaxhp()/2);
    else knight->sethp(knight->gethp()+knight->getmaxhp()/5);
}
/* * * END implementation of class BaseItem * * */

/* * * BEGIN implementation of class BaseKnight * * */
BaseKnight::~BaseKnight()
{
    int n=getSoluongItem(bag);
    for (int i = 0; i < n; i++)
    {
        popFront(&bag);
    }
}
BaseBag*makeNode(BaseItem*item)
{
    BaseBag*tmp=new BaseBag();
    tmp->item=item;
    tmp->next=NULL;
    return tmp;
}
void popFront(BaseBag**head)
{
    if((*head)==NULL) return;
    BaseBag*del=(*head);
    (*head)=(*head)->next;
    delete del;
    
}
void swap(BaseBag**head,int vitri)
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
 int getSoluongItem(BaseBag*head)
{
    int count=0;
    while(head!=NULL)
    {
        count=count+1;
        head=head->next;
    }
    return count;
}

void nhat_item(BaseBag**head,BaseItem* item)
{
    BaseBag*newItem=makeNode(item);
    newItem->next=(*head);
    (*head)=newItem;
}


void BaseKnight::setPhoenixI(int phoenix)
{
    phoenixdownI=phoenix;
}
int BaseKnight::getPhoenixI()
{
    return phoenixdownI;
}
void BaseKnight::setAntidote(int anti)
{
    antidote=anti;
}
int BaseKnight::getAntidote()
{
    return antidote;
}

BaseBag* BaseKnight::getbag()
{
    return bag;
}
void BaseKnight::tim_do(BaseKnight*knight)
{
    BaseBag*tmp=bag;
    int i=0;
    while(tmp!=NULL){
        i++;
        if(tmp->item->canUse(knight)==1)
        {
           
            swap(&bag,i);
            bag->item->use(knight);
            popFront(&bag);
            break;
        }
        tmp=tmp->next;
    }
}
void BaseKnight::setbag()
{
    this->bag=nullptr;
}
KnightType BaseKnight::getknighttype()
{
    return knightType;
}
void BaseKnight::setgil(int gi)
{
    gil=gi;
}
int BaseKnight::getId()
{
    return id;
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
bool BaseKnight:: insertFirst(BaseItem*item)
{
    if(getSoluongItem(bag) >=sizebag) return 0;
    else if(item->getTypeItem()==ANTIDOTE&&antidote>=5)return 0;
    else if(item->getTypeItem()==PHOENIXDOWNI&&phoenixdownI>=5) return 0;
    return 1;
}
bool DragonKnight::insertFirst(BaseItem*item)
{
        if(item->getTypeItem()==ANTIDOTE)return 0;
    else if(getSoluongItem(bag)>=sizebag) return 0;
    else if(phoenixdownI>=5) return 0;
    return 1;
}
void BaseKnight::setlevel(int le)
{
    level=le;
}
bool BaseKnight::is_Dragon(int maxhp)
{
    int a = maxhp % 10;
    maxhp /= 10;
    int b = maxhp % 10;
    maxhp /= 10;
    int c = maxhp % 10;
    maxhp /= 10;
    if (a * a + b * b == c * c || a * a + c * c == b * b || b * b + c * c == a * a) return 1;
    return 0;
}
bool BaseKnight::is_Lancelot(int maxhp)
{
if (maxhp == 888) return 1;
     return 0;
}
bool BaseKnight::is_Paladin(int maxhp)
{
    if (maxhp < 2) return 0;
    int count = 0;
    for (int i = 2; i <= sqrt(maxhp); i++){
        if(maxhp%i==0) 
        {
            count++;
            break;
        }
    }
    if (count != 0)return 0;
    return 1;
}
BaseKnight* BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    // BaseKnight*newKnight=nullptr;
     // return new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
     if(gil>999) gil=999;
     if(antidote>5)antidote=5;
     if(phoenixdownI>5)phoenixdownI=5;
    if (is_Paladin(maxhp)==1)
    {
        return  new PaladinKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        // newKnight->setknighttype(PALADIN);
        //  newKnight->bag=new BagPaladin(newKnight,phoenixdownI,antidote);
    }
   else  if (is_Lancelot(maxhp)==1)
    {
        return new LancelotKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        // newKnight->setknighttype(LANCELOT);
        //  newKnight->bag=new BagLancelot(newKnight,phoenixdownI,antidote);
    }
    else if (is_Dragon(maxhp)==1)
    {
        return new DragonKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        // newKnight->setknighttype(DRAGON);
        //  newKnight->bag=new BagDragon(newKnight,phoenixdownI,antidote);
    }
    else
    {
        return new NormalKnight(id, maxhp, level, gil, antidote, phoenixdownI);
        // newKnight->setknighttype(NORMAL);
        // if(newKnight->bag==nullptr)cout<<"rong";
        //  newKnight->bag=new BagNormal(newKnight,phoenixdownI,antidote);
         
    }
     return nullptr;
}
string BaseKnight::ToString(BaseBag*bag) const
{
    string nameItem[5]={"Antidote","PhoenixI","PhoenixII","PhoenixIII","PhoenixIV"};
string str("");
        //LOI PHAN TUI
if(getSoluongItem(bag)==0) str=str+"Bag[count=0;]";
else
{
str=str+"Bag[count="
+to_string(getSoluongItem(bag))
+";"
+nameItem[bag->item->getTypeItem()];
while(bag->next!=nullptr)
{
    bag=bag->next;
    str+=","+nameItem[bag->item->getTypeItem()];
}
str+="]";
}
return str;
}
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    // cout<<hp;
    // cout<<to_string(hp);
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" 
    + to_string(maxhp) + ",level:" 
    + to_string(level) 
    + ",gil:" + to_string(gil) 
    + "," +ToString(bag) 
    + ",knight_type:" 
    + typeString[knightType] + "]";
    return s;
}
void BaseKnight::setknighttype(KnightType type)
{
        knightType = type;
}
PaladinKnight::PaladinKnight(int i,int max,int le,int gi,int anti,int pho)
{
    this->id=i;
    this->maxhp=max;
    this->hp=max;
    this->level=le;
    this->gil=gi;
    this->antidote=anti;
    this->phoenixdownI=pho;
    this->knightType=PALADIN;
    this->sizebag=9999;
    this->bag=NULL;
    BaseItem*phoenixI=new PhoenixdownI();
    for (int i = 0; i < pho; i++)
    {
        nhat_item(&bag,phoenixI);
    }
    BaseItem*antidote=new Antidote();
    for (int i = 0; i < anti; i++)
    {
        nhat_item(&bag,antidote);
    }
}
LancelotKnight::LancelotKnight(int i,int max,int le,int gi,int anti,int pho)
{
    this->id=i;
    this->maxhp=max;
    this->hp=max;
    this->level=le;
    this->gil=gi;
    this->antidote=anti;
    this->phoenixdownI=pho;
    this->knightType=LANCELOT;
    this->sizebag=16;
    this->bag=NULL;
    BaseItem*phoenixI=new PhoenixdownI();
    for (int i = 0; i < pho; i++)
    {
        nhat_item(&bag,phoenixI);
    }
    BaseItem*antidote=new Antidote();
    for (int i = 0; i < anti; i++)
    {
        nhat_item(&bag,antidote);
    }
}
DragonKnight::DragonKnight(int i,int max,int le,int gi,int anti,int pho)
{
    this->id=i;
    this->maxhp=max;
    this->hp=max;
    this->level=le;
    this->gil=gi;
    this->antidote=0;
    this->phoenixdownI=pho;
    this->knightType=DRAGON;
    this->sizebag=14;
    this->bag=NULL;
    BaseItem*phoenixI=new PhoenixdownI();
    for (int i = 0; i < pho; i++)
    {
        nhat_item(&bag,phoenixI);
    }
    // BaseItem*antidote=new Antidote();
    // for (int i = 0; i < anti; i++)
    // {
    //     nhat_item(&bag,antidote);
    // }
}
NormalKnight::NormalKnight(int i,int max,int le,int gi,int anti,int pho)
{
    this->id=i;
    this->maxhp=max;
    this->hp=max;
    this->level=le;
    this->gil=gi;
    this->antidote=anti;
    this->phoenixdownI=pho;
    this->knightType=NORMAL;
    this->sizebag=19;
    this->bag=NULL;
    BaseItem*phoenixI=new PhoenixdownI();
    for (int i = 0; i < pho; i++)
    {
        nhat_item(&bag,phoenixI);
    }
    BaseItem*antidote=new Antidote();
    for (int i = 0; i < anti; i++)
    {
        nhat_item(&bag,antidote);
    }
}
/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class BaseOpponent * * */
MadBear::MadBear()
{
   this-> gil=100;
   this-> baseDamage=10;
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
Bandit::Bandit()
{
   this-> gil=150;
   this-> baseDamage=15;
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
LordLupin::LordLupin()
{
   this-> gil=450;
   this-> baseDamage=45;
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
Elf::Elf()
{
   this-> gil=750;
   this-> baseDamage=75;
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
Troll::Troll()
{
   this-> gil=800;
   this-> baseDamage=95;
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
Hades::Hades()
{
   this-> winOmegaWeapon=0;
   this->winHades=0;
}
void Hades::fight(BaseKnight*knight)
{
    if(knight->getlevel()==10||(knight->getknighttype()==PALADIN&&knight->getlevel()>=8))
    {
        winHades=1;
        // nhan khien paladin
    }
    else 
    {
        knight->sethp(0);
        knight->tim_do(knight);
        if(knight->gethp()<=0&&knight->getgil()>=100)
        {
                knight->setgil(knight->getgil()-100);
                knight->sethp(knight->getmaxhp()/2);
        }
    }
}
OmegaWeapon::OmegaWeapon()
{
   this-> winOmegaWeapon=0;
   this->winHades=0;
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
        knight->tim_do(knight);
        if(knight->gethp()<=0&&knight->getgil()>=100)
        {
                knight->setgil(knight->getgil()-100);
                knight->sethp(knight->getmaxhp()/2);
        }
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
        if (knight->getknighttype() != DRAGON)
        {
                knight->trung_doc();
                knight->tim_do(knight);
                if (knight->hasPoison() == 1)
                {
                    knight->sethp(knight->gethp() - 10);
                    for (int i = 0; i < 3; i++)
                    {
                        popFront(knight->getdiachibag());
                    }
                    knight->giai_doc();
                    knight->tim_do(knight);
                    if (knight->gethp() <= 0 && knight->getgil() >= 100)
                    {
                        knight->setgil(knight->getgil() - 100);
                        knight->sethp(knight->getmaxhp() / 2);
                    }
                }
        }
        //luc tui do de giai doc
        //neu khong giai doc duoc
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
        if(knight->getknighttype()!=PALADIN)
        {
        knight->setgil(knight->getgil()/2);
        }
    }
    else
    {
        knight->setgil(knight->getgil()*2);
        // knight->setlevel(knight->getlevel()+1);
        //hien thuc ham chuyen tien len tren
    }
}
void NinaDeRings::fight(BaseKnight*knight)
{
    if(knight->getknighttype()!=PALADIN)
    {
        if(knight->getgil()>=50&&knight->gethp()<knight->getmaxhp()/3)
        {
        knight->setgil(knight->getgil()-50);
        knight->sethp(knight->gethp()+knight->getmaxhp()/5);
        }
    }
    else
    {
        if(knight->gethp()<knight->getmaxhp()/3)
        {
            knight->sethp(knight->gethp()+knight->getmaxhp()/5);
        }
    }
}
void BaseOpponent::fight(BaseKnight*knight)
{
    if(knight->getknighttype()==LANCELOT||knight->getknighttype()==PALADIN||knight->getlevel()>=level)
    {
        knight->setgil(knight->getgil() + gil);
        // hien thuc ham chuyen tien len tren
        // knight->setlevel(knight->getlevel() + 1);
    }
   else
    {
        knight->sethp(knight->gethp() - baseDamage * (level-knight->getlevel()));
        knight->tim_do(knight);
        if(knight->gethp()<=0&&knight->getgil()>=100)
        {
                knight->setgil(knight->getgil()-100);
                knight->sethp(knight->getmaxhp()/2);
        }
    }
}
BaseOpponent* BaseOpponent::create(int eventid)
{
    if(eventid==1) return new MadBear();
    else if(eventid==2) return new Bandit();
    else if(eventid==3) return new LordLupin();
    else if(eventid==4) return new Elf();
    else if(eventid==5) return new Troll();
    else if(eventid==6) return new Tornbery();
    else if(eventid==7) return new QueenOfCards();
    else if(eventid==8) return new NinaDeRings();
    else if(eventid==9) return new DurianGarden();
    else if(eventid==10) return new OmegaWeapon();
    else if(eventid==11) return new Hades();
    return nullptr;
}
void BaseOpponent::set_info(int i,int eventid)
{
    level=(i+eventid)%10+1;
}
/* * * END implementation of class BaseOpponent * * */

/* * * BEGIN implementation of class ArmyKnights * * */
void ArmyKnights::take_item(BaseKnight*knight,BaseItem*item)
{
    int i=n;
    while(quandoi[i]->insertFirst(item)==0)
    {
        i--;
    }
    if(quandoi[i]->insertFirst(item)==1)
    {
        nhat_item(quandoi[i]->getdiachibag(),item);
    }
}
ArmyKnights ::ArmyKnights(const string &file_armyknights)
{
    ifstream file(file_armyknights);
    file >> n;
    soluong=n;
    quandoi = new BaseKnight *[n + 1];
    int hp;
    int level;
    int phoenixdownI;
    int gil;
    int antidote;
    winhades=0;
    winBoss=0;
    winOmegaWeapon=0;
    paladinshield=0;
    lancelotspear=0;
    guineverehair=0;
    excaliburSword=0;
    //  file >> hp >> level >> phoenixdownI >> gil >> antidote;
    //  BaseKnight*knight=BaseKnight::create(1,hp,level,gil,antidote,phoenixdownI);
    // BaseKnight*knight=new NormalKnight(1,hp,level,gil,antidote,phoenixdownI);
    // cout<<knight->gethp();
    for (int i = 1; i <= n; i++)
    {
        file >> hp >> level >> phoenixdownI >> gil >> antidote;
        quandoi[i] = BaseKnight::create(i, hp, level, gil, antidote, phoenixdownI);
    }
    file.close();
}
ArmyKnights::~ArmyKnights()
{
    for (int i = 0; i < n + 1; i++)
    {
        delete quandoi[i];
    }
    delete quandoi;
}
//  return false neu hiep si cuoi chet
void ArmyKnights::fightUltimecia()
{
    if(hasExcaliburSword()==1){
        this->winBoss=1;
        return;
    }
    int hpBoss=5000;
    for (int i = n; i >=1 ; i--){
        switch (quandoi[i]->getknighttype())
        {
        case NORMAL:
                break;
        case LANCELOT:
            hpBoss=hpBoss-quandoi[i]->gethp()*quandoi[i]->getlevel()*0.05;
            delete quandoi[i];
            n--;
            break;
        case PALADIN:
            hpBoss=hpBoss-quandoi[i]->gethp()*quandoi[i]->getlevel()*0.06;
            delete quandoi[i];
            n--;
            break;
        case DRAGON:
            hpBoss=hpBoss-quandoi[i]->gethp()*quandoi[i]->getlevel()*0.075;
            delete quandoi[i];
            n--;
            break;
        default:
                break;
        }
        // cout<<hpBoss<<" ";
        if (hpBoss <= 0 && n > 0)
        {
                winBoss = 1;
                break;
        }   
        else{
            n=0;
            winBoss=0;
        }
    }
   
}
bool ArmyKnights::fight(BaseOpponent*opponent)  //nhung thay doi cua mang doi quan se viet tren ham nay 
{
    if(lastKnight()==nullptr) return false;
    opponent->fight(quandoi[n]);
    while(quandoi[n]->gethp()<=0)
    {
        delete quandoi[n];
        n--;
        if(n==0)
        {
            return false;
            break;
        }
        opponent->fight(quandoi[n]);
    }
    if(quandoi[n]->getlevel()>10) quandoi[n]->setlevel(10);
    int i=n;
    while(quandoi[i]->getgil()>999)
    {
        if(i==1)
        {
            quandoi[i]->setgil(999);
            break;
        }
        quandoi[i-1]->setgil(quandoi[i]->getgil()-999+quandoi[i-1]->getgil());
        quandoi[i]->setgil(999);
        i--;
    }
    // do
    // {
    //     i--;
    //     quandoi[i]->setgil(quandoi[i+1]->getgil()-999+quandoi[i]->getgil());

    // } while (quandoi[i]->getgil()>999);
    if(opponent->winHades==1)
    {
        winhades=1;
        paladinshield=1;
    }
    if(opponent->winOmegaWeapon)
    {
        winOmegaWeapon=1;
    }
    return true;
}
//return true neu danh bai boss
bool ArmyKnights::adventure(Events*events)  
{
    BaseOpponent*opponent=nullptr;
    BaseItem*item=nullptr;
    for (int i = 0; i < events->count(); i++)
    {
        // cout<<events->get(i);
        switch (events->get(i))
        {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            opponent= opponent->create(events->get(i));
            opponent->set_info(i,events->get(i));
            // cout<<quandoi[n]->gethp();
            if(fight(opponent)==0) return false;
            break;
        case 10:
            if(winOmegaWeapon==1) break;
            opponent=opponent->create(events->get(i));
            opponent->set_info(i,events->get(i));
            if(fight(opponent)==0) return false;
            winOmegaWeapon=opponent->winOmegaWeapon;
            break;
        case 11:
            if(winhades==1) break;
            opponent=opponent->create(events->get(i));
            opponent->set_info(i,events->get(i));
            if(fight(opponent)==0) return false;
            winhades=opponent->winHades;
            break;
        case 112:
            item=item->create( PHOENIXDOWNII);
            take_item(quandoi[n],item);
            break;
        case 113:
            item=item->create(PHOENIXDOWNIII);
            take_item(quandoi[n],item);
            break;
        case 114:
            item=item->create(PHOENIXDOWNIV);
            take_item(quandoi[n],item);
            break;
        case 95:
            if(hasPaladinShield()==1) break;
            this->paladinshield=1;
            break;
        case 96:
           this-> lancelotspear=1;
            break;
        case 97:
           this-> guineverehair=1;
            break;
        case 98:
            if(hasGuinevereHair()&&hasPaladinShield()&&hasLancelotSpear())
            {
               this-> excaliburSword=1;
            }
            break;
        case 99:
            fightUltimecia();
            printInfo();
            if(winBoss==1) return true; 
            else return false;
            break;
        default:
            break;
        }
         printInfo();
        
    }
    return false;
}
int ArmyKnights::count() const //tra ve so luong knight
{
    return n;
}
void ArmyKnights::printInfo() const
{
    cout << "No. knights: " << this->count();
    // cout<<this->count()<<endl;
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
    if(n>0)
    {
        for (int i = soluong; i > 0; i--)
        {
            if(quandoi[i]->getId()<=soluong&&quandoi[i]->getId()>=1) return quandoi[i];
        }
        
    }
    return nullptr;
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
bool ArmyKnights::win()
{
    return winBoss;
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
void KnightAdventure::run()
{
    armyKnights->adventure(events);
    armyKnights->printResult(armyKnights->win());
    
}
KnightAdventure::~KnightAdventure()
{
    delete armyKnights;
    delete events;
}
/* * * END implementation of class KnightAdventure * * */
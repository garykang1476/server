//////////////////////////////////////////////////////////////////////////////
// Filename    : OustersStone.h
// Written By  :
// Description : 
//////////////////////////////////////////////////////////////////////////////

#ifndef __OUSTERS_STONE_H__
#define __OUSTERS_STONE_H__

#include "Item.h"
#include "ConcreteItem.h"
#include "ItemPolicies.h"
#include "ItemInfo.h"
#include "InfoClassManager.h"
#include "ItemFactory.h"
#include "ItemLoader.h"
#include "Mutex.h"

//////////////////////////////////////////////////////////////////////////////
// class OustersStone;
//////////////////////////////////////////////////////////////////////////////

class OustersStone : public ConcreteItem<Item::ITEM_CLASS_OUSTERS_STONE, NoStack, HasDurability, HasOption, AccessoryGrade, NoAttacking>
{
public:
	OustersStone() throw();
	OustersStone(ItemType_t itemType, const list<OptionType_t>& optionType) throw();
	
public:
	virtual void create(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y, ItemID_t itemID=0) throw(Error);
	virtual void save(const string & ownerID, Storage storage, StorageID_t storageID, BYTE x, BYTE y) throw(Error);
	void tinysave(const string & field) const throw(Error)	{ tinysave(field.c_str()); }
	void tinysave(const char* field) const throw(Error);
	virtual string toString() const throw();

	static void initItemIDRegistry(void) throw();

public:
//	virtual ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERS_STONE; }
//	virtual string getObjectTableName() const throw() { return "OustersStoneObject"; }

/*	virtual ItemType_t getItemType() const throw() { return m_ItemType; }
	virtual void setItemType(ItemType_t itemType) throw() { m_ItemType = itemType; }

	virtual bool hasOptionType() const throw() { return !m_OptionType.empty(); }
	virtual int getOptionTypeSize() const throw() { return m_OptionType.size(); }
	virtual int getRandomOptionType() const throw() { if (m_OptionType.empty()) return 0; int pos = rand()%m_OptionType.size(); list<OptionType_t>::const_iterator itr = m_OptionType.begin(); for (int i=0; i<pos; i++) itr++; return *itr; }
	virtual const list<OptionType_t>& getOptionTypeList() const throw() { return m_OptionType; }
	virtual OptionType_t getFirstOptionType() const throw() { if (m_OptionType.empty()) return 0; return m_OptionType.front(); }
	virtual void removeOptionType(OptionType_t OptionType) throw() { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), OptionType); if (itr!=m_OptionType.end()) m_OptionType.erase(itr); }
	virtual void changeOptionType(OptionType_t currentOptionType, OptionType_t newOptionType) throw() { list<OptionType_t>::iterator itr = find(m_OptionType.begin(), m_OptionType.end(), currentOptionType); if (itr!=m_OptionType.end()) *itr=newOptionType; }
	virtual void addOptionType(OptionType_t OptionType) throw() { m_OptionType.push_back(OptionType); }
	virtual void setOptionType(const list<OptionType_t>& OptionType) throw() { m_OptionType = OptionType; }

	virtual VolumeWidth_t getVolumeWidth() const throw(Error);
	virtual VolumeHeight_t getVolumeHeight() const throw(Error);
	virtual Weight_t getWeight() const throw(Error);

public:
	virtual Durability_t getDurability() const throw(Error) { return m_Durability; }
	void setDurability(Durability_t durability) throw(Error) { m_Durability = durability; }

	virtual Defense_t getDefenseBonus() const throw(Error);
	virtual Protection_t getProtectionBonus() const throw(Error);
*/
	virtual ElementalType getElementalType() const;
	virtual Elemental_t getElemental() const;

private:
//	ItemType_t			m_ItemType;			// 아이템 타입
//	list<OptionType_t>		m_OptionType;		// 옵션 타입
//	Durability_t		m_Durability;		// 내구성
	
	static Mutex    m_Mutex;          // 아이템 ID 관련 락
	static ItemID_t m_ItemIDRegistry; // 클래스별 고유 아이템 아이디 발급기
};


//////////////////////////////////////////////////////////////////////////////
// class OustersStoneInfo
//////////////////////////////////////////////////////////////////////////////

class OustersStoneInfo : public ItemInfo 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERS_STONE; }

	virtual Durability_t getDurability() const throw() { return m_Durability; }
	virtual void setDurability(Durability_t durability) throw() { m_Durability = durability; }

	Defense_t getDefenseBonus() const throw() { return m_DefenseBonus; }
	void setDefenseBonus(Defense_t acBonus) throw() { m_DefenseBonus = acBonus; }

	Protection_t getProtectionBonus() const throw() { return m_ProtectionBonus; }
	void setProtectionBonus(Protection_t acBonus) throw() { m_ProtectionBonus = acBonus; }

	virtual uint getItemLevel(void) const throw() { return m_ItemLevel; }
	virtual void setItemLevel(uint level) throw() { m_ItemLevel = level; }

    virtual ElementalType getElementalType() const { return m_ElementalType; }
	void setElementalType(ElementalType elementalType ) { m_ElementalType = elementalType; }

	virtual Elemental_t getElemental() const { return m_Elemental; }
	void setElemental(Elemental_t elemental ) { m_Elemental = elemental; }

	virtual string toString() const throw();

private:
	Durability_t	m_Durability;		// 내구성
	Defense_t		m_DefenseBonus;
	Protection_t	m_ProtectionBonus;
	uint			m_ItemLevel;

	ElementalType m_ElementalType;
	Elemental_t   m_Elemental;
};


//////////////////////////////////////////////////////////////////////////////
// class OustersStoneInfoManager;
//////////////////////////////////////////////////////////////////////////////

class OustersStoneInfoManager : public InfoClassManager 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERS_STONE; }
	virtual void load() throw(Error);
};

// global variable declaration
extern OustersStoneInfoManager* g_pOustersStoneInfoManager;


//////////////////////////////////////////////////////////////////////////////
// class OustersStoneFactory
//////////////////////////////////////////////////////////////////////////////

class OustersStoneFactory : public ItemFactory 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERS_STONE; }
	virtual string getItemClassName() const throw() { return "OustersStone"; }

public:
	virtual Item* createItem(ItemType_t ItemType, const list<OptionType_t>& OptionType) throw() { return new OustersStone(ItemType,OptionType); }
};


//////////////////////////////////////////////////////////////////////////////
// class OustersStoneLoader;
//////////////////////////////////////////////////////////////////////////////

class OustersStoneLoader : public ItemLoader 
{
public:
	virtual Item::ItemClass getItemClass() const throw() { return Item::ITEM_CLASS_OUSTERS_STONE; }
	virtual string getItemClassName() const throw() { return "OustersStone"; }

public:
	virtual void load(Creature* pCreature) throw(Error);
	virtual void load(Zone* pZone) throw(Error);
	virtual void load(StorageID_t storageID, Inventory* pInventory) throw(Error);
};

extern OustersStoneLoader* g_pOustersStoneLoader;

#endif

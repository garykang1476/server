//////////////////////////////////////////////////////////////////////////////
// Filename    : PCFinder.h
// Written By  : Reiot
// Description :
//////////////////////////////////////////////////////////////////////////////

#ifndef __PC_FINDER_H__
#define __PC_FINDER_H__

#include "Types.h"
#include "Exception.h"
#include "Creature.h"
#include "NPC.h"
#include "Mutex.h"
#include <map>

//////////////////////////////////////////////////////////////////////////////
// class PCFinder;
// 게임 서버의 글로벌 매니저 객체로, PC 이름을 사용해서 PC객체에 접근할 수 있도록
// 해준다. 내부적으로 map 을 사용해서, 검색 속도를 향상시킨다.
//////////////////////////////////////////////////////////////////////////////

class PCFinder 
{
public:
	PCFinder() throw();
	~PCFinder() throw();

public:
	// add creature to map
	// execute just once at PC's login
	void addCreature(Creature* pCreature) throw(DuplicatedException, Error);

	// delete creature from map
	// execute just once at PC's logout
	void deleteCreature(const string & name) throw();//NoSuchElementException, Error);

	// get creature with PC-name
	Creature* getCreature(const string & name) const throw(); //NoSuchElementException, Error);

	// get creature with PC-name
	Creature* getCreature_LOCKED(const string & name) const throw(); //NoSuchElementException, Error);

	// PlayerID. for BillingServer. by sigi. 2002.11.18
	Creature* getCreatureByID(const string & ID) const throw(); //NoSuchElementException, Error);
	Creature* getCreatureByID_LOCKED(const string & ID) const throw(); //NoSuchElementException, Error);

	// add NPC to map
	void addNPC(NPC *npc) throw(DuplicatedException, Error);
	
	// delete NPC from map
	void deleteNPC(const string & name) throw();

	// get NPC 
	NPC* getNPC(const string & name) const throw();
	NPC* getNPC_LOCKED(const string & name) const throw();

	// get creature's IP address
	IP_t getIP(const string & name) const throw(NoSuchElementException, Error);

	list<Creature*>	getGuildCreatures(GuildID_t gID, uint Num);

/*	pair<multimap< GuildID_t, Creature* >::const_iterator, multimap< GuildID_t, Creature* >::const_iterator>
		getGuildRange(GuildID_t gID) const { return m_GuildMap.equal_range(gID); }*/

	void lock() throw(Error) { m_Mutex.lock(); }
	void unlock() throw(Error) { m_Mutex.unlock(); }

private:
	map< string, Creature* > 	m_PCs;
	map< string, Creature* > 	m_IDs;	// PlayerID. for BillingServer. by sigi. 2002.11.18
	map< string, NPC* > 		m_NPCs;	// NPCs.. for NPC trace ;; by DEW  2003. 04. 16
//	multimap< GuildID_t, Creature* >	m_GuildMap;
	mutable Mutex m_Mutex;
};

// global variable declaration
extern PCFinder* g_pPCFinder;

#endif

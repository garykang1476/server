////////////////////////////////////////////////////////////////////////////////
// Filename    : CGTradePrepare.h 
// Written By  : �輺��
// Description : 
////////////////////////////////////////////////////////////////////////////////

#ifndef __CG_TRADE_PREPARE_H__
#define __CG_TRADE_PREPARE_H__

#include "Packet.h"
#include "PacketFactory.h"

////////////////////////////////////////////////////////////////////////////////
// ��ȯ �ڵ�
////////////////////////////////////////////////////////////////////////////////

enum
{
	// ���� ó�� ��ȯ�� ���ϴ� �÷��̾ �� �ڵ�� ��Ŷ�� ������.
	CG_TRADE_PREPARE_CODE_REQUEST = 0,

	// ���� ó�� ��ȯ�� ��û�� �÷��̾ ��Ҹ� �ߴ�.
	CG_TRADE_PREPARE_CODE_CANCEL,

	// ��ȯ�� ��û���� �÷��̾ ��ȯ�� ���� ���
	CG_TRADE_PREPARE_CODE_ACCEPT,

	// ��ȯ�� ��û���� �÷��̾ ��ȯ�� ������ ���� ���
	CG_TRADE_PREPARE_CODE_REJECT,

	// ��ȯ�� ��û���� �÷��̾ ���� ��ȯ�� �� �� ���� ���
	CG_TRADE_PREPARE_CODE_BUSY,

	CG_TRADE_PREPARE_CODE_MAX
};

////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepare;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepare : public Packet 
{
public:
    CGTradePrepare() {};
    virtual ~CGTradePrepare() {};
	void read(SocketInputStream & iStream) throw(ProtocolException, Error);
	void write(SocketOutputStream & oStream) const throw(ProtocolException, Error);
	void execute(Player* pPlayer) throw(ProtocolException, Error);
	PacketID_t getPacketID() const throw() { return PACKET_CG_TRADE_PREPARE; }
	PacketSize_t getPacketSize() const throw() { return szObjectID + szBYTE; }
	string getPacketName() const throw() { return "CGTradePrepare"; }
	string toString() const throw();
	
public:
	ObjectID_t getTargetObjectID() const throw() { return m_TargetObjectID; }
	void setTargetObjectID(ObjectID_t id) throw() { m_TargetObjectID = id; }

	BYTE getCode(void) const throw() { return m_Code; }
	void setCode(BYTE code) throw() { m_Code = code; }

private:
	ObjectID_t m_TargetObjectID; // ��ȯ�� ���ϴ� ������ OID
	BYTE       m_Code;           // ��ȯ �ڵ�

};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepareFactory;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepareFactory : public PacketFactory 
{
public:
	Packet* createPacket() throw() { return new CGTradePrepare(); }
	string getPacketName() const throw() { return "CGTradePrepare"; }
	PacketID_t getPacketID() const throw() { return Packet::PACKET_CG_TRADE_PREPARE; }
	PacketSize_t getPacketMaxSize() const throw() { return szObjectID + szBYTE; }
};


////////////////////////////////////////////////////////////////////////////////
//
// class CGTradePrepareHandler;
//
////////////////////////////////////////////////////////////////////////////////

class CGTradePrepareHandler 
{
public:
	static void execute(CGTradePrepare* pPacket, Player* player) throw(ProtocolException, Error);
	static void executeSlayer(CGTradePrepare* pPacket, Player* player) throw(ProtocolException, Error);
	static void executeVampire(CGTradePrepare* pPacket, Player* player) throw(ProtocolException, Error);
	static void executeOusters(CGTradePrepare* pPacket, Player* player) throw(ProtocolException, Error);
	static void executeError(CGTradePrepare* pPacket, Player* player, BYTE ErrorCode) throw(ProtocolException, Error);
};

#endif
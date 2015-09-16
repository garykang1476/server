//////////////////////////////////////////////////////////////////////
// 
// Filename    : LCCreatePCOK.h 
// Written By  : Reiot
// Description : 
// 
//////////////////////////////////////////////////////////////////////

#ifndef __LC_CREATE_PC_OK_H__
#define __LC_CREATE_PC_OK_H__

// include files
#include "Packet.h"
#include "PacketFactory.h"

//////////////////////////////////////////////////////////////////////
//
// class LCCreatePCOK;
//
// �α��μ����� Ŭ���̾�Ʈ���� �α��� ������ �˷��ִ� ��Ŷ�̴�.
//
//////////////////////////////////////////////////////////////////////

class LCCreatePCOK : public Packet {

public:
    LCCreatePCOK() {};
    ~LCCreatePCOK() {};
    // �Է½�Ʈ��(����)���κ��� ����Ÿ�� �о ��Ŷ�� �ʱ�ȭ�Ѵ�.
    void read(SocketInputStream & iStream) throw(ProtocolException, Error) {}
		    
    // ��½�Ʈ��(����)���� ��Ŷ�� ���̳ʸ� �̹����� ������.
    void write(SocketOutputStream & oStream) const throw(ProtocolException, Error) {}

	// execute packet's handler
	void execute(Player* pPlayer) throw(ProtocolException, Error);

	// get packet id
	PacketID_t getPacketID() const throw() { return PACKET_LC_CREATE_PC_OK; }
	
	// get packet body size
	// *OPTIMIZATION HINT*
	// const static LCCreatePCOKPacketSize �� ����, �����϶�.
	PacketSize_t getPacketSize() const throw() { return 0; }
	
	// get packet's name
	string getPacketName() const throw() { return "LCCreatePCOK"; }
	
	// get packet's debug string
	string toString() const throw() { return "LCCreatePCOK"; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class LCCreatePCOKFactory;
//
// Factory for LCCreatePCOK
//
//////////////////////////////////////////////////////////////////////

class LCCreatePCOKFactory : public PacketFactory {

public:
	
	// create packet
	Packet* createPacket() throw() { return new LCCreatePCOK(); }

	// get packet name
	string getPacketName() const throw() { return "LCCreatePCOK"; }
	
	// get packet id
	PacketID_t getPacketID() const throw() { return Packet::PACKET_LC_CREATE_PC_OK; }

	// get packet's max body size
	PacketSize_t getPacketMaxSize() const throw() { return 0; }
	
};


//////////////////////////////////////////////////////////////////////
//
// class LCCreatePCOKHandler;
//
//////////////////////////////////////////////////////////////////////

class LCCreatePCOKHandler {

public:

	// execute packet's handler
	static void execute(LCCreatePCOK* pPacket, Player* pPlayer) throw(ProtocolException, Error);

};

#endif
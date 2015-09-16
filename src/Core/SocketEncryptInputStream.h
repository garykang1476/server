//////////////////////////////////////////////////////////////////////
// 
// SocketEncryptInputStream.h 
// 
// by Reiot
// 
//////////////////////////////////////////////////////////////////////

#ifndef __SOCKET_ENCRYPT_INPUT_STREAM_H__
#define __SOCKET_ENCRYPT_INPUT_STREAM_H__

// include files
#include "Types.h"
#include "Exception.h"
#include "SocketInputStream.h"
#include "Encrypter.h"

const unsigned int DefaultSocketEncryptInputBufferSize = 81920;

//////////////////////////////////////////////////////////////////////
//
// class SocketEncryptInputStream
//
//////////////////////////////////////////////////////////////////////

class SocketEncryptInputStream : public SocketInputStream {

//////////////////////////////////////////////////
// constructor/destructor
//////////////////////////////////////////////////
public :
	
	// constructor
	SocketEncryptInputStream (Socket* sock, uint BufferSize = DefaultSocketEncryptInputBufferSize) throw(Error);
	~SocketEncryptInputStream () throw(Error);
	
//////////////////////////////////////////////////
// methods
//////////////////////////////////////////////////
public :
	
	// read data to stream (output buffer)
	// *CAUTION*
	// string �� ���ۿ� writing �� ��, �ڵ����� size �� �տ� ���� ���� �ִ�.
	// �׷���, string �� ũ�⸦ BYTE/WORD �� ��� ������ �� ������ �ǹ��̴�.
	// ��Ŷ�� ũ��� ���� ���� ���ٴ� ��å�Ͽ��� �ʿ信 ���� string size ����
	// BYTE �Ǵ� WORD �� �������� ����ϵ��� �Ѵ�.
    uint readEncrypt (bool   &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (char   &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (uchar  &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (short  &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (ushort &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (int    &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (uint   &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (long   &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (ulong  &buf) throw(ProtocolException, Error) { uint n = read(buf); buf = m_Encrypter.convert(buf);  return n; }

/*    uint readEncrypt (bool   &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szbool ); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (char   &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szchar ); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (uchar  &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szuchar); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (short  &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szshort); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (ushort &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szushort); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (int    &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szint  ); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (uint   &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szuint ); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (long   &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szlong ); buf = m_Encrypter.convert(buf);  return n; }
    uint readEncrypt (ulong  &buf) throw(ProtocolException, Error) { uint n = read((char*)&buf, szulong); buf = m_Encrypter.convert(buf);  return n; }
*/
	void	setEncryptCode(uchar code)	{ m_Encrypter.setCode(code); }
	uchar	getEncryptCode() const		{ return m_Encrypter.getCode(); }

//////////////////////////////////////////////////
// attributes
//////////////////////////////////////////////////
private :
	Encrypter m_Encrypter;
	
};

#endif
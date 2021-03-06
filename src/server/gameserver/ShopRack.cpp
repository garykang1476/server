//////////////////////////////////////////////////////////////////////
// Filename    : ShopRack.cpp
// Written By  : 김성민
// Description :
//////////////////////////////////////////////////////////////////////

#include "ShopRack.h"
#include "Assert1.h"

//////////////////////////////////////////////////////////////////////
// constructor & destructor
//////////////////////////////////////////////////////////////////////

ShopRack::ShopRack() 
: ItemRack(SHOP_RACK_INDEX_MAX)
{
	// 버전 초기화
	// 버전을 0으로 초기화하면 클라이언트도 0으로 초기화할 경우,
	// 클라이언트가 실제로 상점의 상품 목록을 가지고 있지 않은 경우에도,
	// 상점 버전이 같아서 상품 목록을 요구하지 않을 수가 있다.
	// 그러므로 이를 방지하기 위해서 걍 100으로 초기화해준다.
	m_Version  = 100;
}

ShopRack::~ShopRack()
{
}


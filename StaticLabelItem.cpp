#include "StaticLabelItem.h"
#include <iostream>
#include <string>
using namespace std;

/*
 *  Constructor
 */
StaticLabelItem::StaticLabelItem( const std::string &name )
: MenuItem( name )
{
}


/*
 *  Destructor
 */
StaticLabelItem::~StaticLabelItem()
{
}


/*
 *  selectable()
 */
bool StaticLabelItem::selectable( void )
{
	return false;
}

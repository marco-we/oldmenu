#include "PageBackItem.h"
#include "Menu.h"

/*
 *  Constructor
 */
PageBackItem::PageBackItem( const std::string &name )
: MenuItem( name )
{
}


/*
 *  Destructor
 */
PageBackItem::~PageBackItem()
{
}


/*
 *  process_input()
 */
void PageBackItem::process_input( unsigned char key )
{
	if( key == ID_ACTION )
		Menu::get_instance()->leave_item();		
}


/*
 *  selectable()
 */
bool PageBackItem::selectable( void )
{
	return true;
}

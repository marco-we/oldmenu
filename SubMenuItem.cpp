#include "SubMenuItem.h"
#include "MenuPage.h"
#include "Menu.h"
#include "MenuDefinitions.h"

#include <iostream>
#include <string>
using namespace std;



/*
 *  Constructor
 */
SubMenuItem::SubMenuItem( const std::string &name )
:MenuItem( name )
{
	m_pMenu_page = 0;
}


/*
 *  Destructor
 */
SubMenuItem::~SubMenuItem()
{
}


/*
 *
 */
void SubMenuItem::set_menu_page( MenuPage *page )
{
	m_pMenu_page = page;
}


/*
 *  process_input()
 */
void SubMenuItem::process_input( int key )
{
	if( key == ID_ACTION ) {
		if( m_pMenu_page )
			Menu::get_instance()->add_menu_page( m_pMenu_page );
		else
			cerr << "[SubMenuItem]::process_input() No page to pop up!" << endl;
	}
}


/*
*  process_input()
*/
void SubMenuItem::process_input( unsigned char key )
{
	if( key == ID_ACTION ) {
		if( m_pMenu_page )
			Menu::get_instance()->add_menu_page( m_pMenu_page );
		else
			cerr << "[SubMenuItem]::process_input() No page to pop up!" << endl;
	}
}


/*
 *  selectable()
 */
bool SubMenuItem::selectable( void )
{
	return true;
}
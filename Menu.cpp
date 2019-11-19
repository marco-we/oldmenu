#include "Menu.h"
#include "MenuPage.h"
#include <stack>
#include <iostream>
using namespace std;

/*
 *  Constructor
 */
Menu::Menu()
{
	m_menu_active = false;
}


/*
 *  Destructor
 */
Menu::~Menu()
{
}


/*
 *  get_instance()
 */
Menu *Menu::get_instance( void )
{
	static Menu *g_instance = 0;
	if( !g_instance )
		g_instance = new Menu();
	return g_instance;
}


/*
 *  is_active()
 */
bool Menu::is_active( void )
{
	return m_menu_active;
}


/*
 *  set_menu_state()
 */
void Menu::set_menu_state( bool active )
{
	// activate if something left to show
	if( active && m_menu_pages.empty() ) {
		cerr << "[Menu] No menu-page to show!" << endl;
		m_menu_active = false;
	}
	else
		m_menu_active = active;
}


/*
 *  leave_item();
 */
void Menu::leave_item( void )
{
	// shouldn't happen: no page but menu active
	if( m_menu_pages.empty() ) {
		cerr << "[Menu] No menu-page to show!" << endl;
		set_menu_state( false );
	}
	// last page to pop, so just disable
	else if( m_menu_pages.size() == 1 )
		set_menu_state( false );
	// simple return to last menu
	else
		m_menu_pages.pop();
}


/*
 *  
 */
void Menu::add_menu_page( MenuPage *page )
{
	m_menu_pages.push( page );
}


/*
 *  process_input()
 */
void Menu::process_input( int key )
{
	switch( key ) {
		case ID_MENU_EXIT:
			leave_item();
			break;
		case ID_PREVIOUS_ITEM:
			if( !m_menu_pages.empty() )
				m_menu_pages.top()->previous_item();
			break;
		case ID_NEXT_ITEM:
			if( !m_menu_pages.empty() )
				m_menu_pages.top()->next_item();
			break;
		default:
			// action!
			if( !m_menu_pages.empty() )
				m_menu_pages.top()->process_input( key );
			break;
	}
}


/*
 *  process_input()
 */
void Menu::process_input( unsigned char key )
{
	// action!
	if( key == ID_MENU_EXIT )
		leave_item();
	else if( !m_menu_pages.empty() )
		m_menu_pages.top()->process_input( key );
}


/*
 *  draw()
 */
void Menu::draw( void )
{
	if( m_menu_pages.empty() )
		cerr << "[Menu]::draw() No pages to draw!" << endl;
	else
		m_menu_pages.top()->draw();
}


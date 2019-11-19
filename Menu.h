#ifndef _MENU__H_
#define _MENU__H_

#include "MenuDefinitions.h"
#include <stack>

//! Forward declarations
class MenuItem;
class MenuPage;

/*!
 *  \class Menu
 */
class Menu
{
public:

	//! Returns singleton instance
	static Menu *get_instance( void );

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns wether menu is active or not
	bool is_active( void );

	//! Sets the menu state
	void set_menu_state( bool active );

	//! Pushes a new menu-page on page-stack
	void add_menu_page( MenuPage *page );

	//! Leaves current page
	void leave_item( void );

	//! Draws the menu
	void draw( void );

	//! Destructor
	~Menu();

private:

	//! Activates next item
	void next_item( void );

	//! Actives previous item
	void previous_item( void );

	//! Private constructor for singleton
	Menu();

	//! Topmost menu-entry
	std::stack<MenuPage *> m_menu_pages;

	//! Current state of menu
	bool m_menu_active;

};

#endif


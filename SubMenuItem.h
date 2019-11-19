#ifndef _SUBMENUITEM__H_
#define _SUBMENUITEM__H_

#include "MenuItem.h"

//! Forward declarations
class MenuPage;

/*!
 *  \class SubMenuItem
 */
class SubMenuItem :
	public MenuItem
{
public:

	//! Constructor
	SubMenuItem( const std::string &name );

	//! Destructor
	~SubMenuItem();

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Sets the menu-page
	void set_menu_page( MenuPage *page );

	//! Returns wether item is selectable or not
	bool selectable( void );

protected:

	//! Submenu to popup
	MenuPage *m_pMenu_page;

};

#endif


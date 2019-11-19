#ifndef _MENUPAGE__H_
#define _MENUPAGE__H_

#include <vector>

//! Forward declarations
class MenuItem;

/*!
 *  \class MenuPage
 */
class MenuPage
{
public:

	//! Constructor
	MenuPage();

	//! Destructor
	~MenuPage();

	//! Adds new menu-item
	void add_item( MenuItem *item );

	//! Activates next menu-entry
	void next_item( void );

	//! Activates previous menu-entry
	void previous_item( void );

	//! Passes action to active menu-item
	void process_input( int key );

	//! Passes action to active menu-item
	void process_input( unsigned char key );

	//! Draws the current menu
	void draw( void );

	//! Loads font for menu-drawing
	bool load_font( const char *filename );

protected:

	//! Container for all items
	std::vector<MenuItem *> m_items;

	//! Active menu-item
	unsigned int m_active_item_id;

	unsigned int m_font_texture;
	unsigned int m_font_list;
	

};

#endif

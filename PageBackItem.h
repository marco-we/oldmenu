#ifndef _PAGEBACKITEM__H_
#define _PAGEBACKITEM__H_

#include "MenuItem.h"

/*!
 *  \class PageBackItem
 */
class PageBackItem :
	public MenuItem
{
public:

	//! Constructor
	PageBackItem( const std::string &name );

	//! Destructor
	~PageBackItem();

	//! Processes input
	void process_input( unsigned char key );

	//! Returns wether item is selectable or not
	bool selectable( void );
};

#endif

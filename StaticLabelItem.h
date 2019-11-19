#ifndef _STATICLABELITEM__H_
#define _STATICLABELITEM__H_

#include "MenuItem.h"

/*!
 *  \class StaticLabelItem
 */
class StaticLabelItem :
	public MenuItem
{
public:
	
	//! Constructor
	StaticLabelItem( const std::string &name );

	//! Destructor
	~StaticLabelItem();

	//! Returns wether item is selectable or not
	bool selectable( void );
	
};

#endif


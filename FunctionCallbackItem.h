#ifndef _FUNCTIONCALLBACKITEM__H_
#define _FUNCTIONCALLBACKITEM__H_

#include "MenuItem.h"
#include <string>

typedef void(*CBFunction)();

/*!
 *  \class FunctionCallbackItem
 */
class FunctionCallbackItem :
	public MenuItem
{
public:

	//! Constructor
	FunctionCallbackItem( const std::string &name );

	//! Destructor
	~FunctionCallbackItem();

	//! Sets the callback function to call
	void set_callback_function( CBFunction fn );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns wether item is selectable or not
	bool selectable( void );

protected:

	//! Callback function
	CBFunction m_cb_function;
	
};

#endif


#ifndef _TEXTFIELDITEM__H_
#define _TEXTFIELDITEM__H_

#include "MenuItem.h"

/*!
 *  \class TextFieldItem
 */
class TextFieldItem :
	public MenuItem
{
public:

	//! Constructor
	TextFieldItem( const std::string &name );

	//! Destructor
	~TextFieldItem();

	//! Processes input
	void process_input( int key );

	//! Processes input
	void process_input( unsigned char key );

	//! Returns entered text
	std::string get_text( void );

	//! Sets text
	void set_text( const std::string &text );

	//! Returns name of item
	std::string get_name( void );

	//! Returns wether item is selectable or not
	bool selectable( void );

	//! Sets the live-variable
	void set_live_variable( std::string *live_var );

protected:

	std::string m_text;
	std::string *m_pLive_variable;
	unsigned int m_max_length;
	
};

#endif


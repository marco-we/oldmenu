#ifndef _MENUITEM__H_
#define _MENUITEM__H_
#include <string>

/*!
 *  \class MenuItem
 */
class MenuItem
{
public:

	//! Constructor
	MenuItem( const std::string &name );

	//! Destructor
	virtual ~MenuItem();

	//! Processes input, crunches only
	virtual void process_input( int key );

	//! Processes input, crunches only
	virtual void process_input( unsigned char key );

	//! Returns name of item
	virtual std::string get_name( void );
	
	//! Returns wether selectable or not
	virtual bool selectable( void ) = 0;

protected:

	//! Menu item entry name
	std::string m_name;

};

#endif


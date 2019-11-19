#include "MenuItem.h"
#include <string>
#include <iostream>
using namespace std;

/*
 *  Constructor
 */
MenuItem::MenuItem( const std::string &name )
{
	m_name = name;
}


/*
 *  Destructor
 */
MenuItem::~MenuItem()
{
}


/*
 *  get_name()
 */
std::string MenuItem::get_name( void )
{
	return m_name;
}


/*
 *  process_input()
 */
void MenuItem::process_input( int key )
{
	cerr << "[MenuItem]::process_input(int) Crunched item, *yummy*" << endl;
}


/*
 *  process_input()
 */
void MenuItem::process_input( unsigned char key )
{
	cerr << "[MenuItem]::process_input(unsigned char) Crunched item, *mmh*" << endl;
}


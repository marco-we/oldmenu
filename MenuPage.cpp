#include "MenuPage.h"
#include "MenuItem.h"
#include <iostream>
using namespace std;

#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#define FREEGLUT_STATIC
#include <GL/freeglut.h>
#include <GL/gl.h>
//#include <GL/glext.h>

#include <string>
#include <fstream>
using namespace std;


/*
 *  Constructor
 */
MenuPage::MenuPage()
{
	m_active_item_id = 0;
	m_items.clear();
}


/*
 *  Destructor
 */
MenuPage::~MenuPage()
{
}


/*
 * add_item()
 */
void MenuPage::add_item( MenuItem *item )
{
	// prevent invalid selections
	if( m_items.size() > 0 ) {
		if( item->selectable() && !m_items[m_active_item_id]->selectable() )
			m_active_item_id++;
	}
	
	m_items.push_back( item );
}


/*
 *  next_item()
 */
void MenuPage::next_item( void )
{
	if( m_items.size() == 0 ) {
		cerr << "[MenuPage]::next_item() No items on page!" << endl;
	}
	unsigned int next_active = m_active_item_id + 1;
	while( next_active < m_items.size() ) {
		if( m_items[next_active]->selectable() ) {
			m_active_item_id = next_active;
			break;
		}
		else 
			next_active++;
	}
}


/* 
 *  previous_item()
 */
void MenuPage::previous_item( void )
{
	if( m_items.size() == 0 ) {
		cerr << "[MenuPage]::previous_item() No items on page!" << endl;
	}
	int next_active = m_active_item_id - 1;
	while( next_active >= 0 ) {
		if( m_items[next_active]->selectable() ) {
			m_active_item_id = next_active;
			break;
		}
		else 
			next_active--;
	}
}


/*
 *  process_input()
 */
void MenuPage::process_input( int key )
{
	if( m_items.size() == 0 ) {
		cerr << "[MenuPage]::process_input(int) No items on page!" << endl;
	}
	else 
		m_items[m_active_item_id]->process_input( key );
}


/*
 *  process_input()
 */
void MenuPage::process_input( unsigned char key )
{
	if( m_items.size() == 0 ) {
		cerr << "[MenuPage]::process_input(unsigned char) No items on page!" << endl;
	}
	else 
		m_items[m_active_item_id]->process_input( key );
}


/*
 *  draw()
 */
void MenuPage::draw( void )
{
	if( m_items.size() == 0 ) {
		cerr << "[MenuPage]::draw() No items on page!" << endl;
		return;
	}

	int viewport[4];
	glGetIntegerv( GL_VIEWPORT, viewport );

	unsigned int num_entries = m_items.size();
	vector<string> labels;
	
	for( unsigned int i=0; i < num_entries; i++ ) 
		labels.push_back( m_items[i]->get_name() );

	if( glIsList( m_font_list ) ) {

			glMatrixMode( GL_PROJECTION );
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D( 0, 100, 0, 100 );
			glMatrixMode( GL_MODELVIEW );
			glPushMatrix();
			glLoadIdentity();

			// draw ground
			glDisable( GL_DEPTH_TEST );
			glDepthMask( GL_FALSE );
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

			glColor4f( 0.2f, 0.2f, 0.2f, 0.75f );
			glRectf( 25, 20, 
				     90, 86 );
			glColor4f( 0.5f, 0.5f, 0.5f, 0.5f );
			glRectf( 21, 24, 
				     86, 90 );

			glEnable( GL_TEXTURE_2D );
			glBindTexture( GL_TEXTURE_2D, m_font_texture );
			glListBase( m_font_list - 32 + ( 128 * 0 ) );

			// draw strings
			glTranslatef( 34.5f, 59.5f, 0 );
	 		for( unsigned int i=0; i < num_entries; i++ ) {
				 glColor4f( 0.2f, 0.2f, 0.2f, 0.5f );
				 glPushMatrix();
				 glCallLists( labels[i].length(), GL_BYTE, labels[i].c_str() );
				 glPopMatrix();
				 glTranslatef( 0, -5.0f, 0 );
			}
			
			glLoadIdentity();

			glTranslatef( 34, 60, 0 );
			for( unsigned int i=0; i < num_entries; i++ ) {
					if( i == m_active_item_id )	glColor4f( 0.0f, 0.0f, 1.0f, 1.0f );
					else glColor4f( 1.0f, 1.0f, 1.0f, 1.0f );
					glPushMatrix();
					glCallLists( labels[i].length(), GL_BYTE, labels[i].c_str() );
					glPopMatrix();
					glTranslatef( 0, -5.0f, 0 );
			}
			
			glDisable( GL_TEXTURE_2D );
			glDisable( GL_BLEND );

			glViewport( viewport[0], viewport[1], viewport[2], viewport[3] );
	}
	// no texture fonts
	else {
			unsigned int spacing = 15;
			unsigned int font_height = 16;
			unsigned int h_border = (unsigned int)(viewport[2] * 0.75f);
			unsigned int v_border = (unsigned int)(viewport[3] * 0.75f);

			glMatrixMode( GL_PROJECTION );
			glPushMatrix();
			glLoadIdentity();
			gluOrtho2D( 0, viewport[2], 0, viewport[3] );
			glMatrixMode( GL_MODELVIEW );
			glPushMatrix();
			glLoadIdentity();

			// draw ground
			glDisable( GL_DEPTH_TEST );
			glDepthMask( GL_FALSE );
			glEnable( GL_BLEND );
			glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );

			int offset = 10;
			glColor4f( 0.2f, 0.2f, 0.2f, 0.5f );
			glRectf( h_border + offset, v_border - offset, 
							viewport[2] - h_border + offset, viewport[3] - v_border - offset );
			glColor4f( 0.5f, 0.5f, 0.5f, 0.5f );
			glRectf( h_border, v_border, viewport[2] - h_border, viewport[3] - v_border );

			glDisable( GL_BLEND );
			// draw strings
			int dx = viewport[2] - h_border + h_border / 8;
			int dy = viewport[3] - v_border + v_border / 2;
			for( unsigned int i=0; i < num_entries; i++ ) {
					dy -= spacing;
					if( i == m_active_item_id ) {
							dy -= 9;
							continue;
					}
					glColor3f( 0.2f, 0.2f, 0.2f );

					glRasterPos2i( dx + offset/4, dy - offset/4 );
					glutBitmapString( GLUT_BITMAP_9_BY_15, (unsigned char *)labels[i].c_str() );
					dy -= 9;
			}

			dx = viewport[2] - h_border + h_border / 8;
			dy = viewport[3] - v_border + v_border / 2;
			for( unsigned int i=0; i < num_entries; i++ ) {
					dy -= spacing;
					if( i == m_active_item_id )	glColor3f( 0.0f, 0.0f, 1.0f );
					else glColor3f( 1.0f, 1.0f, 1.0f );

					glRasterPos2i( dx, dy );
					glutBitmapString( GLUT_BITMAP_9_BY_15, (unsigned char *)labels[i].c_str() );
					dy -= 9;
			}

	}

	glColor3f( 1.0f, 1.0f, 1.0f );
	
	glEnable( GL_DEPTH_TEST );
	glDepthMask( GL_TRUE );

	glMatrixMode( GL_PROJECTION );
	glPopMatrix();
	glMatrixMode( GL_MODELVIEW );
	glPopMatrix();

	labels.empty();
}


/*
 *  load_font
 */
bool MenuPage::load_font( const char *filename )
{
	ifstream font( filename );
	if( font.is_open() ) {
		int width, height, max;
		string header;
		font >> header >> width >> height >> max;
		char *data = new char[ width * height * 4 ];
		font.read( data, width * height * 4 );

		glGenTextures( 1, &m_font_texture );
		glBindTexture( GL_TEXTURE_2D, m_font_texture );
		glTexImage2D( GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_BGRA, GL_UNSIGNED_BYTE, data );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR );
		glTexParameteri( GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR );
		delete [] data;

		m_font_list = glGenLists( 256 );

		float font_width = 2.5f;
		float font_height = 3.5f;

		// create each character
		for( unsigned int i=0; i < 256; i++ ) {

			float cx = 1.0f - ( float )( i % 16 ) / 16.0f;
			float cy = 1.0f - ( float )( i / 16 ) / 16.0f;

			glNewList( m_font_list + ( 255 - i ), GL_COMPILE );
			{
				glBegin( GL_QUADS );
				{
					glTexCoord2f( cx - 0.0625, cy );
					glVertex2i( 0, 0 );
					glTexCoord2f( cx, cy );
					glVertex2f( font_width, 0 );
					glTexCoord2f( cx, cy - 0.0625f );
					glVertex2f( font_width, font_height );
					glTexCoord2f( cx - 0.0625f, cy - 0.0625f);
					glVertex2f( 0, font_height );
				}
				glEnd( );

				glTranslatef( font_width * 0.75f, 0, 0 );
			}
			glEndList( );
		}
		return true;
	}
	else 
		return false;

}


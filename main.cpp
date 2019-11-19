#ifdef _WIN32
#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#endif

#include <iostream>
using namespace std;

#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>

#include "MenuFramework.h"

void display( void );
void idle( void );
void reshape( int w, int h );
void keyboard( unsigned char key, int x, int y );
void special( int key, int x, int y );
void check_error( const char *msg=0 );
void setup_menu( void );

int window_width = 640;
int window_height = 480;
int mainwindow_id;

/*
 *  main()
 */
int main( int argc, char **argv )
{
	// initialize glut
	glutInit( &argc, argv );

	// create main-window
	glutInitWindowPosition( 10, 10 );
	glutInitWindowSize( window_width, window_height );
	glutInitDisplayMode( GLUT_RGBA | GLUT_ALPHA | GLUT_DOUBLE | GLUT_DEPTH );
	mainwindow_id = glutCreateWindow( "Menu a la carte" );

	// set main-window callbacks
	glutDisplayFunc( display );
	glutIdleFunc( idle );
	glutReshapeFunc( reshape );
	glutKeyboardFunc( keyboard );
	glutSpecialFunc( special );

	setup_menu();

	glutMainLoop();
	cerr << "Good bye!" << endl;
	return 0;
}


/*
 *  display()
 */
void display( void )
{
	Menu *menu = Menu::get_instance();
	if( menu->is_active() ) glClearColor( 1.0f, 0.0f, 0.0f, 1.0f );
	else glClearColor( 0.0f, 1.0f, 0.0f, 1.0f );

	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_PROJECTION );
	glLoadIdentity();
	gluPerspective( 90, (GLdouble)window_width/(GLdouble)window_height, 1.0, 100.0 );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	glTranslatef( 0, 0, -3 );

	glRotated( glutGet( GLUT_ELAPSED_TIME )/ 50.0, 0, 1, 0 );
	glColor3f( 1.0f, 1.0f, 1.0f );
	glutWireTeapot( 1 );
	
	glColor3f( 1.0f, 1.0f, 1.0f );
	if( menu->is_active() )
		menu->draw();

	glutSwapBuffers();
}

/*
 *	idle()
 */
void idle( void )
{
	glutSetWindow( mainwindow_id );
	static int last_redraw = glutGet( GLUT_ELAPSED_TIME );
	int time_now = glutGet( GLUT_ELAPSED_TIME );
	if( time_now - last_redraw > 25 ) {
		glutSetWindow( mainwindow_id );
		glutPostRedisplay();
		last_redraw = time_now;
	}
	/*
	else
		Sleep( 5 );
		*/
}


/*
 *	reshape()
 */
void reshape( int w, int h )
{
	glutSetWindow( mainwindow_id );
	glViewport( 0, 0, w, h );

	window_width = w;
	window_height = h;
}



/*
 *  check_error()
 */
void check_error( const char *msg )
{
	GLenum glerror = glGetError();

	// determine prefix
	const char *prefix;
	if( msg ) prefix = msg;
	else prefix = "OpenGL error: ";

	while( glerror != GL_NO_ERROR ) {
		cerr << prefix << gluErrorString( glerror );
		glerror = glGetError();
	}
}


/*
 *  keyboard()
 */
void keyboard( unsigned char key, int x, int y )
{
	Menu *menu = Menu::get_instance();
	if( menu->is_active() )
		menu->process_input( key );
	else {
		switch( key ) {
			case 'q':
			case 27:
				menu->set_menu_state( true );
				break;
			default:
				cerr << "Unregistered key: " << key << " num: " << (int) key << endl; 
		}
	}
}


/*
 *  keyboard()
 */
void special( int key, int x, int y )
{
	Menu *menu = Menu::get_instance();
	if( menu->is_active() )
		menu->process_input( key );
	else {
		
		switch( key ) {
			case GLUT_KEY_F1:
				break;
			default:
				cerr << "Unregistered key: " << key << " num: " << (int) key << endl; 
		}
		
	}
}


/*
 *  setup_menu()
 */
void setup_menu( void )
{
	SubMenuItem *sm_button;
	FunctionCallbackItem *fn_button;
	IntegerFieldItem *if_button;
	TextFieldItem *tf_button;
	StaticLabelItem *sl_button;

	MenuPage *game_page = new MenuPage();
	game_page->load_font( "font_alpha.ppm" );
	sl_button = new StaticLabelItem( "Dummy" );
	game_page->add_item( sl_button );

	MenuPage *graphic_page = new MenuPage();
	graphic_page->load_font( "font_alpha.ppm" );
	sl_button = new StaticLabelItem( "Dummy" );
	graphic_page->add_item( sl_button );

	MenuPage *sound_page = new MenuPage();
	sound_page->load_font( "font_alpha.ppm" );
	sl_button = new StaticLabelItem( "Dummy" );
	sound_page->add_item( sl_button );

	MenuPage *client_page = new MenuPage();
	client_page->load_font( "font_alpha.ppm" );
	sl_button = new StaticLabelItem( "Client" );
	client_page->add_item( sl_button );
	tf_button = new TextFieldItem( "Server IP: " );
	client_page->add_item( tf_button );
	if_button = new IntegerFieldItem( "Server Port: " );
	client_page->add_item( if_button );
	tf_button = new TextFieldItem( "Player Name: " );
	client_page->add_item( tf_button );
	fn_button = new FunctionCallbackItem( "Connect ..." );
	fn_button->set_callback_function( glutLeaveMainLoop );
	client_page->add_item( fn_button );
	
	MenuPage *server_page = new MenuPage();
	server_page->load_font( "font_alpha.ppm" );
	sl_button = new StaticLabelItem( "Server" );
	server_page->add_item( sl_button );
	if_button = new IntegerFieldItem( "Port: " );
	if_button->set_min_value( 1024 );
	if_button->set_max_value( 128000 );
	server_page->add_item( if_button );
	if_button = new IntegerFieldItem( "Number of players: " );
	if_button->set_value( 4 );
	if_button->set_min_value( 1 );
	if_button->set_max_value( 4 );
	server_page->add_item( if_button );
	fn_button = new FunctionCallbackItem( "Start server ..." );
	fn_button->set_callback_function( glutLeaveMainLoop );
	server_page->add_item( fn_button );

	MenuPage *option_page = new MenuPage();
	option_page->load_font( "font_alpha.ppm" );
	sm_button = new SubMenuItem( "Game" );
	sm_button->set_menu_page( game_page );
	option_page->add_item( sm_button );
	sm_button = new SubMenuItem( "Graphic" );
	sm_button->set_menu_page( graphic_page );
	option_page->add_item( sm_button );
	sm_button = new SubMenuItem( "Sound" );
	sm_button->set_menu_page( sound_page );
	option_page->add_item( sm_button );


	MenuPage *main_page = new MenuPage();
	main_page->load_font( "font_alpha.ppm" );
	sm_button = new SubMenuItem( "Client" );
	sm_button->set_menu_page( client_page );
	main_page->add_item( sm_button );

	sm_button = new SubMenuItem( "Server" );
	sm_button->set_menu_page( server_page );
	main_page->add_item( sm_button );

	sm_button = new SubMenuItem( "Options" );
	sm_button->set_menu_page( option_page );
	main_page->add_item( sm_button );

	fn_button = new FunctionCallbackItem( "Quit" );
	fn_button->set_callback_function( glutLeaveMainLoop );
	main_page->add_item( fn_button );

	Menu::get_instance()->add_menu_page( main_page );
}

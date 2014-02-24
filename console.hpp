
#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_

#include <string>
#include <vector>

namespace Console
{
	enum color 
	{
		black		= 0,
#ifdef WIN32
		dark_red	= 0x0004,
		dark_green	= 0x0002,
		dark_blue	= 0x0001,
#else //UNIX
		dark_red	= 1,
		dark_green	= 2,
		dark_blue	= 4,
#endif
		dark_yellow	= dark_red   | dark_green,
		dark_magenta= dark_red   | dark_blue,
		dark_cyan	= dark_green | dark_blue,
		gray		= dark_red   | dark_green | dark_blue,

		dark_gray	= 0x0008 | black,
		red			= 0x0008 | dark_red,
		green		= 0x0008 | dark_green,
		blue		= 0x0008 | dark_blue,
		yellow		= 0x0008 | dark_yellow,
		magenta		= 0x0008 | dark_magenta,
		cyan		= 0x0008 | dark_cyan,
		white		= 0x0008 | gray
	};

	class cursor
	{
		int _size;
		bool _visible;

	public:
		/*the size of a cursor is a value between 0 and 100 (percent) */
		cursor( int size = 20, bool visible = true) { this->_size = size; this->_visible = visible;}

		int size() const {return _size;}
		void size(int size) {this->_size = size;}

		void visible( bool visible ) {this->_visible = visible;}
		bool visible() const {return _visible;}
	};

	class font;
	void enumerate_fonts(std::vector<font> &fonts);

	int number_of_fonts();

	class font
	{
	protected:
		int _index;
		int _width, _height;

		font(int index, int width,int height) { _index = index; _width = width; _height = height;}
	public:
		/*the font index has to be smaller than number_of_fonts().*/
		font(int index);

		int index() const {return _index;}
		void index(int index) {this->_index = index;}

		int height() const {return _height;}
		int width() const {return _width;}

		friend void enumerate_fonts(std::vector<font> &fonts);
		friend class console;
	};

	/*A point represents the position in characters!*/
	class point
	{
	public:
		point(int _x, int _y) {x = _x;y = _y;}
		int x;
		int y;
	};

	class pixel_point 
	{
	public:
		pixel_point(int _x, int _y) {x = _x;y = _y;}
		int x;
		int y;
	};

	/* The height and width of size are characters on the window */
	class size 
	{
	public:
		size(int _w, int _h) {width = _w;height = _h;}
		int width;
		int height;
	};

	class console
	{
	protected:
		//~ void* hwnd;
		//~ void* hConsoleOutput;
		color bg;
		color col;
		void update_colors();
	public:
		console();

		//~ bool position( const pixel_point& pos);
		//~ pixel_point position();

		//~ bool screen_buffer_size( const size &_size );
		//~ Console::size screen_buffer_size( ) const;

		bool size( const size &_size );
		Console::size size( ) const;

		//~ Console::size max_size() const;

		//~ std::string title() const;
		bool title( const std::string &_title );

		//~ cursor cursor() const;
		//~ bool cursor( const Console::cursor &_cursor );

		bool cursor_position( const point& pt );
		point cursor_position() const;

		//~ void background_color(color _color);
		//~ Console::color background_color() const{return bg;}

		void text_background(Console::color _color );
		void text_color(color _color );

		color text_color() const;
		color text_background() const;

		//~ Console::font font() const;
		//~ bool font(const Console::font &_font);

		/*The handle of a console window is a Windows HWND handle*/
		//~ void* handle() const {return hwnd;}

		//~ void hide();	
		//~ void show();
		//~ void minimize();
		//~ void maximize();
		//~ void restore();

		//~ bool is_shown() const;
		//~ bool is_minimized() const;
		//~ bool is_maximized() const;

		void clear();

		/*hIcon is a Windows API HICON handle*/
		//~ void icon(void *hIcon);
		//~ void icon(const std::string &_szFile);

	}; 
}
#endif

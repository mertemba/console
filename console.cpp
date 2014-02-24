
#include "console.hpp"

#include <sys/ioctl.h>
#include <linux/vt.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

using namespace Console;

console::console()
{
	text_color(white);
	text_background(black);
}

Console::size console::size() const
{
	winsize s;
	ioctl(STDOUT_FILENO, TIOCGWINSZ, &s);
	return Console::size(s.ws_col, s.ws_row);
}

bool console::size(const Console::size& s)
{
	winsize ts;
	ts.ws_col = s.width;
	ts.ws_row = s.height;
	int ret = ioctl(STDOUT_FILENO, TIOCSWINSZ, &ts);
	printf("\e[8;%d;%dt", s.width, s.height);
	return ret != -1;
}

bool console::title(const std::string& str)
{
	printf("\033]0;%s\007", str.c_str());
	return true;
}

void console::clear()
{
	// color
	puts("\033c");
}

bool console::cursor_position(const point& p)
{
	printf("\033[%d;%dH", p.x, p.y);
}

void console::text_color(color col)
{
	this->col = col;
	update_colors();
}

color console::text_color() const
{
	return col;
}

void console::text_background(color col)
{
	this->bg = col;
	update_colors();
}

color console::text_background() const
{
	return bg;
}

void console::update_colors()
{
	printf("\x1b[0m");
	printf("\x1b[3%d%s;4%dm", col%8, col>=8?";1":"", bg%8);
}


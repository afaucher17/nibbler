/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   LibNcurses.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdieumeg <tdieumeg@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/19 12:27:33 by tdieumeg          #+#    #+#             */
/*   Updated: 2015/10/19 15:46:36 by tdieumeg         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "LibNcurses.hpp"

static std::map<type_e, std::map<cardinal_e, char> >		_sprites =
{
	{SNAKE_HEAD_1,{ {NORTH, '^'} }},
	{SNAKE_HEAD_1,{ {EAST, '>'} }},
	{SNAKE_HEAD_1,{ {WEST, '<'} }},
	{SNAKE_HEAD_1,{ {SOUTH, 'v'} }},
	{SNAKE_BODY_1,{ {NORTH, 186} }},
	{SNAKE_BODY_1,{ {EAST, 205} }},
	{SNAKE_BODY_1,{ {WEST, 205} }},
	{SNAKE_BODY_1,{ {SOUTH, 186} }},
	{SNAKE_BODY_1,{ {NORTH_EAST, 187} }},
	{SNAKE_BODY_1,{ {NORTH_WEST, 201} }},
	{SNAKE_BODY_1,{ {SOUTH_EAST, 188} }},
	{SNAKE_BODY_1,{ {SOUTH_WEST, 200} }},
	{SNAKE_TAIL_1,{ {NORTH, 186} }},
	{SNAKE_TAIL_1,{ {EAST, 205} }},
	{SNAKE_TAIL_1,{ {WEST, 205} }},
	{SNAKE_TAIL_1,{ {SOUTH, 186} }},
	{SNAKE_HEAD_2,{ {NORTH, '^'} }},
	{SNAKE_HEAD_2,{ {EAST, '>'} }},
	{SNAKE_HEAD_2,{ {WEST, '<'} }},
	{SNAKE_HEAD_2,{ {SOUTH, 'v'} }},
	{SNAKE_BODY_2,{ {NORTH, 186} }},
	{SNAKE_BODY_2,{ {EAST, 205} }},
	{SNAKE_BODY_2,{ {WEST, 205} }},
	{SNAKE_BODY_2,{ {SOUTH, 186} }},
	{SNAKE_BODY_2,{ {NORTH_EAST, 187} }},
	{SNAKE_BODY_2,{ {NORTH_WEST, 201} }},
	{SNAKE_BODY_2,{ {SOUTH_EAST, 188} }},
	{SNAKE_BODY_2,{ {SOUTH_WEST, 200} }},
	{SNAKE_TAIL_2,{ {NORTH, 186} }},
	{SNAKE_TAIL_2,{ {EAST, 205} }},
	{SNAKE_TAIL_2,{ {WEST, 205} }},
	{SNAKE_TAIL_2,{ {SOUTH, 186} }},
	{OBSTACLE, {{NORTH, ' '}}},
	{FOOD, {{NORTH, 'o'}}},
	{UNKNOWN, {{NORTH, '?'}}}
};

LibNcurses::LibNcurses(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	cbreak();
	refresh();
	curs_set(0);
	this->_window = newwin(0, 0, 0, 0);
	keypad(this->_window, true);
	return ;
}

LibNcurses::LibNcurses(LibNcurses const & src)
{
	*this = src;
	return ;
}

LibNcurses::LibNcurses(int height, int width, std::string winName)
{
	(void)winName;
	initscr();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_MAGENTA, COLOR_BLACK);
	cbreak();
	refresh();
	curs_set(0);
	this->_window = newwin(height, width, 0, 0);
	keypad(this->_window, true);
	return ;
}

LibNcurses::~LibNcurses(void)
{
	_terminate();
	return ;
}

LibNcurses &		LibNcurses::operator=(LibNcurses const & rhs)
{
	this->_window = rhs._window;
	return *this;
}

void				LibNcurses::display(std::list<IGameObject*> const game_objects)
{
	std::list<IGameObject*>::const_iterator		obj;
	std::map<type_e, std::map<cardinal_e, char> >::iterator		type;
	std::map<cardinal_e, char>::iterator	dir;

	werase(this->_window);
	for (obj = game_objects.begin(); obj != game_objects.end(); obj++)
		for (type = this->_sprites.begin(); type != this->_sprites.end(); type++)
			for (dir = type->second.begin(); dir != type->second.end(); dir++)
				if (((*obj)->getType() == type->first) && ((*obj)->getCurrentDirection().getCardinal() == dir->first))
					this->_display_sprite((*obj)->getPosition().getX(), (*obj)->getPosition().getY(), dir->second, (*obj)->getType());
	wrefresh(this->_window);
	return ;
}

void				LibNcurses::display_score(std::list<int> const scores)
{
	(void)scores;
	return ;
}

void				LibNcurses::_display_sprite(int const x, int const y, char const sprite, type_e const type)
{
	int				pair;

	pair = 1;
	wmove(this->_window, x, y);
	if (type == OBSTACLE)
		pair = 1;
	if (type == FOOD)
		pair = 2;
	if ((type == SNAKE_HEAD_1) || (type == SNAKE_BODY_1) || (type == SNAKE_TAIL_1))
		pair = 3;
	if ((type == SNAKE_HEAD_2) || (type == SNAKE_BODY_2) || (type == SNAKE_TAIL_2))
		pair = 4;
	wattron(this->_window, COLOR_PAIR(pair));
	wprintw(this->_window, "%c", sprite);
	wattroff(this->_window, COLOR_PAIR(pair));
	return ;
}

void				LibNcurses::_terminate(void)
{
	delwin(this->_window);
	endwin();
	return ;
}

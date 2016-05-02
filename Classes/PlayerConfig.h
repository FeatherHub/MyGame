#pragma once

enum DIRECTION : short
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

enum MOVE : short
{
	DEFAULT_SPEED = 5
};

enum STATE : int
{
	ENTER_BABE = 0,
	EXIT_BABE = 1,
	IN_BABE = 2,
	OUT_BABE = 3
};
#pragma once

// ºï×Ó
class Monkey
{
public:
	Monkey() {}
	virtual ~Monkey() {}
	virtual Monkey* Clone() = 0;  // ¿ËÂ¡
	virtual void Play() = 0;  // ÍæË£
};
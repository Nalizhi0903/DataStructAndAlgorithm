#pragma once

#include "Page.h"


enum signal
{
	Back = 0,
	NewPage,
	Quit
};

class CBrowser
{
public:
	CBrowser();
	virtual ~CBrowser();
public:
	void show();
private:
	void initHomePage();
private:
	CPage m_pgHome;
public:
	static signal s_signal;
};
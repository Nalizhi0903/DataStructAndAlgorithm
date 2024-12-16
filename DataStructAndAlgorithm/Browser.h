#pragma once

#include "Page.h"

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
};
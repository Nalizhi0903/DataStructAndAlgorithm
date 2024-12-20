#include "Browser.h"
#ifdef _WIN32
#include <Windows.h>
#endif

signal CBrowser::s_signal = signal::NewPage;

CBrowser::CBrowser()
{

}

CBrowser::~CBrowser()
{

}

void CBrowser::show()
{
	// Clear previous page content
#ifdef _WIN32
	system("cls");
#endif
	initHomePage();
}

void CBrowser::initHomePage()
{
	std::vector<std::vector<std::string>> textGridContent;
	m_pgHome.setTitle("Home");
	m_pgHome.setContent(textGridContent);
	m_pgHome.addOperation("Algorithm", Page::OperationFlag::Stay);
	m_pgHome.addOperation("DataStruct", Page::OperationFlag::Stay);
	m_pgHome.showPage();
}
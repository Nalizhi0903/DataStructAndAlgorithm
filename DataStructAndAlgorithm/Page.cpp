#include "Page.h"

#define MAX_WIDTH 64
#define MAX_HEIGHT 64

CPage::CPage():m_iHeight(64), m_iWidth(64)
{

}

CPage::~CPage()
{

}

void CPage::showPage()
{
	// 打印上边框
	for (int i = 0; i < m_iWidth; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;

	// Print title
	std::cout << m_strTilte << std::endl;

	// 打印下边框
	for (int i = 0; i < m_iWidth; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}

void CPage::setTitle(const std::string& strText)
{
	m_strTilte = std::move(strText);
}

void CPage::showContent()
{
	if (m_textGridContent.empty())
	{
		return;
	}
	std::cout << std::endl;
}

// TODO
void CPage::setContent(const std::vector<std::vector<std::string>>& textGridContent)
{
	// TODO
	// Judge the width and height, if anyone of them exceed the max size, return;

	return;
}
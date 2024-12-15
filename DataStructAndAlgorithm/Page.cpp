#include "Page.h"

#define MAX_WIDTH 64
#define MAX_HEIGHT 64

CPage::CPage():m_iHeight(64), m_iWidth(64), m_aligimentFlag(Page::Left)
{
	setAlignment(Page::Center);
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
	printLine(m_strTilte);

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

void CPage::setAlignment(Page::Aligiment aligiment)
{
	m_aligimentFlag = aligiment;
}

void CPage::setLineAligiment(const std::string& strContent)
{
	if (m_aligimentFlag == Page::Left)
	{
		return;
	}
	else if (m_aligimentFlag == Page::Center)
	{

		for (int i = 0; i < (m_iWidth - strContent.size()) / 2; i++)
		{
			std::cout << " ";
		}
	}
	else if (m_aligimentFlag == Page::Right)
	{
		for (int i = 0; i < m_iWidth - strContent.size(); i++)
		{
			std::cout << " ";
		}
	}
}

void CPage::printLine(const std::string& strContent)
{
	if (m_iWidth < strContent.size())
	{
		return;
	}
	else if (m_iWidth == strContent.size() || m_aligimentFlag == Page::Left)
	{
		std::cout << strContent << std::endl;
	}
	else
	{
		setLineAligiment(strContent);
		std::cout << strContent << std::endl;
	}
}
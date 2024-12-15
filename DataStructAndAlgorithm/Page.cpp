#include "Page.h"

#define MAX_WIDTH 64
#define MAX_HEIGHT 64

CPage::CPage():m_iHeight(64), m_iWidth(64), 
			   m_alignmentFlag(Page::Left), m_iOptionCount(0)
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

	// Print option
	auto it = m_vtstrOptions.begin();
	while (it != m_vtstrOptions.end())
	{
		size_t index = std::distance(m_vtstrOptions.begin(), it);
		if (index >= m_iOptionCount)
		{
			break;
		}
		std::string strOption = std::to_string(index + 1).append(".").append(*it);
		printLine(strOption);
		it++;
	}

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
	m_alignmentFlag = aligiment;
}

void CPage::setLineAligiment(const std::string& strContent)
{
	if (m_alignmentFlag == Page::Left)
	{
		return;
	}
	else if (m_alignmentFlag == Page::Center)
	{

		for (int i = 0; i < (m_iWidth - strContent.size()) / 2; i++)
		{
			std::cout << " ";
		}
	}
	else if (m_alignmentFlag == Page::Right)
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
	else if (m_iWidth == strContent.size() || m_alignmentFlag == Page::Left)
	{
		std::cout << strContent << std::endl;
	}
	else
	{
		setLineAligiment(strContent);
		std::cout << strContent << std::endl;
	}
}

void CPage::addOperation(const std::string& strOperationName)
{
	m_iOptionCount++;
	m_vtstrOptions.push_back(strOperationName);
}
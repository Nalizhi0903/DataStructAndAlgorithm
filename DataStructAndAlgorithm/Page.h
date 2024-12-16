#pragma once

#include "Util.h"
#include "common.h"

namespace Page
{
	enum Alignment
	{
		Left = 0,
		Center,
		Right,
		Empty
	};

	enum EnterFlag
	{
		False,
		True
	};
}

class CPage
{
public:
	// Empty page
	CPage();
	virtual ~CPage();

public:
	// show this page
	void showPage();
	void setTitle(const std::string& strText);
	void setContent(const std::vector<std::vector<std::string>>& textGridContent);
	// set the all alignment of the page
	void setAlignment(Page::Alignment alignment);
	void addOperation(const std::string& strOperationName);

private:
	void showContent();
	// set the alignment of a line in page
	void setLineAlignment(const std::string& strContent, Page::Alignment alignment = Page::Empty);
	void printLine(const std::string& strContent, Page::EnterFlag flag, Page::Alignment alignment = Page::Empty);
	void waitForOperation();

private:
	// title
	std::string m_strTilte;
	// count of options
	int m_iOptionCount;
	// store all options
	std::vector<std::string> m_vtstrOptions;
	// real Height & Width of page
	int m_iWidth;
	int m_iHeight;
	// alignment flag
	Page::Alignment m_alignmentFlag;
	// main content
	std::vector<std::vector<std::string>> m_textGridContent;
};


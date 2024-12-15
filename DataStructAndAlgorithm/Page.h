#pragma once

#include "Util.h"
#include "common.h"

namespace Page
{
	enum Aligiment
	{
		Left = 0,
		Center,
		Right
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
	void setAlignment(Page::Aligiment aligiment);
	void addOperation(const std::string& strOperationName);

private:
	void showContent();
	// set the alignment of a line in page
	void setLineAligiment(const std::string& strContent);
	void printLine(const std::string& strContent);

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
	Page::Aligiment m_alignmentFlag;
	// main content
	std::vector<std::vector<std::string>> m_textGridContent;
};


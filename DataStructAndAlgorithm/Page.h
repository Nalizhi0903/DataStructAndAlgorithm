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
		False = 0,
		True
	};

	enum OperationFlag
	{
		Back = 0, 
		NewPage,
		Stay,
		Quit
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
	void setTitle(const std::string& strText);
	void setContent(const std::vector<std::vector<std::string>>& textGridContent);
	void showPage();
	// set the all alignment of the page
	void setAlignment(Page::Alignment alignment);
	void addOperation(const std::string& strOperationName, const Page::OperationFlag& operationFlag);

private:
	void showContent();
	// set the alignment of a line in page
	void setLineAlignment(const std::string& strContent, Page::Alignment alignment = Page::Empty);
	void printLine(const std::string& strContent, Page::EnterFlag flag, Page::Alignment alignment = Page::Empty);
	int waitForOperation();
	void excuteOperation(int iOperation, Page::OperationFlag& operationFlag);

private:
	// title
	std::string m_strTilte;
	// count of options
	int m_iOptionCount;
	// store all options
	std::vector<std::pair<std::string, Page::OperationFlag>> m_vtstrOptions;
	// real Height & Width of page
	int m_iWidth;
	int m_iHeight;
	// alignment flag
	Page::Alignment m_alignmentFlag;
	// main content
	std::vector<std::vector<std::string>> m_textGridContent;
};


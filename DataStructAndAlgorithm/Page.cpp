#include "Page.h"
#include "Browser.h"

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
	printLine(m_strTilte, Page::EnterFlag::True);

	// Print option
	auto it = m_vtstrOptions.begin();
	while (it != m_vtstrOptions.end())
	{
		size_t index = std::distance(m_vtstrOptions.begin(), it);
		if (index >= m_iOptionCount)
		{
			break;
		}
		std::string strOption = std::to_string(index + 1).append(".").append(it->first);
		printLine(strOption, Page::EnterFlag::True);
		it++;
	}

	// 打印下边框
	for (int i = 0; i < m_iWidth; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;

	// Waitting for user's operation
	Page::OperationFlag operationFlag;
	while (true)
	{
		excuteOperation(waitForOperation(), operationFlag);
		if (operationFlag == Page::OperationFlag::Back)
		{
			// set signal
			std::cout << operationFlag << std::endl;
			CBrowser::s_signal = signal::Back;
			break;
		}
		else if (operationFlag == Page::OperationFlag::Stay)
		{
			// TODO using list to store the fuction pointer
			// excute additonal work
			std::cout << operationFlag << std::endl;
			continue;
		}
		else if (operationFlag == Page::OperationFlag::NewPage)
		{
			// set signal
			std::cout << operationFlag << std::endl;
			CBrowser::s_signal = signal::NewPage;
			break;
		}
		else if (operationFlag == Page::OperationFlag::Quit)
		{
			// set signal
			std::cout << operationFlag << std::endl;
			CBrowser::s_signal = signal::Quit;
			break;
		}
	}
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

void CPage::setAlignment(Page::Alignment aligiment)
{
	m_alignmentFlag = aligiment;
}

void CPage::setLineAlignment(const std::string& strContent, Page::Alignment alignment)
{
	Page::Alignment tmpAlignmentFlag;
	if (alignment != Page::Alignment::Empty)
	{
		tmpAlignmentFlag = alignment;
	}
	else
	{
		tmpAlignmentFlag = m_alignmentFlag;
	}

	if (tmpAlignmentFlag == Page::Left)
	{
		return;
	}
	else if (tmpAlignmentFlag == Page::Center)
	{

		for (int i = 0; i < (m_iWidth - strContent.size()) / 2; i++)
		{
			std::cout << " ";
		}
	}
	else if (tmpAlignmentFlag == Page::Right)
	{
		for (int i = 0; i < m_iWidth - strContent.size(); i++)
		{
			std::cout << " ";
		}
	}
}

void CPage::printLine(const std::string& strContent, Page::EnterFlag flag, Page::Alignment alignment)
{
	if (m_iWidth < strContent.size())
	{
		return;
	}
	else if (m_iWidth == strContent.size() || alignment == Page::Left)
	{
		std::cout << strContent;
	}
	else
	{
		setLineAlignment(strContent, alignment);
		std::cout << strContent;
	}

	if (flag == Page::EnterFlag::True)
	{
		std::cout << "\n";
	}
}

void CPage::addOperation(const std::string& strOperationName, const Page::OperationFlag& operationFlag)
{
	m_iOptionCount++;
	m_vtstrOptions.push_back(std::make_pair(strOperationName, operationFlag));
}

int CPage::waitForOperation()
{
	printLine("Please enter the number of selection:", Page::EnterFlag::False, Page::Alignment::Left);
	int iOperation;
	std::string strInput;
	std::getline(std::cin, strInput);
	try 
	{
		iOperation = std::stoi(strInput);
		if (iOperation != 0)
		{
			iOperation--;
		}
	}
	catch (const std::invalid_argument& e) 
	{
		std::cout << "Invalid input, please input a intergration number" << std::endl;
		iOperation = 0;
	}
	catch (const std::out_of_range& e) 
	{
		std::cout << "Out of range" << std::endl;
		iOperation = 0;
	}
	return iOperation;
}

void CPage::excuteOperation(int iOperation, Page::OperationFlag& operationFlag)
{
	if (iOperation < 0 || iOperation >= m_iOptionCount)
	{
		printLine("No option", Page::EnterFlag::True, Page::Alignment::Left);
		excuteOperation(waitForOperation(), operationFlag);
		return;
	}
	operationFlag = m_vtstrOptions[iOperation].second;
	return;
}
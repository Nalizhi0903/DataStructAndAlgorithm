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
	// ��ҳ��
	CPage();
	virtual ~CPage();

public:
	// ��ʾ��ҳ��
	void showPage();
	void setTitle(const std::string& strText);
	void setContent(const std::vector<std::vector<std::string>>& textGridContent);
	void setAlignment(Page::Aligiment aligiment);
private:
	void showContent();
	void setLineAligiment(const std::string& strContent);
	void printLine(const std::string& strContent);

private:
	// ����
	std::string m_strTilte;
	// ѡ�����
	int m_iOptionNumber;
	int m_iWidth;
	int m_iHeight;
	Page::Aligiment m_aligimentFlag;
	std::vector<std::vector<std::string>> m_textGridContent;
};


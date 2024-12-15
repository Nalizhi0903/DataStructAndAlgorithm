#pragma once

#include "Util.h"
#include "common.h"

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
private:
	void showContent();

private:
	// ����
	std::string m_strTilte;
	// ѡ�����
	int m_iOptionNumber;
	int m_iWidth;
	int m_iHeight;
	std::vector<std::vector<std::string>> m_textGridContent;
};


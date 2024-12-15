#pragma once

#include "Util.h"
#include "common.h"

class CPage
{
public:
	// 空页面
	CPage();
	virtual ~CPage();

public:
	// 显示此页面
	void showPage();
	void setTitle(const std::string& strText);
	void setContent(const std::vector<std::vector<std::string>>& textGridContent);
private:
	void showContent();

private:
	// 标题
	std::string m_strTilte;
	// 选项个数
	int m_iOptionNumber;
	int m_iWidth;
	int m_iHeight;
	std::vector<std::vector<std::string>> m_textGridContent;
};


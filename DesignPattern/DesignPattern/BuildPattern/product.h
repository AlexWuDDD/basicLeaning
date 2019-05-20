#pragma once

#include <iostream>

using namespace std;

//µçÄÔ
class Computer
{
public:
	void SetmCpu(string cpu) { m_strCpu = cpu; }
	void SetmMainboard(string mainboard) { m_strMainboard = mainboard; }
	void SetmRam(string ram) { m_strRam = ram; }
	void SetmVideoCard(string videoCard) { m_strVideoCard = videoCard; }

	string GetCPU() { return m_strCpu; }
	string GetMainboard(){ return m_strMainboard; }
	string GetRam() { return m_strRam; }
	string GetVideoCard() { return m_strVideoCard; }

private:
	string m_strCpu;
	string m_strMainboard;
	string m_strRam;
	string m_strVideoCard;
};
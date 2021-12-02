#include "DiceThread.h"
#include <QTime>

void DiceThread::run()
{
	m_stop = false;
	m_seq = 0;
	qsrand(QTime::currentTime().msec());
	while (!m_stop)
	{
		if (!m_Paused)
		{
			m_diceValue = qrand();
			m_diceValue = (m_diceValue % 6) + 1;
			m_seq++;
			emit newValue(m_seq, m_diceValue);
		}
		msleep(500);
	}
	quit();
}

DiceThread::DiceThread()
{

}

void DiceThread::diceBegin()
{
	m_Paused = false;
}


void DiceThread::dicePause()
{
	m_Paused = true;
}

void DiceThread::stopThread()
{
	m_stop = true;
}
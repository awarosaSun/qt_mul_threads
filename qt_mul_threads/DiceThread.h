#pragma once

#include <QThread>


class DiceThread :
	public QThread
{
	Q_OBJECT

private:
	int m_seq = 0;
	int m_diceValue;
	bool m_Paused = true;
	bool m_stop = false;

protected:
	void run()
		Q_DECL_OVERRIDE;

public:
	explicit DiceThread();
	void diceBegin();
	void dicePause();
	void stopThread();


signals:
	void newValue(int seq, int diceValue);

public slots:

};


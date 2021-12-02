#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MainWindow.h"

#include "DiceThread.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
	DiceThread threadA;

protected:
	void closeEvent(QCloseEvent *event) Q_DECL_OVERRIDE;

public:
    MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private:
    Ui::MainWindowClass *ui;

private slots:
	void on_threadAnewValue(int seq, int diceValue);
	void on_threadAStarted();
	void on_threadAFinished();

private slots:
	void on_btnStartThread_clicked();
	void on_btnStopThread_clicked();

};

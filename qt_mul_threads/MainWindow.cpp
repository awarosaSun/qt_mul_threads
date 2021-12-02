#include "MainWindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    ui->setupUi(this);
	connect(&threadA, SIGNAL(started()), this, SLOT(on_threadAStarted()));
	connect(&threadA, SIGNAL(finished()), this, SLOT(on_threadAFinished()));
}

//THREAD A quit out
void MainWindow::closeEvent(QCloseEvent *event)
{
	//qDebug() << "come into closeEvent";
	if (threadA.isRunning())
	{
		threadA.stopThread();
		threadA.wait();
	}
	event->accept();
}

MainWindow::~MainWindow()
{
	delete ui;
}


void MainWindow::on_threadAnewValue(int seq, int diceValue)
{

}

void MainWindow::on_threadAStarted()
{
	//qDebug() << "come into on_threadAStarted";
	ui->LabA->setText("threadA status:started");
}

void MainWindow::on_threadAFinished()
{
	ui->LabA->setText("threadA status:finished");

	/*ui->btnStartThread->setEnabled(true);
	ui->btnDiceBegin->setEnabled(false);
	ui->btnDiceEnd->setEnabled(true);
	ui->btnStopThread->setEnabled(false);*/
}

void MainWindow::on_btnStartThread_clicked()
{
	threadA.start();
	ui->btnStartThread->setEnabled(false);
	ui->btnDiceBegin->setEnabled(true);
	ui->btnDiceEnd->setEnabled(false);
	ui->btnStopThread->setEnabled(true);
}

void MainWindow::on_btnStopThread_clicked()
{
	threadA.stopThread();
	threadA.wait();

	ui->btnStartThread->setEnabled(false);
	ui->btnDiceBegin->setEnabled(true);
	ui->btnDiceEnd->setEnabled(false);
	ui->btnStopThread->setEnabled(true);
}
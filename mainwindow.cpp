#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // GroupBox gb_winner param
    ui->gb_winner->setTitle("Who will win?");
    ui->rb_winner_harris->setText("Kamala Harris");
    ui->rb_winner_trump->setText("Donald Trump");

    // ComboBox cb_english_level param
    ui->l_english_level->setText("What is your English level?");
    ui->cb_english_level->addItems({"A1", "A2", "B1", "B2", "C1", "C2"});

    // Progress bar pbar_progress param
    ui->pbar_progress->setRange(0, 10);
    ui->pbar_progress->setValue(0);
    ui->pbar_progress->setAlignment(Qt::AlignCenter);

    // Push Button pb_progress param
    ui->pb_progress->setText("Progress or Die");
    ui->pb_progress->setCheckable(true);
    ui->pb_progress->setChecked(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_progress_clicked()
{
    if (ui->pb_progress->isChecked()) {
        ui->pbar_progress->setValue((ui->pbar_progress->value() + 1) % (ui->pbar_progress->maximum() + 1));
    }
}


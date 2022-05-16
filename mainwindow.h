#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include "qfiledialog.h"
#include<QInputDialog>
#include <QtAlgorithms>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_actionOpen_triggered();

    void on_actionSave_as_triggered();

    void on_actionSave_triggered();



    void on_actionCopy_triggered();

    void on_actionPaste_triggered();

    void on_actionCut_triggered();

    void on_actionUndo_triggered();

    void on_actionRedo_triggered();

    void on_actionNew_triggered();

    void on_actionEncrypt_triggered();

    void on_actionDecrypt_triggered();

    void on_actionCount_the_exist_of_a_word_triggered();

    void on_actionMerge_another_file_triggered();

    void on_actionCount_number_of_words_triggered();

    void on_actionCount_number_of_characters_triggered();

    void on_actionCount_number_of_lines_triggered();

    void on_actionTo_Upper_triggered();

    void on_actionTo_Lower_triggered();


    void on_action1st_Char_is_upper_triggered();

    void on_actionSearch_for_a_word_triggered();

private:
    Ui::MainWindow *ui;
    QString currentFile="";
};
#endif // MAINWINDOW_H

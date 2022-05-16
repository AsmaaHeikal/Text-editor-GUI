#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setCentralWidget(ui->textEdit );

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this , "Open the file");
     QFile file (fileName );
     currentFile = fileName;
     if (!(file.open(QFile::ReadOnly) | QFile::Text)){
         QMessageBox::warning(this, "...","File not open");
         return;
     }
     QTextStream in(&file);
     QString text = in.readAll();
     ui->textEdit->setText(text);
     file.close();
}


void MainWindow::on_actionSave_as_triggered()
{
    QString fileName = QFileDialog::getSaveFileName(this , "Open the file");
     QFile file (fileName );
     currentFile = fileName;
     if (!(file.open(QFile::WriteOnly) | QFile::Text)){
         QMessageBox::warning(this, "...","File not open");
         return;
     }
     QTextStream Out(&file);
     QString text = ui-> textEdit -> toPlainText();
     Out << text;
     file.flush();
     file.close();
}


void MainWindow::on_actionSave_triggered()
{

     QFile file (currentFile );
     if (!(file.open(QFile::WriteOnly) | QFile::Text)){
         QMessageBox::warning(this, "...","File not open");
         return;
     }
     QTextStream Out(&file);
     QString text = ui-> textEdit -> toPlainText();
     Out << text;
     file.flush();
     file.close();
}




void MainWindow::on_actionCopy_triggered()
{
    ui -> textEdit -> copy();
}


void MainWindow::on_actionPaste_triggered()
{
    ui -> textEdit ->paste();
}


void MainWindow::on_actionCut_triggered()
{
    ui -> textEdit -> cut();
}


void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}


void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}


void MainWindow::on_actionNew_triggered()
{
    currentFile ="" ;
    ui->textEdit->setText("");
}


void MainWindow::on_actionEncrypt_triggered()
{
    QString newTxt="";
    QString text = ui-> textEdit -> toPlainText();
    ui->textEdit->clear();

    for (int i = 0 ; i < text.size(); i++){
       if (text[i] == 'z'){
           newTxt+= 'a';
       }
       else if (text[i]== 'Z'){
           newTxt += 'A';
       }
       else{

           int c = text[i].unicode();
           newTxt+= (QChar)(c+1);
       }
    }
    ui->textEdit->setText(newTxt);
}


void MainWindow::on_actionDecrypt_triggered()
{
    QString newTxt="";
    QString text = ui-> textEdit -> toPlainText();
    ui->textEdit->clear();

    for (int i = 0 ; i < text.size(); i++){
       if (text[i] == 'a' ){
           newTxt+= 'z';
       }
       else if (text[i] == 'A'){
           newTxt += 'Z';
       }
       else{

           int c = text[i].unicode();
           newTxt+= (QChar)(c-1);
       }
    }
    ui->textEdit->setText(newTxt);

}




void MainWindow::on_actionMerge_another_file_triggered()
{

    QString fileName2 = QFileDialog::getOpenFileName(this , "Open the file");
     QFile file2 (fileName2 );
     if (!(file2.open(QFile::ReadOnly) | QFile::Text)){
         QMessageBox::warning(this, "...","File not open");
         return;
     }
     QTextStream in(&file2);
     QString text = in.readAll();
     file2.close();
     ui -> textEdit ->append(text);
}


void MainWindow::on_actionCount_number_of_words_triggered()
{
    QFile file = currentFile;
    int counter =-1;
    if ((file.open(QFile::ReadOnly) | QFile::Text)){
        QTextStream read(&file);
        while(!read.atEnd()){
        QString str;
        read >> str;
        counter++;
        }
    }
    if (counter==0 )
        counter =1;
    else if (counter == -1)
        counter = 0;

           QString msg = QString::number(counter);
         QMessageBox::information(this, "Number of words = " , msg);

}


void MainWindow::on_actionCount_number_of_characters_triggered()
{

        int counter =0;
        QString text = ui -> textEdit -> toPlainText();
        for (int i = 0 ; i < text.size(); i++){
           counter++;
        }
        QString msg = QString::number(counter);
      QMessageBox::information(this, "Number of characters = " , msg);

}


void MainWindow::on_actionCount_number_of_lines_triggered()
{
    on_actionSave_triggered();
    QFile file (currentFile);
    int counter= 0;
    if (file.open(QFile::ReadOnly) | QFile::Text){
        QTextStream read(&file);
        while(!read.atEnd()){
            read.readLine();
            counter++;
        }
    }
    file.close();
    QString msg = QString::number(counter);
  QMessageBox::information(this, "Number of lines = " , msg);


}


void MainWindow::on_actionTo_Upper_triggered()
{
    QString text = ui -> textEdit-> toPlainText();
    ui->textEdit->clear();
    for(int i =0;i<text.size();i++){
        text[i] = text[i].toUpper();
    }
    ui->textEdit->setPlainText(text);
}



void MainWindow::on_actionTo_Lower_triggered()
{
    QString text = ui -> textEdit-> toPlainText();
    ui->textEdit->clear();
    for(int i =0;i<text.size();i++){
        text[i] = text[i].toLower();
    }
    ui->textEdit->setPlainText(text);
}




void MainWindow::on_action1st_Char_is_upper_triggered()
{
    on_actionSave_triggered();
    QString newTxt ="";
      QFile file = currentFile;
      ui -> textEdit -> clear();
    if ((file.open(QFile::ReadOnly) | QFile::Text)){
        QTextStream read(&file);
        while(!read.atEnd()){
        QString str;
        read >> str;
        str = str.toLower();
        if(str.size()>0)
       str[0] = str[0].toUpper();
       newTxt += str + ' ';

   }
    }
    file.close();

    ui ->textEdit ->setText(newTxt);

}


void MainWindow::on_actionSearch_for_a_word_triggered()
{
    bool check;
        QString word = QInputDialog::getText(this,tr("QInputDialog::getText()"),tr("Enter the word:"),QLineEdit::Normal,QDir::home().dirName(),&check);

        for(int i =0;i<word.size();i++){
            word[i] = word[i].toLower();
        }
        QString content = ui->textEdit->toPlainText();
        for(int i =0;i<content.size();i++){
            content[i]= content[i].toLower();
        }
        if(content.contains(word)){
            QMessageBox::information(this,"...","the word is in the file!");
        }
        else{
              QMessageBox::information(this,"...","the word is not in the file!");
        }
}


void MainWindow::on_actionCount_the_exist_of_a_word_triggered()
{
    bool check;
        QString word = QInputDialog::getText(this,tr("QInputDialog::getText()"),tr("Enter the word:"),QLineEdit::Normal,QDir::home().dirName(),&check);

        for(int i =0;i<word.size();i++){
            word[i] = word[i].toLower();
        }
        QString content = ui->textEdit->toPlainText();
        for(int i =0;i<content.size();i++){
            content[i]= content[i].toLower();
        }
        int counter = 0;
        if(content.contains(word)){
            counter = content.count(word);
        }
        else{
              QMessageBox::information(this,"...","the word is not in the file!");
        }
        QString msg = QString::number(counter);
        QMessageBox::information(this,"number of Repetition of this word =",msg);
}


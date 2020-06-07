#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"QFileDialog"
#include "QPixmap"
#include"QMessageBox"
#include"Huffman.hpp"
#include"pgmb_io_V3.hpp"
#include"utility.hpp"
#include <bits/stdc++.h>
using namespace std;
struct fileName
{
    string imageNameNoExtension;
    string encoded_pgm;
    string freq;
    string output_name;
};
void Compress(pgm &read_pic, string imageNameNoExtension)
{
    unordered_map<int, int> frequencyTable;
    buildFreqTable(read_pic.data, frequencyTable);
    unordered_map<int, int> tempTable;
    for (int i = 0; i < 256; i++)
        if (frequencyTable.count(i))
            tempTable[i] = frequencyTable[i];

    frequencyTable = tempTable;
    Huffman compressor;
    auto codes = compressor.Encode(frequencyTable);
    serializePgm(read_pic, codes, imageNameNoExtension + ".enc");
    serializeFreq(frequencyTable, imageNameNoExtension + ".frq");
}
//***********************************************************************
void Decompress(pgm &write_pic, fileName &file_name)
{
    Huffman decompressor;
    string encodedData = "";
    deserializePgm(file_name.encoded_pgm, write_pic, encodedData);
    unordered_map<int, int> dFrequencyTable;
    deserializeFreq(file_name.freq, dFrequencyTable);
    write_pic.data = decompressor.Decode(encodedData, dFrequencyTable);
}
//***************************************************
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_2_clicked()
{
    QMessageBox messagebox;
    fileName image_name;
    file_name= QFileDialog::getOpenFileName(this,"Open a file","../"); //opening file
        QMessageBox::information(this,"..",file_name);
       ui->label->setPixmap(file_name); // display chosen image
       QString variable = (file_name);
           std::string imageName = variable.toStdString(); // converting from Qstring to std::string

           if (imageName.length() < 4)
                   {

                          messagebox.critical(0,"Error","Bad file name");
                   }

                   else if (imageName.substr(imageName.length() - 4, 4) != ".pgm")
                   {
                     messagebox.critical(0,"Erro","Invalid file extention");

                   }
else {
    image_name.imageNameNoExtension = imageName.substr(0, imageName.length() - 4);
    pgm read_pic;
    int errorCount = pgmb_read(imageName, read_pic);
            if (errorCount)
            {
                messagebox.setText(" errors encountered");
            }
    Compress(read_pic, image_name.imageNameNoExtension);
    messagebox.information(this,"","Image Compressed Successfully");
    double compressed_size = file_size(image_name.imageNameNoExtension + ".enc"); //size after compression
    double Original_size =  file_size(image_name.imageNameNoExtension + ".pgm"); //size before compression
    double compression_ratio = (compressed_size)/(Original_size);
     ui->label_2->setNum(compression_ratio); //display file size
               //display compression ratio
}
}

void MainWindow::on_pushButton_3_clicked()
{
    QString encodedImage_file;
    QString frequencyTable_file;
    QMessageBox messagebox;
    fileName imageName;
    QStringList files = QFileDialog::getOpenFileNames(this,
                                tr("Choose two files (.enc & .frq)"),
                                "../",
                                tr("Compressed Files (*.enc *.frq)"));
    if (files.size()==2)
    {


           if (files[0].endsWith(".enc"))
           {
                   encodedImage_file = files[0];
                   frequencyTable_file = files [1];
           }
           else
           {
               frequencyTable_file = files[0];
               encodedImage_file = files[1];
           }
           imageName.encoded_pgm = encodedImage_file.toStdString();
           imageName.freq = frequencyTable_file.toStdString();


                   imageName.output_name = imageName.encoded_pgm.substr(0, imageName.encoded_pgm.length() - 4) + ".pgm";

                   pgm write_pic;
                   Decompress(write_pic,imageName);
                   messagebox.information(this,"..","Image decompressed and saved");
       }
       else
       {
           messagebox.critical(0,"Error","Please Select 2 files");
       }

}



#include "mainwindow.h"
#include <QtGui>
#include <iostream>

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  QUrl url;

  if (argc > 1) {
    url = QUrl(argv[1]);
  } else {
    url = QUrl("http://www.google.com/");
  }

  std::cout << " ====== HELLO FROM BROWSER ======" << std::endl;
  MainWindow *browser = new MainWindow(url);
  browser->show();

  return app.exec();
}

#include "mainwindow.h"
#include <QtWebKit>

MainWindow::MainWindow(const QUrl &url) : m_loadProgress(0) {
  m_webview = new QWebView(this);
  m_webview->load(url);

  connect(m_webview, SIGNAL(loadFinished(bool)), SLOT(adjustLocation()));
  connect(m_webview, SIGNAL(titleChanged(QString)), SLOT(adjustTitle()));

  setCentralWidget(m_webview);
}

void MainWindow::adjustTitle() {
  if (m_loadProgress <= 0 || m_loadProgress >= 100) {
    setWindowTitle(m_webview->title());
  } else {
    setWindowTitle(
        QString("%1 (%2%)").arg(m_webview->title()).arg(m_loadProgress));
  }
}

void MainWindow::setProgress(int p) {
  m_loadProgress = p;
  adjustTitle();
}

void MainWindow::finishLoading(bool) {
  m_loadProgress = 100;
  adjustTitle();
}

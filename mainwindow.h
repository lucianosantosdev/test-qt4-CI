#include <QMainWindow>
#include <QObject>

class QUrl;
class QWebView;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  MainWindow(const QUrl &url);

protected slots:
  void setProgress(int p);
  void finishLoading(bool);
  void adjustTitle();

private:
  QWebView *m_webview;
  int m_loadProgress = 0;
};

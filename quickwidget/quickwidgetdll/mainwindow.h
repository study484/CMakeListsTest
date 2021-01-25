#include <QQuickWidget>
#include <QQuickItem>
#include <QQmlError>
#include <QtWidgets>
#include "fbitem.h"
#include "add.h"
#include "quickwidgetdll.h"

namespace quickwidgetdll{
class quickwidgetdll_lib_shared_EXPORTS  MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow();

private slots:
    void quickWidgetStatusChanged(QQuickWidget::Status);
    void sceneGraphError(QQuickWindow::SceneGraphError error, const QString &message);
    void grabFramebuffer();
    void renderToPixmap();
    void grabToImage();
    void createQuickWidgetsInTabs(QMdiArea *mdiArea);

private:
    QQuickWidget *m_quickWidget;
};
}
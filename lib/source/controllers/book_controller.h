#ifndef BOOKCONTROLLER_H
#define BOOKCONTROLLER_H

#include <QObject>
#include <QString>
#include <QUrl>
#include <QVariant>
//#include <QtPdf/QPdfDocument>
//#include <QtPdfQuick/QtPdfQuick>

namespace sianreader{
    namespace controllers{
        class BookController : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(QUrl ui_currentPdf READ currentPdf CONSTANT)
            Q_PROPERTY(QString ui_totalPageCount READ totalPageCount CONSTANT)
            Q_PROPERTY(QString ui_currentPage READ currentPage CONSTANT)
        public:
            explicit BookController(QObject *parent = nullptr);
            ~BookController();

            const QUrl& currentPdf() const;
            const QString totalPageCount() const;
            const QString currentPage() const;

        signals:
            void pdfChanged();
            void currentPageChanged();

        public slots:
            void setPdfBook(QUrl* pdf_url);
            void setPdfDocument(QObject* doc, QObject* doc_view);
            void emitCurrentPageChanged(){
                emit currentPageChanged();
            }

        private:
            class Imp;
            QScopedPointer<Imp> imp;

        };
    }
}

#endif // BOOKCONTROLLER_H

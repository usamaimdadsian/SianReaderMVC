#include "book_controller.h"
#include <QDebug>

namespace sianreader{
    namespace controllers{
        class BookController::Imp{
        public:
            BookController* bookController{nullptr};
            QUrl* pdf_source{nullptr};
            QObject* doc{nullptr};
            QObject* doc_view{nullptr};
            Imp(BookController* _bookController):bookController(_bookController)
            {

            }
        };
        BookController::BookController(QObject *parent)
        : QObject(parent)
        {
            imp.reset(new Imp(this));
        }
        BookController::~BookController()
        {

        }

        void BookController::setPdfBook(QUrl* pdf_url)
        {
            imp->pdf_source = pdf_url;
            emit pdfChanged();
        }

        const QUrl& BookController::currentPdf() const{
            return *imp->pdf_source;
        }

        void BookController::setPdfDocument(QObject* doc, QObject* doc_view){
            imp->doc = doc;
            imp->doc_view = doc_view;
        }

        const QString BookController::totalPageCount() const
        {
            return imp->doc->property("pageCount").toString();
        }

        const QString BookController::currentPage() const
        {
            return QString::number(imp->doc_view->property("currentPage").toInt()+1);
        }
    }
}

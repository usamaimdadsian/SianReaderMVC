#ifndef PDFBOOK_H
#define PDFBOOK_H

#include <QObject>
#include <data/entity.h>

#include <data/int_decorator.h>

namespace sianreader {
    namespace models{
        enum LayoutType{

        };
        class PdfBook: public data::Entity
        {
            Q_OBJECT
            Q_PROPERTY(data::IntDecorator* ui_last_page  MEMBER last_page CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_finger_print MEMBER finger_print CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_location MEMBER location CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_scroll_height MEMBER scroll_height CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_zoom MEMBER zoom CONSTANT)

        protected:
            QString getFingerprint(const QString& pdfFilePath);

        public:
            explicit PdfBook(QObject *parent = nullptr);
            PdfBook(QObject *parent, const QJsonObject& json);



            data::IntDecorator* last_page{nullptr};
            data::StringDecorator* finger_print{nullptr};
            data::StringDecorator* location{nullptr};
            data::IntDecorator* scroll_height{nullptr};
            data::IntDecorator* zoom{nullptr};

        };
    }
}

#endif // PDFBOOK_H

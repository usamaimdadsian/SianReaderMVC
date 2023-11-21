#ifndef BOOK_H
#define BOOK_H

#include <QObject>

#include <data/string_decorator.h>
#include <data/entity.h>
#include <data/enumerator_decorator.h>
#include "pdfbook.h"
#include "audiobook.h"

namespace sianreader {
    namespace models{
        enum BookType
        {
            UNKNOWN = 0,
            PDF,
            AUDIO
        };

        class Book : public data::Entity
        {
            Q_OBJECT
            Q_PROPERTY(data::StringDecorator* ui_id MEMBER id CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_title MEMBER title CONSTANT)
//            Q_PROPERTY(data::EnumeratorDecorator* ui_file_type MEMBER file_type CONSTANT)
            Q_PROPERTY(PdfBook* ui_pdf_book MEMBER pdf_book CONSTANT)
            Q_PROPERTY(AudioBook* ui_audio_book MEMBER audio_book CONSTANT)

        public:
            explicit Book(QObject *parent = nullptr);
            Book(QObject *parent, const QJsonObject& json);

            data::StringDecorator* id{nullptr};
            data::StringDecorator* title{nullptr};
//            data::EnumeratorDecorator* file_type{nullptr};
            PdfBook* pdf_book{nullptr};
            AudioBook* audio_book{nullptr};


            static std::map<int,QString> bookTypeMapper;

        };
    }
}
#endif // BOOK_H

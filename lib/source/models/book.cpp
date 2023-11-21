#include "book.h"

using namespace sianreader::data;

namespace sianreader {
    namespace models {
        std::map<int, QString> Book::bookTypeMapper = std::map<int,QString>{
            {BookType::UNKNOWN,""},
            {BookType::PDF,"PDF"},
            {BookType::AUDIO,"AUDIO"}
        };

        Book::Book(QObject *parent)
            : Entity{parent,"book"}
        {
            id = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"id","ID")));
            title = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"title","Title")));
//            file_type = static_cast<EnumeratorDecorator*>(addDataItem(new EnumeratorDecorator(this,"file_type","File Type pdf/audio",0,bookTypeMapper)));
            pdf_book = static_cast<PdfBook*>(addChild(new PdfBook(this),"pdf_book"));
            audio_book = static_cast<AudioBook*>(addChild(new AudioBook(this),"audio_book"));
            setPrimaryKey(id);
        }

        Book::Book(QObject *parent, const QJsonObject& json): Book(parent)
        {
            update(json);
        }
    }
}

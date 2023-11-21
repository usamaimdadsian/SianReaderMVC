#include "pdfbook.h"

#include <QFile>
//#include <cryptopp/sha.h>
//#include <cryptopp/hex.h>
#include <fstream>

using namespace sianreader::data;

namespace sianreader{
    namespace models{
        PdfBook::PdfBook(QObject* parent): Entity(parent,"pdfbook")
        {
            last_page = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"last_page","Last Page")));
            finger_print = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"finger_print","Finger Print")));
            location = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"location","Location")));
            scroll_height = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"scroll_height","Scroll Height")));
            zoom = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"zoom","Zoom")));
        }

        PdfBook::PdfBook(QObject* parent, const QJsonObject& json)
            : PdfBook(parent)
        {
            update(json);
        }

//        QString PdfBook::getFingerprint(const QString& pdfFilePath) {
//            CryptoPP::SHA256 sha256;

//            std::ifstream file(pdfFilePath.toStdString(), std::ios::binary);
//            if (!file) {
//                return "";
//            }

//            CryptoPP::byte buffer[1024];
//            while (file.good()) {
//                file.read(reinterpret_cast<char*>(buffer), sizeof(buffer));
//                sha256.Update(buffer, static_cast<size_t>(file.gcount()));
//            }

//            CryptoPP::byte digest[CryptoPP::SHA256::DIGESTSIZE];
//            sha256.Final(digest);

//            std::string hexDigest;
//            CryptoPP::HexEncoder encoder(new CryptoPP::StringSink(hexDigest));
//            encoder.Put(digest, sizeof(digest));
//            encoder.MessageEnd();

//            return QString::fromStdString(hexDigest);
//        }
    }
}

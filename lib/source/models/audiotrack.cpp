#include "audiotrack.h"
using namespace sianreader::data;

namespace sianreader {
    namespace models {
        AudioTrack::AudioTrack(QObject *parent)
        : Entity(parent,"audiotrack")
        {
            audio_book_id = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"audio_book_id","Audio Book Id")));
            order = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"order","Track Order")));
            location = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"location","Path of the file")));
            duration = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"duration","Duration")));
        }

        AudioTrack::AudioTrack(QObject *parent, const QJsonObject& json):AudioTrack(parent)
        {
            update(json);
        }
    }
}

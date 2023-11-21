#include "audiobook.h"
#include <data/string_decorator.h>
#include <controllers/database_controller.h>
#include <QtQml/QQmlListProperty>

using namespace sianreader::data;


namespace sianreader {
    namespace models{
        AudioBook::AudioBook(QObject *parent)
            : Entity{parent,"audiobook"}
        {

            total_time = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"total_time","Total Time")));
            dir_location = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"dir_location","Directory Location")));
            playback_speed = static_cast<FloatDecorator*>(addDataItem(new FloatDecorator(this,"playback_speed","Playback Speed")));
            volume = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"volume","Volume")));
            last_track_id = static_cast<StringDecorator*>(addDataItem(new StringDecorator(this,"last_track_id","ID of last playing Audio Track ")));
            time_played = static_cast<IntDecorator*>(addDataItem(new IntDecorator(this,"time_played","Time Played for the last track")));
            audio_tracks = static_cast<EntityCollection<AudioTrack>*>(addChildCollection(new EntityCollection<AudioTrack>(this,"audio_tracks")));

        }

        AudioBook::AudioBook(QObject *parent, const QJsonObject& json): AudioBook(parent)
        {
            update(json);
        }

        QQmlListProperty<AudioTrack> AudioBook::ui_audio_tracks(){
            return QQmlListProperty<AudioTrack>(this,&audio_tracks->derivedEntities());
        }
    }
}

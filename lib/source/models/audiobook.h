#ifndef AUDIOBOOK_H
#define AUDIOBOOK_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <data/entity.h>
#include <data/int_decorator.h>
#include <data/float_decorator.h>
#include "audiotrack.h"

namespace sianreader {
    namespace models{
        class AudioBook : public data::Entity
        {
            Q_OBJECT
            Q_PROPERTY(data::IntDecorator* ui_total_time MEMBER total_time CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_dir_location MEMBER dir_location CONSTANT)
            Q_PROPERTY(data::FloatDecorator* ui_playback_speed MEMBER playback_speed CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_volume MEMBER volume CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_last_track_id MEMBER last_track_id CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_time_played MEMBER time_played CONSTANT)
            Q_PROPERTY(QQmlListProperty<AudioTrack> ui_audio_tracks READ ui_audio_tracks NOTIFY audioTrackChanged)
        public:
            explicit AudioBook(QObject *parent = nullptr);
            AudioBook(QObject *parent, const QJsonObject& json);

            data::IntDecorator* total_time{nullptr};
            data::StringDecorator* dir_location{nullptr};
            data::FloatDecorator* playback_speed{nullptr};
            data::IntDecorator* volume{nullptr};
            data::StringDecorator* last_track_id{nullptr};
            data::IntDecorator* time_played{nullptr};
            data::EntityCollection<AudioTrack>* audio_tracks{nullptr} ;

            QQmlListProperty<AudioTrack> ui_audio_tracks();

        signals:
            void audioTrackChanged();

        };
    }
}

#endif // AUDIOBOOK_H

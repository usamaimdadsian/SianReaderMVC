#ifndef AUDIOTRACK_H
#define AUDIOTRACK_H

#include <QObject>
#include <data/entity.h>
#include <data/string_decorator.h>
#include <data/int_decorator.h>

namespace sianreader {
    namespace models{
        class AudioTrack : public data::Entity
        {
            Q_OBJECT
            Q_PROPERTY(data::StringDecorator* ui_audio_book_id MEMBER audio_book_id CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_order MEMBER order CONSTANT)
            Q_PROPERTY(data::StringDecorator* ui_location MEMBER location CONSTANT)
            Q_PROPERTY(data::IntDecorator* ui_duration MEMBER duration CONSTANT)
        public:
            explicit AudioTrack(QObject *parent = nullptr);
            AudioTrack(QObject *parent, const QJsonObject& json);

            data::StringDecorator* audio_book_id{nullptr};
            data::IntDecorator* order{nullptr};
            data::StringDecorator* location{nullptr};
            data::IntDecorator* duration{nullptr};

        signals:

        };

    }
}

#endif // AUDIOTRACK_H

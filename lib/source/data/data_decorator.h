#ifndef DATADECORATOR_H
#define DATADECORATOR_H

#include <QObject>
#include <lib_global.h>

namespace sianreader{
    namespace data{
        class Entity;
        class LIB_EXPORT DataDecorator : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(QString ui_label READ label CONSTANT)
        public:
            DataDecorator(Entity *parent = nullptr, const QString& key="someItemKey", const QString& label="");
            virtual ~DataDecorator();

            const QString& key() const;
            const QString& label() const;
            Entity* parentEntity();

            virtual QJsonValue jsonValue() const = 0;
            virtual void update(const QJsonObject& QJsonObject) = 0;

        private:
            class Implementation;
            QScopedPointer<Implementation> implementation;

        };
    }
}


#endif // DATADECORATOR_H

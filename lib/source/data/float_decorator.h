#ifndef FLOATDECORATOR_H
#define FLOATDECORATOR_H

#include <QObject>
#include <lib_global.h>
#include <data/data_decorator.h>

namespace sianreader {
    namespace data {
        class LIB_EXPORT FloatDecorator : public DataDecorator
        {
            Q_OBJECT
            Q_PROPERTY( float ui_value READ value WRITE setValue NOTIFY valueChanged )

        public:
            FloatDecorator(Entity* parentEntity = nullptr, const QString& key = "SomeItemKey", const QString& label = "", float value = 0);
            ~FloatDecorator();

            FloatDecorator& setValue(float value);
            float value() const;

        public:
            QJsonValue jsonValue() const override;
            void update(const QJsonObject& jsonObject) override;

        signals:
            void valueChanged();

        private:
            class Implementation;
            QScopedPointer<Implementation> implementation;


        };
    }
}

#endif // FLOATDECORATOR_H

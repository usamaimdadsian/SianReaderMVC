#include "float_decorator.h"

#include <QVariant>
#include <QJsonValue>
#include <QJsonObject>

namespace sianreader {
namespace data {

class FloatDecorator::Implementation
{
public:
    Implementation(FloatDecorator* _floatDecorator, float value)
        : floatDecorator(_floatDecorator)
        , value(value)
    {
    }

    FloatDecorator* floatDecorator{nullptr};
    float value;
};

FloatDecorator::FloatDecorator(Entity* parentEntity, const QString& key, const QString& label, float value)
    : DataDecorator(parentEntity, key, label)
{
    implementation.reset(new Implementation(this, value));
}

FloatDecorator::~FloatDecorator()
{
}

float FloatDecorator::value() const
{
    return implementation->value;
}

FloatDecorator& FloatDecorator::setValue(float value)
{
    if(value != implementation->value) {
        // ...Validation here if required...
        implementation->value = value;
        emit valueChanged();
    }

    return *this;
}

QJsonValue FloatDecorator::jsonValue() const
{
    return QJsonValue::fromVariant(QVariant(implementation->value));
}

void FloatDecorator::update(const QJsonObject& jsonObject)
{
    if (jsonObject.contains(key())) {
        auto l_value = jsonObject.value(key()).toDouble();
        setValue(l_value);
    } else {
        setValue(0);
    }
}

}}

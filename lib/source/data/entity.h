#ifndef ENTITY_H
#define ENTITY_H

#include <map>

#include <QObject>
#include <QScopedPointer>

#include <lib_global.h>
#include <data/data_decorator.h>
#include <data/string_decorator.h>
#include <data/entity_collection.h>

namespace sianreader {
namespace data {

class LIB_EXPORT Entity : public QObject
{
    Q_OBJECT

public:
    Entity(QObject* parent = nullptr, const QString& key = "SomeEntityKey");
    Entity(QObject* parent, const QString& key, const QJsonObject& jsonObject);
    virtual ~Entity();

public:
    const QString& id() const;
    const QString& key() const;
    void setPrimaryKey(StringDecorator* primaryKey);
    void update(const QJsonObject& jsonObject);
    QJsonObject toJson() const;

signals:
    void childCollectionsChanged(const QString& collectionKey);
    void childEntitiesChanged();
    void dataDecoratorsChanged();

protected:
    Entity* addChild(Entity* entity, const QString& key);
    EntityCollectionBase* addChildCollection(EntityCollectionBase* entityCollection);
    DataDecorator* addDataItem(DataDecorator* dataDecorator);

protected:
    class Implementation;
    QScopedPointer<Implementation> implementation;
};

}}

#endif

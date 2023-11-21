#ifndef MASTERCONTROLLER_H
#define MASTERCONTROLLER_H

#include <QObject>
#include <QString>
#include <lib_global.h>

#include "navigation_controller.h"
#include "command_controller.h"
#include "book_controller.h"

namespace sianreader
{
    namespace controllers
    {

        class ViewType : public QObject
        {
            Q_OBJECT
        public:
            enum MyEnum {
                UNKNOWN = 0,
                HOME,
                CONTENT,
                SPLASH
            };
            Q_ENUM(MyEnum)
        };

        class MasterController : public QObject
        {
            Q_OBJECT
            Q_PROPERTY( QString ui_welcomeMessage READ welcomeMessage CONSTANT )
            Q_PROPERTY(sianreader::controllers::NavigationController *ui_navigationController READ navigationController CONSTANT)
            Q_PROPERTY(sianreader::controllers::CommandController* ui_commandController READ commandController CONSTANT )
            Q_PROPERTY(sianreader::controllers::BookController* ui_bookController READ bookController CONSTANT )
            Q_PROPERTY(int currentViewType READ currentViewType CONSTANT)
        public:
            explicit MasterController(QObject *parent = nullptr);
            ~MasterController();

            CommandController* commandController();
            NavigationController* navigationController();
            BookController* bookController();
            const int& currentViewType() const;

            const QString& welcomeMessage() const;
        signals:
            void viewChanged();

        public slots:
            void setView(int view);

        private:
            class Implementation;
            QScopedPointer<Implementation> implementation;
        };
    }
}

#endif // MASTERCONTROLLER_H

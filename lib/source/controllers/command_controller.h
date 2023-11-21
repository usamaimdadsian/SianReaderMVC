#ifndef COMMAND_CONTROLLER_H
#define COMMAND_CONTROLLER_H

#include <QObject>
#include <QtQml/QQmlListProperty>
#include <lib_global.h>
#include <framework/command.h>

namespace sianreader {
    namespace controllers {
        class CommandController : public QObject
        {
            Q_OBJECT
            Q_PROPERTY(QQmlListProperty<sianreader::framework::Command> ui_createClientViewContextCommands READ createClientViewContextCommands CONSTANT)
        public:
            explicit CommandController(QObject* _parent = nullptr);
            ~CommandController();

            QQmlListProperty<sianreader::framework::Command> createClientViewContextCommands();

        public slots:
            void onCreateClientSaveExecuted();

        private:
            class Implementation;
            QScopedPointer<Implementation> implementation;

        };
    }
}

#endif // COMMAND_CONTROLLER_H

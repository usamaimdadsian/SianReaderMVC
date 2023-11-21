#include <QtQml/QQmlListProperty>

#include "command_controller.h"
using namespace sianreader::framework;

namespace sianreader{
    namespace controllers{
        class CommandController::Implementation{
        public:
            CommandController* commandController{nullptr};
            QList<Command*> createClientViewContextCommands{};

            Implementation(CommandController* _commandController)
                : commandController(_commandController)
            {
                Command* createClientSaveCommand = new Command( commandController, QChar( 0xf0c7 ), "Save" );
                QObject::connect( createClientSaveCommand, &Command::executed, commandController, &CommandController::onCreateClientSaveExecuted );
                createClientViewContextCommands.append( createClientSaveCommand );
            }


        };

        CommandController::CommandController(QObject* parent)
            : QObject(parent)
        {
            implementation.reset(new Implementation(this));
        }

        CommandController::~CommandController()
        {
        }

        QQmlListProperty<Command> CommandController::createClientViewContextCommands()
        {
            return QQmlListProperty<Command>(this, &implementation->createClientViewContextCommands);
        }

        void CommandController::onCreateClientSaveExecuted()
        {
            qDebug() << "You executed the Save command!";
        }
    }
}

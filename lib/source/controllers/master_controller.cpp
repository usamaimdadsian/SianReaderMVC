#include "master_controller.h"

namespace sianreader
{
    namespace controllers
    {
        class MasterController::Implementation{
        public:
            Implementation(MasterController *_masterController): masterController(_masterController)
            {
                commandController = new CommandController(masterController);
                navigationController = new NavigationController(masterController);
                bookController = new BookController(masterController);
                current_view = ViewType::UNKNOWN;
            }
            CommandController* commandController{nullptr};
            MasterController* masterController{nullptr};
            NavigationController* navigationController{nullptr};
            BookController* bookController{nullptr};
            QString welcomeMessage = "This is MasterController to Major Tom";
            int current_view;
        };

        MasterController::MasterController(QObject *parent)
            : QObject{parent}
        {
            implementation.reset(new Implementation(this));
        }

        MasterController::~MasterController()
        {
        }


        CommandController* MasterController::commandController()
        {
            return implementation->commandController;
        }

        NavigationController* MasterController::navigationController()
        {
            return implementation->navigationController;
        }

        BookController* MasterController::bookController()
        {
            return implementation->bookController;
        }


        const QString& MasterController::welcomeMessage() const
        {
            return implementation->welcomeMessage;
        }


        const int& MasterController::currentViewType() const
        {
            return implementation->current_view;
        }

        void MasterController::setView(int view){
            implementation->current_view = view;
            qInfo() << "Inside controller's set view" << view;
            emit viewChanged();
        }
    }
}

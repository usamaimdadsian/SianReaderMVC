#ifndef NAVIGATION_CONTROLLER_H
#define NAVIGATION_CONTROLLER_H

#include <QObject>
#include <lib_global.h>

namespace sianreader {
    namespace controllers {
        class LIB_EXPORT NavigationController : public QObject
        {
            Q_OBJECT
        public:
            explicit NavigationController(QObject* _parent = nullptr)
                : QObject(_parent)
            {}
        signals:
            void goHomeView();
            void goSplashView();
            void goContentView();
            //            void goEditClientView(sianreader::models::Client* client);
            //            void goFindClientView();

        public slots:
            void triggerHomeView(){
                emit goHomeView();
            }
            void triggerSplashView(){
                emit goSplashView();
            }
            void triggerContentView(){
                emit goContentView();
            }
        };
    }
}


#endif // NAVIGATION_CONTROLLER_H

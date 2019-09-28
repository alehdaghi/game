//
// Created by mahdi on 28.09.19.
//

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <mutex>
namespace Game {
    namespace Utility {
        template<class T>
        class ISingleton {
        protected:
            static T *instance;
            static std::mutex createInstanceMutex;

            ISingleton();

            ~ISingleton() = default;

        public:
            ISingleton(ISingleton &&) = delete;

            ISingleton(const ISingleton &) = delete;

            static T &getInstance();

            static T *getInstancePointer();

            static void releaseInstance();
        };

        template<class T>
        ISingleton<T>::ISingleton() {
            instance = nullptr;
        }

        template<class T>
        T &ISingleton<T>::getInstance() {
            createInstanceMutex.lock();
            if (instance == nullptr) {
                instance = new T();
            }
            createInstanceMutex.unlock();
            return *instance;
        }

        template<class T>
        T *ISingleton<T>::getInstancePointer() {
            createInstanceMutex.lock();
            if (instance == nullptr) {
                instance = new T();
            }
            createInstanceMutex.unlock();
            return instance;
        }

        template<class T>
        void ISingleton<T>::releaseInstance() {
            if (instance != nullptr) {
                delete instance;
                instance = nullptr;
            }
        }

        template<class T> T *ISingleton<T>::instance = nullptr;
        template<class T> std::mutex ISingleton<T>::createInstanceMutex;
    }
}
#endif // SINGLETON_HPP

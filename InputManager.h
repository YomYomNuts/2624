#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "vec2.h"

#include <string>
#include <map>
#include <SDL.h>

using namespace std;

class InputManager
{
    public:
        InputManager();
        virtual ~InputManager();
        static InputManager* Instance()
        {
            if (InputManager::m_instance == nullptr)
            {
                InputManager::m_instance = new InputManager();
            }
            return InputManager::m_instance;
        }

        void update();
        bool keyPress(string _key) { return keys[_key]; }

        vec2f getMousePosition() { return mouse; }
        vec2f getMouseDeltaPosition() { return mouseDelta; }

    protected:

    private:
        static InputManager* m_instance;
        map<string, bool> keys;
        vec2f mouse, mouseDelta;
};

#endif // INPUTMANAGER_H

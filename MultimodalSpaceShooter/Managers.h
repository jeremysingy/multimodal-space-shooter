#ifndef MANAGERS_H
#define MANAGERS_H

#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "EventManager.h"
#include "SceneManager.h"

GraphicsEngine& graphicsEngine();
PhysicsEngine& physicsEngine();
EventManager& eventManager();
SceneManager& sceneManager();

#endif // MANAGERS_H
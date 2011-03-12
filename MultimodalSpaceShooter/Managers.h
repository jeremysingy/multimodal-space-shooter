#ifndef MANAGERS_H
#define MANAGERS_H

#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "EventManager.h"
#include "SceneManager.h"
#include "ImageManager.h"

GraphicsEngine& graphicsEngine();
PhysicsEngine& physicsEngine();
EventManager& eventManager();
SceneManager& sceneManager();
ImageManager& imageManager();

#endif // MANAGERS_H
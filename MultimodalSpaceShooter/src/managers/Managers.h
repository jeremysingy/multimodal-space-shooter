#ifndef MANAGERS_H
#define MANAGERS_H

#include "managers/GraphicsEngine.h"
#include "managers/PhysicsEngine.h"
#include "managers/AudioEngine.h"
#include "managers/EventManager.h"
#include "managers/MultimodalManager.h"
#include "managers/SceneManager.h"
#include "managers/EntityManager.h"
#include "loaders/ImageManager.h"
#include "loaders/SoundManager.h"
#include "loaders/LevelManager.h"

GraphicsEngine& graphicsEngine();
PhysicsEngine& physicsEngine();
AudioEngine& audioEngine();
EventManager& eventManager();
MultimodalManager& multimodalManager();
SceneManager& sceneManager();
EntityManager& entityManager();
ImageManager& imageManager();
SoundManager& soundManager();
LevelManager& levelManager();

#endif // MANAGERS_H
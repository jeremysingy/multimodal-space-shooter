#ifndef MANAGERS_H
#define MANAGERS_H

#include "GraphicsEngine.h"
#include "PhysicsEngine.h"
#include "AudioEngine.h"
#include "EventManager.h"
#include "MultimodalManager.h"
#include "SceneManager.h"
#include "ImageManager.h"
#include "SoundManager.h"

GraphicsEngine& graphicsEngine();
PhysicsEngine& physicsEngine();
AudioEngine& audioEngine();
EventManager& eventManager();
MultimodalManager& multimodalManager();
SceneManager& sceneManager();
ImageManager& imageManager();
SoundManager& soundManager();

#endif // MANAGERS_H
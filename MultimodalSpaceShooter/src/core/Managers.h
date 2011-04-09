#ifndef MANAGERS_H
#define MANAGERS_H

#include "core/AudioEngine.h"
#include "input/EventManager.h"
#include "input/MultimodalManager.h"
#include "entities/EntityManager.h"
#include "loaders/ImageManager.h"
#include "loaders/SoundManager.h"

//////////////////////////////////////////////////
/// Allow simple access to global managers to simplify
/// dependencies between objects
///
/// Handled a better way than with singletons
/// (the life of these objects is managed by the Game class)
//////////////////////////////////////////////////

AudioEngine& audioEngine();
EventManager& eventManager();
MultimodalManager& multimodalManager();
EntityManager& entityManager();

ImageManager& imageManager();
SoundManager& soundManager();

#endif // MANAGERS_H
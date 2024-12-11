#include "bullet_utils.h"
#include <stdexcept>

using namespace std;

// Function to initialize Bullet Physics
// Returns a pointer to a BulletPhysics structure with initialized components
BulletPhysics *initializeBullet()
{
  BulletPhysics *bulletPhysics = nullptr;

  try
  {
    // Create main BulletPhysics object
    bulletPhysics = new BulletPhysics();

    // Initialize collision configuration with error checking
    if (!(bulletPhysics->collisionConfiguration = new btDefaultCollisionConfiguration()))
    {
      throw runtime_error("Failed to create collision configuration");
    }

    // Initialize dispatcher with error checking
    if (!(bulletPhysics->dispatcher = new btCollisionDispatcher(bulletPhysics->collisionConfiguration)))
    {
      throw runtime_error("Failed to create dispatcher");
    }

    // Initialize broadphase interface with error checking
    if (!(bulletPhysics->overlappingPairCache = new btDbvtBroadphase()))
    {
      throw runtime_error("Failed to create broadphase");
    }

    // Initialize constraint solver with error checking
    if (!(bulletPhysics->solver = new btSequentialImpulseConstraintSolver()))
    {
      throw runtime_error("Failed to create solver");
    }

    // Initialize dynamics world with error checking
    if (!(bulletPhysics->dynamicsWorld = new btDiscreteDynamicsWorld(
              bulletPhysics->dispatcher,
              bulletPhysics->overlappingPairCache,
              bulletPhysics->solver,
              bulletPhysics->collisionConfiguration)))
    {
      throw runtime_error("Failed to create dynamics world");
    }

    // Set gravity for the dynamics world
    bulletPhysics->dynamicsWorld->setGravity(btVector3(0, -9.81, 0));

    // Return the initialized BulletPhysics structure
    return bulletPhysics;
  }
  catch (const exception &e)
  {
    // Clean up in case of an error
    cleanupBullet(bulletPhysics);
    return nullptr;
  }
}

// Function to clean up Bullet Physics objects
// Takes a pointer to a BulletPhysics structure and deallocates its components
void cleanupBullet(BulletPhysics *bulletPhysics)
{
  if (!bulletPhysics)
    return;

  // Delete dynamics world if it exists
  if (bulletPhysics->dynamicsWorld)
  {
    delete bulletPhysics->dynamicsWorld;
    bulletPhysics->dynamicsWorld = nullptr;
  }

  // Delete solver if it exists
  if (bulletPhysics->solver)
  {
    delete bulletPhysics->solver;
    bulletPhysics->solver = nullptr;
  }

  // Delete broadphase interface if it exists
  if (bulletPhysics->overlappingPairCache)
  {
    delete bulletPhysics->overlappingPairCache;
    bulletPhysics->overlappingPairCache = nullptr;
  }

  // Delete dispatcher if it exists
  if (bulletPhysics->dispatcher)
  {
    delete bulletPhysics->dispatcher;
    bulletPhysics->dispatcher = nullptr;
  }

  // Delete collision configuration if it exists
  if (bulletPhysics->collisionConfiguration)
  {
    delete bulletPhysics->collisionConfiguration;
    bulletPhysics->collisionConfiguration = nullptr;
  }

  // Delete the main BulletPhysics object
  delete bulletPhysics;
}
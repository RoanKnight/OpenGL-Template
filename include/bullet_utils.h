#ifndef BULLET_UTILS_H
#define BULLET_UTILS_H

#include <btBulletDynamicsCommon.h>

// Structure to hold Bullet Physics objects
struct BulletPhysics
{
  btDefaultCollisionConfiguration *collisionConfiguration; // Configuration for collision detection
  btCollisionDispatcher *dispatcher;                       // Manages collision detection
  btBroadphaseInterface *overlappingPairCache;             // Broadphase collision detection
  btSequentialImpulseConstraintSolver *solver;             // Solves constraints and calculates forces
  btDiscreteDynamicsWorld *dynamicsWorld;                  // The main physics simulation world
};

// Initialize Bullet Physics
BulletPhysics *initializeBullet();

// Clean up Bullet Physics objects
void cleanupBullet(BulletPhysics *bulletPhysics);

#endif
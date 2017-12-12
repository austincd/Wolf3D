# Wolf3D
C implementation of a basic raycaster in the fashion of Wolfenstein 3D. Uses the MLX/miniLibX library.

Contains a basic two dimensional physics system. Every moveable object in the level contains a typedef t_3di.

t_3di contains a number of double precision floats to keep track of an object's mass and volume, and all the
data specifying its position and orientation in the environment. Each tick or update of the game state will
update the position of each object in the environment by taking into account their current movement path and
velocity, and their given mass is used to determine how quickly their velocity decays. When a character in
the environment moves, their object is just given some velocity in a particular direction as long as they
are moving, kind of like hitting something with some physical force. From there, once the force is no longer
being activated, the object will still move around the 3D environment until it slows and comes to a complete
stop, with higher mass objects coming to a stop more quickly.

t_3di also contains a function pointer, which is used to evaluate collisions between objects in the environment.
each tick of the game updates the position of all 3D objects in the scene as per the physics system, and after
that, the system checks the location and volume of each t_3di object, trying to see if any intersect. If two
objects now intersect, or have collided, a function inside each object will be called, so that different t_3di
instances can have completely different effects upon collision with the same object. For the purpose of providing
an explicit and modifiable order to the evaluation of each object's collision hook, we also have a char inside
each t_3di instance by the name of "priority". This char can have any one byte value, and when two objects collide,
the t_3di instance with the higher priority value has its hook processed first.

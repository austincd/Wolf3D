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

DIRECTIONS(SPATIAL ONES):

Each object has one floating point number per axis to record its position, and one floating point number per
axis to show orientation. Wolf3D might make this less clear, on account of trying to provide the illusion of
3D visuals while only keeping track of 2 axes, but the relationship still holds.

Let's assume that we have some geometric space, where the space extends N number of units along each axis.
Every coordinate in that space can have a value between 0 and N, inclusive. Zero is the lower bound of each
coordinate, and N is the upper bound.

The floats that represent spatial orientation also have lower and upper bounds, but of -1 and 1, respectively.
When moving a given distance, the direction is represented as a number of factors that we can use to determine
how our position on each axis changes.


let's assume that dirX(Direction X) = 0.00;


This means that based on our current orientation, any movement forward(according to our perspective) will
result in no change to X. We can assume that forward and backward movement now will move us along the Y axis.
The inverse is true for a dirY(Direction Y) value of zero.

let's assume that dirX(Direction X) < 0.00;


If our 'dir' for a given axis is negative, then any movement forward(once again, from our perspective) will
result in a decrease in our position along the X axis.

let's assume that dirY(Direction Y) > 0.00;


If our 'dir' for the Y axis is positive, then any movement forward will result in Y increasing. Movement
in Wolf3D operates off of two of these floating point directional values, dirX and dirY. Whenever we move
a given distance, D, we take that distance, and multiply it by dirX for the change that movement brings to
our location on the X axis. Similarly, we multiply the same distance by dirY for the change that movement
will bring to our position on the Y axis.

Each Tick:

{

	new posX = (old posX + (distance * dirX));
	
	new posY = (old posY + (distance * dirY));
}

GLOSSARY:

rotVelo:

Short for Rotational Velocity. Rotating objects in this Wolf3D works similarly to translating them.
Each tick, the rotational velocity of a t_3di object is spent turning the object left or right depending
on whether the rotVelo value is negative or positive, respectively.

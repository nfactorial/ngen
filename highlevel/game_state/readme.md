About
=====
This library is currently still in development and is not ready for use. The library is a part of a bigger project
which forms a 3D game engine. Intended for use as a research and practice bed of code.

Overview
========
This library provides an implementation of a data driven game state system. The game state hierarchy is
formed from a tree, where each node is a single game state. A simple state hierarchy may look like:

    - Core System
        - MainMenu
            - Title Screen
            - Options
        - SinglePlayer
            - Playing
            - Paused
            - GameOver

Given this structure we can define a particular state from a name. Each state name must be unique within
the hierarchy, so their name uniquely identifies them

We also impose a limitation that the 'active' state can only be a leaf node (ie. a state that has no
children). This current architecture provides little to a running title, as there is no processing
involved. To provide this capability we define a game system interface which has two methods:

struct IGameSystem
{
    virtual void onInitialize( InitArgs &initArgs ) = 0;
    virtual void onShutdown() = 0;
};

A game system object must implement this interface and register itself with a factory. During the
registration process the object also associates itself with a name. Given that we now have a
collection of creatable game systems, we can now extend our game state definition to include a
list of game systems that must each exist within them. Let us define a very simple state tree for
explanation purposes and include some associated game systems. Game system names will be contained
within parenthesis to help them differ from state names.

    - Core System
        (Renderer)
        - MainMenu
            (MenuHandler)
        - SinglePlayer
            (GameEngine)
        - Multiplayer
            (GameEngine)

When the state tree is created, each game system associated with its states are also created and
stored. As a state becomes active within the title, the onInitialize method of its associated
systems are invoked. All systems within its parent hierarchy also have their initialize method
invoked, this method is invoked in-order from root to child.

Given the previous state definition, we switch to the MainMenu state. As this state is activated
the framework invokes the onInitialize method of (Renderer) then (MenuHandler).

If the active state is then changed to SinglePlayer the onShutdown method is invoked on the
(MenuHandler) system. The (Renderer) object is not touched, as its state remains active. The
system then invokes the onInitialize method of the (GameEngine) system object.

As the title progresses through its natural execution pipeline, systems will have their
onInitialize and onShutdown methods invoked multiple times. When the application terminates
even the (Renderer) object will have its onShutdown method invoked as the state system is
torn down.

Multiple Instances of Systems
=============================
Sometimes it may be required to have multiple instances of a system object within a single
hierarchy. In the previous example there were two instances of the (GameEngine) system object,
however in this case they existed in different hierarchies of the state tree and thus there
was no conflict.

To combat this, we extend the state tree definition further so that system objects are also
associated with a name identifier.

System Definition
=================
System objects are more than simple clases, they may need data supplied to them or to
interact with other system objects.
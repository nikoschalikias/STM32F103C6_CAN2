/*
 * FSM.h
 *
 *  Created on: Apr 11, 2011
 *      Author: n
 */

/*
 * NX: from-->http://www.netrino.com/node/238
 * State Machines in C and C++
 *
 * Incidentally, the smallest, fastest, and arguably the most natural technique for implementing state machines in C/C++ isn't widely publicized
 * (although I suspect it's in every pro's bag of tricks). The technique hinges on pointers-to-functions in C
 * (and pointers-to-member-functions in C++). Pointers-to-functions are obviously heavily used in other standard techniques
 * (e.g., state tables typically store such pointers). However, the technique I mention here represents the very concept of "state"
 * directly as a pointer-to-function. Please take note, the "state" isn't enumerated; it's not an instance of
 * a State class—it is a pointer to a state-handler function, as declared in line 4 of Listing 1.
 *
 * The other FSM elements in this implementation include: the Event base class for derivation of events
 * with parameters (Listing 1, lines 7-10)
 * and the Fsm base class for derivation of state machine objects (lines 13-22).
 * (The sidebar "Object-Oriented Programming (OOP) in C" explains techniques used to code classes and inheritance in C.)
 *
 * The Fsm class stores the current state in its attribute state__ and provides four methods ("inlined" by means of macros).
 * The constructor FsmCtor_ (Listing 1, line 19) initializes the current state,
 * the method FsmInit() (line 20) triggers the initial transition,
 * the method FsmDispatch() (line 21) dispatches events to the state machine,
 * and finally the method FsmTran_() (line 22) takes a state transition.
 *
 */

//
//typedef short Signal;
//typedef struct Event Event;
//typedef struct Fsm Fsm;
//typedef void (*State)(Fsm *, Event const *);
//
// /* Event base class */
// struct Event
// {
//    Signal sig;
// };
//
// /* Finite State Machine base class */
// struct Fsm
// {
//    State state__; /* the current state */
// };
//
// /* "inlined" methods of Fsm class */
// #define FsmCtor_(me_, init_) ((me_)->state__ = (State)(init_))
// #define FsmInit(me_, e_)     (*(me_)->state__)((me_), (e_))
// #define FsmDispatch(me_, e_) (*(me_)->state__)((me_), (e_))
// #define FsmTran_(me_, targ_) ((me_)->state__ = (State)(targ_))

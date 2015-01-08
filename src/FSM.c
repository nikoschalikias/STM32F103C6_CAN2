/*
 * FSM.c
 *
 *  Created on: Apr 11, 2011
 *      Author: n
 */


/*
 * NX: from-->http://www.netrino.com/node/238
 * Listing 2 shows an example of using the technique to implement the Keyboard FSM from Figure 2.
 * Lines 3-13 declare the Keyboard FSM as a subclass of Fsm. (Please note the member super_ in line 6.)
 * Similarly, the keyboard-specific event KeyboardEvt is derived from Event in Listing 2, lines 16-20.
 * The event types must be enumerated (lines 23-28), but the states aren't: they are referenced by the names of state-handler methods.
 * The Keyboard FSM has two such state-handlers (Keyboard_default() and Keyboard_shifted(),
 * declared in lines 12 and 13 of Listing 2, respectively).
 * The Keyboard_initial() method (declared in line 11 and defined in lines 35-40) implements the initial transition.
 */

// #include "FSM.h"
//
// typedef struct Keyboard Keyboard;
//struct Keyboard
//{
//    Fsm super_; /* extend the Fsm class */
//    /* ... other attributes of Keyboard */
// };
//
// void KeyboardCtor(Keyboard *me);
// void Keyboard_initial(Keyboard *me, Event const *e);
// void Keyboard_default(Keyboard *me, Event const *e);
// void Keyboard_shifted(Keyboard *me, Event const *e);
//
// typedef struct KeyboardEvt KeyboardEvt;
// struct KeyboardEvt
// {
//    Event super_; /* extend the Event class */
//    char code;
// };
//
// /* signals used by the Keyboard FSM */
// enum
// {
//    SHIFT_DEPRESSED_SIG,
//    SHIFT_RELEASED_SIG,
//    ANY_KEY_SIG,
// };
//
// void KeyboardCtor(Keyboard *me)
// {
//    FsmCtor_(&me->super_, &Keyboard_initial);
// }
//
// void Keyboard_initial(Keyboard *me, Event const *e)
// {
//    /* ... initialization of Keyboard attributes */
//    printf("Keyboard initialized");
//    FsmTran_((Fsm *)me, &Keyboard_default);
// }
//
// void Keyboard_default(Keyboard *me, Event const *e)
// {
//    switch (e->sig)
//    {
//       case SHIFT_DEPRESSED_SIG:
//          printf("default::SHIFT_DEPRESSED");
//          FsmTran_((Fsm *)me, &Keyboard_shifted);
//          break;
//       case ANY_KEY_SIG:
//          printf("key %c", (char)tolower(((KeyboardEvt *)e)->code));
//          break;
//    }
// }
//
// void Keyboard_shifted(Keyboard *me, Event const *e)
// {
//    switch (e->sig)
//    {
//       case SHIFT_RELEASED_SIG:
//          printf("shifted::SHIFT_RELEASED");
//          FsmTran_((Fsm *)me, &Keyboard_default);
//          break;
//       case ANY_KEY_SIG:
//          printf("key %c", (char)toupper(((KeyboardEvt *)e)->code));
//          break;
//    }
// }

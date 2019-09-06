# Ti_AuthomatMoore
Finite state machine. Moore machine. Authomat Moore.

---

## Definition

A <b>Finite State Machine</b> is a model of computation based on a hypothetical machine made of one or more states. Only one single state of this machine can be active at the same time. It means the machine has to transition from one state to another in to perform different actions.

Moore Machines: Moore machines are finite state machines with output value and its output depends only on present state. It can be defined as (Q, q0, ∑, O, δ, λ) where:

> Q: finite set of states  
> q0: initial state of machine  
> ∑: finite set of input symbols  
> O: output alphabet  
> δ: transition function where Q × ∑ → Q  
> λ: output function where Q → O  
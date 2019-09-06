# Ti_AuthomatMoore
Finite state machine. Moore machine. Authomat Moore.

---

## Definition

A <b>Finite State Machine</b> is a model of computation based on a hypothetical machine made of one or more states. Only one single state of this machine can be active at the same time. It means the machine has to transition from one state to another in to perform different actions.

<b>Moore Machines:</b> Moore machines are finite state machines with output value and its output depends only on present state. It can be defined as (Q, q0, ∑, O, δ, λ) where:

> <b>Q:</b> finite set of states  
> <b>q0:</b> initial state of machine  
> <b>∑:</b> finite set of input symbols  
> <b>O:</b> output alphabet  
> <b>δ:</b> transition function where Q × ∑ → Q  
> <b>λ:</b> output function where Q → O  

<p align="center">
  <img src="img/moore_machine.jpg">
</p>

---

## Problem

Find in one round of each symbol how many times a word from the alphabet <b>Q</b> is repeated in the input set <b>∑</b>.

I used the <i>Moore Machine</i> to solve this problem.

---

## Example

Imagine we have an alphabet of characters <i><b>Q</b> = {a, b}</i> and word we are looking for: `abb`. We will search for this word in an arbitrary set of input data. But for example, let's take it: `ababbabbaabbabbabaaabba`.

Let's build a <i>Moore diagram</i> for this example:

<p align="center">
  <img src="img/abb.jpg">
</p>
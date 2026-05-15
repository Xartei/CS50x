# Week 0 PSET Solutions
## Starting from Scratch
**Solution:** [Play "It´s Raining Pou" here](https://scratch.mit.edu/projects/1291934703)
> Time Spent: Aproximately 40-50 Hours (From *Creation* to *Upload*)

<img width="476" height="356" alt="itsRainingPou" src="https://github.com/user-attachments/assets/02aeb742-984c-41c1-8895-df5e596cca70" />

### Core Mechanics
> A mouse-controlled physics survival game where the player tracks a paddle (Trampoline) to the cursor's X-axis to keep entities ("Pou") from falling below the death boundary (Y < -180).
  - **Custom Physics System:** Implements a dedicated gravity loop mapping velocity to the Y-axis. Features custom collision logic including randomized lateral wall-bouncing, ceiling collision detection to prevent sprite-sticking, and randomized positive upward thrust when colliding with the Trampoline.
  - **Dynamic Entity Spawning:** Utilizes Scratch's cloning engine to increase difficulty over time. Clones are generated with autonomous physics calculations and randomized inherent properties (such as sprite scale and spawn coordinates).
  - **Multiplier Scoring:** A real-time point generation system (PouPoints) that scales dynamically. A separate Points Modifier function increases the point yield per second as more clones spawn.
  - **Custom Sort Algorithm & Cloud Leaderboards:** Uses a custom array sorting algorithm (a visual bubble-sort logic implementation) to evaluate, replace, and sort local high scores. Integrates Scratch Cloud Variables to pull, compare, and update a global "World Record" in real-time upon Game Over.

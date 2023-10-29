The current version of Nachos can run only one user program at a time. To enable Nachos load and run multiple programs concurrently, we need to overcome the following three limitations.
• First Limitation: Nachos must be able to accept multiple user program names.
• Second Limitation: Nachos must be able to create an individual thread for each user program.
• Third Limitation: Nachos must be able to load multiple programs and create address space for each program in the main memory.

This implementation solves the 1st and 2nd limitation.

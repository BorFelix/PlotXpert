
### OOP Memory View

+---------------------+
|      Text Segment   |
+---------------------+
|      mFunction()    |   <-- Stored only once.
+---------------------+

+---------------------+
|      Data Segment   |
+---------------------+
|        m_sData      |   <-- Static data is stored here, once for all instances.
+---------------------+

+---------------------+
|        Stack        |
+---------------------+
|      sample         |   <-- Memory for object declared on the stack, holds the "m_data" section.
|      pSample        |   <-- Holds address to heap memory (for object created by using 'new').
+---------------------+

+---------------------+
|        Heap         |
+---------------------+
|      *pSample       |   <-- Memory for object declared using 'new', holds the "m_data" section.
+---------------------+



### Inheritance Memory View

+----------------------------+
|      Text Segment          |
+----------------------------+
|  Base::baseFunction()      |
+----------------------------+
| Derived::derivedFunction() |
+----------------------------+

# Stack or Heap (Depending on how the object was created):
Base Object:
+----------------------+
|       baseVar        |   <-- Data member of the Base class.
+----------------------+

# Stack or Heap (Depending on how the object was created):
Derived Object:
+----------------------+
|       baseVar        |   <-- Inherited data member from Base class.
+----------------------+
|     derivedVar       |   <-- Data member of the Derived class.
+----------------------+



## Slicing Memory View

Derived Object in Memory:
+----------------------+
|      baseVar         |
+----------------------+
|       derivedVar     |
+----------------------+

After Slicing (e.g.: "Base b = d;" or "someFunction(d)"),
Derived Object is slicing off in Memory:
+----------------------+
|       baseVar        |
+----------------------+


## Virtual Function Memory View

+---------------------+
|      Data Segment   |
+---------------------+
|   Base's VTable     |   <-- Points to Base's virtual functions
| Derived's VTable    |   <-- Points to Derived's virtual functions (overrides Base's)
+---------------------+

              Base's VTable:
              +------------------------------------+
              | Address of Base's func1            |
              +------------------------------------+
              | Address of Base's func2            |
              +------------------------------------+

              Derived's VTable:
              +---------------------------------------+
              | Address of Derived's func1 (override) |
              +---------------------------------------+
              | Address of Base's func2 (inherited)   |
              +---------------------------------------+
              | Address of Derived's func3            |
              +---------------------------------------+



Base/Derived Obj in Memory:
+--------------------------+
|        VPtr              |   <-- Points to VTable of its class. Determines the function to call.
+--------------------------+
|  ... class data members  |
+--------------------------+



[Stack]                                [Heap]
+------------+                         +-----+
| unique_ptr |  -----> pointer to ---->| int |
|            |                         |  42 |
+------------+                         +-----+



[Stack]                                 [Heap]
+------------+                         +------------------+
|   p1       |  -----> pointer to ---->|      int         |
|            |                         |       42         |
+------------+                         +------------------+
|   p2       |                         |   Control Block  |
|            |  -----> pointer to ---->|                  |
+------------+                         | Ref Count: 2     |
                                       | Weak Count: 0    |
                                       | Deleter: ...     |
                                       | Allocator: ...   |
                                       +------------------+



### Kernel Segment in Process
+--------------------------------------------------+
|                                                  |
|                 User Space                       |
|                                                  |
|  +-------------------------------------------+   |
|  |                                           |   |
|  |               Application Code            |   |
|  |                                           |   |
|  +-------------------------------------------+   |
|  |                                           |   |
|  |               Application Data            |   |
|  |                                           |   |
|  +-------------------------------------------+   |
|  |                                           |   |
|  |                     Heap                  |   |
|  |                                           |   |
|  +-------------------------------------------+   |
|  |                                           |   |
|  |                 User Stack                |   |
|  |                                           |   |
|  +-------------------------------------------+   |
|                                                  |
|----------------Memory Boundary-------------------|
|                                                  |
|                 Kernel Space                     |
|                                                  |
|  +-------------------------------------------+   |
|  |         Process Control Block (PCB)       |   |
|  +-------------------------------------------+   |
|  |                Page Tables                |   |
|  +-------------------------------------------+   |
|  |              Kernel Stack                 |   |
|  +-------------------------------------------+   |
|  |           File Descriptor Tables          |   |
|  +-------------------------------------------+   |
|  |         Network Sockets/I/O structs       |   |
|  +-------------------------------------------+   |
|  |           Signals/Message Queues          |   |
|  +-------------------------------------------+   |
|  |           Other OS-specific structures    |   |
|  +-------------------------------------------+   |
|                                                  |
+--------------------------------------------------+




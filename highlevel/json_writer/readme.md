JSON Writer
===========
This library provides an API for writing JSON data into a memory buffer.
This library is not intended as a generic JSON library but is specifically aimed
at applications that require fast generation of JSON data with a flat memory footprint.

This allows the writer to contain a fixed memory size and fast performance but to gain
these advantages we must forgo other features such as the ability to read the data back.

The library expect the user to write data in a linear fashion from start to end. Unlike
other JSON serializers, this writer does not let you make changes to already serialized
data. This may make this library unsuitable for more complicated serialization needs,
however the benefits (as mentioned) mean this serializes has a fixed memory footprint
and is extremely fast.

The writer will maintain information about the most amount of memory used by the writer
during the applications lifetime.

Benefits of JsonWriter
======================
    * Performance   - The writer is intended to be extremely fast
    * Fixed memory  - The writer does not dynamically allocate memory

Negatives
=========
    * Dynamic nodes - Once a node has been committed it cannot be changed without writing a new block

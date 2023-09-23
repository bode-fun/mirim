# Mirim

Mirim (small) want's to be a small programming language, which compiles to
WebAssembly.

It is inspired by Go and Swift and strives to archive Go's simplicity with
Swift's safety, memory management and strong static type system.

## Goals and Non-goals

### Goals

The goal is to figure out how to build a compiler and what makes a good programming
language to implement programming languages. I started with C++
and I'm now moving to Go, since I'm more comfortable in writing go.
I suspect that a programming language to implement programming languages in, would
be a programming language like Swift, since it has algebraic data-types and enums,
which could come in handy during the tokenization step.

Furthermore, I'm referencing multiple programming language implementation to learn
about multiple possible and successful approaches on implementing these.

### Non-goals

A **non-goal** is to build a production-ready programming language with an
extensible standard library. Therefore the following disclaimer:

**Mirim is a prototype, a toy language to get into compilers engineering
and not an actual programming language!**

## Syntax

```mirim
import std.fmt

struct Person {
    pub let name string

    // Implied if not specified
    init(name string) {
        self.name = name
    }

    pub fun say_hello(self) string {
        return fmt.srintf("Hello, %s\n", self.name)
    }
}

pub fun main(args string[]) int {
    let me = Person(name = args[0])

    fmt.print(me.say_hello())

    return 0
}
```

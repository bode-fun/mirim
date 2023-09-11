# Mirim

Mirim (small) want's to be a small embeddable programming language, which compiles to
WebAssembly.

It is inspired by Go and Lua and strives to archive Go's strong static type
system with Lua's simplicity.

**It's more of a prototype to get into compilers than an actual language**

```mirim
import std.fmt

struct Person {
    Name string

    // Implied if not specified
    New(name string) {
        self.Name = name
    }

    fun SayHello(self) string {
        return "Hello, ${self.Name}\n"
    }
}

fun main() {
    Person me = Person.New()

    fmt.Print(me.SayHello())
}

```
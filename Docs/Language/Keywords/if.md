---
title: If
---

Branch the program flow conditionally.

## Keywords:

### **if**

This expression takes a boolean value and branches the program flow based
upon it's value.
The result of this expression can be assigned to a variable.

#### Syntax:

```mirim
if <BOOLEAN> {} else if <BOOLEAN> {} else {}
```

```mirim
if <BOOLEAN> {} else {}
```

```mirim
if <BOOLEAN> {}
```

```mirim
<IDENTIFIER> = if <BOOLEAN> {} else if <BOOLEAN> {} else {}
```

```mirim
<IDENTIFIER> = if <BOOLEAN> {} else {}
```

#### Examples:

```mirim
fun main(args string[]) int {
    if args[0] == "foo" {
        return 0
    } else {
        return 1
    }
}
```

```mirim
fun main() int {
    let exit_code = if args[0] == "foo" {
        return 0
    } else if args[0] == "bar" {
        return 1
    } else {
        return 2
    }

    return exit_code
}
```

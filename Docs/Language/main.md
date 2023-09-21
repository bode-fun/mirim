---
title: Main
---

The entry point of a program.

## Functions

### **main**

The entry point of the program, carrying the starting arguments.
The returned int is the exit code of the program.
If no exit code is provided, the program terminates with exit code 0.

#### Prototypes:

```mirim
fun main() int
```

```mirim
fun main(args: string[]) int
```

```mirim
fun main()
```

```mirim
fun main(args: string[])
```


#### Parameters:

| Param  | Type     | Required | Description                                  |
| ------ | -------- | -------- | -------------------------------------------- |
| `args` | string[] | No       | Arguments passed in by the operating system. |


#### Returns:

| Type  | Required | Description    |
| ----- | -------- | -------------- |
| `int` | No       | The exit code. |


#### Examples:

```mirim
fun main() {}
```

```mirim
fun main() int {
    return 0
}
```

```mirim
fun main(args: string[]) int {
    if args[0] == "main" {
        return 0
    } else {
        return 1
    }
}
```

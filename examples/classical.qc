fn compute(a: int, b: float) -> float {
    let c: float = a + b
    let d: float = c / 2
    if (a == b) {
        let e : float = c*d
        d += e
    } 
    return d
}

let x: int = 10
let y: float = 5.5
let result: float = compute(x, y)

print("Result = ", result)

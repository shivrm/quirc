// Initialize
let a: [qubit; 2] = [0, 1]
let b: [qubit; 2] = [1, 0]
let carry: qubit = 0

// LSB addition
CNOT(a[0], b[0])
CNOT(a[0], carry)
CCNOT(a[0], b[0], carry)

// MSB addition
CNOT(a[1], b[1])
CNOT(a[1], carry)
CCNOT(a[1], b[1], carry)

// Measure
let sum: [bit; 2] = measure(b)
sum[1] = measure(carry)

print("Sum:", sum)

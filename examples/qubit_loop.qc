let qs: [qubit; 4] = [0, 0, 0, 0]

for q in qs {
    H(q)
    Z(q)
}

let measured: [bit; 4] = measure(qs)
print("Measured:", measured)

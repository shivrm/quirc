fn controlled_rotation(qs: [qubit; 3], theta: float) {
    if theta > 0.5 {
        RX(theta, qs[0])
        CP(theta, qs[0], qs[1])
    } else {
        RZ(theta, qs[2])
        H(qs[2])
    }
}

let qs: [qubit; 3] = [0, 0, 0]
controlled_rotation(qs, 0.8)

let result: [bit; 3] = measure(qs)
print("Measurement:", result)
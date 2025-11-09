// For testing purposes
struct Pair {
    q0: qubit,
    q1: qubit
}

fn bell(qs: [qubit]) {
    let q0: qubit = 0
    H(q0)
        for q in qs {
            CNOT(q0, q)
    }
}

fn bell(qs: [qubit; n]) {
    let q0: qubit = 0
        H(q0)
        for q in qs {
            CNOT(q0, q)
    }
}

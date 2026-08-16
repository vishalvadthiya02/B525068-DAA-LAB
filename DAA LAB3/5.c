/*
Multiply(M, N):

    if n = 1:
        return M * N

    S1 = M1 + M2
    S2 = M1 - M2

    T1 = N1 + N2
    T2 = N1 - N2

    P = Multiply(S1, T1)
    Q = Multiply(S2, T2)

    A = (P + Q)/2
    B = (P - Q)/2

    return [[A, B],
            [B, A]]

*/


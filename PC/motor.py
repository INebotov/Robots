def mapv(value, leftMin, leftMax, rightMin, rightMax):
    leftSpan = leftMax - leftMin
    rightSpan = rightMax - rightMin
    valueScaled = float(value - leftMin) / float(leftSpan)
    return int(rightMin + (valueScaled * rightSpan))


class MotorsValues:
    D11: bool = False
    D12: bool = False
    D21: bool = False
    D22: bool = False

    P1: int = 0
    P2: int = 0

    Shoot: bool = False

    def ToBytes(self) -> bytes:
        return bytes([
            int(self.Shoot),
            self.P1, self.D11, self.D12,
            self.P2, self.D21, self.D22
        ])


givenDiaTable = {
    # DIRECTION  POT > 125
    (True,  True):  (126, 255, lambda m, x: (m, x), (True, False)),
    (True, False):  (0, 125, lambda m, x: (x, m), (False, True)),
    (False, True):  (126, 255, lambda m, x: (m, x), (False, True)),
    (False, False): (0, 125, lambda m, x: (x, m), (True, False))
}

modeTable = {
    # Slow Fast
    (True, False): (0, 70),
    (False, True): (0, 255),
    (False, False): (0, 128),
    (True, True): (0, 128)
}


def Calc(val, d, sl, fs):
    m = givenDiaTable[d, val > 125]
    toRan = m[2](*modeTable[sl, fs])
    return mapv(val, m[0], m[1], *toRan), m[3][0], m[3][1]


def Calculate(
        POT1: int,
        POT2: int,

        FIRE: bool,
        DIRECTION: bool,

        SLOW: bool,
        FAST: bool
) -> MotorsValues:
    r = MotorsValues
    r.Shoot = FIRE

    r.P1, r.D11, r.D12 = Calc(POT1, DIRECTION, SLOW, FAST)
    r.P2, r.D21, r.D22 = Calc(POT2, DIRECTION, SLOW, FAST)

    return r

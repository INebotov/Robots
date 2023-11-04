import keys
import motor
import serialWave


# def Render(sender):
#   rc = '\033[0m'
#   tfc = {True: '\033[32m',
#          False: '\033[31m'}
#
#   def RealRender(ks):
#       values = motor.Calculate(ks.POT1, ks.POT2, ks.FIRE,
#                                ks.DIRECTION, ks.SLOW, ks.FORSAGE)
#       sender.Send(values.ToBytes(values))
#
#       arrow1 = '↑' if values.D11 else '↓'
#       arrow2 = '↑' if values.D21 else '↓'
#
#       speedColor1 = '\033[91m' if values.P1 > 194 else (
#           '\033[93m' if values.P1 > 126 else '\033[92m')
#       speedColor2 = '\033[91m' if values.P2 > 194 else (
#           '\033[93m' if values.P2 > 126 else '\033[92m')
#
#       line1 = f'{arrow1} P1: {speedColor1}{values.P1}{rc}  D11: {tfc[values.D11]}{values.D11}{rc}  D12: {tfc[values.D12]}{values.D12}{rc}'
#       line2 = f'{arrow2} P2: {speedColor2}{values.P2}{rc}  D21: {tfc[values.D21]}{values.D21}{rc}  D22: {tfc[values.D22]}{values.D22}{rc}'
#       print()
#       print(line1)
#       print(line2)
#       print()
#
#   return RealRender


sen = serialWave.Serial("/dev/ttyACM0")
ks = keys.KeyReader()

while True:
    values = motor.Calculate(ks.POT1, ks.POT2, ks.FIRE,
                             ks.DIRECTION, ks.SLOW, ks.FORSAGE)
    sen.Send(values.ToBytes(values))
    line1 = f'P1: {values.P1}  D11: {values.D11} D12: {values.D12}'
    line2 = f'P2: {values.P2}  D21: {values.D21} D22: {values.D22}'
    print()
    print(line1)
    print(line2)
    print()

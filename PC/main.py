import keys
import curses
import motor
import culour


def Render(status_win):
    rc = '\033[0m'
    tfc = {True: '\033[32m',
           False: '\033[31m'}

    def RealRender(ks):
        values = motor.Calculate(ks.POT1, ks.POT2, ks.FIRE,
                                 ks.DIRECTION, ks.SLOW, ks.FORSAGE)
        status_win.clear()
        arrow1 = '↑' if values.D11 else '↓'
        arrow2 = '↑' if values.D21 else '↓'

        speedColor1 = '\033[91m' if values.P1 > 194 else (
            '\033[93m' if values.P1 > 126 else '\033[92m')
        speedColor2 = '\033[91m' if values.P2 > 194 else (
            '\033[93m' if values.P2 > 126 else '\033[92m')

        line1 = f'{arrow1} P1: {speedColor1}{values.P1}{rc}  D11: {tfc[values.D11]}{values.D11}{rc}  D12: {tfc[values.D12]}{values.D12}{rc}'

        line2 = f'{arrow2} P2: {speedColor2}{values.P2}{rc}  D21: {tfc[values.D21]}{values.D21}{rc}  D22: {tfc[values.D22]}{values.D22}{rc}'

        status_win.addstr((curses.LINES//2),
                          (curses.COLS - len(line1)) // 2, line1)
        culour.addstr(status_win, (curses.LINES//2)+1,
                      (curses.COLS - len(line2)) // 2, line2)
        status_win.refresh()

    return RealRender


curses.initscr()
curses.curs_set(0)
curses.noecho()

win = curses.newwin(curses.LINES, curses.COLS)

keys = keys.KeyReader(Render(win))

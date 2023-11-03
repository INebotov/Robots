from pynput import keyboard


class KeyReader:
    FORSAGE = False
    SLOW = False
    DIRECTION = True
    FIRE = False

    POT1 = 126
    POT2 = 126

    def __init__(self, renderer):
        self.Listener = keyboard.Listener(
            on_press=self.on_press, on_release=self.on_release)
        self.Renderer = renderer

        self.Listener.start()
        self.Listener.join()

    def on_press(self, key):
        if key == keyboard.Key.ctrl:
            self.FORSAGE = True
            self.SLOW = False
        elif key == keyboard.Key.shift:
            self.SLOW = True
            self.FORSAGE = False
        elif key == keyboard.Key.space:
            self.FIRE = True
        elif key == keyboard.Key.tab:
            self.DIRECTION = not self.DIRECTION
        elif key == keyboard.Key.esc:
            exit(0)

        else:
            try:
                k = key.char
                if k == "q":
                    self.POT1 = 255
                elif k == "a":
                    self.POT1 = 0
                elif k == "e":
                    self.POT2 = 255
                elif k == "d":
                    self.POT2 = 0

            except:
                pass

        self.Renderer(self)

    def on_release(self, key):
        if key == keyboard.Key.ctrl:
            self.FORSAGE = False
        elif key == keyboard.Key.shift:
            self.SLOW = False
        elif key == keyboard.Key.shift:
            self.FIRE = False

        else:
            try:
                k = key.char
                if k == "q":
                    self.POT1 = 126
                elif k == "a":
                    self.POT1 = 126
                elif k == "e":
                    self.POT2 = 126
                elif k == "d":
                    self.POT2 = 126

            except:
                pass

        self.Renderer(self)

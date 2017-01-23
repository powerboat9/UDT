#transmits data using base64

inp = base64.b64encode("Hi")
charList = list((string.ascii_letters + string.digits + "+/= ").replace("~", "") + "~")

class WireIn():
    def __init__(self, channel, baud = 5, 
volPercent = 100)
        self.channel = channel
        self.baud = baud
        self.volPercent = volPercent
        self.buffer = []
    def transmit

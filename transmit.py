#transmits data using base64

inp = base64.b64encode("Hi")
charList = list((string.ascii_letters + string.digits + "+/= ").replace("~", "") + "~")

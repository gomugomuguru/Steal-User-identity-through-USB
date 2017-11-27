import socket
import smtplib
from uuid import getnode


user = 'ninedividebyzero@gmail.com'
password = 'dummyPassword'

recipients = ['ninedividebyzero@gmail.com']
sender = 'ninedividebyzero@gmail.com'
message = "IP address - " + socket.gethostbyname(socket.gethostname()) + "; MAC ID - " + hex(getnode())
session = smtplib.SMTP('smtp.gmail.com',587)
session.starttls()
session.login(user, password)
session.sendmail(sender, recipients, message)
session.quit()

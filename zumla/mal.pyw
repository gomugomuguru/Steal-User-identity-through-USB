import socket
import smtplib
from uuid import getnode

user = '*******'
password = '*******'
recipients = ['*****']
sender = '******'
message = "IP address - " + socket.gethostbyname(socket.gethostname()) + "; MAC ID - " + hex(getnode())
session = smtplib.SMTP('smtp.gmail.com',587)
session.starttls()
session.login(user, password)
session.sendmail(sender, recipients, message)
session.quit()

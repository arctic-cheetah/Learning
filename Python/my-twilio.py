import os
from twilio.rest import Client

client = Client("AC4eb6d26fbccd8172be97d1fbff63ed3b", "22c5309ea4e84ee4bf105acf799e5426")

for msg in client.messages.list():
    print(msg.body)

msg = client.messages.create(
    to="+61470130392",
    from_="+17028723457",
    body="Hello from Python"
)

print(f"Created a new message: {msg.sid}")
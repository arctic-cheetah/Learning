const Twilio = require("twilio");

const client = new Twilio("", "");

client.messages
    .list()
    .then(messages => (console.log("The most recent message: " + messages[0].body)))
    .catch(error => (console.log(error)) );

console.log("Fetching your message");

const Twilio = require("twilio");

const client = new Twilio("AC4eb6d26fbccd8172be97d1fbff63ed3b", "22c5309ea4e84ee4bf105acf799e542");

client.messages
    .list()
    .then(messages => (console.log("The most recent message: " + messages[0].body)))
    .catch(error => (console.log(error)) );

console.log("Fetching your message");

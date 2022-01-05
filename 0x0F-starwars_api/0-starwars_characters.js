#!/usr/bin/node
// Star Wars Characters
const request = require('request');
const id = process.argv[2];
request('https://swapi-api.hbtn.io/api/films/' + id + '', function (error, response, body) {
  const data = JSON.parse(body);
  JSON.parse(body).characters.forEach(element => {
    request(element, function (error, response, body) {
      const d = JSON.parse(body);
      console.log(d.name);
    });
  });
});

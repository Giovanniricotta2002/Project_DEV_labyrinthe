const express = require('express');

// Constants
const PORT = 8080;
const HOST = 'localhost';

// App
const app = express();
/*app.get('/', (req, res) => {
  //console.log(req);
  res.send('Hello World');
});*/

app.post('/creation/:name', function (req, res) {
  let map = JSON.parse(req.headers.map)
  console.log("headers => ", req.headers);
  console.log("headers.map => ", map);
  console.log(req.params.name);
  console.log(process.env);
  res.send(map);
});

app.listen(PORT, HOST, () => {
  console.log(`Running on http://${HOST}:${PORT}`);
});


const { Client } = require('pg')
const express = require('express');

// Constants
const PORT = 88;



// App
const app = express();

const client = new Client({
  host: '172.21.0.2',
  port: process.env.DB_PORT,
  user: process.env.DB_USER,
  password: process.env.DB_PASSWORD,
})





app.get('/', (req, res) => {
  //dconsole.log(req);
  res.send('Hello World');
});




app.post('/creation/:name', function (req, res) {
  let map = JSON.parse(req.headers.map)
  console.log("headers => ", req.headers);
  console.log("headers.map => ", map);
  console.log(req.params.name);
  
  let connected = false
  client.connect((err) => {
    if (err) console.log(err);
    else connected = true;
  })
  
  
  
  
  let query_map = 'INSERT INTO map(id_value_map, nbr_de_case_total, name_difficulte, nom, creator, date_creation, ) VALUES($1, $2) RETURNING *'
  let params_map = []

  /*let query_value_map = 'INSERT INTO ValueMap(map) VALUES($1) RETURNING int_value_map'
  let params_value_map = [tt.map]
  
  // callback
  client.query(query_value_map, params_value_map, (err, res) => {
    if (err) {
      console.log(err.stack)
    } else {
      console.log(res.rows)
    }
  })*/
  
  
  res.send(map);





















}); 









app.get('/toto', function (req, res) {
  let connected = false
  client.connect((err) => {
    if (err) console.log(err);
    else {
      connected = true;
    }
  })
  
  res.send('Hello World')
});



app.listen(PORT, () => {
  console.log(`Running on http://localhost:${PORT}`);
});


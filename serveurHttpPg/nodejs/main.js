const { Client } = require('pg')
const express = require('express');

// Constants
const PORT = 88;



// App
const app = express();






app.get('/', (req, res) => {
  //dconsole.log(req);
  res.send('Hello World');
});

function _pg() {
  return new Client({
    host: '172.18.0.2',
    port: process.env.DB_PORT,
    user: process.env.DB_USER,
    password: process.env.DB_PASSWORD,
  })
}



function query(query, params, res) {
  const client = _pg()


  client.connect()
  client
    .query(query, params)
    .then((result) => {
      //console.log(result.rows);
      res.send(result.rows)
    })
    .catch((e) => console.error(e.stack))
    .then(() => client.end())
}



app.post('/creation/:name', function (req, res) {
  //console.log("headers => ", req.headers);
  //console.log("headers.map => ", map);


  let mapLab = JSON.parse(req.headers.map)

  let map = JSON.stringify(mapLab.case_map);
  let creator = mapLab.creator
  let diff = mapLab.difficulty
  let nbr_de_case_total = mapLab.nbr_case_total
  let name = req.params.name
  let start = mapLab.start
  let end = mapLab.end




  let query_map = 'INSERT INTO map(case_map, nbr_de_case_total, name_difficulte, nom, creator, date_creation, estart, eend) VALUES($1, $2, $3, $4, $5, $6, $7, $8) RETURNING id_map'
  let params_map = [map, nbr_de_case_total, diff, name, creator, "NOW()", start, end]

  // let query_map = 'INSERT INTO map(case_map) VALUES($1) RETURNING id_map'
  // let params_map = [map]
// console.log(query_map, params_map);
  query(query_map, params_map, res)


});


app.get('/map/:idmap', function (req, res) {
  let query_map = 'Select * from map where id_map = $1'
  let params_map = [req.params.idmap]

  query(query_map, params_map, res)
})

app.get('/mapall/', function (req, res) {
  let query_map = "select id_map, nom, creator, date_creation, start, end from map"

  query(query_map, [], res)
})



app.put('/update/map/', function (req, res) {

  let id = req.headers.id;
  let newValueMap = JSON.parse(req.headers.update)


  let query_map = 'Select * from map where id_map = $1'
  let params_map = [id]

  const client = _pg()


  client.connect()
  client
    .query(query_map, params_map)
    .then((result) => {

      let result_old = JSON.parse(JSON.stringify(result.rows[0]))


      result_old["case_map"] = newValueMap["case_map"]
      result_old["creator"] = newValueMap["creator"]
      result_old["name_difficulte"] = newValueMap["difficulty"]
      result_old["nbr_de_case_total"] = newValueMap["nbr_case_total"]
      result_old["start"] = newValueMap["start"]
      result_old["end"] = newValueMap["end"]



      let query_update_map = "UPDATE map SET case_map=$1, nbr_de_case_total=$2, name_difficulte=$3, nom=$4, creator=$5, date_modification=$6, date_test=$7, start=$8, end=$9 WHERE id_map=$10;"
      let params_update_map = [
        JSON.stringify(result_old["case_map"]),
        result_old["nbr_de_case_total"],
        result_old["name_difficulte"],
        result_old["nom"],
        result_old["creator"],
        'NOW()',
        result_old["date_test"],
        result_old["id_map"],
        result_old["start"],
        result_old["end"]
      ]

      query(query_update_map, params_update_map, res)


    })
    .catch((e) => console.error(e.stack))
    .then(() => client.end())

})






app.listen(PORT, () => {
  console.log(`Running on http://localhost:${PORT}`);
});


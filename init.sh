#!/bin/bash

echo ouvrire le terminal docker bdd
echo "docker exec -itu postgres bdd /bin/bash"

echo ouvrire le bash de postgres
echo "psql -W"
echo mot de passe de postgres
echo "mdp: bdd"

echo voir toutes les database
echo "\l"

echo exporté la base


echo Start docker img
echo \# "docker run -v /bdd:/var/lib/postgresql/data --name bdd -e POSTGRES_PASSWORD=bdd -p 5432:5432 postgres:bullseye"
docker run -v /bdd:/var/lib/postgresql/data --name bdd -e POSTGRES_PASSWORD=bdd -p 5432:5432 postgres:bullseye
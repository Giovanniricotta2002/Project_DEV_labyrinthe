CREATE SEQUENCE labyrinthe_texture_primary_key AS integer;
CREATE SEQUENCE labyrinthe_case_primary_key AS integer;
CREATE SEQUENCE labyrinthe_map_primary_key AS integer;
CREATE SEQUENCE labyrinthe_difficulte_primary_key AS integer;


CREATE TABLE ia (
    seconde INT,
    nbr_de_piege INT
);

CREATE TABLE texture
(
    id_texture smallserial PRIMARY KEY NOT NULL nextval('labyrinthe_texture_primary_key'),
    nom TEXT
);

CREATE TABLE case
(
    id_case serial PRIMARY KEY NOT NULL nextval('labyrinthe_case_primary_key'),
    id_map serial,
    x INT,
    y INT
);

CREATE TABLE map
(
    id_map INT PRIMARY KEY NOT NULL nextval('labyrinthe_map_primary_key'),
    nom TEXT,
    creator TEXT,
    date_creation TIMESTAMP,
    date_modification TIMESTAMP,
    date_test TIMESTAMP
);

CREATE TABLE diff
(
    id_difficulte INT PRIMARY KEY NOT NULL nextval('labyrinthe_difficulte_primary_key'),
    nbr_de_case_total INT,
    name_difficulte char

);


ALTER SEQUENCE labyrinthe_texture_primary_key OWNED BY texture.id_texture;
ALTER SEQUENCE labyrinthe_case_primary_key OWNED BY case.id_case;
ALTER SEQUENCE labyrinthe_map_primary_key OWNED BY map.id_map;
ALTER SEQUENCE labyrinthe_difficulte_primary_key OWNED BY diff.id_difficulte;
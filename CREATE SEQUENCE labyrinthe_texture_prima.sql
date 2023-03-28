CREATE TABLE ia (
    seconde INT,
    nbr_de_piege INT
);

CREATE TABLE texture
(
    id_texture serial PRIMARY KEY NOT NULL,
    nom TEXT,
    caractere text
);


CREATE TABLE map
(
    id_map SERIAL PRIMARY KEY NOT NULL,
    id_value_map integer REFERENCES ValueMap (int_value_map),
    nbr_de_case_total INT,
    name_difficulte char,
    nom TEXT,
    creator TEXT,
    date_creation TIMESTAMP,
    date_modification TIMESTAMP,
    date_test TIMESTAMP
);

CREATE TABLE ValueMap(
    int_value_map SERIAL PRIMARY KEY NOT NULL,
    map JSON
);
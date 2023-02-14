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
    id_texture serial PRIMARY KEY NOT NULL,
    nom TEXT
);

CREATE TABLE caseblock
(
    id_case serial PRIMARY KEY NOT NULL,
    id_map int,
    id_texture int,
    x INT,
    y INT,
    CONSTRAINT idmap
      FOREIGN KEY(id_map) 
	  REFERENCES map(id_map)
    CONSTRAINT idtexture
        FOREIGN KEY(id_texture)
        REFERENCES texture(id_texture)
);



CREATE TABLE map
(
    id_map INT PRIMARY KEY NOT NULL,
    id_diff serial,
    nom TEXT,
    creator TEXT,
    date_creation TIMESTAMP,
    date_modification TIMESTAMP,
    date_test TIMESTAMP,
    CONSTRAINT iddiff
      FOREIGN KEY(id_diff)
      REFERENCES diff(id_difficulte)
);


CREATE TABLE diff
(
    id_difficulte INT PRIMARY KEY NOT NULL,
    nbr_de_case_total INT,
    name_difficulte char
);


ALTER SEQUENCE labyrinthe_texture_primary_key OWNED BY texture.id_texture;
ALTER SEQUENCE labyrinthe_case_primary_key OWNED BY case.id_case;
ALTER SEQUENCE labyrinthe_map_primary_key OWNED BY map.id_map;
ALTER SEQUENCE labyrinthe_difficulte_primary_key OWNED BY diff.id_difficulte;



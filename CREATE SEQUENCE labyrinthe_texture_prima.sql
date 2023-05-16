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


CREATE TABLE map (
	id_map serial4 NOT NULL,
	case_map json NULL,
	nbr_de_case_total int4 NULL,
	name_difficulte text NULL,
	nom text NULL,
	creator text NULL,
	date_creation timestamp NULL,
	date_modification timestamp NULL,
	date_test timestamp NULL,
	start json NULL,
	end json NULL,
	CONSTRAINT map_pkey PRIMARY KEY (id_map)
);

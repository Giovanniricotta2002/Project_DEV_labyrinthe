FROM postgres:bullseye

RUN chown 1000:1000 /var/lib/postgresql/data

ENV POSTGRES_PASSWORD=bdd

EXPOSE 5432

#docker run --name some-postgres -e POSTGRES_PASSWORD=mysecretpassword -d -p 5432:5432 postgres
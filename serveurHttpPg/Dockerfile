FROM node:lts-alpine3.17

RUN mkdir labyrinthe

WORKDIR labyrinthe

COPY ./nodejs/ .

RUN npm i

EXPOSE 8080

CMD [ "npm", "run", "start" ]

 
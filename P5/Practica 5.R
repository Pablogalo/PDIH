library(tuneR)
library(seewave)
library(audio)

setwd("E:/Carrera/2020-2021/PDIH/Practicas/P5/Script/")

perro <- readWave('perro.wav')
oveja <- readWave('oveja.wav')

plot( extractWave(perro, from = 1, to = 159732) )
plot( extractWave(oveja, from = 1, to = 108950) )

perro
oveja

unido <- pastew(perro, oveja, output = "Wave")
listen(unido)
plot( extractWave(unido, from = 1, to = 268682) )

filtro <- bwfilter(unido, channel = 1, n = 1, from = 10000, 
			to = 20000, bandpass = TRUE, listen = FALSE, output = "Wave")
listen(filtro)
writeWave(filtro, file.path("mezcla.wav"))

# Segundo archivo de sonido
hola <- readWave('hola.wav')
listen(hola)

eco <- echo(hola, f = 22050, amp = c(0.8, 0.4, 0.2), delay = c(1, 2, 3), output = "Wave")
eco@left <- 10000 * eco@left
listen(eco)

alreves <- revw(eco, output = "Wave")
listen(alreves)
writeWave(alreves, file.path("alreves.wav"))
# FdF

Fil de Fer - 42

## feature 

- I have implementing transformation matrix and projection matrix with linear algebra
- develop with the minilib X library provide with pdf subject file
	- Minimal X library than can put only one color pixel at once in the windows

## Usage

```
Usage ./fdf [option] map

Draw a map in 3D view by wireframe design
A map contain only the dot top for each coordinate

 OPTIONS :        
 --coef-gap=NUM		Gap between 2 dot
 --coef-top=NUM		Coef for z axes
 --d-plan=NUM		Distance between the plan and the center
 --d-user=NUM		Distance between the user eye and the plan
 --color=NUM		Color in Hex, Default is white
 --size-win=NUM,NUM	Window size by x,y
 --no-color		Disable color
 --no-auto		Disable auto scale
 --help			This help

 CONTROLS :
 LEFT - RIGHT - UP - DOWN :
	3D view by rotation of 10Deg per each key press
 h - j - k - l :
	Translation on x and y
 a - z :
	Zoom max - min on 3D view
 s - x :
	Zoom z axes
```

## demo

> ./fdf --size-win=1800,1000 --coef-top=30 maps/julia.fdf

![1](https://github.com/panaC/FdF/raw/master/img/1.png)

> ./fdf --size-win=1800,1000 --coef-top=30 maps/elem-fract.fdf

![2](https://github.com/panaC/FdF/raw/master/img/2.png)

> ./fdf --size-win=1800,1000 maps/t1.fdf

![3](https://github.com/panaC/FdF/raw/master/img/3.png)

## time flow

- 1 month with learning the website [scractapixel](https://www.scratchapixel.com/)

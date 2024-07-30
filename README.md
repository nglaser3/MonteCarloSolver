# 1-D MonteCarlo Solver

This repository holds the c++ source code of my 1-dimensional monte carlo solver.

## How to Install
Prior to installing and compiling this code, please ensure you have the following on your system:

* git
* c++ compiler, such as clang++ or g++ with std-11 at a minimum.

Once you have verified your system has these, simply clone this repository and compile the main.C file:

`git clone git@github.com:nglaser3/MonteCarloSolver.git` 

`cd MonteCarloSolver` 

`g++ -std=c++11 -o mc-opt main.C`

These commands will clone the repository to your local machine, go into the directory, and then compile the c++ code, generating an executable called `mc-opt`.

Prior to running, please verify that you have the mc-opt executable file in your directory. To do this, ensure you are in the base directory of the repository, and then run `ls`. If an `mc-opt` file is present, you are ready to use the code! 

## How to Run
Running this code is very simple, in the command line type:

`./mc-opt <inputfile>`

Replace <inputfile> with the path to your inputfile, and you are good to go!
A sample inputfile is available in the examples directory, called `sample_input`


## Outputs and Features
Currently, this code has three outputs. 
The first two are the effective multiplication factor, $k_{eff}$, and the average scalar flux of each region. 
The final output is the scalar flux as a function of space. This is accomplished by expanding the interaction sites, collision estimator, with n-order legendre polynomials. 
The methodoloy used for this expansion is presented in [this dissertation](https://deepblue.lib.umich.edu/handle/2027.42/124799) by David Griesheimer. 

Further, this code is n-region, meaning the user can define as many regions as desired.

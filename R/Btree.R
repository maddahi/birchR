###----- BIRCH ALGORITHM -----
#' @importFrom Rcpp sourceCpp
#' @useDynLib Btree, .registration = TRUE
#'
NULL

#library(roxygen2)
#library(devtools)
#'@title "Birch Algorithm"
#'@description This package implements a the Birch algorithm using HDF5 data
#'@author "Aparo Antonino" "Da Col Fabio" "Purrone Alberto"


#'@rdname Btree
#'@importFrom methods is
#'@export
#'@importClassesFrom DelayedArray DelayedMatrix
#'@param x the input data
setMethod("Btree",
  signature = signature(x="ANY"),
  definition = function(x)                         #x is the input from user
  {
    if(!is(x,"matrix") & !is(x,"HDF5Matrix") )
      stop("Input is not supported type")
    else {
      pippo <- readInput(x)
    }
    return(pippo)
  } 
)


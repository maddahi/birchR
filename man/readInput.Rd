% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/RcppExports.R
\name{readInput}
\alias{readInput}
\title{Input Matrix}
\usage{
readInput(data)
}
\arguments{
\item{data}{numeric matrix or integer matrix or HDF5Matrix}
}
\value{
a list with the following attributes: centroids, WCSS_per_cluster, best_initialization, iters_per_initialization
}
\description{
Mini-batch-k-means for both matrix and HDF5Matrix
}
\details{
\strong{random}: random selection of data rows as initial centroids
}
\references{
https://github.com/mlampros/ClusterR
}

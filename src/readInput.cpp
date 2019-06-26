#include <RcppArmadillo.h>

#include "beachmat/numeric_matrix.h"
#include "beachmat/integer_matrix.h"
#include <math.h>

using namespace arma;
//get the number of rows
template<typename T>
int get_nrow(const T& data){
  
  auto matrix_type=beachmat::find_sexp_type(data);
  
  if(matrix_type== INTSXP){
    auto final_matrix=beachmat::create_integer_matrix(data);
    //const size_t& nc = final_matrix->get_ncol();
    const size_t& nr = final_matrix->get_nrow();
    int n_row = nr;
    return n_row;
    
  }else if(matrix_type== REALSXP){
    auto final_matrix=beachmat::create_numeric_matrix(data);
    //const size_t& nc = final_matrix->get_ncol();
    const size_t& nr = final_matrix->get_nrow();
    int n_row = nr;
    return n_row;
  }else{
    
    return 0;
  }
}



//get the number of columns
template<typename T>
int get_ncol(const T& data){
  
  auto matrix_type=beachmat::find_sexp_type(data);
  
  if(matrix_type== INTSXP){
    auto final_matrix=beachmat::create_integer_matrix(data);
    const size_t& nc = final_matrix->get_ncol();
    //const size_t& nr = final_matrix->get_nrow();
    int n_col = nc;
    return n_col;
    
  }else if(matrix_type== REALSXP){
    auto final_matrix=beachmat::create_numeric_matrix(data);
    const size_t& nc = final_matrix->get_ncol();
    //const size_t& nr = final_matrix->get_nrow();
    int n_col = nc;
    return n_col;
  }else{
    
    return 0;
  }
}





//'
//' Input Matrix
//'
//' Mini-batch-k-means for both matrix and HDF5Matrix
//'
//'@param data numeric matrix or integer matrix or HDF5Matrix
//'@return a list with the following attributes: centroids, WCSS_per_cluster, best_initialization, iters_per_initialization
//'@details
//'\strong{random}: random selection of data rows as initial centroids
//'
//'@references
//'https://github.com/mlampros/ClusterR
//'
//' @export
// [[Rcpp::export]]
Rcpp::List readInput(SEXP data){
  
  int data_n_rows = get_nrow(data);
  int data_n_cols = get_ncol(data);
  
  
  Rcpp::NumericMatrix submat(data_n_rows, data_n_cols);
  Rcpp::NumericMatrix original(data_n_rows, data_n_cols);
  Rcpp::NumericVector tmp(data_n_rows);
  
  auto final_matrix=beachmat::create_numeric_matrix(data);
  
  
  for ( unsigned int i = 0; i < data_n_rows; i++ ){
    final_matrix->get_row(i, tmp.begin());
    submat.row(i) = tmp;
  }
  
  
  return Rcpp::List::create(Rcpp::Named("Matrix Input") = submat );
}

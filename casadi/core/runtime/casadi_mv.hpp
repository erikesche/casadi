// NOLINT(legal/copyright)
template<typename T1>
void CASADI_PREFIX(mv)(const T1* x, const int* sp_x, const T1* y, T1* z, int tr) {
  // Get sparsities
  int ncol_x = sp_x[1];
  const int *colind_x = sp_x+2, *row_x = sp_x + 2 + ncol_x+1;
  int i, el;
  if (tr) {
    // loop over the columns of x
    for (i=0; i<ncol_x; ++i) {
      // loop over the non-zeros of x
      for (el=colind_x[i]; el<colind_x[i+1]; ++el) {
        z[i] += x[el] * y[row_x[el]];
      }
    }
  } else {
    // loop over the columns of x
    for (i=0; i<ncol_x; ++i) {
      // loop over the non-zeros of x
      for (el=colind_x[i]; el<colind_x[i+1]; ++el) {
        z[row_x[el]] += x[el] * y[i];
      }
    }
  }
}

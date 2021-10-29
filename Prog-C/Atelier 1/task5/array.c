
/**
 * Computes the sum of array values
 *      sum = (values[0] + ... + values[values.length-1]);
 *      
 * @param values, an array of values
 * @return the sum of the values in the array
 */
int array_sum(int* values, int off, int len) {
  int sum = 0;
  for (int i = off; i < len; ++i) {
    sum += values[i];
  }
  return sum;
}

/**
 * Computes the sum of array values
 *      sum = (values[0] + ... + values[values.length-1]);
 *      
 * @param values,
 *          an array of values
 * @return the sum of the values in the array
 */
float array_sumf(float* values, int off, int len) {
  float sum = 0;
  for (int i = off; i < len; ++i) {
    sum += values[i];
  }
  return sum;
}

/**
 * Computes the average of array values
 *      avg = (values[0] + ... + values[values.length-1])/values.length;
 *      
 * @param values,
 *          an array of values
 * @return the average of the values in the array
 */
int array_average(int* values, int off, int len) {
  int sum = array_sum(values, off, len);
  return sum / len;
}

/**
 * Computes the average of array values
 *      avg = (values[0] + ... + values[values.length-1])/values.length;
 *      
 * @param values,
 *          an array of values
 * @return the average of the values in the array
 */
float array_averagef(float* values, int off, int len) {
  float sum = array_sumf(values, off, len);
  return sum / len;
}

/**
 * Copies values from the source array into the destination array
 * 
 * @param dst,
 *          the destination array
 * @param dstOffset,
 *          the offset where to start copying to, in the destination array
 * @param src,
 *          the source array
 * @param offset,
 *          the offset where to start copying from, in the source array
 * @param length,
 *          the number of values copied
 */
void array_copy(int* dst, int dstOffset, int* src, int offset, int length) {
  for (int i = offset; i < offset + length; ++i){
    dst[i - offset + dstOffset] = src[i];
  }
}

/**
 * Copies values from the source array into the destination array
 * 
 * @param dst,
 *          the destination array
 * @param dstOffset,
 *          the offset where to start copying to, in the destination array
 * @param src,
 *          the source array
 * @param offset,
 *          the offset where to start copying from, in the source array
 * @param length,
 *          the number of values copied
 */
void array_copyf(float* dst, int dstOffset, float* src, int offset, int length) {
  for (int i = offset; i < offset + length; ++i){
    dst[i - offset + dstOffset] = src[i];
  }
}

/**
 * Sorts the values in the given array
 * 
 * @param array
 *          of values to sort
 */
void array_sortf(float* array, int length) {
  for (int i = 0; i < length; ++i){
    for (int j = i + 1; j < length; ++j) {
      if(array[i] > array[j]) {
        float temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}

/**
 * Sorts the values in the given array
 * 
 * @param array
 *          of values to sort
 */
void array_sort(int* array, int length) {
  for (int i = 0; i < length; ++i){
    for (int j = i + 1; j < length; ++j) {
      if(array[i] > array[j]) {
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
      }
    }
  }
}




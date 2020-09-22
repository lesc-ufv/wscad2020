
float elapsed_time;
cudaEvent_t start, stop;                             //# Declara dois eventos

void time_start(int id = 0){
  cudaEventCreate(&start);                          //# Irá marcar o inicio da execucao
  cudaEventCreate(&stop);                           //# Irá  marcar o final da execucao
  cudaEventRecord(start, id);                        //# insere na fila 
}

void time_end(int id = 0) {
  cudaEventRecord(stop, id);                          //# insere na fila
  cudaEventSynchronize(stop);                        //# espera terminar
  cudaEventElapsedTime(&elapsed_time, start, stop);  //# calcula
}

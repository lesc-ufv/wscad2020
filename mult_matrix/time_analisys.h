float elapsed_time;
cudaEvent_t _start, _stop;                             //# Declara dois eventos

void time_start(){
  cudaEventCreate(&_start);                          //# Irá marcar o inicio da execucao
  cudaEventCreate(&_stop);                           //# Irá  marcar o final da execucao
  cudaEventRecord(_start, 0);                        //# insere na fila 
}

void time_end() {
  cudaEventRecord(_stop, 0);                          //# insere na fila
  cudaEventSynchronize(_stop);                        //# espera terminar
  cudaEventElapsedTime(&elapsed_time, _start, _stop);  //# calcula
}

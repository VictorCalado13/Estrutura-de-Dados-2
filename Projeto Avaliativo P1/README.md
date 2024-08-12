# Projeto Avaliativo P1

1° Etapa:

  Consiste em fazer um programa que deve ler uma entrada que tem o seguinte formato:
  - Primeira linha o tamanho do vetor (N>0);
  - As linhas seguintes informarão um número inteiro e em seguida o conjunto ao qual pertencem (A ou B);

  Como sugestão, cada conjunto pode ser representado internamente como um vetor de tamanho N; Serão informados N valores para cada conjunto. Exemplo: 3 200 A 300 A 100 B 300 B 50 A 25 B.
 
2° Etapa:
  Em seguida, é necessario implementar uma ordenação de modo em que primeiro o conjunto A com o algoritmo InsertionSort e em seguida o Conjunto B com SelectionSort. Durante a ordenação deve imprimir cada troca feita em 1 linha no seguinte formato:
  - “Trocou:<número> com <número>”. Exemplo hipotético: InsertionSort Trocou: 55 com 22 Trocou: 18 com 90 Trocou: 350 com 25 ... SelectionSort Trocou: 155 com 222 Trocou: 128 com 900;
  - 
3° Etapa:
  Ao final das impressões anteriores deve imprimir o número de comparações e trocas feitas em cada algoritmo para aquela entrada específica como no exemplo hipotético a seguir:
  - InsertionSort:trocas:138-Comparações:450 SelectionSort:trocas:80-Comparações:447

4° Etapa:
  Por fim, o algoritmo deve ler a próxima entrada. Se o primeiro valor for zero o algoritmo deve parar.

# Ferramentas Utilizadas:
- CLion IDE

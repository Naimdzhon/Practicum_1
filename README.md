# Practicum_1

УСЛОВИЕ:
Даны s(строка) и натуральные числа k,l, такие что 0 <= l < k. Вывести минимальное число n, равное l по модулю k, такое что L(s) содержит слова длины n.

АЛГОРИТМ РЕШЕНИЯ:   
Проверим фун-цией Is_RPN(), является ли s -> регулярным выражением в ОПЗ(обратной польской записи) :  

2)Если не является, выводим "ERROR";  

1)Если является: Воспользуемся, алгоритмом(Build_Reg_Expr()) распознавания выражения, записанного обратной польской записью. Создадим стэк(exps), где эл-ты стэка имеют тип RegExp, хранящий в своих полях, строку(str) описывающую рег-ое выражение в ОПЗ и вектор(length, длины k), где length[i] -> минимальное число, равное i по модулю k, такое что L(str) содержит слова длины length[i] (если таких слов, нет--> length[i] = -1). Пройдёмся по исходной строке s:  

  [1] Если мы встретим операнд, создадим эл-т RegExp соответ. данному операнду и пушаем её в конец стэка: 
  
  [2] Если мы встрели '+' или '.', удаляем последние два эл-та(сохраняя их) и пушаем новый обновлённый эл-т, который легко описывается. 

  [3] Если мы встретили Звезду Клини, и нам нужно провести эту операцию над рег-ым выр-ем Х, то нам достаточно заменить Х* на ((1Х+)^(k)(.)^(k-1) -> это в ОПЗ, а в нормальном виде оно выглядит так : (1+X).(1+X). ..... .(1+X), где (1+Х) -> повторяется k-раз.  
  
              
ТЕСТЫ: После откладки программы, можете прогнать некоторые тесты, скопиров из Input.  

Input : ab+c.aba.*.bac.+.+* 3 1   ->       Output : 4

Input : acb..bab.c.*.ab.ba.+.+*a. 3 0  ->  Output : INF

Input : ab+c.aba.*.bac.+.+* 3 2        ->  Output :  2

Input : abcb...ab.+* 4 3            ->     Output : INF

Input : accb...1+ 4 0               ->     Output : 0

Input : abcb...aab..+* 6 5          ->     Output : 11

Input : abc*.+bac.+. 1 0             ->    Output : 2

Input : acb..bab.c.*.ab.ba.+.+*a 4 3   ->    Output : ERROR

Input : aba.*.a.*ab1+.. 5 4   ->   Output : 4  



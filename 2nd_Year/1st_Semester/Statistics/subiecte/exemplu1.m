N = 1000;

countA = 0;
countNotA = 0;
countB = 0;
for i = 1 : N
  v = extragere();
  if (conditieA(v))
    countA++;
  else
    countNotA++;
    if (conditieB(v))
      countB++;
    endif
  endif
endfor
fprintf('Probabilitatea estimata pentru A: %f\n', countA / N)
fprintf('Probabilitatea estimata pentru B: %f\n', countB / N)
fprintf('Probabilitatea estimata pentru !A: %f\n', countNotA / N)

cazuriTotale = 20 * 19 * 18; % initial 20 de optiuni, dupa 19, dupa 18
cazuriFavorabileA = nchoosek(10, 3) * factorial(3) + nchoosek(5, 3) * factorial(3) + nchoosek(5, 3) * factorial(3);
cazuriFavorabileB = 10 * 5 * 5 * factorial(3); % cate o bila din fiecare si configuratia permutata

fprintf('Probabilitatea teoretica pentru A: %f\n', cazuriFavorabileA / cazuriTotale)
fprintf('Probabilitatea teoretica pentru B: %f\n', cazuriFavorabileB / cazuriTotale)
fprintf('Probabilitatea teoretica pentru !A: %f\n', 1 - cazuriFavorabileA / cazuriTotale)
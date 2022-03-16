function p = frecventa(N, conditie, latura = 20)
  p = 0;
  favorabil = 0;
  clf; hold on; axis square; axis off;
  rectangle('Position', [0 0 latura latura])
  for i = 1 : N
    pct = puncteRandom(latura);
    if conditie(pct, latura)
      favorabil++;
    endif
  endfor
  p = favorabil / N;
endfunction
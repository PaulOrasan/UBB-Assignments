N = 1000;

zaruri = randi(6, 4, N);

sumeZaruri = sum(zaruri);

sumePosibile = 4 : 24;

frecv_abs = hist(sumeZaruri, sumePosibile);

disp('i)')
matrice = [sumePosibile; frecv_abs]

disp('ii)')

clf; hold on; grid on;
xticks(sumePosibile); xlim([3 25]);
yticks(0 : 0.01 : 0.15);
bar(sumePosibile, frecv_abs / N, "hist", "facecolor", "g");

disp('iii)')
sume = [];
for i = 1:6
  for j = 1:6
    for k = 1:6
      for h = 1:6
        sume = [sume sum([i j k h])];
      endfor
    endfor
  endfor
endfor

frecv_abs_teoretica = hist(sume, sumePosibile);
matrice = [sumePosibile; frecv_abs_teoretica]

bar(sumePosibile, frecv_abs_teoretica / N, "hist", "facecolor", "y");

set(findobj('type', 'patch'), 'facealpha', 0.7);

legend('frecvente relative', 'probabilitati');

disp ('iv)')
prob_cond_sim = sum(sumeZaruri <= 20 & sumeZaruri >= 10) / sum(sumeZaruri <= 20)
prob_cond_teor = sum(sume <= 20 & sume >= 10) / sum(sume <= 20)

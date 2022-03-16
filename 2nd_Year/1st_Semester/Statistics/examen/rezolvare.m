urna = [ones(1, 4) ones(1, 5) .* 2 ones(1, 2) .* 3 ones(1, 3) .* 4];

disp('a) cu returnare')
simuleaza(urna, @extragereCuReturnare);

disp('b) fara returnare')
simuleaza(urna, @extragereFaraReturnare);
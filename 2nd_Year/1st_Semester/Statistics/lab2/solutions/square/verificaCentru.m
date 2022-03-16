function out = verificaCentru(pct, latura)
  dist = [pdist([pct; [0, 0]]), pdist([pct; [0, latura]]), pdist([pct; [latura, 0]]), pdist([pct; [latura, latura]])];
  mn = min(dist);
  out = pdist([pct; [latura / 2, latura / 2]]) <= mn;
endfunction
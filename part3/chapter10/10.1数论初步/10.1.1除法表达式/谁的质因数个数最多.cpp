  int ppp, pq, sf=0,mx=-1;
  for(int pppp=988880000; pppp>800000000; pppp--){ 
    ppp=pppp;
    pq=(int)sqrt((double)ppp+0.5);
    for(int i = 2; i <= pq; i++) if(ppp%i==0) {
      while(ppp%i==0) ppp/=i;
      sf++;
      if(ppp==0) break;
    }  
    if(sf>mx) {mx=sf; t = pppp;}
    sf=0;
  }  
  printf("mx=%d(%d)\n", mx, t);

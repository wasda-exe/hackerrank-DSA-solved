int pageCount(int n, int p) {
    int flipFront = 0;
    int flipBack = 0;
    flipFront = p / 2;
    if(n % 2 == 1)
    {
        flipBack = (n - p) / 2;
    }
    // in this case, subconsciously add 1 page at the end
    // to fill that weird blank page. Then, when n become n + 1
    // You are free to continue as normal.
  
    // everyone solved the same way I did, seemingly. Nice.
    else
    {
        flipBack = (n - p + 1) / 2;        
    }
    return min(flipBack, flipFront);
}

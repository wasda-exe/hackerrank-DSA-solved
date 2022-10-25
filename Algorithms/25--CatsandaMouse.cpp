// Complete the catAndMouse function below.
string catAndMouse(int x, int y, int z) {
    string s;
    if(abs(x - z) == abs(y - z))
    {
        s = "Mouse C";
    }
    // abs(x - z) distance of Cat A
    // basically, if abs(x - z) < abs(y - z)
    // then Cat A wins, because it has lesser distance
    else if(abs(x - z) > abs(y - z))
    {
        s = "Cat B";
    }
    else
    {
        s = "Cat A";
    }
    return s;
}

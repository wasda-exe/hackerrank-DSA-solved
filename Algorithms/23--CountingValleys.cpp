int countingValleys(int steps, string path) {
    int valCnt = 0;
    int alt = 0;
    for(int i = 0; i < path.size(); i++)
    {
        // valley only after initial baseline (guaranteed)
        // if going down removed us from baseline
        // if(alt == 0 && path[i] == 'D')
        // {
        //     valCnt++;
        // }
        if(path[i] == 'U')
        {
            alt++;
        }
        else
        {
            alt--;
        }
        // if going up returned us to baseline
        if(alt == 0 && path[i] == 'U')
        {
            valCnt++;
        }
    }
    return valCnt;
}

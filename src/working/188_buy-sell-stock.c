int maxProfit(int k, int* prices, int pricesSize)

{

    int max = 0, maxProp = 0, highest = 0, last = 0;

    int stepProf = 0;

    int transNum = 0, transIdx = 0, transProf = 0;

    int noTrans = 0;

    int propDone = 0;

    

    if( pricesSize < 2 || k < 1 )

      return max;

    

    int end = pricesSize-1;

    int next = end-1;

    // for entire input array

    while( end > 0 )  

    {

      // scan left and compute profit for this step

      while( next >= 0 )

      {

        int price = prices[end];

        stepProf = price - prices[next];

        // if this step's profit is higher than the previous highest, save it

        if( (stepProf > 0) && (stepProf >= transProf) )

        {

          transProf = stepProf;

          transIdx = next;

        }

        if( transIdx == 0 )

          propDone = 1;

        --next;

      }

      

      // update profit for this proposal

      maxProp += transProf;

      if(maxProp > 0)

        ++transNum;

      

      // check whether this proposal's profit is higher than the max so far

      if( (transNum <=k) && (maxProp > max) )

      {

        max = maxProp;

      }

      

      // move to next location in proposal to check

      if( propDone )

      {

        --end;

        transNum = 0;

        maxProp = 0;

      }

      else

      {

        end = transIdx-1;

        transIdx = 0;

      }

      next = end-1;



      // reset per-proposal variables

      transProf = 0;

      

    }

    

    return max;

}



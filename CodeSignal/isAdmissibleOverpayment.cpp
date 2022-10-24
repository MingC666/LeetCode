bool solution(vector<double> prices, vector<string> notes, double x) {
    int n = prices.size();
    
    double overpay = 0;
    for(int i=0; i<n; ++i)
    {
      if(notes[i][0]!='S')
      {
        size_t index = notes[i].find('%');
        double percent = stold(notes[i].substr(0, index+1));
        overpay += (notes[i].find("hi") != std::string::npos) ?
                prices[i] - (100*prices[i])/(100+percent) : // else
                prices[i] - (prices[i]*100/(100-percent));
        
      }
    }
    return x-overpay >= 0-0;
}




bool solution1(vector<double> prices, vector<string> notes, double x) {
    int n = prices.size();
    
    double overpay = 0;
    for(int i=0; i<n; ++i)
    {
        double origin_price;
        if(notes[i].find("hi") != std::string::npos)
        {
            size_t index = notes[i].find('%');
            double percent = stold(notes[i].substr(0, index+1));
            origin_price = prices[i]*100 / (100+percent);
            overpay += prices[i] - origin_price;
        }
        else if(notes[i].find("lo") != std::string::npos)
        {
            size_t index = notes[i].find('%');
            double percent = stold(notes[i].substr(0, index+1));
            origin_price = prices[i]*100 / (100-percent);
            overpay -= (origin_price - prices[i]);
        }
        else {
            // do nothing
        }
    }
    return x >=overpay;
}


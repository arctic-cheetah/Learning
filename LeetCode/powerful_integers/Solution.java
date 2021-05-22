//Initial solution to Powerful_integers (recursive)
class Solution {
    
    List<Integer> num = new ArrayList<Integer>();
    
    //Helper methods
    public void addPowerfulNum(int x, int y, int bound) {
        int i = 0;
        int tempNum = 0;
        
        if (bound == 1) {
            return;
        } 
        if (bound == 2) {
            num.add(2);
            return;
        }
        //Check if x or y is 1
        else if (x == 1 && y != 1) {
            while ((tempNum = powOfNum(y, i)) <= bound) {
                if (tempNum + 1 == bound) {
                    num.add(bound);
                    break;
                }
                i +=1;
            }
        }
        else if (x != 1 && y == 1) {
            while ((tempNum = powOfNum(x, i)) <= bound) {
                if (tempNum + 1 == bound) {
                    num.add(bound);
                    break;
                }
                i +=1;
            }
        }
        else if (x == 1 && y == 1) {
            num.add(2);
            return;
        } 
        
        else if (bound <= x && bound <= y) {
            //don't add
        }
        else if (bound >= x && bound <= y) {
            while ((tempNum = powOfNum(x, i)) <= bound) {
                if (tempNum + 1 == bound) {
                    num.add(bound);
                    break;
                }
                i +=1;
            }

        }
        else if (bound <= x && bound >= y) {
            while ((tempNum = powOfNum(y, i)) <= bound) {
                if (tempNum + 1 == bound) {
                    num.add(bound);
                    break;
                }
                i +=1;
            }            
        }
        else {
            boolean NeedExit = false;
            int tempNum2 = 0;
            while ((tempNum = powOfNum(x, i)) <= bound && !NeedExit) {
                int j = 0;
                while ((tempNum2 = powOfNum(y, j)) <= bound) {
                    if (tempNum + tempNum2 == bound) {
                        num.add(bound);
                        NeedExit = true;
                        break;
                    }
                    j +=1;
                }

                i +=1;
            }

        }   
        addPowerfulNum(x, y, bound -=1);
    }
    
    public int powOfNum (int num, int end) {
        //Cases 
        if (num == 1) {
            return 1;
        }
        if (end == 0) {
            return 1;
        }
        int result = 1;
        for (int i = 0; i < end; i +=1) {
            result *= num;
        }
        return result;
    }
    
    //Main function here
    public List<Integer> powerfulIntegers(int x, int y, int bound) {
        
        //bound is 0 or 1
        if (bound == 0 || bound == 1) {
            return num;
        }
        else {
			addPowerfulNum(x, y, bound);
        }
        return num;
    }
}

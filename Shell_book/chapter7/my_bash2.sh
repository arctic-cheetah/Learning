echo "" | awk '
{
    x = 0
    while (x < 4) {
        print x
        x +=1
    }
}
'
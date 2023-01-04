#include <bits/stdc++.h>
using namespace std;

int main()
{
    int val, dis, n;
    cin >> val;
    for (int j = 1; j <= val; j++)
    {
        cin >> dis >> n;
        int count = 0;
        int x, buffer;
        char d, d_last;
        cin >> x >> d;
        count = x / dis;
        buffer = x % dis;
        d_last = d;
        cout << x << " " << d << " " << count << " " << buffer << endl;
        for (int i = 1; i < n; i++)
        {
            cin >> x >> d;
            if (d == d_last)
            {
                if ((x + buffer) / dis != 0)
                {
                    count += 1 + ((x - dis + buffer) / dis);
                    buffer = (x - dis + buffer) % dis;
                }
                else
                {
                    buffer = buffer + x;
                }
                d_last = d;
            }
            else
            {
                if (buffer - x <= 0)
                {
                    if (count != 0)
                    {
                        if (buffer == 0)
                        {
                            count += ((x - buffer) / dis) - 1;
                            buffer = (x - buffer) % dis;
                            d_last = d;
                        }
                        else
                        {
                            count += ((x - buffer) / dis) - 1;
                            buffer = (x - buffer) % dis;
                            d_last = d;
                        }
                    }
                    else
                    {
                        count += 1 + ((x - buffer) / dis);
                        buffer = (x - buffer) % dis;
                        d_last = d;
                    }
                }
                else
                {
                    buffer = dis - buffer + x;
                    d_last = d;
                }
            }
            cout << x << " " << d << " " << count << " " << buffer << endl;
        }

        cout << "Case #" << j << ": " << count << endl;
    }

    return 0;
}
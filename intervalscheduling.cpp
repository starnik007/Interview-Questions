#include <bits.\stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter number of jobs" << endl;
    cin >> n;
    int f[100] = {}, s[100] = {};
    int ft[100] = {};
    for (int i = 0; i < n; i++)
    {
        cout << "Enter start time :";
        cin >> s[i];
        cout << "Enter Finish time: " << endl;
        cin >> f[i];
        ft[i] = f[i];
    }

    sort(ft, ft + n);
    int k = 0;
    int st[100] = {};
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (f[j] == ft[i])
            {
                st[k] = s[j];
                f[j] = 0;
                k++;
                break;
            }
        }
    }
    cout << endl;

    int i = 0;
    cout << "Set of jobs with maximum cardinality which can be scheduled \n";
    cout << st[0] << "," << ft[0] << "   ";

    for (int j = i + 1; j < n; j++)
    {
        if (st[j] > ft[i])
        {
            cout << "The starting and finishing time is of selected interval is: ";
            cout << st[j] << "," << ft[j] << "  ";
            i = j;
        }
    }
    cout << "\n";
    int incomp = 0, comp = 0;
    int maxcon = 0, mincon = 0, indmax = 0, indmin = 0;
    for (int i = 0; i <= n - 1; i++)
    {

        incomp = 0;
        comp = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (st[j] < ft[i])
            {
                incomp++;
            }
            else
            {
                comp++;
            }
        }
        maxcon = max(maxcon, incomp);
        mincon = max(mincon, comp);

        if (maxcon == incomp)
        {
            indmax = i;
        }
        if (mincon == comp)
        {
            indmin = i;
        }

        cout << "For job " << i << " number of conflicting jobs are " << incomp << "\n";
    }
    cout << "Job with maximum conflicts is with starting time " << st[indmax] << " and finish time " << ft[indmax] << "\n";
    cout << "Job with minimum conflicts is with starting time " << st[indmin] << " and finish time " << ft[indmin] << "\n";
}

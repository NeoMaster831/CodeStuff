#include <iostream>
#include "testlib.h"

using namespace std;
#define int long long



signed main(signed argc, char* argv[]) {

    registerTestlibCmd(argc, argv);
    int test_count = inf.readInt();

    for (int t = 1; t <= test_count; t++) {

        setTestCase(t);

        inf.readEoln();
        int N = inf.readInt();
        inf.readSpace();
        int L = inf.readInt();
        inf.readEoln(); inf.readEof();

        int Participant = ouf.readInt();
        int Jury = ans.readInt();
        ouf.readEoln(); ans.readEoln();

        if (Jury != Participant) quitf(_wa, "Expected %s, but found %s", Jury, Participant);
        if (Participant != -1) {
            int parans = Participant;
            int tomul = parans;

            int park = 0;
            for (int i = 1; i <= N; i++) {
                int para = ouf.readInt();
                ouf.readSpace();

                if (para == 0) quitf(_wa, "Wrong answer: found 0");
                park += para * tomul;
                tomul *= parans;
            }
    
            if (park != L) quitf(_wa, "Wrong answer: Expected %d, but found %d", L, park);
            ouf.readEoln();
        }
    }

    ans.readEof();
    inf.readEof();
    ouf.readEof();
    
    quitf(_ok, "OK");
    return 0;
}
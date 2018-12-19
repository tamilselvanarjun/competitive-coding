#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--) {
		long double px, py, pz, qx, qy, qz, dx, dy, dz, cx, cy, cz, r;
		cin >> px >> py >> pz;
		cin >> qx >> qy >> qz;
		cin >> dx >> dy >> dz;
		cin >> cx >> cy >> cz >> r;

		// time to make shit go crazy
		qx-=px;
		qy-=py;
		qz-=pz;

		cx-=px;
		cy-=py;
		cz-=pz;

		long double c, a, b, A, B, C;
		c = cx*cx + cy*cy + cz*cz;
		a = cx*qx + cy*qy + cz*qz;
		b = cx*dx + cy*dy + cz*dz;

		A = (c - r*r)*(dx*dx + dy*dy + dz*dz) - b*b;
		B = (c - r*r)*(qx*dx + qy*dy + qz*dz) - a*b;
		B = 2*B;
		C = (c - r*r)*(qx*qx + qy*qy + qz*qz) - a*a;

		long double ans1, ans2;
		if(abs(A) < 1e-6) {
			cout << -C/B << endl;
		}
		else {
			cout << A << " " << B << " " << C << endl;
			ans1 = (-B + sqrt(B*B - 4*A*C))/(2*A);
			ans2 = (-B - sqrt(B*B - 4*A*C))/(2*A);
			if(ans1 > 0)
				cout << ans1 << endl;
			else
				cout << ans2 << endl;
		}

	}
	return 0;
}
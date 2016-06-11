#include <bits/stdc++.h>
using namespace std;
struct course {
    int start;
    int end;
};

int *successors,N;
vector<course> mainCourses;

bool mySort(course a, course b) {
		if(a.end < b.end)
			return true;
		else if(a.end > b.end)
			return false;
		else if(a.end == b.end) {
			if(a.start > b.start)
				return true;
			return false;
		}
}

int binarySearch(int start, int size) {
    int index,beg=0,end=size;
    while(beg<=end) {
        index = (beg+end)/2;
        if(index==0) return 0;
        if(mainCourses[index].start >= start and mainCourses[index-1].start < start )
            return index;
        else if(mainCourses[index].start < start) {
            beg = index+1;
        }
        else if(mainCourses[index-1].start >= start) {
            end = index-1;
        }
    }
    return -1;
}

void findMaxCourses(int start, int end, int size) {
		int startTime,endTime=0,attended=0;
        int i = binarySearch(start,size);
        for(;i<size;i++) {
            if(mainCourses[i].end > end)          //class finishes later, no classes can be attended after that
                break;
            if(mainCourses[i].start >= endTime) {
                endTime = mainCourses[i].end;
                attended++;
                if(successors[i]==-1)
                    break;
                i = successors[i]-1;
                // cout<<"attended "<<attended<<endl;
            }
            else {
                printf("%s\n","Error\n" );
            }
        }
        printf("%d\n",attended);
}

int main() {
    course* c;
    int start,end;
    int n,q;
    int kj = scanf("%d %d\n",&n,&q);
		c = new course[n];
		for(int i = 0; i<n;i++) {
				int ts,te;
				// cin>>ts>>te;
                int temp = scanf("%d %d\n",&ts,&te);
				c[i].start = ts;
				c[i].end = te;
		}
		sort(c,c+n,mySort);

        mainCourses.push_back(c[0]);
        for(int i=1;i<n;i++) {
            if(mainCourses[mainCourses.size()-1].start < c[i].start) {
                mainCourses.push_back(c[i]);
            }
        }
        N = mainCourses.size();

        successors = new int[N];
        for(int i=0;i<N;i++) {
            int j;
            for(j=i+1;j<N;j++) {
                if(mainCourses[j].start >= mainCourses[i].end) {
                    successors[i] = j;
                    break;
                }
            }
            if(j==N)
                successors[i] = -1;
        }

		for(int i=0;i<q;i++) {
                int ad = scanf("%d %d\n",&start,&end);
				findMaxCourses(start,end,N);
		}
        delete[] c,successors;
}

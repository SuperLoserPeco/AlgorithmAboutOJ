#include <cstdio>
#include <vector>
#include <cmath>

#define PI atan( 1.0 ) * 4

using namespace std;

struct Point {
    double x;
    double y;
    Point (double x = 0, double y = 0): x(x), y(y) {}
};
typedef Point Vector;

Vector operator + (Vector A, Vector B) {
    return Vector(A.x + B.x, A.y + B.y);
}
Vector operator - (Vector A, Vector B) {
    return Vector(A.x - B.x, A.y - B.y);
}
Vector operator * (Vector A, double p) {
    return Vector(A.x * p, A.y * p);
}
Vector operator / (Vector A, double p) {
    return Vector(A.x / p, A.y / p);
}

bool operator < (const Point& a, const Point& b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

const double eps = 1e-10;
int dcmp(double x) {
    if(fabs(x) < eps) return 0;
    else return x < 0 ? -1 : 1;
} 

bool operator == (const Point& a, const Point& b) {
    return dcmp(a.x - b.x) == 0 && dcmp(a.y - b.y) == 0;
}

double Dot(Vector A, Vector B) {
    return A.x * B.x + A.y * B.y;
}
double Length(Vector A) {
    return sqrt( Dot(A, A) );
}
double Angle(Vector A, Vector B) {
    return acos(Dot(A, B) / Length(A) / Length(B));
}
double Cross(Vector A, Vector B) {
    return A.x * B.y - A.y * B.x;
}
Vector Rotate(Vector A, double rad) {
    return Vector(A.x * cos(rad) - A.y * sin(rad), 
                    A.x * sin(rad) + A.y * cos(rad));
}

Point GetLineIntersection(Point P, Vector v, Point Q, Vector w) {
    Vector u = P - Q;
    double t = Cross(w, u) / Cross(v, w);
    return P + v * t;
}

Point p[3];

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 3; i++)
            scanf("%lf%lf", &p[i].x, &p[i].y);
        
        Vector BA = p[0] - p[1];
        Vector AB = p[1] - p[0];
        Vector BC = p[2] - p[1];
        Vector CB = p[1] - p[2];
        Vector AC = p[2] - p[0];
        Vector CA = p[0] - p[2];

        double angleABC = Angle(BA, BC);
        double angleACB = Angle(CA, CB);
        double angleBAC = Angle(AB, AC);

        Vector BD;
        Vector CD;
        Vector AE;
        Vector CE;
        Vector BF;
        Vector AF;

        if(dcmp(Cross(CB, CA)) == -1) {
            BD = Rotate(BC, angleABC / 3);
            CD = Rotate(CB, 2.0 * PI - angleACB / 3);
        }
        else {
            BD = Rotate(BC, 2.0 * PI - angleABC / 3);
            CD = Rotate(CB, angleACB / 3);
        }

        if(dcmp(Cross(AB, AC)) == -1 ) {
            BF = Rotate(BA, angleABC / 3);
            AF = Rotate(AB, 2.0 * PI - angleBAC / 3);
        }
        else {
            BF = Rotate(BA, 2.0 * PI - angleABC / 3);
            AF = Rotate(AB, angleBAC / 3);
        }

        if(dcmp(Cross(BC, BA)) == -1) {
            AE = Rotate(AC, angleBAC / 3);
            CE = Rotate(CA, 2.0 * PI - angleACB / 3);
        }
        else {
            AE = Rotate(AC, 2.0 * PI - angleBAC / 3);
            CE = Rotate(CA, angleACB / 3);
        }

        Point D = GetLineIntersection(p[1], BD, p[2], CD);
        Point E = GetLineIntersection(p[0], AE, p[2], CE);
        Point F = GetLineIntersection(p[0], AF, p[1], BF);
        printf("%lf %lf %lf %lf %lf %lf\n", 
                    D.x, D.y, E.x, E.y, F.x, F.y);
    }
}
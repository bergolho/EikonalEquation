#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N 10 // size of grid
#define MAX_VAL 10.0 // maximum value of u(x)

double u[N][N]; // solution array
double dx = 1.0; // grid spacing
double dt = 0.1; // time step

// Compute the value of u(x,y) at the point (i,j)
void update_point(int i, int j) {
    double up, down, left, right, C;
    up = i > 0 ? u[i-1][j] : MAX_VAL;
    down = i < N-1 ? u[i+1][j] : MAX_VAL;
    left = j > 0 ? u[i][j-1] : MAX_VAL;
    right = j < N-1 ? u[i][j+1] : MAX_VAL;
    C = dx / sqrt(pow(fmax(up,down)-fmin(up,down),2) + pow(fmax(left,right)-fmin(left,right),2));
    u[i][j] = fmin(u[i][j], fmin(up, fmin(down, fmin(left, right))) + C * dt);
}

// Solve the Eikonal equation using the Fast Marching Method
void fast_marching() {
    // Initialize solution array
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            if(i==0 || i==N-1 || j==0 || j==N-1) {
                u[i][j] = 0.0; // boundary condition
            } else {
                u[i][j] = MAX_VAL; // unknown
            }
        }
    }
    // March forward in time
    for(int n=0; n<100; n++) {
        for(int i=1; i<N-1; i++) {
            for(int j=1; j<N-1; j++) {
                update_point(i, j);
            }
        }
    }
}

int main() {
    // Solve the Eikonal equation
    fast_marching();
    // Print the solution
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            printf("%f ", u[i][j]);
        }
        printf("\n");
    }
    return 0;
}

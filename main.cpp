#include <iostream>
#include "lbfgs.h"
using namespace std;
float evaluate(
        void *instance,
        const float *x,
        float *g,
        const int n,
        const float step
) {
    int i;
    float fx = 0.0;
    for (i = 0; i < n; i += 2) {
        float t1 = 1.0 - x[i];
        float t2 = 10.0 * (x[i + 1] - x[i] * x[i]);
        g[i + 1] = 20.0 * t2;
        g[i] = -2.0 * (x[i] * g[i + 1] + t1);
        fx += t1 * t1 + t2 * t2;
    }
    return fx;
}
int progress(
        void *instance,
        const float *x,
        const float *g,
        const float fx,
        const float xnorm,
        const float gnorm,
        const float step,
        int n,
        int k,
        int ls
)
{
    printf("Iteration %d:\n", k);
    printf("  fx = %f, x[0] = %f, x[1] = %f\n", fx, x[0], x[1]);
    printf("  xnorm = %f, gnorm = %f, step = %f\n", xnorm, gnorm, step);
    printf("\n");
    return 0;
}






int main() {
    cout << "Hello, World!" << endl;
    int i, ret = 0;
    float fx;
    int N=100;
    float *x = new float[N];
    lbfgs_parameter_t param;

    /* Initialize the variables. */
    for (i = 0;i < N;i += 2) {
        x[i] = -1.2;
        x[i+1] = 1.0;
    }
    /* Initialize the parameters for the L-BFGS optimization. */
    lbfgs_parameter_init(&param);
    /*param.linesearch = LBFGS_LINESEARCH_BACKTRACKING;*/
    /*
        Start the L-BFGS optimization; this will invoke the callback functions
        evaluate() and progress() when necessary.
     */
    ret = lbfgs(N, x, &fx, evaluate, progress, NULL, &param);
    /* Report the result. */
    printf("L-BFGS optimization terminated with status code = %d\n", ret);
    printf("  fx = %f, x[0] = %f, x[1] = %f\n", fx, x[0], x[1]);
    delete [] x;
    return 0;
}
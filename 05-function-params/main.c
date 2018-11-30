#include <stdio.h>

void evaluate(void (*f)()) { printf("evaluate: "); f(); }

void evalAny2(void fn())    			 	   { printf("evalAny2:  ");fn();  	 } // that works too
void evalAny(void (*fn)())    			 	   { printf("evalAny:  "); fn();  	 }
void eval2  (void (*fn)(int a, int b, int c)) { printf("eval2:    "); fn(1,2,3); }

void cb() { printf("cb()\n"); };
void cbWArgs(int x, int y, int z) { 
	printf("cbWArgs() %d %d %d\n", x, y, z); 
};
int icb() {printf("icb()\n"); return 42;}

int main(int argc, char const *argv[])
{
	// -std=c++11, RHalterman page 655
	//evaluate([]()->void{ printf("this is callback\n"); });
	
	void (*func)(int, int, int);
	void (*func2)();
	
	func = cbWArgs; // that works
	func2 = &cb;    // that works too

	evalAny(func);
	evalAny(func2);

	evaluate(cb);
	evalAny(cbWArgs);
	eval2(cbWArgs);
	// evalAny(icb); // works, but warns implicit conversion error int(*)()/void(*)()
	evalAny((void(*)())icb);

	// evalAny(toBeEvaluated2);

	return 0;
}
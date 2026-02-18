#if defined __linux__
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/CollatzConjecture.h"
#elif defined _WINE
#include "/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "/home/codeleaded/System/Static/Library/CollatzConjecture.h"
#elif defined _WIN32
#include "F:/home/codeleaded/System/Static/Library/WindowEngine1.0.h"
#include "F:/home/codeleaded/System/Static/Library/CollatzConjecture.h"
#elif defined(__APPLE__)
#error "Apple not supported!"
#else
#error "Platform not supported!"
#endif


const int count = 100;
CollatzConjecture wrp;

void Setup(AlxWindow* w){
	wrp = CollatzConjecture_New(F32_PI * 0.1f,1.0f);
}
void Update(AlxWindow* w){
	CollatzConjecture_Update(&wrp);

	Clear(BLACK);

	CollatzConjecture_Render(&wrp,WINDOW_STD_ARGS,0.0f,0.0f);
}
void Delete(AlxWindow* w){
	CollatzConjecture_Free(&wrp);
}

int main(){
    if(Create("Fire Pool",1900,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}
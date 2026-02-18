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

CollatzConjecture cc;

void Setup(AlxWindow* w){
	cc = CollatzConjecture_New(10000U,10000U,F32_PI * 0.1f,1.0f);
}
void Update(AlxWindow* w){
	TransformedView_HandlePanZoom(&cc.tv,w->Strokes,GetMouse());

	if(Stroke(ALX_KEY_W).PRESSED){
		cc.depth++;
	}
	if(Stroke(ALX_KEY_S).PRESSED){
		if(cc.depth > 0U) cc.depth--;
	}
	if(Stroke(ALX_KEY_E).PRESSED){
		CollatzConjecture_Update(&cc);
	}

	Clear(BLACK);

	CollatzConjecture_Render(&cc,WINDOW_STD_ARGS,0.0f,0.0f);

	CStr_RenderAlxFontf(WINDOW_STD_ARGS,GetAlxFont(),0.0f,0.0f,RED,"Depth: %d",cc.depth);
}
void Delete(AlxWindow* w){
	CollatzConjecture_Free(&cc);
}

int main(){
    if(Create("Fire Pool",1900,1000,1,1,Setup,Update,Delete))
        Start();
    return 0;
}
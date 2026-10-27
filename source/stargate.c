/* Stargate Slit-Scan - native 64-bit Windows screen saver.
 * Standalone Win32 + OpenGL 2 shader; no C runtime / external assets.
 * Original recovered artwork is embedded as 1024x256 RGB textures.
 */
#define WINAPI __attribute__((ms_abi))
#define API __declspec(dllimport)
typedef void *HANDLE; typedef HANDLE HWND,HINSTANCE,HDC,HGLRC,HCURSOR; typedef unsigned short WCHAR; typedef unsigned int UINT, DWORD, GLuint, GLenum, GLbitfield; typedef int BOOL, GLint, GLsizei; typedef unsigned long long U64; typedef long long I64; typedef long long LPARAM, LRESULT; typedef unsigned long long WPARAM; typedef float GLfloat; typedef char GLchar; typedef unsigned short WORD; typedef unsigned char BYTE;
typedef struct {long x,y;} POINT; typedef struct {long left,top,right,bottom;} RECT;
typedef struct {UINT style; void *lpfnWndProc; int cbClsExtra,cbWndExtra; HINSTANCE hInstance; HANDLE hIcon,hCursor,hbrBackground; const char *lpszMenuName,*lpszClassName;} WNDCLASSA;
typedef struct {WORD nSize,nVersion; DWORD dwFlags; BYTE iPixelType,cColorBits,cRedBits,cRedShift,cGreenBits,cGreenShift,cBlueBits,cBlueShift,cAlphaBits,cAlphaShift,cAccumBits,cAccumRedBits,cAccumGreenBits,cAccumBlueBits,cAccumAlphaBits,cDepthBits,cStencilBits,cAuxBuffers; BYTE iLayerType,bReserved; DWORD dwLayerMask,dwVisibleMask,dwDamageMask;} PFD;
API HINSTANCE WINAPI GetModuleHandleA(const char*);
API const WCHAR* WINAPI GetCommandLineW(void);
API void WINAPI ExitProcess(UINT);
API BOOL WINAPI QueryPerformanceCounter(I64*);
API BOOL WINAPI QueryPerformanceFrequency(I64*);
API void WINAPI Sleep(DWORD);
API int WINAPI GetSystemMetrics(int);
API int WINAPI MessageBoxA(HWND,const char*,const char*,UINT);
API unsigned short WINAPI RegisterClassA(const WNDCLASSA*);
API HWND WINAPI CreateWindowExA(DWORD,const char*,const char*,DWORD,int,int,int,int,HWND,HANDLE,HINSTANCE,void*);
API BOOL WINAPI DestroyWindow(HWND);
API LRESULT WINAPI DefWindowProcA(HWND,UINT,WPARAM,LPARAM);
API BOOL WINAPI PeekMessageA(void*,HWND,UINT,UINT,UINT);
API BOOL WINAPI TranslateMessage(const void*);
API LRESULT WINAPI DispatchMessageA(const void*);
API BOOL WINAPI GetClientRect(HWND,RECT*);
API BOOL WINAPI GetCursorPos(POINT*);
API int WINAPI ShowCursor(BOOL);
API BOOL WINAPI SetWindowPos(HWND,HWND,int,int,int,int,UINT);
API HDC WINAPI GetDC(HWND);
API int WINAPI ReleaseDC(HWND,HDC);
API LRESULT WINAPI SendMessageA(HWND,UINT,WPARAM,LPARAM);
API BOOL WINAPI SetWindowTextA(HWND,const char*);
API BOOL WINAPI SetFocus(HWND);
API long WINAPI RegCreateKeyExA(HANDLE,const char*,DWORD,char*,DWORD,DWORD,void*,HANDLE*,DWORD*);
API long WINAPI RegOpenKeyExA(HANDLE,const char*,DWORD,DWORD,HANDLE*);
API long WINAPI RegQueryValueExA(HANDLE,const char*,DWORD*,DWORD*,BYTE*,DWORD*);
API long WINAPI RegSetValueExA(HANDLE,const char*,DWORD,DWORD,const BYTE*,DWORD);
API long WINAPI RegCloseKey(HANDLE);
typedef struct {DWORD dwSize,dwICC;} INITCOMMONCONTROLSEX;
API BOOL WINAPI InitCommonControlsEx(const INITCOMMONCONTROLSEX*);
API int WINAPI ChoosePixelFormat(HDC,const PFD*);
API BOOL WINAPI SetPixelFormat(HDC,int,const PFD*);
API BOOL WINAPI SwapBuffers(HDC);
API HGLRC WINAPI wglCreateContext(HDC);
API BOOL WINAPI wglMakeCurrent(HDC,HGLRC);
API BOOL WINAPI wglDeleteContext(HGLRC);
API void* WINAPI wglGetProcAddress(const char*);
API void WINAPI glViewport(GLint,GLint,GLsizei,GLsizei);
API void WINAPI glClearColor(GLfloat,GLfloat,GLfloat,GLfloat);
API void WINAPI glClear(GLbitfield);
API void WINAPI glGenTextures(GLsizei,GLuint*);
API void WINAPI glBindTexture(GLenum,GLuint);
API void WINAPI glTexImage2D(GLenum,GLint,GLint,GLsizei,GLsizei,GLint,GLenum,GLenum,const void*);
API void WINAPI glTexParameteri(GLenum,GLenum,GLint);
API void WINAPI glDrawArrays(GLenum,GLint,GLsizei);
API void WINAPI glEnable(GLenum);
API void WINAPI glActiveTexture(GLenum); /* On Windows may not be exported by OpenGL32: use function pointer instead */

#define HKEY_CURRENT_USER ((HANDLE)(U64)0x80000001ULL)
#define KEY_READ 0x20019
#define KEY_WRITE 0x20006
#define REG_DWORD 4
#define WS_CAPTION 0x00C00000U
#define WS_SYSMENU 0x00080000U
#define WS_OVERLAPPED 0x00000000U
#define WS_TABSTOP 0x00010000U
#define WS_BORDER 0x00800000U
#define WS_GROUP 0x00020000U
#define BS_DEFPUSHBUTTON 1
#define CBS_DROPDOWNLIST 3
#define WM_COMMAND 0x111
#define WM_HSCROLL 0x114
#define TBM_GETPOS 0x400
#define TBM_SETRANGE 0x406
#define TBM_SETPOS 0x405
#define TBS_AUTOTICKS 1
#define CB_ADDSTRING 0x143
#define CB_GETCURSEL 0x147
#define CB_SETCURSEL 0x14E
#define BN_CLICKED 0
#define IDOK 1
#define IDCANCEL 2
#define SM_CXSCREEN 0
#define SM_CYSCREEN 1
#define WS_POPUP 0x80000000U
#define WS_CHILD 0x40000000U
#define WS_VISIBLE 0x10000000U
#define WS_EX_TOPMOST 0x00000008U
#define WM_DESTROY 2
#define WM_CLOSE 16
#define WM_KEYDOWN 0x100
#define WM_SYSKEYDOWN 0x104
#define WM_MOUSEMOVE 0x200
#define WM_LBUTTONDOWN 0x201
#define WM_RBUTTONDOWN 0x204
#define WM_MBUTTONDOWN 0x207
#define WM_ACTIVATEAPP 0x1c
#define PM_REMOVE 1
#define PFD_DRAW_TO_WINDOW 4
#define PFD_SUPPORT_OPENGL 32
#define PFD_DOUBLEBUFFER 1
#define PFD_TYPE_RGBA 0
#define GL_TEXTURE_2D 0x0DE1
#define GL_RGB 0x1907
#define GL_UNSIGNED_BYTE 0x1401
#define GL_TEXTURE_MAG_FILTER 0x2800
#define GL_TEXTURE_MIN_FILTER 0x2801
#define GL_TEXTURE_WRAP_S 0x2802
#define GL_TEXTURE_WRAP_T 0x2803
#define GL_LINEAR 0x2601
#define GL_CLAMP_TO_EDGE 0x812F
#define GL_COLOR_BUFFER_BIT 0x4000
#define GL_VERTEX_SHADER 0x8B31
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_TRIANGLE_STRIP 5
#define GL_TEXTURE0 0x84C0
#define GL_TEXTURE1 0x84C1

extern const BYTE art1[],art2[];
typedef GLuint (WINAPI *PCreateShader)(GLenum);
typedef void (WINAPI *PShaderSource)(GLuint,GLsizei,const char*const*,const GLint*);
typedef void (WINAPI *PCompileShader)(GLuint);
typedef void (WINAPI *PGetShaderiv)(GLuint,GLenum,GLint*);
typedef GLuint (WINAPI *PCreateProgram)(void);
typedef void (WINAPI *PAttachShader)(GLuint,GLuint);
typedef void (WINAPI *PLinkProgram)(GLuint);
typedef void (WINAPI *PGetProgramiv)(GLuint,GLenum,GLint*);
typedef void (WINAPI *PUseProgram)(GLuint);
typedef GLint (WINAPI *PGetUniformLocation)(GLuint,const GLchar*);
typedef void (WINAPI *PUniform1i)(GLint,GLint);
typedef void (WINAPI *PUniform1f)(GLint,GLfloat);
typedef void (WINAPI *PUniform2f)(GLint,GLfloat,GLfloat);
typedef void (WINAPI *PActiveTexture)(GLenum);
typedef void (WINAPI *PDeleteShader)(GLuint);
typedef void (WINAPI *PDeleteProgram)(GLuint);
typedef struct {PCreateShader createShader;PShaderSource shaderSource;PCompileShader compileShader;PGetShaderiv getShaderiv;PCreateProgram createProgram;PAttachShader attachShader;PLinkProgram linkProgram;PGetProgramiv getProgramiv;PUseProgram useProgram;PGetUniformLocation getUniformLocation;PUniform1i uniform1i;PUniform1f uniform1f;PUniform2f uniform2f;PActiveTexture activeTexture;PDeleteShader deleteShader;PDeleteProgram deleteProgram;} GLFns;
static GLFns g;
int _fltused = 0;
static HWND win;static HDC dc;static HGLRC ctx;static int running=1,preview=0,armed=0,frames=0;static POINT mouseStart;
typedef struct {DWORD speed,depth,glow,art;} Settings;
static const Settings defaults={250,10,200,2};static Settings opts={250,10,200,2};
static HWND dialog,slSpeed,slDepth,slGlow,comboArt,labelSpeed,labelDepth,labelGlow;
static const char settingsKey[]="Software\\StargateSlitScan64";
static void loadSettings(void){HANDLE k;DWORD typ,len,v;
 if(RegOpenKeyExA(HKEY_CURRENT_USER,settingsKey,0,KEY_READ,&k))return;
 len=4;if(!RegQueryValueExA(k,"Speed",0,&typ,(BYTE*)&v,&len)&&typ==REG_DWORD&&len==4&&v>=10&&v<=250)opts.speed=v;
 len=4;if(!RegQueryValueExA(k,"Depth",0,&typ,(BYTE*)&v,&len)&&typ==REG_DWORD&&len==4&&v>=10&&v<=110)opts.depth=v;
 len=4;if(!RegQueryValueExA(k,"Glow",0,&typ,(BYTE*)&v,&len)&&typ==REG_DWORD&&len==4&&v<=200)opts.glow=v;
 len=4;if(!RegQueryValueExA(k,"Artwork",0,&typ,(BYTE*)&v,&len)&&typ==REG_DWORD&&len==4&&v<=2)opts.art=v;
 RegCloseKey(k);
}
static void saveSettings(void){HANDLE k;if(RegCreateKeyExA(HKEY_CURRENT_USER,settingsKey,0,0,0,KEY_WRITE,0,&k,0))return;
 RegSetValueExA(k,"Speed",0,REG_DWORD,(const BYTE*)&opts.speed,4);
 RegSetValueExA(k,"Depth",0,REG_DWORD,(const BYTE*)&opts.depth,4);
 RegSetValueExA(k,"Glow",0,REG_DWORD,(const BYTE*)&opts.glow,4);
 RegSetValueExA(k,"Artwork",0,REG_DWORD,(const BYTE*)&opts.art,4);RegCloseKey(k);
}
static GLuint program,tex[2];static GLint uRes,uTime,uSpeed,uDepth,uGlow,uArt,uTex1,uTex2;static I64 tickFreq,tickStart;

static const char vertex[]=
"#version 120\n"
"void main(){gl_Position=gl_Vertex;}\n";
static const char fragment[]=
"#version 120\n"
"uniform vec2 resolution;uniform float clockTime,speed,depth,glow;uniform int artwork;uniform sampler2D tex1,tex2;\n"
"float hash(vec2 p){return fract(sin(dot(p,vec2(127.1,311.7)))*43758.5453);}\n"
"vec3 sampleArt(vec2 u){vec3 a=texture2D(tex1,u).rgb,b=texture2D(tex2,u).rgb; if(artwork==0)return a;if(artwork==1)return b;return mix(a,b,0.5+0.5*sin(clockTime*.32));}\n"
"vec3 linearArt(vec2 uv){vec3 c=sampleArt(uv);return pow(max(c,0.),vec3(1.33));}\n"
"void main(){\n"
"vec2 q=gl_FragCoord.xy/resolution.xy;vec2 p=(q-.5)*vec2(resolution.x/resolution.y,1.);p.x*=.76;\n"
"float ax=abs(p.x),ay=abs(p.y);float wedge=max(ax*.69,ay*1.50);float radius=max(.0005,wedge);\n"
"float horizon=atan(ay,ax+.0001)/1.5707963;\n"
"float travel=clockTime*speed*.035;float distancePhase=log2(radius+.001)*depth*.19;\n"
"float u=fract(.28+travel-distancePhase);float v=clamp(.5+sign(p.y)*(.05+.44*pow(horizon,.72)),.002,.998);\n"
"float slant=atan(p.y,p.x)/6.2831853;float drift=.016*sin(clockTime*.29+distancePhase*1.3)+.035*slant;\n"
"vec3 color=linearArt(vec2(fract(u+drift),v));vec3 nearSample=linearArt(vec2(fract(u+.007+drift),v));vec3 farSample=linearArt(vec2(fract(u-.009+drift),v));\n"
"color=mix(color,(color+nearSample+farSample)/3.,.32);float core=exp(-radius*40.);float streak=exp(-abs(p.y)*55.)*.055;\n"
"float lum=max(color.r,max(color.g,color.b));color+=color*lum*glow*.46;\n"
"color+=vec3(.19,.34,.50)*core*.53+vec3(.20,.10,.16)*streak;\n"
"float peripheral=smoothstep(1.25,.1,length(p));color*=mix(.55,1.,peripheral);\n"
"color*=smoothstep(0.,.06,radius)*.99+core*.6;color=vec3(1.)-exp(-color*1.45);\n"
"float grain=(hash(gl_FragCoord.xy+floor(clockTime*24.))-.5)*.018;\n"
"color=clamp(color+grain,0.,1.);gl_FragColor=vec4(color,1.);}\n";

static int initFns(void){
#define LOAD(n,s) g.n=(void*)wglGetProcAddress("gl" s);if(!g.n)return 0;
 LOAD(createShader,"CreateShader") LOAD(shaderSource,"ShaderSource") LOAD(compileShader,"CompileShader")
 LOAD(getShaderiv,"GetShaderiv") LOAD(createProgram,"CreateProgram") LOAD(attachShader,"AttachShader")
 LOAD(linkProgram,"LinkProgram") LOAD(getProgramiv,"GetProgramiv") LOAD(useProgram,"UseProgram")
 LOAD(getUniformLocation,"GetUniformLocation") LOAD(uniform1i,"Uniform1i") LOAD(uniform1f,"Uniform1f")
 LOAD(uniform2f,"Uniform2f") LOAD(activeTexture,"ActiveTexture") LOAD(deleteShader,"DeleteShader") LOAD(deleteProgram,"DeleteProgram")
#undef LOAD
 return 1;
}
static GLuint makeShader(GLenum type,const char*src){GLuint s=g.createShader(type);GLint ok=0;g.shaderSource(s,1,&src,0);g.compileShader(s);g.getShaderiv(s,GL_COMPILE_STATUS,&ok);return ok?s:0;}
static int initialise(void){
 PFD p={0};p.nSize=sizeof(p);p.nVersion=1;p.dwFlags=PFD_DRAW_TO_WINDOW|PFD_SUPPORT_OPENGL|PFD_DOUBLEBUFFER;p.iPixelType=PFD_TYPE_RGBA;p.cColorBits=32;
 dc=GetDC(win);if(!dc)return 0;int pf=ChoosePixelFormat(dc,&p);if(!pf||!SetPixelFormat(dc,pf,&p))return 0;
 ctx=wglCreateContext(dc);if(!ctx||!wglMakeCurrent(dc,ctx))return 0;if(!initFns())return 0;
 GLuint v=makeShader(GL_VERTEX_SHADER,vertex),f=makeShader(GL_FRAGMENT_SHADER,fragment);if(!v||!f)return 0;
 program=g.createProgram();g.attachShader(program,v);g.attachShader(program,f);g.linkProgram(program);GLint ok=0;g.getProgramiv(program,GL_LINK_STATUS,&ok);g.deleteShader(v);g.deleteShader(f);if(!ok)return 0;
 g.useProgram(program);
 uRes=g.getUniformLocation(program,"resolution");uTime=g.getUniformLocation(program,"clockTime");uSpeed=g.getUniformLocation(program,"speed");uDepth=g.getUniformLocation(program,"depth");uGlow=g.getUniformLocation(program,"glow");uArt=g.getUniformLocation(program,"artwork");uTex1=g.getUniformLocation(program,"tex1");uTex2=g.getUniformLocation(program,"tex2");
 glGenTextures(2,tex);
 for(int i=0;i<2;i++){
  g.activeTexture(GL_TEXTURE0+i);glBindTexture(GL_TEXTURE_2D,tex[i]);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP_TO_EDGE);glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP_TO_EDGE);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGB,1024,256,0,GL_RGB,GL_UNSIGNED_BYTE,i?art2:art1);
 }
 g.uniform1i(uTex1,0);g.uniform1i(uTex2,1);g.uniform1i(uArt,(int)opts.art);
 g.uniform1f(uSpeed,(float)opts.speed/80.f);g.uniform1f(uDepth,(float)opts.depth/110.f);g.uniform1f(uGlow,(float)opts.glow/100.f);
 QueryPerformanceFrequency(&tickFreq);QueryPerformanceCounter(&tickStart);return 1;
}
static void render(void){RECT r;I64 now;GetClientRect(win,&r);int w=r.right-r.left,h=r.bottom-r.top;if(w<1||h<1)return;
 glViewport(0,0,w,h);QueryPerformanceCounter(&now);float t=(float)((double)(now-tickStart)/(double)tickFreq);
 g.uniform2f(uRes,(float)w,(float)h);g.uniform1f(uTime,t);glClear(GL_COLOR_BUFFER_BIT);
 /* GLSL 1.20 gl_Vertex is fed by old OpenGL fixed-function immediate vertices. */
 extern void WINAPI glBegin(GLenum);extern void WINAPI glVertex2f(GLfloat,GLfloat);extern void WINAPI glEnd(void);
 glBegin(7);glVertex2f(-1.f,-1.f);glVertex2f(1.f,-1.f);glVertex2f(1.f,1.f);glVertex2f(-1.f,1.f);glEnd();
 SwapBuffers(dc);frames++;
}
static LRESULT WINAPI wndproc(HWND h,UINT m,WPARAM w,LPARAM l){(void)w;(void)l;
 if(m==WM_DESTROY){running=0;return 0;}
 if(!preview){
  if(m==WM_KEYDOWN||m==WM_SYSKEYDOWN||m==WM_LBUTTONDOWN||m==WM_RBUTTONDOWN||m==WM_MBUTTONDOWN){running=0;return 0;}
  if(m==WM_MOUSEMOVE&&armed){POINT p;GetCursorPos(&p);long dx=p.x-mouseStart.x,dy=p.y-mouseStart.y;if(dx>8||dx< -8||dy>8||dy< -8)running=0;return 0;}
  if(m==WM_ACTIVATEAPP&&!w&&frames>20){running=0;return 0;}
 }
 return DefWindowProcA(h,m,w,l);
}
static void setTrack(HWND h,DWORD min,DWORD max,DWORD value){SendMessageA(h,TBM_SETRANGE,1,(LPARAM)((max<<16)|min));SendMessageA(h,TBM_SETPOS,1,value);}
static void updateConfigLabels(void){
 char str[40];DWORD v;char*end;
 v=(DWORD)SendMessageA(slSpeed,TBM_GETPOS,0,0);end=str;*end++='S';*end++='p';*end++='e';*end++='e';*end++='d';*end++=':';*end++=' ';if(v>=100)*end++=(char)('0'+v/100);if(v>=10)*end++=(char)('0'+(v/10)%10);*end++=(char)('0'+v%10);*end=0;SetWindowTextA(labelSpeed,str);
 v=(DWORD)SendMessageA(slDepth,TBM_GETPOS,0,0);end=str;*end++='D';*end++='e';*end++='p';*end++='t';*end++='h';*end++=':';*end++=' ';if(v>=100)*end++=(char)('0'+v/100);if(v>=10)*end++=(char)('0'+(v/10)%10);*end++=(char)('0'+v%10);*end=0;SetWindowTextA(labelDepth,str);
 v=(DWORD)SendMessageA(slGlow,TBM_GETPOS,0,0);end=str;*end++='G';*end++='l';*end++='o';*end++='w';*end++=':';*end++=' ';if(v>=100)*end++=(char)('0'+v/100);if(v>=10)*end++=(char)('0'+(v/10)%10);*end++=(char)('0'+v%10);*end=0;SetWindowTextA(labelGlow,str);
}
static HWND ctl(const char*cls,const char*title,DWORD style,int x,int y,int w,int h,int id){return CreateWindowExA(0,cls,title,WS_CHILD|WS_VISIBLE|style,x,y,w,h,dialog,(HANDLE)(U64)id,GetModuleHandleA(0),0);}
static void configReset(void){setTrack(slSpeed,10,250,defaults.speed);setTrack(slDepth,10,110,defaults.depth);setTrack(slGlow,0,200,defaults.glow);SendMessageA(comboArt,CB_SETCURSEL,defaults.art,0);updateConfigLabels();}
static LRESULT WINAPI configProc(HWND h,UINT m,WPARAM w,LPARAM l){
 if(m==WM_CLOSE){DestroyWindow(h);dialog=0;return 0;}
 if(m==WM_HSCROLL){updateConfigLabels();return 0;}
 if(m==WM_COMMAND){int id=(int)(w&65535);if(id==1003){configReset();return 0;}if(id==IDOK){
 opts.speed=(DWORD)SendMessageA(slSpeed,TBM_GETPOS,0,0);opts.depth=(DWORD)SendMessageA(slDepth,TBM_GETPOS,0,0);opts.glow=(DWORD)SendMessageA(slGlow,TBM_GETPOS,0,0);
 int a=(int)SendMessageA(comboArt,CB_GETCURSEL,0,0);opts.art=(a>=0&&a<=2)?(DWORD)a:2;saveSettings();DestroyWindow(h);dialog=0;return 0;}
 if(id==IDCANCEL){DestroyWindow(h);dialog=0;return 0;}}
 return DefWindowProcA(h,m,w,l);
}
static void runConfig(void){
 HINSTANCE inst=GetModuleHandleA(0);WNDCLASSA wc={0};wc.lpfnWndProc=(void*)configProc;wc.hInstance=inst;wc.lpszClassName="StargateSaverConfig";RegisterClassA(&wc);
 INITCOMMONCONTROLSEX ic={sizeof(ic),0x00000004};if(!InitCommonControlsEx(&ic)){MessageBoxA(0,"Windows trackbar controls unavailable.","Stargate Settings",0x10);return;}
 int x=(GetSystemMetrics(0)-440)/2,y=(GetSystemMetrics(1)-380)/2;
 dialog=CreateWindowExA(0x00000100U,"StargateSaverConfig","Stargate Slit-Scan — Settings",WS_OVERLAPPED|WS_CAPTION|WS_SYSMENU|WS_VISIBLE,x,y,440,380,0,0,inst,0);
 if(!dialog)return;
 ctl("STATIC","1968 Stargate • native OpenGL x64",0,18,14,390,20,1100);
 labelSpeed=ctl("STATIC","Speed",0,18,48,390,20,1101);
 slSpeed=ctl("msctls_trackbar32","",WS_TABSTOP|TBS_AUTOTICKS,17,68,390,36,1201);setTrack(slSpeed,10,250,opts.speed);
 labelDepth=ctl("STATIC","Depth",0,18,110,390,20,1102);
 slDepth=ctl("msctls_trackbar32","",WS_TABSTOP|TBS_AUTOTICKS,17,130,390,36,1202);setTrack(slDepth,10,110,opts.depth);
 labelGlow=ctl("STATIC","Glow",0,18,172,390,20,1103);
 slGlow=ctl("msctls_trackbar32","",WS_TABSTOP|TBS_AUTOTICKS,17,192,390,36,1203);setTrack(slGlow,0,200,opts.glow);
 ctl("STATIC","Artwork",0,18,237,390,20,1104);
 comboArt=ctl("COMBOBOX","",CBS_DROPDOWNLIST|WS_TABSTOP,18,259,390,100,1204);
 SendMessageA(comboArt,CB_ADDSTRING,0,(LPARAM)"Recovered artwork 1");SendMessageA(comboArt,CB_ADDSTRING,0,(LPARAM)"Recovered artwork 2");SendMessageA(comboArt,CB_ADDSTRING,0,(LPARAM)"Crossfade both (default)");SendMessageA(comboArt,CB_SETCURSEL,opts.art,0);
 ctl("BUTTON","Defaults",WS_TABSTOP,18,306,96,28,1003);
 ctl("BUTTON","Cancel",WS_TABSTOP,218,306,90,28,IDCANCEL);
 ctl("BUTTON","OK",WS_TABSTOP|BS_DEFPUSHBUTTON,318,306,90,28,IDOK);
 updateConfigLabels();
 struct {void* hwnd;UINT message;WPARAM wParam;LPARAM lParam;DWORD time;POINT pt;DWORD lPrivate;} msg;
 while(dialog){while(PeekMessageA(&msg,0,0,0,PM_REMOVE)){TranslateMessage(&msg);DispatchMessageA(&msg);}Sleep(12);}
}
static HWND parseParent(const WCHAR *s){U64 v=0;int digits=0,hex=0;while(*s==32||*s==9||*s==':')s++;if(s[0]=='0'&&(s[1]=='x'||s[1]=='X')){hex=1;s+=2;}
 for(;*s;s++){unsigned c=*s;unsigned n;if(c>='0'&&c<='9')n=c-'0';else if(c>='a'&&c<='f')n=c-'a'+10;else if(c>='A'&&c<='F')n=c-'A'+10;else break;if(n>= (hex?16:10))break;v=v*(hex?16:10)+n;digits++;}return digits?(HWND)(U64)v:0;}
void WINAPI entry(void){
 const WCHAR *cmd=GetCommandLineW();const WCHAR *s=cmd;WCHAR flag='s';HWND parent=0;
 /* Skip executable name, with or without quotes. */
 if(*s=='"'){s++;while(*s&&*s!='"')s++;if(*s)s++;}else{while(*s&&*s!=' ')s++;}
 while(*s==' '||*s==9)s++;
 if((*s=='/'||*s=='-')&&s[1]){flag=s[1];s+=2;if(flag>='A'&&flag<='Z')flag=(WCHAR)(flag+32);}
 loadSettings();
 if(flag=='c'){runConfig();ExitProcess(0);}
 if(flag=='p'){preview=1;parent=parseParent(s);if(!parent)ExitProcess(0);}
 HINSTANCE inst=GetModuleHandleA(0);WNDCLASSA wc={0};wc.lpfnWndProc=(void*)wndproc;wc.hInstance=inst;wc.lpszClassName="StargateSlitScanSaver64";
 if(!RegisterClassA(&wc))ExitProcess(1);
 int x=0,y=0,w=640,h=360;DWORD style=WS_VISIBLE|WS_POPUP,ex=WS_EX_TOPMOST;
 if(preview){RECT rc;GetClientRect(parent,&rc);w=rc.right-rc.left;h=rc.bottom-rc.top;style=WS_VISIBLE|WS_CHILD;ex=0;}
 else{x=GetSystemMetrics(76);y=GetSystemMetrics(77);w=GetSystemMetrics(78);h=GetSystemMetrics(79);if(w<=0||h<=0){x=0;y=0;w=GetSystemMetrics(0);h=GetSystemMetrics(1);}}
 win=CreateWindowExA(ex,"StargateSlitScanSaver64","Stargate Slit Scan",style,x,y,w,h,parent,0,inst,0);if(!win)ExitProcess(2);
 if(!initialise()){MessageBoxA(0,"Could not start the OpenGL shader. An OpenGL 2.1-compatible driver is needed.","Stargate OpenGL error",0x10);ExitProcess(3);}
 GetCursorPos(&mouseStart);if(!preview)ShowCursor(0);
 struct {void* hwnd;UINT message;WPARAM wParam;LPARAM lParam;DWORD time;POINT pt;DWORD lPrivate;} msg;
 while(running){while(PeekMessageA(&msg,0,0,0,PM_REMOVE)){TranslateMessage(&msg);DispatchMessageA(&msg);}if(!running)break;
  render();if(frames>18)armed=1;Sleep(1);}
 if(!preview)ShowCursor(1);wglMakeCurrent(0,0);if(ctx)wglDeleteContext(ctx);if(dc)ReleaseDC(win,dc);if(win)DestroyWindow(win);ExitProcess(0);
}

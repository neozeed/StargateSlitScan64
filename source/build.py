from PIL import Image
import subprocess,pathlib
p=pathlib.Path(__file__).parent
files=[p/'recovered-artwork-1.png',p/'recovered-artwork-2.png']
for i,n in enumerate(files,1):
 im=Image.open(n).convert('RGB').resize((1024,256),Image.Resampling.LANCZOS)
 (p/f'art{i}.rgb').write_bytes(im.tobytes())
 (p/f'art{i}.s').write_text(f'.section .rdata,"dr"\n.globl art{i}\n.p2align 4\nart{i}:\n.incbin "art{i}.rgb"\n')
subprocess.run(['/usr/local/swift/usr/bin/clang','-target','x86_64-pc-windows-msvc','-ffreestanding','-fno-builtin','-fno-stack-protector','-O2','-c','stargate.c','-o','stargate.obj'],cwd=p,check=True)
for i in (1,2):subprocess.run(['/usr/local/swift/usr/bin/clang','-target','x86_64-pc-windows-msvc','-c',f'art{i}.s','-o',f'art{i}.obj'],cwd=p,check=True)
for name in ('kernel32','user32','gdi32','opengl32','advapi32','comctl32'):
 subprocess.run(['/usr/local/swift/usr/bin/lld-link','/lib',f'/def:{name}.def','/machine:x64',f'/out:{name}.lib'],cwd=p,check=True)
subprocess.run(['/usr/local/swift/usr/bin/lld-link','/nologo','/machine:x64','/subsystem:windows','/entry:entry','/nodefaultlib','/opt:ref','/Brepro','/fixed','/dynamicbase:no','/out:../StargateSlitScan64.scr','stargate.obj','art1.obj','art2.obj','kernel32.lib','user32.lib','gdi32.lib','opengl32.lib','advapi32.lib','comctl32.lib'],cwd=p,check=True)
print('built:',(p/'../StargateSlitScan64.scr').stat().st_size)

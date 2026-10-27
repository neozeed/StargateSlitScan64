# Stargate Slit-Scan Screensaver — x64 R1

Native x64 Win32 screen saver (.scr) using OpenGL 2.1 / GLSL 1.20, with **no browser, runtime DLLs, configuration files or external image files**. The two user-provided recovered slit-scan artwork images are resized to 1024×256 and embedded as RGB textures.

## Requested default visual settings

- Artwork: crossfade between image 1 and image 2
- Speed: maximum WebGL slider setting (250/80 = **3.125**)
- Depth: minimum WebGL slider setting (10/110 = **0.090909**)
- Glow: maximum WebGL slider setting (200/100 = **2.0**)
- Image mapping, colour enhancement, perspective formula and crossfade timing are adapted from the prior WebGL experiment.

## How to use

**Safest first test:** from PowerShell in the extracted directory, run `& .\StargateSlitScan64.scr /s`. Move the mouse at least 8 pixels, click, or press any key to exit. It will span the Windows virtual desktop (including multiple monitors), subject to OpenGL driver behaviour.

Install by copying `StargateSlitScan64.scr` into `C:\Windows\System32` (requires administrator permissions), or right-click the `.scr` file and choose **Install**. In Windows, open **Change screen saver**, select StargateSlitScan64, then use **Preview**. Note: right-click Install may trigger a fullscreen test immediately on some systems.

Windows screensaver switches: `/s` runs, `/c` shows the informational configuration message, `/p <HWND>` draws into Windows' small preview host window. The latter is implemented but not runtime-verified.

## Build

On a host with Python 3 + Pillow and LLVM Clang + lld-link in `/usr/local/swift/usr/bin`, run `python build.py`. The script compiles freestanding Windows x64 without CRT libraries. Import libraries are generated from the included `.def` files. Edit paths in `build.py` if your LLVM distribution is elsewhere.

All asset inputs are included in this source folder. The generated `art*.rgb`, `art*.s`, `.obj`, `.lib` files are intermediate build products, not required for installation.

## Qualification

- **Successfully cross-compiled** into PE32+ / AMD64, Windows GUI subsystem, with only Windows OS DLL imports.
- **Not live-tested on Windows** in this environment; driver, full-screen, dual-monitor and preview behaviour require a real Windows test.
- OpenGL requires compatible graphics drivers; Remote Desktop / Windows basic display modes may not support GLSL 1.20.
- This reproduces the earlier software shader experiment, *not* the original optical-camera mechanics of the 1968 production.

## R1A Windows loader fix (2026-10-27)

The initial R1 binary mistakenly imported GetDC and ReleaseDC from GDI32.dll.
They are USER32.dll exports. R1A corrects the two module definitions and
rebuilds from the same C/shader/artwork sources. Windows had rejected R1
before any OpenGL code ran. R1A is loader-import-audited but not yet
live-tested on Windows.

## R1B native configuration dialog (2026-10-27)

The former informational `/c` message box is replaced with a native Win32 settings window using standard trackbar and combo-box controls. The parameters are saved under `HKEY_CURRENT_USER\Software\StargateSlitScan64` as DWORDs (`Speed`, `Depth`, `Glow`, `Artwork`) and loaded for `/s` and `/p`.

- Speed: integer 10–250 (default 250), mapped to shader speed value /80.
- Depth: integer 10–110 (default 10), mapped to shader depth value /110.
- Glow: integer 0–200 (default 200), mapped to shader glow value /100.
- Artwork: recovered artwork 1, recovered artwork 2, crossfade both (default).
- Defaults resets controls; **OK** saves; **Cancel** closes without changes.

Build target remains x64 Win32 GUI, freestanding Clang + lld-link; additionally imports standard Windows ADVAPI32 and COMCTL32 DLLs. As with earlier builds, live validation on Windows is needed.

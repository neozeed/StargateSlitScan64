# StargateSlitScan64

### A 1968 optical effect, reconstructed as a native Windows x64 screensaver.

**A little piece of *2001: A Space Odyssey* for your desktop.**

StargateSlitScan64 is a standalone Windows 64-bit `.scr` screensaver that uses OpenGL shaders and two digitally recovered slit-scan artwork images to evoke the extraordinary **Stargate** sequence in Stanley Kubrick's *2001: A Space Odyssey* (1968).

No browser. No web service. No installer. Just a native Win32 executable, a GPU, and a journey into a tunnel of colour.

> **Status:** R1B — native renderer demonstrated in Windows Screen Saver Settings preview and full-screen on a real Windows PC (R1A). R1B adds a configurable settings dialog; that revision's settings UI still awaits separate live confirmation.

## See it in motion

https://github.com/YOUR-USERNAME/StargateSlitScan64

![Stargate screen saver in action](docs/stargate-preview.gif)

[Watch the original moving preview (MP4)](docs/stargate.mp4)

> **Before publishing:** put your supplied `stargate.mp4` in `docs/`, optionally convert it to `docs/stargate-preview.gif`, and replace the repository placeholder URL above. The preview was captured *inside Windows' own screensaver preview window* — a preview of the preview!

## What it does

- **Native Win32 screensaver**, packaged as a real 64-bit `.scr` PE executable.
- **OpenGL 2.1 / GLSL 1.20** rendering — no browser, Electron, WebView, or external shader dependencies.
- **Two embedded recovered artwork textures**, so no separate image files are needed at runtime.
- **Crossfade mode** between the two images, as well as either image individually.
- **Adjustable speed, depth, and glow**, with the intentionally outrageous default settings.
- **Windows screensaver integration**, including the small Control Panel preview (`/p`), fullscreen mode (`/s`) and configuration dialog (`/c`).
- **Settings persistence** per user in the Windows registry.
- Supports drawing across the **Windows virtual desktop** (multi-monitor behaviour may depend on driver/display configuration).
- Exit on keyboard, click, or mouse movement (mouse movement threshold in the current implementation).

This is a **real-time shader interpretation** of the Stargate look, *not* a frame-accurate simulation of Douglas Trumbull's original physical slit-scan camera and optical process.

## Installation

1. Download `StargateSlitScan64.scr` from the [Releases](../../releases) page, or build it from source.
2. Right-click the `.scr` and select **Install**, or copy it to `C:\Windows\System32` (administrator permission may be required).
3. Open **Screen Saver Settings**, choose **StargateSlitScan64**, then use **Settings** or **Preview**.
4. Enjoy falling indefinitely into 1968.

To test from PowerShell without installing:

```powershell
& ".\StargateSlitScan64.scr" /s
```

To open settings:

```powershell
& ".\StargateSlitScan64.scr" /c
```

Windows also starts the preview using `/p <HWND>`, passing a parent window handle. This is implemented for the standard screen saver host.

**Note:** Screensavers are executable programs. Download only builds you trust, and consult the source if you wish to audit the binary.

## Configuration

| Setting | Range | Default | Effect |
|:--|:--|:--|:--|
| Speed | 10–250 | **250** | How quickly the tunnel moves |
| Depth | 10–110 | **10** | Perspective/stretching of the tunnel |
| Glow | 0–200 | **200** | Brightness/glow enhancement |
| Artwork | Image 1, Image 2, Crossfade | **Crossfade** | Source texture selection |

These are deliberately inherited from the earlier WebGL prototype's control scales. **Defaults** restores the values above; **OK** saves them; **Cancel** discards changes.

Settings live at:

```text
HKEY_CURRENT_USER\Software\StargateSlitScan64
```

The four DWORD values are `Speed`, `Depth`, `Glow`, and `Artwork`. There is no external configuration file.

## Building from source

The R1B source package contains:

```text
StargateSlitScan64.scr      # Prebuilt x64 screensaver
source/
  stargate.c               # Win32 window, shader, renderer, screensaver & settings UI
  build.py                 # Freestanding cross-build
  recovered-artwork-1.png  # Embedded source artwork
  recovered-artwork-2.png
  art1.s, art2.s           # Binary asset section declarations
  *.def                    # Windows system DLL import definitions
  README.md                # Original technical notes
```

The provided build script targets the original build environment: **Python 3 + Pillow**, **LLVM Clang**, and **lld-link**, with LLVM paths currently set to `/usr/local/swift/usr/bin`. If your tools are installed elsewhere, adjust the paths in `source/build.py`.

From the `source` directory:

```bash
python3 build.py
```

The build uses `clang -target x86_64-pc-windows-msvc` and `lld-link` to create a **freestanding PE32+ Windows GUI executable** without linking a C runtime. At build time, Pillow resamples the two source PNGs into embedded **1024 × 256 RGB textures**. The executable imports standard Windows system DLLs; no special third-party DLL is needed for deployment.

**Build-portability note:** this isn't a conventional MinGW or Visual Studio solution yet. The included script is the reproducible build method for the existing Clang/lld environment; other toolchains may require adjustments.

## How this compares with the original

Douglas Trumbull and the *2001* visual-effects team created the original slit-scan imagery using artwork, controlled illumination, long exposures, narrow slits, and mechanically choreographed camera movement. The effect was photographic, not a 3D computer render.

Here, the artwork becomes texture data and a GPU shader performs animated perspective mapping, colour treatment, glow, and transitions. The illusion recalls the optical effect while using a fundamentally different mechanism.

The source textures derive from reconstructions of *2001* slit-scan imagery. An especially fascinating reference is Greg Ercolano's investigation:

**[2001: A Space Odyssey — Unwrapping the Slit Scan Sequences](https://www.seriss.com/people/erco/2001/)**

It explores the unusual imagery concealed in the film's streaks of light, including geometric patterns that are difficult to recognise while watching the actual sequence.

## A very improbable origin story

This project began with a screenshot of an AI image system apparently refusing to combine **two harmless motivational spirals** on the grounds that the request might be sexual.

This naturally led to:

1. A joke about *too many curves*.
2. A glamorous 1980s sci-fi poster with a large **TOO MANY CURVES?!** stamp.
3. A woman riding turtles through an infinitely recursive universe.
4. A vintage AT&T-style cyan-and-orange perspective-grid wallpaper.
5. A conversation about Kubrick, *Dr. Strangelove*, *2001*, and the Stargate.
6. A rediscovery of digitally unwrapped slit-scan artwork.
7. A WebGL experiment.
8. An actual native Windows x64 screensaver.

As one does.

The first native build even arrived with its own charmingly period-appropriate Windows bug: it imported `GetDC` and `ReleaseDC` from **GDI32.dll** instead of **USER32.dll**. Windows refused to load it. R1A fixed those imports and was subsequently seen rendering in both the Windows screensaver preview and fullscreen. R1B added a native settings UI and persistence.

A perfect little lesson in the history of computer graphics: **1968 optical engineering → 2002-era digital archaeology → WebGL → 2026 Win32/OpenGL.**

## Current limitations and possible future improvements

- R1B's new settings UI should be live-tested on Windows; the proven preview/fullscreen observations are from R1A.
- Multi-monitor spanning is implemented using the virtual desktop, but hasn't been independently verified across every topology.
- The shader is an artistic approximation rather than a reproduction of the exact 1968 optical geometry.
- Behaviour under Remote Desktop or graphics drivers without suitable OpenGL/GLSL support may differ.
- There is no native per-monitor configuration, automatic brightness adaptation, or GPU usage limiter yet.

Potential next experiments: a more historically faithful slit geometry, subtle film grain and exposure flutter, a low-glow '1968 film' preset, and configurable per-monitor or spanning behaviour.

## Credits and rights

- **Original film and Stargate sequence:** *2001: A Space Odyssey* (1968), directed by Stanley Kubrick; optical effects associated with Douglas Trumbull and the film's visual-effects team.
- **Digital slit-scan research:** Greg Ercolano's [unwrapping investigation](https://www.seriss.com/people/erco/2001/).
- **Source artwork:** Two recovered-image references supplied for this experiment.
- **Screensaver implementation:** Built collaboratively with ChatGPT, with real-world Windows testing and feedback from the project author.

**Important licensing distinction:** The original *2001* imagery is not public domain merely because it has been reconstructed, screenshot, or embedded. The supplied images may remain subject to film-studio or other third-party rights. **Do not assert that these images are MIT, GPL, CC0, or otherwise freely redistributable without verifying their provenance and permissions.** The independently authored screensaver code can be licensed separately from its embedded source imagery; decide how to publish the images and binary only after checking those rights.

This is an unofficial, non-commercial fan/technical experiment. It is **not affiliated with or endorsed by** the rights holders of *2001: A Space Odyssey*.

## One last thing

> “My God, it's full of stars!”

Well, in this case it's full of **colourful arrows, circles, recovered textures, OpenGL shaders, and rather too many curves.**

**Enjoy the journey.** 🌌

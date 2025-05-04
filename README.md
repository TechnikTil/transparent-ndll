# Transparent Windows

## Build instructions:

First clone this repo

Then open cmd or terminal in the repo, and run

For Windows: `lime rebuild . windows`

For Mac: `lime rebuild . mac`

For Linux: `lime rebuild . linux`

For 32 bit add `-32`

For debug add `-debug`

The resulting file will be in `ndll/Platform64/ndllexample-platform.ndll`

To change the name go into `project/Build.xml`

The code for the ndll is in `project/common/ExternalInterface.cpp`

## Usage in Codename:

```hx
import funkin.backend.utils.NdllUtil;

// Place ndlls in mods/yourmodname/ndlls/
var setTransparency = NdllUtil.getFunction("ndllexample", "ndllexample_set_windows_transparent", 4);
// setTransparency(active:Bool, r:Int, g:Int, b:Int);

setTransparency(true, 255, 255, 255);

// This works fine on hscript and using Reflect.callMethod, only on codename tho
```

## Usage in non-codename projects:

```hx
// For fnf add your ndlls in assets/preload/ndlls/
var os = #if windows "-windows" #elseif linux "-linux" #elseif macos "-mac" #elseif android "-android" #elseif ios "-ios" #else "" #end;
var setTransparency:Dynamic = lime.system.CFFI.load(openfl.utils.Assets.getPath('assets/ndlls/ndllexample' + os + '.ndll'), "ndllexample_set_windows_transparent", 4);
if(setTransparency == null) setTransparency = function() {}; // anti crash
// setTransparency(active:Bool, r:Int, g:Int, b:Int);

setTransparency(true, 255, 255, 255);

// You cannot call ndll functions using Reflect.callMethod / Hscript
```

# Yet Another Steam Overlay Fixer (for Fallout 3)
Enables the Steam overlay and playtime tracking in Fallout 3 when launching outside Steam (for example, with Mod Organizer 2).

## Compiling
This FOSE plugin was compiled with Visual Studio 2019 (MSVC v142).

You'll also need to download the Steamworks SDK and place the relevant files in the `steam` folder. It uses the x86 binaries.

The build config will automatically run the Steam GOTY version of Fallout 3, assuming it is installed on the C drive.
Remember to place `steam_api.dll` and `steam_appid.txt` next to `Fallout3.exe`.

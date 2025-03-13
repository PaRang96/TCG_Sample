# Update : Native call for pre-built unreal engine.
> Prior shell had two major problems.

- It works not on pre-built Unreal Engine because of the lack of `GenerateProjectFiles.sh`
- It manages the environment variables and main logic at the same file.

> And this is a fix of it with native call and modularised shell.


# Unreal Build Tool (UBT)
- Built utility (unreal builder tool) is stored in:
    > /path/to/EpicGames/UnrealEngine/Engine/BinariesDotNET/UnrealBuildTool

- No matter which operating system you use, it is highly possible that built-in Build Tool would be stored in same directory.


# env.sh : Configuration
- To configure the build system, you would want to set the value of env.sh
- It is to personalis the navigation for Unreal Engine 5. (and its root).
- Open `/path/to/PaRang96/TCG_Sample/env.sh`. If you do not have it, make one.

## UEEngine
- An engine-specified for Unreal Engine.
- As repository, the expected value will be as following:
    > /path/to/EpicGames/UnrealEngine/Engine

# init.sh : Project File Generation
- This shell will generate the makefiles and components needed to build.
- This includes the header `Intermediate`, `TCG_Sample.code-workspace`, and tons of `*.generated.h`s.
- Navigate to `/path/to/PaRang96/TCG_Sample` and run a script below:
```sh
sh init.sh
```

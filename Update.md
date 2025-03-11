# CLI-Build Tool
> Installing Vulkan Driver for every developing computer is too much for just making a game.  
> I have found a way to build this project (likely) without opening the GUI.  
> Of course you will not be able to run it on GLI, but you don't always need to run it just for debugging few lines.

# Why the hell did I've done this
- I am now running an OS(not very windows) on external Hard Drive (with Port of USB) for Drive Issues, and Windows was not suitable option for this.
- For make it portable, I have decied not to install any graphic device
- The Unreal Engine GUI does not run without Graphic Driver which implements Vulkan.

# 'Basic' Knowledge which will help you
- Unreal Engine will require you a manifest file to build.
- Directly building with Unreal Header Tool (aka UHT) will require you a lot of control.
- GenerateProjectFiles.sh from Unreal Engine Repository (It's in the root directory, you could easily find it) will help you make a project file just works fine for thy device.
- At least you could check your compile error without running the heavy GUi Tool.

# Dependencies
- sh
- make
- Unreal Engine (repository, built)
- Your clear mind

# Unreal Engine Repository
> https://github.com/EpicGames/UnrealEngine

- When you build it, it will work   [Tested]
    - 165GiB for after building (For size of Repository)
    - 340+GiB while building
        > That almost fried my computer with disk of 256GB.


# init.sh
- Requires the absolute path for Unreal Engine Source Repository 

# UERoot
- A full path for Unreal Engine Repostory's root
- 

# Usage
## Configuration
> You will need to direct the `UERoot` from `init.sh` as thy Unreal Engine Repository Directory.  
> This is how variable should look alike:
```sh
UERoot=/path/to/thy/UnrealEngine/
```

> After that you are now able to build like:
```sh
sh init.sh # It will generate the Makefiles for thee.
make # Actually builds the project
```

# Etc
> I am not including Makefiles since I am not sure if it will work on different environments such alike:
- Different directory for Unreal Engine

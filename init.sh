# This is a main logic section.
# It means its value and logic are not supposed to change.


# Basics
PWD=$(pwd)

source ./env.sh


# Variables
osname=$(uname -s)
proj=$PWD/TCG_Sample.uproject
projgen=$UERoot/GenerateProjectFiles

shell=""
bin_ext=""

case "$osname" in
	Linux)
		shell=sh
		bin_ext=""

		;;
	Darwin)
		shell=sh
		bin_ext=""
		;;
	MINGW*|MSYS*)
		shell=cmd
		bin_ext=.exe
		;;

	*)
		echo "I have no clue what are you running this on"
		;;
esac

"$UEEngine"/Binaries/DotNET/UnrealBuildTool/UnrealBuildTool$bin_ext -projectfiles -project=$PWD/TCG_Sample.uproject -game -engine -makefile

# Basics
PWD=$(pwd)

# Parameters
# You may change them
UERoot=~/UE2 
UEFlags=""


# Variables
osname=$(uname -s)
proj=$PWD/TCG_Sample.uproject
projgen=$UERoot/GenerateProjectFiles

shell=""
shell_ext=""

case "$osname" in
	Linux)
		shell=sh
		shell_ext=sh

		;;
	Darwin)
		shell=sh
		shell_ext=sh
		;;
	MINGW*|MSYS*)
		shell=cmd
		shell_ext=bat
		;;

	*)
		echo "I have no clue what are you running this on"
		;;
esac

$shell $projgen.$shell_ext $proj -game # $UEFlags

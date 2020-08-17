#!/bin/sh

# Ubuntu
if command -v apt-install &> /dev/null; then
    echo "Installing packages for Ubuntu"

    sudo apt install -y git build-essential binutils-mips-linux-gnu zlib1g-dev libcapstone-dev libyaml-dev || exit 1

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        sudo apt install -y python3 python3-pip clang-tidy astyle || exit 1
        python3 -m pip install stringcase || exit 1
    fi

    echo "Done"
    exit
fi

# Arch
if command -v pacman &> /dev/null; then
    echo "Installing packages for Arch"

    # Upgrade existing packages (note: no --noconfirm)
    sudo pacman -Syu || exit 1

    # Install dependencies
    sudo pacman -S --noconfirm --needed git base-devel zlib capstone libyaml || exit 1

    # Install binutils if required
    if ! command -v mips-linux-gnu-ar &> /dev/null; then
        PKG="mips-linux-gnu-binutils"
        if command -v aura &> /dev/null; then
            sudo aura -A --noconfirm $PKG || exit 1
        elif command -v yay &> /dev/null; then
            yay -S --noconfirm $PKG || exit 1
        elif command -v yaourt &> /dev/null; then
            sudo yaourt -S --noconfirm $PKG || exit 1
        else
            echo "AUR manager not found, installing $PKG without one"

            git clone "https://aur.archlinux.org/$PKG.git" || exit 1
            cd $PKG
            makepkg -si || exit 1
            cd ..
            rm -rf $PKG
        fi
    fi

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        sudo pacman -S --noconfirm --needed python python-pip clang astyle || exit 1
        python3 -m pip install stringcase || exit 1
    fi

    echo "Done"
    exit
fi

echo "Only Ubuntu (apt) and Arch Linux (pacman) are supported by install.sh."
echo "Please consider contributing and adding an installation script for your distro."
exit 1

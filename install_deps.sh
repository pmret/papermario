#!/usr/bin/env bash

if [[ "$UID" -eq "0" ]]; then
    SUDO=""
else
    SUDO=sudo
fi

uname=`uname`
unset supported

if [[ "$uname" == "Darwin" ]]; then
    supported=true

    echo "Installing packages for macOS"

    if ! command -v brew >/dev/null 2>&1; then
        # Install Homebrew
        /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)" || exit 1
    fi

    # Install packages
    brew install md5sha1sum ninja gcc bates64/brew/mips-linux-gnu-binutils bates64/brew/mips-linux-gnu-gcc || exit 1
    python3 -m pip install -U -r tools/configure/requirements.txt || exit 1
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
    exit 0
fi

# Debian and derivatives (apt)
if cat /etc/os-release | grep -E 'ID=debian|ID_LIKE=(.*)debian' &> /dev/null; then
    supported=true

    echo "Installing packages for Debian or derivative (apt)"

    ${SUDO} apt install -y curl git python3 python3-pip python3-setuptools build-essential binutils-mips-linux-gnu zlib1g-dev libyaml-dev ninja-build cpp-mips-linux-gnu gcc-mips-linux-gnu || exit 1
    python3 -m pip install -U -r tools/configure/requirements.txt
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        ${SUDO} apt install -y clang-tidy astyle doxygen || exit 1
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
fi

# Fedora (dnf)
if cat /etc/os-release | grep -E ID=fedora &> /dev/null; then
    supported=true

    echo "Installing packages for Fedora (dnf)"

    ${SUDO} dnf install -y curl git python3 python3-pip python3-setuptools ninja-build gcc-mips64-linux-gnu libyaml-devel zlib-devel || exit 1
    ${SUDO} dnf group info "C Development Tools and Libraries" "Development Tools" || exit 1
    # Install binutils if required
    if ! command -v mips-linux-gnu-ar &> /dev/null; then
        PKG="mips-linux-gnu-binutils"

        RETURNDIR="$(pwd)"
        cd "$(mktemp -d)"

        wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.bz2
        tar -xf binutils-2.35.tar.bz2

        cd binutils-2.35
        sed -i "/ac_cpp=/s/\$CPPFLAGS/\$CPPFLAGS -O2/" libiberty/configure
        ./configure --target=mips-linux-gnu \
                    --with-sysroot=/usr/mips-linux-gnu \
                    --prefix=/usr \
                    --disable-multilib \
                    --with-gnu-as \
                    --with-gnu-ld \
                    --disable-nls \
                    --enable-ld=default \
                    --enable-plugins \
                    --enable-deterministic-archives \
                    --disable-werror
        ${SUDO} make
        ${SUDO} make install

        cd ..
        # delete temp directory we made
        rm -rf "$(pwd)"
        # go back to old dir
        cd "${RETURNDIR}"
    fi
    python3 -m pip install -U -r tools/configure/requirements.txt
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        ${SUDO} dnf install -y clang-tools-extra astyle doxygen || exit 1
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
fi

# Arch Linux and derivatives (pacman)
if cat /etc/os-release | grep -E 'ID=arch|ID_LIKE="?arch"?' &> /dev/null; then
    supported=true

    echo "Installing packages for Arch Linux or derivative (pacman)"

    # Upgrade existing packages (note: no --noconfirm)
    ${SUDO} pacman -Syu || exit 1

    # Install dependencies
    ${SUDO} pacman -S --noconfirm --needed curl git python python-pip python-setuptools base-devel zlib libyaml ninja || exit 1
    python3 -m pip install -U -r tools/configure/requirements.txt
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    # Install binutils if required
    if ! command -v mips-linux-gnu-ar &> /dev/null; then
        PKG="mips-linux-gnu-binutils"
        if command -v aura &> /dev/null; then
            ${SUDO} aura -A --noconfirm $PKG || exit 1
        elif command -v yay &> /dev/null; then
            yay -S --noconfirm $PKG || exit 1
        elif command -v yaourt &> /dev/null; then
            ${SUDO} yaourt -S --noconfirm $PKG || exit 1
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
        ${SUDO} pacman -S --noconfirm --needed clang astyle doxygen || exit 1
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
fi

# openSUSE (zypper)
if cat /etc/os-release | grep ID=opensuse &> /dev/null; then
    supported=true

    echo "Installing packages for openSUSE (zypper)"

    ${SUDO} zypper -n curl install git python3 python3-devel python3-pip python3-setuptools gcc gcc-c++ glibc-devel make cross-mips-binutils zlib-devel libyaml-devel ninja

    # Link the openSUSE locations for binutils tools to their usual GNU locations
    ${SUDO} ln -s /usr/bin/mips-suse-linux-addr2line /usr/bin/mips-linux-gnu-addr2line
    ${SUDO} ln -s /usr/bin/mips-suse-linux-ar /usr/bin/mips-linux-gnu-ar
    ${SUDO} ln -s /usr/bin/mips-suse-linux-as /usr/bin/mips-linux-gnu-as
    ${SUDO} ln -s /usr/bin/mips-suse-linux-elfedit /usr/bin/mips-linux-gnu-elfedit
    ${SUDO} ln -s /usr/bin/mips-suse-linux-gprof /usr/bin/mips-linux-gnu-gprof
    ${SUDO} ln -s /usr/bin/mips-suse-linux-ld /usr/bin/mips-linux-gnu-ld
    ${SUDO} ln -s /usr/bin/mips-suse-linux-ld.bfd /usr/bin/mips-linux-gnu-ld.bfd
    ${SUDO} ln -s /usr/bin/mips-suse-linux-nm /usr/bin/mips-linux-gnu-nm
    ${SUDO} ln -s /usr/bin/mips-suse-linux-objcopy /usr/bin/mips-linux-gnu-objcopy
    ${SUDO} ln -s /usr/bin/mips-suse-linux-objdump /usr/bin/mips-linux-gnu-objdump
    ${SUDO} ln -s /usr/bin/mips-suse-linux-ranlib /usr/bin/mips-linux-gnu-ranlib
    ${SUDO} ln -s /usr/bin/mips-suse-linux-readelf /usr/bin/mips-linux-gnu-readelf
    ${SUDO} ln -s /usr/bin/mips-suse-linux-size /usr/bin/mips-linux-gnu-size
    ${SUDO} ln -s /usr/bin/mips-suse-linux-strings /usr/bin/mips-linux-gnu-strings
    ${SUDO} ln -s /usr/bin/mips-suse-linux-strip /usr/bin/mips-linux-gnu-strip

    python3 -m pip install -U -r tools/configure/requirements.txt
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        ${SUDO} zypper -n install clang astyle doxygen || exit 1
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
fi

# Alpine Linux (apk)
if cat /etc/os-release | grep ID=alpine &> /dev/null; then
    supported=true

    echo "Installing packages for Alpine Linux (apk)"

    # If the edge/community repo isn't present, it needs to be for astyle
    if ! grep -q "edge/community" /etc/apk/repositories; then
        echo "http://dl-cdn.alpinelinux.org/alpine/edge/community" >> /etc/apk/repositories
    fi

    # Install dependencies
    ${SUDO} apk add --no-cache bash curl wget git python3 python3-dev py3-pip build-base zlib-dev yaml-dev ninja
    python3 -m pip install -U -r tools/configure/requirements.txt
    cp tools/precommit_check_no_assets.sh "$(git rev-parse --git-path hooks)/pre-commit" || exit 1

    # Install binutils if required
    if ! command -v mips-linux-gnu-ar &> /dev/null; then
        PKG="mips-linux-gnu-binutils"

        RETURNDIR="$(pwd)"
        cd "$(mktemp -d)"

        wget https://ftp.gnu.org/gnu/binutils/binutils-2.35.tar.bz2
        tar -xf binutils-2.35.tar.bz2

        cd binutils-2.35
        sed -i "/ac_cpp=/s/\$CPPFLAGS/\$CPPFLAGS -O2/" libiberty/configure
        ./configure --target=mips-linux-gnu \
                    --with-sysroot=/usr/mips-linux-gnu \
                    --prefix=/usr \
                    --disable-multilib \
                    --with-gnu-as \
                    --with-gnu-ld \
                    --disable-nls \
                    --enable-ld=default \
                    --enable-plugins \
                    --enable-deterministic-archives \
                    --disable-werror
        ${SUDO} make
        ${SUDO} make install

        cd ..
        # delete temp directory we made
        rm -rf "$(pwd)"
        # go back to old dir
        cd "${RETURNDIR}"
    fi

    if [[ $1 == "--extra" ]]; then
        echo "Installing extra"
        ${SUDO} apk add --no-cache clang-extra-tools astyle doxygen || exit 1
        python3 -m pip install -U -r tools/configure/requirements_extra.txt || exit 1
    fi
fi


if [ "$supported" != true ]; then
    echo "The following distros (and their derivatives) are supported by install_deps.sh:"
    echo "- Debian/Ubuntu (apt)"
    echo "- Arch Linux (pacman)"
    echo "- openSUSE (zypper)"
    echo "- Alpine Linux (apk)"
    echo "- Fedora (dnf)"
    echo "Please consider contributing and adding an installation script for your distro."
    exit 1
fi

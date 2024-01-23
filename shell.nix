{ pkgsNative ? import <nixpkgs> {}
, pkgsCross ? import (builtins.fetchTarball {
    # This commit uses binutils 2.39. We don't want binutils 2.40+ because of a performance regression in ld.
    url = "https://github.com/NixOS/nixpkgs/archive/55070e598e0e03d1d116c49b9eff322ef07c6ac6.tar.gz";
  }) {
    crossSystem = { config = "mips-linux-gnu"; };
  }
}:

let
  gcc-papermario = builtins.fetchurl {
    url =
      "https://github.com/pmret/gcc-papermario/releases/download/master/linux.tar.gz";
    sha256 = "1156cf0d6a88a64c20e2a10fc9445d99cb9a38518f432b1669528dfa82ebb45f";
  };

  binutils-papermario = builtins.fetchurl {
    url =
      "https://github.com/pmret/binutils-papermario/releases/download/master/linux.tar.gz";
    sha256 = "c3cd88db47ac41f78b557042c7e7ad47ac9c04cee6f0d1069a489c1c9e8c103c";
  };

  mips-gcc-272 = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz";
    sha256 = "ff3e299c1d952c0a5cb39f7790a208d0c547cf93986eb5607f820c935cedc288";
  };

  mips-binutils-26 = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz";
    sha256 = "405a7ddb29a0b2eb472b167e8f15472223df1eff3093a5ff31d6e545d3a6c670";
  };

  egcs-binutils = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-binutils-egcs-2.9.5/releases/latest/download/mips-binutils-egcs-2.9.5-linux.tar.gz";
    sha256 = "04pdjk5n7xw7y4xamc4nisq0vdipsxgpq3jmd7j48gfn0hx9kz21";
  };

  egcs-gcc = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-gcc-egcs-2.91.66/releases/latest/download/mips-gcc-egcs-2.91.66-linux.tar.gz";
    sha256 = "03v1ci7j0hi53z639rwj60xwz0zzi82a9azi0yiw818r754faql0";
  };

  ido = builtins.fetchurl {
    url =
      "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-ubuntu-latest.tar.gz";
    sha256 = "65b42b9673b6f439e45e5dafab1eca4fc006a68cda87bdb55681f027d9fb903c";
  };
in pkgsCross.mkShell {
  nativeBuildInputs = (with pkgsNative; [
    ninja
    zlib
    libyaml
    patchelf
    glibc
    python3
    python3Packages.virtualenv
    cargo
    rustc
  ]);
  buildInputs = (with pkgsCross; [
    gcc
    binutils
  ]);

  shellHook = ''
    # Install compilers
    # TODO: use pkgs.stdenv.mkDerivation instead of extracting here
    tar zx -C tools/build/cc/gcc -f ${gcc-papermario}
    tar zx -C tools/build/cc/gcc -f ${binutils-papermario}
    tar zx -C tools/build/cc/gcc2.7.2 -f ${mips-gcc-272}
    tar zx -C tools/build/cc/gcc2.7.2 -f ${mips-binutils-26}
    tar zx -C tools/build/cc/ido5.3 -f ${ido}
    tar zx -C tools/build/cc/egcs -f ${egcs-binutils}
    tar zx -C tools/build/cc/egcs -f ${egcs-gcc}

    # Fix 'file not found' errors since we're using a newer glibc
    for dir in $(find tools/build/cc -type d); do
      for f in $(find $dir -type f); do
        # Silence errors instead of thinking hard about this
        ${pkgsNative.patchelf}/bin/patchelf --set-interpreter "${pkgsNative.glibc}/lib/ld-linux-x86-64.so.2" $f 2>/dev/null
      done
    done

    # Install pigment64
    export PATH=$HOME/.cargo/bin:$PATH
    cargo install pigment64

    # Install python packages
    virtualenv venv
    source venv/bin/activate
    pip install -r ${./requirements.txt}
    pip install -r ${./requirements_extra.txt}
  '';
}

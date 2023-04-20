{ pkgsNative ? import <nixpkgs> { }
, pkgsCross ? import <nixpkgs> { crossSystem = { config = "mips-linux-gnu"; }; }
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

  gcc-papermario-272 = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-linux.tar.gz";
    sha256 = "ff3e299c1d952c0a5cb39f7790a208d0c547cf93986eb5607f820c935cedc288";
  };

  binutils-papermario-272 = builtins.fetchurl {
    url =
      "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-linux.tar.gz";
    sha256 = "405a7ddb29a0b2eb472b167e8f15472223df1eff3093a5ff31d6e545d3a6c670";
  };

  ido = builtins.fetchurl {
    url =
      "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-ubuntu-latest.tar.gz";
    sha256 = "65b42b9673b6f439e45e5dafab1eca4fc006a68cda87bdb55681f027d9fb903c";
  };
in pkgsCross.mkShell {
  nativeBuildInputs =
    (with pkgsNative; [ ninja zlib libyaml patchelf glibc gcc ]);
  buildInputs = with pkgsNative;
    [ python3Packages.python python3Packages.venvShellHook ]
    ++ (with pkgsCross; [ gcc binutils ]);

  # This is a very un-Nix-y way of doing things
  # mach-nix and pip2nix both struggle with venvs, and I'm not sure how to best approach the binaries
  venvDir = "./venv";
  postVenvCreation =
    "pip install -r requirements.txt -r requirements_extra.txt";
  shellHook = ''
    tar zx -C tools/build/cc/gcc -f ${gcc-papermario}
    tar zx -C tools/build/cc/gcc -f ${binutils-papermario}

    tar zx -C tools/build/cc/gcc2.7.2 -f ${gcc-papermario-272}
    tar zx -C tools/build/cc/gcc2.7.2 -f ${binutils-papermario-272}

    tar zx -C tools/build/cc/ido5.3 -f ${ido}

    needs_patching=(
      tools/build/cc/gcc
      tools/build/cc/gcc2.7.2
      tools/build/cc/ido5.3
    )

    for dir in $needs_patching; do
      for f in $(find $dir -type f); do
        # Silence errors instead of thinking hard about this
        patchelf --set-interpreter "${pkgsNative.glibc}/lib/ld-linux-x86-64.so.2" $f 2>/dev/null
      done
    done
  '';
}

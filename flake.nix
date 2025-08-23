{
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-25.05";

    # This commit uses binutils 2.39. We don't want binutils 2.40+ because of a performance regression in ld.
    nixpkgs-binutils-2_39.url = "github:NixOS/nixpkgs/55070e598e0e03d1d116c49b9eff322ef07c6ac6";

    flake-utils.url = "github:numtide/flake-utils";

    dream2nix.url = "github:nix-community/dream2nix";
    dream2nix.inputs.nixpkgs.follows = "nixpkgs";
  };
  nixConfig = {
    extra-substituters = [
      "https://papermario-dx.cachix.org"
    ];
    extra-trusted-public-keys = [
      "papermario-dx.cachix.org-1:VTXILrqiajck9s5U2O3nDJH0pAI64GAJK41b2pt1JIk="
    ];
  };
  outputs = {
    nixpkgs,
    nixpkgs-binutils-2_39,
    flake-utils,
    dream2nix,
    ...
  }:
    flake-utils.lib.eachDefaultSystem (
      system: let
        crossSystem = {
          config = "mips-linux-gnu";
        };
        pkgs = import nixpkgs {inherit system;};
        pkgsCross = import nixpkgs {inherit system crossSystem;};
        binutils2_39 = (import nixpkgs-binutils-2_39 {inherit system crossSystem;}).buildPackages.binutilsNoLibc;

        hashFromVersion = version: builtins.elemAt (builtins.match "([a-f0-9]+) .*" (builtins.readFile ./ver/${version}/checksum.sha1)) 0;
        requireBaseRom = version:
          pkgs.requireFile rec {
            name = "papermario.${version}.z64";
            message = ''
              papermario requires a base ROM.

              Please add it to the Nix store using
                  nix store add --mode flat --name ${name} --hash-algo sha1 path/to/${name}
            '';
            sha1 = hashFromVersion version;
          };

        configure = dream2nix.lib.evalModules {
          packageSets.nixpkgs = pkgs;
          modules = [
            ./tools/configure/default.nix
            {
              paths = {
                projectRoot = ./.;
                projectRootFile = "flake.nix";
                package = ./tools/configure;
              };
            }
          ];
        };
        commonBuildInputs = with pkgs; [
          configure
          configure.pyEnv
          ninja
          zlib
          libyaml
          python3
          ccache
          git
          iconv
          gcc # for n64crc
          (callPackage ./tools/pigment64.nix {})
          (callPackage ./tools/crunch64.nix {})
        ];
        commonCompilers = let
          isLinux = pkgs.stdenv.isLinux;
          osGcc =
            if isLinux
            then "linux"
            else "mac";
          osIdo =
            if isLinux
            then "ubuntu"
            else "macos";
        in {
          gcc = [
            (pkgs.fetchzip {
              name = "gcc-papermario";
              version = "master";
              url = "https://github.com/pmret/gcc-papermario/releases/download/master/${osGcc}.tar.gz";
              sha256 =
                if isLinux
                then "sha256-bFlt13n13a7UZulwkcdrwRbXfXRWkUTqszAczzAs8Ac="
                else "sha256-mkBPLgGPg/tKKRwnVXLVULzd4HuuZabZJccy/t7a2ZI=";
              stripRoot = false;
            })
            (pkgs.fetchzip {
              name = "binutils-papermario";
              version = "master";
              url = "https://github.com/pmret/binutils-papermario/releases/download/master/${osGcc}.tar.gz";
              sha256 =
                if isLinux
                then "sha256-HdVaaOjFBJYywA/+uQ2wsqmJrEwBEuFSdo9jPb4qceE="
                else "sha256-sqpEhIypLleEnJJIAw0+JR7mg8cESWUhr4Umh8GURNE=";
              stripRoot = false;
            })
          ];
          "gcc2.7.2" = [
            (pkgs.fetchzip {
              name = "mips-gcc";
              version = "2.7.2";
              url = "https://github.com/decompals/mips-gcc-2.7.2/releases/download/main/gcc-2.7.2-${osGcc}.tar.gz";
              sha256 =
                if isLinux
                then "sha256-0orDbWWom581bJ60SvE96ct5H9Mua0c3gyMHbY7DzRE="
                else "sha256-A7CH2JNLlY6aFgI/L6AvvsnRJrAu3KYZFWwmqJ6ZWWA=";
              stripRoot = false;
            })
            (pkgs.fetchzip {
              name = "mips-binutils";
              version = "2.6";
              url = "https://github.com/decompals/mips-binutils-2.6/releases/download/main/binutils-2.6-${osGcc}.tar.gz";
              sha256 =
                if isLinux
                then "sha256-237UECnNLGSBZEyLJr9rEHC3cT2m5pS0ApDjgkL3WqM="
                else "sha256-1hbEAXjN00+tnfXqbeMX1D8OWordLoeWXf++KF7YsMM=";
              stripRoot = false;
            })
          ];
          "ido5.3" = [
            (pkgs.fetchzip {
              name = "ido";
              version = "5.3";
              url = "https://github.com/decompals/ido-static-recomp/releases/download/v0.2/ido-5.3-recomp-${osIdo}-latest.tar.gz";
              sha256 =
                if isLinux
                then "sha256-LvEmsxIeF+JFZFLjIBBbHjDb1ZuvFB5XParZDqamVhE="
                else "sha256-5P93jXkgj2kQP+54gXvtDMLyRI5JvJcjsCBEVCQMKTg=";
              stripRoot = false;
            })
          ];
        };
        iqueCompilers =
          if pkgs.stdenv.isDarwin
          then {}
          else {
            "egcs" = [
              (pkgs.fetchzip {
                name = "egcs-gcc";
                version = "2.91.66";
                url = "https://github.com/decompals/mips-gcc-egcs-2.91.66/releases/latest/download/mips-gcc-egcs-2.91.66-linux.tar.gz";
                sha256 = "sha256-nEr2btiRvUnciBK8Rh42JyJmseT3PAZvhs/UUiMLvH4=";
                stripRoot = false;
              })
              (pkgs.fetchzip {
                name = "egcs-binutils";
                version = "2.9.5";
                url = "https://github.com/decompals/mips-binutils-egcs-2.9.5/releases/latest/download/mips-binutils-egcs-2.9.5-linux.tar.gz";
                sha256 = "sha256-v8KAW4OoLtxyPMeO1Uw5bTXFxOaEUi8ZN52J8l/Zols=";
                stripRoot = false;
              })
            ];
          };
        mkCompilerScript = compilers: let
          lib = pkgs.lib;
        in
          pkgs.writeShellScript "setup-compilers.sh" (lib.concatStringsSep "\n" (lib.mapAttrsToList (
              name: paths: let
                quotedPaths = lib.concatStringsSep " " (map (p: "\"${p}\"") paths);
              in
                ''
                  rm -rf tools/build/cc/${name}/*
                  mkdir -p tools/build/cc/${name}

                  for path in ${quotedPaths}; do
                    cp -r "$path"/* tools/build/cc/${name}/
                  done
                ''
                + lib.optionalString pkgs.stdenv.isLinux ''
                  # Fix 'cannot execute: required file not found' errors
                  for bin in tools/build/cc/${name}/*; do
                    ${pkgs.patchelf}/bin/patchelf --set-interpreter "${pkgs.glibc}/lib/ld-linux-x86-64.so.2" $bin 2>/dev/null || true
                  done
                ''
            )
            compilers));

        mkVersion = {
          version,
          compilers ? commonCompilers,
        }: {
          "papermario_${version}" = pkgsCross.ccacheStdenv.mkDerivation {
            name = "papermario";
            inherit version;
            src = ./.;
            nativeBuildInputs = commonBuildInputs;
            configurePhase = ''
              rm -f ver/${version}/baserom.z64 && cp ${requireBaseRom version} ver/${version}/baserom.z64
              . ${mkCompilerScript compilers}
              configure --ccache
            '';
            buildPhase = ''
              ninja
            '';
            installPhase = ''
              cp ver/${version}/build/papermario.elf $out
            '';
            dontStrip = true;
            enableParallelBuilding = true;
            outputHashMode = "flat";
            outputHashAlgo = "sha256";
            PAPERMARIO_LD = "${binutils2_39}/bin/mips-linux-gnu-ld";
          };
        };
      in {
        packages =
          {
            inherit configure; # for `nix run ".#configure.lock"` to update python lockfile
          }
          // mkVersion {version = "us";}
          // mkVersion {version = "jp";}
          // mkVersion {version = "pal";}
          // mkVersion {
            version = "ique";
            compilers = commonCompilers // iqueCompilers;
          };
        devShells = {
          default = pkgsCross.mkShell {
            name = "papermario";
            venvDir = "./venv";
            packages = commonBuildInputs;
            shellHook = ''
              rm -f ./ver/us/baserom.z64 && cp ${requireBaseRom "us"} ./ver/us/baserom.z64
              rm -f ./ver/jp/baserom.z64 && cp ${requireBaseRom "jp"} ./ver/jp/baserom.z64
              rm -f ./ver/pal/baserom.z64 && cp ${requireBaseRom "pal"} ./ver/pal/baserom.z64
              rm -f ./ver/ique/baserom.z64 && cp ${requireBaseRom "ique"} ./ver/ique/baserom.z64

              . ${mkCompilerScript (commonCompilers // iqueCompilers)}
            '';
            PAPERMARIO_LD = "${binutils2_39}/bin/mips-linux-gnu-ld";
          };
        };
        formatter = pkgs.alejandra;
      }
    );
}

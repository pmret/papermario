{
  config,
  lib,
  dream2nix,
  ...
}:
{
  imports = [
    dream2nix.modules.dream2nix.pip
  ];

  deps =
    { nixpkgs, ... }:
    {
      python = nixpkgs.python3;
    };

  name = "configure";
  version = "0.1.0";

  mkDerivation = {
    src = lib.cleanSourceWith {
      src = lib.cleanSource ./.;
      filter =
        name: _type:
        !(builtins.any (x: x) [
          (lib.hasSuffix ".nix" name)
          (lib.hasPrefix "." (builtins.baseNameOf name))
          (lib.hasSuffix "flake.lock" name)
        ]);
    };
  };

  buildPythonPackage = {
    pyproject = true;
    pythonImportsCheck = [
      "configure"
    ];
  };

  pip = {
    requirementsList =
      lib.strings.splitString "\n" (builtins.readFile ./requirements.txt)
      ++ lib.strings.splitString "\n" (builtins.readFile ./requirements_extra.txt);
    flattenDependencies = true;

    overrides.click = {
      buildPythonPackage.pyproject = true;
      mkDerivation.nativeBuildInputs = with config.deps.python.pkgs; [
        ninja
        zlib
        libyaml
        python3
        ccache
        git
        iconv
        gcc # for n64crc
        (callPackage ../pigment64.nix { })
        (callPackage ../crunch64.nix { })
      ];
    };
  };
}

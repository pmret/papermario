{
  lib,
  fetchFromGitHub,
  rustPlatform,
  ...
}:
rustPlatform.buildRustPackage rec {
  pname = "crunch64";
  version = "0.5.3";
  src = fetchFromGitHub {
    owner = "decompals";
    repo = pname;
    rev = version;
    hash = "sha256-Kuid2u5HzHfyeDOYlh18P/DKIbNr79zdpZlgQ560N4s=";
  };
  buildAndTestSubdir = "cli";
  cargoHash = "sha256-XO9nWhR1hDcx7t9ib6gHI1jSyvNbAUPzTlXQP8Ub7kw=";
  meta = with lib; {
    description = "Common N64 compression formats";
    homepage = "https://github.com/decompals/crunch64";
    license = licenses.mit;
  };
}

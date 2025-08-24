{
  lib,
  fetchFromGitHub,
  rustPlatform,
  ...
}:
rustPlatform.buildRustPackage rec {
  pname = "pigment64";
  version = "0.4.5";
  src = fetchFromGitHub {
    owner = "decompals";
    repo = pname;
    rev = version;
    hash = "sha256-AO9Gz3n/MiFyw1Q5/8rqCUKy8NToroSwvu7KBy+nQaY=";
  };
  cargoHash = "sha256-mX3yVGFnI1ZQP4E1Vj5IdluWS1KjBOBQYg5RJsczHLs=";
  meta = with lib; {
    description = "Performant image-generating modestly entertaining new tool...64";
    homepage = "https://github.com/decompals/pigment64";
    license = licenses.mit;
  };
}

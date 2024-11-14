{
  inputs = {
    nixpkgs.url = "github:nixos/nixpkgs";
    flake-utils.url = "github:numtide/flake-utils";
  };

  outputs = { self, nixpkgs, flake-utils, ... }:
    flake-utils.lib.eachDefaultSystem (system:
      let pkgs = import nixpkgs { system = system; };
      in {
        devShells = {
          cmake = with pkgs;
            mkShell {
              nativeBuildInputs = [ ripgrep clang-tools gnupatch gcc gnumake cargo];
              shellHook = ''
                nu
                exit
              '';
            };
          default = self.devShells.${system}.cmake;
        };

        formatter = pkgs.nixfmt-classic;
      });
}

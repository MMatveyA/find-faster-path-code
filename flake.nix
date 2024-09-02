{
  description = "Find faster path";
  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/24.05";
    utils.url = "github:numtide/flake-utils";
  };
  outputs = { self, nixpkgs, ... }@inputs:
    inputs.utils.lib.eachSystem [
      "x86_64-linux"
      "i686-linux"
      "aarch64-linux"
      "aarch64-darwin"
    ] (system:
      let
        pkgs = import nixpkgs {
          inherit system;
          overlays = [ ];
        };
      in {
        devShells.default = pkgs.callPackage ./shell.nix { };
        packages.default = pkgs.callPackage ./default.nix { };
      });
}

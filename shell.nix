{ pkgs ? import <nixpkgs> { }, ... }:
pkgs.mkShell rec {
  # Update the name to something that suites your project.
  name = "find-faster-path";

  packages = with pkgs; [
    # Development Tools
    llvmPackages_14.clang
    cmake

    # Development time dependencies
    doxygen
    gtest

    # Build time and Run time dependencies
    boost
    ncurses

    texliveFull
  ];

  # Setting up the environment variables you need during
  # development.
  shellHook = let icon = "f121";
  in ''
    export PS1="$(echo -e '\u${icon}') {\[$(tput sgr0)\]\[\033[38;5;228m\]\w\[$(tput sgr0)\]\[\033[38;5;15m\]} (${name}) \\$ \[$(tput sgr0)\]"

    export CC=${pkgs.llvmPackages_14.clang}/bin/clang
    export CXX=${pkgs.llvmPackages_14.clang}/bin/clang++
  '';
}

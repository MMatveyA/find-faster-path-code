{ pkgs, lib, config, inputs, ... }:

{
  packages = with pkgs; [ clang git ncurses ];

  languages = { cplusplus = { enable = true; }; };

  enterShell = ''
    echo
    echo
    clang --version
    echo
    git --version
  '';

}

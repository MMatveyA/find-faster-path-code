{ pkgs, ... }:

{
  packages = with pkgs; [ boost clang doxygen git ncurses ];

  languages = { cplusplus = { enable = true; }; };

  enterShell = ''
    echo
    echo
    clang --version
    echo
    git --version
  '';

}

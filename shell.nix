{ pkgs ? import <nixpkgs> { } }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    ncurses
    gcc
    universal-ctags
    gnumake
    gdb
  ];
}

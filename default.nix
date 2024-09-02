{ lib, llvmPackages_14, cmake, boost, doxygen, gnumake, ncurses, texliveFull }:
llvmPackages_14.stdenv.mkDerivation (finalAttrs: {
  pname = "find-faster-path";
  version = "0.0";

  src = ./.;

  nativeBuildInputs = [ cmake doxygen gnumake texliveFull ];
  buildInputs = [ boost ncurses ];

  cmakeFlags = [ "-DBUILD_DOC=ON" ];

  installPhase = ''
    cd docs/doxygen/latex
    make
    cd ../../../

    mkdir -p $out/bin $out/doc
    cp ./main $out/bin/find-faster-path
    cp docs/doxygen/latex/refman.pdf $out/doc/refman.pdf
  '';

  env = {
    TEXMFHOME = ".cache";
    TEXMFVAR = ".cache/texmf-var";
    # OSFONTDIR = "${pkgs.liberation_ttf}/share/fonts";
  };

  meta = {
    description = "Find faster path on 2D map";
    homepage = "https://github.com/MMatveyA/find-faster-path-code";
    license = lib.licenses.asl20-llvm;
    maintainers = with lib.maintainers; [ ];
  };
})

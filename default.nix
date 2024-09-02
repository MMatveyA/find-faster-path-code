{ lib, llvmPackages_14, cmake, boost, doxygen, ncurses }:
llvmPackages_14.stdenv.mkDerivation (finalAttrs: {
  pname = "find-faster-path";
  version = "0.0";

  src = ./.;

  nativeBuildInputs = [ cmake doxygen ];
  buildInputs = [ boost ncurses ];

  cmakeFlags = [ "-DBUILD_DOC=ON" ];

  installPhase = ''
    echo $(pwd)
    mkdir -p $out
    cp ./main $out/find-faster-path
  '';

  meta = {
    description = "Find faster path on 2D map";
    homepage = "https://github.com/MMatveyA/find-faster-path-code";
    license = lib.licenses.asl20-llvm;
    maintainers = with lib.maintainers; [ ];
  };
})

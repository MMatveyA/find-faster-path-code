{ lib, llvmPackages_14, boost, cmake, doxygen, gnumake, texliveFull }:
llvmPackages_14.stdenv.mkDerivation (finalAttrs: {
  pname = "find-faster-path";
  version = "0.0";

  src = ./.;

  nativeBuildInputs = [ cmake doxygen gnumake texliveFull ];
  buildInputs = [ boost ];

  cmakeFlags = [ "-DBUILD_DOC=OFF" ];

  env = {
    TEXMFHOME = ".cache";
    TEXMFVAR = ".cache/texmf-var";
  };

  meta = {
    description = "Find faster path on 2D map";
    homepage = "";
    license = lib.licenses.asl20-llvm;
    maintainers = with lib.maintainers; [ ];
  };
})

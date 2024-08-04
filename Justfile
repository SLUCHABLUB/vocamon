build:
    -@rm pokeemerald.gba
    @make -j8

run:
    @just build
    mgba pokeemerald.gba

clean:
    @make clean
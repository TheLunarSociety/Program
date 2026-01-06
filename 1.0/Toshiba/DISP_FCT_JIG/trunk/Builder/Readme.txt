ielftool.exe --fill 0xff;0x00000000-0x0001FFFF --bin --verbose "$TARGET_PATH$" "$TARGET_DIR$\Vivace_SW31100.bin"

"$TOOLKIT_DIR$\bin\isymexport.exe" "$TARGET_PATH$" "$PROJ_DIR$\Debug\Exe\SW31100_MakOS.symbols" --edit "$PROJ_DIR$\IAR_Config\sym_export.txt"
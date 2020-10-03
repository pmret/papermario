.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243FDC
/* 1728BC 80243FDC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1728C0 80243FE0 AFBF0010 */  sw        $ra, 0x10($sp)
/* 1728C4 80243FE4 0C093903 */  jal       func_8024E40C
/* 1728C8 80243FE8 24040002 */   addiu    $a0, $zero, 2
/* 1728CC 80243FEC 0C090464 */  jal       func_80241190
/* 1728D0 80243FF0 2404000C */   addiu    $a0, $zero, 0xc
/* 1728D4 80243FF4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 1728D8 80243FF8 03E00008 */  jr        $ra
/* 1728DC 80243FFC 27BD0018 */   addiu    $sp, $sp, 0x18

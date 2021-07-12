.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240404_A3FB44
/* A3FB44 80240404 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* A3FB48 80240408 3C01C396 */  lui       $at, 0xc396
/* A3FB4C 8024040C 44810000 */  mtc1      $at, $f0
/* A3FB50 80240410 3C01C2C8 */  lui       $at, 0xc2c8
/* A3FB54 80240414 44811000 */  mtc1      $at, $f2
/* A3FB58 80240418 3C0141F0 */  lui       $at, 0x41f0
/* A3FB5C 8024041C 44812000 */  mtc1      $at, $f4
/* A3FB60 80240420 3C054348 */  lui       $a1, 0x4348
/* A3FB64 80240424 3C0643C8 */  lui       $a2, 0x43c8
/* A3FB68 80240428 3C074496 */  lui       $a3, 0x4496
/* A3FB6C 8024042C 24040001 */  addiu     $a0, $zero, 1
/* A3FB70 80240430 AFBF0020 */  sw        $ra, 0x20($sp)
/* A3FB74 80240434 AFA00018 */  sw        $zero, 0x18($sp)
/* A3FB78 80240438 E7A00010 */  swc1      $f0, 0x10($sp)
/* A3FB7C 8024043C E7A20014 */  swc1      $f2, 0x14($sp)
/* A3FB80 80240440 0C01BF8C */  jal       playFX_0F
/* A3FB84 80240444 E7A4001C */   swc1     $f4, 0x1c($sp)
/* A3FB88 80240448 8FBF0020 */  lw        $ra, 0x20($sp)
/* A3FB8C 8024044C 24020002 */  addiu     $v0, $zero, 2
/* A3FB90 80240450 03E00008 */  jr        $ra
/* A3FB94 80240454 27BD0028 */   addiu    $sp, $sp, 0x28
/* A3FB98 80240458 00000000 */  nop
/* A3FB9C 8024045C 00000000 */  nop

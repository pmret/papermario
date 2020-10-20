.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024159C
/* 8ED3BC 8024159C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8ED3C0 802415A0 0000202D */  daddu     $a0, $zero, $zero
/* 8ED3C4 802415A4 240503E8 */  addiu     $a1, $zero, 0x3e8
/* 8ED3C8 802415A8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8ED3CC 802415AC 0C01559B */  jal       func_8005566C
/* 8ED3D0 802415B0 24060001 */   addiu    $a2, $zero, 1
/* 8ED3D4 802415B4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8ED3D8 802415B8 24020002 */  addiu     $v0, $zero, 2
/* 8ED3DC 802415BC 03E00008 */  jr        $ra
/* 8ED3E0 802415C0 27BD0018 */   addiu    $sp, $sp, 0x18

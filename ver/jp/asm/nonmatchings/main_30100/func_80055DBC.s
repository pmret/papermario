.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80055DBC
/* 311BC 80055DBC 3C05800A */  lui       $a1, %hi(D_8009A5A0)
/* 311C0 80055DC0 8CA5A5A0 */  lw        $a1, %lo(D_8009A5A0)($a1)
/* 311C4 80055DC4 2404000F */  addiu     $a0, $zero, 0xf
/* 311C8 80055DC8 8CA30094 */  lw        $v1, 0x94($a1)
.L80055DCC:
/* 311CC 80055DCC AC600000 */  sw        $zero, ($v1)
/* 311D0 80055DD0 24630004 */  addiu     $v1, $v1, 4
/* 311D4 80055DD4 0080102D */  daddu     $v0, $a0, $zero
/* 311D8 80055DD8 1440FFFC */  bnez      $v0, .L80055DCC
/* 311DC 80055DDC 2484FFFF */   addiu    $a0, $a0, -1
/* 311E0 80055DE0 8CA20094 */  lw        $v0, 0x94($a1)
/* 311E4 80055DE4 ACA00098 */  sw        $zero, 0x98($a1)
/* 311E8 80055DE8 ACA0009C */  sw        $zero, 0x9c($a1)
/* 311EC 80055DEC 03E00008 */  jr        $ra
/* 311F0 80055DF0 ACA20090 */   sw       $v0, 0x90($a1)

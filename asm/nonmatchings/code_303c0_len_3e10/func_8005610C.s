.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005610C
/* 3150C 8005610C 3C05800A */  lui       $a1, %hi(D_8009A5C0)
/* 31510 80056110 8CA5A5C0 */  lw        $a1, %lo(D_8009A5C0)($a1)
/* 31514 80056114 2404000F */  addiu     $a0, $zero, 0xf
/* 31518 80056118 8CA30094 */  lw        $v1, 0x94($a1)
.L8005611C:
/* 3151C 8005611C AC600000 */  sw        $zero, ($v1)
/* 31520 80056120 24630004 */  addiu     $v1, $v1, 4
/* 31524 80056124 0080102D */  daddu     $v0, $a0, $zero
/* 31528 80056128 1440FFFC */  bnez      $v0, .L8005611C
/* 3152C 8005612C 2484FFFF */   addiu    $a0, $a0, -1
/* 31530 80056130 8CA20094 */  lw        $v0, 0x94($a1)
/* 31534 80056134 ACA00098 */  sw        $zero, 0x98($a1)
/* 31538 80056138 ACA0009C */  sw        $zero, 0x9c($a1)
/* 3153C 8005613C 03E00008 */  jr        $ra
/* 31540 80056140 ACA20090 */   sw       $v0, 0x90($a1)

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80054C24
/* 30024 80054C24 04C10002 */  bgez      $a2, .L80054C30
/* 30028 80054C28 00C0102D */   daddu    $v0, $a2, $zero
/* 3002C 80054C2C 24C20003 */  addiu     $v0, $a2, 3
.L80054C30:
/* 30030 80054C30 00023083 */  sra       $a2, $v0, 2
/* 30034 80054C34 18C0000B */  blez      $a2, .L80054C64
/* 30038 80054C38 00851025 */   or       $v0, $a0, $a1
/* 3003C 80054C3C 30420003 */  andi      $v0, $v0, 3
/* 30040 80054C40 14400008 */  bnez      $v0, .L80054C64
/* 30044 80054C44 24C6FFFF */   addiu    $a2, $a2, -1
.L80054C48:
/* 30048 80054C48 8C820000 */  lw        $v0, ($a0)
/* 3004C 80054C4C 24840004 */  addiu     $a0, $a0, 4
/* 30050 80054C50 00C0182D */  daddu     $v1, $a2, $zero
/* 30054 80054C54 24C6FFFF */  addiu     $a2, $a2, -1
/* 30058 80054C58 ACA20000 */  sw        $v0, ($a1)
/* 3005C 80054C5C 1460FFFA */  bnez      $v1, .L80054C48
/* 30060 80054C60 24A50004 */   addiu    $a1, $a1, 4
.L80054C64:
/* 30064 80054C64 03E00008 */  jr        $ra
/* 30068 80054C68 00000000 */   nop
/* 3006C 80054C6C 00000000 */  nop

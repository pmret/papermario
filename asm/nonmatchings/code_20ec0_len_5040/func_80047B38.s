.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80047B38
/* 22F38 80047B38 00041040 */  sll       $v0, $a0, 1
/* 22F3C 80047B3C 00441021 */  addu      $v0, $v0, $a0
/* 22F40 80047B40 00021080 */  sll       $v0, $v0, 2
/* 22F44 80047B44 00441023 */  subu      $v0, $v0, $a0
/* 22F48 80047B48 3C03800A */  lui       $v1, %hi(D_800A0F44)
/* 22F4C 80047B4C 8C630F44 */  lw        $v1, %lo(D_800A0F44)($v1)
/* 22F50 80047B50 00021100 */  sll       $v0, $v0, 4
/* 22F54 80047B54 00622821 */  addu      $a1, $v1, $v0
/* 22F58 80047B58 2403FFDF */  addiu     $v1, $zero, -0x21
/* 22F5C 80047B5C 8CA20000 */  lw        $v0, ($a1)
/* 22F60 80047B60 80A40068 */  lb        $a0, 0x68($a1)
/* 22F64 80047B64 00431024 */  and       $v0, $v0, $v1
/* 22F68 80047B68 14800004 */  bnez      $a0, .L80047B7C
/* 22F6C 80047B6C ACA20000 */   sw       $v0, ($a1)
/* 22F70 80047B70 24020001 */  addiu     $v0, $zero, 1
/* 22F74 80047B74 A0A20068 */  sb        $v0, 0x68($a1)
/* 22F78 80047B78 A0A2006A */  sb        $v0, 0x6a($a1)
.L80047B7C:
/* 22F7C 80047B7C 03E00008 */  jr        $ra
/* 22F80 80047B80 00000000 */   nop      

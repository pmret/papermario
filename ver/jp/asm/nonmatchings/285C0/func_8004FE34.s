.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FE34
/* 2B234 8004FE34 908600D6 */  lbu       $a2, 0xd6($a0)
/* 2B238 8004FE38 948200D4 */  lhu       $v0, 0xd4($a0)
/* 2B23C 8004FE3C 8C840064 */  lw        $a0, 0x64($a0)
/* 2B240 8004FE40 8CA30000 */  lw        $v1, ($a1)
/* 2B244 8004FE44 00441021 */  addu      $v0, $v0, $a0
/* 2B248 8004FE48 A4A6003E */  sh        $a2, 0x3e($a1)
/* 2B24C 8004FE4C ACA30004 */  sw        $v1, 4($a1)
/* 2B250 8004FE50 03E00008 */  jr        $ra
/* 2B254 8004FE54 ACA20000 */   sw       $v0, ($a1)

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004AED4
/* 262D4 8004AED4 3C03800A */  lui       $v1, %hi(D_800A19E0)
/* 262D8 8004AED8 246319E0 */  addiu     $v1, $v1, %lo(D_800A19E0)
/* 262DC 8004AEDC 90620000 */  lbu       $v0, ($v1)
/* 262E0 8004AEE0 14400007 */  bnez      $v0, .L8004AF00
/* 262E4 8004AEE4 00000000 */   nop
/* 262E8 8004AEE8 3C02800A */  lui       $v0, %hi(D_800A19F0)
/* 262EC 8004AEEC 244219F0 */  addiu     $v0, $v0, %lo(D_800A19F0)
/* 262F0 8004AEF0 AC620008 */  sw        $v0, 8($v1)
/* 262F4 8004AEF4 24020001 */  addiu     $v0, $zero, 1
/* 262F8 8004AEF8 AC600004 */  sw        $zero, 4($v1)
/* 262FC 8004AEFC A0620000 */  sb        $v0, ($v1)
.L8004AF00:
/* 26300 8004AF00 3C028005 */  lui       $v0, %hi(D_8004AD24)
/* 26304 8004AF04 2442AD24 */  addiu     $v0, $v0, %lo(D_8004AD24)
/* 26308 8004AF08 3C018008 */  lui       $at, %hi(D_80078148)
/* 2630C 8004AF0C AC208148 */  sw        $zero, %lo(D_80078148)($at)
/* 26310 8004AF10 03E00008 */  jr        $ra
/* 26314 8004AF14 AC830000 */   sw       $v1, ($a0)

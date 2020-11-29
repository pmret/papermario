.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_800EE994
/* 87E44 800EE994 8C830000 */  lw        $v1, ($a0)
/* 87E48 800EE998 3C020001 */  lui       $v0, 1
/* 87E4C 800EE99C AC820080 */  sw        $v0, 0x80($a0)
/* 87E50 800EE9A0 0000102D */  daddu     $v0, $zero, $zero
/* 87E54 800EE9A4 3C018011 */  lui       $at, %hi(D_8010CFC8)
/* 87E58 800EE9A8 A420CFC8 */  sh        $zero, %lo(D_8010CFC8)($at)
/* 87E5C 800EE9AC 34630100 */  ori       $v1, $v1, 0x100
/* 87E60 800EE9B0 03E00008 */  jr        $ra
/* 87E64 800EE9B4 AC830000 */   sw       $v1, ($a0)

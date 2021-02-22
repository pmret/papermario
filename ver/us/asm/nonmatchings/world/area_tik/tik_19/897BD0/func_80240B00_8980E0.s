.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240B00_8980E0
/* 8980E0 80240B00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8980E4 80240B04 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8980E8 80240B08 8C82000C */  lw        $v0, 0xc($a0)
/* 8980EC 80240B0C 0C0B1EAF */  jal       get_variable
/* 8980F0 80240B10 8C450000 */   lw       $a1, ($v0)
/* 8980F4 80240B14 0040202D */  daddu     $a0, $v0, $zero
/* 8980F8 80240B18 8C830000 */  lw        $v1, ($a0)
/* 8980FC 80240B1C 34630010 */  ori       $v1, $v1, 0x10
/* 898100 80240B20 AC830000 */  sw        $v1, ($a0)
/* 898104 80240B24 8FBF0010 */  lw        $ra, 0x10($sp)
/* 898108 80240B28 24020002 */  addiu     $v0, $zero, 2
/* 89810C 80240B2C 03E00008 */  jr        $ra
/* 898110 80240B30 27BD0018 */   addiu    $sp, $sp, 0x18

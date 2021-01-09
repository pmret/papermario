.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8024051C_9EE10C
/* 9EE10C 8024051C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9EE110 80240520 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9EE114 80240524 8C82000C */  lw        $v0, 0xc($a0)
/* 9EE118 80240528 0C0B1EAF */  jal       get_variable
/* 9EE11C 8024052C 8C450000 */   lw       $a1, ($v0)
/* 9EE120 80240530 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9EE124 80240534 3C018024 */  lui       $at, %hi(func_80241438_8535A8)
/* 9EE128 80240538 AC221438 */  sw        $v0, %lo(func_80241438_8535A8)($at)
/* 9EE12C 8024053C 24020002 */  addiu     $v0, $zero, 2
/* 9EE130 80240540 03E00008 */  jr        $ra
/* 9EE134 80240544 27BD0018 */   addiu    $sp, $sp, 0x18

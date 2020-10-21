.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240510_989070
/* 989070 80240510 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 989074 80240514 AFBF0010 */  sw        $ra, 0x10($sp)
/* 989078 80240518 8C82000C */  lw        $v0, 0xc($a0)
/* 98907C 8024051C 0C0B1EAF */  jal       get_variable
/* 989080 80240520 8C450000 */   lw       $a1, ($v0)
/* 989084 80240524 0040202D */  daddu     $a0, $v0, $zero
/* 989088 80240528 8C830000 */  lw        $v1, ($a0)
/* 98908C 8024052C 34630010 */  ori       $v1, $v1, 0x10
/* 989090 80240530 AC830000 */  sw        $v1, ($a0)
/* 989094 80240534 8FBF0010 */  lw        $ra, 0x10($sp)
/* 989098 80240538 24020002 */  addiu     $v0, $zero, 2
/* 98909C 8024053C 03E00008 */  jr        $ra
/* 9890A0 80240540 27BD0018 */   addiu    $sp, $sp, 0x18

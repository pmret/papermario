.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243A70_8042F0
/* 8042F0 80243A70 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8042F4 80243A74 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8042F8 80243A78 8C82000C */  lw        $v0, 0xc($a0)
/* 8042FC 80243A7C 0C0B1EAF */  jal       get_variable
/* 804300 80243A80 8C450000 */   lw       $a1, ($v0)
/* 804304 80243A84 00021600 */  sll       $v0, $v0, 0x18
/* 804308 80243A88 0C03AC5A */  jal       func_800EB168
/* 80430C 80243A8C 00022603 */   sra      $a0, $v0, 0x18
/* 804310 80243A90 8FBF0010 */  lw        $ra, 0x10($sp)
/* 804314 80243A94 24020002 */  addiu     $v0, $zero, 2
/* 804318 80243A98 03E00008 */  jr        $ra
/* 80431C 80243A9C 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80045798
/* 20B98 80045798 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 20B9C 8004579C AFBF0010 */  sw        $ra, 0x10($sp)
/* 20BA0 800457A0 8C82000C */  lw        $v0, 0xc($a0)
/* 20BA4 800457A4 0C0B1EAF */  jal       get_variable
/* 20BA8 800457A8 8C450000 */   lw       $a1, ($v0)
/* 20BAC 800457AC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 20BB0 800457B0 3C018011 */  lui       $at, 0x8011
/* 20BB4 800457B4 AC22EF08 */  sw        $v0, -0x10f8($at)
/* 20BB8 800457B8 24020002 */  addiu     $v0, $zero, 2
/* 20BBC 800457BC 03E00008 */  jr        $ra
/* 20BC0 800457C0 27BD0018 */   addiu    $sp, $sp, 0x18

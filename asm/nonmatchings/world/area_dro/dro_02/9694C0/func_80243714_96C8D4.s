.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243714_96C8D4
/* 96C8D4 80243714 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 96C8D8 80243718 AFBF0010 */  sw        $ra, 0x10($sp)
/* 96C8DC 8024371C 8C82000C */  lw        $v0, 0xc($a0)
/* 96C8E0 80243720 3C068011 */  lui       $a2, 0x8011
/* 96C8E4 80243724 80C6F2A2 */  lb        $a2, -0xd5e($a2)
/* 96C8E8 80243728 0C0B2026 */  jal       set_variable
/* 96C8EC 8024372C 8C450000 */   lw       $a1, ($v0)
/* 96C8F0 80243730 0C03AC5A */  jal       func_800EB168
/* 96C8F4 80243734 0000202D */   daddu    $a0, $zero, $zero
/* 96C8F8 80243738 8FBF0010 */  lw        $ra, 0x10($sp)
/* 96C8FC 8024373C 24020002 */  addiu     $v0, $zero, 2
/* 96C900 80243740 03E00008 */  jr        $ra
/* 96C904 80243744 27BD0018 */   addiu    $sp, $sp, 0x18

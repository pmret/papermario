.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802406FC_87A2DC
/* 87A2DC 802406FC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 87A2E0 80240700 AFBF0010 */  sw        $ra, 0x10($sp)
/* 87A2E4 80240704 8C82000C */  lw        $v0, 0xc($a0)
/* 87A2E8 80240708 0C0B1EAF */  jal       get_variable
/* 87A2EC 8024070C 8C450000 */   lw       $a1, ($v0)
/* 87A2F0 80240710 0C03AC5A */  jal       func_800EB168
/* 87A2F4 80240714 0040202D */   daddu    $a0, $v0, $zero
/* 87A2F8 80240718 8FBF0010 */  lw        $ra, 0x10($sp)
/* 87A2FC 8024071C 24020002 */  addiu     $v0, $zero, 2
/* 87A300 80240720 03E00008 */  jr        $ra
/* 87A304 80240724 27BD0018 */   addiu    $sp, $sp, 0x18

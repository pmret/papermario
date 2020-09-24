.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel GetSelfVar
/* 206C0 800452C0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 206C4 800452C4 AFB20018 */  sw        $s2, 0x18($sp)
/* 206C8 800452C8 0080902D */  daddu     $s2, $a0, $zero
/* 206CC 800452CC AFBF001C */  sw        $ra, 0x1c($sp)
/* 206D0 800452D0 AFB10014 */  sw        $s1, 0x14($sp)
/* 206D4 800452D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 206D8 800452D8 8E51000C */  lw        $s1, 0xc($s2)
/* 206DC 800452DC 8E500148 */  lw        $s0, 0x148($s2)
/* 206E0 800452E0 8E250000 */  lw        $a1, ($s1)
/* 206E4 800452E4 0C0B1EAF */  jal       get_variable
/* 206E8 800452E8 26310004 */   addiu    $s1, $s1, 4
/* 206EC 800452EC 00021080 */  sll       $v0, $v0, 2
/* 206F0 800452F0 02028021 */  addu      $s0, $s0, $v0
/* 206F4 800452F4 8E250000 */  lw        $a1, ($s1)
/* 206F8 800452F8 8E06006C */  lw        $a2, 0x6c($s0)
/* 206FC 800452FC 0C0B2026 */  jal       set_variable
/* 20700 80045300 0240202D */   daddu    $a0, $s2, $zero
/* 20704 80045304 8FBF001C */  lw        $ra, 0x1c($sp)
/* 20708 80045308 8FB20018 */  lw        $s2, 0x18($sp)
/* 2070C 8004530C 8FB10014 */  lw        $s1, 0x14($sp)
/* 20710 80045310 8FB00010 */  lw        $s0, 0x10($sp)
/* 20714 80045314 24020002 */  addiu     $v0, $zero, 2
/* 20718 80045318 03E00008 */  jr        $ra
/* 2071C 8004531C 27BD0020 */   addiu    $sp, $sp, 0x20

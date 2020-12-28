.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802197B8_465C48
/* 465C48 802197B8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 465C4C 802197BC AFB20018 */  sw        $s2, 0x18($sp)
/* 465C50 802197C0 0080902D */  daddu     $s2, $a0, $zero
/* 465C54 802197C4 AFB10014 */  sw        $s1, 0x14($sp)
/* 465C58 802197C8 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 465C5C 802197CC 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 465C60 802197D0 AFBF001C */  sw        $ra, 0x1c($sp)
/* 465C64 802197D4 AFB00010 */  sw        $s0, 0x10($sp)
/* 465C68 802197D8 8E50000C */  lw        $s0, 0xc($s2)
/* 465C6C 802197DC 82260012 */  lb        $a2, 0x12($s1)
/* 465C70 802197E0 8E050000 */  lw        $a1, ($s0)
/* 465C74 802197E4 0C0B2026 */  jal       set_variable
/* 465C78 802197E8 26100004 */   addiu    $s0, $s0, 4
/* 465C7C 802197EC 82220012 */  lb        $v0, 0x12($s1)
/* 465C80 802197F0 8E050000 */  lw        $a1, ($s0)
/* 465C84 802197F4 000210C0 */  sll       $v0, $v0, 3
/* 465C88 802197F8 00511021 */  addu      $v0, $v0, $s1
/* 465C8C 802197FC 80460015 */  lb        $a2, 0x15($v0)
/* 465C90 80219800 0C0B2026 */  jal       set_variable
/* 465C94 80219804 0240202D */   daddu    $a0, $s2, $zero
/* 465C98 80219808 8FBF001C */  lw        $ra, 0x1c($sp)
/* 465C9C 8021980C 8FB20018 */  lw        $s2, 0x18($sp)
/* 465CA0 80219810 8FB10014 */  lw        $s1, 0x14($sp)
/* 465CA4 80219814 8FB00010 */  lw        $s0, 0x10($sp)
/* 465CA8 80219818 24020002 */  addiu     $v0, $zero, 2
/* 465CAC 8021981C 03E00008 */  jr        $ra
/* 465CB0 80219820 27BD0020 */   addiu    $sp, $sp, 0x20

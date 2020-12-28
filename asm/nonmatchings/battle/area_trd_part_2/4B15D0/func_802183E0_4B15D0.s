.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802183E0_4B15D0
/* 4B15D0 802183E0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4B15D4 802183E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 4B15D8 802183E8 0080882D */  daddu     $s1, $a0, $zero
/* 4B15DC 802183EC AFBF0018 */  sw        $ra, 0x18($sp)
/* 4B15E0 802183F0 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B15E4 802183F4 8E30000C */  lw        $s0, 0xc($s1)
/* 4B15E8 802183F8 8E050000 */  lw        $a1, ($s0)
/* 4B15EC 802183FC 0C0B1EAF */  jal       get_variable
/* 4B15F0 80218400 26100004 */   addiu    $s0, $s0, 4
/* 4B15F4 80218404 0220202D */  daddu     $a0, $s1, $zero
/* 4B15F8 80218408 8E050000 */  lw        $a1, ($s0)
/* 4B15FC 8021840C 0C0B1EAF */  jal       get_variable
/* 4B1600 80218410 0040802D */   daddu    $s0, $v0, $zero
/* 4B1604 80218414 0200202D */  daddu     $a0, $s0, $zero
/* 4B1608 80218418 0C00A3C2 */  jal       start_rumble
/* 4B160C 8021841C 0040282D */   daddu    $a1, $v0, $zero
/* 4B1610 80218420 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4B1614 80218424 8FB10014 */  lw        $s1, 0x14($sp)
/* 4B1618 80218428 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B161C 8021842C 24020002 */  addiu     $v0, $zero, 2
/* 4B1620 80218430 03E00008 */  jr        $ra
/* 4B1624 80218434 27BD0020 */   addiu    $sp, $sp, 0x20

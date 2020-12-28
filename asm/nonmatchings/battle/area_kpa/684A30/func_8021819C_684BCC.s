.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021819C_684BCC
/* 684BCC 8021819C 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 684BD0 802181A0 AFB10014 */  sw        $s1, 0x14($sp)
/* 684BD4 802181A4 0080882D */  daddu     $s1, $a0, $zero
/* 684BD8 802181A8 AFBF0018 */  sw        $ra, 0x18($sp)
/* 684BDC 802181AC AFB00010 */  sw        $s0, 0x10($sp)
/* 684BE0 802181B0 8E30000C */  lw        $s0, 0xc($s1)
/* 684BE4 802181B4 8E050000 */  lw        $a1, ($s0)
/* 684BE8 802181B8 0C0B1EAF */  jal       get_variable
/* 684BEC 802181BC 26100004 */   addiu    $s0, $s0, 4
/* 684BF0 802181C0 0220202D */  daddu     $a0, $s1, $zero
/* 684BF4 802181C4 8E050000 */  lw        $a1, ($s0)
/* 684BF8 802181C8 0C0B1EAF */  jal       get_variable
/* 684BFC 802181CC 0040802D */   daddu    $s0, $v0, $zero
/* 684C00 802181D0 0200202D */  daddu     $a0, $s0, $zero
/* 684C04 802181D4 0C00A3C2 */  jal       start_rumble
/* 684C08 802181D8 0040282D */   daddu    $a1, $v0, $zero
/* 684C0C 802181DC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 684C10 802181E0 8FB10014 */  lw        $s1, 0x14($sp)
/* 684C14 802181E4 8FB00010 */  lw        $s0, 0x10($sp)
/* 684C18 802181E8 24020002 */  addiu     $v0, $zero, 2
/* 684C1C 802181EC 03E00008 */  jr        $ra
/* 684C20 802181F0 27BD0020 */   addiu    $sp, $sp, 0x20
/* 684C24 802181F4 00000000 */  nop       
/* 684C28 802181F8 00000000 */  nop       
/* 684C2C 802181FC 00000000 */  nop       

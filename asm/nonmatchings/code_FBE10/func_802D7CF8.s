.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802D7CF8
/* FC6A8 802D7CF8 27BDFFD0 */  addiu     $sp, $sp, -0x30
/* FC6AC 802D7CFC AFB10014 */  sw        $s1, 0x14($sp)
/* FC6B0 802D7D00 0080882D */  daddu     $s1, $a0, $zero
/* FC6B4 802D7D04 AFBF002C */  sw        $ra, 0x2c($sp)
/* FC6B8 802D7D08 AFB60028 */  sw        $s6, 0x28($sp)
/* FC6BC 802D7D0C AFB50024 */  sw        $s5, 0x24($sp)
/* FC6C0 802D7D10 AFB40020 */  sw        $s4, 0x20($sp)
/* FC6C4 802D7D14 AFB3001C */  sw        $s3, 0x1c($sp)
/* FC6C8 802D7D18 AFB20018 */  sw        $s2, 0x18($sp)
/* FC6CC 802D7D1C AFB00010 */  sw        $s0, 0x10($sp)
/* FC6D0 802D7D20 8E30000C */  lw        $s0, 0xc($s1)
/* FC6D4 802D7D24 8E050000 */  lw        $a1, ($s0)
/* FC6D8 802D7D28 0C0B1EAF */  jal       get_variable
/* FC6DC 802D7D2C 26100004 */   addiu    $s0, $s0, 4
/* FC6E0 802D7D30 8E050000 */  lw        $a1, ($s0)
/* FC6E4 802D7D34 26100004 */  addiu     $s0, $s0, 4
/* FC6E8 802D7D38 0220202D */  daddu     $a0, $s1, $zero
/* FC6EC 802D7D3C 0C0B1EAF */  jal       get_variable
/* FC6F0 802D7D40 0040B02D */   daddu    $s6, $v0, $zero
/* FC6F4 802D7D44 8E050000 */  lw        $a1, ($s0)
/* FC6F8 802D7D48 26100004 */  addiu     $s0, $s0, 4
/* FC6FC 802D7D4C 0220202D */  daddu     $a0, $s1, $zero
/* FC700 802D7D50 0C0B1EAF */  jal       get_variable
/* FC704 802D7D54 0040A82D */   daddu    $s5, $v0, $zero
/* FC708 802D7D58 8E050000 */  lw        $a1, ($s0)
/* FC70C 802D7D5C 26100004 */  addiu     $s0, $s0, 4
/* FC710 802D7D60 0220202D */  daddu     $a0, $s1, $zero
/* FC714 802D7D64 0C0B1EAF */  jal       get_variable
/* FC718 802D7D68 0040A02D */   daddu    $s4, $v0, $zero
/* FC71C 802D7D6C 8E050000 */  lw        $a1, ($s0)
/* FC720 802D7D70 26100004 */  addiu     $s0, $s0, 4
/* FC724 802D7D74 0220202D */  daddu     $a0, $s1, $zero
/* FC728 802D7D78 0C0B1EAF */  jal       get_variable
/* FC72C 802D7D7C 0040982D */   daddu    $s3, $v0, $zero
/* FC730 802D7D80 8E050000 */  lw        $a1, ($s0)
/* FC734 802D7D84 26100004 */  addiu     $s0, $s0, 4
/* FC738 802D7D88 0220202D */  daddu     $a0, $s1, $zero
/* FC73C 802D7D8C 0C0B1EAF */  jal       get_variable
/* FC740 802D7D90 0040902D */   daddu    $s2, $v0, $zero
/* FC744 802D7D94 0220202D */  daddu     $a0, $s1, $zero
/* FC748 802D7D98 8E050000 */  lw        $a1, ($s0)
/* FC74C 802D7D9C 0C0B1EAF */  jal       get_variable
/* FC750 802D7DA0 0040882D */   daddu    $s1, $v0, $zero
/* FC754 802D7DA4 3C04802E */  lui       $a0, 0x802e
/* FC758 802D7DA8 24849D50 */  addiu     $a0, $a0, -0x62b0
/* FC75C 802D7DAC 24050001 */  addiu     $a1, $zero, 1
/* FC760 802D7DB0 0040802D */  daddu     $s0, $v0, $zero
/* FC764 802D7DB4 0C0B0CF8 */  jal       start_script
/* FC768 802D7DB8 0000302D */   daddu    $a2, $zero, $zero
/* FC76C 802D7DBC 0040182D */  daddu     $v1, $v0, $zero
/* FC770 802D7DC0 AC760084 */  sw        $s6, 0x84($v1)
/* FC774 802D7DC4 AC750088 */  sw        $s5, 0x88($v1)
/* FC778 802D7DC8 AC74008C */  sw        $s4, 0x8c($v1)
/* FC77C 802D7DCC AC730090 */  sw        $s3, 0x90($v1)
/* FC780 802D7DD0 AC720094 */  sw        $s2, 0x94($v1)
/* FC784 802D7DD4 AC710098 */  sw        $s1, 0x98($v1)
/* FC788 802D7DD8 AC70009C */  sw        $s0, 0x9c($v1)
/* FC78C 802D7DDC 8FBF002C */  lw        $ra, 0x2c($sp)
/* FC790 802D7DE0 8FB60028 */  lw        $s6, 0x28($sp)
/* FC794 802D7DE4 8FB50024 */  lw        $s5, 0x24($sp)
/* FC798 802D7DE8 8FB40020 */  lw        $s4, 0x20($sp)
/* FC79C 802D7DEC 8FB3001C */  lw        $s3, 0x1c($sp)
/* FC7A0 802D7DF0 8FB20018 */  lw        $s2, 0x18($sp)
/* FC7A4 802D7DF4 8FB10014 */  lw        $s1, 0x14($sp)
/* FC7A8 802D7DF8 8FB00010 */  lw        $s0, 0x10($sp)
/* FC7AC 802D7DFC 24020002 */  addiu     $v0, $zero, 2
/* FC7B0 802D7E00 03E00008 */  jr        $ra
/* FC7B4 802D7E04 27BD0030 */   addiu    $sp, $sp, 0x30

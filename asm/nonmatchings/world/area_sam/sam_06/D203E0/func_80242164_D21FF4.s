.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242164_D21FF4
/* D21FF4 80242164 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* D21FF8 80242168 AFB10014 */  sw        $s1, 0x14($sp)
/* D21FFC 8024216C 0080882D */  daddu     $s1, $a0, $zero
/* D22000 80242170 AFBF001C */  sw        $ra, 0x1c($sp)
/* D22004 80242174 AFB20018 */  sw        $s2, 0x18($sp)
/* D22008 80242178 AFB00010 */  sw        $s0, 0x10($sp)
/* D2200C 8024217C 8E30000C */  lw        $s0, 0xc($s1)
/* D22010 80242180 8E050000 */  lw        $a1, ($s0)
/* D22014 80242184 0C0B1EAF */  jal       get_variable
/* D22018 80242188 26100004 */   addiu    $s0, $s0, 4
/* D2201C 8024218C 8E050000 */  lw        $a1, ($s0)
/* D22020 80242190 26100004 */  addiu     $s0, $s0, 4
/* D22024 80242194 0220202D */  daddu     $a0, $s1, $zero
/* D22028 80242198 0C0B1EAF */  jal       get_variable
/* D2202C 8024219C 0040902D */   daddu    $s2, $v0, $zero
/* D22030 802421A0 0220202D */  daddu     $a0, $s1, $zero
/* D22034 802421A4 8E050000 */  lw        $a1, ($s0)
/* D22038 802421A8 0C0B1EAF */  jal       get_variable
/* D2203C 802421AC 0040802D */   daddu    $s0, $v0, $zero
/* D22040 802421B0 0000202D */  daddu     $a0, $zero, $zero
/* D22044 802421B4 324500FF */  andi      $a1, $s2, 0xff
/* D22048 802421B8 320600FF */  andi      $a2, $s0, 0xff
/* D2204C 802421BC 0C04DF84 */  jal       func_80137E10
/* D22050 802421C0 304700FF */   andi     $a3, $v0, 0xff
/* D22054 802421C4 8FBF001C */  lw        $ra, 0x1c($sp)
/* D22058 802421C8 8FB20018 */  lw        $s2, 0x18($sp)
/* D2205C 802421CC 8FB10014 */  lw        $s1, 0x14($sp)
/* D22060 802421D0 8FB00010 */  lw        $s0, 0x10($sp)
/* D22064 802421D4 24020002 */  addiu     $v0, $zero, 2
/* D22068 802421D8 03E00008 */  jr        $ra
/* D2206C 802421DC 27BD0020 */   addiu    $sp, $sp, 0x20

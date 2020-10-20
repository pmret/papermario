.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242150
/* 9C7530 80242150 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9C7534 80242154 AFB10014 */  sw        $s1, 0x14($sp)
/* 9C7538 80242158 0080882D */  daddu     $s1, $a0, $zero
/* 9C753C 8024215C AFBF0018 */  sw        $ra, 0x18($sp)
/* 9C7540 80242160 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7544 80242164 8E30000C */  lw        $s0, 0xc($s1)
/* 9C7548 80242168 8E050000 */  lw        $a1, ($s0)
/* 9C754C 8024216C 0C0B1EAF */  jal       get_variable
/* 9C7550 80242170 26100004 */   addiu    $s0, $s0, 4
/* 9C7554 80242174 AE22008C */  sw        $v0, 0x8c($s1)
/* 9C7558 80242178 8E050000 */  lw        $a1, ($s0)
/* 9C755C 8024217C 26100004 */  addiu     $s0, $s0, 4
/* 9C7560 80242180 0C0B1EAF */  jal       get_variable
/* 9C7564 80242184 0220202D */   daddu    $a0, $s1, $zero
/* 9C7568 80242188 AE220090 */  sw        $v0, 0x90($s1)
/* 9C756C 8024218C 8E050000 */  lw        $a1, ($s0)
/* 9C7570 80242190 26100004 */  addiu     $s0, $s0, 4
/* 9C7574 80242194 0C0B1EAF */  jal       get_variable
/* 9C7578 80242198 0220202D */   daddu    $a0, $s1, $zero
/* 9C757C 8024219C AE220094 */  sw        $v0, 0x94($s1)
/* 9C7580 802421A0 8E050000 */  lw        $a1, ($s0)
/* 9C7584 802421A4 26100004 */  addiu     $s0, $s0, 4
/* 9C7588 802421A8 0C0B1EAF */  jal       get_variable
/* 9C758C 802421AC 0220202D */   daddu    $a0, $s1, $zero
/* 9C7590 802421B0 AE220098 */  sw        $v0, 0x98($s1)
/* 9C7594 802421B4 8E050000 */  lw        $a1, ($s0)
/* 9C7598 802421B8 26100004 */  addiu     $s0, $s0, 4
/* 9C759C 802421BC 0C0B1EAF */  jal       get_variable
/* 9C75A0 802421C0 0220202D */   daddu    $a0, $s1, $zero
/* 9C75A4 802421C4 AE22009C */  sw        $v0, 0x9c($s1)
/* 9C75A8 802421C8 8E050000 */  lw        $a1, ($s0)
/* 9C75AC 802421CC 26100004 */  addiu     $s0, $s0, 4
/* 9C75B0 802421D0 0C0B1EAF */  jal       get_variable
/* 9C75B4 802421D4 0220202D */   daddu    $a0, $s1, $zero
/* 9C75B8 802421D8 AE2200A0 */  sw        $v0, 0xa0($s1)
/* 9C75BC 802421DC 8E050000 */  lw        $a1, ($s0)
/* 9C75C0 802421E0 26100004 */  addiu     $s0, $s0, 4
/* 9C75C4 802421E4 0C0B1EAF */  jal       get_variable
/* 9C75C8 802421E8 0220202D */   daddu    $a0, $s1, $zero
/* 9C75CC 802421EC AE2200A4 */  sw        $v0, 0xa4($s1)
/* 9C75D0 802421F0 8E050000 */  lw        $a1, ($s0)
/* 9C75D4 802421F4 26100004 */  addiu     $s0, $s0, 4
/* 9C75D8 802421F8 0C0B1EAF */  jal       get_variable
/* 9C75DC 802421FC 0220202D */   daddu    $a0, $s1, $zero
/* 9C75E0 80242200 AE2200A8 */  sw        $v0, 0xa8($s1)
/* 9C75E4 80242204 8E050000 */  lw        $a1, ($s0)
/* 9C75E8 80242208 26100004 */  addiu     $s0, $s0, 4
/* 9C75EC 8024220C 0C0B1EAF */  jal       get_variable
/* 9C75F0 80242210 0220202D */   daddu    $a0, $s1, $zero
/* 9C75F4 80242214 AE2200AC */  sw        $v0, 0xac($s1)
/* 9C75F8 80242218 8E050000 */  lw        $a1, ($s0)
/* 9C75FC 8024221C 0C0B1EAF */  jal       get_variable
/* 9C7600 80242220 0220202D */   daddu    $a0, $s1, $zero
/* 9C7604 80242224 AE2200B0 */  sw        $v0, 0xb0($s1)
/* 9C7608 80242228 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9C760C 8024222C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C7610 80242230 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C7614 80242234 24020002 */  addiu     $v0, $zero, 2
/* 9C7618 80242238 03E00008 */  jr        $ra
/* 9C761C 8024223C 27BD0020 */   addiu    $sp, $sp, 0x20

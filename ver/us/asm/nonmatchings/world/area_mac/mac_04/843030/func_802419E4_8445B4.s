.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802419E4_8445B4
/* 8445B4 802419E4 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 8445B8 802419E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 8445BC 802419EC 0080802D */  daddu     $s0, $a0, $zero
/* 8445C0 802419F0 AFB10014 */  sw        $s1, 0x14($sp)
/* 8445C4 802419F4 3C118011 */  lui       $s1, %hi(gPlayerData)
/* 8445C8 802419F8 2631F290 */  addiu     $s1, $s1, %lo(gPlayerData)
/* 8445CC 802419FC AFBF0020 */  sw        $ra, 0x20($sp)
/* 8445D0 80241A00 AFB3001C */  sw        $s3, 0x1c($sp)
/* 8445D4 80241A04 AFB20018 */  sw        $s2, 0x18($sp)
/* 8445D8 80241A08 8E02000C */  lw        $v0, 0xc($s0)
/* 8445DC 80241A0C 82260004 */  lb        $a2, 4($s1)
/* 8445E0 80241A10 8C450000 */  lw        $a1, ($v0)
/* 8445E4 80241A14 24420004 */  addiu     $v0, $v0, 4
/* 8445E8 80241A18 8C520000 */  lw        $s2, ($v0)
/* 8445EC 80241A1C 0C0B2026 */  jal       evt_set_variable
/* 8445F0 80241A20 8C530004 */   lw       $s3, 4($v0)
/* 8445F4 80241A24 0200202D */  daddu     $a0, $s0, $zero
/* 8445F8 80241A28 82260007 */  lb        $a2, 7($s1)
/* 8445FC 80241A2C 0C0B2026 */  jal       evt_set_variable
/* 844600 80241A30 0240282D */   daddu    $a1, $s2, $zero
/* 844604 80241A34 0200202D */  daddu     $a0, $s0, $zero
/* 844608 80241A38 82260008 */  lb        $a2, 8($s1)
/* 84460C 80241A3C 0C0B2026 */  jal       evt_set_variable
/* 844610 80241A40 0260282D */   daddu    $a1, $s3, $zero
/* 844614 80241A44 8FBF0020 */  lw        $ra, 0x20($sp)
/* 844618 80241A48 8FB3001C */  lw        $s3, 0x1c($sp)
/* 84461C 80241A4C 8FB20018 */  lw        $s2, 0x18($sp)
/* 844620 80241A50 8FB10014 */  lw        $s1, 0x14($sp)
/* 844624 80241A54 8FB00010 */  lw        $s0, 0x10($sp)
/* 844628 80241A58 24020002 */  addiu     $v0, $zero, 2
/* 84462C 80241A5C 03E00008 */  jr        $ra
/* 844630 80241A60 27BD0028 */   addiu    $sp, $sp, 0x28

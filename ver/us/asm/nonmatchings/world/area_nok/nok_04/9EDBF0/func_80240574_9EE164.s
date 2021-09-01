.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240574_9EE164
/* 9EE164 80240574 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9EE168 80240578 AFB20018 */  sw        $s2, 0x18($sp)
/* 9EE16C 8024057C 0080902D */  daddu     $s2, $a0, $zero
/* 9EE170 80240580 AFBF0020 */  sw        $ra, 0x20($sp)
/* 9EE174 80240584 AFB3001C */  sw        $s3, 0x1c($sp)
/* 9EE178 80240588 AFB10014 */  sw        $s1, 0x14($sp)
/* 9EE17C 8024058C AFB00010 */  sw        $s0, 0x10($sp)
/* 9EE180 80240590 8E50000C */  lw        $s0, 0xc($s2)
/* 9EE184 80240594 8E050000 */  lw        $a1, ($s0)
/* 9EE188 80240598 0C0B1EAF */  jal       evt_get_variable
/* 9EE18C 8024059C 26100004 */   addiu    $s0, $s0, 4
/* 9EE190 802405A0 8E050000 */  lw        $a1, ($s0)
/* 9EE194 802405A4 26100004 */  addiu     $s0, $s0, 4
/* 9EE198 802405A8 00028840 */  sll       $s1, $v0, 1
/* 9EE19C 802405AC 02228821 */  addu      $s1, $s1, $v0
/* 9EE1A0 802405B0 00111080 */  sll       $v0, $s1, 2
/* 9EE1A4 802405B4 3C068024 */  lui       $a2, %hi(D_80241440_9EF030)
/* 9EE1A8 802405B8 00C23021 */  addu      $a2, $a2, $v0
/* 9EE1AC 802405BC 8CC61440 */  lw        $a2, %lo(D_80241440_9EF030)($a2)
/* 9EE1B0 802405C0 8E130000 */  lw        $s3, ($s0)
/* 9EE1B4 802405C4 8E100004 */  lw        $s0, 4($s0)
/* 9EE1B8 802405C8 0C0B2026 */  jal       evt_set_variable
/* 9EE1BC 802405CC 0240202D */   daddu    $a0, $s2, $zero
/* 9EE1C0 802405D0 0240202D */  daddu     $a0, $s2, $zero
/* 9EE1C4 802405D4 26220001 */  addiu     $v0, $s1, 1
/* 9EE1C8 802405D8 00021080 */  sll       $v0, $v0, 2
/* 9EE1CC 802405DC 3C068024 */  lui       $a2, %hi(D_80241440_9EF030)
/* 9EE1D0 802405E0 00C23021 */  addu      $a2, $a2, $v0
/* 9EE1D4 802405E4 8CC61440 */  lw        $a2, %lo(D_80241440_9EF030)($a2)
/* 9EE1D8 802405E8 0C0B2026 */  jal       evt_set_variable
/* 9EE1DC 802405EC 0260282D */   daddu    $a1, $s3, $zero
/* 9EE1E0 802405F0 0240202D */  daddu     $a0, $s2, $zero
/* 9EE1E4 802405F4 26310002 */  addiu     $s1, $s1, 2
/* 9EE1E8 802405F8 00118880 */  sll       $s1, $s1, 2
/* 9EE1EC 802405FC 3C068024 */  lui       $a2, %hi(D_80241440_9EF030)
/* 9EE1F0 80240600 00D13021 */  addu      $a2, $a2, $s1
/* 9EE1F4 80240604 8CC61440 */  lw        $a2, %lo(D_80241440_9EF030)($a2)
/* 9EE1F8 80240608 0C0B2026 */  jal       evt_set_variable
/* 9EE1FC 8024060C 0200282D */   daddu    $a1, $s0, $zero
/* 9EE200 80240610 8FBF0020 */  lw        $ra, 0x20($sp)
/* 9EE204 80240614 8FB3001C */  lw        $s3, 0x1c($sp)
/* 9EE208 80240618 8FB20018 */  lw        $s2, 0x18($sp)
/* 9EE20C 8024061C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9EE210 80240620 8FB00010 */  lw        $s0, 0x10($sp)
/* 9EE214 80240624 24020002 */  addiu     $v0, $zero, 2
/* 9EE218 80240628 03E00008 */  jr        $ra
/* 9EE21C 8024062C 27BD0028 */   addiu    $sp, $sp, 0x28

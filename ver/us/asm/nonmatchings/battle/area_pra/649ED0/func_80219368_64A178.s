.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80219368_64A178
/* 64A178 80219368 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 64A17C 8021936C AFB10014 */  sw        $s1, 0x14($sp)
/* 64A180 80219370 0080882D */  daddu     $s1, $a0, $zero
/* 64A184 80219374 AFBF0018 */  sw        $ra, 0x18($sp)
/* 64A188 80219378 AFB00010 */  sw        $s0, 0x10($sp)
/* 64A18C 8021937C 8E30000C */  lw        $s0, 0xc($s1)
/* 64A190 80219380 8E050000 */  lw        $a1, ($s0)
/* 64A194 80219384 0C0B1EAF */  jal       evt_get_variable
/* 64A198 80219388 26100004 */   addiu    $s0, $s0, 4
/* 64A19C 8021938C 0040202D */  daddu     $a0, $v0, $zero
/* 64A1A0 80219390 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 64A1A4 80219394 14820002 */  bne       $a0, $v0, .L802193A0
/* 64A1A8 80219398 00000000 */   nop
/* 64A1AC 8021939C 8E240148 */  lw        $a0, 0x148($s1)
.L802193A0:
/* 64A1B0 802193A0 0C09A75B */  jal       get_actor
/* 64A1B4 802193A4 00000000 */   nop
/* 64A1B8 802193A8 0040202D */  daddu     $a0, $v0, $zero
/* 64A1BC 802193AC 90830136 */  lbu       $v1, 0x136($a0)
/* 64A1C0 802193B0 24020047 */  addiu     $v0, $zero, 0x47
/* 64A1C4 802193B4 1062000B */  beq       $v1, $v0, .L802193E4
/* 64A1C8 802193B8 0062102A */   slt      $v0, $v1, $v0
/* 64A1CC 802193BC 54400011 */  bnel      $v0, $zero, .L80219404
/* 64A1D0 802193C0 0220202D */   daddu    $a0, $s1, $zero
/* 64A1D4 802193C4 28620065 */  slti      $v0, $v1, 0x65
/* 64A1D8 802193C8 1040000D */  beqz      $v0, .L80219400
/* 64A1DC 802193CC 2862004D */   slti     $v0, $v1, 0x4d
/* 64A1E0 802193D0 1440000C */  bnez      $v0, .L80219404
/* 64A1E4 802193D4 0220202D */   daddu    $a0, $s1, $zero
/* 64A1E8 802193D8 8E050000 */  lw        $a1, ($s0)
/* 64A1EC 802193DC 08086503 */  j         .L8021940C
/* 64A1F0 802193E0 2406FFFF */   addiu    $a2, $zero, -1
.L802193E4:
/* 64A1F4 802193E4 8C8300A8 */  lw        $v1, 0xa8($a0)
/* 64A1F8 802193E8 24020001 */  addiu     $v0, $zero, 1
/* 64A1FC 802193EC 14620005 */  bne       $v1, $v0, .L80219404
/* 64A200 802193F0 0220202D */   daddu    $a0, $s1, $zero
/* 64A204 802193F4 8E050000 */  lw        $a1, ($s0)
/* 64A208 802193F8 08086503 */  j         .L8021940C
/* 64A20C 802193FC 2406FFFF */   addiu    $a2, $zero, -1
.L80219400:
/* 64A210 80219400 0220202D */  daddu     $a0, $s1, $zero
.L80219404:
/* 64A214 80219404 8E050000 */  lw        $a1, ($s0)
/* 64A218 80219408 0000302D */  daddu     $a2, $zero, $zero
.L8021940C:
/* 64A21C 8021940C 0C0B2026 */  jal       evt_set_variable
/* 64A220 80219410 00000000 */   nop
/* 64A224 80219414 8FBF0018 */  lw        $ra, 0x18($sp)
/* 64A228 80219418 8FB10014 */  lw        $s1, 0x14($sp)
/* 64A22C 8021941C 8FB00010 */  lw        $s0, 0x10($sp)
/* 64A230 80219420 24020002 */  addiu     $v0, $zero, 2
/* 64A234 80219424 03E00008 */  jr        $ra
/* 64A238 80219428 27BD0020 */   addiu    $sp, $sp, 0x20

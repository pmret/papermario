.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218430_6DE1F0
/* 6DE1F0 80218430 27BDFF78 */  addiu     $sp, $sp, -0x88
/* 6DE1F4 80218434 AFB10054 */  sw        $s1, 0x54($sp)
/* 6DE1F8 80218438 0080882D */  daddu     $s1, $a0, $zero
/* 6DE1FC 8021843C AFBF0060 */  sw        $ra, 0x60($sp)
/* 6DE200 80218440 AFB3005C */  sw        $s3, 0x5c($sp)
/* 6DE204 80218444 AFB20058 */  sw        $s2, 0x58($sp)
/* 6DE208 80218448 AFB00050 */  sw        $s0, 0x50($sp)
/* 6DE20C 8021844C F7BA0080 */  sdc1      $f26, 0x80($sp)
/* 6DE210 80218450 F7B80078 */  sdc1      $f24, 0x78($sp)
/* 6DE214 80218454 F7B60070 */  sdc1      $f22, 0x70($sp)
/* 6DE218 80218458 F7B40068 */  sdc1      $f20, 0x68($sp)
/* 6DE21C 8021845C 8E30000C */  lw        $s0, 0xc($s1)
/* 6DE220 80218460 8E050000 */  lw        $a1, ($s0)
/* 6DE224 80218464 0C0B1EAF */  jal       evt_get_variable
/* 6DE228 80218468 26100004 */   addiu    $s0, $s0, 4
/* 6DE22C 8021846C 4482A000 */  mtc1      $v0, $f20
/* 6DE230 80218470 00000000 */  nop
/* 6DE234 80218474 4680A521 */  cvt.d.w   $f20, $f20
/* 6DE238 80218478 3C014024 */  lui       $at, 0x4024
/* 6DE23C 8021847C 44810800 */  mtc1      $at, $f1
/* 6DE240 80218480 44800000 */  mtc1      $zero, $f0
/* 6DE244 80218484 8E120000 */  lw        $s2, ($s0)
/* 6DE248 80218488 26100004 */  addiu     $s0, $s0, 4
/* 6DE24C 8021848C 4620A503 */  div.d     $f20, $f20, $f0
/* 6DE250 80218490 3C0140C9 */  lui       $at, 0x40c9
/* 6DE254 80218494 34210FD0 */  ori       $at, $at, 0xfd0
/* 6DE258 80218498 44810000 */  mtc1      $at, $f0
/* 6DE25C 8021849C 4620A520 */  cvt.s.d   $f20, $f20
/* 6DE260 802184A0 4600A502 */  mul.s     $f20, $f20, $f0
/* 6DE264 802184A4 00000000 */  nop
/* 6DE268 802184A8 8E130000 */  lw        $s3, ($s0)
/* 6DE26C 802184AC 8E100004 */  lw        $s0, 4($s0)
/* 6DE270 802184B0 3C0143B4 */  lui       $at, 0x43b4
/* 6DE274 802184B4 44810000 */  mtc1      $at, $f0
/* 6DE278 802184B8 3C014316 */  lui       $at, 0x4316
/* 6DE27C 802184BC 4481C000 */  mtc1      $at, $f24
/* 6DE280 802184C0 4600A503 */  div.s     $f20, $f20, $f0
/* 6DE284 802184C4 0C00A85B */  jal       sin_rad
/* 6DE288 802184C8 4600A306 */   mov.s    $f12, $f20
/* 6DE28C 802184CC 46180582 */  mul.s     $f22, $f0, $f24
/* 6DE290 802184D0 00000000 */  nop
/* 6DE294 802184D4 4480D000 */  mtc1      $zero, $f26
/* 6DE298 802184D8 00000000 */  nop
/* 6DE29C 802184DC 461AB580 */  add.s     $f22, $f22, $f26
/* 6DE2A0 802184E0 0C00A874 */  jal       cos_rad
/* 6DE2A4 802184E4 4600A306 */   mov.s    $f12, $f20
/* 6DE2A8 802184E8 46180502 */  mul.s     $f20, $f0, $f24
/* 6DE2AC 802184EC 00000000 */  nop
/* 6DE2B0 802184F0 3C01C37C */  lui       $at, 0xc37c
/* 6DE2B4 802184F4 4481C000 */  mtc1      $at, $f24
/* 6DE2B8 802184F8 C62000B8 */  lwc1      $f0, 0xb8($s1)
/* 6DE2BC 802184FC 46800020 */  cvt.s.w   $f0, $f0
/* 6DE2C0 80218500 4600C601 */  sub.s     $f24, $f24, $f0
/* 6DE2C4 80218504 C62000B0 */  lwc1      $f0, 0xb0($s1)
/* 6DE2C8 80218508 46800020 */  cvt.s.w   $f0, $f0
/* 6DE2CC 8021850C 4600B581 */  sub.s     $f22, $f22, $f0
/* 6DE2D0 80218510 0220202D */  daddu     $a0, $s1, $zero
/* 6DE2D4 80218514 0240282D */  daddu     $a1, $s2, $zero
/* 6DE2D8 80218518 461AA500 */  add.s     $f20, $f20, $f26
/* 6DE2DC 8021851C C62000B4 */  lwc1      $f0, 0xb4($s1)
/* 6DE2E0 80218520 46800020 */  cvt.s.w   $f0, $f0
/* 6DE2E4 80218524 4406B000 */  mfc1      $a2, $f22
/* 6DE2E8 80218528 0C0B2190 */  jal       evt_set_float_variable
/* 6DE2EC 8021852C 4600A501 */   sub.s    $f20, $f20, $f0
/* 6DE2F0 80218530 0220202D */  daddu     $a0, $s1, $zero
/* 6DE2F4 80218534 4406A000 */  mfc1      $a2, $f20
/* 6DE2F8 80218538 0C0B2190 */  jal       evt_set_float_variable
/* 6DE2FC 8021853C 0260282D */   daddu    $a1, $s3, $zero
/* 6DE300 80218540 0220202D */  daddu     $a0, $s1, $zero
/* 6DE304 80218544 4406C000 */  mfc1      $a2, $f24
/* 6DE308 80218548 0C0B2190 */  jal       evt_set_float_variable
/* 6DE30C 8021854C 0200282D */   daddu    $a1, $s0, $zero
/* 6DE310 80218550 8FBF0060 */  lw        $ra, 0x60($sp)
/* 6DE314 80218554 8FB3005C */  lw        $s3, 0x5c($sp)
/* 6DE318 80218558 8FB20058 */  lw        $s2, 0x58($sp)
/* 6DE31C 8021855C 8FB10054 */  lw        $s1, 0x54($sp)
/* 6DE320 80218560 8FB00050 */  lw        $s0, 0x50($sp)
/* 6DE324 80218564 D7BA0080 */  ldc1      $f26, 0x80($sp)
/* 6DE328 80218568 D7B80078 */  ldc1      $f24, 0x78($sp)
/* 6DE32C 8021856C D7B60070 */  ldc1      $f22, 0x70($sp)
/* 6DE330 80218570 D7B40068 */  ldc1      $f20, 0x68($sp)
/* 6DE334 80218574 24020002 */  addiu     $v0, $zero, 2
/* 6DE338 80218578 03E00008 */  jr        $ra
/* 6DE33C 8021857C 27BD0088 */   addiu    $sp, $sp, 0x88

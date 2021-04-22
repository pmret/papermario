.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003D07C
/* 1847C 8003D07C 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 18480 8003D080 AFB10024 */  sw        $s1, 0x24($sp)
/* 18484 8003D084 0080882D */  daddu     $s1, $a0, $zero
/* 18488 8003D088 0000282D */  daddu     $a1, $zero, $zero
/* 1848C 8003D08C AFBF003C */  sw        $ra, 0x3c($sp)
/* 18490 8003D090 AFB60038 */  sw        $s6, 0x38($sp)
/* 18494 8003D094 AFB50034 */  sw        $s5, 0x34($sp)
/* 18498 8003D098 AFB40030 */  sw        $s4, 0x30($sp)
/* 1849C 8003D09C AFB3002C */  sw        $s3, 0x2c($sp)
/* 184A0 8003D0A0 AFB20028 */  sw        $s2, 0x28($sp)
/* 184A4 8003D0A4 AFB00020 */  sw        $s0, 0x20($sp)
/* 184A8 8003D0A8 86340098 */  lh        $s4, 0x98($s1)
/* 184AC 8003D0AC 8630009A */  lh        $s0, 0x9a($s1)
/* 184B0 8003D0B0 8635009C */  lh        $s5, 0x9c($s1)
/* 184B4 8003D0B4 8632009E */  lh        $s2, 0x9e($s1)
/* 184B8 8003D0B8 863600A0 */  lh        $s6, 0xa0($s1)
/* 184BC 8003D0BC 963300A2 */  lhu       $s3, 0xa2($s1)
/* 184C0 8003D0C0 00A0302D */  daddu     $a2, $a1, $zero
/* 184C4 8003D0C4 AFA00010 */  sw        $zero, 0x10($sp)
/* 184C8 8003D0C8 AFA00014 */  sw        $zero, 0x14($sp)
/* 184CC 8003D0CC AFA00018 */  sw        $zero, 0x18($sp)
/* 184D0 8003D0D0 8E240024 */  lw        $a0, 0x24($s1)
/* 184D4 8003D0D4 0C0448F9 */  jal       func_801123E4
/* 184D8 8003D0D8 00A0382D */   daddu    $a3, $a1, $zero
/* 184DC 8003D0DC 2E820011 */  sltiu     $v0, $s4, 0x11
/* 184E0 8003D0E0 10400076 */  beqz      $v0, .L8003D2BC
/* 184E4 8003D0E4 00141080 */   sll      $v0, $s4, 2
/* 184E8 8003D0E8 3C01800A */  lui       $at, %hi(D_80098528)
/* 184EC 8003D0EC 00220821 */  addu      $at, $at, $v0
/* 184F0 8003D0F0 8C228528 */  lw        $v0, %lo(D_80098528)($at)
/* 184F4 8003D0F4 00400008 */  jr        $v0
/* 184F8 8003D0F8 00000000 */   nop
/* 184FC 8003D0FC 0000282D */  daddu     $a1, $zero, $zero
/* 18500 8003D100 00A0302D */  daddu     $a2, $a1, $zero
/* 18504 8003D104 2402000D */  addiu     $v0, $zero, 0xd
/* 18508 8003D108 A22200AA */  sb        $v0, 0xaa($s1)
/* 1850C 8003D10C AFA00010 */  sw        $zero, 0x10($sp)
/* 18510 8003D110 AFA00014 */  sw        $zero, 0x14($sp)
/* 18514 8003D114 AFB30018 */  sw        $s3, 0x18($sp)
/* 18518 8003D118 8E240024 */  lw        $a0, 0x24($s1)
/* 1851C 8003D11C 0800F4AD */  j         .L8003D2B4
/* 18520 8003D120 00A0382D */   daddu    $a3, $a1, $zero
/* 18524 8003D124 2402000D */  addiu     $v0, $zero, 0xd
/* 18528 8003D128 A22200AA */  sb        $v0, 0xaa($s1)
/* 1852C 8003D12C 0280282D */  daddu     $a1, $s4, $zero
/* 18530 8003D130 0000302D */  daddu     $a2, $zero, $zero
/* 18534 8003D134 AFA00010 */  sw        $zero, 0x10($sp)
/* 18538 8003D138 AFA00014 */  sw        $zero, 0x14($sp)
/* 1853C 8003D13C AFB30018 */  sw        $s3, 0x18($sp)
/* 18540 8003D140 8E240024 */  lw        $a0, 0x24($s1)
/* 18544 8003D144 0800F4AD */  j         .L8003D2B4
/* 18548 8003D148 00C0382D */   daddu    $a3, $a2, $zero
/* 1854C 8003D14C 24050004 */  addiu     $a1, $zero, 4
/* 18550 8003D150 0200302D */  daddu     $a2, $s0, $zero
/* 18554 8003D154 2402000D */  addiu     $v0, $zero, 0xd
/* 18558 8003D158 A22200AA */  sb        $v0, 0xaa($s1)
/* 1855C 8003D15C AFB20010 */  sw        $s2, 0x10($sp)
/* 18560 8003D160 0800F4AA */  j         .L8003D2A8
/* 18564 8003D164 AFA00014 */   sw       $zero, 0x14($sp)
/* 18568 8003D168 24050006 */  addiu     $a1, $zero, 6
/* 1856C 8003D16C 0200302D */  daddu     $a2, $s0, $zero
/* 18570 8003D170 2402000D */  addiu     $v0, $zero, 0xd
/* 18574 8003D174 A22200AA */  sb        $v0, 0xaa($s1)
/* 18578 8003D178 240200FF */  addiu     $v0, $zero, 0xff
/* 1857C 8003D17C AFB20010 */  sw        $s2, 0x10($sp)
/* 18580 8003D180 0800F4AA */  j         .L8003D2A8
/* 18584 8003D184 AFA20014 */   sw       $v0, 0x14($sp)
/* 18588 8003D188 24050007 */  addiu     $a1, $zero, 7
/* 1858C 8003D18C 240600FF */  addiu     $a2, $zero, 0xff
/* 18590 8003D190 24020016 */  addiu     $v0, $zero, 0x16
/* 18594 8003D194 A22200AA */  sb        $v0, 0xaa($s1)
/* 18598 8003D198 00C0102D */  daddu     $v0, $a2, $zero
/* 1859C 8003D19C AFA20010 */  sw        $v0, 0x10($sp)
/* 185A0 8003D1A0 AFB00014 */  sw        $s0, 0x14($sp)
/* 185A4 8003D1A4 AFB30018 */  sw        $s3, 0x18($sp)
/* 185A8 8003D1A8 8E240024 */  lw        $a0, 0x24($s1)
/* 185AC 8003D1AC 0800F4AD */  j         .L8003D2B4
/* 185B0 8003D1B0 00C0382D */   daddu    $a3, $a2, $zero
/* 185B4 8003D1B4 24050008 */  addiu     $a1, $zero, 8
/* 185B8 8003D1B8 0200302D */  daddu     $a2, $s0, $zero
/* 185BC 8003D1BC 24020016 */  addiu     $v0, $zero, 0x16
/* 185C0 8003D1C0 A22200AA */  sb        $v0, 0xaa($s1)
/* 185C4 8003D1C4 AFB20010 */  sw        $s2, 0x10($sp)
/* 185C8 8003D1C8 0800F4AA */  j         .L8003D2A8
/* 185CC 8003D1CC AFB60014 */   sw       $s6, 0x14($sp)
/* 185D0 8003D1D0 24050009 */  addiu     $a1, $zero, 9
/* 185D4 8003D1D4 0200302D */  daddu     $a2, $s0, $zero
/* 185D8 8003D1D8 2402000D */  addiu     $v0, $zero, 0xd
/* 185DC 8003D1DC A22200AA */  sb        $v0, 0xaa($s1)
/* 185E0 8003D1E0 240200FF */  addiu     $v0, $zero, 0xff
/* 185E4 8003D1E4 AFB20010 */  sw        $s2, 0x10($sp)
/* 185E8 8003D1E8 0800F4AA */  j         .L8003D2A8
/* 185EC 8003D1EC AFA20014 */   sw       $v0, 0x14($sp)
/* 185F0 8003D1F0 2405000A */  addiu     $a1, $zero, 0xa
/* 185F4 8003D1F4 0200302D */  daddu     $a2, $s0, $zero
/* 185F8 8003D1F8 24020016 */  addiu     $v0, $zero, 0x16
/* 185FC 8003D1FC A22200AA */  sb        $v0, 0xaa($s1)
/* 18600 8003D200 AFB20010 */  sw        $s2, 0x10($sp)
/* 18604 8003D204 0800F4AA */  j         .L8003D2A8
/* 18608 8003D208 AFB60014 */   sw       $s6, 0x14($sp)
/* 1860C 8003D20C 24050005 */  addiu     $a1, $zero, 5
/* 18610 8003D210 0200302D */  daddu     $a2, $s0, $zero
/* 18614 8003D214 2402000D */  addiu     $v0, $zero, 0xd
/* 18618 8003D218 A22200AA */  sb        $v0, 0xaa($s1)
/* 1861C 8003D21C AFB20010 */  sw        $s2, 0x10($sp)
/* 18620 8003D220 0800F4AA */  j         .L8003D2A8
/* 18624 8003D224 AFA00014 */   sw       $zero, 0x14($sp)
/* 18628 8003D228 2405000D */  addiu     $a1, $zero, 0xd
/* 1862C 8003D22C 0200302D */  daddu     $a2, $s0, $zero
/* 18630 8003D230 24020016 */  addiu     $v0, $zero, 0x16
/* 18634 8003D234 A22200AA */  sb        $v0, 0xaa($s1)
/* 18638 8003D238 AFB20010 */  sw        $s2, 0x10($sp)
/* 1863C 8003D23C 0800F4AA */  j         .L8003D2A8
/* 18640 8003D240 AFB60014 */   sw       $s6, 0x14($sp)
/* 18644 8003D244 2405000E */  addiu     $a1, $zero, 0xe
/* 18648 8003D248 0200302D */  daddu     $a2, $s0, $zero
/* 1864C 8003D24C 2402000D */  addiu     $v0, $zero, 0xd
/* 18650 8003D250 A22200AA */  sb        $v0, 0xaa($s1)
/* 18654 8003D254 240200FF */  addiu     $v0, $zero, 0xff
/* 18658 8003D258 AFB20010 */  sw        $s2, 0x10($sp)
/* 1865C 8003D25C 0800F4AA */  j         .L8003D2A8
/* 18660 8003D260 AFA20014 */   sw       $v0, 0x14($sp)
/* 18664 8003D264 2405000F */  addiu     $a1, $zero, 0xf
/* 18668 8003D268 0200302D */  daddu     $a2, $s0, $zero
/* 1866C 8003D26C 2402000D */  addiu     $v0, $zero, 0xd
/* 18670 8003D270 A22200AA */  sb        $v0, 0xaa($s1)
/* 18674 8003D274 240200FF */  addiu     $v0, $zero, 0xff
/* 18678 8003D278 AFA00010 */  sw        $zero, 0x10($sp)
/* 1867C 8003D27C AFA20014 */  sw        $v0, 0x14($sp)
/* 18680 8003D280 AFB30018 */  sw        $s3, 0x18($sp)
/* 18684 8003D284 8E240024 */  lw        $a0, 0x24($s1)
/* 18688 8003D288 0800F4AD */  j         .L8003D2B4
/* 1868C 8003D28C 0040382D */   daddu    $a3, $v0, $zero
/* 18690 8003D290 2405000F */  addiu     $a1, $zero, 0xf
/* 18694 8003D294 0200302D */  daddu     $a2, $s0, $zero
/* 18698 8003D298 24020016 */  addiu     $v0, $zero, 0x16
/* 1869C 8003D29C A22200AA */  sb        $v0, 0xaa($s1)
/* 186A0 8003D2A0 AFA00010 */  sw        $zero, 0x10($sp)
/* 186A4 8003D2A4 AFB50014 */  sw        $s5, 0x14($sp)
.L8003D2A8:
/* 186A8 8003D2A8 AFB30018 */  sw        $s3, 0x18($sp)
/* 186AC 8003D2AC 8E240024 */  lw        $a0, 0x24($s1)
/* 186B0 8003D2B0 02A0382D */  daddu     $a3, $s5, $zero
.L8003D2B4:
/* 186B4 8003D2B4 0C0448F9 */  jal       func_801123E4
/* 186B8 8003D2B8 00000000 */   nop
.L8003D2BC:
/* 186BC 8003D2BC 8FBF003C */  lw        $ra, 0x3c($sp)
/* 186C0 8003D2C0 8FB60038 */  lw        $s6, 0x38($sp)
/* 186C4 8003D2C4 8FB50034 */  lw        $s5, 0x34($sp)
/* 186C8 8003D2C8 8FB40030 */  lw        $s4, 0x30($sp)
/* 186CC 8003D2CC 8FB3002C */  lw        $s3, 0x2c($sp)
/* 186D0 8003D2D0 8FB20028 */  lw        $s2, 0x28($sp)
/* 186D4 8003D2D4 8FB10024 */  lw        $s1, 0x24($sp)
/* 186D8 8003D2D8 8FB00020 */  lw        $s0, 0x20($sp)
/* 186DC 8003D2DC 03E00008 */  jr        $ra
/* 186E0 8003D2E0 27BD0040 */   addiu    $sp, $sp, 0x40

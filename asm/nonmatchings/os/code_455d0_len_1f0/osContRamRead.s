.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel osContRamRead
/* 455D0 8006A1D0 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 455D4 8006A1D4 AFB40038 */  sw        $s4, 0x38($sp)
/* 455D8 8006A1D8 0080A021 */  addu      $s4, $a0, $zero
/* 455DC 8006A1DC AFB30034 */  sw        $s3, 0x34($sp)
/* 455E0 8006A1E0 00A09821 */  addu      $s3, $a1, $zero
/* 455E4 8006A1E4 AFB5003C */  sw        $s5, 0x3c($sp)
/* 455E8 8006A1E8 24150002 */  addiu     $s5, $zero, 2
/* 455EC 8006A1EC AFB00028 */  sw        $s0, 0x28($sp)
/* 455F0 8006A1F0 00C08021 */  addu      $s0, $a2, $zero
/* 455F4 8006A1F4 AFBF004C */  sw        $ra, 0x4c($sp)
/* 455F8 8006A1F8 AFBE0048 */  sw        $fp, 0x48($sp)
/* 455FC 8006A1FC AFB70044 */  sw        $s7, 0x44($sp)
/* 45600 8006A200 AFB60040 */  sw        $s6, 0x40($sp)
/* 45604 8006A204 AFB20030 */  sw        $s2, 0x30($sp)
/* 45608 8006A208 AFB1002C */  sw        $s1, 0x2c($sp)
/* 4560C 8006A20C 0C019771 */  jal       osSiGetAccess
/* 45610 8006A210 AFA70014 */   sw       $a3, 0x14($sp)
/* 45614 8006A214 24170002 */  addiu     $s7, $zero, 2
/* 45618 8006A218 3216FFFF */  andi      $s6, $s0, 0xffff
/* 4561C 8006A21C 00108140 */  sll       $s0, $s0, 5
/* 45620 8006A220 3C1E800E */  lui       $fp, %hi(D_800DA000)
/* 45624 8006A224 27DEA000 */  addiu     $fp, $fp, %lo(D_800DA000)
/* 45628 8006A228 AFB0001C */  sw        $s0, 0x1c($sp)
.L8006A22C:
/* 4562C 8006A22C 3C02800A */  lui       $v0, %hi(D_8009A61C)
/* 45630 8006A230 9042A61C */  lbu       $v0, %lo(D_8009A61C)($v0)
/* 45634 8006A234 3C10800E */  lui       $s0, %hi(D_800DA000)
/* 45638 8006A238 14570005 */  bne       $v0, $s7, .L8006A250
/* 4563C 8006A23C 2610A000 */   addiu    $s0, $s0, %lo(D_800DA000)
/* 45640 8006A240 3C028009 */  lui       $v0, %hi(D_800958E0)
/* 45644 8006A244 8C4258E0 */  lw        $v0, %lo(D_800958E0)($v0)
/* 45648 8006A248 50530019 */  beql      $v0, $s3, .L8006A2B0
/* 4564C 8006A24C 02708021 */   addu     $s0, $s3, $s0
.L8006A250:
/* 45650 8006A250 3C01800A */  lui       $at, %hi(D_8009A61C)
/* 45654 8006A254 A037A61C */  sb        $s7, %lo(D_8009A61C)($at)
/* 45658 8006A258 3C018009 */  lui       $at, %hi(D_800958E0)
/* 4565C 8006A25C AC3358E0 */  sw        $s3, %lo(D_800958E0)($at)
/* 45660 8006A260 1A600006 */  blez      $s3, .L8006A27C
/* 45664 8006A264 00001821 */   addu     $v1, $zero, $zero
.L8006A268:
/* 45668 8006A268 A2000000 */  sb        $zero, ($s0)
/* 4566C 8006A26C 24630001 */  addiu     $v1, $v1, 1
/* 45670 8006A270 0073102A */  slt       $v0, $v1, $s3
/* 45674 8006A274 1440FFFC */  bnez      $v0, .L8006A268
/* 45678 8006A278 26100001 */   addiu    $s0, $s0, 1
.L8006A27C:
/* 4567C 8006A27C 24020001 */  addiu     $v0, $zero, 1
/* 45680 8006A280 3C01800E */  lui       $at, %hi(D_800DA03C)
/* 45684 8006A284 AC22A03C */  sw        $v0, %lo(D_800DA03C)($at)
/* 45688 8006A288 240800FF */  addiu     $t0, $zero, 0xff
/* 4568C 8006A28C 24020003 */  addiu     $v0, $zero, 3
/* 45690 8006A290 A2020001 */  sb        $v0, 1($s0)
/* 45694 8006A294 24020021 */  addiu     $v0, $zero, 0x21
/* 45698 8006A298 A2080000 */  sb        $t0, ($s0)
/* 4569C 8006A29C A2020002 */  sb        $v0, 2($s0)
/* 456A0 8006A2A0 240200FE */  addiu     $v0, $zero, 0xfe
/* 456A4 8006A2A4 A2170003 */  sb        $s7, 3($s0)
/* 456A8 8006A2A8 A2080026 */  sb        $t0, 0x26($s0)
/* 456AC 8006A2AC A2020027 */  sb        $v0, 0x27($s0)
.L8006A2B0:
/* 456B0 8006A2B0 02C02021 */  addu      $a0, $s6, $zero
/* 456B4 8006A2B4 001610C2 */  srl       $v0, $s6, 3
/* 456B8 8006A2B8 0C01B218 */  jal       osContAddressCrc
/* 456BC 8006A2BC A2020004 */   sb       $v0, 4($s0)
/* 456C0 8006A2C0 8FA8001C */  lw        $t0, 0x1c($sp)
/* 456C4 8006A2C4 24040001 */  addiu     $a0, $zero, 1
/* 456C8 8006A2C8 03C02821 */  addu      $a1, $fp, $zero
/* 456CC 8006A2CC 00481025 */  or        $v0, $v0, $t0
/* 456D0 8006A2D0 0C019730 */  jal       osSiRawStartDma
/* 456D4 8006A2D4 A2020005 */   sb       $v0, 5($s0)
/* 456D8 8006A2D8 02802021 */  addu      $a0, $s4, $zero
/* 456DC 8006A2DC 00002821 */  addu      $a1, $zero, $zero
/* 456E0 8006A2E0 0C0195BC */  jal       osRecvMesg
/* 456E4 8006A2E4 24060001 */   addiu    $a2, $zero, 1
/* 456E8 8006A2E8 00002021 */  addu      $a0, $zero, $zero
/* 456EC 8006A2EC 0C019730 */  jal       osSiRawStartDma
/* 456F0 8006A2F0 03C02821 */   addu     $a1, $fp, $zero
/* 456F4 8006A2F4 02802021 */  addu      $a0, $s4, $zero
/* 456F8 8006A2F8 00002821 */  addu      $a1, $zero, $zero
/* 456FC 8006A2FC 0C0195BC */  jal       osRecvMesg
/* 45700 8006A300 24060001 */   addiu    $a2, $zero, 1
/* 45704 8006A304 92020002 */  lbu       $v0, 2($s0)
/* 45708 8006A308 304200C0 */  andi      $v0, $v0, 0xc0
/* 4570C 8006A30C 00028902 */  srl       $s1, $v0, 4
/* 45710 8006A310 56200015 */  bnel      $s1, $zero, .L8006A368
/* 45714 8006A314 24110001 */   addiu    $s1, $zero, 1
/* 45718 8006A318 26120006 */  addiu     $s2, $s0, 6
/* 4571C 8006A31C 0C01B233 */  jal       osContDataCrc
/* 45720 8006A320 02402021 */   addu     $a0, $s2, $zero
/* 45724 8006A324 92030026 */  lbu       $v1, 0x26($s0)
/* 45728 8006A328 304200FF */  andi      $v0, $v0, 0xff
/* 4572C 8006A32C 10430008 */  beq       $v0, $v1, .L8006A350
/* 45730 8006A330 02802021 */   addu     $a0, $s4, $zero
/* 45734 8006A334 0C01A530 */  jal       osPfsGetStatus
/* 45738 8006A338 02602821 */   addu     $a1, $s3, $zero
/* 4573C 8006A33C 00408821 */  addu      $s1, $v0, $zero
/* 45740 8006A340 1620000E */  bnez      $s1, .L8006A37C
/* 45744 8006A344 00000000 */   nop
/* 45748 8006A348 0801A8DA */  j         .L8006A368
/* 4574C 8006A34C 24110004 */   addiu    $s1, $zero, 4
.L8006A350:
/* 45750 8006A350 8FA50014 */  lw        $a1, 0x14($sp)
/* 45754 8006A354 02402021 */  addu      $a0, $s2, $zero
/* 45758 8006A358 0C019194 */  jal       bcopy
/* 4575C 8006A35C 24060020 */   addiu    $a2, $zero, 0x20
/* 45760 8006A360 0801A8DB */  j         .L8006A36C
/* 45764 8006A364 24020004 */   addiu    $v0, $zero, 4
.L8006A368:
/* 45768 8006A368 24020004 */  addiu     $v0, $zero, 4
.L8006A36C:
/* 4576C 8006A36C 16220003 */  bne       $s1, $v0, .L8006A37C
/* 45770 8006A370 02A01021 */   addu     $v0, $s5, $zero
/* 45774 8006A374 0441FFAD */  bgez      $v0, .L8006A22C
/* 45778 8006A378 26B5FFFF */   addiu    $s5, $s5, -1
.L8006A37C:
/* 4577C 8006A37C 0C01978C */  jal       osSiRelAccess
/* 45780 8006A380 00000000 */   nop
/* 45784 8006A384 02201021 */  addu      $v0, $s1, $zero
/* 45788 8006A388 8FBF004C */  lw        $ra, 0x4c($sp)
/* 4578C 8006A38C 8FBE0048 */  lw        $fp, 0x48($sp)
/* 45790 8006A390 8FB70044 */  lw        $s7, 0x44($sp)
/* 45794 8006A394 8FB60040 */  lw        $s6, 0x40($sp)
/* 45798 8006A398 8FB5003C */  lw        $s5, 0x3c($sp)
/* 4579C 8006A39C 8FB40038 */  lw        $s4, 0x38($sp)
/* 457A0 8006A3A0 8FB30034 */  lw        $s3, 0x34($sp)
/* 457A4 8006A3A4 8FB20030 */  lw        $s2, 0x30($sp)
/* 457A8 8006A3A8 8FB1002C */  lw        $s1, 0x2c($sp)
/* 457AC 8006A3AC 8FB00028 */  lw        $s0, 0x28($sp)
/* 457B0 8006A3B0 03E00008 */  jr        $ra
/* 457B4 8006A3B4 27BD0050 */   addiu    $sp, $sp, 0x50
/* 457B8 8006A3B8 00000000 */  nop
/* 457BC 8006A3BC 00000000 */  nop

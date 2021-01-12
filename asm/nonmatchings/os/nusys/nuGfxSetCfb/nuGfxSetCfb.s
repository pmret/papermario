.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel nuGfxSetCfb
/* 3A6F0 8005F2F0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 3A6F4 8005F2F4 AFB10014 */  sw        $s1, 0x14($sp)
/* 3A6F8 8005F2F8 00A0882D */  daddu     $s1, $a1, $zero
/* 3A6FC 8005F2FC AFBF0018 */  sw        $ra, 0x18($sp)
/* 3A700 8005F300 AFB00010 */  sw        $s0, 0x10($sp)
/* 3A704 8005F304 3C01800A */  lui       $at, %hi(D_8009A658)
/* 3A708 8005F308 AC24A658 */  sw        $a0, %lo(D_8009A658)($at)
/* 3A70C 8005F30C 3C018007 */  lui       $at, %hi(D_800773F0)
/* 3A710 8005F310 AC3173F0 */  sw        $s1, %lo(D_800773F0)($at)
/* 3A714 8005F314 3C01800A */  lui       $at, %hi(D_8009A5F0)
/* 3A718 8005F318 AC20A5F0 */  sw        $zero, %lo(D_8009A5F0)($at)
/* 3A71C 8005F31C 8C820000 */  lw        $v0, ($a0)
/* 3A720 8005F320 3C01800A */  lui       $at, %hi(D_8009A64C)
/* 3A724 8005F324 AC22A64C */  sw        $v0, %lo(D_8009A64C)($at)
/* 3A728 8005F328 0C0180DC */  jal       nuGfxRetraceWait
/* 3A72C 8005F32C 24040001 */   addiu    $a0, $zero, 1
/* 3A730 8005F330 0C017BE4 */  jal       nuScSetFrameBufferNum
/* 3A734 8005F334 322400FF */   andi     $a0, $s1, 0xff
/* 3A738 8005F338 2E220002 */  sltiu     $v0, $s1, 2
/* 3A73C 8005F33C 1440002A */  bnez      $v0, .L8005F3E8
/* 3A740 8005F340 2625FFFF */   addiu    $a1, $s1, -1
/* 3A744 8005F344 10A0000B */  beqz      $a1, .L8005F374
/* 3A748 8005F348 0000802D */   daddu    $s0, $zero, $zero
/* 3A74C 8005F34C 3C04800A */  lui       $a0, %hi(D_8009A658)
/* 3A750 8005F350 8C84A658 */  lw        $a0, %lo(D_8009A658)($a0)
.L8005F354:
/* 3A754 8005F354 8C830000 */  lw        $v1, ($a0)
/* 3A758 8005F358 8C820004 */  lw        $v0, 4($a0)
/* 3A75C 8005F35C 14620006 */  bne       $v1, $v0, .L8005F378
/* 3A760 8005F360 2622FFFF */   addiu    $v0, $s1, -1
/* 3A764 8005F364 26100001 */  addiu     $s0, $s0, 1
/* 3A768 8005F368 0205102B */  sltu      $v0, $s0, $a1
/* 3A76C 8005F36C 1440FFF9 */  bnez      $v0, .L8005F354
/* 3A770 8005F370 24840004 */   addiu    $a0, $a0, 4
.L8005F374:
/* 3A774 8005F374 2622FFFF */  addiu     $v0, $s1, -1
.L8005F378:
/* 3A778 8005F378 1602000C */  bne       $s0, $v0, .L8005F3AC
/* 3A77C 8005F37C 00000000 */   nop
/* 3A780 8005F380 0C017BE4 */  jal       nuScSetFrameBufferNum
/* 3A784 8005F384 24040001 */   addiu    $a0, $zero, 1
/* 3A788 8005F388 08017CFA */  j         .L8005F3E8
/* 3A78C 8005F38C 00000000 */   nop
.L8005F390:
/* 3A790 8005F390 8C820000 */  lw        $v0, ($a0)
/* 3A794 8005F394 3C01800A */  lui       $at, %hi(D_8009A5F0)
/* 3A798 8005F398 AC30A5F0 */  sw        $s0, %lo(D_8009A5F0)($at)
/* 3A79C 8005F39C 3C01800A */  lui       $at, %hi(D_8009A64C)
/* 3A7A0 8005F3A0 AC22A64C */  sw        $v0, %lo(D_8009A64C)($at)
/* 3A7A4 8005F3A4 08017CFA */  j         .L8005F3E8
/* 3A7A8 8005F3A8 00000000 */   nop
.L8005F3AC:
/* 3A7AC 8005F3AC 1220000E */  beqz      $s1, .L8005F3E8
/* 3A7B0 8005F3B0 0000802D */   daddu    $s0, $zero, $zero
.L8005F3B4:
/* 3A7B4 8005F3B4 0C019A6C */  jal       osViGetCurrentFramebuffer
/* 3A7B8 8005F3B8 00000000 */   nop
/* 3A7BC 8005F3BC 3C03800A */  lui       $v1, %hi(D_8009A658)
/* 3A7C0 8005F3C0 8C63A658 */  lw        $v1, %lo(D_8009A658)($v1)
/* 3A7C4 8005F3C4 00102080 */  sll       $a0, $s0, 2
/* 3A7C8 8005F3C8 00832021 */  addu      $a0, $a0, $v1
/* 3A7CC 8005F3CC 8C830000 */  lw        $v1, ($a0)
/* 3A7D0 8005F3D0 1443FFEF */  bne       $v0, $v1, .L8005F390
/* 3A7D4 8005F3D4 00000000 */   nop
/* 3A7D8 8005F3D8 26100001 */  addiu     $s0, $s0, 1
/* 3A7DC 8005F3DC 0211102B */  sltu      $v0, $s0, $s1
/* 3A7E0 8005F3E0 1440FFF4 */  bnez      $v0, .L8005F3B4
/* 3A7E4 8005F3E4 00000000 */   nop
.L8005F3E8:
/* 3A7E8 8005F3E8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 3A7EC 8005F3EC 8FB10014 */  lw        $s1, 0x14($sp)
/* 3A7F0 8005F3F0 8FB00010 */  lw        $s0, 0x10($sp)
/* 3A7F4 8005F3F4 03E00008 */  jr        $ra
/* 3A7F8 8005F3F8 27BD0020 */   addiu    $sp, $sp, 0x20
/* 3A7FC 8005F3FC 00000000 */  nop

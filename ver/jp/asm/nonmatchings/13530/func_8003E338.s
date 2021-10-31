.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8003E338
/* 19738 8003E338 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1973C 8003E33C 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 19740 8003E340 3C08800B */  lui       $t0, %hi(D_800B0EF0)
/* 19744 8003E344 25080EF0 */  addiu     $t0, $t0, %lo(D_800B0EF0)
/* 19748 8003E348 A1040021 */  sb        $a0, 0x21($t0)
/* 1974C 8003E34C A1050020 */  sb        $a1, 0x20($t0)
/* 19750 8003E350 AD060024 */  sw        $a2, 0x24($t0)
/* 19754 8003E354 8442008A */  lh        $v0, 0x8a($v0)
/* 19758 8003E358 1040001B */  beqz      $v0, .L8003E3C8
/* 1975C 8003E35C 00000000 */   nop
/* 19760 8003E360 0000282D */  daddu     $a1, $zero, $zero
/* 19764 8003E364 00A0382D */  daddu     $a3, $a1, $zero
.L8003E368:
/* 19768 8003E368 0000202D */  daddu     $a0, $zero, $zero
/* 1976C 8003E36C 00E0182D */  daddu     $v1, $a3, $zero
.L8003E370:
/* 19770 8003E370 01031021 */  addu      $v0, $t0, $v1
/* 19774 8003E374 AC4000B0 */  sw        $zero, 0xb0($v0)
/* 19778 8003E378 24840001 */  addiu     $a0, $a0, 1
/* 1977C 8003E37C 2882000C */  slti      $v0, $a0, 0xc
/* 19780 8003E380 1440FFFB */  bnez      $v0, .L8003E370
/* 19784 8003E384 24630004 */   addiu    $v1, $v1, 4
/* 19788 8003E388 24A50001 */  addiu     $a1, $a1, 1
/* 1978C 8003E38C 28A2003C */  slti      $v0, $a1, 0x3c
/* 19790 8003E390 1440FFF5 */  bnez      $v0, .L8003E368
/* 19794 8003E394 24E70030 */   addiu    $a3, $a3, 0x30
/* 19798 8003E398 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 1979C 8003E39C 8C42417C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 197A0 8003E3A0 8442008A */  lh        $v0, 0x8a($v0)
/* 197A4 8003E3A4 10400008 */  beqz      $v0, .L8003E3C8
/* 197A8 8003E3A8 00000000 */   nop
/* 197AC 8003E3AC 2403FFFF */  addiu     $v1, $zero, -1
/* 197B0 8003E3B0 24050001 */  addiu     $a1, $zero, 1
/* 197B4 8003E3B4 25020002 */  addiu     $v0, $t0, 2
.L8003E3B8:
/* 197B8 8003E3B8 A4430BF0 */  sh        $v1, 0xbf0($v0)
/* 197BC 8003E3BC 24A5FFFF */  addiu     $a1, $a1, -1
/* 197C0 8003E3C0 04A1FFFD */  bgez      $a1, .L8003E3B8
/* 197C4 8003E3C4 2442FFFE */   addiu    $v0, $v0, -2
.L8003E3C8:
/* 197C8 8003E3C8 10C00007 */  beqz      $a2, .L8003E3E8
/* 197CC 8003E3CC 24020001 */   addiu    $v0, $zero, 1
/* 197D0 8003E3D0 3C01800A */  lui       $at, %hi(D_8009A5E0)
/* 197D4 8003E3D4 AC22A5E0 */  sw        $v0, %lo(D_8009A5E0)($at)
/* 197D8 8003E3D8 3C01800A */  lui       $at, %hi(D_8009A658)
/* 197DC 8003E3DC AC22A658 */  sw        $v0, %lo(D_8009A658)($at)
/* 197E0 8003E3E0 3C01800A */  lui       $at, %hi(D_8009A5B0)
/* 197E4 8003E3E4 AC20A5B0 */  sw        $zero, %lo(D_8009A5B0)($at)
.L8003E3E8:
/* 197E8 8003E3E8 03E00008 */  jr        $ra
/* 197EC 8003E3EC 00000000 */   nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241180_96A340
/* 96A340 80241180 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 96A344 80241184 AFB10014 */  sw        $s1, 0x14($sp)
/* 96A348 80241188 0080882D */  daddu     $s1, $a0, $zero
/* 96A34C 8024118C AFB00010 */  sw        $s0, 0x10($sp)
/* 96A350 80241190 00A0802D */  daddu     $s0, $a1, $zero
/* 96A354 80241194 AFBF0018 */  sw        $ra, 0x18($sp)
/* 96A358 80241198 0C00EABB */  jal       get_npc_unsafe
/* 96A35C 8024119C 2404FFFC */   addiu    $a0, $zero, -4
/* 96A360 802411A0 12000003 */  beqz      $s0, .L802411B0
/* 96A364 802411A4 0040182D */   daddu    $v1, $v0, $zero
/* 96A368 802411A8 2402003C */  addiu     $v0, $zero, 0x3c
/* 96A36C 802411AC AE220070 */  sw        $v0, 0x70($s1)
.L802411B0:
/* 96A370 802411B0 C462000C */  lwc1      $f2, 0xc($v1)
/* 96A374 802411B4 3C0141F0 */  lui       $at, 0x41f0
/* 96A378 802411B8 44810000 */  mtc1      $at, $f0
/* 96A37C 802411BC 00000000 */  nop       
/* 96A380 802411C0 46001000 */  add.s     $f0, $f2, $f0
/* 96A384 802411C4 3C0143B4 */  lui       $at, 0x43b4
/* 96A388 802411C8 44811000 */  mtc1      $at, $f2
/* 96A38C 802411CC 00000000 */  nop       
/* 96A390 802411D0 4600103E */  c.le.s    $f2, $f0
/* 96A394 802411D4 00000000 */  nop       
/* 96A398 802411D8 45000003 */  bc1f      .L802411E8
/* 96A39C 802411DC E460000C */   swc1     $f0, 0xc($v1)
/* 96A3A0 802411E0 46020001 */  sub.s     $f0, $f0, $f2
/* 96A3A4 802411E4 E460000C */  swc1      $f0, 0xc($v1)
.L802411E8:
/* 96A3A8 802411E8 8E230070 */  lw        $v1, 0x70($s1)
/* 96A3AC 802411EC 2463FFFF */  addiu     $v1, $v1, -1
/* 96A3B0 802411F0 000317C3 */  sra       $v0, $v1, 0x1f
/* 96A3B4 802411F4 AE230070 */  sw        $v1, 0x70($s1)
/* 96A3B8 802411F8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 96A3BC 802411FC 8FB10014 */  lw        $s1, 0x14($sp)
/* 96A3C0 80241200 8FB00010 */  lw        $s0, 0x10($sp)
/* 96A3C4 80241204 30420002 */  andi      $v0, $v0, 2
/* 96A3C8 80241208 03E00008 */  jr        $ra
/* 96A3CC 8024120C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802414B0
/* 7EC1C0 802414B0 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7EC1C4 802414B4 AFB10014 */  sw        $s1, 0x14($sp)
/* 7EC1C8 802414B8 0080882D */  daddu     $s1, $a0, $zero
/* 7EC1CC 802414BC AFB00010 */  sw        $s0, 0x10($sp)
/* 7EC1D0 802414C0 00A0802D */  daddu     $s0, $a1, $zero
/* 7EC1D4 802414C4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 7EC1D8 802414C8 0C00EABB */  jal       get_npc_unsafe
/* 7EC1DC 802414CC 2404FFFC */   addiu    $a0, $zero, -4
/* 7EC1E0 802414D0 12000003 */  beqz      $s0, .L802414E0
/* 7EC1E4 802414D4 0040182D */   daddu    $v1, $v0, $zero
/* 7EC1E8 802414D8 2402003C */  addiu     $v0, $zero, 0x3c
/* 7EC1EC 802414DC AE220070 */  sw        $v0, 0x70($s1)
.L802414E0:
/* 7EC1F0 802414E0 C462000C */  lwc1      $f2, 0xc($v1)
/* 7EC1F4 802414E4 3C0141F0 */  lui       $at, 0x41f0
/* 7EC1F8 802414E8 44810000 */  mtc1      $at, $f0
/* 7EC1FC 802414EC 00000000 */  nop       
/* 7EC200 802414F0 46001000 */  add.s     $f0, $f2, $f0
/* 7EC204 802414F4 3C0143B4 */  lui       $at, 0x43b4
/* 7EC208 802414F8 44811000 */  mtc1      $at, $f2
/* 7EC20C 802414FC 00000000 */  nop       
/* 7EC210 80241500 4600103E */  c.le.s    $f2, $f0
/* 7EC214 80241504 00000000 */  nop       
/* 7EC218 80241508 45000003 */  bc1f      .L80241518
/* 7EC21C 8024150C E460000C */   swc1     $f0, 0xc($v1)
/* 7EC220 80241510 46020001 */  sub.s     $f0, $f0, $f2
/* 7EC224 80241514 E460000C */  swc1      $f0, 0xc($v1)
.L80241518:
/* 7EC228 80241518 8E230070 */  lw        $v1, 0x70($s1)
/* 7EC22C 8024151C 2463FFFF */  addiu     $v1, $v1, -1
/* 7EC230 80241520 000317C3 */  sra       $v0, $v1, 0x1f
/* 7EC234 80241524 AE230070 */  sw        $v1, 0x70($s1)
/* 7EC238 80241528 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7EC23C 8024152C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7EC240 80241530 8FB00010 */  lw        $s0, 0x10($sp)
/* 7EC244 80241534 30420002 */  andi      $v0, $v0, 2
/* 7EC248 80241538 03E00008 */  jr        $ra
/* 7EC24C 8024153C 27BD0020 */   addiu    $sp, $sp, 0x20

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242790_9D97B0
/* 9D97B0 80242790 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 9D97B4 80242794 AFB10014 */  sw        $s1, 0x14($sp)
/* 9D97B8 80242798 0080882D */  daddu     $s1, $a0, $zero
/* 9D97BC 8024279C AFB00010 */  sw        $s0, 0x10($sp)
/* 9D97C0 802427A0 00A0802D */  daddu     $s0, $a1, $zero
/* 9D97C4 802427A4 AFBF0018 */  sw        $ra, 0x18($sp)
/* 9D97C8 802427A8 0C00EABB */  jal       get_npc_unsafe
/* 9D97CC 802427AC 2404FFFC */   addiu    $a0, $zero, -4
/* 9D97D0 802427B0 12000003 */  beqz      $s0, .L802427C0
/* 9D97D4 802427B4 0040182D */   daddu    $v1, $v0, $zero
/* 9D97D8 802427B8 2402003C */  addiu     $v0, $zero, 0x3c
/* 9D97DC 802427BC AE220070 */  sw        $v0, 0x70($s1)
.L802427C0:
/* 9D97E0 802427C0 C462000C */  lwc1      $f2, 0xc($v1)
/* 9D97E4 802427C4 3C0141F0 */  lui       $at, 0x41f0
/* 9D97E8 802427C8 44810000 */  mtc1      $at, $f0
/* 9D97EC 802427CC 00000000 */  nop       
/* 9D97F0 802427D0 46001000 */  add.s     $f0, $f2, $f0
/* 9D97F4 802427D4 3C0143B4 */  lui       $at, 0x43b4
/* 9D97F8 802427D8 44811000 */  mtc1      $at, $f2
/* 9D97FC 802427DC 00000000 */  nop       
/* 9D9800 802427E0 4600103E */  c.le.s    $f2, $f0
/* 9D9804 802427E4 00000000 */  nop       
/* 9D9808 802427E8 45000003 */  bc1f      .L802427F8
/* 9D980C 802427EC E460000C */   swc1     $f0, 0xc($v1)
/* 9D9810 802427F0 46020001 */  sub.s     $f0, $f0, $f2
/* 9D9814 802427F4 E460000C */  swc1      $f0, 0xc($v1)
.L802427F8:
/* 9D9818 802427F8 8E230070 */  lw        $v1, 0x70($s1)
/* 9D981C 802427FC 2463FFFF */  addiu     $v1, $v1, -1
/* 9D9820 80242800 000317C3 */  sra       $v0, $v1, 0x1f
/* 9D9824 80242804 AE230070 */  sw        $v1, 0x70($s1)
/* 9D9828 80242808 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9D982C 8024280C 8FB10014 */  lw        $s1, 0x14($sp)
/* 9D9830 80242810 8FB00010 */  lw        $s0, 0x10($sp)
/* 9D9834 80242814 30420002 */  andi      $v0, $v0, 2
/* 9D9838 80242818 03E00008 */  jr        $ra
/* 9D983C 8024281C 27BD0020 */   addiu    $sp, $sp, 0x20

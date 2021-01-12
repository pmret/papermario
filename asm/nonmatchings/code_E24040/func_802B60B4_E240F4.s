.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B60B4_E240F4
/* E240F4 802B60B4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E240F8 802B60B8 AFB00010 */  sw        $s0, 0x10($sp)
/* E240FC 802B60BC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24100 802B60C0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24104 802B60C4 AFBF0014 */  sw        $ra, 0x14($sp)
/* E24108 802B60C8 8E030000 */  lw        $v1, ($s0)
/* E2410C 802B60CC 0461001D */  bgez      $v1, .L802B6144
/* E24110 802B60D0 3C027FFF */   lui      $v0, 0x7fff
/* E24114 802B60D4 3442FFFF */  ori       $v0, $v0, 0xffff
/* E24118 802B60D8 00621024 */  and       $v0, $v1, $v0
/* E2411C 802B60DC 0C0AD800 */  jal       func_802B6000_E24040
/* E24120 802B60E0 AE020000 */   sw       $v0, ($s0)
/* E24124 802B60E4 820300B4 */  lb        $v1, 0xb4($s0)
/* E24128 802B60E8 24020006 */  addiu     $v0, $zero, 6
/* E2412C 802B60EC 14620005 */  bne       $v1, $v0, .L802B6104
/* E24130 802B60F0 00000000 */   nop      
/* E24134 802B60F4 0C03954C */  jal       func_800E5530
/* E24138 802B60F8 00000000 */   nop      
/* E2413C 802B60FC 080AD846 */  j         .L802B6118
/* E24140 802B6100 00000000 */   nop      
.L802B6104:
/* E24144 802B6104 3C03800B */  lui       $v1, %hi(gCameras)
/* E24148 802B6108 24631D80 */  addiu     $v1, $v1, %lo(gCameras)
/* E2414C 802B610C 94620002 */  lhu       $v0, 2($v1)
/* E24150 802B6110 34420001 */  ori       $v0, $v0, 1
/* E24154 802B6114 A4620002 */  sh        $v0, 2($v1)
.L802B6118:
/* E24158 802B6118 820300B4 */  lb        $v1, 0xb4($s0)
/* E2415C 802B611C 24020003 */  addiu     $v0, $zero, 3
/* E24160 802B6120 14620008 */  bne       $v1, $v0, .L802B6144
/* E24164 802B6124 00000000 */   nop      
/* E24168 802B6128 8E020004 */  lw        $v0, 4($s0)
/* E2416C 802B612C 30424000 */  andi      $v0, $v0, 0x4000
/* E24170 802B6130 10400002 */  beqz      $v0, .L802B613C
/* E24174 802B6134 24042081 */   addiu    $a0, $zero, 0x2081
/* E24178 802B6138 24042082 */  addiu     $a0, $zero, 0x2082
.L802B613C:
/* E2417C 802B613C 0C052736 */  jal       play_sound_at_player
/* E24180 802B6140 0000282D */   daddu    $a1, $zero, $zero
.L802B6144:
/* E24184 802B6144 8E030004 */  lw        $v1, 4($s0)
/* E24188 802B6148 30624000 */  andi      $v0, $v1, 0x4000
/* E2418C 802B614C 10400003 */  beqz      $v0, .L802B615C
/* E24190 802B6150 3C040009 */   lui      $a0, 9
/* E24194 802B6154 080AD85D */  j         .L802B6174
/* E24198 802B6158 34840005 */   ori      $a0, $a0, 5
.L802B615C:
/* E2419C 802B615C 3C040006 */  lui       $a0, 6
/* E241A0 802B6160 30620003 */  andi      $v0, $v1, 3
/* E241A4 802B6164 14400003 */  bnez      $v0, .L802B6174
/* E241A8 802B6168 34840009 */   ori      $a0, $a0, 9
/* E241AC 802B616C 3C040001 */  lui       $a0, 1
/* E241B0 802B6170 34840007 */  ori       $a0, $a0, 7
.L802B6174:
/* E241B4 802B6174 0C037FBF */  jal       func_800DFEFC
/* E241B8 802B6178 00000000 */   nop      
/* E241BC 802B617C 960200C0 */  lhu       $v0, 0xc0($s0)
/* E241C0 802B6180 24420001 */  addiu     $v0, $v0, 1
/* E241C4 802B6184 A60200C0 */  sh        $v0, 0xc0($s0)
/* E241C8 802B6188 8FBF0014 */  lw        $ra, 0x14($sp)
/* E241CC 802B618C 8FB00010 */  lw        $s0, 0x10($sp)
/* E241D0 802B6190 03E00008 */  jr        $ra
/* E241D4 802B6194 27BD0018 */   addiu    $sp, $sp, 0x18

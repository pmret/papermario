.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240828_B9E188
/* B9E188 80240828 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* B9E18C 8024082C AFB40040 */  sw        $s4, 0x40($sp)
/* B9E190 80240830 0080A02D */  daddu     $s4, $a0, $zero
/* B9E194 80240834 AFBF0044 */  sw        $ra, 0x44($sp)
/* B9E198 80240838 AFB3003C */  sw        $s3, 0x3c($sp)
/* B9E19C 8024083C AFB20038 */  sw        $s2, 0x38($sp)
/* B9E1A0 80240840 AFB10034 */  sw        $s1, 0x34($sp)
/* B9E1A4 80240844 AFB00030 */  sw        $s0, 0x30($sp)
/* B9E1A8 80240848 8E920148 */  lw        $s2, 0x148($s4)
/* B9E1AC 8024084C 00A0882D */  daddu     $s1, $a1, $zero
/* B9E1B0 80240850 86440008 */  lh        $a0, 8($s2)
/* B9E1B4 80240854 0C00EABB */  jal       get_npc_unsafe
/* B9E1B8 80240858 00C0982D */   daddu    $s3, $a2, $zero
/* B9E1BC 8024085C 8E230014 */  lw        $v1, 0x14($s1)
/* B9E1C0 80240860 0460002D */  bltz      $v1, .L80240918
/* B9E1C4 80240864 0040802D */   daddu    $s0, $v0, $zero
/* B9E1C8 80240868 0260202D */  daddu     $a0, $s3, $zero
/* B9E1CC 8024086C AFA00010 */  sw        $zero, 0x10($sp)
/* B9E1D0 80240870 8E260024 */  lw        $a2, 0x24($s1)
/* B9E1D4 80240874 8E270028 */  lw        $a3, 0x28($s1)
/* B9E1D8 80240878 0C01242D */  jal       func_800490B4
/* B9E1DC 8024087C 0240282D */   daddu    $a1, $s2, $zero
/* B9E1E0 80240880 10400025 */  beqz      $v0, .L80240918
/* B9E1E4 80240884 0000202D */   daddu    $a0, $zero, $zero
/* B9E1E8 80240888 0200282D */  daddu     $a1, $s0, $zero
/* B9E1EC 8024088C 0000302D */  daddu     $a2, $zero, $zero
/* B9E1F0 80240890 860300A8 */  lh        $v1, 0xa8($s0)
/* B9E1F4 80240894 3C013F80 */  lui       $at, 0x3f80
/* B9E1F8 80240898 44810000 */  mtc1      $at, $f0
/* B9E1FC 8024089C 3C014000 */  lui       $at, 0x4000
/* B9E200 802408A0 44811000 */  mtc1      $at, $f2
/* B9E204 802408A4 3C01C1A0 */  lui       $at, 0xc1a0
/* B9E208 802408A8 44812000 */  mtc1      $at, $f4
/* B9E20C 802408AC 2402000F */  addiu     $v0, $zero, 0xf
/* B9E210 802408B0 AFA2001C */  sw        $v0, 0x1c($sp)
/* B9E214 802408B4 44833000 */  mtc1      $v1, $f6
/* B9E218 802408B8 00000000 */  nop
/* B9E21C 802408BC 468031A0 */  cvt.s.w   $f6, $f6
/* B9E220 802408C0 44073000 */  mfc1      $a3, $f6
/* B9E224 802408C4 27A20028 */  addiu     $v0, $sp, 0x28
/* B9E228 802408C8 AFA20020 */  sw        $v0, 0x20($sp)
/* B9E22C 802408CC E7A00010 */  swc1      $f0, 0x10($sp)
/* B9E230 802408D0 E7A20014 */  swc1      $f2, 0x14($sp)
/* B9E234 802408D4 0C01BFA4 */  jal       fx_emote
/* B9E238 802408D8 E7A40018 */   swc1     $f4, 0x18($sp)
/* B9E23C 802408DC 0200202D */  daddu     $a0, $s0, $zero
/* B9E240 802408E0 240502F4 */  addiu     $a1, $zero, 0x2f4
/* B9E244 802408E4 0C012530 */  jal       ai_enemy_play_sound
/* B9E248 802408E8 3C060020 */   lui      $a2, 0x20
/* B9E24C 802408EC 3C02800F */  lui       $v0, %hi(gPlayerStatusPtr)
/* B9E250 802408F0 8C427B30 */  lw        $v0, %lo(gPlayerStatusPtr)($v0)
/* B9E254 802408F4 C60C0038 */  lwc1      $f12, 0x38($s0)
/* B9E258 802408F8 C60E0040 */  lwc1      $f14, 0x40($s0)
/* B9E25C 802408FC 8C460028 */  lw        $a2, 0x28($v0)
/* B9E260 80240900 0C00A720 */  jal       atan2
/* B9E264 80240904 8C470030 */   lw       $a3, 0x30($v0)
/* B9E268 80240908 2402000C */  addiu     $v0, $zero, 0xc
/* B9E26C 8024090C E600000C */  swc1      $f0, 0xc($s0)
/* B9E270 80240910 0809026B */  j         .L802409AC
/* B9E274 80240914 AE820070 */   sw       $v0, 0x70($s4)
.L80240918:
/* B9E278 80240918 8602008C */  lh        $v0, 0x8c($s0)
/* B9E27C 8024091C 14400023 */  bnez      $v0, .L802409AC
/* B9E280 80240920 00000000 */   nop
/* B9E284 80240924 9602008E */  lhu       $v0, 0x8e($s0)
/* B9E288 80240928 2442FFFF */  addiu     $v0, $v0, -1
/* B9E28C 8024092C A602008E */  sh        $v0, 0x8e($s0)
/* B9E290 80240930 00021400 */  sll       $v0, $v0, 0x10
/* B9E294 80240934 1C40001D */  bgtz      $v0, .L802409AC
/* B9E298 80240938 00000000 */   nop
/* B9E29C 8024093C 8E820074 */  lw        $v0, 0x74($s4)
/* B9E2A0 80240940 2442FFFF */  addiu     $v0, $v0, -1
/* B9E2A4 80240944 18400018 */  blez      $v0, .L802409A8
/* B9E2A8 80240948 AE820074 */   sw       $v0, 0x74($s4)
/* B9E2AC 8024094C C600000C */  lwc1      $f0, 0xc($s0)
/* B9E2B0 80240950 3C014334 */  lui       $at, 0x4334
/* B9E2B4 80240954 44816000 */  mtc1      $at, $f12
/* B9E2B8 80240958 0C00A6C9 */  jal       clamp_angle
/* B9E2BC 8024095C 460C0300 */   add.s    $f12, $f0, $f12
/* B9E2C0 80240960 240403E8 */  addiu     $a0, $zero, 0x3e8
/* B9E2C4 80240964 0C00A67F */  jal       rand_int
/* B9E2C8 80240968 E600000C */   swc1     $f0, 0xc($s0)
/* B9E2CC 8024096C 3C032E8B */  lui       $v1, 0x2e8b
/* B9E2D0 80240970 3463A2E9 */  ori       $v1, $v1, 0xa2e9
/* B9E2D4 80240974 00430018 */  mult      $v0, $v1
/* B9E2D8 80240978 00021FC3 */  sra       $v1, $v0, 0x1f
/* B9E2DC 8024097C 00004010 */  mfhi      $t0
/* B9E2E0 80240980 00082043 */  sra       $a0, $t0, 1
/* B9E2E4 80240984 00832023 */  subu      $a0, $a0, $v1
/* B9E2E8 80240988 00041840 */  sll       $v1, $a0, 1
/* B9E2EC 8024098C 00641821 */  addu      $v1, $v1, $a0
/* B9E2F0 80240990 00031880 */  sll       $v1, $v1, 2
/* B9E2F4 80240994 00641823 */  subu      $v1, $v1, $a0
/* B9E2F8 80240998 00431023 */  subu      $v0, $v0, $v1
/* B9E2FC 8024099C 24420005 */  addiu     $v0, $v0, 5
/* B9E300 802409A0 0809026B */  j         .L802409AC
/* B9E304 802409A4 A602008E */   sh       $v0, 0x8e($s0)
.L802409A8:
/* B9E308 802409A8 AE800070 */  sw        $zero, 0x70($s4)
.L802409AC:
/* B9E30C 802409AC 8FBF0044 */  lw        $ra, 0x44($sp)
/* B9E310 802409B0 8FB40040 */  lw        $s4, 0x40($sp)
/* B9E314 802409B4 8FB3003C */  lw        $s3, 0x3c($sp)
/* B9E318 802409B8 8FB20038 */  lw        $s2, 0x38($sp)
/* B9E31C 802409BC 8FB10034 */  lw        $s1, 0x34($sp)
/* B9E320 802409C0 8FB00030 */  lw        $s0, 0x30($sp)
/* B9E324 802409C4 03E00008 */  jr        $ra
/* B9E328 802409C8 27BD0048 */   addiu    $sp, $sp, 0x48

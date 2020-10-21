.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242548_DCF218
/* DCF218 80242548 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* DCF21C 8024254C AFB20038 */  sw        $s2, 0x38($sp)
/* DCF220 80242550 0080902D */  daddu     $s2, $a0, $zero
/* DCF224 80242554 AFB00030 */  sw        $s0, 0x30($sp)
/* DCF228 80242558 AFBF003C */  sw        $ra, 0x3c($sp)
/* DCF22C 8024255C AFB10034 */  sw        $s1, 0x34($sp)
/* DCF230 80242560 F7B60048 */  sdc1      $f22, 0x48($sp)
/* DCF234 80242564 F7B40040 */  sdc1      $f20, 0x40($sp)
/* DCF238 80242568 8E510148 */  lw        $s1, 0x148($s2)
/* DCF23C 8024256C 4485A000 */  mtc1      $a1, $f20
/* DCF240 80242570 86240008 */  lh        $a0, 8($s1)
/* DCF244 80242574 4486B000 */  mtc1      $a2, $f22
/* DCF248 80242578 0C00EABB */  jal       get_npc_unsafe
/* DCF24C 8024257C 00E0802D */   daddu    $s0, $a3, $zero
/* DCF250 80242580 0200202D */  daddu     $a0, $s0, $zero
/* DCF254 80242584 0220282D */  daddu     $a1, $s1, $zero
/* DCF258 80242588 24030001 */  addiu     $v1, $zero, 1
/* DCF25C 8024258C 4406A000 */  mfc1      $a2, $f20
/* DCF260 80242590 4407B000 */  mfc1      $a3, $f22
/* DCF264 80242594 0040802D */  daddu     $s0, $v0, $zero
/* DCF268 80242598 0C01242D */  jal       func_800490B4
/* DCF26C 8024259C AFA30010 */   sw       $v1, 0x10($sp)
/* DCF270 802425A0 1440001D */  bnez      $v0, .L80242618
/* DCF274 802425A4 24040002 */   addiu    $a0, $zero, 2
/* DCF278 802425A8 0200282D */  daddu     $a1, $s0, $zero
/* DCF27C 802425AC 0000302D */  daddu     $a2, $zero, $zero
/* DCF280 802425B0 860300A8 */  lh        $v1, 0xa8($s0)
/* DCF284 802425B4 3C013F80 */  lui       $at, 0x3f80
/* DCF288 802425B8 44810000 */  mtc1      $at, $f0
/* DCF28C 802425BC 3C014000 */  lui       $at, 0x4000
/* DCF290 802425C0 44811000 */  mtc1      $at, $f2
/* DCF294 802425C4 3C01C1A0 */  lui       $at, 0xc1a0
/* DCF298 802425C8 44812000 */  mtc1      $at, $f4
/* DCF29C 802425CC 2402000F */  addiu     $v0, $zero, 0xf
/* DCF2A0 802425D0 AFA2001C */  sw        $v0, 0x1c($sp)
/* DCF2A4 802425D4 44833000 */  mtc1      $v1, $f6
/* DCF2A8 802425D8 00000000 */  nop       
/* DCF2AC 802425DC 468031A0 */  cvt.s.w   $f6, $f6
/* DCF2B0 802425E0 44073000 */  mfc1      $a3, $f6
/* DCF2B4 802425E4 27A20028 */  addiu     $v0, $sp, 0x28
/* DCF2B8 802425E8 AFA20020 */  sw        $v0, 0x20($sp)
/* DCF2BC 802425EC E7A00010 */  swc1      $f0, 0x10($sp)
/* DCF2C0 802425F0 E7A20014 */  swc1      $f2, 0x14($sp)
/* DCF2C4 802425F4 0C01BFA4 */  jal       fx_emote
/* DCF2C8 802425F8 E7A40018 */   swc1     $f4, 0x18($sp)
/* DCF2CC 802425FC 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCF2D0 80242600 8C430000 */  lw        $v1, ($v0)
/* DCF2D4 80242604 24020014 */  addiu     $v0, $zero, 0x14
/* DCF2D8 80242608 A602008E */  sh        $v0, 0x8e($s0)
/* DCF2DC 8024260C 24020021 */  addiu     $v0, $zero, 0x21
/* DCF2E0 80242610 0809099A */  j         .L80242668
/* DCF2E4 80242614 AE030028 */   sw       $v1, 0x28($s0)
.L80242618:
/* DCF2E8 80242618 0C0908D6 */  jal       func_80242358_DCF028
/* DCF2EC 8024261C 0240202D */   daddu    $a0, $s2, $zero
/* DCF2F0 80242620 0040202D */  daddu     $a0, $v0, $zero
/* DCF2F4 80242624 2402FFFF */  addiu     $v0, $zero, -1
/* DCF2F8 80242628 10820010 */  beq       $a0, $v0, .L8024266C
/* DCF2FC 8024262C 00000000 */   nop      
/* DCF300 80242630 0C00FB3A */  jal       get_enemy
/* DCF304 80242634 00000000 */   nop      
/* DCF308 80242638 8C42006C */  lw        $v0, 0x6c($v0)
/* DCF30C 8024263C 1440000B */  bnez      $v0, .L8024266C
/* DCF310 80242640 00000000 */   nop      
/* DCF314 80242644 8602008C */  lh        $v0, 0x8c($s0)
/* DCF318 80242648 14400008 */  bnez      $v0, .L8024266C
/* DCF31C 8024264C 00000000 */   nop      
/* DCF320 80242650 8E2200CC */  lw        $v0, 0xcc($s1)
/* DCF324 80242654 8C420020 */  lw        $v0, 0x20($v0)
/* DCF328 80242658 AE020028 */  sw        $v0, 0x28($s0)
/* DCF32C 8024265C 96220072 */  lhu       $v0, 0x72($s1)
/* DCF330 80242660 A602008E */  sh        $v0, 0x8e($s0)
/* DCF334 80242664 2402001E */  addiu     $v0, $zero, 0x1e
.L80242668:
/* DCF338 80242668 AE420070 */  sw        $v0, 0x70($s2)
.L8024266C:
/* DCF33C 8024266C 8FBF003C */  lw        $ra, 0x3c($sp)
/* DCF340 80242670 8FB20038 */  lw        $s2, 0x38($sp)
/* DCF344 80242674 8FB10034 */  lw        $s1, 0x34($sp)
/* DCF348 80242678 8FB00030 */  lw        $s0, 0x30($sp)
/* DCF34C 8024267C D7B60048 */  ldc1      $f22, 0x48($sp)
/* DCF350 80242680 D7B40040 */  ldc1      $f20, 0x40($sp)
/* DCF354 80242684 03E00008 */  jr        $ra
/* DCF358 80242688 27BD0050 */   addiu    $sp, $sp, 0x50

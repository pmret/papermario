.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B6000_E24040
/* E24040 802B6000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E24044 802B6004 3C037FFF */  lui       $v1, 0x7fff
/* E24048 802B6008 AFB00010 */  sw        $s0, 0x10($sp)
/* E2404C 802B600C 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E24050 802B6010 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E24054 802B6014 AFBF0014 */  sw        $ra, 0x14($sp)
/* E24058 802B6018 8E020000 */  lw        $v0, ($s0)
/* E2405C 802B601C C6000028 */  lwc1      $f0, 0x28($s0)
/* E24060 802B6020 C6020030 */  lwc1      $f2, 0x30($s0)
/* E24064 802B6024 C604002C */  lwc1      $f4, 0x2c($s0)
/* E24068 802B6028 3463FFF7 */  ori       $v1, $v1, 0xfff7
/* E2406C 802B602C A20000B6 */  sb        $zero, 0xb6($s0)
/* E24070 802B6030 A60000C0 */  sh        $zero, 0xc0($s0)
/* E24074 802B6034 A60000C2 */  sh        $zero, 0xc2($s0)
/* E24078 802B6038 00431024 */  and       $v0, $v0, $v1
/* E2407C 802B603C 34420002 */  ori       $v0, $v0, 2
/* E24080 802B6040 AE020000 */  sw        $v0, ($s0)
/* E24084 802B6044 E600003C */  swc1      $f0, 0x3c($s0)
/* E24088 802B6048 E6020040 */  swc1      $f2, 0x40($s0)
/* E2408C 802B604C 0C038BD8 */  jal       phys_init_integrator_for_current_state
/* E24090 802B6050 E604004C */   swc1     $f4, 0x4c($s0)
/* E24094 802B6054 8E030004 */  lw        $v1, 4($s0)
/* E24098 802B6058 3C108016 */  lui       $s0, %hi(gCollisionStatus)
/* E2409C 802B605C 2610A550 */  addiu     $s0, $s0, %lo(gCollisionStatus)
/* E240A0 802B6060 30624000 */  andi      $v0, $v1, 0x4000
/* E240A4 802B6064 10400003 */  beqz      $v0, .L802B6074
/* E240A8 802B6068 3C040009 */   lui      $a0, 9
/* E240AC 802B606C 080AD823 */  j         .L802B608C
/* E240B0 802B6070 34840005 */   ori      $a0, $a0, 5
.L802B6074:
/* E240B4 802B6074 3C040006 */  lui       $a0, 6
/* E240B8 802B6078 30620003 */  andi      $v0, $v1, 3
/* E240BC 802B607C 14400003 */  bnez      $v0, .L802B608C
/* E240C0 802B6080 34840009 */   ori      $a0, $a0, 9
/* E240C4 802B6084 3C040001 */  lui       $a0, 1
/* E240C8 802B6088 34840007 */  ori       $a0, $a0, 7
.L802B608C:
/* E240CC 802B608C 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E240D0 802B6090 00000000 */   nop
/* E240D4 802B6094 96030002 */  lhu       $v1, 2($s0)
/* E240D8 802B6098 2402FFFF */  addiu     $v0, $zero, -1
/* E240DC 802B609C A6020002 */  sh        $v0, 2($s0)
/* E240E0 802B60A0 A6030004 */  sh        $v1, 4($s0)
/* E240E4 802B60A4 8FBF0014 */  lw        $ra, 0x14($sp)
/* E240E8 802B60A8 8FB00010 */  lw        $s0, 0x10($sp)
/* E240EC 802B60AC 03E00008 */  jr        $ra
/* E240F0 802B60B0 27BD0018 */   addiu    $sp, $sp, 0x18

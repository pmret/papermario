.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802BB000_E2D930
/* E2D930 802BB000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E2D934 802BB004 AFB10014 */  sw        $s1, 0x14($sp)
/* E2D938 802BB008 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* E2D93C 802BB00C 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* E2D940 802BB010 AFBF0018 */  sw        $ra, 0x18($sp)
/* E2D944 802BB014 AFB00010 */  sw        $s0, 0x10($sp)
/* E2D948 802BB018 90820006 */  lbu       $v0, 6($a0)
/* E2D94C 802BB01C 8C900040 */  lw        $s0, 0x40($a0)
/* E2D950 802BB020 30420001 */  andi      $v0, $v0, 1
/* E2D954 802BB024 10400019 */  beqz      $v0, .L802BB08C
/* E2D958 802BB028 00000000 */   nop      
/* E2D95C 802BB02C 0C04D07A */  jal       func_801341E8
/* E2D960 802BB030 00000000 */   nop      
/* E2D964 802BB034 14400015 */  bnez      $v0, .L802BB08C
/* E2D968 802BB038 24020021 */   addiu    $v0, $zero, 0x21
/* E2D96C 802BB03C 822300B4 */  lb        $v1, 0xb4($s1)
/* E2D970 802BB040 14620005 */  bne       $v1, $v0, .L802BB058
/* E2D974 802BB044 2402001D */   addiu    $v0, $zero, 0x1d
/* E2D978 802BB048 8E220004 */  lw        $v0, 4($s1)
/* E2D97C 802BB04C 34420004 */  ori       $v0, $v0, 4
/* E2D980 802BB050 080AEC23 */  j         .L802BB08C
/* E2D984 802BB054 AE220004 */   sw       $v0, 4($s1)
.L802BB058:
/* E2D988 802BB058 1062000C */  beq       $v1, $v0, .L802BB08C
/* E2D98C 802BB05C 00000000 */   nop      
/* E2D990 802BB060 9604002C */  lhu       $a0, 0x2c($s0)
/* E2D994 802BB064 96020028 */  lhu       $v0, 0x28($s0)
/* E2D998 802BB068 9603002A */  lhu       $v1, 0x2a($s0)
/* E2D99C 802BB06C 3C01802C */  lui       $at, %hi(D_802BCE32)
/* E2D9A0 802BB070 A424CE32 */  sh        $a0, %lo(D_802BCE32)($at)
/* E2D9A4 802BB074 3C01802C */  lui       $at, %hi(D_802BCE34)
/* E2D9A8 802BB078 A422CE34 */  sh        $v0, %lo(D_802BCE34)($at)
/* E2D9AC 802BB07C 3C01802C */  lui       $at, %hi(D_802BCE30)
/* E2D9B0 802BB080 A423CE30 */  sh        $v1, %lo(D_802BCE30)($at)
/* E2D9B4 802BB084 0C039769 */  jal       set_action_state
/* E2D9B8 802BB088 2404001D */   addiu    $a0, $zero, 0x1d
.L802BB08C:
/* E2D9BC 802BB08C 8FBF0018 */  lw        $ra, 0x18($sp)
/* E2D9C0 802BB090 8FB10014 */  lw        $s1, 0x14($sp)
/* E2D9C4 802BB094 8FB00010 */  lw        $s0, 0x10($sp)
/* E2D9C8 802BB098 03E00008 */  jr        $ra
/* E2D9CC 802BB09C 27BD0020 */   addiu    $sp, $sp, 0x20

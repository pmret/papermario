.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802438D0_9DA8F0
/* 9DA8F0 802438D0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9DA8F4 802438D4 3C048025 */  lui       $a0, %hi(D_802523B4)
/* 9DA8F8 802438D8 248423B4 */  addiu     $a0, $a0, %lo(D_802523B4)
/* 9DA8FC 802438DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9DA900 802438E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9DA904 802438E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9DA908 802438E8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9DA90C 802438EC 8C830000 */  lw        $v1, ($a0)
/* 9DA910 802438F0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 9DA914 802438F4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 9DA918 802438F8 28620003 */  slti      $v0, $v1, 3
/* 9DA91C 802438FC 50400007 */  beql      $v0, $zero, .L8024391C
/* 9DA920 80243900 24020003 */   addiu    $v0, $zero, 3
/* 9DA924 80243904 1C60000C */  bgtz      $v1, .L80243938
/* 9DA928 80243908 24620001 */   addiu    $v0, $v1, 1
/* 9DA92C 8024390C 10600007 */  beqz      $v1, .L8024392C
/* 9DA930 80243910 0000102D */   daddu    $v0, $zero, $zero
/* 9DA934 80243914 08090E6A */  j         .L802439A8
/* 9DA938 80243918 00000000 */   nop      
.L8024391C:
/* 9DA93C 8024391C 10620008 */  beq       $v1, $v0, .L80243940
/* 9DA940 80243920 0000102D */   daddu    $v0, $zero, $zero
/* 9DA944 80243924 08090E6A */  j         .L802439A8
/* 9DA948 80243928 00000000 */   nop      
.L8024392C:
/* 9DA94C 8024392C 24020001 */  addiu     $v0, $zero, 1
/* 9DA950 80243930 08090E69 */  j         .L802439A4
/* 9DA954 80243934 AC820000 */   sw       $v0, ($a0)
.L80243938:
/* 9DA958 80243938 08090E69 */  j         .L802439A4
/* 9DA95C 8024393C AC820000 */   sw       $v0, ($a0)
.L80243940:
/* 9DA960 80243940 3C108011 */  lui       $s0, %hi(D_8010C930)
/* 9DA964 80243944 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* 9DA968 80243948 0C03BD17 */  jal       clear_partner_move_history
/* 9DA96C 8024394C 8E040000 */   lw       $a0, ($s0)
/* 9DA970 80243950 C6200028 */  lwc1      $f0, 0x28($s1)
/* 9DA974 80243954 C6220030 */  lwc1      $f2, 0x30($s1)
/* 9DA978 80243958 4600010D */  trunc.w.s $f4, $f0
/* 9DA97C 8024395C 44042000 */  mfc1      $a0, $f4
/* 9DA980 80243960 4600110D */  trunc.w.s $f4, $f2
/* 9DA984 80243964 44052000 */  mfc1      $a1, $f4
/* 9DA988 80243968 0C03BCF0 */  jal       func_800EF3C0
/* 9DA98C 8024396C 00000000 */   nop      
/* 9DA990 80243970 0C03BCF5 */  jal       func_800EF3D4
/* 9DA994 80243974 0000202D */   daddu    $a0, $zero, $zero
/* 9DA998 80243978 3C0142B4 */  lui       $at, 0x42b4
/* 9DA99C 8024397C 4481A000 */  mtc1      $at, $f20
/* 9DA9A0 80243980 8E040000 */  lw        $a0, ($s0)
/* 9DA9A4 80243984 4405A000 */  mfc1      $a1, $f20
/* 9DA9A8 80243988 0C00ECD0 */  jal       set_npc_yaw
/* 9DA9AC 8024398C 00000000 */   nop      
/* 9DA9B0 80243990 24020002 */  addiu     $v0, $zero, 2
/* 9DA9B4 80243994 E6340080 */  swc1      $f20, 0x80($s1)
/* 9DA9B8 80243998 E6340084 */  swc1      $f20, 0x84($s1)
/* 9DA9BC 8024399C 08090E6A */  j         .L802439A8
/* 9DA9C0 802439A0 AE2000A8 */   sw       $zero, 0xa8($s1)
.L802439A4:
/* 9DA9C4 802439A4 0000102D */  daddu     $v0, $zero, $zero
.L802439A8:
/* 9DA9C8 802439A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9DA9CC 802439AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9DA9D0 802439B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DA9D4 802439B4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9DA9D8 802439B8 03E00008 */  jr        $ra
/* 9DA9DC 802439BC 27BD0028 */   addiu    $sp, $sp, 0x28

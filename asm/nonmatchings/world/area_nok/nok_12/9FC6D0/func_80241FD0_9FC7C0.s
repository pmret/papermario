.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241FD0_9FC7C0
/* 9FC7C0 80241FD0 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9FC7C4 80241FD4 3C048024 */  lui       $a0, %hi(D_80245A14)
/* 9FC7C8 80241FD8 24845A14 */  addiu     $a0, $a0, %lo(D_80245A14)
/* 9FC7CC 80241FDC AFBF0018 */  sw        $ra, 0x18($sp)
/* 9FC7D0 80241FE0 AFB10014 */  sw        $s1, 0x14($sp)
/* 9FC7D4 80241FE4 AFB00010 */  sw        $s0, 0x10($sp)
/* 9FC7D8 80241FE8 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9FC7DC 80241FEC 8C830000 */  lw        $v1, ($a0)
/* 9FC7E0 80241FF0 3C118011 */  lui       $s1, %hi(gPlayerStatus)
/* 9FC7E4 80241FF4 2631EFC8 */  addiu     $s1, $s1, %lo(gPlayerStatus)
/* 9FC7E8 80241FF8 28620003 */  slti      $v0, $v1, 3
/* 9FC7EC 80241FFC 50400007 */  beql      $v0, $zero, .L8024201C
/* 9FC7F0 80242000 24020003 */   addiu    $v0, $zero, 3
/* 9FC7F4 80242004 1C60000C */  bgtz      $v1, .L80242038
/* 9FC7F8 80242008 24620001 */   addiu    $v0, $v1, 1
/* 9FC7FC 8024200C 10600007 */  beqz      $v1, .L8024202C
/* 9FC800 80242010 0000102D */   daddu    $v0, $zero, $zero
/* 9FC804 80242014 0809082A */  j         .L802420A8
/* 9FC808 80242018 00000000 */   nop
.L8024201C:
/* 9FC80C 8024201C 10620008 */  beq       $v1, $v0, .L80242040
/* 9FC810 80242020 0000102D */   daddu    $v0, $zero, $zero
/* 9FC814 80242024 0809082A */  j         .L802420A8
/* 9FC818 80242028 00000000 */   nop
.L8024202C:
/* 9FC81C 8024202C 24020001 */  addiu     $v0, $zero, 1
/* 9FC820 80242030 08090829 */  j         .L802420A4
/* 9FC824 80242034 AC820000 */   sw       $v0, ($a0)
.L80242038:
/* 9FC828 80242038 08090829 */  j         .L802420A4
/* 9FC82C 8024203C AC820000 */   sw       $v0, ($a0)
.L80242040:
/* 9FC830 80242040 3C108011 */  lui       $s0, %hi(D_8010C930)
/* 9FC834 80242044 2610C930 */  addiu     $s0, $s0, %lo(D_8010C930)
/* 9FC838 80242048 0C03BD17 */  jal       clear_partner_move_history
/* 9FC83C 8024204C 8E040000 */   lw       $a0, ($s0)
/* 9FC840 80242050 C6200028 */  lwc1      $f0, 0x28($s1)
/* 9FC844 80242054 C6220030 */  lwc1      $f2, 0x30($s1)
/* 9FC848 80242058 4600010D */  trunc.w.s $f4, $f0
/* 9FC84C 8024205C 44042000 */  mfc1      $a0, $f4
/* 9FC850 80242060 4600110D */  trunc.w.s $f4, $f2
/* 9FC854 80242064 44052000 */  mfc1      $a1, $f4
/* 9FC858 80242068 0C03BCF0 */  jal       func_800EF3C0
/* 9FC85C 8024206C 00000000 */   nop
/* 9FC860 80242070 0C03BCF5 */  jal       func_800EF3D4
/* 9FC864 80242074 0000202D */   daddu    $a0, $zero, $zero
/* 9FC868 80242078 3C0142B4 */  lui       $at, 0x42b4
/* 9FC86C 8024207C 4481A000 */  mtc1      $at, $f20
/* 9FC870 80242080 8E040000 */  lw        $a0, ($s0)
/* 9FC874 80242084 4405A000 */  mfc1      $a1, $f20
/* 9FC878 80242088 0C00ECD0 */  jal       set_npc_yaw
/* 9FC87C 8024208C 00000000 */   nop
/* 9FC880 80242090 24020002 */  addiu     $v0, $zero, 2
/* 9FC884 80242094 E6340080 */  swc1      $f20, 0x80($s1)
/* 9FC888 80242098 E6340084 */  swc1      $f20, 0x84($s1)
/* 9FC88C 8024209C 0809082A */  j         .L802420A8
/* 9FC890 802420A0 AE2000A8 */   sw       $zero, 0xa8($s1)
.L802420A4:
/* 9FC894 802420A4 0000102D */  daddu     $v0, $zero, $zero
.L802420A8:
/* 9FC898 802420A8 8FBF0018 */  lw        $ra, 0x18($sp)
/* 9FC89C 802420AC 8FB10014 */  lw        $s1, 0x14($sp)
/* 9FC8A0 802420B0 8FB00010 */  lw        $s0, 0x10($sp)
/* 9FC8A4 802420B4 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9FC8A8 802420B8 03E00008 */  jr        $ra
/* 9FC8AC 802420BC 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_8029D7F0
.word L8026FAC8_19E3A8, L8026FAD4_19E3B4, L8026FAE0_19E3C0, L8026FAE8_19E3C8, L8026FAF0_19E3D0, L8026FAF8_19E3D8

.section .text

glabel SetPartSounds
/* 19E2E0 8026FA00 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19E2E4 8026FA04 AFB20018 */  sw        $s2, 0x18($sp)
/* 19E2E8 8026FA08 0080902D */  daddu     $s2, $a0, $zero
/* 19E2EC 8026FA0C AFBF0024 */  sw        $ra, 0x24($sp)
/* 19E2F0 8026FA10 AFB40020 */  sw        $s4, 0x20($sp)
/* 19E2F4 8026FA14 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19E2F8 8026FA18 AFB10014 */  sw        $s1, 0x14($sp)
/* 19E2FC 8026FA1C AFB00010 */  sw        $s0, 0x10($sp)
/* 19E300 8026FA20 8E51000C */  lw        $s1, 0xc($s2)
/* 19E304 8026FA24 8E250000 */  lw        $a1, ($s1)
/* 19E308 8026FA28 0C0B1EAF */  jal       get_variable
/* 19E30C 8026FA2C 26310004 */   addiu    $s1, $s1, 4
/* 19E310 8026FA30 0040982D */  daddu     $s3, $v0, $zero
/* 19E314 8026FA34 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 19E318 8026FA38 16620002 */  bne       $s3, $v0, .L8026FA44
/* 19E31C 8026FA3C 00000000 */   nop
/* 19E320 8026FA40 8E530148 */  lw        $s3, 0x148($s2)
.L8026FA44:
/* 19E324 8026FA44 8E250000 */  lw        $a1, ($s1)
/* 19E328 8026FA48 26310004 */  addiu     $s1, $s1, 4
/* 19E32C 8026FA4C 0C0B1EAF */  jal       get_variable
/* 19E330 8026FA50 0240202D */   daddu    $a0, $s2, $zero
/* 19E334 8026FA54 8E250000 */  lw        $a1, ($s1)
/* 19E338 8026FA58 26310004 */  addiu     $s1, $s1, 4
/* 19E33C 8026FA5C 0240202D */  daddu     $a0, $s2, $zero
/* 19E340 8026FA60 0C0B1EAF */  jal       get_variable
/* 19E344 8026FA64 0040802D */   daddu    $s0, $v0, $zero
/* 19E348 8026FA68 8E250000 */  lw        $a1, ($s1)
/* 19E34C 8026FA6C 26310004 */  addiu     $s1, $s1, 4
/* 19E350 8026FA70 0240202D */  daddu     $a0, $s2, $zero
/* 19E354 8026FA74 0C0B1EAF */  jal       get_variable
/* 19E358 8026FA78 0040A02D */   daddu    $s4, $v0, $zero
/* 19E35C 8026FA7C 0240202D */  daddu     $a0, $s2, $zero
/* 19E360 8026FA80 8E250000 */  lw        $a1, ($s1)
/* 19E364 8026FA84 0C0B1EAF */  jal       get_variable
/* 19E368 8026FA88 0040882D */   daddu    $s1, $v0, $zero
/* 19E36C 8026FA8C 0260202D */  daddu     $a0, $s3, $zero
/* 19E370 8026FA90 0C09A75B */  jal       get_actor
/* 19E374 8026FA94 0040902D */   daddu    $s2, $v0, $zero
/* 19E378 8026FA98 0040202D */  daddu     $a0, $v0, $zero
/* 19E37C 8026FA9C 0C099117 */  jal       get_actor_part
/* 19E380 8026FAA0 0200282D */   daddu    $a1, $s0, $zero
/* 19E384 8026FAA4 0040182D */  daddu     $v1, $v0, $zero
/* 19E388 8026FAA8 2E820006 */  sltiu     $v0, $s4, 6
/* 19E38C 8026FAAC 10400013 */  beqz      $v0, .L8026FAFC
/* 19E390 8026FAB0 00141080 */   sll      $v0, $s4, 2
/* 19E394 8026FAB4 3C01802A */  lui       $at, %hi(jtbl_8029D7F0)
/* 19E398 8026FAB8 00220821 */  addu      $at, $at, $v0
/* 19E39C 8026FABC 8C22D7F0 */  lw        $v0, %lo(jtbl_8029D7F0)($at)
/* 19E3A0 8026FAC0 00400008 */  jr        $v0
/* 19E3A4 8026FAC4 00000000 */   nop
glabel L8026FAC8_19E3A8
/* 19E3A8 8026FAC8 AC7100A4 */  sw        $s1, 0xa4($v1)
/* 19E3AC 8026FACC 0809BEBF */  j         .L8026FAFC
/* 19E3B0 8026FAD0 AC7200A8 */   sw       $s2, 0xa8($v1)
glabel L8026FAD4_19E3B4
/* 19E3B4 8026FAD4 AC7100AC */  sw        $s1, 0xac($v1)
/* 19E3B8 8026FAD8 0809BEBF */  j         .L8026FAFC
/* 19E3BC 8026FADC AC7200B0 */   sw       $s2, 0xb0($v1)
glabel L8026FAE0_19E3C0
/* 19E3C0 8026FAE0 0809BEBF */  j         .L8026FAFC
/* 19E3C4 8026FAE4 AC7100B4 */   sw       $s1, 0xb4($v1)
glabel L8026FAE8_19E3C8
/* 19E3C8 8026FAE8 0809BEBF */  j         .L8026FAFC
/* 19E3CC 8026FAEC AC7100B8 */   sw       $s1, 0xb8($v1)
glabel L8026FAF0_19E3D0
/* 19E3D0 8026FAF0 0809BEBF */  j         .L8026FAFC
/* 19E3D4 8026FAF4 A47100BC */   sh       $s1, 0xbc($v1)
glabel L8026FAF8_19E3D8
/* 19E3D8 8026FAF8 A47100BE */  sh        $s1, 0xbe($v1)
.L8026FAFC:
/* 19E3DC 8026FAFC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 19E3E0 8026FB00 8FB40020 */  lw        $s4, 0x20($sp)
/* 19E3E4 8026FB04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 19E3E8 8026FB08 8FB20018 */  lw        $s2, 0x18($sp)
/* 19E3EC 8026FB0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 19E3F0 8026FB10 8FB00010 */  lw        $s0, 0x10($sp)
/* 19E3F4 8026FB14 24020002 */  addiu     $v0, $zero, 2
/* 19E3F8 8026FB18 03E00008 */  jr        $ra
/* 19E3FC 8026FB1C 27BD0028 */   addiu    $sp, $sp, 0x28

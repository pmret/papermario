.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel bind_npc_aux
/* 19F50 8003EB50 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 19F54 8003EB54 AFB3001C */  sw        $s3, 0x1c($sp)
/* 19F58 8003EB58 0080982D */  daddu     $s3, $a0, $zero
/* 19F5C 8003EB5C AFB40020 */  sw        $s4, 0x20($sp)
/* 19F60 8003EB60 00A0A02D */  daddu     $s4, $a1, $zero
/* 19F64 8003EB64 AFB20018 */  sw        $s2, 0x18($sp)
/* 19F68 8003EB68 3C12800B */  lui       $s2, %hi(gCurrentEncounter)
/* 19F6C 8003EB6C 26520F10 */  addiu     $s2, $s2, %lo(gCurrentEncounter)
/* 19F70 8003EB70 AFBF0024 */  sw        $ra, 0x24($sp)
/* 19F74 8003EB74 AFB10014 */  sw        $s1, 0x14($sp)
/* 19F78 8003EB78 AFB00010 */  sw        $s0, 0x10($sp)
/* 19F7C 8003EB7C 8242001C */  lb        $v0, 0x1c($s2)
/* 19F80 8003EB80 1840001E */  blez      $v0, .L8003EBFC
/* 19F84 8003EB84 0000802D */   daddu    $s0, $zero, $zero
/* 19F88 8003EB88 0240882D */  daddu     $s1, $s2, $zero
.L8003EB8C:
/* 19F8C 8003EB8C 8E260028 */  lw        $a2, 0x28($s1)
/* 19F90 8003EB90 50C00015 */  beql      $a2, $zero, .L8003EBE8
/* 19F94 8003EB94 26310004 */   addiu    $s1, $s1, 4
/* 19F98 8003EB98 8CC20000 */  lw        $v0, ($a2)
/* 19F9C 8003EB9C 18400011 */  blez      $v0, .L8003EBE4
/* 19FA0 8003EBA0 0000282D */   daddu    $a1, $zero, $zero
/* 19FA4 8003EBA4 00C0182D */  daddu     $v1, $a2, $zero
.L8003EBA8:
/* 19FA8 8003EBA8 8C640004 */  lw        $a0, 4($v1)
/* 19FAC 8003EBAC 10800008 */  beqz      $a0, .L8003EBD0
/* 19FB0 8003EBB0 00000000 */   nop
/* 19FB4 8003EBB4 84820008 */  lh        $v0, 8($a0)
/* 19FB8 8003EBB8 14530005 */  bne       $v0, $s3, .L8003EBD0
/* 19FBC 8003EBBC 00000000 */   nop
/* 19FC0 8003EBC0 0C00FA6D */  jal       bind_enemy_aux
/* 19FC4 8003EBC4 0280282D */   daddu    $a1, $s4, $zero
/* 19FC8 8003EBC8 0800FAFA */  j         .L8003EBE8
/* 19FCC 8003EBCC 26310004 */   addiu    $s1, $s1, 4
.L8003EBD0:
/* 19FD0 8003EBD0 8CC20000 */  lw        $v0, ($a2)
/* 19FD4 8003EBD4 24A50001 */  addiu     $a1, $a1, 1
/* 19FD8 8003EBD8 00A2102A */  slt       $v0, $a1, $v0
/* 19FDC 8003EBDC 1440FFF2 */  bnez      $v0, .L8003EBA8
/* 19FE0 8003EBE0 24630004 */   addiu    $v1, $v1, 4
.L8003EBE4:
/* 19FE4 8003EBE4 26310004 */  addiu     $s1, $s1, 4
.L8003EBE8:
/* 19FE8 8003EBE8 8242001C */  lb        $v0, 0x1c($s2)
/* 19FEC 8003EBEC 26100001 */  addiu     $s0, $s0, 1
/* 19FF0 8003EBF0 0202102A */  slt       $v0, $s0, $v0
/* 19FF4 8003EBF4 1440FFE5 */  bnez      $v0, .L8003EB8C
/* 19FF8 8003EBF8 00000000 */   nop
.L8003EBFC:
/* 19FFC 8003EBFC 8FBF0024 */  lw        $ra, 0x24($sp)
/* 1A000 8003EC00 8FB40020 */  lw        $s4, 0x20($sp)
/* 1A004 8003EC04 8FB3001C */  lw        $s3, 0x1c($sp)
/* 1A008 8003EC08 8FB20018 */  lw        $s2, 0x18($sp)
/* 1A00C 8003EC0C 8FB10014 */  lw        $s1, 0x14($sp)
/* 1A010 8003EC10 8FB00010 */  lw        $s0, 0x10($sp)
/* 1A014 8003EC14 03E00008 */  jr        $ra
/* 1A018 8003EC18 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218D6C_58D05C
/* 58D05C 80218D6C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 58D060 80218D70 AFB3001C */  sw        $s3, 0x1c($sp)
/* 58D064 80218D74 0080982D */  daddu     $s3, $a0, $zero
/* 58D068 80218D78 AFBF0020 */  sw        $ra, 0x20($sp)
/* 58D06C 80218D7C AFB20018 */  sw        $s2, 0x18($sp)
/* 58D070 80218D80 AFB10014 */  sw        $s1, 0x14($sp)
/* 58D074 80218D84 AFB00010 */  sw        $s0, 0x10($sp)
/* 58D078 80218D88 8E70000C */  lw        $s0, 0xc($s3)
/* 58D07C 80218D8C 8E050000 */  lw        $a1, ($s0)
/* 58D080 80218D90 0C0B1EAF */  jal       get_variable
/* 58D084 80218D94 26100004 */   addiu    $s0, $s0, 4
/* 58D088 80218D98 0040882D */  daddu     $s1, $v0, $zero
/* 58D08C 80218D9C 8E050000 */  lw        $a1, ($s0)
/* 58D090 80218DA0 26100004 */  addiu     $s0, $s0, 4
/* 58D094 80218DA4 0C0B1EAF */  jal       get_variable
/* 58D098 80218DA8 0260202D */   daddu    $a0, $s3, $zero
/* 58D09C 80218DAC 0040902D */  daddu     $s2, $v0, $zero
/* 58D0A0 80218DB0 2402FF81 */  addiu     $v0, $zero, -0x7f
/* 58D0A4 80218DB4 16220002 */  bne       $s1, $v0, .L80218DC0
/* 58D0A8 80218DB8 00000000 */   nop      
/* 58D0AC 80218DBC 8E710148 */  lw        $s1, 0x148($s3)
.L80218DC0:
/* 58D0B0 80218DC0 0C09A75B */  jal       get_actor
/* 58D0B4 80218DC4 0220202D */   daddu    $a0, $s1, $zero
/* 58D0B8 80218DC8 0040202D */  daddu     $a0, $v0, $zero
/* 58D0BC 80218DCC 0C099117 */  jal       get_actor_part
/* 58D0C0 80218DD0 0240282D */   daddu    $a1, $s2, $zero
/* 58D0C4 80218DD4 8C440078 */  lw        $a0, 0x78($v0)
/* 58D0C8 80218DD8 0C099791 */  jal       lookup_defense
/* 58D0CC 80218DDC 24050001 */   addiu    $a1, $zero, 1
/* 58D0D0 80218DE0 0260202D */  daddu     $a0, $s3, $zero
/* 58D0D4 80218DE4 8E050000 */  lw        $a1, ($s0)
/* 58D0D8 80218DE8 0C0B2026 */  jal       set_variable
/* 58D0DC 80218DEC 0040302D */   daddu    $a2, $v0, $zero
/* 58D0E0 80218DF0 8FBF0020 */  lw        $ra, 0x20($sp)
/* 58D0E4 80218DF4 8FB3001C */  lw        $s3, 0x1c($sp)
/* 58D0E8 80218DF8 8FB20018 */  lw        $s2, 0x18($sp)
/* 58D0EC 80218DFC 8FB10014 */  lw        $s1, 0x14($sp)
/* 58D0F0 80218E00 8FB00010 */  lw        $s0, 0x10($sp)
/* 58D0F4 80218E04 24020002 */  addiu     $v0, $zero, 2
/* 58D0F8 80218E08 03E00008 */  jr        $ra
/* 58D0FC 80218E0C 27BD0028 */   addiu    $sp, $sp, 0x28

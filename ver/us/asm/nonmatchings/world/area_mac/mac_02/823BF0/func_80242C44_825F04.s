.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C44_825F04
/* 825F04 80242C44 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 825F08 80242C48 AFB10014 */  sw        $s1, 0x14($sp)
/* 825F0C 80242C4C 0080882D */  daddu     $s1, $a0, $zero
/* 825F10 80242C50 AFBF0020 */  sw        $ra, 0x20($sp)
/* 825F14 80242C54 AFB3001C */  sw        $s3, 0x1c($sp)
/* 825F18 80242C58 AFB20018 */  sw        $s2, 0x18($sp)
/* 825F1C 80242C5C AFB00010 */  sw        $s0, 0x10($sp)
/* 825F20 80242C60 8E30000C */  lw        $s0, 0xc($s1)
/* 825F24 80242C64 8E120000 */  lw        $s2, ($s0)
/* 825F28 80242C68 26100004 */  addiu     $s0, $s0, 4
/* 825F2C 80242C6C 8E130000 */  lw        $s3, ($s0)
/* 825F30 80242C70 26100004 */  addiu     $s0, $s0, 4
/* 825F34 80242C74 8E050000 */  lw        $a1, ($s0)
/* 825F38 80242C78 0C0B1EAF */  jal       evt_get_variable
/* 825F3C 80242C7C 26100004 */   addiu    $s0, $s0, 4
/* 825F40 80242C80 0220202D */  daddu     $a0, $s1, $zero
/* 825F44 80242C84 8E050000 */  lw        $a1, ($s0)
/* 825F48 80242C88 0C0B1EAF */  jal       evt_get_variable
/* 825F4C 80242C8C 0040802D */   daddu    $s0, $v0, $zero
/* 825F50 80242C90 0040282D */  daddu     $a1, $v0, $zero
/* 825F54 80242C94 24020096 */  addiu     $v0, $zero, 0x96
/* 825F58 80242C98 1602001E */  bne       $s0, $v0, .L80242D14
/* 825F5C 80242C9C 0000202D */   daddu    $a0, $zero, $zero
/* 825F60 80242CA0 0C00A67F */  jal       rand_int
/* 825F64 80242CA4 240403E8 */   addiu    $a0, $zero, 0x3e8
/* 825F68 80242CA8 284201F4 */  slti      $v0, $v0, 0x1f4
/* 825F6C 80242CAC 10400003 */  beqz      $v0, .L80242CBC
/* 825F70 80242CB0 0000802D */   daddu    $s0, $zero, $zero
/* 825F74 80242CB4 08090B60 */  j         .L80242D80
/* 825F78 80242CB8 240600C2 */   addiu    $a2, $zero, 0xc2
.L80242CBC:
/* 825F7C 80242CBC 0C00A67F */  jal       rand_int
/* 825F80 80242CC0 24042710 */   addiu    $a0, $zero, 0x2710
/* 825F84 80242CC4 3C03B216 */  lui       $v1, 0xb216
/* 825F88 80242CC8 346342C9 */  ori       $v1, $v1, 0x42c9
/* 825F8C 80242CCC 00430018 */  mult      $v0, $v1
/* 825F90 80242CD0 24100004 */  addiu     $s0, $zero, 4
/* 825F94 80242CD4 000227C3 */  sra       $a0, $v0, 0x1f
/* 825F98 80242CD8 00003810 */  mfhi      $a3
/* 825F9C 80242CDC 00E21821 */  addu      $v1, $a3, $v0
/* 825FA0 80242CE0 02031807 */  srav      $v1, $v1, $s0
/* 825FA4 80242CE4 00642023 */  subu      $a0, $v1, $a0
/* 825FA8 80242CE8 00041840 */  sll       $v1, $a0, 1
/* 825FAC 80242CEC 00641821 */  addu      $v1, $v1, $a0
/* 825FB0 80242CF0 000318C0 */  sll       $v1, $v1, 3
/* 825FB4 80242CF4 00641823 */  subu      $v1, $v1, $a0
/* 825FB8 80242CF8 00432023 */  subu      $a0, $v0, $v1
/* 825FBC 80242CFC 00041080 */  sll       $v0, $a0, 2
/* 825FC0 80242D00 3C068025 */  lui       $a2, %hi(D_8024909C_82C35C)
/* 825FC4 80242D04 00C23021 */  addu      $a2, $a2, $v0
/* 825FC8 80242D08 8CC6909C */  lw        $a2, %lo(D_8024909C_82C35C)($a2)
/* 825FCC 80242D0C 08090B61 */  j         .L80242D84
/* 825FD0 80242D10 0220202D */   daddu    $a0, $s1, $zero
.L80242D14:
/* 825FD4 80242D14 3C038025 */  lui       $v1, %hi(D_80248A98_82BD58)
/* 825FD8 80242D18 24638A98 */  addiu     $v1, $v1, %lo(D_80248A98_82BD58)
.L80242D1C:
/* 825FDC 80242D1C 8C620000 */  lw        $v0, ($v1)
/* 825FE0 80242D20 10500006 */  beq       $v0, $s0, .L80242D3C
/* 825FE4 80242D24 2882001D */   slti     $v0, $a0, 0x1d
/* 825FE8 80242D28 24840001 */  addiu     $a0, $a0, 1
/* 825FEC 80242D2C 2882001D */  slti      $v0, $a0, 0x1d
/* 825FF0 80242D30 1440FFFA */  bnez      $v0, .L80242D1C
/* 825FF4 80242D34 24630004 */   addiu    $v1, $v1, 4
/* 825FF8 80242D38 2882001D */  slti      $v0, $a0, 0x1d
.L80242D3C:
/* 825FFC 80242D3C 5040000A */  beql      $v0, $zero, .L80242D68
/* 826000 80242D40 0000202D */   daddu    $a0, $zero, $zero
/* 826004 80242D44 10A00005 */  beqz      $a1, .L80242D5C
/* 826008 80242D48 00000000 */   nop
/* 82600C 80242D4C 3C018025 */  lui       $at, %hi(D_80248CD0_82BF90)
/* 826010 80242D50 00240821 */  addu      $at, $at, $a0
/* 826014 80242D54 08090B5A */  j         .L80242D68
/* 826018 80242D58 80248CD0 */   lb       $a0, %lo(D_80248CD0_82BF90)($at)
.L80242D5C:
/* 82601C 80242D5C 3C018025 */  lui       $at, %hi(D_80248CB0_82BF70)
/* 826020 80242D60 00240821 */  addu      $at, $at, $a0
/* 826024 80242D64 80248CB0 */  lb        $a0, %lo(D_80248CB0_82BF70)($at)
.L80242D68:
/* 826028 80242D68 3C038025 */  lui       $v1, %hi(D_80248B10_82BDD0)
/* 82602C 80242D6C 24638B10 */  addiu     $v1, $v1, %lo(D_80248B10_82BDD0)
/* 826030 80242D70 000410C0 */  sll       $v0, $a0, 3
/* 826034 80242D74 00431021 */  addu      $v0, $v0, $v1
/* 826038 80242D78 8C500000 */  lw        $s0, ($v0)
/* 82603C 80242D7C 8C460004 */  lw        $a2, 4($v0)
.L80242D80:
/* 826040 80242D80 0220202D */  daddu     $a0, $s1, $zero
.L80242D84:
/* 826044 80242D84 0C0B2026 */  jal       evt_set_variable
/* 826048 80242D88 0240282D */   daddu    $a1, $s2, $zero
/* 82604C 80242D8C 0220202D */  daddu     $a0, $s1, $zero
/* 826050 80242D90 0260282D */  daddu     $a1, $s3, $zero
/* 826054 80242D94 0C0B2026 */  jal       evt_set_variable
/* 826058 80242D98 0200302D */   daddu    $a2, $s0, $zero
/* 82605C 80242D9C 8FBF0020 */  lw        $ra, 0x20($sp)
/* 826060 80242DA0 8FB3001C */  lw        $s3, 0x1c($sp)
/* 826064 80242DA4 8FB20018 */  lw        $s2, 0x18($sp)
/* 826068 80242DA8 8FB10014 */  lw        $s1, 0x14($sp)
/* 82606C 80242DAC 8FB00010 */  lw        $s0, 0x10($sp)
/* 826070 80242DB0 24020002 */  addiu     $v0, $zero, 2
/* 826074 80242DB4 03E00008 */  jr        $ra
/* 826078 80242DB8 27BD0028 */   addiu    $sp, $sp, 0x28

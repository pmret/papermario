.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8021CCFC_6A3EFC
/* 6A3EFC 8021CCFC 27BDFFC0 */  addiu     $sp, $sp, -0x40
/* 6A3F00 8021CD00 AFB3002C */  sw        $s3, 0x2c($sp)
/* 6A3F04 8021CD04 0080982D */  daddu     $s3, $a0, $zero
/* 6A3F08 8021CD08 AFB00020 */  sw        $s0, 0x20($sp)
/* 6A3F0C 8021CD0C 0000802D */  daddu     $s0, $zero, $zero
/* 6A3F10 8021CD10 AFB20028 */  sw        $s2, 0x28($sp)
/* 6A3F14 8021CD14 3C12800E */  lui       $s2, %hi(gBattleStatus)
/* 6A3F18 8021CD18 2652C070 */  addiu     $s2, $s2, %lo(gBattleStatus)
/* 6A3F1C 8021CD1C AFB40030 */  sw        $s4, 0x30($sp)
/* 6A3F20 8021CD20 3C148011 */  lui       $s4, %hi(gPlayerData)
/* 6A3F24 8021CD24 2694F290 */  addiu     $s4, $s4, %lo(gPlayerData)
/* 6A3F28 8021CD28 AFB50034 */  sw        $s5, 0x34($sp)
/* 6A3F2C 8021CD2C 2404FFFF */  addiu     $a0, $zero, -1
/* 6A3F30 8021CD30 AFBF0038 */  sw        $ra, 0x38($sp)
/* 6A3F34 8021CD34 AFB10024 */  sw        $s1, 0x24($sp)
/* 6A3F38 8021CD38 824200AE */  lb        $v0, 0xae($s2)
/* 6A3F3C 8021CD3C 8E71000C */  lw        $s1, 0xc($s3)
/* 6A3F40 8021CD40 14440003 */  bne       $v0, $a0, .L8021CD50
/* 6A3F44 8021CD44 0280A82D */   daddu    $s5, $s4, $zero
/* 6A3F48 8021CD48 AFA00010 */  sw        $zero, 0x10($sp)
/* 6A3F4C 8021CD4C 24100001 */  addiu     $s0, $zero, 1
.L8021CD50:
/* 6A3F50 8021CD50 824200AF */  lb        $v0, 0xaf($s2)
/* 6A3F54 8021CD54 14440005 */  bne       $v0, $a0, .L8021CD6C
/* 6A3F58 8021CD58 00101080 */   sll      $v0, $s0, 2
/* 6A3F5C 8021CD5C 03A21821 */  addu      $v1, $sp, $v0
/* 6A3F60 8021CD60 24020001 */  addiu     $v0, $zero, 1
/* 6A3F64 8021CD64 AC620010 */  sw        $v0, 0x10($v1)
/* 6A3F68 8021CD68 02028021 */  addu      $s0, $s0, $v0
.L8021CD6C:
/* 6A3F6C 8021CD6C 824200B0 */  lb        $v0, 0xb0($s2)
/* 6A3F70 8021CD70 14440005 */  bne       $v0, $a0, .L8021CD88
/* 6A3F74 8021CD74 00101080 */   sll      $v0, $s0, 2
/* 6A3F78 8021CD78 03A21821 */  addu      $v1, $sp, $v0
/* 6A3F7C 8021CD7C 24020002 */  addiu     $v0, $zero, 2
/* 6A3F80 8021CD80 AC620010 */  sw        $v0, 0x10($v1)
/* 6A3F84 8021CD84 26100001 */  addiu     $s0, $s0, 1
.L8021CD88:
/* 6A3F88 8021CD88 0C00A67F */  jal       rand_int
/* 6A3F8C 8021CD8C 24040002 */   addiu    $a0, $zero, 2
/* 6A3F90 8021CD90 2604FFFF */  addiu     $a0, $s0, -1
/* 6A3F94 8021CD94 0C00A67F */  jal       rand_int
/* 6A3F98 8021CD98 24500002 */   addiu    $s0, $v0, 2
/* 6A3F9C 8021CD9C 00021080 */  sll       $v0, $v0, 2
/* 6A3FA0 8021CDA0 03A21021 */  addu      $v0, $sp, $v0
/* 6A3FA4 8021CDA4 8C430010 */  lw        $v1, 0x10($v0)
/* 6A3FA8 8021CDA8 24020001 */  addiu     $v0, $zero, 1
/* 6A3FAC 8021CDAC 1062001C */  beq       $v1, $v0, .L8021CE20
/* 6A3FB0 8021CDB0 28620002 */   slti     $v0, $v1, 2
/* 6A3FB4 8021CDB4 10400005 */  beqz      $v0, .L8021CDCC
/* 6A3FB8 8021CDB8 24020002 */   addiu    $v0, $zero, 2
/* 6A3FBC 8021CDBC 50600007 */  beql      $v1, $zero, .L8021CDDC
/* 6A3FC0 8021CDC0 A25000AE */   sb       $s0, 0xae($s2)
/* 6A3FC4 8021CDC4 080873A4 */  j         .L8021CE90
/* 6A3FC8 8021CDC8 00000000 */   nop      
.L8021CDCC:
/* 6A3FCC 8021CDCC 50620026 */  beql      $v1, $v0, .L8021CE68
/* 6A3FD0 8021CDD0 A25000B0 */   sb       $s0, 0xb0($s2)
/* 6A3FD4 8021CDD4 080873A4 */  j         .L8021CE90
/* 6A3FD8 8021CDD8 00000000 */   nop      
.L8021CDDC:
/* 6A3FDC 8021CDDC 8E250000 */  lw        $a1, ($s1)
/* 6A3FE0 8021CDE0 82820001 */  lb        $v0, 1($s4)
/* 6A3FE4 8021CDE4 26310004 */  addiu     $s1, $s1, 4
/* 6A3FE8 8021CDE8 00021080 */  sll       $v0, $v0, 2
/* 6A3FEC 8021CDEC 3C068023 */  lui       $a2, %hi(D_80230B28)
/* 6A3FF0 8021CDF0 00C23021 */  addu      $a2, $a2, $v0
/* 6A3FF4 8021CDF4 8CC60B28 */  lw        $a2, %lo(D_80230B28)($a2)
/* 6A3FF8 8021CDF8 0C0B2026 */  jal       set_variable
/* 6A3FFC 8021CDFC 0260202D */   daddu    $a0, $s3, $zero
/* 6A4000 8021CE00 82820001 */  lb        $v0, 1($s4)
/* 6A4004 8021CE04 8E250000 */  lw        $a1, ($s1)
/* 6A4008 8021CE08 00021080 */  sll       $v0, $v0, 2
/* 6A400C 8021CE0C 3C068023 */  lui       $a2, %hi(D_80230B34)
/* 6A4010 8021CE10 00C23021 */  addu      $a2, $a2, $v0
/* 6A4014 8021CE14 8CC60B34 */  lw        $a2, %lo(D_80230B34)($a2)
/* 6A4018 8021CE18 080873A2 */  j         .L8021CE88
/* 6A401C 8021CE1C 0260202D */   daddu    $a0, $s3, $zero
.L8021CE20:
/* 6A4020 8021CE20 A25000AF */  sb        $s0, 0xaf($s2)
/* 6A4024 8021CE24 8E250000 */  lw        $a1, ($s1)
/* 6A4028 8021CE28 82A20000 */  lb        $v0, ($s5)
/* 6A402C 8021CE2C 26310004 */  addiu     $s1, $s1, 4
/* 6A4030 8021CE30 00021080 */  sll       $v0, $v0, 2
/* 6A4034 8021CE34 3C068023 */  lui       $a2, %hi(D_80230B40)
/* 6A4038 8021CE38 00C23021 */  addu      $a2, $a2, $v0
/* 6A403C 8021CE3C 8CC60B40 */  lw        $a2, %lo(D_80230B40)($a2)
/* 6A4040 8021CE40 0C0B2026 */  jal       set_variable
/* 6A4044 8021CE44 0260202D */   daddu    $a0, $s3, $zero
/* 6A4048 8021CE48 82A20000 */  lb        $v0, ($s5)
/* 6A404C 8021CE4C 8E250000 */  lw        $a1, ($s1)
/* 6A4050 8021CE50 00021080 */  sll       $v0, $v0, 2
/* 6A4054 8021CE54 3C068023 */  lui       $a2, %hi(D_80230B4C)
/* 6A4058 8021CE58 00C23021 */  addu      $a2, $a2, $v0
/* 6A405C 8021CE5C 8CC60B4C */  lw        $a2, %lo(D_80230B4C)($a2)
/* 6A4060 8021CE60 080873A2 */  j         .L8021CE88
/* 6A4064 8021CE64 0260202D */   daddu    $a0, $s3, $zero
.L8021CE68:
/* 6A4068 8021CE68 8E250000 */  lw        $a1, ($s1)
/* 6A406C 8021CE6C 26310004 */  addiu     $s1, $s1, 4
/* 6A4070 8021CE70 0260202D */  daddu     $a0, $s3, $zero
/* 6A4074 8021CE74 0C0B2026 */  jal       set_variable
/* 6A4078 8021CE78 2406016C */   addiu    $a2, $zero, 0x16c
/* 6A407C 8021CE7C 0260202D */  daddu     $a0, $s3, $zero
/* 6A4080 8021CE80 8E250000 */  lw        $a1, ($s1)
/* 6A4084 8021CE84 2406004F */  addiu     $a2, $zero, 0x4f
.L8021CE88:
/* 6A4088 8021CE88 0C0B2026 */  jal       set_variable
/* 6A408C 8021CE8C 00000000 */   nop      
.L8021CE90:
/* 6A4090 8021CE90 8FBF0038 */  lw        $ra, 0x38($sp)
/* 6A4094 8021CE94 8FB50034 */  lw        $s5, 0x34($sp)
/* 6A4098 8021CE98 8FB40030 */  lw        $s4, 0x30($sp)
/* 6A409C 8021CE9C 8FB3002C */  lw        $s3, 0x2c($sp)
/* 6A40A0 8021CEA0 8FB20028 */  lw        $s2, 0x28($sp)
/* 6A40A4 8021CEA4 8FB10024 */  lw        $s1, 0x24($sp)
/* 6A40A8 8021CEA8 8FB00020 */  lw        $s0, 0x20($sp)
/* 6A40AC 8021CEAC 24020002 */  addiu     $v0, $zero, 2
/* 6A40B0 8021CEB0 03E00008 */  jr        $ra
/* 6A40B4 8021CEB4 27BD0040 */   addiu    $sp, $sp, 0x40

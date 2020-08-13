.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel add_part_decoration
/* 1959F4 80267114 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 1959F8 80267118 AFB10014 */  sw    $s1, 0x14($sp)
/* 1959FC 8026711C 0080882D */  daddu $s1, $a0, $zero
/* 195A00 80267120 AFB20018 */  sw    $s2, 0x18($sp)
/* 195A04 80267124 00A0902D */  daddu $s2, $a1, $zero
/* 195A08 80267128 AFBF0020 */  sw    $ra, 0x20($sp)
/* 195A0C 8026712C AFB3001C */  sw    $s3, 0x1c($sp)
/* 195A10 80267130 AFB00010 */  sw    $s0, 0x10($sp)
/* 195A14 80267134 8E220094 */  lw    $v0, 0x94($s1)
/* 195A18 80267138 1040000E */  beqz  $v0, .L80267174
/* 195A1C 8026713C 00C0982D */   daddu $s3, $a2, $zero
/* 195A20 80267140 8E220000 */  lw    $v0, ($s1)
/* 195A24 80267144 30420002 */  andi  $v0, $v0, 2
/* 195A28 80267148 1440000A */  bnez  $v0, .L80267174
/* 195A2C 8026714C 00000000 */   nop   
/* 195A30 80267150 8E3000C0 */  lw    $s0, 0xc0($s1)
/* 195A34 80267154 0C09740F */  jal   _remove_part_decoration
/* 195A38 80267158 02128021 */   addu  $s0, $s0, $s2
/* 195A3C 8026715C 0220202D */  daddu $a0, $s1, $zero
/* 195A40 80267160 24020001 */  addiu $v0, $zero, 1
/* 195A44 80267164 A21308B8 */  sb    $s3, 0x8b8($s0)
/* 195A48 80267168 A20208BA */  sb    $v0, 0x8ba($s0)
/* 195A4C 8026716C 0C0973B2 */  jal   func_8025CEC8
/* 195A50 80267170 A20008BC */   sb    $zero, 0x8bc($s0)
.L80267174:
/* 195A54 80267174 8FBF0020 */  lw    $ra, 0x20($sp)
/* 195A58 80267178 8FB3001C */  lw    $s3, 0x1c($sp)
/* 195A5C 8026717C 8FB20018 */  lw    $s2, 0x18($sp)
/* 195A60 80267180 8FB10014 */  lw    $s1, 0x14($sp)
/* 195A64 80267184 8FB00010 */  lw    $s0, 0x10($sp)
/* 195A68 80267188 03E00008 */  jr    $ra
/* 195A6C 8026718C 27BD0028 */   addiu $sp, $sp, 0x28


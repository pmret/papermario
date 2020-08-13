.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel kill_all_scripts
/* 0E8AC4 802C4114 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0E8AC8 802C4118 AFB00010 */  sw    $s0, 0x10($sp)
/* 0E8ACC 802C411C 0000802D */  daddu $s0, $zero, $zero
/* 0E8AD0 802C4120 AFBF0014 */  sw    $ra, 0x14($sp)
.L802C4124:
/* 0E8AD4 802C4124 3C03802E */  lui   $v1, 0x802e
/* 0E8AD8 802C4128 8C63A890 */  lw    $v1, -0x5770($v1)
/* 0E8ADC 802C412C 00101080 */  sll   $v0, $s0, 2
/* 0E8AE0 802C4130 00431021 */  addu  $v0, $v0, $v1
/* 0E8AE4 802C4134 8C440000 */  lw    $a0, ($v0)
/* 0E8AE8 802C4138 10800003 */  beqz  $a0, .L802C4148
/* 0E8AEC 802C413C 26100001 */   addiu $s0, $s0, 1
/* 0E8AF0 802C4140 0C0B0FCF */  jal   kill_script
/* 0E8AF4 802C4144 00000000 */   nop   
.L802C4148:
/* 0E8AF8 802C4148 2A020080 */  slti  $v0, $s0, 0x80
/* 0E8AFC 802C414C 1440FFF5 */  bnez  $v0, .L802C4124
/* 0E8B00 802C4150 00000000 */   nop   
/* 0E8B04 802C4154 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0E8B08 802C4158 8FB00010 */  lw    $s0, 0x10($sp)
/* 0E8B0C 802C415C 03E00008 */  jr    $ra
/* 0E8B10 802C4160 27BD0018 */   addiu $sp, $sp, 0x18


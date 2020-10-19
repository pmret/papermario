.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241A3C_D0716C
/* D0716C 80241A3C 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* D07170 80241A40 AFB10014 */  sw        $s1, 0x14($sp)
/* D07174 80241A44 0080882D */  daddu     $s1, $a0, $zero
/* D07178 80241A48 AFB00010 */  sw        $s0, 0x10($sp)
/* D0717C 80241A4C 00A0802D */  daddu     $s0, $a1, $zero
/* D07180 80241A50 AFBF001C */  sw        $ra, 0x1c($sp)
/* D07184 80241A54 AFB20018 */  sw        $s2, 0x18($sp)
/* D07188 80241A58 F7B40020 */  sdc1      $f20, 0x20($sp)
/* D0718C 80241A5C 0C00EABB */  jal       get_npc_unsafe
/* D07190 80241A60 2404FFFC */   addiu    $a0, $zero, -4
/* D07194 80241A64 12000017 */  beqz      $s0, .L80241AC4
/* D07198 80241A68 0040902D */   daddu    $s2, $v0, $zero
/* D0719C 80241A6C 0220202D */  daddu     $a0, $s1, $zero
/* D071A0 80241A70 3C05FE36 */  lui       $a1, 0xfe36
/* D071A4 80241A74 0C0B210B */  jal       get_float_variable
/* D071A8 80241A78 34A53C80 */   ori      $a1, $a1, 0x3c80
/* D071AC 80241A7C 0220202D */  daddu     $a0, $s1, $zero
/* D071B0 80241A80 3C05FE36 */  lui       $a1, 0xfe36
/* D071B4 80241A84 3C014270 */  lui       $at, 0x4270
/* D071B8 80241A88 4481A000 */  mtc1      $at, $f20
/* D071BC 80241A8C 34A53C85 */  ori       $a1, $a1, 0x3c85
/* D071C0 80241A90 46140003 */  div.s     $f0, $f0, $f20
/* D071C4 80241A94 0C0B210B */  jal       get_float_variable
/* D071C8 80241A98 E6200074 */   swc1     $f0, 0x74($s1)
/* D071CC 80241A9C 0220202D */  daddu     $a0, $s1, $zero
/* D071D0 80241AA0 3C05FE36 */  lui       $a1, 0xfe36
/* D071D4 80241AA4 34A53C81 */  ori       $a1, $a1, 0x3c81
/* D071D8 80241AA8 46140003 */  div.s     $f0, $f0, $f20
/* D071DC 80241AAC 0C0B210B */  jal       get_float_variable
/* D071E0 80241AB0 E6200078 */   swc1     $f0, 0x78($s1)
/* D071E4 80241AB4 46140003 */  div.s     $f0, $f0, $f20
/* D071E8 80241AB8 2402003C */  addiu     $v0, $zero, 0x3c
/* D071EC 80241ABC E620007C */  swc1      $f0, 0x7c($s1)
/* D071F0 80241AC0 AE220070 */  sw        $v0, 0x70($s1)
.L80241AC4:
/* D071F4 80241AC4 C6400038 */  lwc1      $f0, 0x38($s2)
/* D071F8 80241AC8 C6220074 */  lwc1      $f2, 0x74($s1)
/* D071FC 80241ACC 46020000 */  add.s     $f0, $f0, $f2
/* D07200 80241AD0 E6400038 */  swc1      $f0, 0x38($s2)
/* D07204 80241AD4 C640003C */  lwc1      $f0, 0x3c($s2)
/* D07208 80241AD8 C6220078 */  lwc1      $f2, 0x78($s1)
/* D0720C 80241ADC 46020000 */  add.s     $f0, $f0, $f2
/* D07210 80241AE0 E640003C */  swc1      $f0, 0x3c($s2)
/* D07214 80241AE4 C6400040 */  lwc1      $f0, 0x40($s2)
/* D07218 80241AE8 C622007C */  lwc1      $f2, 0x7c($s1)
/* D0721C 80241AEC 46020000 */  add.s     $f0, $f0, $f2
/* D07220 80241AF0 E6400040 */  swc1      $f0, 0x40($s2)
/* D07224 80241AF4 8E230070 */  lw        $v1, 0x70($s1)
/* D07228 80241AF8 2463FFFF */  addiu     $v1, $v1, -1
/* D0722C 80241AFC 2C620001 */  sltiu     $v0, $v1, 1
/* D07230 80241B00 AE230070 */  sw        $v1, 0x70($s1)
/* D07234 80241B04 8FBF001C */  lw        $ra, 0x1c($sp)
/* D07238 80241B08 8FB20018 */  lw        $s2, 0x18($sp)
/* D0723C 80241B0C 8FB10014 */  lw        $s1, 0x14($sp)
/* D07240 80241B10 8FB00010 */  lw        $s0, 0x10($sp)
/* D07244 80241B14 D7B40020 */  ldc1      $f20, 0x20($sp)
/* D07248 80241B18 00021040 */  sll       $v0, $v0, 1
/* D0724C 80241B1C 03E00008 */  jr        $ra
/* D07250 80241B20 27BD0028 */   addiu    $sp, $sp, 0x28

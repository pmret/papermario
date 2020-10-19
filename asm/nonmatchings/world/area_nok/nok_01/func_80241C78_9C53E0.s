.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241C78_9C7058
/* 9C7058 80241C78 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 9C705C 80241C7C AFB10014 */  sw        $s1, 0x14($sp)
/* 9C7060 80241C80 0080882D */  daddu     $s1, $a0, $zero
/* 9C7064 80241C84 AFB00010 */  sw        $s0, 0x10($sp)
/* 9C7068 80241C88 00A0802D */  daddu     $s0, $a1, $zero
/* 9C706C 80241C8C AFBF001C */  sw        $ra, 0x1c($sp)
/* 9C7070 80241C90 AFB20018 */  sw        $s2, 0x18($sp)
/* 9C7074 80241C94 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 9C7078 80241C98 0C00EABB */  jal       get_npc_unsafe
/* 9C707C 80241C9C 2404FFFC */   addiu    $a0, $zero, -4
/* 9C7080 80241CA0 12000017 */  beqz      $s0, .L80241D00
/* 9C7084 80241CA4 0040902D */   daddu    $s2, $v0, $zero
/* 9C7088 80241CA8 0220202D */  daddu     $a0, $s1, $zero
/* 9C708C 80241CAC 3C05FE36 */  lui       $a1, 0xfe36
/* 9C7090 80241CB0 0C0B210B */  jal       get_float_variable
/* 9C7094 80241CB4 34A53C80 */   ori      $a1, $a1, 0x3c80
/* 9C7098 80241CB8 0220202D */  daddu     $a0, $s1, $zero
/* 9C709C 80241CBC 3C05FE36 */  lui       $a1, 0xfe36
/* 9C70A0 80241CC0 3C014270 */  lui       $at, 0x4270
/* 9C70A4 80241CC4 4481A000 */  mtc1      $at, $f20
/* 9C70A8 80241CC8 34A53C85 */  ori       $a1, $a1, 0x3c85
/* 9C70AC 80241CCC 46140003 */  div.s     $f0, $f0, $f20
/* 9C70B0 80241CD0 0C0B210B */  jal       get_float_variable
/* 9C70B4 80241CD4 E6200074 */   swc1     $f0, 0x74($s1)
/* 9C70B8 80241CD8 0220202D */  daddu     $a0, $s1, $zero
/* 9C70BC 80241CDC 3C05FE36 */  lui       $a1, 0xfe36
/* 9C70C0 80241CE0 34A53C81 */  ori       $a1, $a1, 0x3c81
/* 9C70C4 80241CE4 46140003 */  div.s     $f0, $f0, $f20
/* 9C70C8 80241CE8 0C0B210B */  jal       get_float_variable
/* 9C70CC 80241CEC E6200078 */   swc1     $f0, 0x78($s1)
/* 9C70D0 80241CF0 46140003 */  div.s     $f0, $f0, $f20
/* 9C70D4 80241CF4 2402003C */  addiu     $v0, $zero, 0x3c
/* 9C70D8 80241CF8 E620007C */  swc1      $f0, 0x7c($s1)
/* 9C70DC 80241CFC AE220070 */  sw        $v0, 0x70($s1)
.L80241D00:
/* 9C70E0 80241D00 C6400038 */  lwc1      $f0, 0x38($s2)
/* 9C70E4 80241D04 C6220074 */  lwc1      $f2, 0x74($s1)
/* 9C70E8 80241D08 46020000 */  add.s     $f0, $f0, $f2
/* 9C70EC 80241D0C E6400038 */  swc1      $f0, 0x38($s2)
/* 9C70F0 80241D10 C640003C */  lwc1      $f0, 0x3c($s2)
/* 9C70F4 80241D14 C6220078 */  lwc1      $f2, 0x78($s1)
/* 9C70F8 80241D18 46020000 */  add.s     $f0, $f0, $f2
/* 9C70FC 80241D1C E640003C */  swc1      $f0, 0x3c($s2)
/* 9C7100 80241D20 C6400040 */  lwc1      $f0, 0x40($s2)
/* 9C7104 80241D24 C622007C */  lwc1      $f2, 0x7c($s1)
/* 9C7108 80241D28 46020000 */  add.s     $f0, $f0, $f2
/* 9C710C 80241D2C E6400040 */  swc1      $f0, 0x40($s2)
/* 9C7110 80241D30 8E230070 */  lw        $v1, 0x70($s1)
/* 9C7114 80241D34 2463FFFF */  addiu     $v1, $v1, -1
/* 9C7118 80241D38 2C620001 */  sltiu     $v0, $v1, 1
/* 9C711C 80241D3C AE230070 */  sw        $v1, 0x70($s1)
/* 9C7120 80241D40 8FBF001C */  lw        $ra, 0x1c($sp)
/* 9C7124 80241D44 8FB20018 */  lw        $s2, 0x18($sp)
/* 9C7128 80241D48 8FB10014 */  lw        $s1, 0x14($sp)
/* 9C712C 80241D4C 8FB00010 */  lw        $s0, 0x10($sp)
/* 9C7130 80241D50 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 9C7134 80241D54 00021040 */  sll       $v0, $v0, 1
/* 9C7138 80241D58 03E00008 */  jr        $ra
/* 9C713C 80241D5C 27BD0028 */   addiu    $sp, $sp, 0x28

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80136A08
/* CD108 80136A08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* CD10C 80136A0C 3C038008 */  lui       $v1, %hi(gItemTable)
/* CD110 80136A10 246378E0 */  addiu     $v1, $v1, %lo(gItemTable)
/* CD114 80136A14 AFBF0018 */  sw        $ra, 0x18($sp)
/* CD118 80136A18 84820018 */  lh        $v0, 0x18($a0)
/* CD11C 80136A1C 8084001A */  lb        $a0, 0x1a($a0)
/* CD120 80136A20 00021140 */  sll       $v0, $v0, 5
/* CD124 80136A24 00431821 */  addu      $v1, $v0, $v1
/* CD128 80136A28 28820002 */  slti      $v0, $a0, 2
/* CD12C 80136A2C 1440000E */  bnez      $v0, .L80136A68
/* CD130 80136A30 28820004 */   slti     $v0, $a0, 4
/* CD134 80136A34 14400006 */  bnez      $v0, .L80136A50
/* CD138 80136A38 2402000A */   addiu    $v0, $zero, 0xa
/* CD13C 80136A3C 2882000C */  slti      $v0, $a0, 0xc
/* CD140 80136A40 10400009 */  beqz      $v0, .L80136A68
/* CD144 80136A44 2882000A */   slti     $v0, $a0, 0xa
/* CD148 80136A48 14400007 */  bnez      $v0, .L80136A68
/* CD14C 80136A4C 2402000A */   addiu    $v0, $zero, 0xa
.L80136A50:
/* CD150 80136A50 24A50008 */  addiu     $a1, $a1, 8
/* CD154 80136A54 8C640014 */  lw        $a0, 0x14($v1)
/* CD158 80136A58 240700FF */  addiu     $a3, $zero, 0xff
/* CD15C 80136A5C AFA20010 */  sw        $v0, 0x10($sp)
/* CD160 80136A60 0C04993B */  jal       draw_string
/* CD164 80136A64 AFA00014 */   sw       $zero, 0x14($sp)
.L80136A68:
/* CD168 80136A68 8FBF0018 */  lw        $ra, 0x18($sp)
/* CD16C 80136A6C 03E00008 */  jr        $ra
/* CD170 80136A70 27BD0020 */   addiu    $sp, $sp, 0x20
/* CD174 80136A74 00000000 */  nop
/* CD178 80136A78 00000000 */  nop
/* CD17C 80136A7C 00000000 */  nop

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241E18_D21CA8
/* D21CA8 80241E18 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* D21CAC 80241E1C AFBF0010 */  sw        $ra, 0x10($sp)
/* D21CB0 80241E20 8C82000C */  lw        $v0, 0xc($a0)
/* D21CB4 80241E24 0C0B1EAF */  jal       get_variable
/* D21CB8 80241E28 8C450000 */   lw       $a1, ($v0)
/* D21CBC 80241E2C 0040182D */  daddu     $v1, $v0, $zero
/* D21CC0 80241E30 10600012 */  beqz      $v1, .L80241E7C
/* D21CC4 80241E34 0000202D */   daddu    $a0, $zero, $zero
/* D21CC8 80241E38 8C620000 */  lw        $v0, ($v1)
/* D21CCC 80241E3C 5040000A */  beql      $v0, $zero, .L80241E68
/* D21CD0 80241E40 00041080 */   sll      $v0, $a0, 2
/* D21CD4 80241E44 3C058025 */  lui       $a1, %hi(D_8024BEA0)
/* D21CD8 80241E48 24A5BEA0 */  addiu     $a1, $a1, %lo(D_8024BEA0)
.L80241E4C:
/* D21CDC 80241E4C 24630004 */  addiu     $v1, $v1, 4
/* D21CE0 80241E50 24840001 */  addiu     $a0, $a0, 1
/* D21CE4 80241E54 ACA20000 */  sw        $v0, ($a1)
/* D21CE8 80241E58 8C620000 */  lw        $v0, ($v1)
/* D21CEC 80241E5C 1440FFFB */  bnez      $v0, .L80241E4C
/* D21CF0 80241E60 24A50004 */   addiu    $a1, $a1, 4
/* D21CF4 80241E64 00041080 */  sll       $v0, $a0, 2
.L80241E68:
/* D21CF8 80241E68 3C018025 */  lui       $at, %hi(D_8024BEA0)
/* D21CFC 80241E6C 00220821 */  addu      $at, $at, $v0
/* D21D00 80241E70 AC20BEA0 */  sw        $zero, %lo(D_8024BEA0)($at)
/* D21D04 80241E74 080907A9 */  j         .L80241EA4
/* D21D08 80241E78 00000000 */   nop
.L80241E7C:
/* D21D0C 80241E7C 3C038025 */  lui       $v1, %hi(D_8024BEA0)
/* D21D10 80241E80 2463BEA0 */  addiu     $v1, $v1, %lo(D_8024BEA0)
/* D21D14 80241E84 0060282D */  daddu     $a1, $v1, $zero
.L80241E88:
/* D21D18 80241E88 24820010 */  addiu     $v0, $a0, 0x10
/* D21D1C 80241E8C AC620000 */  sw        $v0, ($v1)
/* D21D20 80241E90 24630004 */  addiu     $v1, $v1, 4
/* D21D24 80241E94 24840001 */  addiu     $a0, $a0, 1
/* D21D28 80241E98 28820070 */  slti      $v0, $a0, 0x70
/* D21D2C 80241E9C 1440FFFA */  bnez      $v0, .L80241E88
/* D21D30 80241EA0 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80241EA4:
/* D21D34 80241EA4 8FBF0010 */  lw        $ra, 0x10($sp)
/* D21D38 80241EA8 24020002 */  addiu     $v0, $zero, 2
/* D21D3C 80241EAC 03E00008 */  jr        $ra
/* D21D40 80241EB0 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241F38_E17CB8
/* E17CB8 80241F38 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E17CBC 80241F3C 0000202D */  daddu     $a0, $zero, $zero
/* E17CC0 80241F40 AFBF0014 */  sw        $ra, 0x14($sp)
/* E17CC4 80241F44 0C00FB3A */  jal       get_enemy
/* E17CC8 80241F48 AFB00010 */   sw       $s0, 0x10($sp)
/* E17CCC 80241F4C 8C50006C */  lw        $s0, 0x6c($v0)
/* E17CD0 80241F50 8E030020 */  lw        $v1, 0x20($s0)
/* E17CD4 80241F54 28620065 */  slti      $v0, $v1, 0x65
/* E17CD8 80241F58 14400003 */  bnez      $v0, .L80241F68
/* E17CDC 80241F5C 2862004C */   slti     $v0, $v1, 0x4c
/* E17CE0 80241F60 080907EC */  j         .L80241FB0
/* E17CE4 80241F64 24040028 */   addiu    $a0, $zero, 0x28
.L80241F68:
/* E17CE8 80241F68 14400003 */  bnez      $v0, .L80241F78
/* E17CEC 80241F6C 28620033 */   slti     $v0, $v1, 0x33
/* E17CF0 80241F70 080907EC */  j         .L80241FB0
/* E17CF4 80241F74 24040023 */   addiu    $a0, $zero, 0x23
.L80241F78:
/* E17CF8 80241F78 14400003 */  bnez      $v0, .L80241F88
/* E17CFC 80241F7C 2862001F */   slti     $v0, $v1, 0x1f
/* E17D00 80241F80 080907EC */  j         .L80241FB0
/* E17D04 80241F84 2404001E */   addiu    $a0, $zero, 0x1e
.L80241F88:
/* E17D08 80241F88 14400003 */  bnez      $v0, .L80241F98
/* E17D0C 80241F8C 28620015 */   slti     $v0, $v1, 0x15
/* E17D10 80241F90 080907EC */  j         .L80241FB0
/* E17D14 80241F94 2404000A */   addiu    $a0, $zero, 0xa
.L80241F98:
/* E17D18 80241F98 10400005 */  beqz      $v0, .L80241FB0
/* E17D1C 80241F9C 24040005 */   addiu    $a0, $zero, 5
/* E17D20 80241FA0 2862000B */  slti      $v0, $v1, 0xb
/* E17D24 80241FA4 14400002 */  bnez      $v0, .L80241FB0
/* E17D28 80241FA8 24040001 */   addiu    $a0, $zero, 1
/* E17D2C 80241FAC 24040002 */  addiu     $a0, $zero, 2
.L80241FB0:
/* E17D30 80241FB0 8E020020 */  lw        $v0, 0x20($s0)
/* E17D34 80241FB4 00441023 */  subu      $v0, $v0, $a0
/* E17D38 80241FB8 0C03A830 */  jal       add_coins
/* E17D3C 80241FBC AE020020 */   sw       $v0, 0x20($s0)
/* E17D40 80241FC0 0C05272D */  jal       play_sound
/* E17D44 80241FC4 24040211 */   addiu    $a0, $zero, 0x211
/* E17D48 80241FC8 8E020020 */  lw        $v0, 0x20($s0)
/* E17D4C 80241FCC 8FBF0014 */  lw        $ra, 0x14($sp)
/* E17D50 80241FD0 8FB00010 */  lw        $s0, 0x10($sp)
/* E17D54 80241FD4 28420001 */  slti      $v0, $v0, 1
/* E17D58 80241FD8 00021040 */  sll       $v0, $v0, 1
/* E17D5C 80241FDC 03E00008 */  jr        $ra
/* E17D60 80241FE0 27BD0018 */   addiu    $sp, $sp, 0x18

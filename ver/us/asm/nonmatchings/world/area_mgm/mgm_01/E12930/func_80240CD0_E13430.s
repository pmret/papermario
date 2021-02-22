.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240CD0_E13430
/* E13430 80240CD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* E13434 80240CD4 0000202D */  daddu     $a0, $zero, $zero
/* E13438 80240CD8 AFBF0014 */  sw        $ra, 0x14($sp)
/* E1343C 80240CDC 0C00FB3A */  jal       get_enemy
/* E13440 80240CE0 AFB00010 */   sw       $s0, 0x10($sp)
/* E13444 80240CE4 8C500080 */  lw        $s0, 0x80($v0)
/* E13448 80240CE8 8E03000C */  lw        $v1, 0xc($s0)
/* E1344C 80240CEC 28620065 */  slti      $v0, $v1, 0x65
/* E13450 80240CF0 14400003 */  bnez      $v0, .L80240D00
/* E13454 80240CF4 2862004C */   slti     $v0, $v1, 0x4c
/* E13458 80240CF8 08090352 */  j         .L80240D48
/* E1345C 80240CFC 24040028 */   addiu    $a0, $zero, 0x28
.L80240D00:
/* E13460 80240D00 14400003 */  bnez      $v0, .L80240D10
/* E13464 80240D04 28620033 */   slti     $v0, $v1, 0x33
/* E13468 80240D08 08090352 */  j         .L80240D48
/* E1346C 80240D0C 24040023 */   addiu    $a0, $zero, 0x23
.L80240D10:
/* E13470 80240D10 14400003 */  bnez      $v0, .L80240D20
/* E13474 80240D14 2862001F */   slti     $v0, $v1, 0x1f
/* E13478 80240D18 08090352 */  j         .L80240D48
/* E1347C 80240D1C 2404001E */   addiu    $a0, $zero, 0x1e
.L80240D20:
/* E13480 80240D20 14400003 */  bnez      $v0, .L80240D30
/* E13484 80240D24 28620015 */   slti     $v0, $v1, 0x15
/* E13488 80240D28 08090352 */  j         .L80240D48
/* E1348C 80240D2C 2404000A */   addiu    $a0, $zero, 0xa
.L80240D30:
/* E13490 80240D30 10400005 */  beqz      $v0, .L80240D48
/* E13494 80240D34 24040005 */   addiu    $a0, $zero, 5
/* E13498 80240D38 2862000B */  slti      $v0, $v1, 0xb
/* E1349C 80240D3C 14400002 */  bnez      $v0, .L80240D48
/* E134A0 80240D40 24040001 */   addiu    $a0, $zero, 1
/* E134A4 80240D44 24040002 */  addiu     $a0, $zero, 2
.L80240D48:
/* E134A8 80240D48 8E02000C */  lw        $v0, 0xc($s0)
/* E134AC 80240D4C 00441023 */  subu      $v0, $v0, $a0
/* E134B0 80240D50 0C03A830 */  jal       add_coins
/* E134B4 80240D54 AE02000C */   sw       $v0, 0xc($s0)
/* E134B8 80240D58 8E02000C */  lw        $v0, 0xc($s0)
/* E134BC 80240D5C 24040211 */  addiu     $a0, $zero, 0x211
/* E134C0 80240D60 0C05272D */  jal       play_sound
/* E134C4 80240D64 AE020010 */   sw       $v0, 0x10($s0)
/* E134C8 80240D68 8E02000C */  lw        $v0, 0xc($s0)
/* E134CC 80240D6C 8FBF0014 */  lw        $ra, 0x14($sp)
/* E134D0 80240D70 8FB00010 */  lw        $s0, 0x10($sp)
/* E134D4 80240D74 28420001 */  slti      $v0, $v0, 1
/* E134D8 80240D78 00021040 */  sll       $v0, $v0, 1
/* E134DC 80240D7C 03E00008 */  jr        $ra
/* E134E0 80240D80 27BD0018 */   addiu    $sp, $sp, 0x18

.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218CE4_465174
/* 465174 80218CE4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 465178 80218CE8 AFB00010 */  sw        $s0, 0x10($sp)
/* 46517C 80218CEC 0080802D */  daddu     $s0, $a0, $zero
/* 465180 80218CF0 AFBF0014 */  sw        $ra, 0x14($sp)
/* 465184 80218CF4 0C09A75B */  jal       get_actor
/* 465188 80218CF8 8E040148 */   lw       $a0, 0x148($s0)
/* 46518C 80218CFC 0C09A75B */  jal       get_actor
/* 465190 80218D00 84440428 */   lh       $a0, 0x428($v0)
/* 465194 80218D04 0040202D */  daddu     $a0, $v0, $zero
/* 465198 80218D08 8C820000 */  lw        $v0, ($a0)
/* 46519C 80218D0C 30420800 */  andi      $v0, $v0, 0x800
/* 4651A0 80218D10 1440000A */  bnez      $v0, .L80218D3C
/* 4651A4 80218D14 00000000 */   nop
/* 4651A8 80218D18 90820191 */  lbu       $v0, 0x191($a0)
/* 4651AC 80218D1C 8E030088 */  lw        $v1, 0x88($s0)
/* 4651B0 80218D20 00021042 */  srl       $v0, $v0, 1
/* 4651B4 80218D24 00621821 */  addu      $v1, $v1, $v0
/* 4651B8 80218D28 AE030088 */  sw        $v1, 0x88($s0)
/* 4651BC 80218D2C 90820191 */  lbu       $v0, 0x191($a0)
/* 4651C0 80218D30 00021082 */  srl       $v0, $v0, 2
/* 4651C4 80218D34 08086357 */  j         .L80218D5C
/* 4651C8 80218D38 00621821 */   addu     $v1, $v1, $v0
.L80218D3C:
/* 4651CC 80218D3C 90820191 */  lbu       $v0, 0x191($a0)
/* 4651D0 80218D40 8E030088 */  lw        $v1, 0x88($s0)
/* 4651D4 80218D44 00021042 */  srl       $v0, $v0, 1
/* 4651D8 80218D48 00621823 */  subu      $v1, $v1, $v0
/* 4651DC 80218D4C AE030088 */  sw        $v1, 0x88($s0)
/* 4651E0 80218D50 90820191 */  lbu       $v0, 0x191($a0)
/* 4651E4 80218D54 00021082 */  srl       $v0, $v0, 2
/* 4651E8 80218D58 00621823 */  subu      $v1, $v1, $v0
.L80218D5C:
/* 4651EC 80218D5C AE030088 */  sw        $v1, 0x88($s0)
/* 4651F0 80218D60 90830191 */  lbu       $v1, 0x191($a0)
/* 4651F4 80218D64 90840190 */  lbu       $a0, 0x190($a0)
/* 4651F8 80218D68 0064102A */  slt       $v0, $v1, $a0
/* 4651FC 80218D6C 54400001 */  bnel      $v0, $zero, .L80218D74
/* 465200 80218D70 0080182D */   daddu    $v1, $a0, $zero
.L80218D74:
/* 465204 80218D74 2462007E */  addiu     $v0, $v1, 0x7e
/* 465208 80218D78 AE020090 */  sw        $v0, 0x90($s0)
/* 46520C 80218D7C 8FBF0014 */  lw        $ra, 0x14($sp)
/* 465210 80218D80 8FB00010 */  lw        $s0, 0x10($sp)
/* 465214 80218D84 24020002 */  addiu     $v0, $zero, 2
/* 465218 80218D88 03E00008 */  jr        $ra
/* 46521C 80218D8C 27BD0018 */   addiu    $sp, $sp, 0x18

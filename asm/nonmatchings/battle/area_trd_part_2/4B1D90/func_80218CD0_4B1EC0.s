.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218CD0_4B1EC0
/* 4B1EC0 80218CD0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4B1EC4 80218CD4 AFB00010 */  sw        $s0, 0x10($sp)
/* 4B1EC8 80218CD8 0080802D */  daddu     $s0, $a0, $zero
/* 4B1ECC 80218CDC AFBF0014 */  sw        $ra, 0x14($sp)
/* 4B1ED0 80218CE0 0C09A75B */  jal       get_actor
/* 4B1ED4 80218CE4 24040200 */   addiu    $a0, $zero, 0x200
/* 4B1ED8 80218CE8 0040202D */  daddu     $a0, $v0, $zero
/* 4B1EDC 80218CEC 10800004 */  beqz      $a0, .L80218D00
/* 4B1EE0 80218CF0 00000000 */   nop      
/* 4B1EE4 80218CF4 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B1EE8 80218CF8 10500019 */  beq       $v0, $s0, .L80218D60
/* 4B1EEC 80218CFC 0080102D */   daddu    $v0, $a0, $zero
.L80218D00:
/* 4B1EF0 80218D00 0C09A75B */  jal       get_actor
/* 4B1EF4 80218D04 24040201 */   addiu    $a0, $zero, 0x201
/* 4B1EF8 80218D08 0040202D */  daddu     $a0, $v0, $zero
/* 4B1EFC 80218D0C 10800004 */  beqz      $a0, .L80218D20
/* 4B1F00 80218D10 00000000 */   nop      
/* 4B1F04 80218D14 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B1F08 80218D18 10500011 */  beq       $v0, $s0, .L80218D60
/* 4B1F0C 80218D1C 0080102D */   daddu    $v0, $a0, $zero
.L80218D20:
/* 4B1F10 80218D20 0C09A75B */  jal       get_actor
/* 4B1F14 80218D24 24040202 */   addiu    $a0, $zero, 0x202
/* 4B1F18 80218D28 0040202D */  daddu     $a0, $v0, $zero
/* 4B1F1C 80218D2C 10800004 */  beqz      $a0, .L80218D40
/* 4B1F20 80218D30 00000000 */   nop      
/* 4B1F24 80218D34 8C82008C */  lw        $v0, 0x8c($a0)
/* 4B1F28 80218D38 10500009 */  beq       $v0, $s0, .L80218D60
/* 4B1F2C 80218D3C 0080102D */   daddu    $v0, $a0, $zero
.L80218D40:
/* 4B1F30 80218D40 0C09A75B */  jal       get_actor
/* 4B1F34 80218D44 24040203 */   addiu    $a0, $zero, 0x203
/* 4B1F38 80218D48 0040202D */  daddu     $a0, $v0, $zero
/* 4B1F3C 80218D4C 50800004 */  beql      $a0, $zero, .L80218D60
/* 4B1F40 80218D50 0000102D */   daddu    $v0, $zero, $zero
/* 4B1F44 80218D54 8C83008C */  lw        $v1, 0x8c($a0)
/* 4B1F48 80218D58 54700001 */  bnel      $v1, $s0, .L80218D60
/* 4B1F4C 80218D5C 0000102D */   daddu    $v0, $zero, $zero
.L80218D60:
/* 4B1F50 80218D60 8FBF0014 */  lw        $ra, 0x14($sp)
/* 4B1F54 80218D64 8FB00010 */  lw        $s0, 0x10($sp)
/* 4B1F58 80218D68 03E00008 */  jr        $ra
/* 4B1F5C 80218D6C 27BD0018 */   addiu    $sp, $sp, 0x18

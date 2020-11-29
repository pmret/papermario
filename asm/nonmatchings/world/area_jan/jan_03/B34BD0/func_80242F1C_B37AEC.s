.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F1C_B37AEC
/* B37AEC 80242F1C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* B37AF0 80242F20 0000302D */  daddu     $a2, $zero, $zero
/* B37AF4 80242F24 00C0482D */  daddu     $t1, $a2, $zero
/* B37AF8 80242F28 AFBF0010 */  sw        $ra, 0x10($sp)
/* B37AFC 80242F2C 8C82000C */  lw        $v0, 0xc($a0)
/* B37B00 80242F30 3C088011 */  lui       $t0, %hi(gPlayerData)
/* B37B04 80242F34 2508F290 */  addiu     $t0, $t0, %lo(gPlayerData)
/* B37B08 80242F38 8C450000 */  lw        $a1, ($v0)
.L80242F3C:
/* B37B0C 80242F3C 3C038025 */  lui       $v1, %hi(D_8024A5AC)
/* B37B10 80242F40 2463A5AC */  addiu     $v1, $v1, %lo(D_8024A5AC)
/* B37B14 80242F44 8C620000 */  lw        $v0, ($v1)
/* B37B18 80242F48 5040000A */  beql      $v0, $zero, .L80242F74
/* B37B1C 80242F4C 25290001 */   addiu    $t1, $t1, 1
/* B37B20 80242F50 850701B4 */  lh        $a3, 0x1b4($t0)
.L80242F54:
/* B37B24 80242F54 8C620000 */  lw        $v0, ($v1)
/* B37B28 80242F58 14E20002 */  bne       $a3, $v0, .L80242F64
/* B37B2C 80242F5C 24630004 */   addiu    $v1, $v1, 4
/* B37B30 80242F60 24C60001 */  addiu     $a2, $a2, 1
.L80242F64:
/* B37B34 80242F64 8C620000 */  lw        $v0, ($v1)
/* B37B38 80242F68 1440FFFA */  bnez      $v0, .L80242F54
/* B37B3C 80242F6C 00000000 */   nop      
/* B37B40 80242F70 25290001 */  addiu     $t1, $t1, 1
.L80242F74:
/* B37B44 80242F74 2922000A */  slti      $v0, $t1, 0xa
/* B37B48 80242F78 1440FFF0 */  bnez      $v0, .L80242F3C
/* B37B4C 80242F7C 25080002 */   addiu    $t0, $t0, 2
/* B37B50 80242F80 0C0B2026 */  jal       set_variable
/* B37B54 80242F84 00000000 */   nop      
/* B37B58 80242F88 8FBF0010 */  lw        $ra, 0x10($sp)
/* B37B5C 80242F8C 24020002 */  addiu     $v0, $zero, 2
/* B37B60 80242F90 03E00008 */  jr        $ra
/* B37B64 80242F94 27BD0018 */   addiu    $sp, $sp, 0x18
/* B37B68 80242F98 00000000 */  nop       
/* B37B6C 80242F9C 00000000 */  nop       

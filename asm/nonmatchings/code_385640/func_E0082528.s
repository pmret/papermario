.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E0082528
/* 385B68 E0082528 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 385B6C E008252C AFB10014 */  sw        $s1, 0x14($sp)
/* 385B70 E0082530 0080882D */  daddu     $s1, $a0, $zero
/* 385B74 E0082534 AFBF0018 */  sw        $ra, 0x18($sp)
/* 385B78 E0082538 AFB00010 */  sw        $s0, 0x10($sp)
/* 385B7C E008253C 8E30000C */  lw        $s0, 0xc($s1)
/* 385B80 E0082540 8E020004 */  lw        $v0, 4($s0)
/* 385B84 E0082544 10400009 */  beqz      $v0, .LE008256C
/* 385B88 E0082548 00000000 */   nop      
/* 385B8C E008254C 0C020A2D */  jal       func_E00828B4
/* 385B90 E0082550 00000000 */   nop      
/* 385B94 E0082554 8E030000 */  lw        $v1, ($s0)
/* 385B98 E0082558 24020001 */  addiu     $v0, $zero, 1
/* 385B9C E008255C 10620003 */  beq       $v1, $v0, .LE008256C
/* 385BA0 E0082560 00000000 */   nop      
/* 385BA4 E0082564 0C020AA1 */  jal       func_E0082A84
/* 385BA8 E0082568 0220202D */   daddu    $a0, $s1, $zero
.LE008256C:
/* 385BAC E008256C 8FBF0018 */  lw        $ra, 0x18($sp)
/* 385BB0 E0082570 8FB10014 */  lw        $s1, 0x14($sp)
/* 385BB4 E0082574 8FB00010 */  lw        $s0, 0x10($sp)
/* 385BB8 E0082578 03E00008 */  jr        $ra
/* 385BBC E008257C 27BD0020 */   addiu    $sp, $sp, 0x20

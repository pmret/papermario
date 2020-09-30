.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8004FBBC
/* 2AFBC 8004FBBC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 2AFC0 8004FBC0 AFB00010 */  sw        $s0, 0x10($sp)
/* 2AFC4 8004FBC4 0080802D */  daddu     $s0, $a0, $zero
/* 2AFC8 8004FBC8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 2AFCC 8004FBCC 960500D4 */  lhu       $a1, 0xd4($s0)
/* 2AFD0 8004FBD0 0C013F02 */  jal       func_8004FC08
/* 2AFD4 8004FBD4 A6050208 */   sh       $a1, 0x208($s0)
/* 2AFD8 8004FBD8 00021880 */  sll       $v1, $v0, 2
/* 2AFDC 8004FBDC 00621821 */  addu      $v1, $v1, $v0
/* 2AFE0 8004FBE0 00031840 */  sll       $v1, $v1, 1
/* 2AFE4 8004FBE4 AE0200B0 */  sw        $v0, 0xb0($s0)
/* 2AFE8 8004FBE8 AE030008 */  sw        $v1, 8($s0)
/* 2AFEC 8004FBEC AE0000BC */  sw        $zero, 0xbc($s0)
/* 2AFF0 8004FBF0 AE0000B8 */  sw        $zero, 0xb8($s0)
/* 2AFF4 8004FBF4 AE0000B4 */  sw        $zero, 0xb4($s0)
/* 2AFF8 8004FBF8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 2AFFC 8004FBFC 8FB00010 */  lw        $s0, 0x10($sp)
/* 2B000 8004FC00 03E00008 */  jr        $ra
/* 2B004 8004FC04 27BD0018 */   addiu    $sp, $sp, 0x18

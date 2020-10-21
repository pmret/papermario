.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242C0C_9AAFFC
/* 9AAFFC 80242C0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9AB000 80242C10 AFB00010 */  sw        $s0, 0x10($sp)
/* 9AB004 80242C14 0080802D */  daddu     $s0, $a0, $zero
/* 9AB008 80242C18 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9AB00C 80242C1C 8E020148 */  lw        $v0, 0x148($s0)
/* 9AB010 80242C20 0C00EABB */  jal       get_npc_unsafe
/* 9AB014 80242C24 84440008 */   lh       $a0, 8($v0)
/* 9AB018 80242C28 0040202D */  daddu     $a0, $v0, $zero
/* 9AB01C 80242C2C 8482008E */  lh        $v0, 0x8e($a0)
/* 9AB020 80242C30 9483008E */  lhu       $v1, 0x8e($a0)
/* 9AB024 80242C34 18400005 */  blez      $v0, .L80242C4C
/* 9AB028 80242C38 2462FFFF */   addiu    $v0, $v1, -1
/* 9AB02C 80242C3C A482008E */  sh        $v0, 0x8e($a0)
/* 9AB030 80242C40 00021400 */  sll       $v0, $v0, 0x10
/* 9AB034 80242C44 1C400006 */  bgtz      $v0, .L80242C60
/* 9AB038 80242C48 00000000 */   nop      
.L80242C4C:
/* 9AB03C 80242C4C 8482008C */  lh        $v0, 0x8c($a0)
/* 9AB040 80242C50 14400003 */  bnez      $v0, .L80242C60
/* 9AB044 80242C54 2402000E */   addiu    $v0, $zero, 0xe
/* 9AB048 80242C58 A480008E */  sh        $zero, 0x8e($a0)
/* 9AB04C 80242C5C AE020070 */  sw        $v0, 0x70($s0)
.L80242C60:
/* 9AB050 80242C60 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9AB054 80242C64 8FB00010 */  lw        $s0, 0x10($sp)
/* 9AB058 80242C68 03E00008 */  jr        $ra
/* 9AB05C 80242C6C 27BD0018 */   addiu    $sp, $sp, 0x18

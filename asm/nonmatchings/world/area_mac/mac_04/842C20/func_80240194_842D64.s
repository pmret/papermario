.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240194_842D64
/* 842D64 80240194 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 842D68 80240198 AFBF0010 */  sw        $ra, 0x10($sp)
/* 842D6C 8024019C 0C04760B */  jal       func_8011D82C
/* 842D70 802401A0 24040003 */   addiu    $a0, $zero, 3
/* 842D74 802401A4 8FBF0010 */  lw        $ra, 0x10($sp)
/* 842D78 802401A8 24020002 */  addiu     $v0, $zero, 2
/* 842D7C 802401AC 03E00008 */  jr        $ra
/* 842D80 802401B0 27BD0018 */   addiu    $sp, $sp, 0x18
/* 842D84 802401B4 00000000 */  nop
/* 842D88 802401B8 00000000 */  nop
/* 842D8C 802401BC 00000000 */  nop

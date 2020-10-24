.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240BB0_9C5F90
/* 9C5F90 80240BB0 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9C5F94 80240BB4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 9C5F98 80240BB8 8C82000C */  lw        $v0, 0xc($a0)
/* 9C5F9C 80240BBC 0C0B1EAF */  jal       get_variable
/* 9C5FA0 80240BC0 8C450000 */   lw       $a1, ($v0)
/* 9C5FA4 80240BC4 0C0B1059 */  jal       does_script_exist
/* 9C5FA8 80240BC8 0040202D */   daddu    $a0, $v0, $zero
/* 9C5FAC 80240BCC 2C420001 */  sltiu     $v0, $v0, 1
/* 9C5FB0 80240BD0 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9C5FB4 80240BD4 00021040 */  sll       $v0, $v0, 1
/* 9C5FB8 80240BD8 03E00008 */  jr        $ra
/* 9C5FBC 80240BDC 27BD0018 */   addiu    $sp, $sp, 0x18

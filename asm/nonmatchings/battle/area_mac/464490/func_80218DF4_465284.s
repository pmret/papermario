.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80218DF4_465284
/* 465284 80218DF4 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 465288 80218DF8 AFBF0010 */  sw        $ra, 0x10($sp)
/* 46528C 80218DFC 8C82000C */  lw        $v0, 0xc($a0)
/* 465290 80218E00 0C0B1EAF */  jal       get_variable
/* 465294 80218E04 8C450000 */   lw       $a1, ($v0)
/* 465298 80218E08 8C43000C */  lw        $v1, 0xc($v0)
/* 46529C 80218E0C 3C01C47A */  lui       $at, 0xc47a
/* 4652A0 80218E10 44810000 */  mtc1      $at, $f0
/* 4652A4 80218E14 00000000 */  nop       
/* 4652A8 80218E18 E4600008 */  swc1      $f0, 8($v1)
/* 4652AC 80218E1C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4652B0 80218E20 24020002 */  addiu     $v0, $zero, 2
/* 4652B4 80218E24 03E00008 */  jr        $ra
/* 4652B8 80218E28 27BD0018 */   addiu    $sp, $sp, 0x18

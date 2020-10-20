.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240000_800880
/* 800880 80240000 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 800884 80240004 AFBF0010 */  sw        $ra, 0x10($sp)
/* 800888 80240008 8C82000C */  lw        $v0, 0xc($a0)
/* 80088C 8024000C 0C0B1EAF */  jal       get_variable
/* 800890 80240010 8C450000 */   lw       $a1, ($v0)
/* 800894 80240014 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* 800898 80240018 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* 80089C 8024001C 8C630140 */  lw        $v1, 0x140($v1)
/* 8008A0 80240020 00021100 */  sll       $v0, $v0, 4
/* 8008A4 80240024 00431021 */  addu      $v0, $v0, $v1
/* 8008A8 80240028 8C440000 */  lw        $a0, ($v0)
/* 8008AC 8024002C 0C04D052 */  jal       set_item_entity_flags
/* 8008B0 80240030 24050040 */   addiu    $a1, $zero, 0x40
/* 8008B4 80240034 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8008B8 80240038 24020002 */  addiu     $v0, $zero, 2
/* 8008BC 8024003C 03E00008 */  jr        $ra
/* 8008C0 80240040 27BD0018 */   addiu    $sp, $sp, 0x18

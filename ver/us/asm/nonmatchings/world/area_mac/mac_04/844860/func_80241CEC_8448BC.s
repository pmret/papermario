.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241CEC_8448BC
/* 8448BC 80241CEC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8448C0 80241CF0 3C05FD05 */  lui       $a1, 0xfd05
/* 8448C4 80241CF4 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8448C8 80241CF8 0C0B1EAF */  jal       get_variable
/* 8448CC 80241CFC 34A50F8B */   ori      $a1, $a1, 0xf8b
/* 8448D0 80241D00 0040202D */  daddu     $a0, $v0, $zero
/* 8448D4 80241D04 3C028011 */  lui       $v0, %hi(gPlayerStatus)
/* 8448D8 80241D08 2442EFC8 */  addiu     $v0, $v0, %lo(gPlayerStatus)
/* 8448DC 80241D0C 8C430004 */  lw        $v1, 4($v0)
/* 8448E0 80241D10 2405DFFF */  addiu     $a1, $zero, -0x2001
/* 8448E4 80241D14 00651824 */  and       $v1, $v1, $a1
/* 8448E8 80241D18 0C048D70 */  jal       free_dynamic_entity
/* 8448EC 80241D1C AC430004 */   sw       $v1, 4($v0)
/* 8448F0 80241D20 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8448F4 80241D24 24020002 */  addiu     $v0, $zero, 2
/* 8448F8 80241D28 03E00008 */  jr        $ra
/* 8448FC 80241D2C 27BD0018 */   addiu    $sp, $sp, 0x18
